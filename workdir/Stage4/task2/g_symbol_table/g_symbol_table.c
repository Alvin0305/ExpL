#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../define/constants.h"
#include "../error_handler/error_handler.h"
#include "../util/util.h"
#include "g_symbol_table.h"

int stackTop = STACK_START;
struct GSymbol *g_symbol_table_head;
int currentDataType = NONE;

struct GSymbol *lookup(char *name) {
    struct GSymbol *head = g_symbol_table_head;

    while (head) {
        if (strcmp(head->name, name) == 0) {
            return head;
        }
        head = head->next;
    }

    return NULL;
}

struct GSymbol *createSymbolTableEntry(char *name, int type, int size) {
    struct GSymbol *entry = (struct GSymbol *) malloc(sizeof(struct GSymbol));
    entry->name = (char *) malloc(strlen(name) + 1);

    strcpy(entry->name, name);
    entry->type = type;
    entry->size = size;
    entry->binding = stackTop;
    entry->next = NULL;

    stackTop += size;

    return entry;
}

struct GSymbol *install(char *name, int type, int size) {
    struct GSymbol *head = g_symbol_table_head;
    struct GSymbol *prev = NULL;

    if (!head) {
        g_symbol_table_head = createSymbolTableEntry(name, type, size);
        return g_symbol_table_head;
    }

    while (head) {
        if (strcmp(head->name, name) == 0) {
            throwError(E_VARIABLE_REDECLARATION, name);
        }

        prev = head;
        head = head->next;
    }

    prev->next = createSymbolTableEntry(name, type, size);
    return prev->next;
}

void printGSymbolTable() {
    struct GSymbol *head = g_symbol_table_head;
    printf("\n[SYMBOL TABLE]\n");

    while (head) {
        printf("%s %s %d %d\n", head->name, dataTypeToString(head->type), head->size, head->binding);
        head = head->next;
    }

    printf("\n");
}

void populateGSymbolTable(struct tnode *root) {
    if (!root) return;
    
    struct GSymbol *entry;
    switch (root->nodeType) {
        case NODE_CONNECTOR:
        case NODE_DECL:
            populateGSymbolTable(root->left);
            populateGSymbolTable(root->right);
            break;

        case NODE_TYPE:
            currentDataType = root->type;
            break;

        case NODE_VARIABLE:
            entry = install(root->varName, currentDataType, getSizeOfDataType(currentDataType));
            root->gSymbolTableEntry = entry;
            root->type = root->gSymbolTableEntry->type;
            break;

        case NODE_ARRAY_DECL:
            entry = install(root->left->varName, currentDataType, getSizeOfArrayFromAST(root));
            root->gSymbolTableEntry = entry;
            root->type = entry->type;
            break;
    }
}

int getSizeOfArrayFromAST(struct tnode *arrayDeclNode) {
    return arrayDeclNode->right->numVal * getSizeOfDataType(currentDataType);
}