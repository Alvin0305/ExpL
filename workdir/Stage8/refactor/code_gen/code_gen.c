#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../class_table/class_table.h"
#include "../define/constants.h"
#include "../error_handler/error_handler.h"
#include "../g_symbol_table/g_symbol_table.h"
#include "../label/label.h"
#include "../label/label_stack.h"
#include "../local_symbol_table/local_symbol_table.h"
#include "../node/node.h"
#include "../register/register.h"
#include "../type_table/type_table.h"
#include "../util/util.h"
#include "code_gen.h"

#include "arithmetic/arithmetic.h"
#include "array/array.h"
#include "control_flow/control_flow.h"
#include "function/function.h"
#include "library/library.h"
#include "member_access/member_access.h"
#include "pointer/pointer.h"
#include "tuple/tuple.h"

void generateWriteToMemoryCode(int reg, int varMemAddr) {
    fprintf(target_file, "MOV [%d], R%d\n", varMemAddr, reg);
    releaseRegister(reg);
}

int getAddressOfVariable(struct Node *node) {
    LSymbol *localEntry = lookupLST(node->varName);
    GSymbol *globalEntry = lookupGST(node->varName, false, NULL, 0);
    int reg = getFreeRegister();

    if (localEntry) {
        int binding = localEntry->binding;

        fprintf(target_file, "MOV R%d, BP\n", reg);
        fprintf(target_file, "ADD R%d, %d\n", reg, binding);
    } else if (globalEntry) {
        fprintf(target_file, "MOV R%d, %d\n", reg, globalEntry->binding);
    } else {
        printf("[ERROR]: Failed to get Symbol Table Entry for \"%s\"", node->varName);
        exit(1);
    }

    return reg;
}

int generateLoadConstantCode(int val) {
    int freeReg = getFreeRegister();
    fprintf(target_file, "MOV R%d, %d\n", freeReg, val);
    return freeReg;
}

int generateLoadStringLiteralCode(char *stringLiteral) {
    int freeReg = getFreeRegister();
    fprintf(target_file, "MOV R%d, %s\n", freeReg, stringLiteral);
    return freeReg;
}

int loadNull() {
    int freeReg = getFreeRegister();
    fprintf(target_file, "MOV R%d, %d\n", freeReg, NULL_VALUE);
    return freeReg;
}

int generateLoadVariableCode(struct Node *node) {
    int varMemAddrReg = getAddressOfVariable(node);
    int freeReg = getFreeRegister();

    fprintf(target_file, "MOV R%d, [R%d]\n", freeReg, varMemAddrReg);
    releaseRegister(varMemAddrReg);

    return freeReg;
}

void generateAssignVariableCode(struct Node *node) {
    int varMemAddrReg = getAddressOfVariable(node->left);
    int rightReg;

    if (node->left->typeInfo->kind == CLASS) {
        if (node->right->nodeType == NODE_VARIABLE) {
            rightReg = getAddressOfVariable(node->right);
        } else if (node->right->nodeType == NODE_CLASS_FIELD_ACCESS) {
            rightReg = resolveMemberAddress(node->right);
        } else {
            int rightReg = generateCode(node->right);
            fprintf(target_file, "MOV [R%d], R%d\n", varMemAddrReg, rightReg);
            releaseRegister(rightReg);
            releaseRegister(varMemAddrReg);
            return;
        }

        int tempReg = getFreeRegister();

        fprintf(target_file, "MOV R%d, [R%d]\n", tempReg, rightReg);
        fprintf(target_file, "MOV [R%d], R%d\n", varMemAddrReg, tempReg);

        fprintf(target_file, "ADD R%d, 1\n", varMemAddrReg);
        fprintf(target_file, "ADD R%d, 1\n", rightReg);
        fprintf(target_file, "MOV R%d, [R%d]\n", tempReg, rightReg);
        fprintf(target_file, "MOV [R%d], R%d\n", varMemAddrReg, tempReg);
        releaseRegister(tempReg);
    } else {
        rightReg = generateCode(node->right);
        fprintf(target_file, "MOV [R%d], R%d\n", varMemAddrReg, rightReg);
    }
    releaseRegister(rightReg);
    releaseRegister(varMemAddrReg);
}

void generateNewClassCode(struct Node *node) {
    struct Node *left = node->left;
    int nodeType = left->nodeType;

    struct ClassTable *_class = lookupCT(node->right->varName);
    int size = _class->numFields;

    if (size < 0 || size > DYNAMIC_MEM_ALLOC_BLOCK_SIZE) {
        compilerError(E_INVALID_SIZE_FOR_CLASS, node->typeInfo->_class->name, size);
    }

    int freeReg = getFreeRegister();
    int returnReg = getFreeRegister();

    fprintf(target_file, "MOV R%d, \"%s\"\n", freeReg, "Alloc");
    fprintf(target_file, "PUSH R%d\n", freeReg);
    fprintf(target_file, "MOV R%d, %d\n", freeReg, size);
    fprintf(target_file, "PUSH R%d\n", freeReg);
    fprintf(target_file, "PUSH R%d\n", freeReg);
    fprintf(target_file, "PUSH R%d\n", freeReg);
    fprintf(target_file, "PUSH R%d\n", freeReg);
    fprintf(target_file, "CALL 0\n");

    fprintf(target_file, "POP R%d\n", returnReg);
    fprintf(target_file, "SUB SP, 4\n");

    releaseRegister(freeReg);

    if (nodeType == NODE_VARIABLE) {
        freeReg = getAddressOfVariable(left);
        fprintf(target_file, "MOV [R%d], R%d\n", freeReg, returnReg);
        fprintf(target_file, "ADD R%d, 1\n", freeReg);
        fprintf(target_file, "MOV [R%d], %d\n", freeReg, STACK_START + _class->classIndex * MAX_NUM_METHODS);
    } else if (nodeType == NODE_CLASS_FIELD_ACCESS) {
        freeReg = resolveMemberAddress(left);
        fprintf(target_file, "MOV [R%d], R%d\n", freeReg, returnReg);
        fprintf(target_file, "ADD R%d, 1\n", freeReg);
        fprintf(target_file, "MOV [R%d], %d\n", freeReg, STACK_START + _class->classIndex * MAX_NUM_METHODS);
    }

    // else if (nodeType == NODE_ARRAY_ACCESS) {
    //     freeReg = generateArrayElementAddress(left);
    //     fprintf(target_file, "MOV [R%d], R%d\n", freeReg, returnReg);
    // }

    releaseRegister(freeReg);
    releaseRegister(returnReg);
}

int generateCode(struct Node *root) {
    if (!root) return __NONE__;

    switch (root->nodeType) {
        case NODE_EMPTY:
            break;

        case NODE_NULL:
            return loadNull();

        case NODE_ASSIGN:
            generateAssignVariableCode(root);
            break;

        case NODE_CONNECTOR:
            generateCode(root->left);
            generateCode(root->right);
            break;

        case NODE_NEW:
            generateNewClassCode(root);
            break;

        case NODE_CLASS_FIELD_ACCESS:
            return generateClassFieldAccessCode(root);

        case NODE_CLASS_METHOD_ACCESS:
            return generateClassMethodCallCode(root);

        case NODE_CLASS_FIELD_ASSIGNMENT:
            generateClassFieldAssignmentCode(root);
            break;

        case NODE_USER_DEF_TYPE_ACCESS:
            return generateUserTypeAccessCode(root);

        case NODE_USER_DEF_TYPE_ASSIGNMENT:
            generateUserTypeAssignmentCode(root);
            break;

        case NODE_VARIABLE:
            return generateLoadVariableCode(root);

        case NODE_CONSTANT:
            return generateLoadConstantCode(root->numVal);

        case NODE_STRING_LITERAL:
            return generateLoadStringLiteralCode(root->strVal);

        case NODE_DEREFERENCE:
            return generateDereferenceCode(root);

        case NODE_ASSIGN_TO_DEREFERENCED:
            generateAssignToDereferencedCode(root);
            break;

        case NODE_ADDRESS_TO:
            return generateAddressToCode(root);

        case NODE_READ:
            int varMemAddrReg = getAddressOfVariable(root->left);
            generateReadFromConsoleCode(varMemAddrReg);
            break;

        case NODE_READ_TO_ARRAY:
            int memAddrReg = generateArrayElementAddress(root->left);
            generateReadFromConsoleCode(memAddrReg);
            break;

        case NODE_READ_TO_MEMBER:
            memAddrReg = resolveMemberAddress(root->left);
            generateReadFromConsoleCode(memAddrReg);
            break;

        case NODE_WRITE:
            int exprReg = generateCode(root->left);
            generateWriteToConsoleCode(exprReg);
            break;

        case NODE_WHILE:
            generateWhileLoopCode(root);
            break;

        case NODE_IF:
            generateIfCode(root);
            break;

        case NODE_IF_ELSE:
            generateIfElseCode(root);
            break;

        case NODE_BREAK:
            generateBreakCode();
            break;

        case NODE_CONTINUE:
            generateContinueCode();
            break;

        case NODE_REPEAT_UNTIL:
            generateRepeatUntilCode(root);
            break;

        case NODE_DO_WHILE:
            generateDoWhileCode(root);
            break;

        case NODE_ARRAY_ACCESS:
            return generateArrayAccessCode(root);

        case NODE_ARRAY_ASSIGN:
            generateAssignmentToArray(root);
            break;

        case NODE_ADD:
        case NODE_SUB:
        case NODE_MUL:
        case NODE_DIV:
        case NODE_MOD:
            {
                int leftReg = generateCode(root->left);
                int rightReg = generateCode(root->right);

                switch (root->nodeType) {
                    case NODE_ADD:
                        return generateAddRegCode(leftReg, rightReg);
                    case NODE_SUB:
                        return generateSubtractRegCode(leftReg, rightReg);
                    case NODE_MUL:
                        return generateMultiplyRegCode(leftReg, rightReg);
                    case NODE_DIV:
                        return generateDivideRegCode(leftReg, rightReg);
                    case NODE_MOD:
                        return generateModuloRegCode(leftReg, rightReg);
                    default:
                        printf("[WARNING]: Unhandled arithmetic node while code generation: ");
                        printNode(root);
                        break;
                }
            }

        case NODE_INC:
            generateIncrementCode(root);
            break;

        case NODE_DEC:
            generateDecrementCode(root);
            break;

        case NODE_BREAK_POINT:
            fprintf(target_file, "BRKP\n");
            break;

        case NODE_FUNC_CALL:
            return generateFunctionCallCode(root);

        case NODE_RETURN:
            generateFunctionReturnCode(root);
            break;

        case NODE_TUPLE_ACCESS:
            return generateTupleAccessCode(root);

        case NODE_TUPLE_ASSIGN:
            generateTupleAssignCode(root);
            break;

        case NODE_TUPLE_POINTER_ACCESS:
            return generateTuplePointerAccessCode(root);

        case NODE_TUPLE_POINTER_ASSIGN:
            generateTuplePointerAssignCode(root);
            break;

        case NODE_INIT:
            return generateHeapInitializeCode(root);

        case NODE_ALLOC:
            generateAllocCode(root);
            break;

        case NODE_FREE:
            generateFreeCode(root);
            break;

        default:
            printf("[WARNING]: Unhandled node came while generating code: ");
            printNode(root);
            break;
    }

    return __NONE__;
}

void generateHeader() { fprintf(target_file, "%d\n%s\n%d\n%d\n%d\n%d\n%d\n%d\n", 0, MAIN, 0, 0, 0, 0, 0, 0); }