%{
    #include <stdio.h>
    #include <stdlib.h>
    void yyerror(char const *msg);
    int yylex(void);
%}

%union {
    int num;
}

%token <num> DIGIT 

%left '+'
%left '-'

%type <num> expr

%%

start : expr '\n' {
    printf("\nComplete\n");
    exit(0);
};

expr : expr '+' expr {printf("+ ");}
     | expr '-' expr {printf("- ");}
     | '(' expr ')'
     | DIGIT         {printf("%d ", $1);}
     ;

%%

void yyerror(char const *msg) {
    printf("[Error] : %s\n", msg);
    return;
}

int main() {
    yyparse();
    return 1;
}