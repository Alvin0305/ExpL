#include "../node.h"
#include "../../define/constants.h"
#include "../../error_handler/error_handler.h"
#include "node_library.h"
#include "../../util/util.h"

#include <stdio.h>
#include <stdlib.h>

struct tnode *createReadNode(tnode *idNode) {
    struct tnode *node = createEmptyNode();
    struct tnode *idUsageNode = createVariableUsageNode(idNode->varName);

    node->left = idUsageNode;
    node->nodeType = NODE_READ;
    node->type = NONE;
    node->numVal = NOT_CONSTANT;
    node->varName = NULL;

    return node;
}

struct tnode *createReadToArrayNode(struct tnode *idNode, struct tnode *dimensionNode) {
    struct tnode *node = createEmptyNode();
    struct tnode *newIdNode = createArrayAccessNode(idNode, dimensionNode);

    node->left = newIdNode;
    node->right = NULL;
    node->nodeType = NODE_READ_TO_ARRAY;
    node->numVal = NOT_CONSTANT;
    node->type = NONE;
    node->varName = NULL;

    return node;
}

struct tnode *createWriteNode(tnode *exprNode) {
    struct tnode *node = createEmptyNode();

    if (exprNode->type != INT && exprNode->type != STRING && exprNode->type != USER_TYPE) {
        printf("[ERROR]: [%d] Type mismatch, type is: %s\n", lineNumber, dataTypeToString(exprNode->type));
        exit(1);
    }

    node->left = exprNode;
    node->nodeType = NODE_WRITE;
    node->type = NONE;
    node->numVal = NOT_CONSTANT;
    node->varName = NULL;

    return node;
}

struct tnode *createInitNode(struct tnode *idNode) {
    struct tnode *idUsageNode = createVariableUsageNode(idNode->varName);
    struct tnode *node = createEmptyNode();

    node->left = idUsageNode;
    node->nodeType = NODE_INIT;

    return node;
}

struct tnode *createAllocNode(struct tnode *node) {
    if (node->nodeType == NODE_VARIABLE) {
        struct tnode *allocNode = createEmptyNode();
        struct tnode *idNode = createVariableUsageNode(node->varName);

        struct TypeTable *type = idNode->typeTableEntry;
        if (!type) {
            compilerError(E_USER_TYPE_USED_BEFORE_DECLARATION, idNode->varName);
        }

        allocNode->nodeType = NODE_ALLOC;
        allocNode->typeTableEntry = type;
        allocNode->left = idNode;
        return allocNode;

    } else if (node->nodeType == NODE_USER_DEF_TYPE_ACCESS) {
        struct tnode *allocNode = createEmptyNode();
        struct tnode *idNode = node->left;
        struct tnode *prev = node;
        while (idNode->left) {
            prev = idNode;
            idNode = idNode->left;
        }

        prev->left = createVariableUsageNode(idNode->varName);
        struct TypeTable *type = prev->left->typeTableEntry;
        if (!type) {
            compilerError(E_USER_TYPE_USED_BEFORE_DECLARATION, idNode->varName);
        }

        allocNode->nodeType = NODE_ALLOC;
        allocNode->left = node;
        allocNode->typeTableEntry = type;

        return allocNode;

    } else if (node->nodeType == NODE_ARRAY_ACCESS) {
        struct tnode *allocNode = createEmptyNode();
        struct tnode *idNode = createVariableUsageNode(node->left->varName);
 
        struct TypeTable *type = idNode->typeTableEntry;
        if (!type) {
            compilerError(E_USER_TYPE_USED_BEFORE_DECLARATION, idNode->varName);
        }

        allocNode->nodeType = NODE_ALLOC;
        allocNode->typeTableEntry = type;
        allocNode->left = node;
        return allocNode;
    } else {
        printf("[WARNING]: unknown node in alloc\n");
        return NULL;
    }
}

struct tnode *createFreeNode(struct tnode *idNode) {
    struct tnode *node = createEmptyNode();

    node->left = idNode;
    node->nodeType = NODE_FREE;

    return node;
}