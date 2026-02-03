%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "node/node.h"
    #include "node/node.c"

    #include "define/constants.h"

    int yylex(void);
    void yyerror(char const *msg);

    int regCount = 0;
    int totalRegs = 20;

    int getReg();
    int freeReg();

    void generateHeader();
    regIndex codeGen(struct tnode *node);

    FILE *target_file;
    extern FILE *yyin;
%}

%union {
    struct tnode *node;
}

%type <node> expr statementList statement inputStatement outputStatement assignmentStatement statement
%token <node> ID NUM
%token NUM PLUS MINUS MUL DIV KW_BEGIN KW_END ID READ WRITE ASSIGN SEMI

%left PLUS MINUS
%left MUL DIV

%%

program : KW_BEGIN statementList KW_END {
        print($2);
        printf("Finished\n");
        exit(0);
    }
    | KW_BEGIN KW_END
    ;

statementList : statementList statement     { $$ = createConnectorNode($1, $2); }
    | statement                             { $$ = $1; }
    ;

statement : inputStatement                  { $$ = $1; }
    | outputStatement                       { $$ = $1; }
    | assignmentStatement                   { $$ = $1; }
    ;

inputStatement : READ '(' ID ')' SEMI       { $$ = createReadNode($3); }
    ;

outputStatement : WRITE '(' expr ')' SEMI   { $$ = createWriteNode($3); }
    ;

assignmentStatement : ID ASSIGN expr SEMI   { $$ = createAssignNode($1, $3); }
    ;

expr : expr PLUS expr                       { $$ = createArithOpNode(NODE_ADD, $1, $3); }
    | expr MINUS expr                       { $$ = createArithOpNode(NODE_SUB, $1, $3); }
    | expr MUL expr                         { $$ = createArithOpNode(NODE_MUL, $1, $3); }
    | expr DIV expr                         { $$ = createArithOpNode(NODE_DIV, $1, $3); }
    | '(' expr ')'                          { $$ = $2; }
    | NUM                                   { $$ = $1; }
    | ID                                    { $$ = $1; }
    ;

%%

void yyerror(char const *msg) {
    printf("[Error] : %s\n", msg);
    return;
}

int main() {
    target_file = fopen(OUTPUT_FILE, "w");

    FILE *source_file = fopen(SOURCE_FILE, "r");
    yyin = source_file;

    return yyparse();
}