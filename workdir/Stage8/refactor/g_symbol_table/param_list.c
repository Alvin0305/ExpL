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

    return param;
}

// core methods

struct Param *lookupParam(struct GSymbol *GSymbolTableEntry, char *name) {
    struct Param *head = GSymbolTableEntry->params;

    while (head) {
        if (strcmp(name, head->name) == 0) {
            return head;
        }
        head = head->next;
    }

    return NULL;
}

int getNumOfParams(struct Param *params) {
    struct Param *head = params;
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
            compilerError(E_PARAMETER_DUPLICATION, "", head->name);
        }
        prev = head;
        head = head->next;
    }

    prev->next = param;
    return params;
}

int countNumArgs(struct Node *argListNode) {
    if (!argListNode) return 0;
    if (argListNode->nodeType != NODE_CONNECTOR) return 1;
    return countNumArgs(argListNode->left) + countNumArgs(argListNode->right);
}

static void populateTypeList(struct Node *argListNode, struct TypeInfo *types[], int *i) {
    if (!argListNode) return;
    if (argListNode->nodeType == NODE_CONNECTOR) {
        populateTypeList(argListNode->left, types, i);
        populateTypeList(argListNode->right, types, i);
    } else {
        types[(*i)++] = argListNode->typeInfo;
    }
}

struct TypeInfo **getTypeInfoFromArgs(struct Node *argListNode, int *numArgs) {
    if (!argListNode) {
        *numArgs = 0;
        return NULL;
    }

    int n = countNumArgs(argListNode);
    struct TypeInfo **types = malloc(sizeof(struct TypeInfo *) * n);

    int i = 0;
    populateTypeList(argListNode, types, &i);

    *numArgs = n;
    return types;
}

struct TypeInfo **getParamTypesFromParams(struct Param *params) {
    struct Param *param = params;
    int n = 0;
    while (param) {
        n++;
        param = param->next;
    }

    param = params;
    struct TypeInfo **types = malloc(sizeof(struct TypeInfo *) * n);

    for (int i = 0; i < n; i++) {
        types[i] = param->typeInfo;
        param = param->next;
    }

    return types;
}