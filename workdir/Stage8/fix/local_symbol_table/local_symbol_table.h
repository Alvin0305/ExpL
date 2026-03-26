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

struct LSymbol *lookupLST(char *name);

void installVarsToLST(struct TypeInfo *typeInfo, struct VarList *vars);
struct LSymbol *installToLST(struct TypeInfo *typeInfo, char *name, bool isPtr, bool isParam, struct Dimension *dimensions);

void printLST();
void freeLocalSymbolTable();

#endif