#include "node.h"
#include "../class_table/class_table.h"
#include "../code_gen/code_gen.h"
#include "../define/constants.h"
#include "../error_handler/error_handler.h"
#include "../g_symbol_table/g_symbol_table.h"
#include "../local_symbol_table/local_symbol_table.h"
#include "../tuple_type_table/tuple_type_table.h"
#include "../type_table/type_table.h"
#include "../util/util.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../code_gen/function/function.h"

extern int lineNumber;

struct Node *createEmptyNode() {
    struct Node *node = (struct Node *)malloc(sizeof(Node));

    node->left = NULL;
    node->right = NULL;
    node->nodeType = NODE_EMPTY;

    return node;
}

struct Node *createLeafNode(enum NodeType nodeType) {
    struct Node *node = createEmptyNode();

    node->nodeType = nodeType;
    node->gSymbolTableEntry = NULL;
    node->lSymbolTableEntry = NULL;
    node->numVal = __NONE__;
    node->type = NONE;
    node->varName = NULL;

    return node;
}

struct Node *createConnectorNode(Node *left, Node *right) {
    struct Node *node = createEmptyNode();

    node->left = left;
    node->right = right;
    node->nodeType = NODE_CONNECTOR;
    node->type = NONE;
    node->numVal = __NONE__;
    node->varName = NULL;

    return node;
}

struct Node *createConstantNode(int val) {
    struct Node *node = createLeafNode(NODE_CONSTANT);

    node->numVal = val;
    node->type = INT;
    node->typeInfo = createTypeInfo(INT, NULL, lookupTT("INT"), NULL);

    return node;
}

struct Node *createStringLiteralNode(char *stringLiteral) {
    struct Node *node = createLeafNode(NODE_STRING_LITERAL);

    node->strVal = strdup(stringLiteral);
    node->type = STRING;
    node->typeInfo = createTypeInfo(STRING, NULL, lookupTT("STRING"), NULL);

    return node;
}

struct Node *createNewVariableNode(char *varName) {
    struct Node *node = createLeafNode(NODE_VARIABLE);

    node->varName = strdup(varName);

    return node;
}

struct Node *createVariableUsageNode(char *varName) {
    struct Node *node = createLeafNode(NODE_VARIABLE);

    node->varName = strdup(varName);

    LSymbol *localEntry = lookupLST(varName);
    GSymbol *globalEntry = lookupGST(varName);

    if (localEntry) {
        node->type = localEntry->typeInfo->kind;
        node->gSymbolTableEntry = NULL;
        node->lSymbolTableEntry = localEntry;
        node->typeInfo = localEntry->typeInfo;
    } else if (globalEntry) {
        node->type = globalEntry->typeInfo->kind;
        node->gSymbolTableEntry = globalEntry;
        node->lSymbolTableEntry = NULL;
        node->typeInfo = globalEntry->typeInfo;
    } else {
        compilerError(E_VARIABLE_USED_BEFORE_DECLARATION, varName);
    }

    return node;
}

struct Node *createArithOpNode(enum NodeType nodeType, Node *left, Node *right) {
    if (left->type != INT || right->type != INT) {
        printf("[ERROR]: [%d] Type of mismatch in %s %s %s\n", lineNumber, dataTypeToString(left->type), opToString(nodeType),
               dataTypeToString(right->type));
        exit(1);
    }

    struct Node *node = createEmptyNode();

    node->left = left;
    node->right = right;
    node->nodeType = nodeType;
    node->numVal = __NONE__;
    node->varName = NULL;
    node->type = INT;
    node->typeInfo = left->typeInfo;

    return node;
}

struct Node *createAssignNode(Node *idNode, Node *exprNode) {
    struct Node *idUsageNode = createVariableUsageNode(idNode->varName);

    // if (!isTypeCompatible(idUsageNode->type, exprNode->type)) {
    //     compilerError(E_ASSIGN_TYPE_MISMATCH, idUsageNode->type, exprNode->type);
    // } else
    if (!isTypeCompatible(idUsageNode->typeInfo, exprNode->typeInfo)) {
        compilerError(E_ASSIGN_USER_TYPE_MISMATCH, idUsageNode->typeInfo->type, exprNode->typeInfo->type);
    }

    idUsageNode->type = exprNode->type;

    struct Node *node = createEmptyNode();

    node->left = idUsageNode;
    node->right = exprNode;
    node->nodeType = NODE_ASSIGN;
    node->numVal = __NONE__;
    node->varName = NULL;
    node->type = NONE;

    return node;
}

struct Node *createNullNode() {
    struct Node *node = createLeafNode(NODE_NULL);
    node->type = NULL_TYPE;
    node->numVal = NULL_VALUE;
    node->typeInfo = createTypeInfo(NULL_TYPE, NULL, lookupTT("NULL_TYPE"), NULL);

    return node;
}

struct Node *createIncrementNode(struct Node *idNode) {
    struct Node *node = createEmptyNode();
    struct Node *newIdNode = createVariableUsageNode(idNode->varName);

    if (newIdNode->typeInfo->kind != INT) {
        printf("[ERROR]: Increment allowed only on INT\n");
        exit(1);
    }

    node->nodeType = NODE_INC;
    node->left = newIdNode;
    node->right = NULL;
    node->type = newIdNode->type;
    node->numVal = __NONE__;
    node->varName = NULL;
    node->typeInfo = newIdNode->typeInfo;

    return node;
}

struct Node *createDecrementNode(struct Node *idNode) {
    struct Node *node = createEmptyNode();
    struct Node *newIdNode = createVariableUsageNode(idNode->varName);

    if (newIdNode->typeInfo->kind != INT) {
        printf("[ERROR]: Decrement allowed only on INT\n");
        exit(1);
    }

    node->nodeType = NODE_DEC;
    node->left = newIdNode;
    node->right = NULL;
    node->type = newIdNode->type;
    node->numVal = __NONE__;
    node->varName = NULL;
    node->typeInfo = newIdNode->typeInfo;

    return node;
}

struct Node *createCompoundAssignNode(enum NodeType nodeType, struct Node *idNode, struct Node *exprNode) {
    struct Node *leftIdNode = createVariableUsageNode(idNode->varName);
    struct Node *rightIdNode = createVariableUsageNode(idNode->varName);
    struct Node *opNode = createArithOpNode(nodeType, rightIdNode, exprNode);

    return createAssignNode(leftIdNode, opNode);
}

struct Node *createBreakPointNode() { return createLeafNode(NODE_BREAK_POINT); }

struct Node *createNewNode(struct Node *leftNode, struct Node *classNameNode) {
    struct ClassTable *_class = lookupCT(classNameNode->varName);
    if (!_class) {
        printf("error\n");
    }

    struct Node *node;
    if (leftNode->nodeType == NODE_VARIABLE) {
        struct Node *varUsageNode = createVariableUsageNode(leftNode->varName);
        node = createConnectorNode(varUsageNode, classNameNode);
    } else if (leftNode->nodeType == NODE_CLASS_FIELD_ACCESS) {
        node = createConnectorNode(leftNode, classNameNode);
    }

    node->nodeType = NODE_NEW;

    return node;
}

void print_helper(struct Node *root) {
    static int indent = 0;
    if (!root) return;

    for (int i = 0; i < indent; i++) {
        printf(" ");
    }
    printf("|-");
    printNode(root);
    indent++;

    print_helper(root->left);
    print_helper(root->right);
    indent--;
}

void print(struct Node *root) {
    printf("[Printing AST]\n");
    print_helper(root);
    printf("\n");
}

void inorder_helper(struct Node *root) {
    if (!root) return;

    inorder_helper(root->left);
    printNode(root);
    inorder_helper(root->right);
}

void print_inorder(struct Node *root) {
    printf("[PRINTING IN INORDER]\n");
    inorder_helper(root);
    printf("\n");
}
