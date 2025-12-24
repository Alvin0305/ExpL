#ifndef UTIL_H
#define UTIL_H

#include "../node/node.h"
#include <stdbool.h>

char *booleanToString(bool b);
char *dataTypeToString(int dataType);
char *opToString(int op);
int getSizeOfDataType(int dataType);
void printNode(struct tnode *node);

#endif