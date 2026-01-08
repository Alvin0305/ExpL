%option noyywrap

%{
    #include <stdio.h>
%}

cap     [A-Z]

%%

A[A-Z]{2}[ \t\n]     { printf("%s\n", yytext); }
.               { }

%%

int main() {
    return yylex();
}