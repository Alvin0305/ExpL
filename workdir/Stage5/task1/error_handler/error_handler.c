#include "../define/constants.h"
#include "../util/util.h"
#include <stdlib.h>
#include <stdio.h>

extern int lineNumber;

void throwError(int error, void *arg1) {
    switch (error) {
        case E_VARIABLE_REDECLARATION:
            printf("[ERROR]: Variable \"%s\" redeclared\n", (char *) arg1);
            exit(1);
        case E_VARIABLE_USED_BEFORE_DECLARATION:
            printf("[ERROR]: Variable \"%s\" used before declaration\n", (char *) arg1);
            exit(1);
        case E_DEREFERENCING_NON_POINTER_VARIABLE:
            printf("[ERROR]: Variable \"%s\" is not a pointer but is dereferenced\n", (char *) arg1);
            exit(1);
        case E_POINTER_TO_POINTER:
            printf("[ERROR]: A pointer to another pointer variable \"%s\" is not allowed\n", (char *) arg1);
            exit(1);
        case E_STACK_MEMORY_EXHAUSTED:
            printf("[ERROR]: Stack Memory Exhausted\n");
            exit(1);
        case E_INVALID_ARGUMENT:
            printf("[ERROR]: Invalid %s argument\n", (char *) arg1);
            exit(1);
        case E_FUNCTION_REDECLARATION:
            printf("[ERROR]: Function %s is redeclared\n", (char *) arg1);
            exit(1);
        case E_FUNCTION_USED_BEFORE_DECLARATION:
            printf("[ERROR]: Function %s is used before declaration\n", (char *) arg1);
            exit(1);
        case E_FUNCTION_SIGNATURE_NUM_ARGS_MISMATCH:
            printf("[ERROR]: Function signature number of args mismatch\n");
            exit(1);
    }
}

void throwTypeMismatchError(char *location, int expectedType, int givenType) {
    printf("[ERROR]: [%d] Expected %s in %s. But got %s\n", lineNumber, dataTypeToString(expectedType), location, dataTypeToString(givenType));
    exit(1);
}

void throwFunctionSignatureMismatchError(int error, int expectedType, int givenType, char *expectedName, char *givenName) {
    switch (error) {
        case E_FUNCTION_SIGNATURE_TYPE_MISMATCH:
            printf("[ERROR]: Function Signature Mismatch, expected %s type for \"%s\", got %s\n", dataTypeToString(expectedType), expectedName, dataTypeToString(givenType));
            exit(1);
        case E_FUNCTION_SIGNATURE_VARNAME_MISMATCH:
            printf("[ERROR]: Function Signature Mismatch, expected variable name: \"%s\", got \"%s\"\n", expectedName, givenName);
            exit(1);
        case E_FUNCTION_SIGNATURE_RETURN_TYPE_MISMATCH:
            printf("[ERROR]: Function Signature Mismatch, expected return type: %s, got %s\n", dataTypeToString(expectedType), dataTypeToString(givenType));
            exit(1);
    }
}