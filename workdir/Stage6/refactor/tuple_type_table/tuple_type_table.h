#ifndef TUPLE_TYPE_H
#define TUPLE_TYPE_H

#include "../node/node.h"

typedef struct TupleType {
    char *name;
    int size;
    int numFields;
    struct TupleField *fields;
    struct TupleType *next;
} TupleType;

typedef struct TupleField {
    enum Type type;
    int size;
    char *name;
    struct TupleField *next;
} TupleField;

typedef struct TupleFieldInfo {
    enum Type type;
    char *name;
} TupleFieldInfo;

struct TupleType *lookupTupleTypeTable(char *name);
struct TupleType *installTupleType(char *name, struct TupleFieldInfo fields[], int n);
struct TupleField *getFieldOfTuple(struct TupleType *tuple, char *name);

struct TupleType *createTupleTypeFromNode(char *name, struct tnode *paramListNode);
int getOffsetOfTupleField(struct TupleType *tuple, char *fieldName);

void printTupleType(struct TupleType *tuple);

#endif