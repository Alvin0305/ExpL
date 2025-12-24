#ifndef LOCAL_SYMBOL_TABLE_H
#define LOCAL_SYMBOL_TABLE_H

#include "../node/node.h"
#include <stdbool.h>

typedef struct LSymbol
{
    char *name;
    int type;
    int binding;

    // for pointers
    bool isPtr;

    // for tuples
    struct TupleType *tupleEntry;

    struct LSymbol *next;
} LSymbol;

extern struct LSymbol *local_symbol_table_head;
extern int currentLocalType;
extern int localBinding;
extern struct GSymbol *currentFunction;

struct LSymbol *local_st_install(char *name, int type, bool isParam, bool isPtr);
struct LSymbol *local_st_lookup(char *name);
struct LSymbol *local_st_tuple_install(char *name, struct TupleType *tupleEntry, bool isPtr, bool isParam);
void populateLocalSymbolTable(struct tnode *declListNode);
void populateTuplesToLST(struct tnode *idListNode, struct TupleType *tupleType);
void printLocalSymbolTable();
void freeLocalSymbolTable();

#endif