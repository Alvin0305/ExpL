#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../class_table/class_table.h"
#include "../error_handler/error_handler.h"
#include "../type_info/type_info.h"
#include "../type_table/type_table.h"
#include "../util/util.h"
#include "g_symbol_table.h"
#include "param_list.h"

struct Param *createParam(struct TypeInfo *typeInfo, char *name, bool isPtr) {
    struct Param *param = (struct Param *)malloc(sizeof(struct Param));
    param->name = strdup(name);
    param->isPtr = isPtr;
    param->typeInfo = typeInfo;
    printf("created param %s\n", name);

    return param;
}

// core methods

struct Param *lookupParam(struct GSymbol *GSymbolTableEntry, char *name) {
    struct Param *head = GSymbolTableEntry->paramList;

    while (head) {
        if (strcmp(name, head->name) == 0) {
            return head;
        }
        head = head->next;
    }

    return NULL;
}

int getNumOfParams(struct Param *paramList) {
    struct Param *head = paramList;
    int length = 0;

    while (head) {
        length++;
        head = head->next;
    }

    return length;
}

void printParamList(struct Param *head) {
    while (head) {
        if (head->typeInfo->kind == TUPLE) {
            printf("- %s [%s] %s\n", head->name, head->typeInfo->tupleType->name, booleanToString(head->isPtr));
        } else if (head->typeInfo->kind == CLASS) {
            printf("- %s [%s] %s\n", head->name, head->typeInfo->_class->name, booleanToString(head->isPtr));
        } else {
            printf("- %s [%s] %s\n", head->name, head->typeInfo->type->name, booleanToString(head->isPtr));
        }

        head = head->next;
    }
}

struct Param *mergeParams(struct Param *params, struct Param *param) {
    if (!params) return param;
    if (!param) return params;

    struct Param *prev = NULL;
    struct Param *head = params;
    while (head) {
        if (strcmp(head->name, param->name) == 0) {
            printf("error here\n");
            compilerError(E_PARAMETER_DUPLICATION, "", head->name);
        }
        prev = head;
        head = head->next;
    }

    prev->next = param;
    return params;
}