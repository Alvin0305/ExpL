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

struct Node *createMemberAssignmentNode(struct Node *fieldAccess, struct Node *exprNode) {
    struct Node *node = createConnectorNode(fieldAccess, exprNode);

    if (!isTypeCompatible(fieldAccess->typeInfo, exprNode->typeInfo)) {
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
        printf("[ERROR]");
        printNode(fieldAccess);
    }

    return node;
}

struct Node *createMemberAccessNode(struct Node *baseExprNode, struct Node *memberIdNode, AccessType accessType,
                                    bool isMethodCall, struct Node *argList) {
    static struct TypeTable *activeUserType = NULL;
    static struct ClassTable *activeClass = NULL;
    static struct FieldList *resolvedTypeField = NULL;
    static struct ClassField *resolvedClassField = NULL;

    struct Node *baseIdNode;
    struct Node *memberAccessNode;

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
                    printf("%s is type. new active type is: %s\n", baseIdNode->varName, activeUserType->name);
                    return memberAccessNode;

                case CLASS:
                    if (isMethodCall) {
                        if (!activeClass) {
                            compilerError(E_METHOD_CALLED_ON_NON_CLASS_VARIABLE, memberIdNode->varName);
                        }

                        struct ClassMethod *method = lookupClassMethod(activeClass, memberIdNode->varName);
                        if (!method) {
                            compilerError(E_CALL_NON_EXISTING_METHOD_OF_CLASS, activeClass->name, memberIdNode->varName);
                        }

                        activeClass = method->returnType->_class;
                        activeUserType = method->returnType->type;

                        struct Node *node = createConnectorNode(memberIdNode, argList);
                        node->nodeType = NODE_FUNC_CALL;
                        memberAccessNode = createConnectorNode(baseIdNode, node);
                        memberAccessNode->nodeType = NODE_CLASS_METHOD_ACCESS;
                        memberAccessNode->type = method->returnType->kind;
                        memberAccessNode->typeInfo = method->returnType;

                        printf("%s is class. on calling method %s, new active type is: %s, active Class: %s\n",
                               baseIdNode->varName, memberIdNode->varName, activeUserType ? activeUserType->name : "NONE",
                               activeClass ? activeClass->name : "NONE");

                        return memberAccessNode;
                    }

                    resolvedClassField = lookupClassField(baseIdNode->typeInfo->_class, memberIdNode->varName);
                    if (!resolvedClassField) {
                        compilerError(E_ACCESS_NON_EXISTING_FIELD_OF_CLASS, baseIdNode->typeInfo->_class->name,
                                      memberIdNode->varName);
                    }

                    activeClass = resolvedClassField->typeInfo->_class;
                    activeUserType = resolvedClassField->typeInfo->type;
                    if (activeClass) {
                        memberAccessNode->type = CLASS;
                        printf("%s is class. on offsetting %s, new active type is: %s, active Class: %s\n", baseIdNode->varName,
                               memberIdNode->varName, activeUserType ? activeUserType->name : "NONE",
                               activeClass ? activeClass->name : "NONE");
                    } else if (activeUserType) {
                        memberAccessNode->type = resolvedClassField->typeInfo->kind;
                        printf("%s is class. on offsetting %s new active type is: %s, active Class: %s\n", baseIdNode->varName,
                               memberIdNode->varName, activeUserType ? activeUserType->name : "NONE",
                               activeClass ? activeClass->name : "NONE");
                    }

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
                    compilerError(E_METHOD_CALLED_ON_NON_CLASS_VARIABLE, memberIdNode->varName);
                }

                struct ClassMethod *method = lookupClassMethod(activeClass, memberIdNode->varName);
                if (!method) {
                    compilerError(E_CALL_NON_EXISTING_METHOD_OF_CLASS, activeClass->name, memberIdNode->varName);
                }

                activeClass = method->returnType->_class;
                activeUserType = method->returnType->type;

                struct Node *node = createConnectorNode(memberIdNode, argList);
                node->nodeType = NODE_FUNC_CALL;
                memberAccessNode = createConnectorNode(baseExprNode, node);
                memberAccessNode->nodeType = NODE_CLASS_METHOD_ACCESS;
                memberAccessNode->type = method->returnType->kind;
                memberAccessNode->typeInfo = method->returnType;

                printf("on calling method %s, new active type is: %s, active Class: %s\n", memberIdNode->varName,
                       activeClass ? activeClass->name : "NONE", activeUserType ? activeUserType->name : "NONE");

                return memberAccessNode;
            }

            memberAccessNode = createConnectorNode(baseExprNode, memberIdNode);
            if (activeUserType) {
                resolvedTypeField = fieldListLookup(activeUserType, memberIdNode->varName);
                printf("looking for %s in %s and got %s\n", memberIdNode->varName, activeUserType->name,
                       resolvedTypeField ? resolvedTypeField->name : "NONE");
            } else {
                resolvedTypeField = NULL;
            }
            if (activeClass) {
                resolvedClassField = lookupClassField(activeClass, memberIdNode->varName);
            } else {
                resolvedClassField = NULL;
            }

            if (resolvedTypeField) {
                printf("problem 1\n");
                memberAccessNode->nodeType = NODE_USER_DEF_TYPE_ACCESS;
                memberAccessNode->type = typeTableEntryToType(resolvedTypeField->type);
                activeUserType = resolvedTypeField->type;
                activeClass = NULL;
                memberAccessNode->typeInfo = createTypeInfo(typeTableEntryToType(activeUserType), NULL, activeUserType, NULL);
                printf("on offseting %s, new active type is: %s, active class: %s\n", memberIdNode->varName,
                       activeUserType ? activeUserType->name : "NONE", activeClass ? activeClass->name : "NONE");
            } else if (resolvedClassField) {
                printf("problem 2\n");
                memberAccessNode->nodeType = NODE_CLASS_FIELD_ACCESS;
                memberAccessNode->type = CLASS;
                activeUserType = resolvedClassField->typeInfo->type;
                activeClass = resolvedClassField->typeInfo->_class;
                memberAccessNode->typeInfo = resolvedClassField->typeInfo;
                printf("on offsetting %s, new active type is: %s, active class: %s\n", memberIdNode->varName,
                       activeUserType ? activeUserType->name : "NONE", activeClass ? activeClass->name : "NONE");
            } else {
                compilerError(E_ACCESS_NON_EXISTING_FIELD_OF_CLASS, activeClass ? activeClass->name : activeUserType->name,
                              memberIdNode->varName);
            }

            return memberAccessNode;
    }
}
