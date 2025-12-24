#include <stdio.h>

#include "../node.h"
#include "node_array.h"
#include "../../define/constants.h"

struct tnode *createNewArrayNode(struct tnode *idNode, struct tnode *dimListNode) {
    struct tnode *node = createEmptyNode();

    node->left = idNode;
    node->right = dimListNode;
    node->nodeType = NODE_ARRAY_DECL;
    node->type = NONE;
    node->varName = NULL;
    node->numVal = NOT_CONSTANT;

    return node;
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
