#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../error_handler/error_handler.h"
#include "../g_symbol_table/g_symbol_table.h"
#include "../node/node.h"
#include "../type_table/type_table.h"
#include "../util/util.h"
#include "local_symbol_table.h"

static struct TupleType *currentTupleType = NULL;
static struct TypeTable *currentType = NULL;

static struct LSymbol *LSTHead = NULL;
static int paramCount = 0;

struct GSymbol *currentFunction = NULL;
int localBinding = 1;

// static helpers

static LSymbol *createLSTEntry(char *name, enum Type type, bool isParam, bool isPtr, struct TupleType *tupleType,
                               struct TypeTable *typeTableEntry) {
    struct LSymbol *entry = (struct LSymbol *)malloc(sizeof(struct LSymbol));

    if (isParam) {
        entry->binding = -(++paramCount + 2);
    } else {
        entry->binding = localBinding;
        if (type == TUPLE) {
            localBinding += tupleType->size;
        } else if (type == USER_TYPE) {
            localBinding += 1;
        } else {
            localBinding += getSizeOfDataType(type);
        }
    }

    entry->name = strdup(name);
    entry->type = type;
    entry->isPtr = isPtr;
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
    struct tnode *idNode;

    switch (declNode->nodeType) {
        case NODE_CONNECTOR:
        case NODE_LOCAL_DECL:
            populateLST(declNode->left);
            populateLST(declNode->right);
            break;

        case NODE_TYPE:
            currentTupleType = declNode->tupleType;
            currentType = declNode->typeTableEntry;
            break;

        case NODE_VARIABLE:
            if (currentType->kind == VOID) {
                compilerError(E_VARIABLE_WITH_TYPE_VOID, declNode->varName);
            }

            alreadyExisting = lookupLST(declNode->varName);
            if (alreadyExisting) {
                compilerError(E_VARIABLE_REDECLARATION, declNode->varName);
            }

            installLST(declNode->varName, currentType->kind, false, false, currentTupleType, currentType);
            break;

        case NODE_DEREFERENCE:
            idNode = declNode->left;
            if (currentType->kind == VOID) {
                compilerError(E_VARIABLE_WITH_TYPE_VOID, idNode->varName);
            }

            alreadyExisting = lookupLST(idNode->varName);
            if (alreadyExisting) {
                compilerError(E_VARIABLE_REDECLARATION, idNode->varName);
            }

            struct LSymbol *entry = installLST(idNode->varName, currentType->kind, false, true, currentTupleType, currentType);
            entry->isPtr = true;
            break;

        default:
            printf("[WARNING]: Unhandled node while populating LST: ");
            printNode(declNode);
            break;
    }
}

// core methods

struct LSymbol *installLST(char *name, enum Type type, bool isParam, bool isPtr, struct TupleType *tupleType,
                           struct TypeTable *typeTableEntry) {
    struct LSymbol *entry = createLSTEntry(name, type, isParam, isPtr, tupleType, typeTableEntry);
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
    currentTupleType = typeNode->tupleType;
    currentType = typeNode->typeTableEntry;

    populateLST(idListNode);
}

void addNewTupleTypeToLST(struct tnode *tupleTypeNameNode, struct tnode *tupleFieldListNode, struct tnode *idListNode) {
    char *tupleTypeName = tupleTypeNameNode->varName;

    struct TupleType *alreadyExisting = lookupTupleTypeTable(tupleTypeName);
    if (alreadyExisting) {
        compilerError(E_TUPLE_TYPE_REDECLARATION, tupleTypeName);
    }

    currentTupleType = createTupleTypeFromNode(tupleTypeName, tupleFieldListNode);

    createNewTypeForTuple(currentTupleType);
    currentType = lookupTT(currentTupleType->name);

    populateLST(idListNode);
}

void printLST() {
    printf("\n------[LOCAL SYMBOL TABLE]------\n");
    printf("[Name][DataType][Binding][isPtr]\n");

    struct LSymbol *head = LSTHead;
    while (head) {
        printf("%s %s %d (%s)\n", head->name, dataTypeToString(head->type), head->binding, booleanToString(head->isPtr));
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
    paramCount = 0;
    currentFunction = NULL;
    currentType = NULL;
    currentTupleType = NULL;
}
