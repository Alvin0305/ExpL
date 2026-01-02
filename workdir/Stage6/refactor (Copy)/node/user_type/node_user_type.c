#include "../../define/constants.h"
#include "../../error_handler/error_handler.h"
#include "../../g_symbol_table/g_symbol_table.h"
#include "../../local_symbol_table/local_symbol_table.h"
#include "../../type_table/type_table.h"
#include "../../util/util.h"
#include "../node.h"

#include "node_user_type.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tnode *createUserTypeNode(struct tnode *typeNameNode) {
    struct tnode *node = createLeafNode(NODE_TYPE);
    node->type = USER_TYPE;

    struct TypeTable *type = typeTableLookup(typeNameNode->varName);
    node->typeTableEntry = type;

    return node;
}

struct tnode *createMemberAssignmentNode(struct tnode *fieldAccess, struct tnode *exprNode) {
    struct tnode *node = createConnectorNode(fieldAccess, exprNode);

    // if (!isTypeCompatible(fieldAccess->type, exprNode->type)) {
    //     compilerError(E_ASSIGN_TYPE_MISMATCH, fieldAccess->type, exprNode->type);
    // } else 
    if (!areSameUserType(fieldAccess->typeTableEntry, exprNode->typeTableEntry)) {
        compilerError(E_ASSIGN_USER_TYPE_MISMATCH, fieldAccess->typeTableEntry, exprNode->typeTableEntry);
    }

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

            memberAccessNode->type = tupleField->type;
            return memberAccessNode;

        } else if (baseIdNode->type == USER_TYPE) {
            resolvedField = fieldListLookup(activeUserType, memberIdNode->varName);
            activeUserType = resolvedField->type;

            memberAccessNode->nodeType = NODE_USER_DEF_TYPE_ACCESS;
            memberAccessNode->type = typeTableEntryToType(activeUserType);
            memberAccessNode->typeTableEntry = activeUserType;
            
            return memberAccessNode;
        } else {
            compilerError(E_MEMBER_ACCESS_ON_NON_SUPPORTED_TYPE, baseIdNode->varName, baseIdNode->type);
            return NULL;
        }
    } else if (baseExprNode->nodeType == NODE_ARRAY_ACCESS) {
        struct tnode *memberAccessNode = createConnectorNode(baseExprNode, memberIdNode);
        struct tnode *baseIdNode = baseExprNode->left;

        activeUserType = baseIdNode->typeTableEntry;
        resolvedField = fieldListLookup(activeUserType, memberIdNode->varName);

        memberAccessNode->nodeType = NODE_USER_DEF_TYPE_ACCESS;
        memberAccessNode->type = typeTableEntryToType(resolvedField->type);
        memberAccessNode->typeTableEntry = resolvedField->type;

        activeUserType = resolvedField->type;

        return memberAccessNode;

    } else {
        struct tnode *node = createConnectorNode(baseExprNode, memberIdNode);
        resolvedField = fieldListLookup(activeUserType, memberIdNode->varName);
        
        node->nodeType = NODE_USER_DEF_TYPE_ACCESS;
        node->type = typeTableEntryToType(resolvedField->type);
        node->typeTableEntry = resolvedField->type;
        
        activeUserType = resolvedField->type;

        return node;
    }
}
