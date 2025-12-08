#include <stdio.h>
#include "evaluator.h"
#include "../define/constants.h"
#include "../node/node.h"

int variables[NUM_VARS];

int getVariableIndex(struct tnode *node) {
    char varName = node->varName[0];
    return (int) varName - 'a';
}

void evaluateAndPrint(struct tnode *root) {
    for (int i = 0; i < NUM_VARS; i++) {
        variables[i] = 0;
    }

    evaluate(root);

    for (int i = 0; i < NUM_VARS; i++) {
        printf("%c: %d\n", (char) (i + 'a'), variables[i]);
    }
}

int evaluate(struct tnode *root) {
    if (!root) return NO_RETURN;
    int varIndex, val;

    switch (root->nodeType) {
        case NODE_CONNECTOR:
            evaluate(root->left);
            evaluate(root->right);
            return NO_RETURN;

        case NODE_EMPTY:
            return NO_RETURN;

        case NODE_READ:
            varIndex = getVariableIndex(root->left);

            printf("[READ]: ");
            scanf("%d", &variables[varIndex]);
            return NO_RETURN;

        case NODE_WRITE:
            val = evaluate(root->left);
            
            printf("[WRITE]: %d\n", val);
            return NO_RETURN;

        case NODE_ASSIGN:
            val = evaluate(root->right);
            varIndex = getVariableIndex(root->left);

            variables[varIndex] = val;
            return NO_RETURN;

        case NODE_VARIABLE:
            varIndex = getVariableIndex(root);
            return variables[varIndex];

        case NODE_CONSTANT:
            return root->val;

        case NODE_ADD:
        case NODE_SUB:
        case NODE_MUL:
        case NODE_DIV:
            int leftVal = evaluate(root->left);
            int rightVal = evaluate(root->right);
            
            switch(root->nodeType) {
                case NODE_ADD: return leftVal + rightVal;
                case NODE_SUB: return leftVal - rightVal;
                case NODE_MUL: return leftVal * rightVal;
                case NODE_DIV: return leftVal / rightVal;
            }

            return NO_RETURN;
    }
}