#ifndef POINTER_CODE_H
#define POINTER_CODE_H

#include <stdio.h>

extern FILE *target_file;

int generateAddressToCode(struct Node *addressToNode);
int generateDereferenceCode(struct Node *dereferenceNode);
void generateAssignToDereferencedCode(struct Node *assignNode);

#endif