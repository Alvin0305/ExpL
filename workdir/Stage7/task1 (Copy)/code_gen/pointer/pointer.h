#ifndef POINTER_CODE_H
#define POINTER_CODE_H

#include <stdio.h>

extern FILE *target_file;

int generateAddressToCode(struct tnode *addressToNode);
int generateDereferenceCode(struct tnode *dereferenceNode);
void generateAssignToDereferencedCode(struct tnode *assignNode);

#endif