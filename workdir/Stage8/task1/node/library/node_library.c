#include "../node.h"

#include "../../class_table/class_table.h"
#include "../../define/constants.h"
#include "../../error_handler/error_handler.h"
#include "../../type_info/type_info.h"
#include "../../type_table/type_table.h"
#include "../../util/util.h"
#include "node_library.h"

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
    struct Node *allocNode = createEmptyNode();
    struct Node *idNode;

    struct TypeTable *type;
    struct ClassTable *_class;

    allocNode->nodeType = NODE_ALLOC;

    switch (node->nodeType) {
        case NODE_VARIABLE:
            idNode = createVariableUsageNode(node->varName);
            type = idNode->typeInfo->type;
            _class = idNode->typeInfo->_class;
            
            if (!type && !_class) {
                compilerError(E_USER_TYPE_USED_BEFORE_DECLARATION, idNode->varName);
            }

            if (isPrimitive(idNode->type)) {
                compilerError(E_ALLOC_ON_NON_UDT, idNode->varName);
            }

            node = idNode;
            break;

        case NODE_USER_DEF_TYPE_ACCESS:
            idNode = node->left;
            while (idNode->left) {
                idNode = idNode->left;
            }

            idNode = createVariableUsageNode(idNode->varName);
            type = idNode->typeInfo->type;
            if (!type) {
                compilerError(E_USER_TYPE_USED_BEFORE_DECLARATION, idNode->varName);
            }
            if (isPrimitive(node->type)) {
                compilerError(E_ALLOC_ON_NON_UDT, idNode->varName);
            }

            break;

        case NODE_ARRAY_ACCESS:
            idNode = createVariableUsageNode(node->left->varName);
            type = idNode->typeInfo->type;

            if (!type) {
                compilerError(E_USER_TYPE_USED_BEFORE_DECLARATION, idNode->varName);
            }
            if (isPrimitive(idNode->type)) {
                compilerError(E_ALLOC_ON_NON_UDT, idNode->varName);
            }

            break;

        case NODE_CLASS_FIELD_ACCESS:
            idNode = node;
            while (idNode->left) {
                idNode = idNode->left;
            }
            idNode = createVariableUsageNode(idNode->varName);
            _class = idNode->typeInfo->_class;

            if (!_class) {
                compilerError(E_CLASS_USED_BEFORE_DECLARATION, idNode->varName);
            }
            if (isPrimitive(node->type)) {
                compilerError(E_ALLOC_ON_NON_UDT, idNode->varName);
            }
            break;

        default:
            printf("[WARNING]: unknown node in alloc\n");
            return NULL;
    }

    allocNode->typeInfo = idNode->typeInfo;
    allocNode->left = node;
    return allocNode;
}

struct Node *createFreeNode(struct Node *idNode) {
    struct Node *node = createEmptyNode();

    node->left = idNode;
    node->nodeType = NODE_FREE;

    return node;
}