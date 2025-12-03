%{
    #include <stdio.h>
    #include <stdlib.h>
    int yyerror(char const *c);
    int yylex();
%}

%union {
    int num;
}

%token <num> NUMBER

%left '+'
%left '*'

%type <num> start expr

%%

start : expr '\n' {printf("Value: %d\n", $1); exit(0);}
      ;

expr : expr '+' expr {$$ = $1 + $3;}
     | expr '*' expr {$$ = $1 * $3;}
     | '(' expr ')'  {$$ = $2;}
     | NUMBER        {$$ = $1;}
     ;

%%

int yyerror(char const *c) {
    printf("Error %s\n", c);

    return 1;
}

int main() {
    return yyparse();
}