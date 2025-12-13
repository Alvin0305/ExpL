%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "node/node.h"
    #include "code_gen/code_gen.h"
    #include "define/constants.h"
    #include "g_symbol_table/g_symbol_table.h"
    #include "util/util.h"

    int yylex(void);
    void yyerror(char const *msg);

    FILE *target_file;
    extern FILE *yyin;
    extern int lineNumber;
%}

%union {
    struct tnode *node;
}

%type <node> expr program statementList statement inputStatement outputStatement assignmentStatement
%type <node> whileStatement ifStatement repeatUntilStatement doWhileStatement
%type <node> declarations declList decl varList type
%type <node> ID NUM STRING_LITERAL

%token NUM ID STRING_LITERAL
%token READ WRITE
%token PLUS MUL MINUS DIV MOD ASSIGN SEMI
%token GT GE LT LE NE EQ
%token KW_BEGIN KW_END KW_IF KW_THEN KW_ELSE KW_ENDIF
%token KW_WHILE KW_DO KW_ENDWHILE KW_BREAK KW_CONTINUE KW_REPEAT KW_UNTIL
%token KW_DECL KW_ENDDECL TYPE_INT TYPE_STRING COMMA

%left PLUS MINUS
%left MUL DIV MOD

%nonassoc GE GT LE LT NE EQ

%%

program : KW_BEGIN declarations statementList KW_END {
        $$ = createConnectorNode($2, $3);
        generateCode($3);
        printf("Finished\n");
        exit(0);
    }
    | KW_BEGIN declarations KW_END { 
        $$ = NULL;
        generateCode(NULL);
    }
    ;

declarations : KW_DECL declList KW_ENDDECL { 
        $$ = $2; 
        print($2);
        populateGSymbolTable($2);
        printGSymbolTable(); 
    }
    | KW_DECL KW_ENDDECL { $$ = NULL; }
    ;

declList : declList decl { $$ = createConnectorNode($1, $2); }
    | decl               { $$ = $1; }
    ;

decl : type varList SEMI { $$ = createDeclarationNode($1, $2); }
    ;

type : TYPE_INT     { $$ = createTypeNode(INT); }
    | TYPE_STRING   { $$ = createTypeNode(STRING); }
    ;

varList : varList COMMA ID          { $$ = createConnectorNode($1, $3); }
    | varList COMMA ID '[' NUM ']'  { $$ = createNewArrayNode($1, $3, $5); }
    | ID '[' NUM ']'                { $$ = createNewArrayNode(NULL, $1, $3); }
    | ID                            { $$ = $1; }
    ;

statementList : statementList statement { $$ = createConnectorNode($1, $2); }
    | statement                         { $$ = $1; }
    ;

statement : inputStatement      { $$ = $1; }
    | outputStatement           { $$ = $1; }
    | assignmentStatement       { $$ = $1; }
    | ifStatement               { $$ = $1; }
    | whileStatement            { $$ = $1; }
    | KW_BREAK SEMI             { $$ = createBreakNode(); }
    | KW_CONTINUE SEMI          { $$ = createContinueNode(); }
    | repeatUntilStatement      { $$ = $1; }
    | doWhileStatement          { $$ = $1; }
    ;

inputStatement : READ '(' ID ')' SEMI { $$ = createReadNode($3); }
    ;

outputStatement : WRITE '(' expr ')' SEMI { $$ = createWriteNode($3); }
    ;

assignmentStatement : ID ASSIGN expr SEMI   { $$ = createAssignNode($1, $3); }
    | ID '[' expr ']' ASSIGN expr SEMI      { $$ = createArrayAssignNode($1, $3, $6); }
    ;

ifStatement : KW_IF '(' expr ')' KW_THEN statementList KW_ELSE statementList KW_ENDIF   { $$ = createIfElseNode($3, $6, $8); }
    | KW_IF '(' expr ')' KW_THEN statementList KW_ENDIF                                 { $$ = createIfNode($3, $6); }
    ;

whileStatement : KW_WHILE '(' expr ')' KW_DO statementList KW_ENDWHILE { $$ = createWhileNode($3, $6); }
    ;

repeatUntilStatement: KW_REPEAT statementList KW_UNTIL '(' expr ')' SEMI { $$ = createRepeatUntilNode($2, $5); }
    ;

doWhileStatement: KW_DO statementList KW_WHILE '(' expr ')' SEMI { $$ = createDoWhileNode($2, $5); }
    ;

expr : expr PLUS expr { $$ = createArithOpNode(NODE_ADD, $1, $3); }
    | expr MINUS expr { $$ = createArithOpNode(NODE_SUB, $1, $3); }
    | expr MUL expr   { $$ = createArithOpNode(NODE_MUL, $1, $3); }
    | expr DIV expr   { $$ = createArithOpNode(NODE_DIV, $1, $3); }
    | expr MOD expr   { $$ = createArithOpNode(NODE_MOD, $1, $3); }
    | '(' expr ')'    { $$ = $2; }
    | NUM             { $$ = $1; }
    | ID              { $$ = createVariableUsageNode($1->varName); }
    | STRING_LITERAL  { $$ = $1; }
    | expr GE expr    { $$ = createConditionNode(NODE_GE, $1, $3); }
    | expr GT expr    { $$ = createConditionNode(NODE_GT, $1, $3); }
    | expr LT expr    { $$ = createConditionNode(NODE_LT, $1, $3); }
    | expr LE expr    { $$ = createConditionNode(NODE_LE, $1, $3); }
    | expr NE expr    { $$ = createConditionNode(NODE_NE, $1, $3); }
    | expr EQ expr    { $$ = createConditionNode(NODE_EQ, $1, $3); }
    | ID '[' expr ']' { $$ = createArrayAccessNode($1, $3); }
    ;

%%

void yyerror(char const *msg) {
    printf("[Error] : %s in line: %d\n", msg, lineNumber);
    return;
}

int main() {
    target_file = fopen(INTERMEDIATE_FILE, "w");
    FILE *source_file = fopen(SOURCE_FILE, "r");

    yyin = source_file;

    return yyparse();
}