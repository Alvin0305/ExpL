#ifndef USER_TYPE_H
#define USER_TYPE_H

#include <stdio.h>

extern FILE *target_file;

void findMemberAddr(int *currentMemAddrReg, struct Node *node, struct TypeInfo **activeType);
int generateUserTypeAccessCode(struct Node *root);
void generateUserTypeAssignmentCode(struct Node *root);

int generateClassFieldAccessCode(struct Node *root);
void generateClassFieldAssignmentCode(struct Node *root);
int generateClassMethodCallCode(struct Node *root);

#endif