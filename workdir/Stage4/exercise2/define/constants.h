#ifndef CONSTANTS_H
#define CONSTANTS_H

#define NOT_CONSTANT 1000000
#define NO_RETURN -100

#define SOURCE_FILE "io/array/sum_of_n_factorials.expl"
#define INTERMEDIATE_FILE "io/intermediate.xsm"
#define TRANSLATED_FILE "io/translated.xsm"

#define STACK_START 4096
#define CODE_START 2056
#define NUM_STATIC_VARS 26
#define HEADER_SIZE 8

#define regIndex int

#define TOTAL_REGISTERS 20

enum sizes
{
    INT_SIZE = 4,
    STRING_SIZE = 6,
    NONE_SIZE = 0
};

enum type
{
    INT,
    STRING,
    BOOL,
    NONE
};

enum nodeTypes
{
    NODE_EMPTY,
    NODE_ASSIGN,
    NODE_CONNECTOR,

    NODE_VARIABLE,
    NODE_CONSTANT,
    NODE_STRING_LITERAL,

    NODE_TYPE,
    NODE_DECL,

    NODE_ARRAY_DECL,
    NODE_ARRAY_ASSIGN,
    NODE_ARRAY_ACCESS,

    NODE_DEREFERENCE,
    NODE_ADDRESS_TO,
    NODE_ASSIGN_TO_DEREFERENCED,

    NODE_READ,
    NODE_READ_TO_ARRAY,
    NODE_WRITE,

    NODE_GT,
    NODE_GE,
    NODE_EQ,
    NODE_NE,
    NODE_LE,
    NODE_LT,

    NODE_WHILE,
    NODE_BREAK,
    NODE_CONTINUE,
    NODE_REPEAT_UNTIL,
    NODE_DO_WHILE,

    NODE_IF_ELSE,
    NODE_IF,

    NODE_ADD,
    NODE_SUB,
    NODE_MUL,
    NODE_DIV,
    NODE_MOD
};

#define SUCCESS 0
#define FAILURE -1

// errors
enum errors
{
    E_VARIABLE_REDECLARATION,
    E_VARIABLE_USED_BEFORE_DECLARATION,
    E_DEREFERENCING_NON_POINTER_VARIABLE,
    E_POINTER_TO_POINTER
};

// error returns for labels
#define E_LABEL_EXISTS -3

#endif