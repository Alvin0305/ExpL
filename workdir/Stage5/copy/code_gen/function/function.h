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

// helpers for maintaining the stack while function call and return
void generatePushArgumentsToStackCode(int numArgs, int argRegs[]);
void generateSaveMachineStatusCode();
void generatePopArgumentsFromStackCode(int numArgs);
int generateRegainMachineStatusCode(int numArgs);

// helpers
void generateFunctionHeader(int label);
void getArgRegs(struct tnode *argListNode, int *i, int argRegs[]);

#endif