%option noyywrap

%{
    #include <stdio.h>
%}

%%

"//".*\n    { printf("Single Comment: %s\n", yytext); }

exit        { return 0; }
.           {  }

%%

int main() {
    return yylex();
}