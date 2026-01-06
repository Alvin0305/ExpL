#ifndef CLASS_TABLE_H
#define CLASS_TABLE_H

struct TypeInfo;
struct VarList;
struct Param;

typedef struct ClassTable {
    char *name;
    int classIndex;
    int numFields;
    int numMethods;
    struct ClassField *fields;
    struct ClassMethod *methods;
    struct ClassTable *next;
} ClassTable;

typedef struct ClassField {
    char *name;
    int fieldIndex;
    struct TypeInfo *typeInfo;
    struct ClassField *next;
} ClassField;

typedef struct ClassMethod {
    char *name;
    int methodIndex;
    int methodLabel;
    struct TypeInfo *returnType;
    struct Param *params;
    struct ClassMethod *next;
} ClassMethod;

extern struct ClassMethod *activeMethod;

struct ClassTable *createNewClass(char *name);
struct ClassField *createNewClassField(struct TypeInfo *typeInfo, char *name);
struct ClassMethod *createNewClassMethod(struct TypeInfo *returnType, char *name, struct Param *params);

struct ClassField *installVarsToCT(struct TypeInfo *typeInfo, struct VarList *vars);

void setFieldsToClass(struct ClassField *fields);
void setMethodsToClass(struct ClassMethod *methods);

struct ClassField *mergeClassFields(struct ClassField *fields1, struct ClassField *fields2);
struct ClassMethod *mergeClassMethods(struct ClassMethod *methods1, struct ClassMethod *methods2);

struct ClassTable *lookupCT(char *name);
struct ClassField *lookupClassField(struct ClassTable *_class, char *name);
struct ClassMethod *lookupClassMethod(struct ClassTable *_class, char *name);
struct ClassMethod *lookupMethodInActiveClass(char *name);

void printCT();

void addMethodParamsToLST(struct Param *params);
void checkMethodSignature(struct TypeInfo *returnType, char *methodName, struct Param *params);

#endif