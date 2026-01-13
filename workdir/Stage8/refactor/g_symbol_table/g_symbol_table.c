#include "g_symbol_table.h"
#include "../class_table/class_table.h"
#include "../define/constants.h"
#include "../error_handler/error_handler.h"
#include "../label/label.h"
#include "../type_info/dimension.h"
#include "../type_info/type_info.h"
#include "../type_table/type_table.h"
#include "../util/util.h"
#include "../util/var_list.h"
#include "param_list.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int stackTop = STACK_START;

static struct GSymbol *GSTHead;

// ------------------ core methods --------------------

static bool areSameFunction(struct GSymbol *symbol, char *name, struct TypeInfo **paramTypes, int numParams) {
    if (strcmp(symbol->name, name) != 0) return false;

    struct Param *expectedParam = symbol->params;
    for (int i = 0; i < numParams; i++) {
        if (!expectedParam) {
            return false;
        }
        if (!isTypeCompatible(expectedParam->typeInfo, paramTypes[i])) {
            printf("%s is not having type %s\n", expectedParam->name, dataTypeToString(paramTypes[i]->kind));
            return false;
        }

        expectedParam = expectedParam->next;
    }

    printf("is same function\n");
    return true;
}

struct GSymbol *lookupGST(char *name, bool isFunction, struct TypeInfo **paramTypes, int numParams) {
    struct GSymbol *head = GSTHead;
    printf("looking for %s\n", name);

    while (head) {
        if (isFunction) {
            if (areSameFunction(head, name, paramTypes, numParams)) {
                printf("%s is function and got true\n", name);
                return head;
            } else {
                head = head->next;
                continue;
            }
        }

        if (strcmp(head->name, name) == 0) {
            return head;
        }
        head = head->next;
    }

    return NULL;
}

static struct GSymbol *createGS(char *name, struct TypeInfo *typeInfo, struct Dimension *dimensions, struct Param *params,
                                int functionLabel, bool isArray, bool isFunction, bool isPtr) {
    struct GSymbol *entry = (struct GSymbol *)malloc(sizeof(struct GSymbol));

    int size = sizeOfTypeOnStack(typeInfo, dimensions, isPtr, isFunction);

    entry->name = strdup(name);
    entry->size = size;
    entry->binding = stackTop;
    entry->next = NULL;
    entry->isPtr = isPtr;
    entry->functionLabel = functionLabel;

    entry->params = params;
    entry->typeInfo = typeInfo;

    if (isArray) {
        entry->numDimensions = getNumDimensions(dimensions);
        entry->dimensions = convertDimToArray(dimensions);
    }

    stackTop += size;

    if (stackTop >= STACK_END) {
        compilerError(E_STACK_MEMORY_EXHAUSTED);
    }

    return entry;
}

void populateGST(struct TypeInfo *typeInfo, struct VarList *vars) {
    struct VarList *head = vars;
    while (head) {
        installToGST(typeInfo, head->name, head->isPtr, head->isFunction, head->params, head->dimensions);
        head = head->next;
    }
}

static void checkGSTEntry(struct TypeInfo *typeInfo, char *name, bool isFunction, int numParams, struct TypeInfo *paramTypes[]) {
    struct GSymbol *alreadyExisting = lookupGST(name, isFunction, paramTypes, numParams);
    if (alreadyExisting) {
        compilerError(E_VARIABLE_REDECLARATION, name);
    }

    if (!isFunction && typeInfo->kind == VOID) {
        compilerError(E_VARIABLE_WITH_TYPE_VOID, name);
    }
}

struct GSymbol *installToGST(struct TypeInfo *typeInfo, char *name, bool isPtr, bool isFunction, struct Param *params,
                             struct Dimension *dimensions) {
    printGST();
    printf("installing %s %s\n", name, booleanToString(isFunction));

    checkGSTEntry(typeInfo, name, isFunction, getNumOfParams(params), getParamTypesFromParams(params));
    struct ClassTable *_class = typeInfo->_class;
    struct TypeTable *type = typeInfo->type;

    bool isArray = dimensions != NULL;
    int label = isFunction ? createNewLabel() : NO_LABEL;
    isPtr = isPtr || (type && type->kind == TYPE) || (_class);

    struct GSymbol *symbol = createGS(name, typeInfo, dimensions, params, label, isArray, isFunction, isPtr);

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
            printParamList(head->params);
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
        } else if (!isTypeCompatible(head1->typeInfo, head2->typeInfo)) {
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
    struct GSymbol *entry = lookupGST(funcName, true, getParamTypesFromParams(givenParams), getNumOfParams(givenParams));

    if (!entry) {
        compilerError(E_FUNCTION_USED_BEFORE_DECLARATION, funcName, getParamTypesFromParams(givenParams), getNumOfParams(givenParams));
    }

    if (!isTypeCompatible(typeInfo, entry->typeInfo)) {
        compilerError(E_FUNCTION_SIGNATURE_RETURN_TYPE_MISMATCH, funcName, entry->typeInfo->type, typeInfo->type);
    }

    struct Param *expectedParams = entry->params;
    checkParamsForFunction(givenParams, expectedParams, funcName);
}