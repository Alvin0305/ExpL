#ifndef ARRAY_H
#define ARRAY_H

#include <stdio.h>

extern FILE *target_file;

// generate code for array assignment and access
int generateArrayAccessCode(struct Node *arrayAccessNode);
void generateAssignmentFromArray(struct Node *arrayAssignNode);
void generateAssignmentToArray(struct Node *arrayAssignNode);

// helper for getting the address of an element in an array
int generateArrayElementAddress(struct Node *arrayAccessNode);

#endif