#include "control_flow.h"
#include "../../node/node.h"
#include "../../define/constants.h"
#include "../../label/label_stack.h"
#include "../../register/register.h"
#include "../code_gen.h"
#include "../../label/label.h"

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
    int leftReg = generateCode(node->left);
    int rightReg = generateCode(node->right);

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
    generateCode(ifNode);
    generateJumpCode(restOfCodeLabel);

    generateLabelHeader(elseLabel);
    generateCode(elseNode);

    generateLabelHeader(restOfCodeLabel);
}

void generateIfCode(struct tnode *node) {
    int ifLabel = createNewLabel();
    int restOfCodeLabel = createNewLabel();

    struct tnode *conditionNode = node->left;
    struct tnode *ifNode = node->right;

    generateLogicalConditionCode(conditionNode, ifLabel, restOfCodeLabel);
    
    generateLabelHeader(ifLabel);
    generateCode(ifNode);

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
    generateCode(node->right);
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
    generateCode(node->left);
    generateJumpCode(loopConditionLabel);

    generateLabelHeader(restOfCodeLabel);
    popFromLabelStack();
}

void generateDoWhileCode(struct tnode *node) {
    generateCode(node->right);

    generateWhileLoopCode(node);
}
