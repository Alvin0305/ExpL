#ifndef CODE_GEN_H
#define CODE_GEN_H

#include "../node/node.h"
#include <stdio.h>

extern FILE *target_file;

// helpers
void generateWriteToMemoryCode(int reg, int varMemAddr);
int getAddressOfVariable(struct Node *node);

// loaders
int generateLoadConstantCode(int val);
int generateLoadStringLiteralCode(char *stringLiteral);
int loadNull();
int generateLoadVariableCode(struct Node *node);

// assignment
void generateAssignVariableCode(struct Node *node);

// core code generation methods
int generateCode(struct Node *root);
void generateHeader();

#endif