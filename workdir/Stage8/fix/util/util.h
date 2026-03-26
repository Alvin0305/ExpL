#ifndef UTIL_H
#define UTIL_H

#include "../define/constants.h"
#include "../node/node.h"
#include <stdbool.h>

struct Dimension;
struct TypeInfo;

char *booleanToString(bool b);
char *dataTypeToString(enum Kind dataType);
char *opToString(int op);
void printNode(struct Node *node);

#endif