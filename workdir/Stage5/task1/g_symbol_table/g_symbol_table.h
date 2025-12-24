#ifndef G_SYMBOL_TABLE_H
#define G_SYMBOL_TABLE_H

#include <stdbool.h>

#include "../define/constants.h"
#include "../node/node.h"
#include "param_list.h"

typedef struct GSymbol {
    char *name;
    int type;
    int size;
    int binding;

    int numDimensions;
    int *dimensions;

    bool isPtr;

    struct Param *paramList;
    int functionLabel;

    struct GSymbol *next;
} GSymbol;

extern struct GSymbol *g_symbol_table_head;
extern int stackTop;

struct GSymbol *lookupGST(char *name);
struct GSymbol *install(char *name, int type, int size, bool isPtr);

// printer
void printGSymbolTable();
void printDimensions(struct GSymbol *entry);

void populateGST(struct tnode *node);

// helper
int getSizeOfArrayFromAST(struct tnode *dimensionDeclNode, int *dimensionCount);
int getDimensionProdFromAST(struct tnode *dimensionDeclNode, int *dimensionCount);
void addParamsToFunction(struct GSymbol *entry, struct tnode *paramListNode);

// setting up dimensions of the array
void addDimensionsOfArray(struct GSymbol *entry, struct tnode *dimensionDeclNode);

#endif