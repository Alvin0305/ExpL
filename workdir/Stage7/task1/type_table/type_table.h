#ifndef TYPE_TABLE_H
#define TYPE_TABLE_H

struct TupleType;

typedef struct TypeTable {
    char *name;
    int size;
    enum Type kind;
    bool isPtr;
    struct FieldList *fields;
    struct TypeTable *next;
} TypeTable;

typedef struct FieldList {
    char *name;
    int fieldIndex;
    struct TypeTable *type;
    struct FieldList *next;
} FieldList;

void initializeTypeTable();
int getSizeOfType(TypeTable *type);

struct TypeTable *createNewType(char *name, enum Type kind);
struct FieldList *createNewTypeField(char *name, struct TypeTable *type);
struct FieldList *mergeTypeFields(struct FieldList *field1, struct FieldList *field2);

struct TypeTable *lookupTT(char *name);
void installTT(struct TypeTable *type);
void setFieldsOfType(char *name, struct FieldList *fields);

struct FieldList *fieldListLookup(struct TypeTable *type, char *name);

struct TypeTable *createNewTypeForTuple(struct TupleType *tupleType);

void printTypeTable();

#endif