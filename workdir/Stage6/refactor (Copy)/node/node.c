#include "node.h"
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

struct tnode *createEmptyNode() {
    struct tnode *node = (struct tnode *)malloc(sizeof(tnode));

    node->left = NULL;
    node->right = NULL;
    node->nodeType = NODE_EMPTY;

    return node;
}

struct tnode *createLeafNode(enum NodeType nodeType) {
    struct tnode *node = createEmptyNode();

    node->nodeType = nodeType;
    node->gSymbolTableEntry = NULL;
    node->lSymbolTableEntry = NULL;
    node->numVal = __NONE__;
    node->type = NONE;
    node->varName = NULL;

    return node;
}

struct tnode *createConnectorNode(tnode *left, tnode *right) {
    struct tnode *node = createEmptyNode();

    node->left = left;
    node->right = right;
    node->nodeType = NODE_CONNECTOR;
    node->type = NONE;
    node->numVal = NOT_CONSTANT;
    node->varName = NULL;

    return node;
}

struct tnode *createConstantNode(int val) {
    struct tnode *node = createLeafNode(NODE_CONSTANT);

    node->numVal = val;
    node->type = INT;
    node->typeTableEntry = typeTableLookup("INT");

    return node;
}

struct tnode *createStringLiteralNode(char *stringLiteral) {
    struct tnode *node = createLeafNode(NODE_STRING_LITERAL);

    node->strVal = strdup(stringLiteral);
    node->type = STRING;
    node->typeTableEntry = typeTableLookup("STRING");

    return node;
}

struct tnode *createNewVariableNode(char *varName) {
    struct tnode *node = createLeafNode(NODE_VARIABLE);

    node->varName = strdup(varName);

    return node;
}

struct tnode *createVariableUsageNode(char *varName) {
    struct tnode *node = createLeafNode(NODE_VARIABLE);

    node->varName = strdup(varName);

    LSymbol *localEntry = lookupLST(varName);
    GSymbol *globalEntry = lookupGST(varName);

    if (localEntry) {
        node->type = localEntry->type;
        node->gSymbolTableEntry = NULL;
        node->lSymbolTableEntry = localEntry;
        node->typeTableEntry = localEntry->typeTableEntry;
        node->tupleType = localEntry->tupleType;
    } else if (globalEntry) {
        node->type = globalEntry->type;
        node->gSymbolTableEntry = globalEntry;
        node->lSymbolTableEntry = NULL;
        node->typeTableEntry = globalEntry->typeTableEntry;
        node->tupleType = globalEntry->tupleType;
    } else {
        compilerError(E_VARIABLE_USED_BEFORE_DECLARATION, varName);
    }

    return node;
}

struct tnode *createArithOpNode(enum NodeType nodeType, tnode *left, tnode *right) {
    if (left->type != INT || right->type != INT) {
        printf("[ERROR]: [%d] Type of mismatch in %s %s %s\n", lineNumber, dataTypeToString(left->type), opToString(nodeType), dataTypeToString(right->type));
        exit(1);
    }

    struct tnode *node = createEmptyNode();

    node->left = left;
    node->right = right;
    node->nodeType = nodeType;
    node->numVal = NOT_CONSTANT;
    node->varName = NULL;
    node->type = INT;
    node->typeTableEntry = typeTableLookup("INT");

    return node;
}

struct tnode *createAssignNode(tnode *idNode, tnode *exprNode) {
    struct tnode *idUsageNode = createVariableUsageNode(idNode->varName);

    // if (!isTypeCompatible(idUsageNode->type, exprNode->type)) {
    //     compilerError(E_ASSIGN_TYPE_MISMATCH, idUsageNode->type, exprNode->type);
    // } else 
    if (!areSameUserType(idUsageNode->typeTableEntry, exprNode->typeTableEntry)) {
        compilerError(E_ASSIGN_USER_TYPE_MISMATCH, idUsageNode->typeTableEntry, exprNode->typeTableEntry);
    }

    idUsageNode->type = exprNode->type;

    struct tnode *node = createEmptyNode();

    node->left = idUsageNode;
    node->right = exprNode;
    node->nodeType = NODE_ASSIGN;
    node->numVal = NOT_CONSTANT;
    node->varName = NULL;
    node->type = NONE;

    return node;
}

struct tnode *createTypeNode(enum Type type) {
    struct tnode *node = createLeafNode(NODE_TYPE);
    node->type = type;
    node->typeTableEntry = typeTableLookup(dataTypeToString(type));

    return node;
}

struct tnode *createNullNode() {
    struct tnode *node = createLeafNode(NODE_NULL);
    node->type = NULL_TYPE;
    node->numVal = NULL_VALUE;

    return node;
}

struct tnode *createDeclarationNode(struct tnode *typeNode, struct tnode *varListNode) {
    struct tnode *node = createConnectorNode(typeNode, varListNode);
    int type = typeNode->type;
    node->typeTableEntry = typeTableLookup(dataTypeToString(type));

    if (type == TUPLE) {
        node->nodeType = NODE_TUPLE_VAR_DECL;
    } else {
        node->nodeType = NODE_DECL;
    }

    addToGST(typeNode, node);

    return NULL;
}

struct tnode *createIncrementNode(struct tnode *idNode) {
    struct tnode *node = createEmptyNode();
    struct tnode *newIdNode = createVariableUsageNode(idNode->varName);

    if (strcmp(newIdNode->typeTableEntry->name, "INT") != 0) {
        printf("[ERROR]: Increment allowed only on INT\n");
        exit(1);
    }

    node->nodeType = NODE_INC;
    node->left = newIdNode;
    node->right = NULL;
    node->type = newIdNode->type;
    node->typeTableEntry = newIdNode->typeTableEntry;
    node->numVal = NOT_CONSTANT;
    node->varName = NULL;

    return node;
}

struct tnode *createDecrementNode(struct tnode *idNode) {
    struct tnode *node = createEmptyNode();
    struct tnode *newIdNode = createVariableUsageNode(idNode->varName);

    if (strcmp(newIdNode->typeTableEntry->name, "INT") != 0) {
        printf("[ERROR]: Decrement allowed only on INT\n");
        exit(1);
    }

    node->nodeType = NODE_DEC;
    node->left = newIdNode;
    node->right = NULL;
    node->type = newIdNode->type;
    node->typeTableEntry = newIdNode->typeTableEntry;
    node->numVal = NOT_CONSTANT;
    node->varName = NULL;

    return node;
}

struct tnode *createCompoundAssignNode(enum NodeType nodeType, struct tnode *idNode, struct tnode *exprNode) {
    struct tnode *leftIdNode = createVariableUsageNode(idNode->varName);
    struct tnode *rightIdNode = createVariableUsageNode(idNode->varName);
    struct tnode *opNode = createArithOpNode(nodeType, rightIdNode, exprNode);

    return createAssignNode(leftIdNode, opNode);
}

struct tnode *createBreakPointNode() {
    return createLeafNode(NODE_BREAK_POINT);
}

void print_helper(struct tnode *root) {
    if (!root)
        return;

    printNode(root);

    print_helper(root->left);
    print_helper(root->right);
}

void print(struct tnode *root) {
    printf("[Printing AST]\n");
    print_helper(root);
    printf("\n");
}

void inorder_helper(struct tnode *root) {
    if (!root)
        return;

    inorder_helper(root->left);
    printNode(root);
    inorder_helper(root->right);
}

void print_inorder(struct tnode *root) {
    printf("[PRINTING IN INORDER]\n");
    inorder_helper(root);
    printf("\n");
}
