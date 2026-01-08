#ifndef LOCAL_SYMBOL_TABLE_H
#define LOCAL_SYMBOL_TABLE_H

struct TypeTable;
struct ClassTable;
struct Dimension;
struct TypeInfo;
struct VarList;

#include "../node/node.h"
#include <stdbool.h>

typedef struct LSymbol {
    char *name;
    int binding;

    // for pointers
    bool isPtr;

    struct TypeInfo *typeInfo;
    struct LSymbol *next;
} LSymbol;

extern int localBinding;
extern struct GSymbol *currentFunction;

// struct LSymbol *installLST(char *name, struct TypeInfo *typeInfo, bool isParam, bool isPtr);
struct LSymbol *lookupLST(char *name);

void addToLST(struct Node *typeNode, struct Node *idListNode);
void addNewTupleTypeToLST(struct Node *tupleTypeNameNode, struct Node *tupleFieldListNode, struct Node *idListNode);

void installVarsToLST(struct TypeInfo *typeInfo, struct VarList *vars);
struct LSymbol *installToLST(struct TypeInfo *typeInfo, char *name, bool isPtr, bool isParam, struct Dimension *dimensions);

void printLST();
void freeLocalSymbolTable();

#endif