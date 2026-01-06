#include "class_table.h"
#include "../error_handler/error_handler.h"
#include "../label/label.h"
#include "../type_table/type_table.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int numClasses = 0;
static int numField = 0;
static int numMethods = 0;

static struct TypeTable *activeType;
static struct ClassTable *activeClass;
static char *activeClassName;

static struct ClassTable *classTableHead;

struct ClassTable *createNewClass(char *name) {
    struct ClassTable *_class = (struct ClassTable *)malloc(sizeof(struct ClassTable));

    _class->name = strdup(name);
    _class->classIndex = numClasses++;
    _class->fields = NULL;
    _class->methods = NULL;
    _class->next = NULL;
    _class->numFields = 0;
    _class->numMethods = 0;

    numField = 0;
    numMethods = 0;

    installCT(_class);
    activeClassName = strdup(name);

    return _class;
}

struct ClassField *createNewClassField(char *name) {
    struct ClassField *field = (struct ClassField *)malloc(sizeof(struct ClassField));

    field->name = strdup(name);
    field->type = activeType;
    field->_class = activeClass;
    field->next = NULL;
    field->fieldIndex = numField++;

    return field;
}

struct ClassMethod *createNewClassMethod(char *name, struct Param *params) {
    struct ClassMethod *method = (struct ClassMethod *)malloc(sizeof(struct ClassMethod));

    method->name = strdup(name);
    method->params = params;
    method->returnType = activeType;
    method->next = NULL;
    method->methodIndex = numMethods++;
    method->methodLabel = createNewLabel();

    return method;
}

struct ClassTable *lookupCT(char *name) {
    struct ClassTable *head = classTableHead;

    while (head) {
        if (strcmp(name, head->name) == 0) {
            return head;
        }
        head = head->next;
    }

    return NULL;
}

struct ClassField *lookupClassField(struct ClassTable *_class, char *name) {
    struct ClassField *field = _class->fields;

    while (field) {
        if (strcmp(field->name, name) == 0) {
            return field;
        }
        field = field->next;
    }

    return NULL;
}

struct ClassMethod *lookupClassMethod(struct ClassTable *_class, char *name) {
    struct ClassMethod *method = _class->methods;

    while (method) {
        if (strcmp(method->name, name) == 0) {
            return method;
        }
        method = method->next;
    }

    return NULL;
}

void setFieldsToClass(struct ClassField *fields) {
    struct ClassTable *_class = lookupCT(activeClassName);
    if (!_class) compilerError(E_CLASS_USED_BEFORE_DECLARATION, activeClassName);

    _class->numFields = numField;
    _class->fields = fields;
}

void setMethodsToClass(struct ClassMethod *methods) {
    struct ClassTable *_class = lookupCT(activeClassName);
    if (!_class) compilerError(E_CLASS_USED_BEFORE_DECLARATION, activeClassName);

    _class->numMethods = numMethods;
    _class->methods = methods;
}

void installCT(struct ClassTable *_class) {
    struct ClassTable *head = classTableHead;

    if (!head) {
        classTableHead = _class;
        return;
    }

    while (head->next) {
        head = head->next;
    }

    head->next = _class;
}

struct ClassField *mergeClassFields(struct ClassField *fields, struct ClassField *field) {
    if (!fields) return field;
    if (!field) return fields;

    struct ClassField *prev = NULL;
    struct ClassField *head = fields;
    while (head) {
        if (strcmp(head->name, field->name) == 0) {
            compilerError(E_VARIABLE_REDECLARATION, head->name);
        }
        prev = head;
        head = head->next;
    }

    prev->next = field;

    return fields;
}

struct ClassMethod *mergeClassMethods(struct ClassMethod *methods, struct ClassMethod *method) {
    if (!methods) return method;
    if (!method) return methods;

    struct ClassMethod *prev = NULL;
    struct ClassMethod *head = methods;
    while (head) {
        if (strcmp(head->name, method->name) == 0) {
            compilerError(E_FUNCTION_REDECLARATION, head->name);
        }
        prev = head;
        head = head->next;
    }
    
    prev->next = method;

    return methods;
}

static void printClassFieldOfClass(struct ClassTable *_class) {
    struct ClassField *field = _class->fields;

    printf("  Fields: \n");
    while (field) {
        printf("  - %d %s %s\n", field->fieldIndex, field->name,
               field->type     ? field->type->name
               : field->_class ? field->_class->name
                               : "NONE");
        field = field->next;
    }
}

static void printClassMethodsOfClass(struct ClassTable *_class) {
    struct ClassMethod *method = _class->methods;

    printf("  Methods: \n");
    while (method) {
        printf("  - %d %s %d %s\n", method->methodIndex, method->name, method->methodLabel, method->returnType->name);
        method = method->next;
    }
}

void printCT() {
    struct ClassTable *head = classTableHead;

    printf("\n-----------[CLASS TABLE]-----------\n");
    while (head) {
        printf("Class: ");
        printf("%d %s %d %d\n", head->classIndex, head->name, head->numFields, head->numMethods);
        printClassFieldOfClass(head);
        printClassMethodsOfClass(head);

        head = head->next;
    }
}

void setActiveClassName(char *name) {
    activeClassName = strdup(name);
}

void setActiveClassFieldType(struct TypeTable *type, struct ClassTable *_class) {
    activeType = type;
    activeClass = _class;
}