#ifndef CODE_GEN_H
#define CODE_GEN_H

#include <stdio.h>
#include "../node/node.h"

extern FILE *target_file;

// arithmetic operations
int generateAddRegCode(int leftReg, int rightReg);
int generateSubtractRegCode(int leftReg, int rightReg);
int generateMultiplyRegCode(int leftReg, int rightReg);
int generateDivideRegCode(int leftReg, int rightReg);
int generateModuloRegCode(int leftReg, int rightReg);

// read and write
void generateReadFromConsoleCode(int varMemAddr);
void generateWriteToConsoleCode(int reg);
void generateWriteToMemoryCode(int reg, int varMemAddr);

// loading and assigning variables and constants
int generateLoadConstantCode(int val);
int generateLoadStringLiteralCode(char *stringLiteral);
int generateLoadVariableCode(struct tnode *node);
int generateAssignVariableCode(struct tnode *node);

// control flow
void generateConditionCode(struct tnode *node, int trueLabel, int falseLabel);
void generateLogicalConditionCode(struct tnode *node, int trueLabel, int falseLabel);
void generateWhileLoopCode(struct tnode *node);
void generateIfCode(struct tnode *node);
void generateIfElseCode(struct tnode *node);
void generateJumpOnZeroCode(int reg, int label);
void generateJumpOnNonZeroCode(int reg, int label);
void generateRepeatUntilCode(struct tnode *node);

// core code generation methods
void generateCode(struct tnode *root);
void generateHeader();
int generateCode(struct tnode *root);
void generateExitCode();

// helpers
int getAddressOfVariable(struct tnode *node);

#endif