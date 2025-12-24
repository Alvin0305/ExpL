%{
    #include <stdio.h>
    #include <stdlib.h>

    #include "node/node.h"
    #include "y.tab.h"
    #include "define/constants.h"
    
    int lineNumber = 1;
%}

%option noinput
%option nounput

%%

[0-9]+ {
    int number = atoi(yytext);
    yylval.node = createConstantNode(number);
    return NUM;
}

\"[^\n]*\" {
    yylval.node = createStringLiteralNode(yytext);
    return STRING_LITERAL;
}

"//".*\n { }

"+" {return PLUS;}
"-" {return MINUS;}
"*" {return MUL;}
"/" {return DIV;}
"%" {return MOD;}
"=" {return ASSIGN;}
";" {return SEMI;}
"," {return COMMA;}
"&" {return AMPERSAND;}

"++" {return INCREMENT;}
"--" {return DECREMENT;}

"+=" {return ASSIGN_ADD;}
"-=" {return ASSIGN_SUB;}
"*=" {return ASSIGN_MUL;}
"/=" {return ASSIGN_DIV;}
"%=" {return ASSIGN_MOD;}

"==" {return EQ;}
"!=" {return NE;}
">=" {return GE;}
">" {return GT;}
"<=" {return LE;}
"<" {return LT;}

"or" {return OR;}
"and" {return AND;}
"not" {return NOT;}

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
"break" {return KW_BREAK;}
"continue" {return KW_CONTINUE;}
"repeat" {return KW_REPEAT;}
"until" {return KW_UNTIL;}

"decl" {return KW_DECL;}
"enddecl" {return KW_ENDDECL;}
"int" {return TYPE_INT;}
"str" {return TYPE_STRING;}

[a-zA-Z][a-zA-Z0-9_]* {
    yylval.node = createNewVariableNode(yytext);
    return ID;
}

[\t ] { }
[()\[\]] {return yytext[0];}
[\n] { lineNumber++; }
. {printf("unknown character %s\n", yytext); exit(1);}

%%

int yywrap() {
    return 1;
}