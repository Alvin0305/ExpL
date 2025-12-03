%{
    #include "y.tab.h"
    #include <stdlib.h>
%}

%%

[0-9]+ {
    yylval.num = atoi(yytext);
    return DIGIT;
}

"+" {return '+';}
"-" {return '-';}
[()] {return yytext[0];}

[\t ] {}
\n {return '\n';}

%%

int yywrap() {
    return 1;
}