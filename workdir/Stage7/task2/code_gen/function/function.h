#ifndef FUNCTION_H
#define FUNCTION_H

#include "../../node/node.h"
#include <stdio.h>

extern FILE *target_file;

// generate function code
void generateMainCode(struct Node *root);
void generateFunctionCode(int functionLabel, struct Node *root);
void generateFunctionReturnCode(struct Node *root);
void generateFunctionJumpBackCode();
int generateFunctionCallCode(struct Node *root);

void generateFunctionHeader(int label);
void saveMachineStatus();
void pushArgsToStack(struct Node *argListNode);
void popArgsFromStack(int numArgs);
int regainMachineStatus(int numArgs);

#endif