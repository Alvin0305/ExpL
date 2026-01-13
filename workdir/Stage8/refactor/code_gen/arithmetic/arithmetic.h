#ifndef ARITHMETIC_H
#define ARITHMETIC_H

#include "../../node/node.h"
#include <stdio.h>

extern FILE *target_file;

// generate code for arithmetic operations and return the calculated register
int generateAddRegCode(int leftReg, int rightReg);
int generateSubtractRegCode(int leftReg, int rightReg);
int generateMultiplyRegCode(int leftReg, int rightReg);
int generateDivideRegCode(int leftReg, int rightReg);
int generateModuloRegCode(int leftReg, int rightReg);

// generate code for ++ and --
void generateIncrementCode(struct Node *node);
void generateDecrementCode(struct Node *node);

#endif