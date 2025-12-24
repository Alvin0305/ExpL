#ifndef PARAM_LIST_H
#define PARAM_LIST_H

#include <stdbool.h>

typedef struct Param {
    char *name;
    int type;
    struct Param *next;
    struct TupleType *tupleType;

    bool isPtr;
} Param;

struct Param *addParam(struct GSymbol *GSymbolTableEntry, char *name, int type, bool isPtr, struct TupleType *tupleType);
struct Param *lookupParam(struct GSymbol *GSymbolTableEntry, char *name);
int getNumOfParams(struct Param *paramList);

void printParamList(struct Param *head);

#endif