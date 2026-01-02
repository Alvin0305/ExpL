#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../define/constants.h"
#include "../error_handler/error_handler.h"
#include "../g_symbol_table/g_symbol_table.h"
#include "../label/label.h"
#include "../label/label_stack.h"
#include "../local_symbol_table/local_symbol_table.h"
#include "../node/node.h"
#include "../register/register.h"
#include "../util/util.h"
#include "../type_table/type_table.h"
#include "code_gen.h"

#include "arithmetic/arithmetic.h"
#include "array/array.h"
#include "control_flow/control_flow.h"
#include "function/function.h"
#include "tuple/tuple.h"

void generateWriteToMemoryCode(int reg, int varMemAddr) {
    fprintf(target_file, "MOV [%d], R%d\n", varMemAddr, reg);
    releaseRegister(reg);
}

void generateReadFromConsoleCode(int varMemAddrReg) {
    int functionNameReg = getFreeRegister();
    int fileDescriptorReg = getFreeRegister();
    int arg3Reg = getFreeRegister();
    int returnReg = getFreeRegister();

    fprintf(target_file, "MOV R%d, \"%s\"\n", functionNameReg, "Read");
    fprintf(target_file, "PUSH R%d\n", functionNameReg);

    fprintf(target_file, "MOV R%d, -1\n", fileDescriptorReg);
    fprintf(target_file, "PUSH R%d\n", fileDescriptorReg);

    fprintf(target_file, "PUSH R%d\n", varMemAddrReg);

    fprintf(target_file, "PUSH R%d\n", arg3Reg);
    fprintf(target_file, "PUSH R%d\n", returnReg);

    fprintf(target_file, "CALL 0\n");
    fprintf(target_file, "SUB SP, 5\n");

    releaseRegister(functionNameReg);
    releaseRegister(fileDescriptorReg);
    releaseRegister(varMemAddrReg);
    releaseRegister(arg3Reg);
    releaseRegister(returnReg);
}

void generateReadFromConsoleCodeToAddrInReg(int memAddrReg) {
    int functionNameReg = getFreeRegister();
    int fileDescriptorReg = getFreeRegister();
    int arg3Reg = getFreeRegister();
    int returnReg = getFreeRegister();

    fprintf(target_file, "MOV R%d, \"%s\"\n", functionNameReg, "Read");
    fprintf(target_file, "PUSH R%d\n", functionNameReg);

    fprintf(target_file, "MOV R%d, -1\n", fileDescriptorReg);
    fprintf(target_file, "PUSH R%d\n", fileDescriptorReg);

    fprintf(target_file, "PUSH R%d\n", memAddrReg);

    fprintf(target_file, "PUSH R%d\n", arg3Reg);
    fprintf(target_file, "PUSH R%d\n", returnReg);

    fprintf(target_file, "CALL 0\n");
    fprintf(target_file, "SUB SP, 5\n");

    releaseRegister(functionNameReg);
    releaseRegister(fileDescriptorReg);
    releaseRegister(memAddrReg);
    releaseRegister(arg3Reg);
    releaseRegister(returnReg);
}

void generateWriteToConsoleCode(int reg) {
    int functionNameReg = getFreeRegister();
    int fileDescriptorReg = getFreeRegister();
    int arg3Reg = getFreeRegister();
    int returnReg = getFreeRegister();

    fprintf(target_file, "MOV R%d, \"Write\"\n", functionNameReg);
    fprintf(target_file, "PUSH R%d\n", functionNameReg);

    fprintf(target_file, "MOV R%d, -2\n", fileDescriptorReg);
    fprintf(target_file, "PUSH R%d\n", fileDescriptorReg);

    fprintf(target_file, "PUSH R%d\n", reg);
    fprintf(target_file, "PUSH R%d\n", arg3Reg);
    fprintf(target_file, "PUSH R%d\n", returnReg);

    fprintf(target_file, "CALL 0\n");
    fprintf(target_file, "SUB SP, 5\n");

    releaseRegister(functionNameReg);
    releaseRegister(returnReg);
    releaseRegister(arg3Reg);
    releaseRegister(fileDescriptorReg);
    releaseRegister(reg);
}

void generateExitCode() {
    int freeReg = getFreeRegister();

    fprintf(target_file, "MOV R%d, \"Exit\"\n", freeReg);
    fprintf(target_file, "PUSH R%d\n", freeReg);
    fprintf(target_file, "PUSH R%d\n", freeReg);
    fprintf(target_file, "PUSH R%d\n", freeReg);
    fprintf(target_file, "PUSH R%d\n", freeReg);
    fprintf(target_file, "PUSH R%d\n", freeReg);
    fprintf(target_file, "CALL 0\n");

    releaseRegister(freeReg);
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

int generateLoadVariableCode(struct tnode *node) {
    int varMemAddrReg = getAddressOfVariable(node);
    int freeReg = getFreeRegister();

    fprintf(target_file, "MOV R%d, [R%d]\n", freeReg, varMemAddrReg);
    releaseRegister(varMemAddrReg);
    return freeReg;
}

int generateAssignVariableCode(struct tnode *node) {
    int varMemAddrReg = getAddressOfVariable(node->left);
    int rightReg = generateCode(node->right);

    if (rightReg == __NONE__) {
        compilerError(E_INVALID_REGISTER);
    }

    fprintf(target_file, "MOV [R%d], R%d\n", varMemAddrReg, rightReg);
    releaseRegister(rightReg);
    releaseRegister(varMemAddrReg);
    return __NONE__;
}

int generateAddressToCode(struct tnode *addressToNode) {
    struct tnode *idNode = addressToNode->left;

    return getAddressOfVariable(idNode);
}

int generateDereferenceCode(struct tnode *dereferenceNode) {
    struct tnode *idNode = dereferenceNode->left;

    int freeReg = getFreeRegister();
    int idReg = generateCode(idNode);

    if (idReg == __NONE__) {
        compilerError(E_INVALID_REGISTER);
    }

    fprintf(target_file, "MOV R%d, [R%d]\n", freeReg, idReg);

    releaseRegister(idReg);
    return freeReg;
}

void generateAssignToDereferencedCode(struct tnode *assignNode) {
    struct tnode *dereferencedNode = assignNode->left;
    struct tnode *exprNode = assignNode->right;

    int exprReg = generateCode(exprNode);
    int memAddrReg = generateCode(dereferencedNode);

    if (exprReg == __NONE__ || memAddrReg == __NONE__) {
        compilerError(E_INVALID_REGISTER);
    }

    fprintf(target_file, "MOV [R%d], R%d\n", memAddrReg, exprReg);

    releaseRegister(exprReg);
    releaseRegister(memAddrReg);
}

int generateCode(struct tnode *root) {
    if (!root) return __NONE__;

    switch (root->nodeType) {
        case NODE_EMPTY:
            break;

        case NODE_ASSIGN:
            return generateAssignVariableCode(root);

        case NODE_CONNECTOR:
            generateCode(root->left);
            generateCode(root->right);
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
            {
                int varMemAddrReg = getAddressOfVariable(root->left);
                generateReadFromConsoleCode(varMemAddrReg);
                break;
            }

        case NODE_READ_TO_ARRAY:
            {
                int memAddrReg = generateArrayElementAddress(root->left);
                generateReadFromConsoleCodeToAddrInReg(memAddrReg);
                break;
            }

        case NODE_WRITE:
            {
                int exprReg = generateCode(root->left);
                generateWriteToConsoleCode(exprReg);
                break;
            }

        case NODE_WHILE:
            {
                generateWhileLoopCode(root);
                break;
            }

        case NODE_IF:
            {
                generateIfCode(root);
                break;
            }

        case NODE_IF_ELSE:
            {
                generateIfElseCode(root);
                break;
            }

        case NODE_BREAK:
            {
                generateBreakCode();
                break;
            }

        case NODE_CONTINUE:
            {
                generateContinueCode();
                break;
            }

        case NODE_REPEAT_UNTIL:
            {
                generateRepeatUntilCode(root);
                break;
            }

        case NODE_DO_WHILE:
            {
                generateDoWhileCode(root);
                break;
            }

        case NODE_ARRAY_ACCESS:
            {
                return generateArrayAccessCode(root);
            }

        case NODE_ARRAY_ASSIGN:
            {
                generateAssignmentToArray(root);
                break;
            }

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

        default:
            printf("[WARNING]: Unhandled node came while generating code: ");
            printNode(root);
            break;
    }

    return __NONE__;
}

void generateHeader() {
    fprintf(target_file, "%d\n%s\n%d\n%d\n%d\n%d\n%d\n%d\n", 0, "MAIN", 0, 0, 0, 0, 0, 0);
}

int getAddressOfVariable(struct tnode *node) {
    LSymbol *localEntry = lookupLST(node->varName);
    int reg = getFreeRegister();

    if (!localEntry) {
        GSymbol *globalEntry = node->gSymbolTableEntry;
        if (!globalEntry) {
            printf("[ERROR]: Failed to get Symbol Table Entry for \"%s\"", node->varName);
            exit(1);
        }
        fprintf(target_file, "MOV R%d, %d\n", reg, globalEntry->binding);
        return reg;
    }

    int binding = localEntry->binding;
    if (binding < 0) {
        fprintf(target_file, "MOV R%d, BP\n", reg);
        fprintf(target_file, "SUB R%d, %d\n", reg, -binding);
    } else {
        fprintf(target_file, "MOV R%d, BP\n", reg);
        fprintf(target_file, "ADD R%d, %d\n", reg, binding);
    }

    return reg;
}