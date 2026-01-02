#ifndef TYPE_TABLE_H
#define TYPE_TABLE_H

typedef struct TypeTable {
    char *name;
    int size;
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

struct TypeTable *createNewType(char *name);
struct FieldList *createNewTypeField(char *name, struct TypeTable *type);
struct FieldList *mergeTypeFields(struct FieldList *field1, struct FieldList *field2);

struct TypeTable *typeTableLookup(char *name);
void typeTableInstall(struct TypeTable *type);
void setFieldsOfType(char *name, struct FieldList *fields);

struct FieldList *fieldListLookup(struct TypeTable *type, char *name);

void printTypeTable();

#endif