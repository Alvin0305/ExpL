#include "class_table.h"
#include "../error_handler/error_handler.h"
#include "../g_symbol_table/param_list.h"
#include "../label/label.h"
#include "../local_symbol_table/local_symbol_table.h"
#include "../tuple_type_table/tuple_type_table.h"
#include "../type_info/type_info.h"
#include "../type_table/type_table.h"
#include "../util/util.h"
#include "../util/var_list.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int numClasses = 0;
static int numField = 0;
static int numMethods = 0;

static struct ClassTable *classTableHead;

static struct ClassTable *activeClass;
struct ClassMethod *activeMethod = NULL;

static void printClassFieldOfClass(struct ClassTable *_class) {
    struct ClassField *field = _class->fields;

    printf("  Fields: \n");
    while (field) {
        if (field->typeInfo->kind == TUPLE) {
            printf("  - %d %s %s\n", field->fieldIndex, field->name, field->typeInfo->tupleType->name);
        } else if (field->typeInfo->kind == CLASS) {
            printf("  - %d %s %s\n", field->fieldIndex, field->name, field->typeInfo->_class->name);
        } else {
            printf("  - %d %s %s\n", field->fieldIndex, field->name, field->typeInfo->type->name);
        }

        field = field->next;
    }
}

static void printClassMethodParam(struct Param *params) {
    struct Param *head = params;
    while (head) {
        if (head->typeInfo->kind == TUPLE) {
            printf("    - %s [%s] %s\n", head->name, head->typeInfo->tupleType->name, booleanToString(head->isPtr));
        } else if (head->typeInfo->kind == CLASS) {
            printf("    - %s [%s] %s\n", head->name, head->typeInfo->_class->name, booleanToString(head->isPtr));
        } else {
            printf("    - %s [%s] %s\n", head->name, head->typeInfo->type->name, booleanToString(head->isPtr));
        }

        head = head->next;
    }
}

static void printClassMethodsOfClass(struct ClassTable *_class) {
    struct ClassMethod *method = _class->methods;

    printf("  Methods: \n");
    while (method) {
        struct TypeInfo *returnType = method->returnType;
        if (returnType->kind == TUPLE) {
            printf("  - %d %s %s\n", method->methodIndex, method->name, returnType->tupleType->name);
        } else if (returnType->kind == CLASS) {
            printf("  - %d %s %s\n", method->methodIndex, method->name, returnType->_class->name);
        } else {
            printf("  - %d %s %s\n", method->methodIndex, method->name, returnType->type->name);
        }
        printClassMethodParam(method->params);
        method = method->next;
    }
}

static void installCT(struct ClassTable *_class) {
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

static struct Param *addSelfParam(struct Param *params) {
    struct Param *selfParam = createParam(createTypeInfo(CLASS, NULL, NULL, activeClass), "self", true);
    selfParam->next = params;
    return selfParam;
}

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
    activeClass = _class;

    return _class;
}

struct ClassField *installVarsToCT(struct TypeInfo *typeInfo, struct VarList *vars) {
    struct VarList *head = vars;
    struct ClassField *fields = NULL;

    while (head) {
        fields = mergeClassFields(fields, createNewClassField(typeInfo, head->name));
        head = head->next;
    }

    return fields;
}

struct ClassField *createNewClassField(struct TypeInfo *typeInfo, char *name) {
    struct ClassField *field = (struct ClassField *)malloc(sizeof(struct ClassField));

    field->name = strdup(name);
    field->typeInfo = typeInfo;
    field->next = NULL;
    field->fieldIndex = numField++;

    if (numField > 8) {
        compilerError(E_INVALID_SIZE_FOR_CLASS, activeClass->name);
    }
 
    return field;
}

struct ClassMethod *createNewClassMethod(struct TypeInfo *returnType, char *name, struct Param *params) {
    struct ClassMethod *method = (struct ClassMethod *)malloc(sizeof(struct ClassMethod));

    params = addSelfParam(params);

    method->params = params;
    method->name = strdup(name);
    method->returnType = returnType;
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

struct ClassMethod *lookupMethodInActiveClass(char *name) { return lookupClassMethod(activeClass, name); }

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
    activeClass->numFields = numField;
    activeClass->fields = fields;
}

void setMethodsToClass(struct ClassMethod *methods) {
    activeClass->numMethods = numMethods;
    activeClass->methods = methods;
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

void checkMethodParams(struct Param *givenParams, struct Param *expectedParams, char *methodName) {
    struct Param *head1 = givenParams;
    struct Param *head2 = expectedParams;

    while (head1 && head2) {
        if (strcmp(head1->name, head2->name) != 0) {
            compilerError(E_FUNCTION_SIGNATURE_VARNAME_MISMATCH, methodName, head1->name, head2->name);
        } else if (!isTypeCompatible(head1->typeInfo, head2->typeInfo)) {
            compilerError(E_FUNCTION_SIGNATURE_TYPE_MISMATCH, methodName, head1->name, head1->typeInfo->kind,
                          head2->typeInfo->kind);
        }

        head1 = head1->next;
        head2 = head2->next;
    }

    if (head1) {
        compilerError(E_FUNCTION_SIGNATURE_MORE_ARG, methodName);
    } else if (head2) {
        compilerError(E_FUNCTION_SIGNATURE_TOO_FEW_ARG, methodName);
    }
}

void addMethodParamsToLST(struct Param *params) {
    params = addSelfParam(params);

    struct Param *param = params;
    while (param) {
        installToLST(param->typeInfo, param->name, param->isPtr, true, NULL);
        param = param->next;
    }
}

void checkMethodSignature(struct TypeInfo *returnType, char *methodName, struct Param *params) {
    struct ClassMethod *method = lookupMethodInActiveClass(methodName);
    struct Param *givenParams = addSelfParam(params);

    if (!method) {
        compilerError(E_FUNCTION_USED_BEFORE_DECLARATION, methodName);
    }

    if (!isTypeCompatible(returnType, method->returnType)) {
        compilerError(E_FUNCTION_SIGNATURE_RETURN_TYPE_MISMATCH, methodName, method->returnType->type, returnType->type);
    }

    checkMethodParams(givenParams, method->params, methodName);
}