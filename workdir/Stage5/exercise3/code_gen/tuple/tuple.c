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

int generateGetTupleMemoryAddrCode(struct tnode *tupleAccessNode) {
    struct tnode *tupleIdNode = tupleAccessNode->left;
    struct tnode *tupleFieldNode = tupleAccessNode->right;

    if (!tupleIdNode || !tupleFieldNode) {
        compilerError(E_AST_STRUCTURE_INCORRECT, tupleAccessNode);
    } else if (tupleIdNode->nodeType != NODE_VARIABLE) {
        compilerError(E_AST_NODE_TYPE_MISMATCH, tupleAccessNode->left, NODE_VARIABLE, tupleIdNode->nodeType);
    } else if (tupleFieldNode->nodeType != NODE_VARIABLE) {
        compilerError(E_AST_NODE_TYPE_MISMATCH, tupleAccessNode->right, NODE_VARIABLE, tupleFieldNode->nodeType);
    }

    char *tupleName = tupleIdNode->varName;
    char *fieldName = tupleFieldNode->varName;

    if (!tupleName) {
        compilerError(E_AST_NULL_VARNAME, "Tuple Name");
    } else if (!fieldName) {
        compilerError(E_AST_NULL_VARNAME, "Tuple Field Name");
    }

    LSymbol *localEntry = local_st_lookup(tupleName);
    GSymbol *globalEntry = lookupGST(tupleName);
    TupleType *tupleType = NULL;
    int binding;

    if (localEntry) {
        tupleType = localEntry->tupleEntry;
        binding = localEntry->binding;
    } else if (globalEntry) {
        tupleType = globalEntry->tupleEntry;
        binding = globalEntry->binding;
    } else {
        compilerError(E_VARIABLE_USED_BEFORE_DECLARATION, tupleName);
    }

    int offsetOfField = getOffsetOfTupleField(tupleType, fieldName);
    int memAddr = binding + offsetOfField;

    int freeReg = getFreeRegister();
    if (localEntry) {
        fprintf(target_file, "MOV R%d, BP\n", freeReg);
        fprintf(target_file, "ADD R%d, %d\n", freeReg, memAddr);
        return freeReg;
    } else if (globalEntry) {
        fprintf(target_file, "MOV R%d, %d\n", freeReg, memAddr);
        return freeReg;
    }

    return __NONE__;
}

int generateGetTuplePointerMemoryAddrCode(struct tnode *tuplePointerAccessNode) {
    struct tnode *tupleIdNode = tuplePointerAccessNode->left;
    struct tnode *tupleFieldNode = tuplePointerAccessNode->right;

    if (!tupleIdNode || !tupleFieldNode) {
        compilerError(E_AST_STRUCTURE_INCORRECT, tuplePointerAccessNode);
    } else if (tupleIdNode->nodeType != NODE_VARIABLE) {
        compilerError(E_AST_NODE_TYPE_MISMATCH, tuplePointerAccessNode->left, NODE_VARIABLE, tupleIdNode->nodeType);
    } else if (tupleFieldNode->nodeType != NODE_VARIABLE) {
        compilerError(E_AST_NODE_TYPE_MISMATCH, tuplePointerAccessNode->right, NODE_VARIABLE, tupleFieldNode->nodeType);
    }

    char *tupleName = tupleIdNode->varName;
    char *fieldName = tupleFieldNode->varName;

    if (!tupleName) {
        compilerError(E_AST_NULL_VARNAME, "Tuple Name");
    } else if (!fieldName) {
        compilerError(E_AST_NULL_VARNAME, "Tuple Field Name");
    }

    LSymbol *localEntry = local_st_lookup(tupleName);
    GSymbol *globalEntry = lookupGST(tupleName);
    TupleType *tupleType = NULL;
    int binding;

    if (localEntry) {
        tupleType = localEntry->tupleEntry;
        binding = localEntry->binding;
    } else if (globalEntry) {
        tupleType = globalEntry->tupleEntry;
        binding = globalEntry->binding;
    } else {
        compilerError(E_VARIABLE_USED_BEFORE_DECLARATION, tupleName);
    }

    int offsetOfField = getOffsetOfTupleField(tupleType, fieldName);

    printf("offset: %d, binding: %d\n", offsetOfField, binding);

    int freeReg = getFreeRegister();
    int memAddrReg = getFreeRegister();

    if (localEntry) {
        fprintf(target_file, "MOV R%d, BP\n", freeReg);
        fprintf(target_file, "ADD R%d, %d\n", freeReg, binding);
        fprintf(target_file, "MOV R%d, [R%d]\n", memAddrReg, freeReg);
        fprintf(target_file, "ADD R%d, %d\n", memAddrReg, offsetOfField);

        releaseRegister(freeReg);
        return memAddrReg;
    } else if (globalEntry) {
        fprintf(target_file, "MOV R%d, [%d]\n", freeReg, binding);
        fprintf(target_file, "ADD R%d, %d\n", freeReg, offsetOfField);

        releaseRegister(memAddrReg);
        return freeReg;
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
