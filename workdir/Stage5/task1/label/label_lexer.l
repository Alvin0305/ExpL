%{
    #include <stdio.h>
    #include <string.h>
    #include "define/constants.h"
    #include "label/label.h"

    int addr = CODE_START;
    int scanNumber = 1;

    FILE *translatedFile;
%}

%option noinput
%option nounput

number [0-9]+
reg R{number}
label_value L{number}

label_header {label_value}:\n

jz_instruction (JZ[ ]{reg},[ ]{label_value}\n)
jnz_instruction (JNZ[ ]{reg},[ ]{label_value}\n)
jmp_instruction (JMP[ ]{label_value}\n)
call_instruction (CALL[ ]{label_value}\n)

header (0\n{number}\n0\n0\n0\n0\n0\n0\n)

%%

{header} { if (scanNumber == 2) { 
        fprintf(translatedFile, "%s", yytext); 
        }
    }

{label_header} {
    if (scanNumber == 1) {
        char labelName[yyleng];
        sscanf(yytext, "%s:", labelName);

        labelName[strlen(labelName) - 1] = '\0';

        addNewLabel(labelName, addr);
    }
}

{jz_instruction} {
    if (scanNumber == 1) {
        addr += 2;
    } else if (scanNumber == 2) {
        char reg[5], labelName[yyleng + 5];
        sscanf(yytext, "JZ %s %s", reg, labelName);

        int memAddr = getMemAddrForLabel(labelName);

        fprintf(translatedFile, "JZ %s %d\n", reg, memAddr);
    }
}

{jnz_instruction} {
    if (scanNumber == 1) {
        addr += 2;
    } else if (scanNumber == 2) {
        char reg[5], labelName[yyleng];
        sscanf(yytext, "JNZ %s %s", reg, labelName);

        int memAddr = getMemAddrForLabel(labelName);
        fprintf(translatedFile, "JNZ %s %d\n", reg, memAddr);
    }
}

{jmp_instruction} {
    if (scanNumber == 1) {
        addr += 2;
    } else if (scanNumber == 2) {
        char labelName[yyleng];
        sscanf(yytext, "JMP %s", labelName);

        int memAddr = getMemAddrForLabel(labelName);
        fprintf(translatedFile, "JMP %d\n", memAddr);
    }
}

{call_instruction} {
    if (scanNumber == 1) {
        addr += 2;
    } else if (scanNumber == 2) {
        char labelName[yyleng];
        sscanf(yytext, "CALL %s", labelName);

        int memAddr = getMemAddrForLabel(labelName);
        fprintf(translatedFile, "CALL %d\n", memAddr);
    }
}

.*\n {
    if (scanNumber == 1) {
        addr += 2;
    } else if (scanNumber == 2) {
        fprintf(translatedFile, yytext);
    }
}

%%

int yywrap() {
    if (scanNumber == 1) {
        rewind(yyin);
        scanNumber++;

        return 0;
    } else {
        return 1;
    }
}

int main() {
    yyin = fopen(INTERMEDIATE_FILE, "r");
    translatedFile = fopen(TRANSLATED_FILE, "w");

    yylex();

    return 0;
}