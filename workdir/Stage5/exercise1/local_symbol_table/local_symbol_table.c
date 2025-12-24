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
int localBinding = 0;
int paramCount = 0;

struct LSymbol *local_st_install(char *name, int type, bool isParam, bool isPtr) {
    printf("installing %s %s\n", name, dataTypeToString(type));
    struct LSymbol *entry = (struct LSymbol *) malloc(sizeof(struct LSymbol));
    entry->name = (char *) malloc(strlen(name) + 1);

    strcpy(entry->name, name);
    entry->type = type;
    if (isParam) {
        entry->binding = -(++paramCount + 1 + 1);
    } else {
        entry->binding = localBinding;
        localBinding += getSizeOfDataType(type);
    }
    entry->next = NULL;
    entry->isPtr = isPtr;

    printf("local binding is now: %d\n", localBinding);

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
            printf("got type: %s\n", dataTypeToString(declNode->type));
            currentLocalType = declNode->type;
            break;

        case NODE_VARIABLE:
            printf("Installing variable %s\n", declNode->varName);
            alreadyExisting = local_st_lookup(declNode->varName);
            if (alreadyExisting) {
                printLocalSymbolTable();
                throwError(E_VARIABLE_REDECLARATION, declNode->varName);
            }
            
            local_st_install(declNode->varName, currentLocalType, false, false);
            break;
        
        case NODE_DEREFERENCE:
            struct tnode *idNode = declNode->left;
            printf("Installing pointer %s\n", idNode->varName);
            
            alreadyExisting = local_st_lookup(idNode->varName);
            if (alreadyExisting) {
                throwError(E_VARIABLE_REDECLARATION, idNode->varName);
            }
            
            local_st_install(idNode->varName, currentLocalType, false, true);
            break;
    }
}

void printLocalSymbolTable() {
    printf("\n[LOCAL SYMBOL TABLE]\n");

    struct LSymbol *head = local_symbol_table_head;
    while (head) {
        printf("%s %s %d (%d)\n", head->name, dataTypeToString(head->type), head->binding, head->isPtr);
        head = head->next;
    }
    printf("\n");
}

void freeLocalSymbolTable() {
    printf("freeing\n");
    struct LSymbol *head = local_symbol_table_head;

    while (head) {
        struct LSymbol *temp = head;
        head = head->next;

        free(temp);
    }

    local_symbol_table_head = NULL;
    localBinding = 0;
    currentLocalType = NONE;
    paramCount = 0;
    currentFunction = NULL;
}