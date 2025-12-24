#ifndef LOCAL_SYMBOL_TABLE_H
#define LOCAL_SYMBOL_TABLE_H

#include "../node/node.h"
#include <stdbool.h>

typedef struct LSymbol {
    char *name;
    int type;
    int binding;
    struct LSymbol *next;
} LSymbol;

extern struct LSymbol *local_symbol_table_head;
extern int currentLocalType;
extern int localBinding;
extern struct GSymbol *currentFunction;

struct LSymbol *local_st_install(char *name, int type, bool isParam);
struct LSymbol *local_st_lookup(char *name);
void populateLocalSymbolTable(struct tnode *declListNode);
void printLocalSymbolTable();
void freeLocalSymbolTable();

#endif