#ifndef CONSTANTS_H
#define CONSTANTS_H

#define NOT_CONSTANT 1000000

enum type {
    INT,
    STRING,
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
    NODE_ADD,
    NODE_SUB,
    NODE_MUL,
    NODE_DIV
};

#endif