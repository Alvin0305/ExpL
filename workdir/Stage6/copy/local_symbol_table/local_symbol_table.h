#ifndef LOCAL_SYMBOL_TABLE_H
#define LOCAL_SYMBOL_TABLE_H

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

    struct LSymbol *next;
} LSymbol;

extern int localBinding;
extern struct GSymbol *currentFunction;

struct LSymbol *installLST(char *name, int type, bool isParam, bool isPtr, struct TupleType *tupleType);
struct LSymbol *lookupLST(char *name);

void addToLST(struct tnode *typeNode, struct tnode *idListNode);
void addTupleTypeToLST(struct tnode *tupleTypeNameNode, struct tnode *tupleFieldListNode, struct tnode *idListNode);

void printLocalSymbolTable();
void freeLocalSymbolTable();

#endif