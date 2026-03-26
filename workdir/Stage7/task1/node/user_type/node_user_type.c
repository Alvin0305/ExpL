#include "../../class_table/class_table.h"
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

struct tnode *createMemberAssignmentNode(struct tnode *fieldAccess, struct tnode *exprNode) {
    struct tnode *node = createConnectorNode(fieldAccess, exprNode);

    if (!areTypeCompatible(fieldAccess->typeInfo, exprNode->typeInfo)) {
        compilerError(E_ASSIGN_USER_TYPE_MISMATCH, fieldAccess->typeInfo->type, exprNode->typeInfo->type);
    }

    if (fieldAccess->nodeType == NODE_TUPLE_ACCESS) {
        node->nodeType = NODE_TUPLE_ASSIGN;
    } else if (fieldAccess->nodeType == NODE_TUPLE_POINTER_ACCESS) {
        node->nodeType = NODE_TUPLE_POINTER_ASSIGN;
    } else if (fieldAccess->nodeType == NODE_USER_DEF_TYPE_ACCESS) {
        node->nodeType = NODE_USER_DEF_TYPE_ASSIGNMENT;
    } else if (fieldAccess->nodeType == NODE_CLASS_FIELD_ACCESS) {
        node->nodeType = NODE_CLASS_FIELD_ASSIGNMENT;
    } else {
        printf("[ERROR] Unexpected Node while creating assignment node");
        printNode(fieldAccess);
    }

    return node;
}

struct tnode *createMemberAccessNode(struct tnode *baseExprNode, struct tnode *memberIdNode, AccessType accessType,
                                     bool isMethodCall, struct tnode *argList) {
    static struct TypeTable *activeUserType = NULL;
    static struct ClassTable *activeClass = NULL;
    static struct FieldList *resolvedTypeField = NULL;
    static struct ClassField *resolvedClassField = NULL;

    struct tnode *baseIdNode;
    struct tnode *memberAccessNode;

    switch (baseExprNode->nodeType) {
        case NODE_VARIABLE:
            baseIdNode = createVariableUsageNode(baseExprNode->varName);
            memberAccessNode = createConnectorNode(baseIdNode, memberIdNode);

            activeUserType = baseIdNode->typeInfo->type;
            activeClass = baseIdNode->typeInfo->_class;

            switch (baseIdNode->type) {
                case TUPLE:
                    struct TupleType *tupleType;
                    if (baseIdNode->lSymbolTableEntry) {
                        tupleType = baseIdNode->lSymbolTableEntry->typeInfo->tupleType;
                    } else if (baseIdNode->gSymbolTableEntry) {
                        tupleType = baseIdNode->gSymbolTableEntry->typeInfo->tupleType;
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

                    activeUserType = lookupTT(dataTypeToString(tupleField->type));
                    memberAccessNode->type = tupleField->type;
                    memberAccessNode->typeInfo = createTypeInfo(tupleField->type, NULL, activeUserType, NULL);
                    return memberAccessNode;

                case TYPE:
                    resolvedTypeField = fieldListLookup(activeUserType, memberIdNode->varName);
                    activeUserType = resolvedTypeField->type;
                    memberAccessNode->type = typeTableEntryToType(activeUserType);
                    memberAccessNode->typeInfo = createTypeInfo(typeTableEntryToType(activeUserType), NULL, activeUserType, NULL);

                    memberAccessNode->nodeType = NODE_USER_DEF_TYPE_ACCESS;
                    return memberAccessNode;

                case CLASS:
                    if (isMethodCall) {
                        if (!activeClass) {
                            printf("error1\n");
                        }

                        struct ClassMethod *method = lookupClassMethod(activeClass, memberIdNode->varName);
                        if (!method) {
                            printf("error2\n");
                        }

                        activeClass = method->returnType->_class;
                        activeUserType = method->returnType->type;

                        struct tnode *node = createConnectorNode(memberIdNode, argList);
                        memberAccessNode = createConnectorNode(baseIdNode, node);
                        memberAccessNode->nodeType = NODE_CLASS_METHOD_ACCESS;
                        memberAccessNode->type = method->returnType->kind;
                        memberAccessNode->typeInfo = method->returnType;

                        return memberAccessNode;
                    }

                    resolvedClassField = lookupClassField(baseIdNode->typeInfo->_class, memberIdNode->varName);
                    activeClass = resolvedClassField->typeInfo->_class;
                    activeUserType = resolvedClassField->typeInfo->type;
                    memberAccessNode->type = resolvedClassField->typeInfo->kind;

                    memberAccessNode->typeInfo = resolvedClassField->typeInfo;
                    memberAccessNode->nodeType = NODE_CLASS_FIELD_ACCESS;
                    return memberAccessNode;

                default:
                    compilerError(E_MEMBER_ACCESS_ON_NON_SUPPORTED_TYPE, baseIdNode->varName, baseIdNode->type);
                    return NULL;
            }
        case NODE_ARRAY_ACCESS:
            baseIdNode = baseExprNode->left;
            memberAccessNode = createConnectorNode(baseExprNode, memberIdNode);

            activeUserType = baseIdNode->typeInfo->type;
            resolvedTypeField = fieldListLookup(activeUserType, memberIdNode->varName);

            memberAccessNode->nodeType = NODE_USER_DEF_TYPE_ACCESS;
            memberAccessNode->type = typeTableEntryToType(resolvedTypeField->type);

            activeUserType = resolvedTypeField->type;
            memberAccessNode->typeInfo = createTypeInfo(typeTableEntryToType(activeUserType), NULL, activeUserType, NULL);

            return memberAccessNode;
        default:
            if (isMethodCall) {
                if (!activeClass) {
                    printf("error1\n");
                }

                struct ClassMethod *method = lookupClassMethod(activeClass, memberIdNode->varName);
                if (!method) {
                    printf("error2\n");
                }

                activeClass = method->returnType->_class;
                activeUserType = method->returnType->type;

                struct tnode *node = createConnectorNode(memberIdNode, argList);
                memberAccessNode = createConnectorNode(baseExprNode, node);
                memberAccessNode->nodeType = NODE_CLASS_METHOD_ACCESS;
                memberAccessNode->type = method->returnType->kind;
                memberAccessNode->typeInfo = method->returnType;

                return node;
            }

            memberAccessNode = createConnectorNode(baseExprNode, memberIdNode);
            resolvedTypeField = fieldListLookup(activeUserType, memberIdNode->varName);
            if (activeClass) {
                resolvedClassField = lookupClassField(activeClass, memberIdNode->varName);
            }

            if (resolvedTypeField) {
                memberAccessNode->nodeType = NODE_USER_DEF_TYPE_ACCESS;
                memberAccessNode->type = typeTableEntryToType(resolvedTypeField->type);
                activeUserType = resolvedTypeField->type;
                memberAccessNode->typeInfo = createTypeInfo(typeTableEntryToType(activeUserType), NULL, activeUserType, NULL);
            } else if (resolvedClassField) {
                memberAccessNode->nodeType = NODE_CLASS_FIELD_ACCESS;
                memberAccessNode->type = CLASS;
                activeUserType = resolvedClassField->typeInfo->type;
                memberAccessNode->typeInfo = resolvedClassField->typeInfo;
            }
            activeClass = NULL;

            return memberAccessNode;
    }
}
