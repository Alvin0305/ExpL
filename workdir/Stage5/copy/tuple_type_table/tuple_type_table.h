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
extern TupleType *tupleTableHead;

struct TupleType *lookupTupleTypeTable(char *name);
struct TupleType *installTupleType(char *name, struct TupleFieldInfo fields[], int n);

struct TupleType *createTupleType(char *name, struct TupleFieldInfo fields[], int n);
struct TupleField *createTupleField(char *name, int type);

struct TupleField *getFieldOfTuple(struct TupleType *tuple, char *name);

struct TupleType *createTupleTypeFromNode(char *name, struct tnode *paramListNode);
void printTupleType(struct TupleType *tuple);
int getOffsetOfTupleField(struct TupleType *tuple, char *fieldName);

#endif