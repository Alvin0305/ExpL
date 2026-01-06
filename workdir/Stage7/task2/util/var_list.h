#ifndef VAR_LIST_H
#define VAR_LIST_H

struct Param;
struct Dimension;

#include <stdbool.h>

typedef struct VarList {
    char *name;
    bool isPtr;
    bool isFunction;
    struct Param *params;
    struct Dimension *dimensions;
    struct VarList *next;
} VarList;

struct VarList *mergeVars(struct VarList *vars, struct VarList *var);
struct VarList *createVar(char *name, bool isPtr, bool isFunction, struct Param *params, struct Dimension *dimensions);

#endif