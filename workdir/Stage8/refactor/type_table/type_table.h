#ifndef TYPE_TABLE_H
#define TYPE_TABLE_H

#include "../type_info/type_info.h"
#include <stdbool.h>

struct TupleType;

typedef struct TypeTable {
    char *name;
    int size;
    enum Kind kind;
    struct TypeField *fields;
    struct TypeTable *next;
} TypeTable;

typedef struct TypeField {
    char *name;
    int fieldIndex;
    struct TypeTable *type;
    struct TypeField *next;
} TypeField;

void initializeTypeTable();

struct TypeTable *createNewType(char *name, enum Kind kind);
struct TypeField *createNewTypeField(char *name, struct TypeTable *type);
struct TypeField *mergeTypeFields(struct TypeField *field1, struct TypeField *field2);

struct TypeTable *lookupTT(char *name);
void installTT(struct TypeTable *type);
void setFieldsOfType(char *name, struct TypeField *fields);

struct TypeField *fieldListLookup(struct TypeTable *type, char *name);

struct TypeTable *createNewTypeForTuple(struct TupleType *tupleType);

void printTypeTable();

bool isPrimitive(enum Kind kind);

#endif