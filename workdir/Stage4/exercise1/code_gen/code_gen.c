#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "code_gen.h"
#include "../define/constants.h"
#include "../node/node.h"
#include "../register/register.h"
#include "../label/label.h"
#include "../label/label_stack.h"
#include "../g_symbol_table/g_symbol_table.h"
#include "../util/util.h"

int generateAddRegCode(int leftReg, int rightReg) {
    fprintf(target_file, "ADD R%d, R%d\n", leftReg, rightReg);
    releaseRegister(rightReg);
    return leftReg;
}

int generateSubtractRegCode(int leftReg, int rightReg) {
    fprintf(target_file, "SUB R%d, R%d\n", leftReg, rightReg);
    releaseRegister(rightReg);
    return leftReg;
}

int generateMultiplyRegCode(int leftReg, int rightReg) {
    fprintf(target_file, "MUL R%d, R%d\n", leftReg, rightReg);
    releaseRegister(rightReg);
    return leftReg;
}

int generateDivideRegCode(int leftReg, int rightReg) {
    fprintf(target_file, "DIV R%d, R%d\n", leftReg, rightReg);
    releaseRegister(rightReg);
    return leftReg;
}

int generateModuloRegCode(int leftReg, int rightReg) {
    fprintf(target_file, "MOD R%d, R%d\n", leftReg, rightReg);
    releaseRegister(rightReg);
    return leftReg;
}

void generateWriteToMemoryCode(int reg, int varMemAddr) {
    fprintf(target_file, "MOV [%d], R%d\n", varMemAddr, reg);
}

void generateReadFromConsoleCode(int varMemAddr) {
    int functionNameReg = getFreeRegister();
    int fileDescriptorReg = getFreeRegister();
    int memAddrReg = getFreeRegister();
    int arg3Reg = getFreeRegister();
    int returnReg = getFreeRegister();
    
    fprintf(target_file, "MOV R%d, \"%s\"\n", functionNameReg, "Read");
    fprintf(target_file, "PUSH R%d\n", functionNameReg);

    fprintf(target_file, "MOV R%d, -1\n", fileDescriptorReg);
    fprintf(target_file, "PUSH R%d\n", fileDescriptorReg);

    fprintf(target_file, "MOV R%d, %d\n", memAddrReg, varMemAddr);
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

void generateHeader() {
    fprintf(target_file, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", 0, 2056, 0, 0, 0, 0, 0, 0);
    fprintf(target_file, "MOV SP, %d\n", stackTop);
    fprintf(target_file, "BRKP\n");
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
    int varMemAddr = getAddressOfVariable(node);
    int freeReg = getFreeRegister();

    fprintf(target_file, "MOV R%d, [%d]\n", freeReg, varMemAddr);
    return freeReg;
}

int generateAssignVariableCode(struct tnode *node) {
    int varMemAddr = getAddressOfVariable(node->left);
    int rightReg = generateUserCode(node->right);

    fprintf(target_file, "MOV [%d], R%d\n", varMemAddr, rightReg);
    releaseRegister(rightReg);
    return NO_RETURN;
}

void generateJumpOnZeroCode(int reg, int label) {
    fprintf(target_file, "JZ R%d, L%d\n", reg, label);
}

void generateJumpOnNonZeroCode(int reg, int label) {
    fprintf(target_file, "JNZ R%d, L%d\n", reg, label);
}

int generateConditionCode(struct tnode *node) {
    int leftReg = generateUserCode(node->left);
    int rightReg = generateUserCode(node->right);

    switch (node->nodeType) {
        case NODE_GE: 
            fprintf(target_file, "GE R%d, R%d\n", leftReg, rightReg);
            break;
        
        case NODE_GT: 
            fprintf(target_file, "GT R%d, R%d\n", leftReg, rightReg);
            break;

        case NODE_LE: 
            fprintf(target_file, "LE R%d, R%d\n", leftReg, rightReg);
            break;

        case NODE_LT: 
            fprintf(target_file, "LT R%d, R%d\n", leftReg, rightReg);
            break;

        case NODE_EQ: 
            fprintf(target_file, "EQ R%d, R%d\n", leftReg, rightReg);
            break;

        case NODE_NE: 
            fprintf(target_file, "NE R%d, R%d\n", leftReg, rightReg);
            break;
    }

    releaseRegister(rightReg);

    return leftReg;
}

void generateWhileLoopCode(struct tnode *node) {
    int loopConditionLabel = createNewLabel();
    int restOfCodeLabel = createNewLabel();

    pushToLabelStack(loopConditionLabel, restOfCodeLabel);

    fprintf(target_file, "L%d:\n", loopConditionLabel);
    int reg = generateConditionCode(node->left);
    generateJumpOnZeroCode(reg, restOfCodeLabel);

    releaseRegister(reg);

    generateUserCode(node->right);
    fprintf(target_file, "JMP L%d\n", loopConditionLabel);

    fprintf(target_file, "L%d:\n", restOfCodeLabel);

    popFromLabelStack();
}

void generateIfElseCode(struct tnode *node) {
    int elseLabel = createNewLabel();
    int restOfCodeLabel = createNewLabel();

    struct tnode *conditionNode = node->left;
    struct tnode *connectorNode = node->right;
    struct tnode *ifNode = connectorNode->left;
    struct tnode *elseNode = connectorNode->right;

    int reg = generateConditionCode(conditionNode);
    generateJumpOnZeroCode(reg, elseLabel);

    generateUserCode(ifNode);
    fprintf(target_file, "JMP L%d\n", restOfCodeLabel);

    fprintf(target_file, "L%d:\n", elseLabel);
    generateUserCode(elseNode);

    fprintf(target_file, "L%d:\n", restOfCodeLabel);

    releaseRegister(reg);
}

void generateIfCode(struct tnode *node) {
    int restOfCodeLabel = createNewLabel();

    struct tnode *conditionNode = node->left;
    struct tnode *ifNode = node->right;

    int reg = generateConditionCode(conditionNode);
    generateJumpOnZeroCode(reg, restOfCodeLabel);

    generateUserCode(ifNode);

    fprintf(target_file, "L%d:\n", restOfCodeLabel);
    releaseRegister(reg);
}

void generateBreakCode() {
    struct LabelStackNode *labelStackNode = peekFromLabelStack();
    int restOfCodeLabel = labelStackNode->restOfCodeLabel;

    fprintf(target_file, "JMP L%d\n", restOfCodeLabel);
}

void generateContinueCode() {
    struct LabelStackNode *labelStackNode = peekFromLabelStack();
    int loopConditionLabel = labelStackNode->loopConditionLabel;

    fprintf(target_file, "JMP L%d\n", loopConditionLabel);
}

void generateRepeatUntilCode(struct tnode *node) {
    int loopConditionLabel = createNewLabel();
    int restOfCodeLabel = createNewLabel();

    pushToLabelStack(loopConditionLabel, restOfCodeLabel);

    fprintf(target_file, "L%d:\n", loopConditionLabel);
    int reg = generateConditionCode(node->right);
    generateJumpOnNonZeroCode(reg, restOfCodeLabel);

    releaseRegister(reg);

    generateUserCode(node->left);
    fprintf(target_file, "JMP L%d\n", loopConditionLabel);

    fprintf(target_file, "L%d:\n", restOfCodeLabel);
    popFromLabelStack();
}

void generateDoWhileCode(struct tnode *node) {
    generateUserCode(node->right);

    generateWhileLoopCode(node);
}

int generateArrayElementAddress(struct tnode *arrayAccessNode) {
    struct tnode *idNode = arrayAccessNode->left;
    struct GSymbol *entry = idNode->gSymbolTableEntry;
    int numDimensions = entry->numDimensions;

    int productArray[numDimensions];

    for (int i = 0; i < numDimensions; i++) {
        productArray[i] = 1;
    }

    for (int i = numDimensions - 2; i >= 0; i--) {
        productArray[i] = productArray[i + 1] * entry->dimensions[i + 1];
    }

    struct tnode *node = arrayAccessNode->right;
    int index = 0;

    int sumReg = getFreeRegister();
    fprintf(target_file, "MOV R%d, 0\n", sumReg);

    while (node) {
        struct tnode *indexExpr = NULL;

        if (node->nodeType == NODE_CONNECTOR) {
            indexExpr = node->left; 
        } else {
            indexExpr = node;       
        }

        int indexReg = generateUserCode(indexExpr);
        
        if (productArray[index] != 1) {
            fprintf(target_file, "MUL R%d, %d\n", indexReg, productArray[index]);
        }
        
        fprintf(target_file, "ADD R%d, R%d\n", sumReg, indexReg);
        releaseRegister(indexReg);
        index++;

        if (node->nodeType == NODE_CONNECTOR) {
            node = node->right;
        } else {
            break; 
        }
    }

    int type = entry->type;
    int size = getSizeOfDataType(type);
    int baseAddr = entry->binding;

    fprintf(target_file, "MUL R%d, %d\n", sumReg, size);
    fprintf(target_file, "ADD R%d, %d\n", sumReg, baseAddr);

    return sumReg;
}

int generateArrayAccessCode(struct tnode *arrayAccessNode) {
    int indexReg = generateArrayElementAddress(arrayAccessNode);
    int freeReg = getFreeRegister();

    fprintf(target_file, "MOV R%d, [R%d]\n", freeReg, indexReg);
    releaseRegister(indexReg);

    return freeReg;
}

void generateAssignmentFromArray(struct tnode *arrayAssignNode) {
    struct tnode *left = arrayAssignNode->left;
    int memAddr = generateUserCode(left);

    int indexReg = generateArrayAccessCode(arrayAssignNode->right);
    fprintf(target_file, "MOV [%d], R%d\n", memAddr, indexReg);

    releaseRegister(indexReg);
}

void generateAssignmentToArray(struct tnode *arrayAssignNode) {
    int indexReg = generateArrayElementAddress(arrayAssignNode->left);
    int valueReg = generateUserCode(arrayAssignNode->right);

    fprintf(target_file, "MOV [R%d], R%d\n", indexReg, valueReg);

    releaseRegister(indexReg);
    releaseRegister(valueReg);
}

int generateUserCode(struct tnode *root) {
    if (!root) return NO_RETURN;

    switch (root->nodeType) {
        case NODE_EMPTY:
            return NO_RETURN;

        case NODE_ASSIGN: 
            return generateAssignVariableCode(root);

        case NODE_CONNECTOR:
            generateUserCode(root->left);
            generateUserCode(root->right);
            return NO_RETURN;

        case NODE_VARIABLE:
            return generateLoadVariableCode(root);

        case NODE_CONSTANT:
            return generateLoadConstantCode(root->numVal);

        case NODE_STRING_LITERAL:
            return generateLoadStringLiteralCode(root->strVal);

        case NODE_READ:
            int varMemAddr = getAddressOfVariable(root->left);
            generateReadFromConsoleCode(varMemAddr);
            return NO_RETURN;

        case NODE_WRITE:
            int exprReg = generateUserCode(root->left);
            generateWriteToConsoleCode(exprReg);
            return NO_RETURN;

        case NODE_WHILE:
            generateWhileLoopCode(root);
            return NO_RETURN;

        case NODE_IF:
            generateIfCode(root);
            return NO_RETURN;

        case NODE_IF_ELSE:
            generateIfElseCode(root);
            return NO_RETURN;

        case NODE_BREAK:
            generateBreakCode();
            return NO_RETURN;
        
        case NODE_CONTINUE:
            generateContinueCode();
            return NO_RETURN;

        case NODE_REPEAT_UNTIL:
            generateRepeatUntilCode(root);
            return NO_RETURN;

        case NODE_DO_WHILE:
            generateDoWhileCode(root);
            return NO_RETURN;

        case NODE_ARRAY_ACCESS:
            return generateArrayAccessCode(root);

        case NODE_ARRAY_ASSIGN:
            generateAssignmentToArray(root);
            return NO_RETURN;

        case NODE_ADD:
        case NODE_SUB:
        case NODE_MUL:
        case NODE_DIV: 
        case NODE_MOD: {
            int leftReg = generateUserCode(root->left);
            int rightReg = generateUserCode(root->right);

            switch(root->nodeType) {
                case NODE_ADD: return generateAddRegCode(leftReg, rightReg);
                case NODE_SUB: return generateSubtractRegCode(leftReg, rightReg);
                case NODE_MUL: return generateMultiplyRegCode(leftReg, rightReg);
                case NODE_DIV: return generateDivideRegCode(leftReg, rightReg);
                case NODE_MOD: return generateModuloRegCode(leftReg, rightReg);
            }
        }
    }

    return NO_RETURN;
}

void generateCode(tnode *root) {
    initializeRegisters();

    generateHeader();
    generateUserCode(root);
    generateExitCode();
}

int getAddressOfVariable(struct tnode *node) {
    GSymbol *entry = node->gSymbolTableEntry;
    if (!entry) {
        printf("Failed to get Symbol Table Entry for \"%s\"", node->varName);
        exit(1);
    }

    return entry->binding;
}