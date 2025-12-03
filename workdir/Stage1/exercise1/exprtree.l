%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "exprtree.h"
    #include "y.tab.h"

    int number;
%}

%%

[0-9]+ {
    number = atoi(yytext);
    yylval.node = createLeafNode(number);
    return NUM;
}

"+" {return PLUS;}
"-" {return MINUS;}
"*" {return MUL;}
"/" {return DIV;}

[\t ] {}
[()] {return yytext[0];}
[\n] {return END;}
. {printf("unknown character %s\n", yytext); exit(1);}

%%

int yywrap() {
    return 1;
}