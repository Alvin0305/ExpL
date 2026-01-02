#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../node.h"
#include "node_array.h"

#include "../../define/constants.h"
#include "../../error_handler/error_handler.h"
#include "../../type_table/type_table.h"
#include "../../util/util.h"

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
    struct tnode *idUsageNode = createVariableUsageNode(idNode->varName);
    struct tnode *arrayNode = createConnectorNode(idUsageNode, dimensionUsageNode);
    struct tnode *assignNode = createConnectorNode(arrayNode, valueNode);

    if (!isTypeCompatible(idUsageNode->type, valueNode->type)) {
        compilerError(E_ASSIGN_TYPE_MISMATCH, idUsageNode->type, valueNode->type);
    } else if (idUsageNode->type == USER_TYPE && strcmp(idUsageNode->typeTableEntry->name, valueNode->typeTableEntry->name) != 0) {
        compilerError(E_ASSIGN_USER_TYPE_MISMATCH, idUsageNode->typeTableEntry, valueNode->typeTableEntry);
    }
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
