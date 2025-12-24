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

struct TypeTable *typeTableLookup(char *name);
struct TypeTable *typeTableInstall(char *name, int size, struct FieldList *fieldList);

struct FieldList *fieldListLookup(struct TypeTable *type, char *name);

#endif