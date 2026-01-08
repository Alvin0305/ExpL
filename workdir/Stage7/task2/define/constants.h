#ifndef CONSTANTS_H
#define CONSTANTS_H

#define NO_LABEL -200
#define __NONE__ -1

#define SOURCE_FILE "io/expl/error/test.expl"
#define INTERMEDIATE_FILE "io/intermediate.xsm"
#define TRANSLATED_FILE "io/translated.xsm"

#define LIBRARY_START 0
#define LIBRARY_END 1023
#define HEAP_START 1024
#define HEAP_END 2047
#define HEADER_START 2048
#define HEADER_END 2055
#define CODE_START 2056
#define CODE_END 4095
#define STACK_START 4096
#define STACK_END 5119

#define HEADER_SIZE 8
#define DYNAMIC_MEM_ALLOC_BLOCK_SIZE 8

#define TOTAL_REGISTERS 20

#define NULL_VALUE 0

#define SUCCESS 0
#define FAILURE -1

// error returns for labels
#define E_LABEL_EXISTS -3

#endif