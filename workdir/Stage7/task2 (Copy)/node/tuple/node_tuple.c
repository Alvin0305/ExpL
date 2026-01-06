#include <stdio.h>
#include <stdlib.h>

#include "../../define/constants.h"
#include "../../error_handler/error_handler.h"
#include "../../g_symbol_table/g_symbol_table.h"
#include "../../local_symbol_table/local_symbol_table.h"
#include "../../type_table/type_table.h"
#include "../../util/util.h"
#include "../node.h"
#include "node_tuple.h"

struct tnode *createTupleAccessNode(struct tnode *idNode, struct tnode *fieldNode) {
    struct tnode *idUsageNode = createVariableUsageNode(idNode->varName);

    struct TupleType *tupleType = NULL;
    if (idUsageNode->lSymbolTableEntry) {
        tupleType = idUsageNode->lSymbolTableEntry->typeInfo->tupleType;
    } else if (idUsageNode->gSymbolTableEntry) {
        tupleType = idUsageNode->gSymbolTableEntry->typeInfo->tupleType;
    } else {
        compilerError(E_VARIABLE_USED_BEFORE_DECLARATION, idNode->varName);
    }

    struct TupleField *fieldEntry = getFieldOfTuple(tupleType, fieldNode->varName);

    if (!fieldEntry) {
        compilerError(E_ACCESS_NON_EXISTING_FIELD_OF_TUPLE, idNode->varName, fieldNode->varName);
    }

    struct tnode *node = createConnectorNode(idUsageNode, fieldNode);

    node->nodeType = NODE_TUPLE_ACCESS;
    node->type = fieldEntry->type;

    return node;
}

struct tnode *createTuplePointerAccessNode(struct tnode *idNode, struct tnode *fieldNode) {
    struct tnode *idUsageNode = createVariableUsageNode(idNode->varName);

    struct TupleType *tupleType = NULL;
    if (idUsageNode->lSymbolTableEntry) {
        tupleType = idUsageNode->lSymbolTableEntry->typeInfo->tupleType;

        if (!idUsageNode->lSymbolTableEntry->isPtr) {
            compilerError(E_DEREFERENCE_NON_POINTER_TUPLE, idUsageNode->varName);
        }
    } else if (idUsageNode->gSymbolTableEntry) {
        tupleType = idUsageNode->gSymbolTableEntry->typeInfo->tupleType;

        if (!idUsageNode->gSymbolTableEntry->isPtr) {
            compilerError(E_DEREFERENCE_NON_POINTER_TUPLE, idUsageNode->varName);
        }
    } else {
        compilerError(E_VARIABLE_USED_BEFORE_DECLARATION, idNode->varName);
    }

    struct TupleField *fieldEntry = getFieldOfTuple(tupleType, fieldNode->varName);

    if (!fieldEntry) {
        compilerError(E_ACCESS_NON_EXISTING_FIELD_OF_TUPLE, idNode->varName, fieldNode->varName);
    }

    struct tnode *node = createConnectorNode(idUsageNode, fieldNode);

    node->nodeType = NODE_TUPLE_POINTER_ACCESS;
    node->type = fieldEntry->type;

    return node;
}

struct tnode *createTupleAssignmentNode(struct tnode *idNode, struct tnode *fieldNode, struct tnode *exprNode) {
    struct tnode *idUsageNode = createVariableUsageNode(idNode->varName);

    struct TupleType *tupleType;
    if (idUsageNode->gSymbolTableEntry) {
        tupleType = idUsageNode->gSymbolTableEntry->typeInfo->tupleType;
    } else if (idUsageNode->lSymbolTableEntry) {
        tupleType = idUsageNode->lSymbolTableEntry->typeInfo->tupleType;
    } else {
        compilerError(E_VARIABLE_USED_BEFORE_DECLARATION, idNode->varName);
    }

    struct TupleField *fieldEntry = getFieldOfTuple(tupleType, fieldNode->varName);

    if (!fieldEntry) {
        compilerError(E_ACCESS_NON_EXISTING_FIELD_OF_TUPLE, idNode->varName, fieldNode->varName);
    }

    if (!areTypeCompatible(createTypeInfo(fieldEntry->type, NULL, lookupTT(dataTypeToString(fieldEntry->type)), NULL),
                           exprNode->typeInfo)) {
        printf("[ERROR]: [%d] Type mismatch in assignment, %s = %s\n", lineNumber, dataTypeToString(fieldEntry->type),
               dataTypeToString(exprNode->type));
        exit(1);
    }

    struct tnode *tupleNode = createConnectorNode(idUsageNode, fieldNode);
    tupleNode->nodeType = NODE_TUPLE_ACCESS;

    struct tnode *node = createConnectorNode(tupleNode, exprNode);
    node->nodeType = NODE_TUPLE_ASSIGN;

    return node;
}

struct tnode *createTuplePointerAssignmentNode(struct tnode *idNode, struct tnode *fieldNode, struct tnode *exprNode) {
    struct tnode *idUsageNode = createVariableUsageNode(idNode->varName);

    struct TupleType *tupleType = NULL;
    if (idUsageNode->lSymbolTableEntry) {
        tupleType = idUsageNode->lSymbolTableEntry->typeInfo->tupleType;

        if (!idUsageNode->lSymbolTableEntry->isPtr) {
            compilerError(E_DEREFERENCE_NON_POINTER_TUPLE, idUsageNode->varName);
        }
    } else if (idUsageNode->gSymbolTableEntry) {
        tupleType = idUsageNode->gSymbolTableEntry->typeInfo->tupleType;

        if (!idUsageNode->gSymbolTableEntry->isPtr) {
            compilerError(E_DEREFERENCE_NON_POINTER_TUPLE, idUsageNode->varName);
        }
    } else {
        compilerError(E_VARIABLE_USED_BEFORE_DECLARATION, idNode->varName);
    }

    struct TupleField *fieldEntry = getFieldOfTuple(tupleType, fieldNode->varName);

    if (!fieldEntry) {
        compilerError(E_ACCESS_NON_EXISTING_FIELD_OF_TUPLE, idNode->varName, fieldNode->varName);
    }

    if (!areTypeCompatible(createTypeInfo(fieldEntry->type, NULL, lookupTT(dataTypeToString(fieldEntry->type)), NULL),
                           exprNode->typeInfo)) {
        printf("[ERROR]: [%d] Type mismatch in assignment, %s = %s\n", lineNumber, dataTypeToString(fieldEntry->type),
               dataTypeToString(exprNode->type));
        exit(1);
    }

    struct tnode *tupleNode = createConnectorNode(idNode, fieldNode);
    tupleNode->nodeType = NODE_TUPLE_POINTER_ACCESS;
    struct tnode *node = createConnectorNode(tupleNode, exprNode);
    node->nodeType = NODE_TUPLE_POINTER_ASSIGN;

    return node;
}