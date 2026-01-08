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
    void generateHeader();
    void generateExitCode();
    void store(int memAddr, int reg);
    void write(int memAddr);

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
    generateHeader();
    store(4096, codeGen($1));
    write(4096);
    generateExitCode();
    printf("Finished\n");
    exit(0);
};

expr : expr PLUS expr { $$ = createOperatorNode('+', $1, $3); }
    | expr MUL expr { $$ = createOperatorNode('*', $1, $3); }
    | expr MINUS expr { $$ = createOperatorNode('-', $1, $3); }
    | expr DIV expr { $$ = createOperatorNode('/', $1, $3); }
    | '(' expr ')' { $$ = $2; }
    | NUM { $$ = createLeafNode($1->val); }
    ;

%%

void yyerror(char const *msg) {
    printf("[Error] : %s\n", msg);
    return;
}

void store(int memAddr, int reg) {
    fprintf(target_file, "MOV [%d], R%d\n", memAddr, reg);
}

void write(int varMemAddr) {
    int reg = getReg();
    fprintf(target_file, "MOV R%d, \"%s\"\n", reg, "Write");
    fprintf(target_file, "PUSH R%d\n", reg);
    fprintf(target_file, "MOV R%d, %d\n", reg, -2);
    fprintf(target_file, "PUSH R%d\n", reg);
    fprintf(target_file, "MOV R%d, [%d]\n", reg, varMemAddr);
    fprintf(target_file, "PUSH R%d\n", reg);
    fprintf(target_file, "PUSH R%d\n", reg);
    fprintf(target_file, "PUSH R%d\n", reg);
    fprintf(target_file, "CALL 0\n");
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

void generateHeader() {
    fprintf(target_file, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", 0, 2056, 0, 0, 0, 0, 0, 0);
    fprintf(target_file, "BRKP\n");
    fprintf(target_file, "MOV SP, %d\n", 4097);
}

void generateExitCode() {
    int reg = getReg();
    fprintf(target_file, "MOV R%d, \"%s\"\n", reg, "Exit");
    fprintf(target_file, "PUSH R%d\n", reg);
    fprintf(target_file, "PUSH R%d\n", reg);
    fprintf(target_file, "PUSH R%d\n", reg);
    fprintf(target_file, "PUSH R%d\n", reg);
    fprintf(target_file, "PUSH R%d\n", reg);
    fprintf(target_file, "CALL 0\n");
    freeReg();
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