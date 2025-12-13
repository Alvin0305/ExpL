#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "node.h"
#include "../util/util.h"
#include "../define/constants.h"
#include "../g_symbol_table/g_symbol_table.h"
#include "../error_handler/error_handler.h"

extern int lineNumber;

struct tnode *createTreeNode(int val, int nodeType, char *varName, struct tnode *left, struct tnode *right) {
    if (val != NOT_CONSTANT) {
        return createConstantNode(val);
    } else if (varName) {
        return createNewVariableNode(varName);
    } else {
        struct tnode *node = (tnode*) malloc(sizeof(tnode));

        node->left = left;
        node->right = right;
        node->nodeType = nodeType;
        node->varName = NULL;
        node->numVal = NOT_CONSTANT;

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

struct tnode *createConstantNode(int val) {
    struct tnode *node = createEmptyNode();
    
    node->nodeType = NODE_CONSTANT;
    node->numVal = val;
    node->varName = NULL;
    node->type = INT;

    return node;
}

struct tnode *createStringLiteralNode(char *stringLiteral) {
    struct tnode *node = createEmptyNode();

    node->left = NULL;
    node->right = NULL;
    node->nodeType = NODE_STRING_LITERAL;
    node->varName = NULL;
    node->strVal = (char *) malloc(strlen(stringLiteral) + 1);
    strcpy(node->strVal, stringLiteral);
    node->type = STRING; 

    return node;
}

struct tnode *createNewVariableNode(char *varName) {
    struct tnode *node = createEmptyNode();
    
    node->nodeType = NODE_VARIABLE;
    node->numVal = NOT_CONSTANT;

    node->varName = (char *) malloc(strlen(varName) + 1);
    strcpy(node->varName, varName);
    return node;
}

struct tnode *createNewArrayNode(struct tnode *varListNode, struct tnode *idNode, struct tnode *dimListNode) {
    struct tnode *node = createEmptyNode();
    struct tnode *connector = createConnectorNode(varListNode, node);

    node->left = idNode;
    node->right = dimListNode;
    node->nodeType = NODE_ARRAY_DECL;
    node->type = NONE;
    node->varName = NULL;
    node->numVal = NOT_CONSTANT;
    
    return connector;
}

struct tnode *createArrayAssignNode(struct tnode *idNode, struct tnode *dimensionUsageNode, struct tnode *valueNode) {
    struct tnode *arrayNode = createConnectorNode(createVariableUsageNode(idNode->varName), dimensionUsageNode);
    struct tnode *assignNode = createConnectorNode(arrayNode, valueNode);

    assignNode->nodeType = NODE_ARRAY_ASSIGN;
    assignNode->type = NONE;
    assignNode->numVal = NOT_CONSTANT;
    assignNode->varName = NULL;

    return assignNode;
}

struct tnode *createArrayAccessNode(struct tnode *idNode, struct tnode *indexExprNode) {
    struct tnode *idUsageNode = createVariableUsageNode(idNode->varName);
    struct tnode *arrayNode = createConnectorNode(idUsageNode, indexExprNode);

    arrayNode->nodeType = NODE_ARRAY_ACCESS;
    arrayNode->numVal = NOT_CONSTANT;
    arrayNode->type = idUsageNode->type;
    arrayNode->varName = NULL;

    return arrayNode;
}

struct tnode *createVariableUsageNode(char *varName) {
    struct tnode *node = createEmptyNode();

    node->nodeType = NODE_VARIABLE;
    node->numVal = NOT_CONSTANT;
    node->varName = (char *) malloc(strlen(varName) + 1);
    strcpy(node->varName, varName);

    GSymbol *entry = lookup(varName);
    if (!entry) {
        throwError(E_VARIABLE_USER_BEFORE_DECLARATION, varName);
    } else {
        node->type = entry->type;
        node->gSymbolTableEntry = entry;
    }

    return node;
}

struct tnode *createArithOpNode(int nodeType, tnode *left, tnode *right) {
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

    return node;
}

struct tnode *createAssignNode(tnode *idNode, tnode *exprNode) {
    struct tnode *idUsageNode = createVariableUsageNode(idNode->varName);

    if (idUsageNode->type != exprNode->type) {
        printf("[ERROR]: [%d] Type mismatch in assignment %s = %s\n", lineNumber, dataTypeToString(idUsageNode->type), dataTypeToString(exprNode->type));
        exit(1);
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

struct tnode *createReadNode(tnode *idNode) {
    struct tnode *node = createEmptyNode();
    struct tnode *idUsageNode = createVariableUsageNode(idNode->varName);

    node->left = idUsageNode;
    node->nodeType = NODE_READ;
    node->type = NONE;
    node->numVal = NOT_CONSTANT;
    node->varName = NULL;

    return node;
}

struct tnode *createWriteNode(tnode *exprNode) {
    struct tnode *node = createEmptyNode();

    if (exprNode->type != INT && exprNode->type != STRING) {
        printf("[ERROR]: [%d] Type mismatch, type is: %s\n", lineNumber, dataTypeToString(exprNode->type));
        exit(1);
    }

    node->left = exprNode;
    node->nodeType = NODE_WRITE;
    node->type = NONE;
    node->numVal = NOT_CONSTANT;
    node->varName = NULL;

    return node;
}

struct tnode *createConditionNode(int nodeType, tnode *left, tnode *right) {
    if (left->type != INT || right->type != INT) {
        printf("[ERROR]: [%d] Type of both variables in a condition should be INT, got %s and %s\n", lineNumber, dataTypeToString(left->type), dataTypeToString(right->type));
        exit(1);
    }

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
        throwTypeMismatchError("condition for while loop", BOOL, conditionNode->type);
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
        throwTypeMismatchError("condition for if else", BOOL, conditionNode->type);
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
        throwTypeMismatchError("condition for if", BOOL, conditionNode->type);
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
    struct tnode *node = createEmptyNode();

    node->left = NULL;
    node->right = NULL;
    node->numVal = NOT_CONSTANT;
    node->nodeType = NODE_BREAK;
    node->varName = NULL;
    node->type = NONE;

    return node;
}

struct tnode *createContinueNode() {
    struct tnode *node = createEmptyNode();

    node->left = NULL;
    node->right = NULL;
    node->numVal = NOT_CONSTANT;
    node->nodeType = NODE_CONTINUE;
    node->varName = NULL;
    node->type = NONE;

    return node;
}

struct tnode *createRepeatUntilNode(struct tnode *statementsNode, struct tnode *conditionNode) {
    if (conditionNode->type != BOOL) {
        throwTypeMismatchError("condition for repeat until loop", BOOL, conditionNode->type);
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
        throwTypeMismatchError("condition for do while loop", BOOL, conditionNode->type);
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

struct tnode *createTypeNode(int type) {
    struct tnode *node = createEmptyNode();

    node->left = NULL;
    node->right = NULL;
    node->nodeType = NODE_TYPE;
    node->type = type;
    node->numVal = NOT_CONSTANT;
    node->varName = NULL;

    return node;
}

struct tnode *createDeclarationNode(struct tnode *typeNode, struct tnode *varListNode) {
    struct tnode *node = createConnectorNode(typeNode, varListNode);

    node->nodeType = NODE_DECL;
    node->type = NONE;
    node->numVal = NOT_CONSTANT;
    node->varName = NULL;

    return node;
}

void print_helper(struct tnode *root) {
    if (!root) return;
    
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
    if (!root) return;

    inorder_helper(root->left);
    printNode(root);
    inorder_helper(root->right);
}

void print_inorder(struct tnode *root) {
    printf("[PRINTING IN INORDER]\n");
    inorder_helper(root);
    printf("\n");
}