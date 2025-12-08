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

// read and write
void generateReadFromConsoleCode(int varMemAddr);
void generateWriteToConsoleCode(int reg);
void generateWriteToMemoryCode(int reg, int varMemAddr);

// loading variables and constants
int generateLoadConstantCode(int val);
int generateLoadVariableCode(struct tnode *node);

int generateAssignVariableCode(struct tnode *node);

// core code generation methods
int generateCode(struct tnode *root);
int generateHeader();
int generateUserCode(struct tnode *root);
void generateExitCode();

// helpers
int getAddressOfVariable(struct tnode *node);

#endif