#include <stdio.h>

#include "../../define/constants.h"
#include "../../error_handler/error_handler.h"
#include "../../g_symbol_table/g_symbol_table.h"
#include "../../local_symbol_table/local_symbol_table.h"
#include "../node.h"
#include "node_control_flow.h"

struct Node *createConditionNode(enum NodeType nodeType, Node *left, Node *right) {
    struct Node *node = createEmptyNode();

    node->left = left;
    node->right = right;
    node->numVal = __NONE__;
    node->type = BOOL;
    node->varName = NULL;
    node->nodeType = nodeType;

    return node;
}

struct Node *createWhileNode(Node *conditionNode, Node *statementsNode) {
    if (conditionNode->type != BOOL) {
        compilerError(E_TYPE_MISMATCH, "While Loop", BOOL, conditionNode->type);
    }

    struct Node *node = createEmptyNode();

    node->left = conditionNode;
    node->right = statementsNode;
    node->nodeType = NODE_WHILE;
    node->type = NONE;
    node->numVal = __NONE__;
    node->varName = NULL;

    return node;
}

struct Node *createIfElseNode(Node *conditionNode, Node *ifStatementsNode, Node *elseStatementsNode) {
    if (conditionNode->type != BOOL) {
        compilerError(E_TYPE_MISMATCH, "If Else", BOOL, conditionNode->type);
    }

    struct Node *node = createEmptyNode();
    struct Node *connector = createConnectorNode(ifStatementsNode, elseStatementsNode);

    node->left = conditionNode;
    node->right = connector;
    node->numVal = __NONE__;
    node->nodeType = NODE_IF_ELSE;
    node->type = NONE;
    node->varName = NULL;

    return node;
}

struct Node *createIfNode(Node *conditionNode, Node *statementsNode) {
    if (conditionNode->type != BOOL) {
        compilerError(E_TYPE_MISMATCH, "If", BOOL, conditionNode->type);
    }

    struct Node *node = createEmptyNode();

    node->left = conditionNode;
    node->right = statementsNode;
    node->nodeType = NODE_IF;
    node->type = NONE;
    node->numVal = __NONE__;
    node->varName = NULL;

    return node;
}

struct Node *createBreakNode() { return createLeafNode(NODE_BREAK); }

struct Node *createContinueNode() { return createLeafNode(NODE_CONTINUE); }

struct Node *createRepeatUntilNode(struct Node *statementsNode, struct Node *conditionNode) {
    if (conditionNode->type != BOOL) {
        compilerError(E_TYPE_MISMATCH, "Repeat Until Loop", BOOL, conditionNode->type);
    }

    struct Node *node = createEmptyNode();

    node->left = statementsNode;
    node->right = conditionNode;
    node->nodeType = NODE_REPEAT_UNTIL;
    node->numVal = __NONE__;
    node->type = NONE;
    node->varName = NULL;

    return node;
}

struct Node *createDoWhileNode(struct Node *statementsNode, struct Node *conditionNode) {
    if (conditionNode->type != BOOL) {
        compilerError(E_TYPE_MISMATCH, "Do While Loop", BOOL, conditionNode->type);
    }

    struct Node *node = createEmptyNode();

    node->left = conditionNode;
    node->right = statementsNode;
    node->type = NONE;
    node->nodeType = NODE_DO_WHILE;
    node->varName = NULL;
    node->numVal = __NONE__;

    return node;
}