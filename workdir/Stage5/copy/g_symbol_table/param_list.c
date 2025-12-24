#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "g_symbol_table.h"
#include "param_list.h"
#include "../util/util.h"
#include "../error_handler/error_handler.h"

struct Param *addParam(struct GSymbol *GSymbolTableEntry, char *name, int type, bool isPtr, struct TupleType *tupleType) {
    struct Param *alreadyExisting = lookupParam(GSymbolTableEntry, name);
    if (alreadyExisting) {
        throwError(E_PARAMETER_DUPLICATION, name);
    }
    
    struct Param *param = (struct Param *) malloc(sizeof(struct Param));
    
    param->name = strdup(name);
    param->type = type;
    param->next = NULL;
    param->isPtr = isPtr;
    param->tupleType = tupleType;

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

void printParamList(struct Param *head) {
    while (head) {
        printf("[%s] %s (%d), ", dataTypeToString(head->type), head->name, head->isPtr);
        head = head->next;
    }
    printf("\n");
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

int getTotalSizeOfParams(struct Param *paramList) {
    struct Param *head = paramList;
    int size = 0;
    
    while (head) {
        size += getSizeOfDataType(head->type);
        head = head->next;
    }

    return size;
}