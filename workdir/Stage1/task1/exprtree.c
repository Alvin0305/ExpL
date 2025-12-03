#include <stdlib.h>
#include <string.h>
#include "exprtree.h"

struct tnode *createLeafNode(int val) {
    struct tnode * node = (struct tnode *) malloc(sizeof(struct tnode));
    
    node->op = NULL;
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    
    return node;
}

struct tnode *createOperatorNode(char op, struct tnode *left, struct tnode *right) {
    struct tnode *node = (struct tnode *) malloc(sizeof(struct tnode));
    
    node->op = malloc(sizeof(char));
    node->op[0] = op;
    node->left = left;
    node->right = right;

    return node;
}

void print_helper(struct tnode *root) {
    if (root) {
        if (root->op) {
            printf("OP: %c\n", *(root->op));
        } else {
            printf("NUM: %d\n", root->val);
        }

        print_helper(root->left);
        print_helper(root->right);
    }
}

void print(struct tnode *root) {
    printf("[Printing Tree]\n");

    print_helper(root);
}

int evaluate(struct tnode *root) {
    if (!root->op) return root->val;

    switch(*(root->op)) {
        case '+':
            return evaluate(root->left) + evaluate(root->right);
            break;
        case '-':
            return evaluate(root->left) - evaluate(root->right);
            break;
        case '*':
            return evaluate(root->left) * evaluate(root->right);
            break;
        case '/':
            return evaluate(root->left) / evaluate(root->right);
            break;
        default:
            printf("Unknown operator found: %c\n", root->op);
            return 0;
            break;
    }
}