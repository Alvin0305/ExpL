#ifndef ARRAY_H
#define ARRAY_H

#include <stdio.h>

extern FILE *target_file;

// generate code for array assignment and access
int generateArrayAccessCode(struct tnode *arrayAccessNode);
void generateAssignmentFromArray(struct tnode *arrayAssignNode);
void generateAssignmentToArray(struct tnode *arrayAssignNode);

// helper
void collectArrayIndexRegisters(struct tnode *node, int *indexRegisters, int *count);
int generateArrayElementAddress(struct tnode *arrayAccessNode);

#endif