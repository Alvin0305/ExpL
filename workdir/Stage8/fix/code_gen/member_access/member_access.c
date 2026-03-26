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

    struct ClassMethod *method = lookupClassMethod(_class, functionNameNode->varName);
    if (!method) {
        int n = 0;
        compilerError(E_FUNCTION_USED_BEFORE_DECLARATION, functionNameNode->varName, getTypeInfoFromArgs(argListNode, &n), n);
    }

    int returnSpace = getFreeRegister();

    int registersPushed = saveMachineStatus();
    pushArgsToStack(argListNode);

    int selfValueReg = getFreeRegister();
    int VFPtrReg = getFreeRegister();

    fprintf(target_file, "MOV R%d, [R%d]\n", selfValueReg, selfReg);
    fprintf(target_file, "PUSH R%d\n", selfValueReg);

    fprintf(target_file, "MOV R%d, R%d\n", VFPtrReg, selfReg);
    fprintf(target_file, "ADD R%d, 1\n", VFPtrReg);
    fprintf(target_file, "MOV R%d, [R%d]\n", VFPtrReg, VFPtrReg);
    fprintf(target_file, "PUSH R%d\n", VFPtrReg);

    fprintf(target_file, "PUSH R0\n");
    if (method->returnType->kind == CLASS) {
        fprintf(target_file, "PUSH R0\n");
    }

    fprintf(target_file, "ADD R%d, %d\n", VFPtrReg, method->methodIndex);
    fprintf(target_file, "MOV R%d, [R%d]\n", VFPtrReg, VFPtrReg);
    fprintf(target_file, "BRKP\n");

    fprintf(target_file, "CALL R%d\n", VFPtrReg);

    releaseRegister(returnSpace);
    int returnValueReg = regainMachineStatus(registersPushed, method->params, method->returnType);

    return returnValueReg;
}

int resolveMemberAddress(struct Node *node) {
    static struct TypeInfo *activeTypeInfo = NULL;
    char *name;

    switch (node->nodeType) {
        case NODE_ARRAY_ACCESS:
            activeTypeInfo = node->typeInfo;
            return generateArrayElementAddress(node);

        case NODE_VARIABLE:
            name = node->varName;
            activeTypeInfo = node->typeInfo;

            struct GSymbol *globalEntry = lookupGST(name, false, NULL, 0);
            struct LSymbol *localEntry = lookupLST(name);

            int varMemAddrReg = getFreeRegister();
            if (localEntry) {
                int binding = localEntry->binding;
                fprintf(target_file, "MOV R%d, BP\n", varMemAddrReg);
                fprintf(target_file, "ADD R%d, %d\n", varMemAddrReg, binding);
            } else if (globalEntry) {
                int binding = globalEntry->binding;
                fprintf(target_file, "MOV R%d, %d\n", varMemAddrReg, binding);
            }
            return varMemAddrReg;

        case NODE_CLASS_FIELD_ACCESS:
        case NODE_USER_DEF_TYPE_ACCESS:
            int memberReg = resolveMemberAddress(node->left);
            name = node->right->varName;

            if (activeTypeInfo->kind == CLASS) {
                struct ClassField *classField = lookupClassField(activeTypeInfo->_class, name);
                activeTypeInfo = classField->typeInfo;
                fprintf(target_file, "MOV R%d, [R%d]\n", memberReg, memberReg);
                fprintf(target_file, "ADD R%d, %d\n", memberReg, classField->fieldIndex);
            } else {
                struct TypeField *field = fieldListLookup(activeTypeInfo->type, name);
                activeTypeInfo = createTypeInfo(typeTableEntryToType(field->type), NULL, field->type, NULL);
                fprintf(target_file, "MOV R%d, [R%d]\n", memberReg, memberReg);
                fprintf(target_file, "ADD R%d, %d\n", memberReg, field->fieldIndex);
            }
            return memberReg;

        case NODE_CLASS_METHOD_ACCESS:
            int methodReg = resolveMemberAddress(node->left);
            struct Node *methodCallNode = node->right;
            struct Node *methodNameNode = methodCallNode->left;
            char *methodName = methodNameNode->varName;
            int activeKind = activeTypeInfo->kind;
            struct ClassTable *activeClass = activeTypeInfo->_class;

            if (activeKind == CLASS) {
                struct ClassMethod *classMethod = lookupClassMethod(activeClass, methodName);
                activeTypeInfo = classMethod->returnType;
                releaseRegister(methodReg);
                methodReg = generateMethodCall(methodReg, activeClass, methodCallNode);
            }
            return methodReg;

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
