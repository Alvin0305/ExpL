#ifndef G_SYMBOL_TABLE_H
#define G_SYMBOL_TABLE_H

struct TypeTable;
struct ClassTable;

#include <stdbool.h>

#include "../define/constants.h"
#include "../node/node.h"
#include "../tuple_type_table/tuple_type_table.h"
#include "param_list.h"

typedef struct GSymbol {
    char *name;
    enum Type type;
    int size;
    int binding;

    // for arrays
    int numDimensions;
    int *dimensions;

    // for pointers
    bool isPtr;

    // for functions
    struct Param *paramList;
    int functionLabel;

    // for tuples
    struct TupleType *tupleType;

    // for user defined types
    struct TypeTable *typeTableEntry;

    struct ClassTable *_class;

    struct GSymbol *next;
} GSymbol;

typedef struct Dimension {
    int value;
    struct Dimension *next;
} Dimension;

extern int stackTop;

struct GSymbol *lookupGST(char *name);

// debug
void printGST();
void printDimensions(struct GSymbol *entry);

struct Dimension *createDimension(int value);
struct Dimension *mergeDimensions(struct Dimension *dimensions, struct Dimension *dimension);
int getNumDimensions(struct Dimension *dim);
int getDimensionProduct(struct Dimension *dim);
int *convertDimToArray(struct Dimension *dim);

void checkFunctionSignature(struct TypeInfo *typeInfo, char *funcName, struct Param *givenParams);

struct GSymbol *installToGST(struct TypeInfo *typeInfo, char *name, bool isPtr, bool isFunction, struct Param *params, struct Dimension *dimensions);
void installVarsToGST(struct TypeInfo *typeInfo, struct VarList *vars);

#endif