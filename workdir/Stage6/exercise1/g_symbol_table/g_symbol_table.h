#ifndef G_SYMBOL_TABLE_H
#define G_SYMBOL_TABLE_H

struct TypeTable;

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

    struct GSymbol *next;
} GSymbol;

extern int stackTop;

struct GSymbol *lookupGST(char *name);
struct GSymbol *installGST(char *name, enum Type type, int size, bool isPtr, struct TupleType *tupleType, struct TypeTable *typeTableEntry, int functionLabel, bool isArray);

void addToGST(struct tnode *typeNode, struct tnode *varListNode);
void addTupleTypeToGST(struct tnode *idNode, struct tnode *tupleFieldNode, struct tnode *idListNode);

bool checkFunctionSignature(struct tnode *functionSignatureNode);

// debug
void printGST();
void printDimensions(struct GSymbol *entry);

#endif