#ifndef FUNCTION_H
#define FUNCTION_H

#include "../../node/node.h"
#include <stdio.h>

struct Param;

extern FILE *target_file;

// generate function code
void generateMainCode(struct Node *root);
void generateFunctionCode(int functionLabel, struct Node *root);
void generateFunctionReturnCode(struct Node *root);
void generateFunctionJumpBackCode();
int generateFunctionCallCode(struct Node *root);

void generateFunctionHeader(int label);
int saveMachineStatus();
void pushArgsToStack(struct Node *argListNode);
void popArgsFromStack(struct Param *params);
int regainMachineStatus(int registersPushed, struct Param *params, struct TypeInfo *returnType);

#endif