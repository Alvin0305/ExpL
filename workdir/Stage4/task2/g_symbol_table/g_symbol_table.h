#ifndef G_SYMBOL_TABLE_H
#define G_SYMBOL_TABLE_H

#include "../node/node.h"

typedef struct GSymbol {
    char *name;
    int type;
    int size;
    int binding;
    struct GSymbol *next;
} GSymbol;

extern struct GSymbol *g_symbol_table_head;
extern int stackTop;

struct GSymbol *lookupGST(char *name);
struct GSymbol *install(char *name, int type, int size);

void printGSymbolTable();
void populateGST(struct tnode *node);

// helper
int getSizeOfArrayFromAST(struct tnode *arrayDeclNode);

#endif