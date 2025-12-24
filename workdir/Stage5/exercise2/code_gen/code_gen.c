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
#include "code_gen.h"

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

void generateIncrementCode(struct tnode *node) {
    struct tnode *idNode = node->left;

    int reg = generateLoadVariableCode(idNode);
    int varMemAddr = idNode->gSymbolTableEntry->binding;

    fprintf(target_file, "INR R%d\n", reg);
    generateWriteToMemoryCode(reg, varMemAddr);
}

void generateDecrementCode(struct tnode *node) {
    struct tnode *idNode = node->left;

    int reg = generateLoadVariableCode(idNode);
    int varMemAddr = idNode->gSymbolTableEntry->binding;

    fprintf(target_file, "DCR R%d\n", reg);
    generateWriteToMemoryCode(reg, varMemAddr);
}

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
    int rightReg = generateUserCode(node->right);

    fprintf(target_file, "MOV [R%d], R%d\n", varMemAddrReg, rightReg);
    releaseRegister(rightReg);
    releaseRegister(varMemAddrReg);
    return NO_RETURN;
}

void generateLabelHeader(int label) {
    fprintf(target_file, "L%d:\n", label);
}

void generateJumpOnZeroCode(int reg, int label) {
    fprintf(target_file, "JZ R%d, L%d\n", reg, label);
    releaseRegister(reg);
}

void generateJumpOnNonZeroCode(int reg, int label) {
    fprintf(target_file, "JNZ R%d, L%d\n", reg, label);
    releaseRegister(reg);
}

void generateJumpCode(int label) {
    fprintf(target_file, "JMP L%d\n", label);
}

void generateConditionCode(struct tnode *node, int trueLabel, int falseLabel) {
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

    generateJumpOnNonZeroCode(leftReg, trueLabel);
    generateJumpCode(falseLabel);

    releaseRegister(leftReg);
    releaseRegister(rightReg);
}

void generateLogicalConditionCode(struct tnode *node, int trueLabel, int falseLabel) {
    int secondConditionLabel;

    switch (node->nodeType) {
    case NODE_LE:
    case NODE_LT:
    case NODE_GE:
    case NODE_GT:
    case NODE_NE:
    case NODE_EQ:
        generateConditionCode(node, trueLabel, falseLabel);
        break;

    case NODE_AND:
        secondConditionLabel = createNewLabel();
        generateLogicalConditionCode(node->left, secondConditionLabel, falseLabel);
        generateLabelHeader(secondConditionLabel);
        generateLogicalConditionCode(node->right, trueLabel, falseLabel);
        break;

    case NODE_OR:
        secondConditionLabel = createNewLabel();
        generateLogicalConditionCode(node->left, trueLabel, secondConditionLabel);
        generateLabelHeader(secondConditionLabel);
        generateLogicalConditionCode(node->right, trueLabel, falseLabel);
        break;

    case NODE_NOT:
        generateLogicalConditionCode(node->left, falseLabel, trueLabel);
        break;

    default:
        printf("[Compiler ERROR]: Called logical condition code generation on non logical node: %d\n", node->nodeType);
        break;
    }
}

void generateIfElseCode(struct tnode *node) {
    int ifLabel = createNewLabel();
    int elseLabel = createNewLabel();
    int restOfCodeLabel = createNewLabel();

    struct tnode *conditionNode = node->left;
    struct tnode *connectorNode = node->right;
    struct tnode *ifNode = connectorNode->left;
    struct tnode *elseNode = connectorNode->right;

    generateLogicalConditionCode(conditionNode, ifLabel, elseLabel);

    generateLabelHeader(ifLabel);
    generateUserCode(ifNode);
    generateJumpCode(restOfCodeLabel);

    generateLabelHeader(elseLabel);
    generateUserCode(elseNode);

    generateLabelHeader(restOfCodeLabel);
}

void generateIfCode(struct tnode *node) {
    int ifLabel = createNewLabel();
    int restOfCodeLabel = createNewLabel();

    struct tnode *conditionNode = node->left;
    struct tnode *ifNode = node->right;

    generateLogicalConditionCode(conditionNode, ifLabel, restOfCodeLabel);

    generateLabelHeader(ifLabel);
    generateUserCode(ifNode);

    generateLabelHeader(restOfCodeLabel);
}

void generateWhileLoopCode(struct tnode *node) {
    int loopConditionLabel = createNewLabel();
    int loopBodyLabel = createNewLabel();
    int restOfCodeLabel = createNewLabel();

    pushToLabelStack(loopConditionLabel, restOfCodeLabel);

    generateLabelHeader(loopConditionLabel);
    generateLogicalConditionCode(node->left, loopBodyLabel, restOfCodeLabel);

    generateLabelHeader(loopBodyLabel);
    generateUserCode(node->right);
    generateJumpCode(loopConditionLabel);

    generateLabelHeader(restOfCodeLabel);

    popFromLabelStack();
}

void generateBreakCode() {
    struct LabelStackNode *labelStackNode = peekFromLabelStack();
    int restOfCodeLabel = labelStackNode->restOfCodeLabel;

    generateJumpCode(restOfCodeLabel);
}

void generateContinueCode() {
    struct LabelStackNode *labelStackNode = peekFromLabelStack();
    int loopConditionLabel = labelStackNode->loopConditionLabel;

    generateJumpCode(loopConditionLabel);
}

void generateRepeatUntilCode(struct tnode *node) {
    int loopConditionLabel = createNewLabel();
    int loopBodyLabel = createNewLabel();
    int restOfCodeLabel = createNewLabel();

    pushToLabelStack(loopConditionLabel, restOfCodeLabel);

    generateLabelHeader(loopConditionLabel);
    generateLogicalConditionCode(node->right, restOfCodeLabel, loopBodyLabel);

    generateLabelHeader(loopBodyLabel);
    generateUserCode(node->left);
    generateJumpCode(loopConditionLabel);

    generateLabelHeader(restOfCodeLabel);
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

int generateAddressToCode(struct tnode *addressToNode) {
    struct tnode *idNode = addressToNode->left;

    return getAddressOfVariable(idNode);
}

int generateDereferenceCode(struct tnode *dereferenceNode) {
    struct tnode *idNode = dereferenceNode->left;

    int freeReg = getFreeRegister();
    int idReg = generateUserCode(idNode);

    fprintf(target_file, "MOV R%d, [R%d]\n", freeReg, idReg);

    releaseRegister(idReg);
    return freeReg;
}

void generateAssignToDereferencedCode(struct tnode *assignNode) {
    struct tnode *dereferencedNode = assignNode->left;
    struct tnode *exprNode = assignNode->right;

    int exprReg = generateUserCode(exprNode);
    int memAddrReg = generateUserCode(dereferencedNode);

    fprintf(target_file, "MOV [R%d], R%d\n", memAddrReg, exprReg);

    releaseRegister(exprReg);
    releaseRegister(memAddrReg);
}

int generateGetTupleMemoryAddrCode(struct tnode *tupleAccessNode) {
    struct tnode *tupleIdNode = tupleAccessNode->left;
    struct tnode *tupleFieldNode = tupleAccessNode->right;

    if (!tupleIdNode || !tupleFieldNode) {
        compilerError(E_AST_STRUCTURE_INCORRECT, tupleAccessNode);
    } else if (tupleIdNode->nodeType != NODE_VARIABLE) {
        compilerError(E_AST_NODE_TYPE_MISMATCH, tupleAccessNode->left, NODE_VARIABLE, tupleIdNode->nodeType);
    } else if (tupleFieldNode->nodeType != NODE_VARIABLE) {
        compilerError(E_AST_NODE_TYPE_MISMATCH, tupleAccessNode->right, NODE_VARIABLE, tupleFieldNode->nodeType);
    }

    char *tupleName = tupleIdNode->varName;
    char *fieldName = tupleFieldNode->varName;

    if (!tupleName) {
        compilerError(E_AST_NULL_VARNAME, "Tuple Name");
    } else if (!fieldName) {
        compilerError(E_AST_NULL_VARNAME, "Tuple Field Name");
    }

    LSymbol *localEntry = local_st_lookup(tupleName);
    GSymbol *globalEntry = lookupGST(tupleName);
    Tuple *tupleType = NULL;
    int binding;

    if (localEntry) {
        tupleType = localEntry->tupleEntry;
        binding = localEntry->binding;
    } else if (globalEntry) {
        tupleType = globalEntry->tupleEntry;
        binding = globalEntry->binding;
    } else {
        compilerError(E_VARIABLE_USED_BEFORE_DECLARATION, tupleName);
    }

    int offsetOfField = getOffsetOfTupleField(tupleType, fieldName);
    int memAddr = binding + offsetOfField;

    int freeReg = getFreeRegister();
    if (localEntry) {
        fprintf(target_file, "MOV R%d, BP\n", freeReg);
        fprintf(target_file, "ADD R%d, %d\n", freeReg, memAddr + 1);
        return freeReg;
    } else if (globalEntry) {
        fprintf(target_file, "MOV R%d, %d\n", freeReg, memAddr);
        return freeReg;
    }

    return __NONE__;
}

int generateGetTuplePointerMemoryAddrCode(struct tnode *tuplePointerAccessNode) {
    struct tnode *tupleIdNode = tuplePointerAccessNode->left;
    struct tnode *tupleFieldNode = tuplePointerAccessNode->right;

    if (!tupleIdNode || !tupleFieldNode) {
        compilerError(E_AST_STRUCTURE_INCORRECT, tuplePointerAccessNode);
    } else if (tupleIdNode->nodeType != NODE_VARIABLE) {
        compilerError(E_AST_NODE_TYPE_MISMATCH, tuplePointerAccessNode->left, NODE_VARIABLE, tupleIdNode->nodeType);
    } else if (tupleFieldNode->nodeType != NODE_VARIABLE) {
        compilerError(E_AST_NODE_TYPE_MISMATCH, tuplePointerAccessNode->right, NODE_VARIABLE, tupleFieldNode->nodeType);
    }

    char *tupleName = tupleIdNode->varName;
    char *fieldName = tupleFieldNode->varName;

    if (!tupleName) {
        compilerError(E_AST_NULL_VARNAME, "Tuple Name");
    } else if (!fieldName) {
        compilerError(E_AST_NULL_VARNAME, "Tuple Field Name");
    }

    LSymbol *localEntry = local_st_lookup(tupleName);
    GSymbol *globalEntry = lookupGST(tupleName);
    Tuple *tupleType = NULL;
    int binding;

    if (localEntry) {
        tupleType = localEntry->tupleEntry;
        binding = localEntry->binding;
    } else if (globalEntry) {
        tupleType = globalEntry->tupleEntry;
        binding = globalEntry->binding;
    } else {
        compilerError(E_VARIABLE_USED_BEFORE_DECLARATION, tupleName);
    }

    int offsetOfField = getOffsetOfTupleField(tupleType, fieldName);

    int freeReg = getFreeRegister();
    int freeReg2 = getFreeRegister();
    if (localEntry) {
        fprintf(target_file, "MOV R%d, BP\n", freeReg);
        fprintf(target_file, "MOV R%d, [%d]\n", freeReg2, binding);
        fprintf(target_file, "ADD R%d, R%d\n", freeReg, freeReg2);
        fprintf(target_file, "ADD R%d, %d\n", freeReg, offsetOfField + 1);
        releaseRegister(freeReg2);
        return freeReg;
    } else if (globalEntry) {
        fprintf(target_file, "MOV R%d, [%d]\n", freeReg, binding);
        fprintf(target_file, "ADD R%d, %d\n", freeReg, offsetOfField);
        return freeReg;
    }

    return __NONE__;
}

int generateTupleAccessCode(struct tnode *root) {
    int tupleMemAddrReg = generateGetTupleMemoryAddrCode(root);

    int freeReg = getFreeRegister();
    fprintf(target_file, "MOV R%d, [R%d]\n", freeReg, tupleMemAddrReg);
    releaseRegister(tupleMemAddrReg);

    return freeReg;
}

int generateTuplePointerAccessCode(struct tnode *root) {
    int tupleMemAddrReg = generateGetTuplePointerMemoryAddrCode(root);

    int freeReg = getFreeRegister();
    fprintf(target_file, "MOV R%d, [R%d]\n", freeReg, tupleMemAddrReg);
    releaseRegister(tupleMemAddrReg);

    return freeReg;
}

void generateTupleAssignCode(struct tnode *node) {
    struct tnode *tupleAccessNode = node->left;
    struct tnode *exprNode = node->right;

    int memAddrReg = generateGetTupleMemoryAddrCode(tupleAccessNode);
    int exprReg = generateUserCode(exprNode);

    if (memAddrReg == __NONE__) {
        printf("Some error\n");
    } else {
        fprintf(target_file, "MOV [R%d], R%d\n", memAddrReg, exprReg);
    }

    releaseRegister(memAddrReg);
    releaseRegister(exprReg);
}

void generateTuplePointerAssignCode(struct tnode *node) {
    struct tnode *tupleAccessNode = node->left;
    struct tnode *exprNode = node->right;

    int memAddrReg = generateGetTuplePointerMemoryAddrCode(tupleAccessNode);
    int exprReg = generateUserCode(exprNode);

    if (memAddrReg == __NONE__) {
        printf("Some error\n");
    } else {
        fprintf(target_file, "MOV [R%d], R%d\n", memAddrReg, exprReg);
    }

    releaseRegister(memAddrReg);
    releaseRegister(exprReg);
}

int generateUserCode(struct tnode *root) {
    if (!root)
        return NO_RETURN;

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

    case NODE_DEREFERENCE:
        return generateDereferenceCode(root);

    case NODE_ASSIGN_TO_DEREFERENCED:
        generateAssignToDereferencedCode(root);
        return NO_RETURN;

    case NODE_ADDRESS_TO:
        return generateAddressToCode(root);

    case NODE_READ:
        int varMemAddrReg = getAddressOfVariable(root->left);
        generateReadFromConsoleCode(varMemAddrReg);
        return NO_RETURN;

    case NODE_READ_TO_ARRAY:
        int memAddrReg = generateArrayElementAddress(root->left);
        generateReadFromConsoleCodeToAddrInReg(memAddrReg);
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
        return NO_RETURN;

    case NODE_DEC:
        generateDecrementCode(root);
        return NO_RETURN;

    case NODE_BREAK_POINT:
        fprintf(target_file, "BRKP\n");
        return __NONE__;

    case NODE_FUNC_CALL:
        return generateFunctionCallCode(root);

    case NODE_RETURN:
        generateFunctionReturnCode(root);
        return __NONE__;

    case NODE_TUPLE_ACCESS:
        return generateTupleAccessCode(root);

    case NODE_TUPLE_ASSIGN:
        generateTupleAssignCode(root);
        return __NONE__;

    case NODE_TUPLE_POINTER_ACCESS:
        return generateTuplePointerAccessCode(root);

    case NODE_TUPLE_POINTER_ASSIGN:
        generateTuplePointerAssignCode(root);
        return __NONE__;

    default:
        printf("Unhandled node came while generating code: ");
        printNode(root);
        return __NONE__;
    }

    return NO_RETURN;
}

void generateCode(tnode *root) {
    initializeRegisters();

    generateHeader();
    generateUserCode(root);
    generateExitCode();
}

void generateHeader() {
    fprintf(target_file, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", 0, 2056, 0, 0, 0, 0, 0, 0);
    fprintf(target_file, "MOV SP, %d\n", stackTop);
    fprintf(target_file, "MOV BP, SP\n");
    fprintf(target_file, "BRKP\n");
}

void generateFunctionHeader(int label) {
    fprintf(target_file, "F%d:\n", label);
}

void generateMainCode(struct tnode *root) {
    initializeRegisters();

    fprintf(target_file, "MAIN:\n");
    fprintf(target_file, "PUSH BP\n");
    fprintf(target_file, "MOV BP, SP\n");

    printf("adding %d to main\n", localBinding);
    fprintf(target_file, "ADD SP, %d\n", localBinding);

    generateUserCode(root);
    generateExitCode();
}

void generateFunctionCode(int functionLabel, struct tnode *root) {
    initializeRegisters();
    generateFunctionHeader(functionLabel);

    fprintf(target_file, "PUSH BP\n");
    fprintf(target_file, "MOV BP, SP\n");
    printf("adding %d\n", localBinding);
    fprintf(target_file, "ADD SP, %d\n", localBinding);
    generateUserCode(root);
    generateFunctionJumpBackCode();
}

void generateFunctionReturnCode(struct tnode *returnNode) {
    int returnReg = generateUserCode(returnNode->left);
    int freeReg = getFreeRegister();

    fprintf(target_file, "MOV R%d, BP\n", freeReg);
    fprintf(target_file, "SUB R%d, 2\n", freeReg);
    fprintf(target_file, "MOV [R%d], R%d\n", freeReg, returnReg);

    releaseRegister(returnReg);
    releaseRegister(freeReg);

    generateFunctionJumpBackCode();
}

void generateFunctionJumpBackCode() {
    int returnAddrReg = getFreeRegister();
    printf("subtracting %d\n", localBinding);
    fprintf(target_file, "SUB SP, %d\n", localBinding);
    fprintf(target_file, "POP BP\n");
    fprintf(target_file, "RET\n");

    releaseRegister(returnAddrReg);
}

int generateFunctionCallCode(struct tnode *node) {
    struct tnode *functionNameNode = node->left;
    struct tnode *argListNode = node->right;

    struct GSymbol *entry = lookupGST(functionNameNode->varName);
    if (!entry) {
        throwError(E_FUNCTION_USED_BEFORE_DECLARATION, functionNameNode->varName);
    }

    int numArgs = getNumOfParams(entry->paramList);
    int argRegs[numArgs];
    int index = 0;
    getArgRegs(argListNode, &index, argRegs);

    for (int i = 0; i < numArgs; i++) {
        printf("%d, ", argRegs[i]);
    }

    int returnReg = getFreeRegister();

    generateSaveMachineStatusCode();
    generatePushArgumentsToStackCode(numArgs, argRegs);

    for (int i = 0; i < numArgs; i++) {
        releaseRegister(argRegs[i]);
    }

    fprintf(target_file, "PUSH R%d\n", returnReg);
    fprintf(target_file, "CALL F%d\n", entry->functionLabel);
    returnReg = generateRegainMachineStatusCode(numArgs);

    return returnReg;
}

void generatePushArgumentsToStackCode(int numArgs, int argRegs[]) {
    for (int i = numArgs - 1; i >= 0; i--) {
        fprintf(target_file, "PUSH R%d\n", argRegs[i]);
    }
}

void generateSaveMachineStatusCode() {
    for (int i = 0; i < TOTAL_REGISTERS; i++) {
        fprintf(target_file, "PUSH R%d\n", i);
    }
}

void generatePopArgumentsFromStackCode(int numArgs) {
    int freeReg = getFreeRegister();
    for (int i = 0; i < numArgs; i++) {
        fprintf(target_file, "POP R%d\n", freeReg);
    }
    releaseRegister(freeReg);
}

int generateRegainMachineStatusCode(int numArgs) {
    int freeReg = getFreeRegister();
    int returnReg = getFreeRegister();

    fprintf(target_file, "POP R%d\n", returnReg);

    generatePopArgumentsFromStackCode(numArgs);

    for (int i = TOTAL_REGISTERS - 1; i >= 0; i--) {
        if (i == returnReg) {
            fprintf(target_file, "POP R%d\n", freeReg);
        } else {
            fprintf(target_file, "POP R%d\n", i);
        }
    }
    releaseRegister(freeReg);

    return returnReg;
}

void getArgRegs(struct tnode *argList, int *i, int argRegs[]) {
    if (!argList)
        return;

    switch (argList->nodeType) {
    case NODE_CONNECTOR:
        getArgRegs(argList->left, i, argRegs);
        getArgRegs(argList->right, i, argRegs);
        break;

    default:
        argRegs[*i] = generateUserCode(argList);
        (*i)++;
        break;
    }
}

int getAddressOfVariable(struct tnode *node) {
    LSymbol *localEntry = local_st_lookup(node->varName);
    int reg = getFreeRegister();

    if (!localEntry) {
        GSymbol *globalEntry = node->gSymbolTableEntry;
        if (!globalEntry) {
            printf("Failed to get Symbol Table Entry for \"%s\"", node->varName);
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
        fprintf(target_file, "ADD R%d, %d\n", reg, binding + 1);
    }

    return reg;
}