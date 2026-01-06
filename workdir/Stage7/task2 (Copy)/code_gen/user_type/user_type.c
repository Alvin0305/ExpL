#include "../../class_table/class_table.h"
#include "../../define/constants.h"
#include "../../error_handler/error_handler.h"
#include "../../g_symbol_table/g_symbol_table.h"
#include "../../local_symbol_table/local_symbol_table.h"
#include "../../node/node.h"
#include "../../register/register.h"
#include "../../semantic_context/semantic_context.h"
#include "../../type_table/type_table.h"
#include "../../util/util.h"
#include "../array/array.h"
#include "../function/function.h"

#include "../code_gen.h"
#include "user_type.h"

#include <stdlib.h>

void findUserTypeFieldAddr(int *fieldAddrReg, struct tnode *node, struct TypeTable **activeType) {
    switch (node->nodeType) {
        case NODE_CONNECTOR:
        case NODE_USER_DEF_TYPE_ACCESS:
            findUserTypeFieldAddr(fieldAddrReg, node->left, activeType);
            findUserTypeFieldAddr(fieldAddrReg, node->right, activeType);
            break;

        case NODE_ARRAY_ACCESS:
            if (*fieldAddrReg == -1) {
                *activeType = node->left->typeInfo->type;
            }

            *fieldAddrReg = generateArrayElementAddress(node);
            break;

        case NODE_VARIABLE:
            if (*fieldAddrReg == -1) {
                *activeType = node->typeInfo->type;
                char *name = node->varName;

                struct GSymbol *globalEntry = lookupGST(name);
                struct LSymbol *localEntry = lookupLST(name);

                *fieldAddrReg = getFreeRegister();
                if (localEntry) {
                    int binding = localEntry->binding;
                    fprintf(target_file, "MOV R%d, BP\n", *fieldAddrReg);
                    fprintf(target_file, "ADD R%d, %d\n", *fieldAddrReg, binding);
                } else if (globalEntry) {
                    int binding = globalEntry->binding;
                    fprintf(target_file, "MOV R%d, %d\n", *fieldAddrReg, binding);
                } else {
                    printf("error\n");
                }
                printf("got %s, active type changes to %s\n", name, node->typeInfo->type->name);
            } else {
                struct FieldList *field = fieldListLookup(*activeType, node->varName);
                *activeType = field->type;
                fprintf(target_file, "MOV R%d, [R%d]\n", *fieldAddrReg, *fieldAddrReg);
                fprintf(target_file, "ADD R%d, %d\n", *fieldAddrReg, field->fieldIndex);
            }
            break;

        default:
            printf("unhandled node in user type access helper: %d\n", node->nodeType);
            break;
    }
}

int generateMethodCall(int selfReg, struct ClassTable *_class, struct tnode *node) {
    struct tnode *functionNameNode = node->left;
    struct tnode *argListNode = node->right;

    struct ClassMethod *entry = lookupClassMethod(_class, functionNameNode->varName);
    if (!entry) {
        compilerError(E_FUNCTION_USED_BEFORE_DECLARATION, functionNameNode->varName);
    }

    int numArgs = getNumOfParams(entry->params);
    int returnReg = getFreeRegister();

    saveMachineStatus();

    pushArgsToStack(argListNode);
    int reg = getFreeRegister();
    fprintf(target_file, "MOV R%d, [R%d]\n", reg, selfReg);
    fprintf(target_file, "PUSH R%d\n", reg);

    fprintf(target_file, "PUSH R%d\n", returnReg);
    fprintf(target_file, "CALL F%d\n", entry->methodLabel);

    releaseRegister(returnReg);
    returnReg = regainMachineStatus(numArgs);

    return returnReg;
}

void findClassFieldAddr(int *fieldAddrReg, struct tnode *node, struct TypeInfo **typeInfo) {
    printf("finding class field addr\n");
    switch (node->nodeType) {
        case NODE_CONNECTOR:
        case NODE_CLASS_FIELD_ACCESS:
            findClassFieldAddr(fieldAddrReg, node->left, typeInfo);
            findClassFieldAddr(fieldAddrReg, node->right, typeInfo);
            break;

        case NODE_VARIABLE:
            char *name = node->varName;
            if (*fieldAddrReg == -1) {
                *typeInfo = node->typeInfo;

                struct GSymbol *globalEntry = lookupGST(name);
                struct LSymbol *localEntry = lookupLST(name);

                *fieldAddrReg = getFreeRegister();
                if (localEntry) {
                    int binding = localEntry->binding;
                    fprintf(target_file, "MOV R%d, BP\n", *fieldAddrReg);
                    fprintf(target_file, "ADD R%d, %d\n", *fieldAddrReg, binding);
                } else if (globalEntry) {
                    int binding = globalEntry->binding;
                    fprintf(target_file, "MOV R%d, %d\n", *fieldAddrReg, binding);
                } else {
                    printf("error\n");
                }
            } else {
                int activeKind = (*typeInfo)->kind;
                struct ClassTable *activeClass = (*typeInfo)->_class;
                struct TypeTable *activeType = (*typeInfo)->type;

                if (activeKind == CLASS) {
                    struct ClassField *classField = lookupClassField(activeClass, name);
                    (*typeInfo) = classField->typeInfo;
                    fprintf(target_file, "MOV R%d, [R%d]\n", *fieldAddrReg, *fieldAddrReg);
                    fprintf(target_file, "ADD R%d, %d\n", *fieldAddrReg, classField->fieldIndex);
                } else {
                    struct FieldList *field = fieldListLookup(activeType, name);
                    (*typeInfo)->type = field->type;
                    (*typeInfo)->kind = typeTableEntryToType(field->type);
                    (*typeInfo)->_class = NULL;
                    (*typeInfo)->tupleType = NULL;
                    fprintf(target_file, "MOV R%d, [R%d]\n", *fieldAddrReg, *fieldAddrReg);
                    fprintf(target_file, "ADD R%d, %d\n", *fieldAddrReg, field->fieldIndex);
                }
            }
            break;

        case NODE_CLASS_METHOD_ACCESS:
            if (*fieldAddrReg == -1) {
                *typeInfo = node->left->typeInfo;
                name = node->left->varName;

                struct GSymbol *globalEntry = lookupGST(name);
                struct LSymbol *localEntry = lookupLST(name);

                *fieldAddrReg = getFreeRegister();
                if (localEntry) {
                    int binding = localEntry->binding;
                    fprintf(target_file, "MOV R%d, BP\n", *fieldAddrReg);
                    fprintf(target_file, "ADD R%d, %d\n", *fieldAddrReg, binding);
                } else if (globalEntry) {
                    int binding = globalEntry->binding;
                    fprintf(target_file, "MOV R%d, %d\n", *fieldAddrReg, binding);
                } else {
                    printf("error\n");
                }
            }
            struct tnode *methodCallNode = node->right;
            print(methodCallNode);
            struct tnode *methodNameNode = methodCallNode->left;
            char *methodName = methodNameNode->varName;
            int activeKind = (*typeInfo)->kind;
            struct ClassTable *activeClass = (*typeInfo)->_class;

            if (activeKind == CLASS) {
                struct ClassMethod *classMethod = lookupClassMethod(activeClass, methodName);
                (*typeInfo) = classMethod->returnType;
                releaseRegister(*fieldAddrReg);
                *fieldAddrReg = generateMethodCall(*fieldAddrReg, activeClass, methodCallNode);
            }
            break;

        default:
            printf("unhandled node in class access helper: %d\n", node->nodeType);
            break;
    }
}

int generateClassFieldAccessCode(struct tnode *root) {
    int addrReg = -1;
    bool flag = true;
    struct TypeInfo *typeInfo = NULL;

    print(root);
    findClassFieldAddr(&addrReg, root, &typeInfo);
    if (flag) {
        fprintf(target_file, "MOV R%d, [R%d]\n", addrReg, addrReg);
    }
    return addrReg;
}

int generateClassMethodCallCode(struct tnode *root) {
    int addrReg = -1;
    struct TypeInfo *typeInfo = NULL;

    print(root);
    findClassFieldAddr(&addrReg, root, &typeInfo);
    
    return addrReg;
}

void generateClassFieldAssignmentCode(struct tnode *root) {
    struct tnode *accessNode = root->left;

    int addrReg = -1;
    struct TypeInfo *typeInfo = NULL;
    findClassFieldAddr(&addrReg, accessNode, &typeInfo);

    int valueReg = generateCode(root->right);
    fprintf(target_file, "MOV [R%d], R%d\n", addrReg, valueReg);

    releaseRegister(addrReg);
    releaseRegister(valueReg);
}

int generateUserTypeAccessCode(struct tnode *root) {
    int addrReg = -1;
    struct TypeTable *type = NULL;
    findUserTypeFieldAddr(&addrReg, root, &type);

    fprintf(target_file, "MOV R%d, [R%d]\n", addrReg, addrReg);
    return addrReg;
}

void generateUserTypeAssignmentCode(struct tnode *root) {
    struct tnode *accessNode = root->left;

    int addrReg = -1;
    struct TypeTable *type = NULL;
    findUserTypeFieldAddr(&addrReg, accessNode, &type);

    int valueReg = generateCode(root->right);
    fprintf(target_file, "MOV [R%d], R%d\n", addrReg, valueReg);

    releaseRegister(addrReg);
    releaseRegister(valueReg);
}
