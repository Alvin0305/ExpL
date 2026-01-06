#ifndef USER_TYPE_H
#define USER_TYPE_H

#include <stdio.h>

extern FILE *target_file;

void findUserTypeFieldAddr(int *currentMemAddrReg, struct tnode *node, struct TypeTable **currentType);
int generateUserTypeAccessCode(struct tnode *root);
void generateUserTypeAssignmentCode(struct tnode *root);

#endif