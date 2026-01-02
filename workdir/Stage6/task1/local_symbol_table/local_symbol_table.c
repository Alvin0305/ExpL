#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../error_handler/error_handler.h"
#include "../g_symbol_table/g_symbol_table.h"
#include "../node/node.h"
#include "../util/util.h"
#include "../type_table/type_table.h"
#include "local_symbol_table.h"

static int currentDataType = NONE;
static struct TupleType *currentTupleType = NULL;
static struct TypeTable *currentUserDefinedType = NULL;

static struct LSymbol *LSTHead = NULL;
static int paramCount = 0;

struct GSymbol *currentFunction = NULL;
int localBinding = 1;

// static helpers

static LSymbol *createLSTEntry(char *name, int type, bool isPtr, bool isParam, struct TupleType *tupleType, struct TypeTable *typeTableEntry) {
    struct LSymbol *entry = (struct LSymbol *)malloc(sizeof(struct LSymbol));

    if (isParam) {
        entry->binding = -(++paramCount + 2);
    } else {
        entry->binding = localBinding;
        if (type == TUPLE) {
            localBinding += tupleType->size;
        } else if (type == USER_TYPE) {
            
        } else {
            localBinding += getSizeOfDataType(type);
        }
    }

    entry->name = strdup(name);
    entry->type = type;
    entry->isPtr = typeTableEntry ? true : isPtr;
    entry->tupleType = tupleType;
    entry->typeTableEntry = typeTableEntry;
    entry->next = NULL;

    if (stackTop + localBinding >= STACK_END) {
        compilerError(E_STACK_MEMORY_EXHAUSTED);
    }

    return entry;
}

static void populateLST(struct tnode *declNode) {
    if (!declNode) return;

    LSymbol *alreadyExisting;

    switch (declNode->nodeType) {
        case NODE_CONNECTOR:
        case NODE_LOCAL_DECL:
            populateLST(declNode->left);
            populateLST(declNode->right);
            break;

        case NODE_TYPE:
            currentDataType = declNode->type;
            currentTupleType = declNode->tupleType;
            currentUserDefinedType = declNode->typeTableEntry;
            break;

        case NODE_VARIABLE:
            if (currentDataType == VOID) {
                compilerError(E_VARIABLE_WITH_TYPE_VOID, declNode->varName);
            }

            alreadyExisting = lookupLST(declNode->varName);
            if (alreadyExisting) {
                printLocalSymbolTable();
                compilerError(E_VARIABLE_REDECLARATION, declNode->varName);
            }

            installLST(declNode->varName, currentDataType, false, false, currentTupleType, currentUserDefinedType);
            break;

        case NODE_DEREFERENCE:
            {
                struct tnode *idNode = declNode->left;
                if (currentDataType == VOID) {
                    compilerError(E_VARIABLE_WITH_TYPE_VOID, idNode->varName);
                }

                alreadyExisting = lookupLST(idNode->varName);
                if (alreadyExisting) {
                    compilerError(E_VARIABLE_REDECLARATION, idNode->varName);
                }

                installLST(idNode->varName, currentDataType, false, true, currentTupleType, currentUserDefinedType);
                break;
            }
    }
}

// core methods

struct LSymbol *installLST(char *name, int type, bool isParam, bool isPtr, struct TupleType *tupleType, struct TypeTable *typeTableEntry) {
    struct LSymbol *entry = createLSTEntry(name, type, isPtr, isParam, tupleType, typeTableEntry);
    entry->typeTableEntry = typeTableEntry;

    if (!LSTHead) {
        LSTHead = entry;
        return entry;
    }

    struct LSymbol *head = LSTHead;

    while (head->next) {
        head = head->next;
    }

    head->next = entry;
    return entry;
}

struct LSymbol *lookupLST(char *name) {
    struct LSymbol *head = LSTHead;

    while (head) {
        if (strcmp(name, head->name) == 0) {
            return head;
        }

        head = head->next;
    }

    return NULL;
}

void addToLST(struct tnode *typeNode, struct tnode *idListNode) {
    currentDataType = typeNode->type;
    currentTupleType = typeNode->tupleType;
    currentUserDefinedType = typeNode->typeTableEntry;

    populateLST(idListNode);
}

void addTupleTypeToLST(struct tnode *tupleTypeNameNode, struct tnode *tupleFieldListNode, struct tnode *idListNode) {
    char *tupleTypeName = tupleTypeNameNode->varName;

    struct TupleType *alreadyExisting = lookupTupleTypeTable(tupleTypeName);
    if (alreadyExisting) {
        compilerError(E_TUPLE_TYPE_REDECLARATION, tupleTypeName);
    }

    struct TupleType *tupleType = createTupleTypeFromNode(tupleTypeName, tupleFieldListNode);
    currentDataType = TUPLE;
    currentTupleType = tupleType;

    populateLST(idListNode);
}

void printLocalSymbolTable() {
    printf("\n[LOCAL SYMBOL TABLE]\n");

    struct LSymbol *head = LSTHead;
    while (head) {
        printf("%s %s %d (%d)\n", head->name, dataTypeToString(head->type), head->binding, head->isPtr);
        if (head->type == TUPLE) {
            printTupleType(head->tupleType);
        }
        head = head->next;
    }
    printf("\n");
}

void freeLocalSymbolTable() {
    struct LSymbol *head = LSTHead;

    while (head) {
        struct LSymbol *temp = head;
        head = head->next;

        free(temp);
    }

    LSTHead = NULL;
    localBinding = 1;
    currentDataType = NONE;
    paramCount = 0;
    currentFunction = NULL;
    currentUserDefinedType = NULL;
    currentTupleType = NULL;
}
