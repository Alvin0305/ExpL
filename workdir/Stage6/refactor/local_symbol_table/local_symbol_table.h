#ifndef LOCAL_SYMBOL_TABLE_H
#define LOCAL_SYMBOL_TABLE_H

struct TypeTable;

#include "../node/node.h"
#include <stdbool.h>

typedef struct LSymbol {
    char *name;
    int type;
    int binding;

    // for pointers
    bool isPtr;

    // for tuples
    struct TupleType *tupleType;

    // for user defined types
    struct TypeTable *typeTableEntry;

    struct LSymbol *next;
} LSymbol;

extern int localBinding;
extern struct GSymbol *currentFunction;

struct LSymbol *installLST(char *name, enum Type type, bool isParam, bool isPtr, struct TupleType *tupleType,
                           struct TypeTable *typeTableEntry);
struct LSymbol *lookupLST(char *name);

void addToLST(struct tnode *typeNode, struct tnode *idListNode);
void addNewTupleTypeToLST(struct tnode *tupleTypeNameNode, struct tnode *tupleFieldListNode, struct tnode *idListNode);

void printLST();
void freeLocalSymbolTable();

#endif