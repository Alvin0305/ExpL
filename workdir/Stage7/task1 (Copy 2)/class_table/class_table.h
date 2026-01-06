#ifndef CLASS_TABLE_H
#define CLASS_TABLE_H

typedef struct ClassTable {
    char *name;
    int classIndex;

    int numFields;
    struct ClassField *fields;

    int numMethods;
    struct ClassMethod *methods;

    struct ClassTable *next;
} ClassTable;

typedef struct ClassField {
    char *name;
    int fieldIndex;

    struct TypeTable *type;
    struct ClassTable *_class;

    struct ClassField *next;
} ClassField;

typedef struct ClassMethod {
    char *name;
    int methodIndex;
    int methodLabel;

    struct TypeTable *returnType;
    struct Param *params;

    struct ClassMethod *next;
} ClassMethod;

struct ClassTable *createNewClass(char *name);
struct ClassField *createNewClassField(char *name);
struct ClassMethod *createNewClassMethod(char *name, struct Param *params);

void setFieldsToClass(struct ClassField *fields);
void setMethodsToClass(struct ClassMethod *methods);

struct ClassField *mergeClassFields(struct ClassField *fields1, struct ClassField *fields2);
struct ClassMethod *mergeClassMethods(struct ClassMethod *methods1, struct ClassMethod *methods2);

struct ClassTable *lookupCT(char *name);
void installCT(struct ClassTable *_class);

struct ClassField *lookupClassField(struct ClassTable *_class, char *name);
struct ClassMethod *lookupClassMethod(struct ClassTable *_class, char *name);

void setActiveClassName(char *name);

void printCT();

#endif