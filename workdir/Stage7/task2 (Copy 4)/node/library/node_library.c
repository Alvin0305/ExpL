#include "../node.h"
#include "node_library.h"
#include "../../class_table/class_table.h"
#include "../../define/constants.h"
#include "../../error_handler/error_handler.h"
#include "../../type_info/type_info.h"
#include "../../type_table/type_table.h"
#include "../../util/util.h"

#include <stdio.h>
#include <stdlib.h>

struct Node *createReadNode(Node *idNode) {
    struct Node *node = createEmptyNode();
    struct Node *idUsageNode = createVariableUsageNode(idNode->varName);

    node->left = idUsageNode;
    node->nodeType = NODE_READ;
    node->type = NONE;
    node->numVal = __NONE__;
    node->varName = NULL;

    return node;
}

struct Node *createReadToArrayNode(struct Node *idNode, struct Node *dimensionNode) {
    struct Node *node = createEmptyNode();
    struct Node *newIdNode = createArrayAccessNode(idNode, dimensionNode);

    node->left = newIdNode;
    node->right = NULL;
    node->nodeType = NODE_READ_TO_ARRAY;
    node->numVal = __NONE__;
    node->type = NONE;
    node->varName = NULL;

    return node;
}

struct Node *createWriteNode(Node *exprNode) {
    struct Node *node = createEmptyNode();

    if (exprNode->type != INT && exprNode->type != STRING && exprNode->type != TYPE) {
        printf("[ERROR]: [%d] Type mismatch, type is: %s\n", lineNumber, dataTypeToString(exprNode->type));
        exit(1);
    }

    node->left = exprNode;
    node->nodeType = NODE_WRITE;
    node->type = NONE;
    node->numVal = __NONE__;
    node->varName = NULL;

    return node;
}

struct Node *createInitNode() {
    struct Node *node = createEmptyNode();

    node->nodeType = NODE_INIT;
    node->typeInfo = createTypeInfo(INT, NULL, lookupTT("INT"), NULL);

    return node;
}

struct Node *createAllocNode(struct Node *node) {
    if (node->nodeType == NODE_VARIABLE) {
        struct Node *allocNode = createEmptyNode();
        struct Node *idNode = createVariableUsageNode(node->varName);

        struct TypeTable *type = idNode->typeInfo->type;
        struct ClassTable *_class = idNode->typeInfo->_class;
        if (!type && !_class) {
            compilerError(E_USER_TYPE_USED_BEFORE_DECLARATION, idNode->varName);
        }

        allocNode->nodeType = NODE_ALLOC;
        allocNode->left = idNode;
        allocNode->typeInfo = idNode->typeInfo;
        return allocNode;

    } else if (node->nodeType == NODE_USER_DEF_TYPE_ACCESS) {
        struct Node *allocNode = createEmptyNode();
        struct Node *idNode = node->left;
        struct Node *prev = node;
        while (idNode->left) {
            prev = idNode;
            idNode = idNode->left;
        }

        prev->left = createVariableUsageNode(idNode->varName);
        struct TypeTable *type = prev->left->typeInfo->type;
        if (!type) {
            compilerError(E_USER_TYPE_USED_BEFORE_DECLARATION, idNode->varName);
        }

        allocNode->nodeType = NODE_ALLOC;
        allocNode->typeInfo = prev->left->typeInfo;
        allocNode->left = node;

        return allocNode;

    } else if (node->nodeType == NODE_ARRAY_ACCESS) {
        struct Node *allocNode = createEmptyNode();
        struct Node *idNode = createVariableUsageNode(node->left->varName);

        struct TypeTable *type = idNode->typeInfo->type;
        if (!type) {
            compilerError(E_USER_TYPE_USED_BEFORE_DECLARATION, idNode->varName);
        }

        allocNode->nodeType = NODE_ALLOC;
        allocNode->typeInfo = idNode->typeInfo;
        allocNode->left = node;
        return allocNode;
    } else if (node->nodeType == NODE_CLASS_FIELD_ACCESS) {
        struct Node *allocNode = createEmptyNode();
        struct Node *idNode = node;
        while (idNode->left) {
            idNode = idNode->left;
        }
        idNode = createVariableUsageNode(idNode->varName);
        struct ClassTable *_class = idNode->typeInfo->_class;

        if (!_class) {
            printf("error\n");
        }

        allocNode->nodeType = NODE_ALLOC;
        allocNode->typeInfo = idNode->typeInfo;
        allocNode->left = node;
        return allocNode;
    } else {
        printf("[WARNING]: unknown node in alloc\n");
        return NULL;
    }
}

struct Node *createFreeNode(struct Node *idNode) {
    struct Node *node = createEmptyNode();

    node->left = idNode;
    node->nodeType = NODE_FREE;

    return node;
}