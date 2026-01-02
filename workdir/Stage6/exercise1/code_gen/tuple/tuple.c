#include <stdio.h>
#include <stdlib.h>

#include "../../define/constants.h"
#include "../../error_handler/error_handler.h"
#include "../../g_symbol_table/g_symbol_table.h"
#include "../../local_symbol_table/local_symbol_table.h"
#include "../../register/register.h"
#include "../../tuple_type_table/tuple_type_table.h"

#include "../code_gen.h"
#include "tuple.h"

typedef enum {
    SCOPE_LOCAL,
    SCOPE_GLOBAL,
    SCOPE_NONE
} Scope;

static Scope scope = SCOPE_NONE;

static struct TupleType *getTupleTypeFromST(char *tupleTypeName) {
    LSymbol *localEntry = lookupLST(tupleTypeName);
    GSymbol *globalEntry = lookupGST(tupleTypeName);

    if (localEntry) {
        scope = SCOPE_LOCAL;
        return localEntry->tupleType;
    } else if (globalEntry) {
        scope = SCOPE_GLOBAL;
        return globalEntry->tupleType;
    } else {
        scope = SCOPE_NONE;
        compilerError(E_VARIABLE_USED_BEFORE_DECLARATION, tupleTypeName);
        return NULL;
    }
}

static int getBindingFromST(char *tupleTypeName) {
    LSymbol *localEntry = lookupLST(tupleTypeName);
    GSymbol *globalEntry = lookupGST(tupleTypeName);

    if (localEntry) {
        scope = SCOPE_LOCAL;
        return localEntry->binding;
    } else if (globalEntry) {
        scope = SCOPE_GLOBAL;
        return globalEntry->binding;
    } else {
        scope = SCOPE_NONE;
        compilerError(E_VARIABLE_USED_BEFORE_DECLARATION, tupleTypeName);
        return __NONE__;
    }
}

int generateGetTupleMemoryAddrCode(struct tnode *tupleAccessNode) {
    struct tnode *tupleIdNode = tupleAccessNode->left;
    struct tnode *tupleFieldNode = tupleAccessNode->right;

    char *tupleName = tupleIdNode->varName;
    char *fieldName = tupleFieldNode->varName;

    TupleType *tupleType = getTupleTypeFromST(tupleName);
    int binding = getBindingFromST(tupleName);

    int offsetOfField = getOffsetOfTupleField(tupleType, fieldName);
    int memAddr = binding + offsetOfField;

    int freeReg = getFreeRegister();
    if (scope == SCOPE_LOCAL) {
        fprintf(target_file, "MOV R%d, BP\n", freeReg);
        fprintf(target_file, "ADD R%d, %d\n", freeReg, memAddr);
        return freeReg;
    } else if (scope == SCOPE_GLOBAL) {
        fprintf(target_file, "MOV R%d, %d\n", freeReg, memAddr);
        return freeReg;
    } else {
        compilerError(E_VARIABLE_USED_BEFORE_DECLARATION, tupleName);
        return __NONE__;
    }
}

int generateGetTuplePointerMemoryAddrCode(struct tnode *tuplePointerAccessNode) {
    struct tnode *tupleIdNode = tuplePointerAccessNode->left;
    struct tnode *tupleFieldNode = tuplePointerAccessNode->right;

    char *tupleName = tupleIdNode->varName;
    char *fieldName = tupleFieldNode->varName;

    TupleType *tupleType = getTupleTypeFromST(tupleName);
    int binding = getBindingFromST(tupleName);

    int offsetOfField = getOffsetOfTupleField(tupleType, fieldName);

    int freeReg = getFreeRegister();
    int memAddrReg = getFreeRegister();

    if (scope == SCOPE_LOCAL) {
        fprintf(target_file, "MOV R%d, BP\n", freeReg);
        fprintf(target_file, "ADD R%d, %d\n", freeReg, binding);
        fprintf(target_file, "MOV R%d, [R%d]\n", memAddrReg, freeReg);
        fprintf(target_file, "ADD R%d, %d\n", memAddrReg, offsetOfField);

        releaseRegister(freeReg);
        return memAddrReg;
    } else if (scope == SCOPE_GLOBAL) {
        fprintf(target_file, "MOV R%d, [%d]\n", freeReg, binding);
        fprintf(target_file, "ADD R%d, %d\n", freeReg, offsetOfField);

        releaseRegister(memAddrReg);
        return freeReg;
    } else {
        compilerError(E_VARIABLE_USED_BEFORE_DECLARATION, tupleName);
        return __NONE__;
    }

    return __NONE__;
}

int generateTupleAccessCode(struct tnode *root) {
    int tupleMemAddrReg = generateGetTupleMemoryAddrCode(root);

    int freeReg = getFreeRegister();
    fprintf(target_file, "MOV R%d, [R%d]\n", freeReg, tupleMemAddrReg);
    releaseRegister(tupleMemAddrReg);

    return freeReg;
}

int generateTuplePointerAccessCode(struct tnode *root) {
    int tupleMemAddrReg = generateGetTuplePointerMemoryAddrCode(root);

    int freeReg = getFreeRegister();
    fprintf(target_file, "MOV R%d, [R%d]\n", freeReg, tupleMemAddrReg);
    releaseRegister(tupleMemAddrReg);

    return freeReg;
}

void generateTupleAssignCode(struct tnode *node) {
    struct tnode *tupleAccessNode = node->left;
    struct tnode *exprNode = node->right;

    int memAddrReg = generateGetTupleMemoryAddrCode(tupleAccessNode);
    int exprReg = generateCode(exprNode);

    if (memAddrReg == __NONE__) {
        printf("[ERROR]: Memory Address got after tuple access is None\n");
        exit(1);
    } else {
        fprintf(target_file, "MOV [R%d], R%d\n", memAddrReg, exprReg);
    }

    releaseRegister(memAddrReg);
    releaseRegister(exprReg);
}

void generateTuplePointerAssignCode(struct tnode *node) {
    struct tnode *tupleAccessNode = node->left;
    struct tnode *exprNode = node->right;

    int memAddrReg = generateGetTuplePointerMemoryAddrCode(tupleAccessNode);
    int exprReg = generateCode(exprNode);

    if (memAddrReg == __NONE__) {
        printf("[ERROR]: Memory Address got after tuple pointer access is NONE\n");
        exit(1);
    } else {
        fprintf(target_file, "MOV [R%d], R%d\n", memAddrReg, exprReg);
    }

    releaseRegister(memAddrReg);
    releaseRegister(exprReg);
}
