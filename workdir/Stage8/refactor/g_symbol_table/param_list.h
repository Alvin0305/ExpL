#ifndef PARAM_LIST_H
#define PARAM_LIST_H

struct TypeTable;
struct ClassTable;
struct GSymbol;
struct TypeInfo;

#include <stdbool.h>

typedef struct Param {
    char *name;
    struct Param *next;

    struct TypeInfo *typeInfo;
    bool isPtr;
} Param;

typedef struct Arg {
    struct Node *arg;
    struct Arg *next;
} Arg;

struct Param *lookupParam(struct GSymbol *GSymbolTableEntry, char *name);
int getNumOfParams(struct Param *params);

void printParamList(struct Param *head);

struct Param *createParam(struct TypeInfo *typeInfo, char *name, bool isPtr);
struct Param *mergeParams(struct Param *params1, struct Param *params2);

int countNumArgs(struct Node *argListNode);
struct TypeInfo **getTypeInfoFromArgs(struct Node *argListNode, int *numArgs);
struct TypeInfo **getParamTypesFromParams(struct Param *params);

#endif