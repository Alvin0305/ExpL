#ifndef PARAM_LIST_H
#define PARAM_LIST_H

struct TypeTable;
struct ClassTable;

#include <stdbool.h>

typedef struct Param {
    char *name;
    enum Type type;
    struct Param *next;

    // for tuple pointer params
    struct TupleType *tupleType;

    // for user defined type params
    struct TypeTable *typeTableEntry;

    bool isPtr;
} Param;

struct Param *addParam(struct GSymbol *GSymbolTableEntry, char *name, enum Type type, bool isPtr,
                       struct TupleType *tupleType, struct TypeTable *typeTableEntry);
struct Param *lookupParam(struct GSymbol *GSymbolTableEntry, char *name);
int getNumOfParams(struct Param *paramList);

void printParamList(struct Param *head);

struct Param *createNewParam(struct TypeTable *type, struct ClassTable *_class, char *name, bool isPtr);
struct Param *mergeParams(struct Param *params1, struct Param *params2);

#endif