#include "../../class_table/class_table.h"
#include "../../define/constants.h"
#include "../../error_handler/error_handler.h"
#include "../../g_symbol_table/g_symbol_table.h"
#include "../../local_symbol_table/local_symbol_table.h"
#include "../../type_table/type_table.h"
#include "../../util/util.h"
#include "../node.h"

#include "node_member_access.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static struct Node *resolveClassMember(struct Node *base, struct Node *member, bool isMethodCall, struct Node *argList) {
    struct ClassTable *_class = base->typeInfo->_class;
    struct Node *node;

    if (isMethodCall) {
        struct ClassMethod *method = lookupClassMethod(_class, member->varName);
        if (!method) {
            compilerError(E_CALL_NON_EXISTING_METHOD_OF_CLASS, _class->name, member->varName);
        }

        struct Node *callNode = createConnectorNode(member, argList);
        callNode->nodeType = NODE_FUNC_CALL;

        node = createConnectorNode(base, callNode);
        node->nodeType = NODE_CLASS_METHOD_ACCESS;
        node->type = method->returnType->kind;
        node->typeInfo = method->returnType;
    } else {
        struct ClassField *field = lookupClassField(_class, member->varName);
        if (!field) {
            compilerError(E_ACCESS_NON_EXISTING_FIELD_OF_CLASS, _class->name, member->varName);
        }

        node = createConnectorNode(base, member);
        node->nodeType = NODE_CLASS_FIELD_ACCESS;
        node->type = field->typeInfo->kind;
        node->typeInfo = field->typeInfo;
    }

    return node;
}

static struct Node *resolvedUDTMember(struct Node *base, struct Node *member) {
    struct TypeTable *type = base->typeInfo->type;
    struct TypeField *field = fieldListLookup(type, member->varName);

    if (!field) {
        compilerError(E_ACCESS_NON_EXISTING_FIELD_OF_TYPE, type->name, member->varName);
    }

    struct Node *node = createConnectorNode(base, member);
    node->nodeType = NODE_USER_DEF_TYPE_ACCESS;
    node->type = typeTableEntryToType(field->type);
    node->typeInfo = createTypeInfo(node->type, NULL, field->type, NULL);

    return node;
}

static struct Node *resolvedTupleMember(struct Node *base, struct Node *member, AccessType accessType) {
    struct TupleType *tupleType = base->typeInfo->tupleType;
    struct TupleField *field = getFieldOfTuple(tupleType, member->varName);

    if (!field) {
        compilerError(E_ACCESS_NON_EXISTING_FIELD_OF_TUPLE, tupleType->name, member->varName);
    }

    struct Node *node = createConnectorNode(base, member);
    node->nodeType = (accessType == ACCESS_DOT) ? NODE_TUPLE_ACCESS : NODE_TUPLE_POINTER_ACCESS;
    node->type = field->type;
    node->typeInfo = createTypeInfo(field->type, NULL, lookupTT(dataTypeToString(field->type)), NULL);
    return node;
}

struct Node *createMemberAccessNode(struct Node *baseExprNode, struct Node *memberIdNode, AccessType accessType,
                                    bool isMethodCall, struct Node *argList) {

    struct Node *resolvedBase = baseExprNode;
    if (resolvedBase->nodeType == NODE_VARIABLE) {
        resolvedBase = createVariableUsageNode(baseExprNode->varName);
    }

    if (resolvedBase->typeInfo->_class) {
        return resolveClassMember(resolvedBase, memberIdNode, isMethodCall, argList);
    }

    if (resolvedBase->typeInfo->type) {
        return resolvedUDTMember(resolvedBase, memberIdNode);
    }

    if (resolvedBase->type == TUPLE) {
        return resolvedTupleMember(resolvedBase, memberIdNode, accessType);
    }

    compilerError(E_MEMBER_ACCESS_ON_NON_SUPPORTED_TYPE, memberIdNode->varName, resolvedBase->type);
    return NULL;
}

struct Node *createMemberAssignmentNode(struct Node *fieldAccess, struct Node *exprNode) {
    struct Node *node = createConnectorNode(fieldAccess, exprNode);

    if (!isTypeCompatible(fieldAccess->typeInfo, exprNode->typeInfo)) {
        compilerError(E_ASSIGN_USER_TYPE_MISMATCH, fieldAccess->typeInfo->type, exprNode->typeInfo->type);
    }

    switch (fieldAccess->nodeType) {
        case NODE_TUPLE_ACCESS:
            node->nodeType = NODE_TUPLE_ASSIGN;
            break;
        case NODE_TUPLE_POINTER_ACCESS:
            node->nodeType = NODE_TUPLE_POINTER_ASSIGN;
            break;
        case NODE_USER_DEF_TYPE_ACCESS:
            node->nodeType = NODE_USER_DEF_TYPE_ASSIGNMENT;
            break;
        case NODE_CLASS_FIELD_ACCESS:
            node->nodeType = NODE_CLASS_FIELD_ASSIGNMENT;
            break;
        default:
            printf("[ERROR] Unknown field access node type for assignment\n");
            printNode(fieldAccess);
    }

    return node;
}
