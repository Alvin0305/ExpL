#ifndef CODE_GEN_H
#define CODE_GEN_H

#include <stdio.h>
#include "../node/node.h"

extern FILE *target_file;

// read and write
void generateReadFromConsoleCode(int varMemAddr);
void generateWriteToConsoleCode(int reg);
void generateWriteToMemoryCode(int reg, int varMemAddr);

// loading and assigning variables and constants
int generateLoadConstantCode(int val);
int generateLoadStringLiteralCode(char *stringLiteral);
int generateLoadVariableCode(struct tnode *node);
int generateAssignVariableCode(struct tnode *node);

// core code generation methods
int generateCode(struct tnode *root);
void generateHeader();
void generateExitCode();

// helpers
int getAddressOfVariable(struct tnode *node);

#endif