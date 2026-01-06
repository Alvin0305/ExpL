#ifndef LIBRARY_CODE_H
#define LIBRARY_CODE_H

#include <stdio.h>

struct Node;
extern FILE *target_file;

// read and write
void generateReadFromConsoleCode(int varMemAddrReg);
void generateWriteToConsoleCode(int reg);

// exit
void generateExitCode();

// dynamic memory allocation
int generateHeapInitializeCode(struct Node *initNode);
void generateAllocCode(struct Node *node);
void generateFreeCode(struct Node *root);

#endif