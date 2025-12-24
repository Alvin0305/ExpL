#ifndef TUPLE_H
#define TUPLE_H

#include <stdio.h>

extern FILE *target_file;

// generate code for tuples
int generateGetTupleMemoryAddrCode(struct tnode *tupleAccessNode);
int generateTupleAccessCode(struct tnode *root);
void generateTupleAssignCode(struct tnode *node);

// generate code for tuple pointers
int generateGetTuplePointerMemoryAddrCode(struct tnode *tuplePointerAccessNode);
int generateTuplePointerAccessCode(struct tnode *root);
void generateTuplePointerAssignCode(struct tnode *node);

#endif