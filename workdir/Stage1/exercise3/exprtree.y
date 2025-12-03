%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "exprtree.h"
    #include "exprtree.c"

    #define regIndex int

    int yylex(void);
    void yyerror(char const *msg);

    int regCount = 0;
    int totalRegs = 20;

    int getReg();
    int freeReg();

    regIndex codeGen(struct tnode *node);

    FILE* target_file;
%}

%union {
    struct tnode * node;
}

%type <node> expr program NUM

%token NUM PLUS MINUS MUL DIV END
%left PLUS MINUS
%left MUL DIV

%%

program : expr END {
    codeGen($1);
    printf("Finished\n");
    exit(0);
};

expr : PLUS expr expr { $$ = createOperatorNode('+', $2, $3); }
    | MINUS expr expr { $$ = createOperatorNode('-', $2, $3); }
    | MUL expr expr { $$ = createOperatorNode('*', $2, $3); }
    | DIV expr expr { $$ = createOperatorNode('/', $2, $3); }
    | '(' expr ')' { $$ = $2; }
    | NUM { $$ = createLeafNode($1->val); }
    ;

%%

void yyerror(char const *msg) {
    printf("[Error] : %s\n", msg);
    return;
}

int getReg() {
    if (regCount == totalRegs) {
        freeReg();
        return getReg();
    } else {
        return regCount++;
    }
}

int freeReg() {
    if (regCount != 0) {
        return regCount--;
    }
}

void operatorInstructionGen(char op, regIndex leftReg, regIndex rightReg) {
    switch (op) {
        case '+':
            fprintf(target_file, "ADD R%d, R%d\n", leftReg, rightReg);
            break;
        case '-':
            fprintf(target_file, "SUB R%d, R%d\n", leftReg, rightReg);
            break;
        case '*':
            fprintf(target_file, "MUL R%d, R%d\n", leftReg, rightReg);
            break;
        case '/':
            fprintf(target_file, "DIV R%d, R%d\n", leftReg, rightReg);
            break;
    }
}

regIndex codeGen(struct tnode *node) {
    if (!node) return -1;

    int leftReg = codeGen(node->left);
    int rightReg = codeGen(node->right);

    if (!node->op) {
        int newReg = getReg();
        fprintf(target_file, "MOV R%d, %d\n", newReg, node->val);

        return newReg;
    } else if (leftReg != -1 && rightReg != -1) {
        operatorInstructionGen(node->op[0], leftReg, rightReg);
        freeReg();

        return leftReg;
    } else {
        return -1;
    }
}

int main() {
    target_file = fopen("result.xsm", "w");
    return yyparse();
}