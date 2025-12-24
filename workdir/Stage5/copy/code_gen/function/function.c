#include "function.h"
#include "../../define/constants.h"
#include "../../error_handler/error_handler.h"
#include "../../g_symbol_table/g_symbol_table.h"
#include "../../local_symbol_table/local_symbol_table.h"
#include "../../register/register.h"
#include "../code_gen.h"

void generateFunctionHeader(int label) {
    fprintf(target_file, "F%d:\n", label);
}

void generateMainCode(struct tnode *root) {
    initializeRegisters();

    fprintf(target_file, "MAIN:\n");

    fprintf(target_file, "MOV SP, %d\n", stackTop);
    fprintf(target_file, "MOV BP, SP\n");
    fprintf(target_file, "BRKP\n");

    fprintf(target_file, "PUSH BP\n");
    fprintf(target_file, "MOV BP, SP\n");

    fprintf(target_file, "ADD SP, %d\n", localBinding);

    generateCode(root);
    generateExitCode();
}

void generateFunctionCode(int functionLabel, struct tnode *root) {
    initializeRegisters();
    generateFunctionHeader(functionLabel);

    fprintf(target_file, "PUSH BP\n");
    fprintf(target_file, "MOV BP, SP\n");
    fprintf(target_file, "ADD SP, %d\n", localBinding);
    generateCode(root);
    generateFunctionJumpBackCode();
}

void generateFunctionReturnCode(struct tnode *returnNode) {
    int returnReg = generateCode(returnNode->left);
    int freeReg = getFreeRegister();

    fprintf(target_file, "MOV R%d, BP\n", freeReg);
    fprintf(target_file, "SUB R%d, 2\n", freeReg);
    fprintf(target_file, "MOV [R%d], R%d\n", freeReg, returnReg);

    releaseRegister(returnReg);
    releaseRegister(freeReg);

    generateFunctionJumpBackCode();
}

void generateFunctionJumpBackCode() {
    int returnAddrReg = getFreeRegister();
    fprintf(target_file, "SUB SP, %d\n", localBinding);
    fprintf(target_file, "POP BP\n");
    fprintf(target_file, "RET\n");

    releaseRegister(returnAddrReg);
}

int generateFunctionCallCode(struct tnode *node) {
    struct tnode *functionNameNode = node->left;
    struct tnode *argListNode = node->right;

    struct GSymbol *entry = lookupGST(functionNameNode->varName);
    if (!entry) {
        throwError(E_FUNCTION_USED_BEFORE_DECLARATION, functionNameNode->varName);
    }

    int numArgs = getNumOfParams(entry->paramList);
    int argRegs[numArgs];
    int index = 0;
    getArgRegs(argListNode, &index, argRegs);

    for (int i = 0; i < numArgs; i++) {
        printf("%d, ", argRegs[i]);
    }

    int returnReg = getFreeRegister();

    generateSaveMachineStatusCode();
    generatePushArgumentsToStackCode(numArgs, argRegs);

    for (int i = 0; i < numArgs; i++) {
        releaseRegister(argRegs[i]);
    }

    fprintf(target_file, "PUSH R%d\n", returnReg);
    fprintf(target_file, "CALL F%d\n", entry->functionLabel);
    returnReg = generateRegainMachineStatusCode(numArgs);

    return returnReg;
}

void generatePushArgumentsToStackCode(int numArgs, int argRegs[]) {
    for (int i = numArgs - 1; i >= 0; i--) {
        fprintf(target_file, "PUSH R%d\n", argRegs[i]);
    }
}

void generateSaveMachineStatusCode() {
    for (int i = 0; i < TOTAL_REGISTERS; i++) {
        fprintf(target_file, "PUSH R%d\n", i);
    }
}

void generatePopArgumentsFromStackCode(int numArgs) {
    int freeReg = getFreeRegister();
    for (int i = 0; i < numArgs; i++) {
        fprintf(target_file, "POP R%d\n", freeReg);
    }
    releaseRegister(freeReg);
}

int generateRegainMachineStatusCode(int numArgs) {
    int freeReg = getFreeRegister();
    int returnReg = getFreeRegister();

    fprintf(target_file, "POP R%d\n", returnReg);

    generatePopArgumentsFromStackCode(numArgs);

    for (int i = TOTAL_REGISTERS - 1; i >= 0; i--) {
        if (i == returnReg) {
            fprintf(target_file, "POP R%d\n", freeReg);
        } else {
            fprintf(target_file, "POP R%d\n", i);
        }
    }
    releaseRegister(freeReg);

    return returnReg;
}

void getArgRegs(struct tnode *argList, int *i, int argRegs[]) {
    if (!argList)
        return;

    switch (argList->nodeType) {
    case NODE_CONNECTOR:
        getArgRegs(argList->left, i, argRegs);
        getArgRegs(argList->right, i, argRegs);
        break;

    default:
        argRegs[*i] = generateCode(argList);
        (*i)++;
        break;
    }
}
