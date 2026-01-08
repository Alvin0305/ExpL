#include "var_list.h"

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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