#include <stdio.h>

#include "../node.h"
#include "node_control_flow.h"
#include "../../define/constants.h"
#include "../../local_symbol_table/local_symbol_table.h"
#include "../../g_symbol_table/g_symbol_table.h"
#include "../../error_handler/error_handler.h"

struct tnode *createConditionNode(int nodeType, tnode *left, tnode *right) {
    struct tnode *node = createEmptyNode();

    node->left = left;
    node->right = right;
    node->numVal = NOT_CONSTANT;
    node->type = BOOL;
    node->varName = NULL;
    node->nodeType = nodeType;

    return node;
}

struct tnode *createWhileNode(tnode *conditionNode, tnode *statementsNode) {
    if (conditionNode->type != BOOL) {
        compilerError(E_TYPE_MISMATCH, "While Loop", BOOL, conditionNode->type);
    }

    struct tnode *node = createEmptyNode();

    node->left = conditionNode;
    node->right = statementsNode;
    node->nodeType = NODE_WHILE;
    node->type = NONE;
    node->numVal = NOT_CONSTANT;
    node->varName = NULL;

    return node;
}

struct tnode *createIfElseNode(tnode *conditionNode, tnode *ifStatementsNode, tnode *elseStatementsNode) {
    if (conditionNode->type != BOOL) {
        compilerError(E_TYPE_MISMATCH, "If Else", BOOL, conditionNode->type);
    }

    struct tnode *node = createEmptyNode();
    struct tnode *connector = createConnectorNode(ifStatementsNode, elseStatementsNode);

    node->left = conditionNode;
    node->right = connector;
    node->numVal = NOT_CONSTANT;
    node->nodeType = NODE_IF_ELSE;
    node->type = NONE;
    node->varName = NULL;

    return node;
}

struct tnode *createIfNode(tnode *conditionNode, tnode *statementsNode) {
    if (conditionNode->type != BOOL) {
        compilerError(E_TYPE_MISMATCH, "If", BOOL, conditionNode->type);
    }

    struct tnode *node = createEmptyNode();

    node->left = conditionNode;
    node->right = statementsNode;
    node->nodeType = NODE_IF;
    node->type = NONE;
    node->numVal = NOT_CONSTANT;
    node->varName = NULL;

    return node;
}

struct tnode *createBreakNode() {
    return createLeafNode(NODE_BREAK);
}

struct tnode *createContinueNode() {
    return createLeafNode(NODE_CONTINUE);
}

struct tnode *createRepeatUntilNode(struct tnode *statementsNode, struct tnode *conditionNode) {
    if (conditionNode->type != BOOL) {
        compilerError(E_TYPE_MISMATCH, "Repeat Until Loop", BOOL, conditionNode->type);
    }

    struct tnode *node = createEmptyNode();

    node->left = statementsNode;
    node->right = conditionNode;
    node->nodeType = NODE_REPEAT_UNTIL;
    node->numVal = NOT_CONSTANT;
    node->type = NONE;
    node->varName = NULL;

    return node;
}

struct tnode *createDoWhileNode(struct tnode *statementsNode, struct tnode *conditionNode) {
    if (conditionNode->type != BOOL) {
        compilerError(E_TYPE_MISMATCH, "Do While Loop", BOOL, conditionNode->type);
    }

    struct tnode *node = createEmptyNode();

    node->left = conditionNode;
    node->right = statementsNode;
    node->type = NONE;
    node->nodeType = NODE_DO_WHILE;
    node->varName = NULL;
    node->numVal = NOT_CONSTANT;

    return node;
}