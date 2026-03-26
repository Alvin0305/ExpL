#include "../../define/constants.h"
#include "../../error_handler/error_handler.h"
#include "../../g_symbol_table/g_symbol_table.h"
#include "../../local_symbol_table/local_symbol_table.h"
#include "../../type_table/type_table.h"
#include "../../util/util.h"
#include "../node.h"

#include <stdio.h>
#include <stdlib.h>

struct Node *createDereferenceNode(struct Node *idNode) {
    struct Node *node = createEmptyNode();
    struct Node *newIdNode = createVariableUsageNode(idNode->varName);

    node->nodeType = NODE_DEREFERENCE;
    node->left = newIdNode;
    node->right = NULL;
    node->numVal = __NONE__;
    node->varName = NULL;
    node->typeInfo = newIdNode->typeInfo;

    struct LSymbol *localEntry = lookupLST(idNode->varName);
    struct GSymbol *globalEntry = lookupGST(idNode->varName, false, NULL, 0);

    if (localEntry && !localEntry->isPtr) {
        compilerError(E_DEREFERENCING_NON_POINTER_VARIABLE, newIdNode->varName);
    } else if (globalEntry && !globalEntry->isPtr) {
        compilerError(E_DEREFERENCING_NON_POINTER_VARIABLE, newIdNode->varName);
    }

    return node;
}

struct Node *createAddressToNode(struct Node *idNode) {
    struct Node *node = createEmptyNode();
    struct Node *newIdNode = createVariableUsageNode(idNode->varName);
    struct TypeInfo *typeInfo = newIdNode->typeInfo;

    struct LSymbol *localEntry = lookupLST(idNode->varName);
    struct GSymbol *globalEntry = lookupGST(idNode->varName, false, NULL, 0);

    if (localEntry && localEntry->isPtr) {
        compilerError(E_POINTER_TO_POINTER, newIdNode->varName);
    } else if (globalEntry && globalEntry->isPtr) {
        compilerError(E_POINTER_TO_POINTER, newIdNode->varName);
    }

    node->nodeType = NODE_ADDRESS_TO;
    node->left = newIdNode;
    node->right = NULL;
    node->numVal = __NONE__;
    node->type = typeInfo->kind;
    node->varName = NULL;
    node->typeInfo = typeInfo;

    return node;
}

struct Node *createAssignToDereferencedNode(struct Node *idNode, struct Node *exprNode) {
    struct Node *node = createEmptyNode();
    struct Node *newIdNode = createVariableUsageNode(idNode->varName);

    if (newIdNode->gSymbolTableEntry && !newIdNode->gSymbolTableEntry->isPtr) {
        compilerError(E_DEREFERENCING_NON_POINTER_VARIABLE, newIdNode->varName);
    } else if (newIdNode->lSymbolTableEntry && !newIdNode->lSymbolTableEntry->isPtr) {
        compilerError(E_DEREFERENCING_NON_POINTER_VARIABLE, newIdNode->varName);
    } else if (!isTypeCompatible(newIdNode->typeInfo, exprNode->typeInfo)) {
        compilerError(E_TYPE_MISMATCH, "Assignment", newIdNode->typeInfo->kind, exprNode->typeInfo->kind);
    }

    node->nodeType = NODE_ASSIGN_TO_DEREFERENCED;
    node->left = newIdNode;
    node->right = exprNode;
    node->numVal = __NONE__;
    node->type = NONE;
    node->varName = NULL;

    return node;
}
