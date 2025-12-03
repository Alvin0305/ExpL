%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "exprtree.h"
    #include "exprtree.c"

    int yylex(void);
    void yyerror(char const *msg);
%}

%union {
    struct tnode *node;
}

%type <node> expr NUM program END
%token NUM PLUS MINUS MUL DIV END
%left PLUS MINUS
%left MUL DIV

%%

program : expr END {
    $$ = $2;
    printf("Answer: %d\n", evaluate($1));

    prefix($1);
    postfix($1);
    
    exit(0);
};

expr : expr PLUS expr { $$ = createOperatorNode('+', $1, $3); }
    | expr MINUS expr { $$ = createOperatorNode('-', $1, $3); }
    | expr MUL expr { $$ = createOperatorNode('*', $1, $3); }
    | expr DIV expr { $$ = createOperatorNode('/', $1, $3); }
    | '(' expr ')' { $$ = $2; }
    | NUM { $$ = $1; }
    ;

%%

void yyerror(char const *msg) {
    printf("[Error] : %s\n", msg);
    return;
}

int main() {
    return yyparse();
}