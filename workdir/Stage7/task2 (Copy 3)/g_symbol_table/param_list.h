#ifndef PARAM_LIST_H
#define PARAM_LIST_H

struct TypeTable;
struct ClassTable;

#include <stdbool.h>

typedef struct Param {
    char *name;
    struct Param *next;

    struct TypeInfo *typeInfo;
    bool isPtr;
} Param;

typedef struct Arg {
    struct tnode *arg;
    struct Arg *next;
} Arg;

struct Param *lookupParam(struct GSymbol *GSymbolTableEntry, char *name);
int getNumOfParams(struct Param *paramList);

void printParamList(struct Param *head);

struct Param *createParam(struct TypeInfo *typeInfo, char *name, bool isPtr);
struct Param *mergeParams(struct Param *params1, struct Param *params2);

struct Arg *createArg(struct tnode *arg);
struct Arg *mergeArgs(struct Arg *args, struct Arg *arg);

#endif