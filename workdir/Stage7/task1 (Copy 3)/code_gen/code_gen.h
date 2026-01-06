#ifndef CODE_GEN_H
#define CODE_GEN_H

#include <stdio.h>
#include "../node/node.h"

extern FILE *target_file;

// helpers
void generateWriteToMemoryCode(int reg, int varMemAddr);
int getAddressOfVariable(struct tnode *node);

// loaders
int generateLoadConstantCode(int val);
int generateLoadStringLiteralCode(char *stringLiteral);
int loadNull();
int generateLoadVariableCode(struct tnode *node);

// assignment
void generateAssignVariableCode(struct tnode *node);

// core code generation methods
int generateCode(struct tnode *root);
void generateHeader();

#endif