#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "local_symbol_table.h"
#include "../g_symbol_table/g_symbol_table.h"
#include "../error_handler/error_handler.h"
#include "../util/util.h"
#include "../node/node.h"

int currentLocalType = NONE;
struct LSymbol *local_symbol_table_head = NULL;
struct GSymbol *currentFunction = NULL;
int localBinding = 1;
int paramCount = 0;

struct LSymbol *local_st_install(char *name, int type, bool isParam, bool isPtr) {
    struct LSymbol *entry = (struct LSymbol *) malloc(sizeof(struct LSymbol));
    
    entry->name = strdup(name);
    entry->type = type;
    if (isParam) {
        entry->binding = -(++paramCount + 2);
    } else {
        entry->binding = localBinding;
        localBinding += getSizeOfDataType(type);
    }
    entry->next = NULL;
    entry->isPtr = isPtr;

    if (!local_symbol_table_head) {
        local_symbol_table_head = entry;
        return entry;
    }
    
    struct LSymbol *head = local_symbol_table_head;

    while (head->next) {
        head = head->next;
    }

    head->next = entry;
    return entry;
}

struct LSymbol *local_st_tuple_install(char *name, struct TupleType *tupleEntry, bool isPtr, bool isParam) {
    struct LSymbol *entry = (struct LSymbol *) malloc(sizeof(struct LSymbol));
    
    entry->name = strdup(name);
    entry->isPtr = isPtr;
    entry->next = NULL;
    entry->tupleEntry = tupleEntry;
    entry->type = TUPLE;
    if (isParam) {
        entry->binding = -(++paramCount + 2);
    } else {
        entry->binding = localBinding;
        localBinding += tupleEntry->size;
    }

    if (!local_symbol_table_head) {
        local_symbol_table_head = entry;
        return entry;
    } else {
        struct LSymbol *head = local_symbol_table_head;

        while (head->next) {
            head = head->next;
        }

        head->next = entry;
        return entry;
    }
}

struct LSymbol *local_st_lookup(char *name) {
    struct LSymbol *head = local_symbol_table_head;

    while (head) {
        if (strcmp(name, head->name) == 0) {
            return head;
        }

        head = head->next;
    }

    return NULL;
}

void populateLocalSymbolTable(struct tnode *declNode) {
    if (!declNode) return;

    LSymbol *alreadyExisting;
    
    switch (declNode->nodeType) {
        case NODE_CONNECTOR:
        case NODE_LOCAL_DECL:
            populateLocalSymbolTable(declNode->left);
            populateLocalSymbolTable(declNode->right);
            break;

        case NODE_TYPE:
            currentLocalType = declNode->type;
            break;

        case NODE_VARIABLE:
            alreadyExisting = local_st_lookup(declNode->varName);
            if (alreadyExisting) {
                printLocalSymbolTable();
                throwError(E_VARIABLE_REDECLARATION, declNode->varName);
            }
            
            local_st_install(declNode->varName, currentLocalType, false, false);
            break;
        
        case NODE_DEREFERENCE: {
            struct tnode *idNode = declNode->left;
            
            alreadyExisting = local_st_lookup(idNode->varName);
            if (alreadyExisting) {
                throwError(E_VARIABLE_REDECLARATION, idNode->varName);
            }
            
            local_st_install(idNode->varName, currentLocalType, false, true);
            break;
        }
    }
}

void populateTuplesToLST(struct tnode *idListNode, struct TupleType *tupleType) {
    if (!idListNode) return;

    switch (idListNode->nodeType) {
        case NODE_CONNECTOR: {
            populateTuplesToLST(idListNode->left, tupleType);
            populateTuplesToLST(idListNode->right, tupleType);
            break;
        }

        case NODE_VARIABLE: {
            local_st_tuple_install(idListNode->varName, tupleType, false, false);
            break;
        }

        case NODE_DEREFERENCE: {
            struct tnode *idNode = idListNode->left;
            local_st_tuple_install(idNode->varName, tupleType, true, false);
            break;
        }

        default: {
            printf("[WARNING]: Unexpected Node while populating ids of tuple type to LST:");
            printNode(idListNode);
            break;
        }
    }
}

void printLocalSymbolTable() {
    printf("\n[LOCAL SYMBOL TABLE]\n");

    struct LSymbol *head = local_symbol_table_head;
    while (head) {
        printf("%s %s %d (%d)\n", head->name, dataTypeToString(head->type), head->binding, head->isPtr);
        if (head->type == TUPLE) {
            printTupleType(head->tupleEntry);
        }
        head = head->next;
    }
    printf("\n");
}

void freeLocalSymbolTable() {
    struct LSymbol *head = local_symbol_table_head;

    while (head) {
        struct LSymbol *temp = head;
        head = head->next;

        free(temp);
    }

    local_symbol_table_head = NULL;
    localBinding = 1;
    currentLocalType = NONE;
    paramCount = 0;
    currentFunction = NULL;
}