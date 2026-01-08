#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../class_table/class_table.h"
#include "../error_handler/error_handler.h"
#include "../g_symbol_table/g_symbol_table.h"
#include "../node/node.h"
#include "../type_info/type_info.h"
#include "../type_table/type_table.h"
#include "../util/util.h"
#include "../util/var_list.h"
#include "local_symbol_table.h"

static struct TupleType *currentTupleType = NULL;
static struct TypeTable *currentType = NULL;

static struct LSymbol *LSTHead = NULL;
static int paramCount = 0;

struct GSymbol *currentFunction = NULL;
int localBinding = 1;

// static helpers

static LSymbol *createLSTEntry(char *name, struct TypeInfo *typeInfo, bool isParam, bool isPtr) {
    struct LSymbol *entry = (struct LSymbol *)malloc(sizeof(struct LSymbol));

    if (isParam) {
        entry->binding = -(++paramCount + 2);
    } else {
        entry->binding = localBinding;
        localBinding += sizeOfTypeOnStack(typeInfo, NULL, isPtr, false);
    }

    entry->name = strdup(name);
    entry->typeInfo = typeInfo;
    entry->isPtr = isPtr;
    entry->next = NULL;

    if (stackTop + localBinding >= STACK_END) {
        compilerError(E_STACK_MEMORY_EXHAUSTED);
    }

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

static void checkLSTEntry(struct TypeInfo *typeInfo, char *name, bool isParam) {
    struct LSymbol *alreadyExisting = lookupLST(name);
    if (alreadyExisting) {
        if (isParam) {
            compilerError(E_PARAMETER_DUPLICATION, name);
        } else {
            compilerError(E_VARIABLE_REDECLARATION, name);
        }
    }

    if (typeInfo->kind == VOID) {
        compilerError(E_VARIABLE_WITH_TYPE_VOID, name);
    }
}

struct LSymbol *installToLST(struct TypeInfo *typeInfo, char *name, bool isPtr, bool isParam, struct Dimension *dimensions) {
    checkLSTEntry(typeInfo, name, isParam);
    struct LSymbol *symbol = createLSTEntry(name, typeInfo, isParam, isPtr);

    if (!LSTHead) {
        LSTHead = symbol;
        return symbol;
    }

    struct LSymbol *head = LSTHead;

    while (head->next) {
        head = head->next;
    }

    head->next = symbol;
    return symbol;
}

void installVarsToLST(struct TypeInfo *typeInfo, struct VarList *vars) {
    struct VarList *head = vars;
    while (head) {
        installToLST(typeInfo, head->name, head->isPtr, false, NULL);
        head = head->next;
    }
}

void printLST() {
    printf("\n------[LOCAL SYMBOL TABLE]------\n");
    printf("[Name][DataType][Binding][isPtr]\n");

    struct LSymbol *head = LSTHead;
    while (head) {
        if (head->typeInfo->kind == TUPLE) {
            printf("%s [%s] %d (%s)\n", head->name, head->typeInfo->tupleType->name, head->binding, booleanToString(head->isPtr));
        } else if (head->typeInfo->kind == CLASS) {
            printf("%s [%s] %d (%s)\n", head->name, head->typeInfo->_class->name, head->binding, booleanToString(head->isPtr));
        } else {
            printf("%s [%s] %d (%s)\n", head->name, head->typeInfo->type->name, head->binding, booleanToString(head->isPtr));
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
