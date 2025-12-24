#ifndef TUPLE_H
#define TUPLE_H

#include "../node/node.h"

typedef struct Tuple {
    char *name;
    int size;
    int n;
    struct TupleField *fields;
} Tuple;

typedef struct TupleField {
    int type;
    int size;
    char *name;
    struct TupleField *next;
} TupleField;

typedef struct TupleFieldInfo {
    int type;
    char *name;
} TupleFieldInfo;

extern int currentTupleFieldType;

struct Tuple *createTuple(char *name, struct TupleFieldInfo fields[], int n);
struct TupleField *getFieldOfTuple(struct Tuple *tuple, char *name);
struct Tuple *createTupleFromNode(char *name, struct tnode *paramListNode);
void printTuple(struct Tuple *tuple);
int getOffsetOfTupleField(struct Tuple *tuple, char *fieldName);

#endif