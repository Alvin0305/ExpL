#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "g_symbol_table.h"
#include "param_list.h"
#include "../util/util.h"
#include "../error_handler/error_handler.h"
#include "../type_table/type_table.h"
#include "../class_table/class_table.h"

// static methods

static struct Param *createParam(char *name, enum Type type, bool isPtr, struct TupleType *tupleType, struct TypeTable *typeTableEntry) {
    struct Param *param = (struct Param *) malloc(sizeof(struct Param));

    param->name = strdup(name);
    param->type = typeTableEntry->kind;
    param->isPtr = isPtr;
    param->tupleType = tupleType;
    param->typeTableEntry = typeTableEntry;
    param->next = NULL;

    return param;
}

// core methods

struct Param *addParam(struct GSymbol *GSymbolTableEntry, char *name, enum Type type, bool isPtr, struct TupleType *tupleType, struct TypeTable *typeTableEntry) {
    struct Param *alreadyExisting = lookupParam(GSymbolTableEntry, name);
    if (alreadyExisting) {
        compilerError(E_PARAMETER_DUPLICATION, GSymbolTableEntry->name, name);
    }
    
    struct Param *param = createParam(name, type, isPtr, tupleType, typeTableEntry);

    struct Param *head = GSymbolTableEntry->paramList;
    if (!head) {
        GSymbolTableEntry->paramList = param;
    } else {
        while (head->next) {
            head = head->next;
        }

        head->next = param;
    }

    return param;
}

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
        printf("- %s [%s] %s\n", head->name, dataTypeToString(head->type), booleanToString(head->isPtr));
        head = head->next;
    }
}

struct Param *createNewParam(struct TypeTable *type, struct ClassTable *_class, char *name, bool isPtr) {
    return createParam(name, type->kind, isPtr, NULL, type);
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
