#include "function.h"
#include "../../class_table/class_table.h"
#include "../../define/constants.h"
#include "../../error_handler/error_handler.h"
#include "../../g_symbol_table/g_symbol_table.h"
#include "../../local_symbol_table/local_symbol_table.h"
#include "../../register/register.h"

#include "../member_access/member_access.h"
#include "../code_gen.h"
#include "../library/library.h"

void generateFunctionHeader(int label) { fprintf(target_file, "F%d:\n", label); }

void saveMachineStatus() {
    for (int i = 0; i < TOTAL_REGISTERS; i++) {
        fprintf(target_file, "PUSH R%d\n", i);
    }
}

void pushArgsToStack(struct Node *argListNode) {
    if (!argListNode) return;

    switch (argListNode->nodeType) {
        case NODE_CONNECTOR:
            pushArgsToStack(argListNode->right);
            pushArgsToStack(argListNode->left);
            break;

        default:
            if (argListNode->typeInfo->kind == CLASS) {
                int addrReg = resolveMemberAddress(argListNode);
                int valReg = getFreeRegister();

                fprintf(target_file, "MOV R%d, [R%d]\n", valReg, addrReg);
                fprintf(target_file, "PUSH R%d\n", valReg);

                fprintf(target_file, "ADD R%d, 1\n", addrReg);
                fprintf(target_file, "MOV R%d, [R%d]\n", valReg, addrReg);
                fprintf(target_file, "PUSH R%d\n", valReg);

                releaseRegister(valReg);
                releaseRegister(addrReg);
            } else {
                int freeReg = generateCode(argListNode);
                fprintf(target_file, "PUSH R%d\n", freeReg);
                releaseRegister(freeReg);
            }
            break;
    }
}
void popArgsFromStack(struct Param *params) {
    int freeReg = getFreeRegister();
    struct Param *param = params;
    while (param) {
        fprintf(target_file, "POP R%d\n", freeReg);
        if (param->typeInfo->kind == CLASS) {
            printf("param %s is class, so double popping\n", param->name);
            fprintf(target_file, "POP R%d\n", freeReg);
        }
        param = param->next;
    }
    releaseRegister(freeReg);
}

int regainMachineStatus(struct Param *params, struct TypeInfo *returnType) {
    int freeReg = getFreeRegister();
    int returnReg = getFreeRegister();

    if (returnType->kind == CLASS) {
        fprintf(target_file, "POP R%d\n", freeReg);
    }
    fprintf(target_file, "POP R%d\n", returnReg);

    popArgsFromStack(params);

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

// core code gen methods

void generateMainCode(struct Node *root) {
    initializeRegisters();

    fprintf(target_file, "MAIN:\n");

    setupVirtualFunctionTable();
    fprintf(target_file, "BRKP\n");

    fprintf(target_file, "MOV SP, %d\n", stackTop);
    fprintf(target_file, "MOV BP, SP\n");
    fprintf(target_file, "BRKP\n");

    fprintf(target_file, "PUSH BP\n");
    fprintf(target_file, "MOV BP, SP\n");

    fprintf(target_file, "ADD SP, %d\n", localBinding);

    // generateHeapInitializeCode();
    generateCode(root);
    generateExitCode();
}

void generateFunctionCode(int functionLabel, struct Node *root) {
    initializeRegisters();
    generateFunctionHeader(functionLabel);

    fprintf(target_file, "PUSH BP\n");
    fprintf(target_file, "MOV BP, SP\n");
    fprintf(target_file, "ADD SP, %d\n", localBinding);
    generateCode(root);
    generateFunctionJumpBackCode();
}

void generateFunctionReturnCode(struct Node *returnNode) {
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

int generateFunctionCallCode(struct Node *node) {
    struct Node *functionNameNode = node->left;
    struct Node *argListNode = node->right;

    struct GSymbol *entry = lookupGST(functionNameNode->varName);
    if (!entry) {
        compilerError(E_FUNCTION_USED_BEFORE_DECLARATION, functionNameNode->varName);
    }

    int returnReg = getFreeRegister();

    saveMachineStatus();
    pushArgsToStack(argListNode);

    if (entry->typeInfo->kind == CLASS) {
        fprintf(target_file, "PUSH R%d\n", returnReg);
    }

    fprintf(target_file, "PUSH R%d\n", returnReg);
    fprintf(target_file, "CALL F%d\n", entry->functionLabel);

    releaseRegister(returnReg);
    returnReg = regainMachineStatus(entry->paramList, entry->typeInfo);

    return returnReg;
}
