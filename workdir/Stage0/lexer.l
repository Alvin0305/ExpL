%{
    #include "y.tab.h"
    #include <stdio.h>
    #include <stdlib.h>
%}

number [0-9]+

%% 

{number} {yylval.num = atoi(yytext); return NUMBER;}

[\t ] {}

\n {return '\n';}

. {return yytext[0];}

%%