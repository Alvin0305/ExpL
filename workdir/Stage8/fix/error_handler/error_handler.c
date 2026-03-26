#include "../define/constants.h"
#include "../g_symbol_table/param_list.h"
#include "../node/node.h"
#include "../type_info/type_info.h"
#include "../type_table/type_table.h"
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
    char *className;
    char *methodName;

    int expectedReturnType;
    int givenReturnType;
    int expectedType;
    int givenType;
    int size;
    int leftType, rightType;
    int dimension;
    int numParams;

    struct TypeTable *leftT, *rightT;
    struct TypeInfo **paramTypes;

    fprintf(stderr, "[ERROR E%d] Line %d: ", error, lineNumber);

    switch (error) {
        case E_ACCESS_NON_EXISTING_FIELD_OF_TUPLE:
            tupleName = va_arg(ap, char *);
            fieldName = va_arg(ap, char *);
            fprintf(stderr, "\"%s\" tuple does not have a field \"%s\"\n", tupleName, fieldName);
            break;

        case E_VARIABLE_USED_BEFORE_DECLARATION:
            variableName = va_arg(ap, char *);
            fprintf(stderr, "variable \"%s\" used before declaration\n", variableName);
            break;

        case E_INVALID_REGISTER:
            fprintf(stderr, "Invalid register is getting allocated. Check the code\n");
            break;

        case E_FUNCTION_SIGNATURE_MORE_ARG:
            functionName = va_arg(ap, char *);
            fprintf(stderr, "Function \"%s\" definition has more arguments than definition\n", functionName);
            break;

        case E_FUNCTION_SIGNATURE_TOO_FEW_ARG:
            functionName = va_arg(ap, char *);
            fprintf(stderr, "Function \"%s\" definition has less arguments than definition\n", functionName);
            break;

        case E_FUNCTION_CALL_MORE_ARG:
            functionName = va_arg(ap, char *);
            fprintf(stderr, "Passed more arguments to function \"%s\" than expected\n", functionName);
            break;

        case E_FUNCTION_CALL_TOO_FEW_ARG:
            functionName = va_arg(ap, char *);
            fprintf(stderr, "Passed few arguments to function \"%s\" than expected\n", functionName);
            break;

        case E_NO_FREE_REGISTERS:
            fprintf(stderr, "Registers Exhausted\n");
            break;

        case E_VARIABLE_REDECLARATION:
            variableName = va_arg(ap, char *);
            fprintf(stderr, "Variable \"%s\" is redeclarared\n", variableName);
            break;

        case E_FUNCTION_USED_BEFORE_DECLARATION:
            functionName = va_arg(ap, char *);
            paramTypes = va_arg(ap, struct TypeInfo **);
            numParams = va_arg(ap, int);
            fprintf(stderr, "Function \"%s\" (", functionName);
            for (int i = 0; i < numParams; i++) {
                fprintf(stderr, "%s", dataTypeToString(paramTypes[i]->kind));
                if (i != numParams - 1) {
                    fprintf(stderr, ", ");
                }
            }
            fprintf(stderr, ") is used before declaration\n");
            break;

        case E_NO_SOURCE_FILE:
            fprintf(stderr, "No Source File given\n");
            break;

        case E_TUPLE_TYPE_REDECLARATION:
            tupleTypeName = va_arg(ap, char *);
            fprintf(stderr, "Tuple type \"%s\" is redeclared\n", tupleTypeName);
            break;

        case E_FUNCTION_SIGNATURE_RETURN_TYPE_MISMATCH:
            functionName = va_arg(ap, char *);
            expectedReturnType = va_arg(ap, int);
            givenReturnType = va_arg(ap, int);
            fprintf(stderr, "Expected return type for function \"%s\" is %s, but got %s\n", functionName,
                    dataTypeToString(expectedReturnType), dataTypeToString(givenReturnType));
            break;

        case E_FUNCTION_SIGNATURE_TYPE_MISMATCH:
            functionName = va_arg(ap, char *);
            paramName = va_arg(ap, char *);
            expectedType = va_arg(ap, int);
            givenType = va_arg(ap, int);
            fprintf(stderr, "Expected type for param \"%s\" in function \"%s\" is %s, but got %s\n", paramName, functionName,
                    dataTypeToString(expectedType), dataTypeToString(givenType));
            break;

        case E_FUNCTION_SIGNATURE_VARNAME_MISMATCH:
            functionName = va_arg(ap, char *);
            expectedParamName = va_arg(ap, char *);
            givenParamName = va_arg(ap, char *);
            fprintf(stderr, "Expected name for param in function \"%s\" is %s, but got %s\n", functionName, expectedParamName,
                    givenParamName);
            break;

        case E_PARAMETER_DUPLICATION:
            functionName = va_arg(ap, char *);
            paramName = va_arg(ap, char *);
            fprintf(stderr, "Duplicate parameter \"%s\" given to function \"%s\"\n", paramName, functionName);
            break;

        case E_FUNCTION_REDECLARATION:
            functionName = va_arg(ap, char *);
            fprintf(stderr, "Function \"%s\" is redeclarated\n", functionName);
            break;

        case E_FUNCTION_RETURN_TYPE_MISMATCH:
            functionName = va_arg(ap, char *);
            expectedType = va_arg(ap, int);
            givenType = va_arg(ap, int);
            fprintf(stderr, "Expected return type of function \"%s\" is %s, but got %s\n", functionName,
                    dataTypeToString(expectedType), dataTypeToString(givenType));
            break;

        case E_FUNCTION_PASSED_ARG_MISMATCH:
            functionName = va_arg(ap, char *);
            paramName = va_arg(ap, char *);
            expectedType = va_arg(ap, int);
            givenType = va_arg(ap, int);
            fprintf(stderr, "Expected type of argument \"%s\" for function \"%s\" is %s, but got %s\n", paramName, functionName,
                    dataTypeToString(expectedType), dataTypeToString(givenType));
            break;

        case E_DEREFERENCING_NON_POINTER_VARIABLE:
            variableName = va_arg(ap, char *);
            fprintf(stderr, "Variable \"%s\" is not a pointer to dereference\n", variableName);
            break;

        case E_DEREFERENCE_NON_POINTER_TUPLE:
            variableName = va_arg(ap, char *);
            fprintf(stderr, "Variable \"%s\" is not a pointer tuple to dereference\n", variableName);
            break;

        case E_POINTER_TO_POINTER:
            variableName = va_arg(ap, char *);
            fprintf(stderr, "Variable \"%s\" is a pointer, a pointer to another pointer is not supported in ExpL\n",
                    variableName);
            break;

        case E_TUPLE_TYPE_USED_BEFORE_DECLARATION:
            tupleTypeName = va_arg(ap, char *);
            fprintf(stderr, "Tuple type \"%s\" is not yet declared to use\n", tupleTypeName);
            break;

        case E_VARIABLE_WITH_TYPE_VOID:
            variableName = va_arg(ap, char *);
            fprintf(stderr, "Variable \"%s\" is assigned void type\n", variableName);
            break;

        case E_TYPE_MISMATCH:
            where = va_arg(ap, char *);
            expectedType = va_arg(ap, int);
            givenType = va_arg(ap, int);
            fprintf(stderr, "Expected %s type in %s, but got %s\n", dataTypeToString(expectedType), where,
                    dataTypeToString(givenType));
            break;

        case E_STACK_MEMORY_EXHAUSTED:
            fprintf(stderr, "Stack Memory Exhausted\n");
            break;

        case E_INVALID_UDT_SIZE:
            fprintf(stderr, "Maximum size of user defined variable is %d\n", DYNAMIC_MEM_ALLOC_BLOCK_SIZE);
            break;

        case E_USER_TYPE_REDECLARATION:
            typeName = va_arg(ap, char *);
            fprintf(stderr, "User defined type \"%s\" is redefined\n", typeName);
            break;

        case E_FIELD_TYPE_UNDEFINED:
            variableName = va_arg(ap, char *);
            fprintf(stderr, "Field \"%s\" in user defined type has a undefined type\n", variableName);
            break;

        case E_ALLOC_ON_NON_UDT:
            variableName = va_arg(ap, char *);
            fprintf(stderr, "Alloc should be used only on UDTs, used on \"%s\"\n", variableName);
            break;

        case E_MEMBER_ACCESS_ON_NON_SUPPORTED_TYPE:
            variableName = va_arg(ap, char *);
            givenType = va_arg(ap, int);
            fprintf(stderr, "Accessing a member is supported in TUPLE and User Defined Typed. Used in %s having type %s\n",
                    variableName, dataTypeToString(givenType));
            break;

        case E_ACCESS_NON_EXISTING_FIELD_OF_TYPE:
            typeName = va_arg(ap, char *);
            fieldName = va_arg(ap, char *);
            fprintf(stderr, "Type \"%s\" has no field named \"%s\"\n", typeName, fieldName);
            break;

        case E_USER_TYPE_USED_BEFORE_DECLARATION:
            typeName = va_arg(ap, char *);
            fprintf(stderr, "User defined type \"%s\" is used before declaration\n", typeName);
            break;

        case E_INVALID_SIZE_FOR_ALLOCATION:
            typeName = va_arg(ap, char *);
            size = va_arg(ap, int);
            fprintf(stderr, "Size for allocation \"%s\" should be between 1 and 8, but given %d\n", typeName, size);
            break;

        case E_ASSIGN_TYPE_MISMATCH:
            leftType = va_arg(ap, int);
            rightType = va_arg(ap, int);
            fprintf(stderr, "Assignment type mismatch %s = %s is not allowed\n", dataTypeToString(leftType),
                    dataTypeToString(rightType));
            break;

        case E_ASSIGN_USER_TYPE_MISMATCH:
            leftT = va_arg(ap, struct TypeTable *);
            rightT = va_arg(ap, struct TypeTable *);
            fprintf(stderr, "Assignment type mismatch %s = %s is not allowed\n", leftT->name, rightT->name);
            break;

        case E_CLASS_USED_BEFORE_DECLARATION:
            className = va_arg(ap, char *);
            fprintf(stderr, "Class %s is used before it is declared\n", className);
            break;

        case E_INVALID_SIZE_FOR_CLASS:
            className = va_arg(ap, char *);
            fprintf(stderr, "Number of fields in a class \"%s\" should be between 0 and 8\n", className);
            break;

        case E_ACCESS_NON_EXISTING_FIELD_OF_CLASS:
            className = va_arg(ap, char *);
            fieldName = va_arg(ap, char *);
            fprintf(stderr, "Class \"%s\" has no field named \"%s\"\n", className, fieldName);
            break;

        case E_METHOD_CALLED_ON_NON_CLASS_VARIABLE:
            methodName = va_arg(ap, char *);
            fprintf(stderr, "Method \"%s\" is called on a non class variable\n", methodName);
            break;

        case E_CALL_NON_EXISTING_METHOD_OF_CLASS:
            className = va_arg(ap, char *);
            methodName = va_arg(ap, char *);
            fprintf(stderr, "Class \"%s\" has no method named \"%s\"\n", className, methodName);
            break;

        case E_INVALID_DIMENSION:
            dimension = va_arg(ap, int);
            fprintf(stderr, "Dimension value of \"%d\" is invalid\n", dimension);
            break;

        case E_UNDEFINED_TYPE:
            fprintf(stderr, "Use of undefine datatype\n");
            break;

        case E_USE_OF_NON_PRIMITIVE_TYPE_IN_TUPLE:
            typeName = va_arg(ap, char *);
            fprintf(stderr, "Tuple Type can contain only primitive type, got \"%s\"", typeName);
            break;

        case E_DUPLICATE_FIELD_IN_TUPLE:
            fieldName = va_arg(ap, char *);
            fprintf(stderr, "Tuple Type is having duplicate fields \"%s\"\n", fieldName);
            break;

        case E_CLASS_REDECLARATION:
            className = va_arg(ap, char *);
            fprintf(stderr, "Class \"%s\" is redeclared\n", className);
            break;

        default:
            printf("[ERROR]: Unhandled Error Occured: %d\n", error);
            break;
    }

    va_end(ap);
    exit(1);
}