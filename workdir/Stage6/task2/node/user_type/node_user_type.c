#include "../../define/constants.h"
#include "../../error_handler/error_handler.h"
#include "../../g_symbol_table/g_symbol_table.h"
#include "../../local_symbol_table/local_symbol_table.h"
#include "../../type_table/type_table.h"
#include "../../util/util.h"
#include "../node.h"

#include "node_user_type.h"
#include <stdio.h>

struct tnode *createUserTypeNode(struct tnode *typeNameNode) {
    struct tnode *node = createLeafNode(NODE_TYPE);
    node->type = USER_TYPE;

    struct TypeTable *type = typeTableLookup(typeNameNode->varName);
    node->typeTableEntry = type;

    return node;
}

struct tnode *createMemberAssignmentNode(struct tnode *fieldAccess, struct tnode *exprNode) {
    struct tnode *node = createConnectorNode(fieldAccess, exprNode);

    if (fieldAccess->nodeType == NODE_TUPLE_ACCESS) {
        node->nodeType = NODE_TUPLE_ASSIGN;
    } else if (fieldAccess->nodeType == NODE_TUPLE_POINTER_ACCESS) {
        node->nodeType = NODE_TUPLE_POINTER_ASSIGN;
    } else if (fieldAccess->nodeType == NODE_USER_DEF_TYPE_ACCESS) {
        node->nodeType = NODE_USER_DEF_TYPE_ASSIGNMENT;
    } else {
        printf("[ERROR]");
        printNode(fieldAccess);
    }

    return node;
}

struct tnode *createMemberAccessNode(struct tnode *baseExprNode, struct tnode *memberIdNode, AccessType accessType) {
    static struct TypeTable *activeUserType = NULL;
    static struct FieldList *resolvedField = NULL;

    if (baseExprNode->nodeType == NODE_VARIABLE) {
        struct tnode *baseIdNode = createVariableUsageNode(baseExprNode->varName);
        struct tnode *memberAccessNode = createConnectorNode(baseIdNode, memberIdNode);

        activeUserType = baseIdNode->typeTableEntry;
        memberAccessNode->type = memberIdNode->type;

        if (baseIdNode->type == TUPLE) {
            struct TupleType *tupleType;
            if (baseIdNode->lSymbolTableEntry) {
                tupleType = baseIdNode->lSymbolTableEntry->tupleType;
            } else if (baseIdNode->gSymbolTableEntry) {
                tupleType = baseIdNode->gSymbolTableEntry->tupleType;
            } else {
                compilerError(E_VARIABLE_USED_BEFORE_DECLARATION, baseIdNode->varName);
            }

            struct TupleField *tupleField = getFieldOfTuple(tupleType, memberIdNode->varName);
            if (!tupleField) {
                compilerError(E_ACCESS_NON_EXISTING_FIELD_OF_TUPLE, baseIdNode->varName, memberIdNode->varName);
            }

            if (accessType == ACCESS_DOT) {
                memberAccessNode->nodeType = NODE_TUPLE_ACCESS;
            } else {
                memberAccessNode->nodeType = NODE_TUPLE_POINTER_ACCESS;
            }
            return memberAccessNode;

        } else if (baseIdNode->type == USER_TYPE) {
            resolvedField = fieldListLookup(activeUserType, memberIdNode->varName);
            memberAccessNode->nodeType = NODE_USER_DEF_TYPE_ACCESS;
            memberAccessNode->type = typeTableEntryToType(resolvedField->type);
            return memberAccessNode;

        } else {
            compilerError(E_MEMBER_ACCESS_ON_NON_SUPPORTED_TYPE, baseIdNode->varName, baseIdNode->type);
            return NULL;
        }
    } else {
        struct tnode *node = createConnectorNode(baseExprNode, memberIdNode);
        node->nodeType = NODE_USER_DEF_TYPE_ACCESS;

        return node;
    }
}
