#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "g_symbol_table.h"
#include "param_list.h"
#include "../util/util.h"
#include "../error_handler/error_handler.h"

struct Param *addParam(struct GSymbol *GSymbolTableEntry, char *name, int type) {
    struct Param *alreadyExisting = lookupParam(GSymbolTableEntry, name);
    if (alreadyExisting) {
        throwError(E_PARAMETER_DUPLICATION, name);
    }
    
    struct Param *param = (struct Param *) malloc(sizeof(struct Param));
    param->name = (char *) malloc(strlen(name) + 1);

    strcpy(param->name, name);
    param->type = type;
    param->next = NULL;

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
        printf("[%s] %s, ", dataTypeToString(head->type), head->name);
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