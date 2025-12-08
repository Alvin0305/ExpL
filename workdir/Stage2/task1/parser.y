%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "node/node.h"
    #include "node/node.c"

    #include "define/constants.h"

    int yylex(void);
    void yyerror(char const *msg);

    int regCount = 0;
    int totalRegs = 20;

    int getReg();
    int freeReg();

    void generateHeader();
    regIndex codeGen(struct tnode *node);

    FILE *target_file;
    extern FILE *yyin;
%}

%union {
    struct tnode *node;
}

%type <node> expr program statementList statement inputStatement outputStatement assignmentStatement statement ID NUM

%token NUM PLUS MINUS MUL DIV KW_BEGIN KW_END ID READ WRITE ASSIGN SEMI

%left PLUS MINUS
%left MUL DIV

%%

program : KW_BEGIN statementList KW_END {
        generateHeader();
        print($2);
        print_inorder($2);
        printf("Finished\n");
        exit(0);
    }
    | KW_BEGIN KW_END
    ;

statementList : statementList statement { $$ = createConnectorNode($1, $2); }
    | statement { $$ = $1; }
    ;

statement : inputStatement { $$ = $1; }
    | outputStatement { $$ = $1; }
    | assignmentStatement { $$ = $1; }
    ;

inputStatement : READ '(' ID ')' SEMI { $$ = createReadNode($3); }
    ;

outputStatement : WRITE '(' expr ')' SEMI { $$ = createWriteNode($3); }
    ;

assignmentStatement : ID ASSIGN expr SEMI { $$ = createAssignNode($1, $3); }
    ;

expr : expr PLUS expr { $$ = createArithOpNode(NODE_ADD, $1, $3); }
    | expr MINUS expr { $$ = createArithOpNode(NODE_SUB, $1, $3); }
    | expr MUL expr { $$ = createArithOpNode(NODE_MUL, $1, $3); }
    | expr DIV expr { $$ = createArithOpNode(NODE_DIV, $1, $3); }
    | '(' expr ')' { $$ = $2; }
    | NUM { $$ = $1; }
    | ID { $$ = $1; }
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

void generateHeader() {
    fprintf(target_file, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", 
        0, 2056, 0, 0, 0, 0, 0, 0);
    fprintf(target_file, "BRKP\n");
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

    switch(node->nodeType) {
        case NODE_CONSTANT:
            int newReg = getReg();
            fprintf(target_file, "MOV R%d, %d\n", newReg, node->val);

            return newReg;

        case NODE_VARIABLE:
            int offset = (int) node->varName[0] - 'a';
            int memoryAddress = STACK_START + offset;

            return memoryAddress;
        
        case NODE_ADD:
            fprintf(target_file, "ADD R%d, R%d\n", leftReg, rightReg);
            return leftReg;
        
        case NODE_SUB:
            fprintf(target_file, "SUB R%d, R%d\n", leftReg, rightReg);
            return leftReg;

        case NODE_MUL:
            fprintf(target_file, "MUL R%d, R%d\n", leftReg, rightReg);
            return leftReg;

        case NODE_DIV:
            fprintf(target_file, "DIV R%d, R%d\n", leftReg, rightReg);
            return leftReg;

        

    }

    if (node->nodeType == NODE_CONSTANT) {
        
    } else if (node->nodeType == NODE_VARIABLE) {
        
    } else if (node->nodeType == NODE_ADD) {
        
    } else if (node->nodeType == NODE_SUB) {
        fprintf(target_file, "SUB R%d, R%d\n", leftReg, rightReg);

        return leftReg;
    } else if (node->nodeType == NODE_MUL) {
        fprintf(target_file, "MUL R%d, R%d\n", leftReg, rightReg);

        return leftReg;
    } else if (node->nodeType == NODE_DIV) {
        fprintf(target_file, "DIV R%d, R%d\n", leftReg, rightReg);

        return leftReg;
    }

    // int leftReg = codeGen(node->left);
    // int rightReg = codeGen(node->right);

    // if (!node->op) {
    //     int newReg = getReg();
    //     fprintf(target_file, "MOV R%d, %d\n", newReg, node->val);

    //     return newReg;
    // } else if (leftReg != -1 && rightReg != -1) {
    //     operatorInstructionGen(node->op[0], leftReg, rightReg);
    //     freeReg();

    //     return leftReg;
    // } else {
    //     return -1;
    // }
}

int main() {
    target_file = fopen(OUTPUT_FILE, "w");

    FILE *source_file = fopen(SOURCE_FILE, "r");
    yyin = source_file;

    return yyparse();
}