#include "library.h"
#include "../../class_table/class_table.h"
#include "../../define/constants.h"
#include "../../error_handler/error_handler.h"
#include "../../g_symbol_table/g_symbol_table.h"
#include "../../local_symbol_table/local_symbol_table.h"
#include "../../node/node.h"
#include "../../register/register.h"
#include "../../type_table/type_table.h"
#include "../../util/util.h"
#include "../array/array.h"
#include "../function/function.h"
#include "../member_access/member_access.h"

#include <stdlib.h>

#include "../code_gen.h"

void generateReadFromConsoleCode(int varMemAddrReg) {
    int functionNameReg = getFreeRegister();
    int fileDescriptorReg = getFreeRegister();
    int arg3Reg = getFreeRegister();
    int returnReg = getFreeRegister();

    fprintf(target_file, "MOV R%d, \"%s\"\n", functionNameReg, "Read");
    fprintf(target_file, "PUSH R%d\n", functionNameReg);

    fprintf(target_file, "MOV R%d, -1\n", fileDescriptorReg);
    fprintf(target_file, "PUSH R%d\n", fileDescriptorReg);

    fprintf(target_file, "PUSH R%d\n", varMemAddrReg);

    fprintf(target_file, "PUSH R%d\n", arg3Reg);
    fprintf(target_file, "PUSH R%d\n", returnReg);

    fprintf(target_file, "CALL 0\n");
    fprintf(target_file, "SUB SP, 5\n");

    releaseRegister(functionNameReg);
    releaseRegister(fileDescriptorReg);
    releaseRegister(varMemAddrReg);
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
    releaseRegister(reg);
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

int generateHeapInitializeCode(struct Node *initNode) {
    int freeReg = getFreeRegister();

    fprintf(target_file, "MOV R%d, \"%s\"\n", freeReg, "Heapset");
    fprintf(target_file, "PUSH R%d\n", freeReg);
    fprintf(target_file, "PUSH R%d\n", freeReg);
    fprintf(target_file, "PUSH R%d\n", freeReg);
    fprintf(target_file, "PUSH R%d\n", freeReg);
    fprintf(target_file, "PUSH R%d\n", freeReg);
    fprintf(target_file, "CALL 0\n");

    fprintf(target_file, "POP R%d\n", freeReg);
    fprintf(target_file, "SUB SP, 4\n");

    releaseRegister(freeReg);
    return freeReg;
}

void generateAllocCode(struct Node *node) {
    struct Node *left = node->left;
    int nodeType = left->nodeType;

    struct TypeTable *typeTableEntry = node->typeInfo->type;
    struct ClassTable *_class = node->typeInfo->_class;
    int size = typeTableEntry ? typeTableEntry->size : _class ? _class->numFields : 0;

    if (size <= 0 || size > 8) {
        compilerError(E_INVALID_SIZE_FOR_ALLOCATION,
                      node->typeInfo->type ? node->typeInfo->type->name : node->typeInfo->_class->name, size);
    }

    // for (int i = 0; i < TOTAL_REGISTERS; i++) {
    //     fprintf(target_file, "PUSH R%d\n", i);
    // }

    int freeReg = getFreeRegister();
    int returnReg = getFreeRegister();

    fprintf(target_file, "MOV R%d, \"%s\"\n", freeReg, "Alloc");
    fprintf(target_file, "PUSH R%d\n", freeReg);
    fprintf(target_file, "MOV R%d, %d\n", freeReg, size);
    fprintf(target_file, "PUSH R%d\n", freeReg);
    fprintf(target_file, "PUSH R%d\n", freeReg);
    fprintf(target_file, "PUSH R%d\n", freeReg);
    fprintf(target_file, "PUSH R%d\n", freeReg);
    fprintf(target_file, "CALL 0\n");

    fprintf(target_file, "POP R%d\n", returnReg);
    fprintf(target_file, "POP R%d\n", freeReg);
    fprintf(target_file, "POP R%d\n", freeReg);
    fprintf(target_file, "POP R%d\n", freeReg);
    fprintf(target_file, "POP R%d\n", freeReg);

    // for (int i = TOTAL_REGISTERS - 1; i >= 0; i--) {
    //     if (i != returnReg) {
    //         fprintf(target_file, "POP R%d\n", i);
    //     } else {
    //         fprintf(target_file, "POP R%d\n", freeReg);
    //     }
    // }

    releaseRegister(freeReg);

    switch (nodeType) {
        case NODE_VARIABLE:
            freeReg = getAddressOfVariable(left);
            fprintf(target_file, "MOV [R%d], R%d\n", freeReg, returnReg);
            break;

        case NODE_ARRAY_ACCESS:
            freeReg = generateArrayElementAddress(left);
            fprintf(target_file, "MOV [R%d], R%d\n", freeReg, returnReg);
            break;

        case NODE_USER_DEF_TYPE_ACCESS:
            freeReg = resolveMemberAddress(left);
            fprintf(target_file, "MOV [R%d], R%d\n", freeReg, returnReg);
            break;

        case NODE_CLASS_FIELD_ACCESS:
            freeReg = resolveMemberAddress(left);
            break;

        default:
            printf("[WARNING]: Unknown node in alloc: ");
            printNode(left);
    }

    releaseRegister(freeReg);
    releaseRegister(returnReg);
}

void generateFreeCode(struct Node *root) {
    struct Node *idNode = root->left;

    struct GSymbol *globalEntry = lookupGST(idNode->varName, false, NULL, 0);
    struct LSymbol *localEntry = lookupLST(idNode->varName);

    int addrReg = getFreeRegister();
    int freeReg = getFreeRegister();

    if (localEntry) {
        fprintf(target_file, "MOV R%d, BP\n", addrReg);
        fprintf(target_file, "ADD R%d, %d\n", addrReg, localEntry->binding);
        fprintf(target_file, "MOV R%d, [R%d]\n", addrReg, addrReg);
    } else if (globalEntry) {
        fprintf(target_file, "MOV R%d, [%d]\n", addrReg, globalEntry->binding);
    } else {
        compilerError(E_VARIABLE_USED_BEFORE_DECLARATION, idNode->varName);
    }

    fprintf(target_file, "MOV R%d, \"%s\"\n", freeReg, "Free");
    fprintf(target_file, "PUSH R%d\n", freeReg);
    fprintf(target_file, "PUSH R%d\n", addrReg);
    fprintf(target_file, "PUSH R%d\n", freeReg);
    fprintf(target_file, "PUSH R%d\n", freeReg);
    fprintf(target_file, "PUSH R%d\n", freeReg);
    fprintf(target_file, "CALL 0\n");

    fprintf(target_file, "POP R%d\n", freeReg);
    fprintf(target_file, "POP R%d\n", freeReg);
    fprintf(target_file, "POP R%d\n", freeReg);
    fprintf(target_file, "POP R%d\n", freeReg);
    fprintf(target_file, "POP R%d\n", freeReg);

    releaseRegister(freeReg);
    releaseRegister(addrReg);
}
