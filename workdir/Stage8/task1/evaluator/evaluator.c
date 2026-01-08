#include "evaluator.h"
#include "../define/constants.h"
#include "../node/node.h"
#include "../util/util.h"
#include <stdio.h>

int variables[NUM_VARS];

int getVariableIndex(struct Node *node) {
    char varName = node->varName[0];
    return (int)varName - 'a';
}

void evaluateAndPrint(struct Node *root) {
    for (int i = 0; i < NUM_VARS; i++) {
        variables[i] = 0;
    }

    evaluate(root);

    for (int i = 0; i < NUM_VARS; i++) {
        printf("%c: %d\n", (char)(i + 'a'), variables[i]);
    }
}

int evaluate(struct Node *root) {
    if (!root) return __NONE__;
    int varIndex, val, condition;

    switch (root->nodeType) {
        case NODE_CONNECTOR:
            evaluate(root->left);
            evaluate(root->right);
            return __NONE__;

        case NODE_GE:
        case NODE_GT:
        case NODE_LE:
        case NODE_LT:
        case NODE_EQ:
        case NODE_NE:
            {
                int left = evaluate(root->left);
                int right = evaluate(root->right);

                switch (root->nodeType) {
                    case NODE_GE:
                        return left >= right;
                    case NODE_GT:
                        return left > right;
                    case NODE_LE:
                        return left <= right;
                    case NODE_LT:
                        return left < right;
                    case NODE_EQ:
                        return left == right;
                    case NODE_NE:
                        return left != right;
                    default:
                        printf("[WARNING]: Unhandled node in evaluating condition: ");
                        printNode(root);
                        break;
                }
            }

        case NODE_IF:
            {
                condition = evaluate(root->left);
                if (condition) {
                    evaluate(root->right);
                }

                return __NONE__;
            }

        case NODE_IF_ELSE:
            {
                condition = evaluate(root->left);
                Node *connector = root->right;

                if (condition) {
                    evaluate(connector->left);
                } else {
                    evaluate(connector->right);
                }

                return __NONE__;
            }

        case NODE_WHILE:
            {
                while (evaluate(root->left)) {
                    evaluate(root->right);
                }

                return __NONE__;
            }

        case NODE_EMPTY:
            return __NONE__;

        case NODE_READ:
            {
                varIndex = getVariableIndex(root->left);

                printf("[READ]: ");
                scanf("%d", &variables[varIndex]);
                return __NONE__;
            }

        case NODE_WRITE:
            {
                val = evaluate(root->left);

                printf("[WRITE]: %d\n", val);
                return __NONE__;
            }

        case NODE_ASSIGN:
            {
                val = evaluate(root->right);
                varIndex = getVariableIndex(root->left);

                variables[varIndex] = val;
                return __NONE__;
            }

        case NODE_VARIABLE:
            {
                varIndex = getVariableIndex(root);
                return variables[varIndex];
            }

        case NODE_CONSTANT:
            return root->numVal;

        case NODE_ADD:
        case NODE_SUB:
        case NODE_MUL:
        case NODE_DIV:
        case NODE_MOD:
            {
                int leftVal = evaluate(root->left);
                int rightVal = evaluate(root->right);

                switch (root->nodeType) {
                    case NODE_ADD:
                        return leftVal + rightVal;
                    case NODE_SUB:
                        return leftVal - rightVal;
                    case NODE_MUL:
                        return leftVal * rightVal;
                    case NODE_DIV:
                        return leftVal / rightVal;
                    case NODE_MOD:
                        return leftVal % rightVal;
                    default:
                        printf("[WARNING]: Unhandled node while evaluating arithmetic: ");
                        printNode(root);
                }

                return __NONE__;
            }

        default:
            printf("[WARNING]: Unhandled node while evaluating: ");
            printNode(root);
    }

    return __NONE__;
}