#include "../node.h"
#include "../../define/constants.h"
#include "../../local_symbol_table/local_symbol_table.h"
#include "../../g_symbol_table/g_symbol_table.h"
#include "../../error_handler/error_handler.h"

#include <stdio.h>

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
    if (newIdNode->gSymbolTableEntry) {
        node->type = newIdNode->gSymbolTableEntry->type;

        if (!newIdNode->gSymbolTableEntry->isPtr) {
            compilerError(E_DEREFERENCING_NON_POINTER_VARIABLE, newIdNode->varName);
        }
    } else if (newIdNode->lSymbolTableEntry) {
        node->type = newIdNode->lSymbolTableEntry->type;
    }
    node->varName = NULL;

    return node;
}

struct tnode *createAddressToNode(struct tnode *idNode) {
    struct tnode *node = createEmptyNode();
    struct tnode *newIdNode = createVariableUsageNode(idNode->varName);

    node->nodeType = NODE_ADDRESS_TO;
    node->left = newIdNode;
    node->right = NULL;
    node->numVal = NOT_CONSTANT;
    if (newIdNode->gSymbolTableEntry) {
        node->type = newIdNode->gSymbolTableEntry->type;

        if (newIdNode->gSymbolTableEntry->isPtr) {
            compilerError(E_POINTER_TO_POINTER, newIdNode->varName);
        }
    } else if (newIdNode->lSymbolTableEntry) {
        node->type = newIdNode->lSymbolTableEntry->type;
    }
    node->varName = NULL;

    return node;
}

struct tnode *createAssignToDereferencedNode(struct tnode *idNode, struct tnode *exprNode) {
    struct tnode *node = createEmptyNode();
    struct tnode *newIdNode = createVariableUsageNode(idNode->varName);

    node->nodeType = NODE_ASSIGN_TO_DEREFERENCED;
    node->left = newIdNode;
    node->right = exprNode;
    node->numVal = NOT_CONSTANT;
    node->type = NONE;
    node->varName = NULL;

    if (newIdNode->gSymbolTableEntry && !newIdNode->gSymbolTableEntry->isPtr) {
        compilerError(E_DEREFERENCING_NON_POINTER_VARIABLE, newIdNode->varName);
    }

    return node;
}
