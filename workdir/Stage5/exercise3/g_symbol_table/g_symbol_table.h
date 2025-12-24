#ifndef G_SYMBOL_TABLE_H
#define G_SYMBOL_TABLE_H

#include <stdbool.h>

#include "../define/constants.h"
#include "../node/node.h"
#include "../tuple_type_table/tuple_type_table.h"
#include "param_list.h"

typedef struct GSymbol {
    char *name;
    int type;
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
    struct TupleType *tupleEntry;

    struct GSymbol *next;
} GSymbol;

extern struct GSymbol *g_symbol_table_head;
extern int stackTop;

struct GSymbol *lookupGST(char *name);
struct GSymbol *install(char *name, int type, int size, bool isPtr, struct TupleType *tupleType);

// printer
void printGSymbolTable();
void printDimensions(struct GSymbol *entry);

void populateGST(struct tnode *node);
void populateTuplesToGST(struct tnode *idList, struct TupleType *tupleType);

// helper
int getSizeOfArrayFromAST(struct tnode *dimensionDeclNode, int *dimensionCount);
int getDimensionProdFromAST(struct tnode *dimensionDeclNode, int *dimensionCount);
void addParamsToFunction(struct GSymbol *entry, struct tnode *paramListNode);
bool checkFunctionSignature(struct tnode *functionSignatureNode);
bool checkParamsForFunction(struct tnode *node, struct Param **param, char *functionName);

// setting up dimensions of the array
void addDimensionsOfArray(struct GSymbol *entry, struct tnode *dimensionDeclNode);

#endif