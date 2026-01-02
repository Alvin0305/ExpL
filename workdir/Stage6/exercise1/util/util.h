#ifndef UTIL_H
#define UTIL_H

#include "../node/node.h"
#include <stdbool.h>

bool isTypeCompatible(enum Type leftType, enum Type rightType);
char *booleanToString(bool b);
char *dataTypeToString(enum Type dataType);
char *opToString(int op);
int getSizeOfDataType(enum Type dataType);
void printNode(struct tnode *node);
int typeTableEntryToType(struct TypeTable *type);

#endif