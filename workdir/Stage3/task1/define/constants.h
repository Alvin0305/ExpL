#ifndef CONSTANTS_H
#define CONSTANTS_H

#define NOT_CONSTANT 1000000
#define NO_RETURN -100

#define SOURCE_FILE "io/input.a"
#define OUTPUT_FILE "io/result.xsm"

#define STACK_START 4096
#define NUM_STATIC_VARS 26

#define regIndex int

#define TOTAL_REGISTERS 20

enum type {
    INT,
    STRING,
    BOOL,
    NONE
};

enum nodeTypes {
    NODE_EMPTY,
    NODE_ASSIGN,
    NODE_CONNECTOR,

    NODE_VARIABLE,
    NODE_CONSTANT,

    NODE_READ,
    NODE_WRITE,

    NODE_GT,
    NODE_GE,
    NODE_EQ,
    NODE_NE,
    NODE_LE,
    NODE_LT,
    
    NODE_WHILE,
    NODE_IF_ELSE,
    NODE_IF,

    NODE_ADD,
    NODE_SUB,
    NODE_MUL,
    NODE_DIV
};

#define SUCCESS 0
#define FAILURE -1

// error returns for read and write
#define NO_ALLOCATION -1
#define E_INVALID_FILE_DESCRIPTOR -1 
#define E_READ_ERROR -2

// error returns for labels
#define E_LABEL_EXISTS -3

#endif