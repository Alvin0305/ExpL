#include "../define/constants.h"
#include "../util/util.h"
#include "../node/node.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

extern int lineNumber;

void compilerError(int error, ...) {
    va_list ap;
    va_start(ap, error);

    char *functionName;
    char *variableName;
    char *expectedParamName;
    char *givenParamName;
    char *tupleTypeName;
    char *tupleName;
    char *fieldName;
    char *paramName;
    char *labelName;
    char *where;

    int expectedReturnType;
    int givenReturnType;
    int expectedType;
    int givenType;

    switch (error) {
        case E_ACCESS_NON_EXISTING_FIELD_OF_TUPLE: 
            tupleName = va_arg(ap, char *);
            fieldName = va_arg(ap, char *);
            fprintf(stderr, "[ERROR]: \"%s\" tuple does not have a field \"%s\"\n", tupleName, fieldName);
            break;
        

        case E_VARIABLE_USED_BEFORE_DECLARATION: 
            variableName = va_arg(ap, char *);
            fprintf(stderr, "[ERROR]: variable \"%s\" used before declaration {%d}\n", variableName, lineNumber);
            break;

        case E_INVALID_REGISTER: 
            fprintf(stderr, "[ERROR]: Invalid register is getting allocated. Check the code\n");
            break;

        case E_FUNCTION_SIGNATURE_MORE_ARG: 
            functionName = va_arg(ap, char *);
            fprintf(stderr, "[ERROR]: Function \"%s\" definition has more arguments than definition\n", functionName);
            break;

        case E_FUNCTION_SIGNATURE_TOO_FEW_ARG: 
            functionName = va_arg(ap, char *);
            fprintf(stderr, "[ERROR]: Function \"%s\" definition has less arguments than definition (%d)\n", 
                functionName, lineNumber
            );
            break;

        case E_FUNCTION_CALL_MORE_ARG: 
            functionName = va_arg(ap, char *);
            fprintf(stderr, "[ERROR]: Passed more arguments to function \"%s\" than expected\n", functionName);
            break;

        case E_FUNCTION_CALL_TOO_FEW_ARG: 
            functionName = va_arg(ap, char *);
            fprintf(stderr, "[ERROR]: Passed few arguments to function \"%s\" than expected\n", functionName);
            break;

        case E_NO_FREE_REGISTERS: 
            fprintf(stderr, "[ERROR]: Registers Exhausted\n");
            break;

        case E_VARIABLE_REDECLARATION: 
            variableName = va_arg(ap, char *);
            fprintf(stderr, "[ERROR]: Variable \"%s\" is redeclarared {%d}\n", variableName, lineNumber);
            break;

        case E_FUNCTION_USED_BEFORE_DECLARATION: 
            functionName = va_arg(ap, char *);
            fprintf(stderr, "[ERROR]: Function \"%s\" is used before declaration {%d}\n", functionName, lineNumber);
            break;

        case E_NO_SOURCE_FILE: 
            fprintf(stderr, "[ERROR]: No Source File given\n");
            break;

        case E_TUPLE_TYPE_REDECLARATION:
            tupleTypeName = va_arg(ap, char *);
            fprintf(stderr, "[ERROR]: Tuple type \"%s\" is redeclared\n", tupleTypeName);
            break;

        case E_FUNCTION_SIGNATURE_RETURN_TYPE_MISMATCH:
            functionName = va_arg(ap, char *);
            expectedReturnType = va_arg(ap, int);
            givenReturnType = va_arg(ap, int);
            fprintf(stderr, 
                "[ERROR]: Expected return type for function \"%s\" is %s, but got %s\n", 
                functionName, dataTypeToString(expectedReturnType), dataTypeToString(givenReturnType)
            );
            break;

        case E_FUNCTION_SIGNATURE_TYPE_MISMATCH:
            functionName = va_arg(ap, char *);
            paramName = va_arg(ap, char *);
            expectedType = va_arg(ap, int);
            givenType = va_arg(ap, int);
            fprintf(stderr, 
                "[ERROR]: Expected type for param \"%s\" in function \"%s\" is %s, but got %s\n",
                paramName, functionName, dataTypeToString(expectedType), dataTypeToString(givenType)
            );
            break;

        case E_FUNCTION_SIGNATURE_VARNAME_MISMATCH:
            functionName = va_arg(ap, char *);
            expectedParamName = va_arg(ap, char *);
            givenParamName = va_arg(ap, char *);
            fprintf(stderr, 
                "[ERROR]: Expected name for param in function \"%s\" is %s, but got %s\n",
                functionName, expectedParamName, givenParamName
            );
            break;

        case E_PARAMETER_DUPLICATION:
            functionName = va_arg(ap, char *);
            paramName = va_arg(ap, char *);
            fprintf(stderr, 
                "[ERROR]: Duplicate parameter \"%s\" given to function \"%s\"\n", 
                paramName, functionName
            );
            break;

        case E_LABEL_EXISTS:
            labelName = va_arg(ap, char *);
            fprintf(stderr, 
                "[ERROR]: Label name \"%s\" already exists\n",
                labelName
            );
            break;

        case E_FUNCTION_PASSED_ARG_MISMATCH:
            functionName = va_arg(ap, char *);
            paramName = va_arg(ap, char *);
            expectedType = va_arg(ap, int);
            givenType = va_arg(ap, int);
            fprintf(stderr,
                "[ERROR]: Expected type of argument \"%s\" for function \"%s\" is %s, but got %s\n",
                paramName, functionName, dataTypeToString(expectedType), dataTypeToString(givenType)
            );
            break;

        case E_DEREFERENCE_NON_POINTER_TUPLE:
            variableName = va_arg(ap, char *);
            fprintf(stderr, 
                "[ERROR]: Variable \"%s\" is not a pointer to dereference\n", 
                variableName
            );
            break;

        case E_POINTER_TO_POINTER:
            variableName = va_arg(ap, char *);
            fprintf(stderr,
                "[ERROR]: Variable \"%s\" is a pointer, a pointer to another pointer is not supported in ExpL\n", 
                variableName
            );
            break;

        case E_TUPLE_TYPE_USED_BEFORE_DECLARATION:
            tupleTypeName = va_arg(ap, char *);
            fprintf(stderr,
                "[ERROR]: Tuple type \"%s\" is not yet declared to use {%d}\n",
                tupleTypeName, lineNumber
            );
            break;

        case E_VARIABLE_WITH_TYPE_VOID:
            variableName = va_arg(ap, char *);
            fprintf(stderr, 
                "[ERROR]: Variable \"%s\" is assigned void type\n", 
                variableName
            );
            break;

        case E_TYPE_MISMATCH:
            where = va_arg(ap, char *);
            expectedType = va_arg(ap, int);
            givenType = va_arg(ap, int);
            fprintf(stderr,
                "[ERROR]: Expected %s type in %s, but got %s",
                dataTypeToString(expectedType), where, dataTypeToString(givenType)
            );
            break;

        case E_STACK_MEMORY_EXHAUSTED:
            fprintf(stderr, "Stack Memory Exhausted\n");
            break;

        default:
            printf("[ERROR]: Unhandled Error Occured: %d\n", error);
            break;
    }

    va_end(ap);
    exit(1);
}