#include "../define/constants.h"
#include "../node/node.h"
#include "../util/util.h"

#include "error_handler.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

extern int lineNumber;

void compilerError(enum Error error, ...) {
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
    char *where;
    char *typeName;

    int expectedReturnType;
    int givenReturnType;
    int expectedType;
    int givenType;
    int size;
    int leftType, rightType;

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
                    functionName, lineNumber);
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
            // return;
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
                    functionName, dataTypeToString(expectedReturnType), dataTypeToString(givenReturnType));
            break;

        case E_FUNCTION_SIGNATURE_TYPE_MISMATCH:
            functionName = va_arg(ap, char *);
            paramName = va_arg(ap, char *);
            expectedType = va_arg(ap, int);
            givenType = va_arg(ap, int);
            fprintf(stderr,
                    "[ERROR]: Expected type for param \"%s\" in function \"%s\" is %s, but got %s\n",
                    paramName, functionName, dataTypeToString(expectedType), dataTypeToString(givenType));
            break;

        case E_FUNCTION_SIGNATURE_VARNAME_MISMATCH:
            functionName = va_arg(ap, char *);
            expectedParamName = va_arg(ap, char *);
            givenParamName = va_arg(ap, char *);
            fprintf(stderr,
                    "[ERROR]: Expected name for param in function \"%s\" is %s, but got %s\n",
                    functionName, expectedParamName, givenParamName);
            break;

        case E_PARAMETER_DUPLICATION:
            functionName = va_arg(ap, char *);
            paramName = va_arg(ap, char *);
            fprintf(stderr,
                    "[ERROR]: Duplicate parameter \"%s\" given to function \"%s\"\n",
                    paramName, functionName);
            break;

        case E_FUNCTION_PASSED_ARG_MISMATCH:
            functionName = va_arg(ap, char *);
            paramName = va_arg(ap, char *);
            expectedType = va_arg(ap, int);
            givenType = va_arg(ap, int);
            fprintf(stderr,
                    "[ERROR]: Expected type of argument \"%s\" for function \"%s\" is %s, but got %s (%d)\n",
                    paramName, functionName, dataTypeToString(expectedType), dataTypeToString(givenType), lineNumber);
            break;

        case E_DEREFERENCE_NON_POINTER_TUPLE:
            variableName = va_arg(ap, char *);
            fprintf(stderr,
                    "[ERROR]: Variable \"%s\" is not a pointer to dereference\n",
                    variableName);
            break;

        case E_POINTER_TO_POINTER:
            variableName = va_arg(ap, char *);
            fprintf(stderr,
                    "[ERROR]: Variable \"%s\" is a pointer, a pointer to another pointer is not supported in ExpL\n",
                    variableName);
            break;

        case E_TUPLE_TYPE_USED_BEFORE_DECLARATION:
            tupleTypeName = va_arg(ap, char *);
            fprintf(stderr,
                    "[ERROR]: Tuple type \"%s\" is not yet declared to use {%d}\n",
                    tupleTypeName, lineNumber);
            break;

        case E_VARIABLE_WITH_TYPE_VOID:
            variableName = va_arg(ap, char *);
            fprintf(stderr,
                    "[ERROR]: Variable \"%s\" is assigned void type\n",
                    variableName);
            break;

        case E_TYPE_MISMATCH:
            where = va_arg(ap, char *);
            expectedType = va_arg(ap, int);
            givenType = va_arg(ap, int);
            fprintf(stderr,
                    "[ERROR]: Expected %s type in %s, but got %s",
                    dataTypeToString(expectedType), where, dataTypeToString(givenType));
            break;

        case E_STACK_MEMORY_EXHAUSTED:
            fprintf(stderr, "Stack Memory Exhausted\n");
            break;

        case E_USER_DEF_VAR_SIZE_OVERFLOW:
            size = va_arg(ap, int);
            fprintf(stderr,
                    "[ERROR]: Maximum size of user defined variable is %d, but got %d\n",
                    MAX_USER_DEF_VAR_SIZE, size);
            break;

        case E_USER_TYPE_REDECLARATION:
            typeName = va_arg(ap, char *);
            fprintf(stderr,
                    "[ERROR]: User defined type \"%s\" is redefined\n", typeName);
            break;

        case E_FIELD_TYPE_UNDEFINED:
            variableName = va_arg(ap, char *);
            fprintf(stderr,
                    "[ERROR]: Field \"%s\" in user defined type has a undefined type\n", variableName);
            break;

        case E_MEMBER_ACCESS_ON_NON_SUPPORTED_TYPE:
            variableName = va_arg(ap, char *);
            givenType = va_arg(ap, int);
            fprintf(stderr,
                    "[ERROR]: Accessing a member is supported in TUPLE and User Defined Typed. Used in %s having type %s\n",
                    variableName, dataTypeToString(givenType));
            break;

        case E_ACCESS_NON_EXISTING_FIELD_OF_TYPE:
            printf("error");
            break;

        case E_USER_TYPE_USED_BEFORE_DECLARATION:
            typeName = va_arg(ap, char *);
            fprintf(stderr,
                    "[ERROR]: User defined type \"%s\" is used before declaration\n", typeName);
            break;

        case E_INVALID_SIZE_FOR_USER_DEFINED_TYPE:
            typeName = va_arg(ap, char *);
            size = va_arg(ap, int);
            fprintf(stderr,
                    "[ERROR]: Size for user defined type \"%s\" should be between 1 and 8, but given %d\n",
                    typeName, size);
            break;

        case E_ASSIGN_TYPE_MISMATCH:
            leftType = va_arg(ap, int);
            rightType = va_arg(ap, int);
            fprintf(stderr,
                "[ERROR]: [%d] Assignment type mismatch, %s = %s is not allowed\n",
                lineNumber, dataTypeToString(leftType), dataTypeToString(rightType)
            );
            break;

        default:
            printf("[ERROR]: Unhandled Error Occured: %d\n", error);
            break;
    }

    va_end(ap);
    exit(1);
}