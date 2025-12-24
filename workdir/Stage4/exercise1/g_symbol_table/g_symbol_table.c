#include "g_symbol_table.h"
#include "../define/constants.h"
#include "../error_handler/error_handler.h"
#include "../util/util.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int stackTop = STACK_START;
struct GSymbol *g_symbol_table_head;
int currentDataType = NONE;

struct GSymbol *lookupGST(char *name) {
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
    struct GSymbol *entry = (struct GSymbol *)malloc(sizeof(struct GSymbol));
    entry->name = (char *)malloc(strlen(name) + 1);

    strcpy(entry->name, name);
    entry->type = type;
    entry->size = size;
    entry->binding = stackTop;
    entry->next = NULL;
    entry->dimensions = NULL;
    entry->numDimensions = 0;

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
    printf("[VarName][DataType][Size][Binding][#Dim]:[Dimensions]\n");
    while (head) {
        printf("%s %s %d %d %d: ", head->name, dataTypeToString(head->type), head->size, head->binding, head->numDimensions);
        printDimensions(head);
        head = head->next;
    }

    printf("\n");
}

void printDimensions(struct GSymbol *entry) {
    for (int i = 0; i < entry->numDimensions; i++) {
        printf("%d,", entry->dimensions[i]);
    }
    printf("\n");
}

void populateGST(struct tnode *root) {
    if (!root)
        return;

    struct GSymbol *entry;
    switch (root->nodeType) {
    case NODE_CONNECTOR:
    case NODE_DECL:
        populateGST(root->left);
        populateGST(root->right);
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
        int dimensionCount = 0;
        entry = install(root->left->varName, currentDataType, getSizeOfArrayFromAST(root->right, &dimensionCount));

        entry->dimensions = (int *)malloc(dimensionCount * sizeof(int));
        addDimensionsOfArray(entry, root->right);

        root->gSymbolTableEntry = entry;
        root->type = entry->type;
        break;
    }
}

int getSizeOfArrayFromAST(struct tnode *dimensionDeclNode, int *dimensionCount) {
    return getDimensionProdFromAST(dimensionDeclNode, dimensionCount) * getSizeOfDataType(currentDataType);
}

int getDimensionProdFromAST(struct tnode *dimensionDeclNode, int *dimensionCount) {
    if (!dimensionDeclNode)
        return 1;

    if (dimensionDeclNode->nodeType == NODE_CONSTANT) {
        (*dimensionCount)++;
        return dimensionDeclNode->numVal;
    }

    return getDimensionProdFromAST(dimensionDeclNode->left, dimensionCount) *
           getDimensionProdFromAST(dimensionDeclNode->right, dimensionCount);
}

void addDimensionsOfArray(struct GSymbol *entry, struct tnode *dimensionDeclNode) {
    if (!dimensionDeclNode)
        return;

    if (dimensionDeclNode->nodeType == NODE_CONSTANT) {
        entry->dimensions[entry->numDimensions++] = dimensionDeclNode->numVal;
        return;
    }

    addDimensionsOfArray(entry, dimensionDeclNode->left);
    addDimensionsOfArray(entry, dimensionDeclNode->right);
}