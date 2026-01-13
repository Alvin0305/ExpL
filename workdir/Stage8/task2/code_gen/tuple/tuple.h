#ifndef TUPLE_H
#define TUPLE_H

#include <stdio.h>

extern FILE *target_file;

// generate code for tuples
int generateGetTupleMemoryAddrCode(struct Node *tupleAccessNode);
int generateTupleAccessCode(struct Node *root);
void generateTupleAssignCode(struct Node *node);

// generate code for tuple pointers
int generateGetTuplePointerMemoryAddrCode(struct Node *tuplePointerAccessNode);
int generateTuplePointerAccessCode(struct Node *root);
void generateTuplePointerAssignCode(struct Node *node);

#endif