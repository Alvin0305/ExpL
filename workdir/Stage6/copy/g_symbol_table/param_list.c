#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "g_symbol_table.h"
#include "param_list.h"
#include "../util/util.h"
#include "../error_handler/error_handler.h"

// static methods

static struct Param *createParam(char *name, int type, bool isPtr, struct TupleType *tupleType) {
    struct Param *param = (struct Param *) malloc(sizeof(struct Param));

    param->name = strdup(name);
    param->type = type;
    param->isPtr = isPtr;
    param->tupleType = tupleType;
    param->next = NULL;

    return param;
}

// core methods

struct Param *addParam(struct GSymbol *GSymbolTableEntry, char *name, int type, bool isPtr, struct TupleType *tupleType) {
    struct Param *alreadyExisting = lookupParam(GSymbolTableEntry, name);
    if (alreadyExisting) {
        compilerError(E_PARAMETER_DUPLICATION, GSymbolTableEntry->name, name);
    }
    
    struct Param *param = createParam(name, type, isPtr, tupleType);

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
        printf("[%s] %s (%d), ", dataTypeToString(head->type), head->name, head->isPtr);
        head = head->next;
    }
    printf("\n");
}
