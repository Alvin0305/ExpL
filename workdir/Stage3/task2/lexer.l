%{
    #include <stdio.h>
    #include <stdlib.h>

    #include "node/node.h"
    #include "y.tab.h"
    #include "define/constants.h"
    
    int number;
%}

%%

[0-9]+ {
    number = atoi(yytext);
    yylval.node = createConstantNode(number, INT);
    return NUM;
}

"+" {return PLUS;}
"-" {return MINUS;}
"*" {return MUL;}
"/" {return DIV;}
"=" {return ASSIGN;}
";" {return SEMI;}

"==" {return EQ;}
"!=" {return NE;}
">=" {return GE;}
">" {return GT;}
"<=" {return LE;}
"<" {return LT;}

"begin" {return KW_BEGIN;}
"end" {return KW_END;}

"read" {return READ;}
"write" {return WRITE;}

"if" {return KW_IF;}
"then" {return KW_THEN;}
"else" {return KW_ELSE;}
"endif" {return KW_ENDIF;}

"while" {return KW_WHILE;}
"do" {return KW_DO;}
"endwhile" {return KW_ENDWHILE;}

[a-z] {
    yylval.node = createVariableNode(yytext, INT);
    return ID;
}

[\t ] { }
[()] {return yytext[0];}
[\n] { }
. {printf("unknown character %s\n", yytext); exit(1);}

%%

int yywrap() {
    return 1;
}