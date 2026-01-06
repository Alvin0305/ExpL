#include "semantic_context.h"
#include "../class_table/class_table.h"
#include "../define/constants.h"
#include "../tuple_type_table/tuple_type_table.h"
#include "../type_table/type_table.h"
#include "../util/util.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TypeInfo *createTypeInfo(enum Type kind, struct TupleType *tupleType, struct TypeTable *type, struct ClassTable *_class) {
    struct TypeInfo *typeInfo = (struct TypeInfo *)malloc(sizeof(struct TypeInfo));

    if (kind == UNKNOWN) {
        kind = _class ? CLASS : type ? TYPE : NONE;
    }
    // printf("creating type: %s %p %p %p [%d]\n", dataTypeToString(kind), tupleType, type, _class, lineNumber);

    typeInfo->kind = kind;
    typeInfo->type = type;
    typeInfo->tupleType = tupleType;
    typeInfo->_class = _class;

    return typeInfo;
}

struct VarList *mergeVars(struct VarList *vars, struct VarList *var) {
    if (!vars) return var;
    if (!var) return vars;

    struct VarList *head = vars;
    while (head->next) {
        head = head->next;
    }

    head->next = var;
    return vars;
}

struct VarList *createVar(char *name, bool isPtr, bool isFunction, struct Param *params, struct Dimension *dimensions) {
    struct VarList *var = (struct VarList *)malloc(sizeof(struct VarList));

    var->name = strdup(name);
    var->isPtr = isPtr;
    var->isFunction = isFunction;
    var->params = params;
    var->dimensions = dimensions;
    var->next = NULL;

    return var;
}