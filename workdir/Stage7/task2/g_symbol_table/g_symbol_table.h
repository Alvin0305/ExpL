#ifndef G_SYMBOL_TABLE_H
#define G_SYMBOL_TABLE_H

struct TypeTable;
struct ClassTable;
struct VarList;

#include <stdbool.h>

#include "../define/constants.h"
#include "../node/node.h"
#include "../tuple_type_table/tuple_type_table.h"
#include "param_list.h"

typedef struct GSymbol {
    char *name;
    int size;
    int binding;
    int numDimensions;
    int *dimensions;
    bool isPtr;
    struct Param *paramList;
    int functionLabel;
    struct TypeInfo *typeInfo;
    struct GSymbol *next;
} GSymbol;

extern int stackTop;

// core methods
struct GSymbol *lookupGST(char *name);
struct GSymbol *installToGST(struct TypeInfo *typeInfo, char *name, bool isPtr, bool isFunction, struct Param *params,
                             struct Dimension *dimensions);

// utilities
void populateGST(struct TypeInfo *typeInfo, struct VarList *vars);
void checkFunctionSignature(struct TypeInfo *typeInfo, char *funcName, struct Param *givenParams);

// debug
void printGST();

#endif