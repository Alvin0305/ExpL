#include <stdio.h>

#include "../define/constants.h"
#include "../node/node.h"

int regCount = 0;

int getFreeRegister() {
    if (regCount == TOTAL_REGISTERS) {
        freeReg();
        return getReg();
    } else {
        return regCount++;
    }
}

int releaseRegister() {
    if (regCount != 0) {
        return regCount--;
    }
}

int add(int leftReg, int rightReg, FILE *target_file) {
    fprintf(target_file, "ADD R%d, R%d\n", leftReg, rightReg);
    return leftReg;
}

int subtract(int leftReg, int rightReg, FILE *target_file) {
    fprintf(target_file, "SUB R%d, R%d\n", leftReg, rightReg);
    return leftReg;
}

int multiply(int leftReg, int rightReg, FILE *target_file) {
    fprintf(target_file, "MUL R%d, R%d\n", leftReg, rightReg);
    return leftReg;
}

int divide(int leftReg, int rightReg, FILE *target_file) {
    fprintf(target_file, "DIV R%d, R%d\n", leftReg, rightReg);
    return leftReg;
}

int read(int offset, FILE *target_file) {
    int memAddr = STACK_START + offset;

    int availableReg = getFreeRegister();
    fprintf(target_file, "MOV R%d, \"Read\"\n", availableReg);
    fprintf(target_file, "PUSH R%d\n", availableReg);
    fprintf(target_file, "MOV R%d, -1\n", availableReg);
    fprintf(target_file, "PUSH R%d\n", availableReg);
    fprintf(target_file, "PUSH R%d\n", availableReg);
    fprintf(target_file, "PUSH R%d\n", availableReg);
    fprintf(target_file, "PUSH R%d\n", availableReg);
    fprintf(target_file, "CALL 0\n");

    fprintf(target_file, "SUB SP, 5\n");

    releaseRegister(availableReg);
}

int write(int offset, FILE *target_file) {
    int memAddr = STACK_START + offset;

    int availableReg = getFreeRegister();
    fprintf(target_file, "MOV R%d, \"Write\"\n", availableReg);
    fprintf(target_file, "PUSH R%d\n", availableReg);
    fprintf(target_file, "MOV R%d, -2\n", availableReg);
    fprintf(target_file, "PUSH R%d\n", availableReg);
    fprintf(target_file, "PUSH R%d\n", availableReg);
    fprintf(target_file, "PUSH R%d\n", availableReg);
    fprintf(target_file, "PUSH R%d\n", availableReg);
    fprintf(target_file, "CALL 0\n");

    fprintf(target_file, "SUB SP, 5\n");

    releaseRegister(availableReg);
}

int loadConstant(int val, FILE *target_file) {
    int freeReg = getFreeRegister();
    fprintf(target_file, "MOV R%d, %d\n", freeReg, val);
    return freeReg;
}

int codeGen(tnode *root, FILE *target_file) {
    if (!root) return -1;

    int leftReg = codeGen(root->left, target_file);
    int rightReg = codeGen(root->right, target_file);

    switch (root->nodeType) {
        case NODE_CONSTANT:
            return loadConstant(root->val, target_file);
        case NODE_ADD:
            return add(leftReg, rightReg, target_file);
        case NODE_SUB:
            return subtract(leftReg, rightReg, target_file);
        case NODE_MUL:
            return multiply(leftReg, rightReg, target_file);
        case NODE_DIV:
            return divide(leftReg, rightReg, target_file);
        case NODE_READ:
            return read(root->varName[0], target_file);
        case NODE_WRITE:
            return write(root->varName[0], target_file);
    }
}