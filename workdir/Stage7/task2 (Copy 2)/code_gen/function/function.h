#ifndef FUNCTION_H
#define FUNCTION_H

#include <stdio.h>
#include "../../node/node.h"

extern FILE *target_file;

// generate function code
void generateMainCode(struct tnode *root);
void generateFunctionCode(int functionLabel, struct tnode *root);
void generateFunctionReturnCode(struct tnode *root);
void generateFunctionJumpBackCode();
int generateFunctionCallCode(struct tnode *root);

void generateFunctionHeader(int label);
void saveMachineStatus();
void pushArgsToStack(struct tnode *argListNode);
void popArgsFromStack(int numArgs);
int regainMachineStatus(int numArgs);

#endif