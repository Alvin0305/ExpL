#ifndef PARAM_LIST_H
#define PARAM_LIST_H

struct TypeTable;

#include <stdbool.h>

typedef struct Param {
    char *name;
    int type;
    struct Param *next;

    // for tuple pointer params
    struct TupleType *tupleType;

    // for user defined type params
    struct TypeTable *typeTableEntry;

    bool isPtr;
} Param;

struct Param *addParam(struct GSymbol *GSymbolTableEntry, char *name, int type, bool isPtr,
                       struct TupleType *tupleType, struct TypeTable *typeTableEntry);
struct Param *lookupParam(struct GSymbol *GSymbolTableEntry, char *name);
int getNumOfParams(struct Param *paramList);

void printParamList(struct Param *head);

#endif