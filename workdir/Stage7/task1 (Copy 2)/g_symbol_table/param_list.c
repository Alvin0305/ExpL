#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "g_symbol_table.h"
#include "param_list.h"
#include "../util/util.h"
#include "../error_handler/error_handler.h"
#include "../type_table/type_table.h"
#include "../class_table/class_table.h"
#include "../semantic_context/semantic_context.h"

// static methods

struct Param *createParam(struct TypeInfo *typeInfo, char *name, bool isPtr) {
    struct Param *param = (struct Param *) malloc(sizeof(struct Param));
    param->name = strdup(name);
    param->isPtr = isPtr;
    param->tupleType = typeInfo->tupleType;
    param->type = typeInfo->kind;
    param->_class = typeInfo->_class;
    param->typeTableEntry = typeInfo->type;

    return param;
}

// core methods

// struct Param *addParam(struct GSymbol *GSymbolTableEntry, char *name, enum Type type, bool isPtr, struct TupleType *tupleType, struct TypeTable *typeTableEntry) {
//     struct Param *alreadyExisting = lookupParam(GSymbolTableEntry, name);
//     if (alreadyExisting) {
//         compilerError(E_PARAMETER_DUPLICATION, GSymbolTableEntry->name, name);
//     }
    
//     struct Param *param = createParam(name, type, isPtr, tupleType, typeTableEntry);

//     struct Param *head = GSymbolTableEntry->paramList;
//     if (!head) {
//         GSymbolTableEntry->paramList = param;
//     } else {
//         while (head->next) {
//             head = head->next;
//         }

//         head->next = param;
//     }

//     return param;
// }

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
        if (head->tupleType) {
            printf("- %s [%s] %s\n", head->name, head->tupleType->name, booleanToString(head->isPtr));
        } else {
            printf("- %s [%s] %s\n", head->name, head->typeTableEntry->name, booleanToString(head->isPtr));
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
