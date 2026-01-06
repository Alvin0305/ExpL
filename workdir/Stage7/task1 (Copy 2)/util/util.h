#ifndef UTIL_H
#define UTIL_H

#include "../node/node.h"
#include "../define/constants.h"
#include <stdbool.h>

struct Dimension;

bool isTypeCompatible(enum Type leftType, enum Type rightType);
bool areTypeCompatible(struct TypeTable *leftType, struct TypeTable *rightType);

char *booleanToString(bool b);
char *dataTypeToString(enum Type dataType);
char *opToString(int op);
int getSizeOfDataType(enum Type dataType);
void printNode(struct tnode *node);
int typeTableEntryToType(struct TypeTable *type);

int calcSizeOfType(struct TupleType *tupleType, struct TypeTable *type, struct ClassTable *_class, struct Dimension *dimensions,
                   bool isFunction);

#endif