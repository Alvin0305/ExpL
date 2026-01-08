#include "../../class_table/class_table.h"
#include "../../define/constants.h"
#include "../../error_handler/error_handler.h"
#include "../../g_symbol_table/g_symbol_table.h"
#include "../../local_symbol_table/local_symbol_table.h"
#include "../../node/node.h"
#include "../../register/register.h"
#include "../../type_info/type_info.h"
#include "../../type_table/type_table.h"
#include "../../util/util.h"
#include "../array/array.h"
#include "../function/function.h"

#include "../code_gen.h"
#include "member_access.h"

#include <stdlib.h>

int generateMethodCall(int selfReg, struct ClassTable *_class, struct Node *node) {
    struct Node *functionNameNode = node->left;
    struct Node *argListNode = node->right;

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

int resolveMemberAddress(struct Node *node) {
    static struct TypeInfo *activeTypeInfo = NULL;
    int freeReg;

    switch (node->nodeType) {
        case NODE_ARRAY_ACCESS:
            activeTypeInfo = node->typeInfo;
            return generateArrayElementAddress(node);

        case NODE_VARIABLE:
            char *name = node->varName;
            activeTypeInfo = node->typeInfo;

            struct GSymbol *globalEntry = lookupGST(name);
            struct LSymbol *localEntry = lookupLST(name);

            freeReg = getFreeRegister();
            if (localEntry) {
                int binding = localEntry->binding;
                fprintf(target_file, "MOV R%d, BP\n", freeReg);
                fprintf(target_file, "ADD R%d, %d\n", freeReg, binding);
            } else if (globalEntry) {
                int binding = globalEntry->binding;
                fprintf(target_file, "MOV R%d, %d\n", freeReg, binding);
            }
            return freeReg;

        case NODE_CLASS_FIELD_ACCESS:
        case NODE_USER_DEF_TYPE_ACCESS:
            {
                freeReg = resolveMemberAddress(node->left);
                int activeKind = activeTypeInfo->kind;
                struct ClassTable *activeClass = activeTypeInfo->_class;
                struct TypeTable *activeType = activeTypeInfo->type;
                char *name = node->right->varName;

                if (activeKind == CLASS) {
                    struct ClassField *classField = lookupClassField(activeClass, name);
                    activeTypeInfo = classField->typeInfo;
                    fprintf(target_file, "MOV R%d, [R%d]\n", freeReg, freeReg);
                    fprintf(target_file, "ADD R%d, %d\n", freeReg, classField->fieldIndex);
                } else {
                    struct TypeField *field = fieldListLookup(activeType, name);
                    activeTypeInfo = createTypeInfo(typeTableEntryToType(field->type), NULL, field->type, NULL);
                    fprintf(target_file, "MOV R%d, [R%d]\n", freeReg, freeReg);
                    fprintf(target_file, "ADD R%d, %d\n", freeReg, field->fieldIndex);
                }
                return freeReg;
            }

        case NODE_CLASS_METHOD_ACCESS:
            freeReg = resolveMemberAddress(node->left);
            struct Node *methodCallNode = node->right;
            struct Node *methodNameNode = methodCallNode->left;
            char *methodName = methodNameNode->varName;
            int activeKind = activeTypeInfo->kind;
            struct ClassTable *activeClass = activeTypeInfo->_class;

            if (activeKind == CLASS) {
                struct ClassMethod *classMethod = lookupClassMethod(activeClass, methodName);
                activeTypeInfo = classMethod->returnType;
                releaseRegister(freeReg);
                freeReg = generateMethodCall(freeReg, activeClass, methodCallNode);
            }
            return freeReg;

        default:
            printf("[WARNING]: unhandled node in class access helper: %d\n", node->nodeType);
            return __NONE__;
    }
}

int generateClassFieldAccessCode(struct Node *root) {
    int addrReg = resolveMemberAddress(root);
    fprintf(target_file, "MOV R%d, [R%d]\n", addrReg, addrReg);

    return addrReg;
}

int generateClassMethodCallCode(struct Node *root) { return resolveMemberAddress(root); }

void generateClassFieldAssignmentCode(struct Node *root) {
    struct Node *accessNode = root->left;

    int addrReg = resolveMemberAddress(accessNode);

    int valueReg = generateCode(root->right);
    fprintf(target_file, "MOV [R%d], R%d\n", addrReg, valueReg);

    releaseRegister(addrReg);
    releaseRegister(valueReg);
}

int generateUserTypeAccessCode(struct Node *root) {
    int addrReg = resolveMemberAddress(root);

    fprintf(target_file, "MOV R%d, [R%d]\n", addrReg, addrReg);
    return addrReg;
}

void generateUserTypeAssignmentCode(struct Node *root) {
    struct Node *accessNode = root->left;
    struct Node *valueNode = root->right;

    int addrReg = resolveMemberAddress(accessNode);
    int valueReg = generateCode(valueNode);

    fprintf(target_file, "MOV [R%d], R%d\n", addrReg, valueReg);

    releaseRegister(addrReg);
    releaseRegister(valueReg);
}
