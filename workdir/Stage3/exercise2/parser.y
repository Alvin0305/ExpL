%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "node/node.h"
    #include "code_gen/code_gen.h"
    #include "define/constants.h"
    #include "evaluator/evaluator.h"

    int yylex(void);
    void yyerror(char const *msg);

    FILE *target_file;
    extern FILE *yyin;
%}

%union {
    struct tnode *node;
}

%type <node> expr program statementList statement inputStatement outputStatement assignmentStatement ifStatement whileStatement statement ID NUM
%type <node> whileStatement ifStatement

%token NUM ID 
%token READ WRITE
%token PLUS MUL MINUS DIV ASSIGN SEMI
%token GT GE LT LE NE EQ
%token KW_BEGIN KW_END KW_IF, KW_THEN, KW_ELSE, KW_ENDIF, KW_WHILE, KW_DO, KW_ENDWHILE

%left PLUS MINUS
%left MUL DIV

%nonassoc GE GT LE LT NE EQ

%%

program : KW_BEGIN statementList KW_END {
        generateCode($2);
        printf("Finished\n");
        exit(0);
    }
    | KW_BEGIN KW_END { $$ = NULL; }
    ;

statementList : statementList statement { $$ = createConnectorNode($1, $2); }
    | statement { $$ = $1; }
    ;

statement : inputStatement { $$ = $1; }
    | outputStatement { $$ = $1; }
    | assignmentStatement { $$ = $1; }
    | ifStatement { $$ = $1; }
    | whileStatement { $$ = $1; }
    ;

inputStatement : READ '(' ID ')' SEMI { $$ = createReadNode($3); }
    ;

outputStatement : WRITE '(' expr ')' SEMI { $$ = createWriteNode($3); }
    ;

assignmentStatement : ID ASSIGN expr SEMI { $$ = createAssignNode($1, $3); }
    ;

ifStatement : KW_IF '(' expr ')' KW_THEN statementList KW_ELSE statementList KW_ENDIF { $$ = createIfElseNode($3, $6, $8); }
    | KW_IF '(' expr ')' KW_THEN statementList KW_ENDIF { $$ = createIfNode($3, $6); }
    ;

whileStatement : KW_WHILE '(' expr ')' KW_DO statementList KW_ENDWHILE { $$ = createWhileNode($3, $6); }
    ;

expr : expr PLUS expr { $$ = createArithOpNode(NODE_ADD, $1, $3); }
    | expr MINUS expr { $$ = createArithOpNode(NODE_SUB, $1, $3); }
    | expr MUL expr   { $$ = createArithOpNode(NODE_MUL, $1, $3); }
    | expr DIV expr   { $$ = createArithOpNode(NODE_DIV, $1, $3); }
    | '(' expr ')'    { $$ = $2; }
    | NUM             { $$ = $1; }
    | ID              { $$ = $1; }
    | expr GE expr    { $$ = createConditionNode(NODE_GE, $1, $3); }
    | expr GT expr    { $$ = createConditionNode(NODE_GT, $1, $3); }
    | expr LT expr    { $$ = createConditionNode(NODE_LT, $1, $3); }
    | expr LE expr    { $$ = createConditionNode(NODE_LE, $1, $3); }
    | expr NE expr    { $$ = createConditionNode(NODE_NE, $1, $3); }
    | expr EQ expr    { $$ = createConditionNode(NODE_EQ, $1, $3); }
    ;

%%

void yyerror(char const *msg) {
    printf("[Error] : %s\n", msg);
    return;
}

int main() {
    target_file = fopen(INTERMEDIATE_FILE, "w");
    FILE *source_file = fopen(SOURCE_FILE, "r");

    yyin = source_file;

    return yyparse();
}