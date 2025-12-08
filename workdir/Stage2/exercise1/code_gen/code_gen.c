#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "code_gen.h"
#include "../define/constants.h"
#include "../node/node.h"
#include "../register/register.h"

int generateAddRegCode(int leftReg, int rightReg) {
    fprintf(target_file, "ADD R%d, R%d\n", leftReg, rightReg);
    releaseRegister(rightReg);
    return leftReg;
}

int generateSubtractRegCode(int leftReg, int rightReg) {
    fprintf(target_file, "SUB R%d, R%d\n", leftReg, rightReg);
    releaseRegister(rightReg);
    return leftReg;
}

int generateMultiplyRegCode(int leftReg, int rightReg) {
    fprintf(target_file, "MUL R%d, R%d\n", leftReg, rightReg);
    releaseRegister(rightReg);
    return leftReg;
}

int generateDivideRegCode(int leftReg, int rightReg) {
    fprintf(target_file, "DIV R%d, R%d\n", leftReg, rightReg);
    releaseRegister(rightReg);
    return leftReg;
}

void generateWriteToMemoryCode(int reg, int varMemAddr) {
    fprintf(target_file, "MOV [%d], R%d\n", varMemAddr, reg);
}

void generateReadFromConsoleCode(int varMemAddr) {
    int functionNameReg = getFreeRegister();
    int fileDescriptorReg = getFreeRegister();
    int memAddrReg = getFreeRegister();
    int arg3Reg = getFreeRegister();
    int returnReg = getFreeRegister();
    
    fprintf(target_file, "MOV R%d, \"%s\"\n", functionNameReg, "Read");
    fprintf(target_file, "PUSH R%d\n", functionNameReg);

    fprintf(target_file, "MOV R%d, -1\n", fileDescriptorReg);
    fprintf(target_file, "PUSH R%d\n", fileDescriptorReg);

    fprintf(target_file, "MOV R%d, %d\n", memAddrReg, varMemAddr);
    fprintf(target_file, "PUSH R%d\n", memAddrReg);

    fprintf(target_file, "PUSH R%d\n", arg3Reg);
    fprintf(target_file, "PUSH R%d\n", returnReg);

    fprintf(target_file, "CALL 0\n");
    fprintf(target_file, "SUB SP, 5\n");

    releaseRegister(functionNameReg);
    releaseRegister(fileDescriptorReg);
    releaseRegister(memAddrReg);
    releaseRegister(arg3Reg);
    releaseRegister(returnReg);
}

void generateWriteToConsoleCode(int reg) {
    int functionNameReg = getFreeRegister();
    int fileDescriptorReg = getFreeRegister();
    int arg3Reg = getFreeRegister();
    int returnReg = getFreeRegister();
    
    fprintf(target_file, "MOV R%d, \"Write\"\n", functionNameReg);
    fprintf(target_file, "PUSH R%d\n", functionNameReg);

    fprintf(target_file, "MOV R%d, -2\n", fileDescriptorReg);
    fprintf(target_file, "PUSH R%d\n", fileDescriptorReg);

    fprintf(target_file, "PUSH R%d\n", reg);
    fprintf(target_file, "PUSH R%d\n", arg3Reg);
    fprintf(target_file, "PUSH R%d\n", returnReg);

    fprintf(target_file, "CALL 0\n");
    fprintf(target_file, "SUB SP, 5\n");

    releaseRegister(functionNameReg);
    releaseRegister(returnReg);
    releaseRegister(arg3Reg);
    releaseRegister(fileDescriptorReg);
}

void generateExitCode() {
    int freeReg = getFreeRegister();

    fprintf(target_file, "MOV R%d, \"Exit\"\n", freeReg);
    fprintf(target_file, "PUSH R%d\n", freeReg);
    fprintf(target_file, "PUSH R%d\n", freeReg);
    fprintf(target_file, "PUSH R%d\n", freeReg);
    fprintf(target_file, "PUSH R%d\n", freeReg);
    fprintf(target_file, "PUSH R%d\n", freeReg);
    fprintf(target_file, "CALL 0\n");

    releaseRegister(freeReg);
}

int generateLoadConstantCode(int val) {
    int freeReg = getFreeRegister();
    fprintf(target_file, "MOV R%d, %d\n", freeReg, val);
    return freeReg;
}

int generateHeader() {
    fprintf(target_file, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", 0, 2056, 0, 0, 0, 0, 0, 0);
    fprintf(target_file, "MOV SP, %d\n", STACK_START - 1 + NUM_STATIC_VARS);
    fprintf(target_file, "BRKP\n");
}

int generateAssignVariableCode(struct tnode *node) {
    int varMemAddr = getAddressOfVariable(node->left);
    int rightReg = generateUserCode(node->right);

    fprintf(target_file, "MOV [%d], R%d\n", varMemAddr, rightReg);
    return NO_RETURN;
}

int generateLoadVariableCode(struct tnode *node) {
    int varMemAddr = getAddressOfVariable(node);
    int freeReg = getFreeRegister();

    fprintf(target_file, "MOV R%d, [%d]\n", freeReg, varMemAddr);
    return freeReg;
}

int generateUserCode(struct tnode *root) {
    if (!root) return NO_RETURN;

    switch (root->nodeType) {
        case NODE_EMPTY:
            return NO_RETURN;

        case NODE_ASSIGN: 
            return generateAssignVariableCode(root);

        case NODE_CONNECTOR:
            generateUserCode(root->left);
            generateUserCode(root->right);
            return NO_RETURN;

        case NODE_VARIABLE:
            return generateLoadVariableCode(root);

        case NODE_CONSTANT:
            return generateLoadConstantCode(root->val);

        case NODE_READ:
            int varMemAddr = getAddressOfVariable(root->left);
            generateReadFromConsoleCode(varMemAddr);
            return NO_RETURN;

        case NODE_WRITE:
            int exprReg = generateUserCode(root->left);
            generateWriteToConsoleCode(exprReg);
            return NO_RETURN;

        case NODE_ADD:
        case NODE_SUB:
        case NODE_MUL:
        case NODE_DIV: {
            int leftReg = generateUserCode(root->left);
            int rightReg = generateUserCode(root->right);

            switch(root->nodeType) {
                case NODE_ADD: return generateAddRegCode(leftReg, rightReg);
                case NODE_SUB: return generateSubtractRegCode(leftReg, rightReg);
                case NODE_MUL: return generateMultiplyRegCode(leftReg, rightReg);
                case NODE_DIV: return generateDivideRegCode(leftReg, rightReg);
            }
        }
    }
}

int generateCode(tnode *root) {
    initializeRegisters();

    generateHeader();
    generateUserCode(root);
    generateExitCode();
}

int getAddressOfVariable(struct tnode *node) {
    int varName = (int) node->varName[0] - 'a';
    return STACK_START + varName;
}