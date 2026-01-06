#ifndef LIBRARY_CODE_H
#define LIBRARY_CODE_H

#include <stdio.h>

struct tnode;
extern FILE *target_file;

// read and write
void generateReadFromConsoleCode(int varMemAddrReg);
void generateWriteToConsoleCode(int reg);

// exit
void generateExitCode();

// dynamic memory allocation
void generateHeapInitializeCode(struct tnode *initNode);
void generateAllocCode(struct tnode *node);
void generateFreeCode(struct tnode *root);

#endif