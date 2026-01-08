#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../node.h"
#include "node_array.h"

#include "../../define/constants.h"
#include "../../error_handler/error_handler.h"
#include "../../type_info/type_info.h"
#include "../../type_table/type_table.h"
#include "../../util/util.h"

struct Node *createArrayAssignNode(struct Node *idNode, struct Node *dimensionUsageNode, struct Node *valueNode) {
    struct Node *idUsageNode = createVariableUsageNode(idNode->varName);
    struct Node *arrayNode = createConnectorNode(idUsageNode, dimensionUsageNode);
    struct Node *assignNode = createConnectorNode(arrayNode, valueNode);

    if (!isTypeCompatible(idUsageNode->typeInfo, valueNode->typeInfo)) {
        compilerError(E_ASSIGN_USER_TYPE_MISMATCH, idUsageNode->typeInfo->type, valueNode->typeInfo->type);
    }

    assignNode->nodeType = NODE_ARRAY_ASSIGN;
    assignNode->type = NONE;
    assignNode->numVal = __NONE__;
    assignNode->varName = NULL;

    return assignNode;
}

struct Node *createArrayAccessNode(struct Node *idNode, struct Node *indexExprNode) {
    struct Node *idUsageNode = createVariableUsageNode(idNode->varName);
    struct Node *arrayNode = createConnectorNode(idUsageNode, indexExprNode);

    arrayNode->nodeType = NODE_ARRAY_ACCESS;
    arrayNode->numVal = __NONE__;
    arrayNode->type = idUsageNode->type;
    // arrayNode->typeTableEntry = idUsageNode->typeTableEntry;
    arrayNode->typeInfo = idUsageNode->typeInfo;
    arrayNode->varName = NULL;

    return arrayNode;
}
