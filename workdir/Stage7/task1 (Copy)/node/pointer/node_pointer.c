#include "../../define/constants.h"
#include "../../error_handler/error_handler.h"
#include "../../g_symbol_table/g_symbol_table.h"
#include "../../local_symbol_table/local_symbol_table.h"
#include "../../type_table/type_table.h"
#include "../../util/util.h"
#include "../node.h"

#include <stdio.h>
#include <stdlib.h>

struct tnode *createNewPointerNode(struct tnode *idNode) {
    struct tnode *node = createEmptyNode();

    node->nodeType = NODE_DEREFERENCE;
    node->left = idNode;
    node->right = NULL;
    node->numVal = NOT_CONSTANT;
    node->varName = NULL;

    return node;
}

struct tnode *createDereferenceNode(struct tnode *idNode) {
    struct tnode *node = createEmptyNode();
    struct tnode *newIdNode = createVariableUsageNode(idNode->varName);

    node->nodeType = NODE_DEREFERENCE;
    node->left = newIdNode;
    node->right = NULL;
    node->numVal = NOT_CONSTANT;
    node->varName = NULL;
    node->typeTableEntry = newIdNode->typeTableEntry;

    struct LSymbol *localEntry = lookupLST(idNode->varName);
    struct GSymbol *globalEntry = lookupGST(idNode->varName);

    if (localEntry && !localEntry->isPtr) {
        compilerError(E_DEREFERENCING_NON_POINTER_VARIABLE, newIdNode->varName);
    } else if (globalEntry && !globalEntry->isPtr) {
        compilerError(E_DEREFERENCING_NON_POINTER_VARIABLE, newIdNode->varName);
    }

    return node;
}

struct tnode *createAddressToNode(struct tnode *idNode) {
    struct tnode *node = createEmptyNode();
    struct tnode *newIdNode = createVariableUsageNode(idNode->varName);
    struct TypeTable *typeTableEntry = newIdNode->typeTableEntry;

    struct LSymbol *localEntry = lookupLST(idNode->varName);
    struct GSymbol *globalEntry = lookupGST(idNode->varName);

    if (localEntry && localEntry->isPtr) {
        compilerError(E_POINTER_TO_POINTER, newIdNode->varName);
    } else if (globalEntry && globalEntry->isPtr) {
        compilerError(E_POINTER_TO_POINTER, newIdNode->varName);
    }

    node->nodeType = NODE_ADDRESS_TO;
    node->left = newIdNode;
    node->right = NULL;
    node->numVal = NOT_CONSTANT;
    node->type = typeTableEntry->kind;
    node->varName = NULL;
    node->typeTableEntry = typeTableEntry;

    return node;
}

struct tnode *createAssignToDereferencedNode(struct tnode *idNode, struct tnode *exprNode) {
    struct tnode *node = createEmptyNode();
    struct tnode *newIdNode = createVariableUsageNode(idNode->varName);

    if (!areTypeCompatible(newIdNode->typeTableEntry, exprNode->typeTableEntry)) {
        compilerError(E_TYPE_MISMATCH, newIdNode->typeTableEntry->kind, exprNode->typeTableEntry->kind);
    } else if (newIdNode->gSymbolTableEntry && !newIdNode->gSymbolTableEntry->isPtr) {
        compilerError(E_DEREFERENCING_NON_POINTER_VARIABLE, newIdNode->varName);
    }

    node->nodeType = NODE_ASSIGN_TO_DEREFERENCED;
    node->left = newIdNode;
    node->right = exprNode;
    node->numVal = NOT_CONSTANT;
    node->type = NONE;
    node->varName = NULL;

    return node;
}
