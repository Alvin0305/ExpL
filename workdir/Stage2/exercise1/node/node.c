#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "node.h"
#include "../define/constants.h"

struct tnode *createTreeNode(int val, int nodeType, char *varName, struct tnode *left, struct tnode *right) {
    if (val != NOT_CONSTANT) {
        return createConstantNode(val, INT);
    } else if (varName) {
        return createVariableNode(varName, INT);
    } else {
        struct tnode *node = (tnode*) malloc(sizeof(tnode));

        node->left = left;
        node->right = right;
        node->nodeType = nodeType;
        node->varName = NULL;
        node->val = NOT_CONSTANT;

        return node;
    }
}

struct tnode *createEmptyNode() {
    struct tnode *node = (struct tnode*) malloc(sizeof(tnode));
    
    node->left = NULL;
    node->right = NULL;
    node->nodeType = NODE_EMPTY;

    return node;
}

struct tnode *createConstantNode(int val, int type) {
    struct tnode *node = createEmptyNode();
    
    node->nodeType = NODE_CONSTANT;
    node->val = val;
    node->varName = NULL;
    node->type = type;

    return node;
}

struct tnode *createVariableNode(char *varName, int type) {
    struct tnode *node = createEmptyNode();
    
    node->nodeType = NODE_VARIABLE;
    node->val = NOT_CONSTANT;
    node->type = type;

    node->varName = (char *) malloc(strlen(varName) + 1);
    strcpy(node->varName, varName);

    return node;
}

struct tnode *createArithOpNode(int nodeType, tnode *left, tnode *right) {
    struct tnode *node = createEmptyNode();

    node->left = left;
    node->right = right;
    node->nodeType = nodeType;
    node->val = NOT_CONSTANT;
    node->varName = NULL;
    node->type = INT;

    return node;
}

struct tnode *createAssignNode(tnode *left, tnode *right) {
    struct tnode *node = createEmptyNode();

    node->left = left;
    node->right = right;
    node->nodeType = NODE_ASSIGN;
    node->val = NOT_CONSTANT;
    node->varName = NULL;
    node->type = NONE;

    return node;
}

struct tnode *createConnectorNode(tnode *left, tnode *right) {
    struct tnode *node = createEmptyNode();

    node->left = left;
    node->right = right;
    node->nodeType = NODE_CONNECTOR;
    node->type = NONE;
    node->val = NOT_CONSTANT;
    node->varName = NULL;

    return node;
}

struct tnode *createReadNode(tnode *idNode) {
    struct tnode *node = createEmptyNode();

    node->left = idNode;
    node->nodeType = NODE_READ;
    node->type = NONE;
    node->val = NOT_CONSTANT;
    node->varName = NULL;

    return node;
}

struct tnode *createWriteNode(tnode *exprNode) {
    struct tnode *node = createEmptyNode();

    node->left = exprNode;
    node->nodeType = NODE_WRITE;
    node->type = NONE;
    node->val = NOT_CONSTANT;
    node->varName = NULL;

    return node;
}

void print_helper(struct tnode *root) {
    if (!root) return;
    
    switch(root->nodeType) {
        case NODE_CONNECTOR:
            printf("CONNECTOR\n");
            break;

        case NODE_ASSIGN:
            printf("ASSIGN\n");
            break;

        case NODE_READ:
            printf("READ\n");
            break;

        case NODE_WRITE:
            printf("WRITE\n");
            break;

        case NODE_EMPTY:
            printf("EMPTY\n");
            break;

        case NODE_CONSTANT:
            printf("%d\n", root->val);
            break;

        case NODE_VARIABLE:
            printf("%s\n", root->varName);
            break;

        case NODE_ADD:
            printf("+\n");
            break;
        
        case NODE_SUB:
            printf("-\n");
            break;

        case NODE_MUL:
            printf("*\n");
            break;

        case NODE_DIV:
            printf("/\n");
            break;
    }

    print_helper(root->left);
    print_helper(root->right);
}

void print(struct tnode *root) {
    printf("[Printing AST]\n");
    print_helper(root);
    printf("\n");
}

void inorder_helper(struct tnode *root) {
    if (!root) return;

    inorder_helper(root->left);
    
    switch(root->nodeType) {
        case NODE_CONNECTOR:
            printf("CONNECTOR\n");
            break;

        case NODE_ASSIGN:
            printf("ASSIGN\n");
            break;

        case NODE_READ:
            printf("READ\n");
            break;

        case NODE_WRITE:
            printf("WRITE\n");
            break;

        case NODE_EMPTY:
            printf("EMPTY\n");
            break;

        case NODE_CONSTANT:
            printf("%d\n", root->val);
            break;

        case NODE_VARIABLE:
            printf("%s\n", root->varName);
            break;

        case NODE_ADD:
            printf("+\n");
            break;
        
        case NODE_SUB:
            printf("-\n");
            break;

        case NODE_MUL:
            printf("*\n");
            break;

        case NODE_DIV:
            printf("/\n");
            break;
    }

    inorder_helper(root->right);
}

void print_inorder(struct tnode *root) {
    printf("[PRINTING IN INORDER]");
    inorder_helper(root);
    printf("\n");
}