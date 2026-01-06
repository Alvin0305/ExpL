#ifndef SEMANTIC_CONTEXT_H
#define SEMANTIC_CONTEXT_H

struct TupleType;
struct TypeTable;
struct ClassTable;
struct Param;
struct Dimension;

#include "../define/constants.h"
#include <stdbool.h>

typedef struct TypeInfo {
    enum Type kind;
    struct TypeTable *type;
    struct TupleType *tupleType;
    struct ClassTable *_class;
} TypeInfo;

typedef struct VarList {
    char *name;
    bool isPtr;
    bool isFunction;
    struct Param *params;
    struct Dimension *dimensions;
    struct VarList *next;
} VarList;

struct TypeInfo *createTypeInfo(enum Type kind, struct TupleType *tupleType, struct TypeTable *type, struct ClassTable *_class);

struct VarList *mergeVars(struct VarList *vars, struct VarList *var);
struct VarList *createVar(char *name, bool isPtr, bool isFunction, struct Param *params, struct Dimension *dimensions);

#endif