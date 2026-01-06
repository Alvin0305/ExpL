#ifndef TUPLE_TYPE_H
#define TUPLE_TYPE_H

#include "../node/node.h"
#include "../semantic_context/semantic_context.h"

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

struct TupleField *createTupleField(struct TypeInfo *type, char *name);
struct TupleField *mergeTupleFields(struct TupleField *fields, struct TupleField *field);

struct TupleType *createNewTupleType(char *name);
struct TupleType *setFieldsToTupleType(char *name, struct TupleField *fields);

struct TupleType *lookupTupleTypeTable(char *name);
struct TupleType *installTupleType(struct TupleType *tupleType);
struct TupleField *getFieldOfTuple(struct TupleType *tuple, char *name);

int getOffsetOfTupleField(struct TupleType *tuple, char *fieldName);

void printTupleType(struct TupleType *tuple);

#endif