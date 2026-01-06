#include "g_symbol_table.h"
#include "../class_table/class_table.h"
#include "../define/constants.h"
#include "../error_handler/error_handler.h"
#include "../label/label.h"
#include "../semantic_context/semantic_context.h"
#include "../type_table/type_table.h"
#include "../util/util.h"
#include "param_list.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int stackTop = STACK_START;

static struct GSymbol *GSTHead;

// ------------------ core methods --------------------

struct GSymbol *lookupGST(char *name) {
    struct GSymbol *head = GSTHead;

    while (head) {
        if (strcmp(head->name, name) == 0) {
            return head;
        }
        head = head->next;
    }

    return NULL;
}

static struct GSymbol *createSymbolTableEntry(char *name, enum Type type, int size, bool isPtr, int functionLabel, bool isArray,
                                              struct TypeInfo *typeInfo) {
    struct GSymbol *entry = (struct GSymbol *)malloc(sizeof(struct GSymbol));

    entry->name = strdup(name);
    // entry->type = type;
    entry->size = functionLabel == NO_LABEL ? size : 0;
    entry->binding = stackTop;
    entry->next = NULL;
    entry->dimensions = NULL;
    entry->numDimensions = 0;
    entry->isPtr = isPtr;
    entry->functionLabel = functionLabel;

    entry->paramList = NULL;
    entry->typeInfo = typeInfo;

    if (functionLabel != NO_LABEL) {

    } else if (isArray) {
        stackTop += size;
    } else if (type == TYPE) {
        stackTop += 1;
    } else {
        stackTop += size;
    }

    if (stackTop >= STACK_END) {
        compilerError(E_STACK_MEMORY_EXHAUSTED);
    }

    return entry;
}

void printGS(struct GSymbol *symbol) {
    printf("%s %s %d %d %s\n", symbol->name, dataTypeToString(symbol->typeInfo->kind), symbol->size, symbol->binding,
           booleanToString(symbol->isPtr));
}

void installVarsToGST(struct TypeInfo *typeInfo, struct VarList *vars) {
    struct VarList *head = vars;
    while (head) {
        installToGST(typeInfo, head->name, head->isPtr, head->isFunction, head->params, head->dimensions);
        head = head->next;
    }
}

struct GSymbol *installToGST(struct TypeInfo *typeInfo, char *name, bool isPtr, bool isFunction, struct Param *params,
                             struct Dimension *dimensions) {
    enum Type activeKind = typeInfo->kind;
    struct ClassTable *_class = typeInfo->_class;
    struct TypeTable *type = typeInfo->type;
    struct TupleType *tupleType = typeInfo->tupleType;

    bool isArray = dimensions != NULL;
    int label = isFunction ? createNewLabel() : NO_LABEL;
    isPtr = isPtr || (type && type->kind == TYPE) || (_class);

    int size = calcSizeOfType(tupleType, type, _class, dimensions, isFunction);

    struct GSymbol *symbol = createSymbolTableEntry(name, activeKind, size, isPtr, label, isArray, typeInfo);
    if (isFunction) {
        symbol->paramList = params;
    }
    if (isArray) {
        symbol->numDimensions = getNumDimensions(dimensions);
        symbol->dimensions = convertDimToArray(dimensions);
    }

    // printf("installing: ");
    // printGS(symbol);

    struct GSymbol *head = GSTHead;
    if (!GSTHead) {
        GSTHead = symbol;
    } else {
        head = GSTHead;
        while (head->next)
            head = head->next;
        head->next = symbol;
    }

    return symbol;
}

struct Dimension *mergeDimensions(struct Dimension *dimensions, struct Dimension *dimension) {
    if (!dimensions) return dimension;
    if (!dimension) return dimensions;

    struct Dimension *head = dimensions;
    while (head->next) {
        head = head->next;
    }

    head->next = dimension;
    return dimensions;
}

struct Dimension *createDimension(int value) {
    if (value <= 0) {
        printf("[error]\n");
    }

    struct Dimension *dim = (struct Dimension *)malloc(sizeof(struct Dimension));
    dim->value = value;
    dim->next = NULL;

    return dim;
}

int *convertDimToArray(struct Dimension *dim) {
    int n = getNumDimensions(dim);
    int *array = (int *)malloc(sizeof(int) * n);
    int i = 0;

    while (dim) {
        array[i++] = dim->value;
        dim = dim->next;
    }

    return array;
}

int getNumDimensions(struct Dimension *dim) {
    int count = 0;
    while (dim) {
        count++;
        dim = dim->next;
    }

    return count;
}

int getDimensionProduct(struct Dimension *dim) {
    int result = 1;
    while (dim) {
        result *= dim->value;
        dim = dim->next;
    }

    return result;
}

void printGST() {
    struct GSymbol *head = GSTHead;
    printf("\n-------------[SYMBOL TABLE]--------------\n");
    printf("[VarName][DataType][Size][Binding][isPtr]\n");
    while (head) {
        if (head->typeInfo->kind == TUPLE) {
            printf("%s [%s] %d %d %s\n", head->name, head->typeInfo->tupleType->name, head->size, head->binding,
                   booleanToString(head->isPtr));
            printTupleType(head->typeInfo->tupleType);
        } else if (head->typeInfo->kind == CLASS) {
            printf("%s [%s] %d %d %s\n", head->name, head->typeInfo->_class->name, head->size, head->binding,
                   booleanToString(head->isPtr));
        } else {
            printf("%s [%s] %d %d %s\n", head->name, head->typeInfo->type->name, head->size, head->binding,
                   booleanToString(head->isPtr));
        }

        if (head->dimensions) {
            printf(" %d: ", head->numDimensions);
            printDimensions(head);
        }

        if (head->functionLabel != NO_LABEL) {
            printParamList(head->paramList);
        }
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

void checkParamsForFunction(struct Param *givenParams, struct Param *expectedParams, char *funcName) {
    struct Param *head1 = givenParams;
    struct Param *head2 = expectedParams;

    while (head1 && head2) {
        if (strcmp(head1->name, head2->name) != 0) {
            compilerError(E_FUNCTION_SIGNATURE_VARNAME_MISMATCH, funcName, head1->name, head2->name);
        } else if (!areTypeCompatible(head1->typeInfo, head2->typeInfo)) {
            compilerError(E_FUNCTION_SIGNATURE_TYPE_MISMATCH, funcName, head1->name, head1->typeInfo->kind,
                          head2->typeInfo->kind);
        }

        head1 = head1->next;
        head2 = head2->next;
    }

    if (head1) {
        compilerError(E_FUNCTION_SIGNATURE_MORE_ARG, funcName);
    } else if (head2) {
        compilerError(E_FUNCTION_SIGNATURE_TOO_FEW_ARG, funcName);
    }
}

void checkFunctionSignature(struct TypeInfo *typeInfo, char *funcName, struct Param *givenParams) {
    struct GSymbol *entry = lookupGST(funcName);
    printParamList(givenParams);
    printParamList(entry->paramList);

    if (!entry) {
        compilerError(E_FUNCTION_USED_BEFORE_DECLARATION, funcName);
    }

    if (!areTypeCompatible(typeInfo, entry->typeInfo)) {
        compilerError(E_FUNCTION_SIGNATURE_RETURN_TYPE_MISMATCH, funcName, entry->typeInfo->type, typeInfo->type);
    }

    struct Param *expectedParams = entry->paramList;
    checkParamsForFunction(givenParams, expectedParams, funcName);
}