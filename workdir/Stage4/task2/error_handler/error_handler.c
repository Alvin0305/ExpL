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
    }
}

void throwTypeMismatchError(char *location, int expectedType, int givenType) {
    printf("[ERROR]: [%d] Expected %s in %s. But got %s\n", lineNumber, dataTypeToString(expectedType), location, dataTypeToString(givenType));
    exit(1);
}