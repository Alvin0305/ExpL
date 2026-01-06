#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tuple_type_table.h"
#include "../util/util.h"
#include "../define/constants.h"
#include "../error_handler/error_handler.h"
#include "../type_table/type_table.h"

// static int currentTupleFieldType = NONE;
static struct TupleType *tupleTableHead = NULL;

// static methods

struct TupleField *createTupleField(struct TypeInfo *type, char *name) {
    if (!isPrimitive(type->kind)) {
        printf("[ERROR]\n");        
    }

    struct TupleField *field = (struct TupleField *) malloc(sizeof(struct TupleField));

    field->name = strdup(name);
    field->type = type->kind;
    field->next = NULL;
    field->size = getSizeOfDataType(type->kind);

    return field;
}

struct TupleField *mergeTupleFields(struct TupleField *fields, struct TupleField *field) {
    if (!fields) return field;
    if (!field) return fields;

    struct TupleField *prev = NULL;
    struct TupleField *head = fields;
    while (head) {
        if (strcmp(head->name, field->name) == 0) {
            printf("[error]\n");
        }
        prev = head;
        head = head->next;
    }

    prev->next = field;
    return fields;
}

static int countNumFields(struct TupleField *fields) {
    struct TupleField *head = fields;
    int count = 0;

    while (head) {
        count++;
        head = head->next;
    }

    return count;
}

struct TupleType *createNewTupleType(char *name) {
    struct TupleType *tupleType = (struct TupleType *) malloc(sizeof(struct TupleType));

    tupleType->name = strdup(name);
    tupleType->numFields = 0;
    tupleType->fields = NULL;
    tupleType->size = 0;
    tupleType->next = NULL;

    installTupleType(tupleType);

    return tupleType;
}

struct TupleType *setFieldsToTupleType(char *name, struct TupleField *fields) {
    struct TupleType *tupleType = lookupTupleTypeTable(name);
    if (!tupleType) {
        printf("error");
    }

    tupleType->fields = fields;
    tupleType->numFields = countNumFields(fields);
    tupleType->size = tupleType->numFields;

    return tupleType;
}

// core methods

struct TupleType *lookupTupleTypeTable(char *name) {
    struct TupleType *head = tupleTableHead;

    while (head) {
        if (strcmp(head->name, name) == 0) {
            return head;
        }
        head = head->next;
    }

    return NULL;
}

struct TupleType *installTupleType(struct TupleType *tupleType) {
    if (!tupleTableHead) {
        tupleTableHead = tupleType;
    } else {
        struct TupleType *head = tupleTableHead;
        while (head->next) {
            head = head->next;
        } 
        head->next = tupleType;
    }

    return tupleType;
}

struct TupleField *getFieldOfTuple(struct TupleType *tuple, char *name) {
    struct TupleField *head = tuple->fields;

    while (head) {
        if (strcmp(head->name, name) == 0) {
            return head;
        }
        head = head->next;
    }

    return NULL;
}

int getOffsetOfTupleField(struct TupleType* tuple, char *fieldName) {
    struct TupleField *field = tuple->fields;
    int offset = 0;

    while (field) {
        if (strcmp(field->name, fieldName) == 0) {
            return offset;
        }

        offset += field->size;
        field = field->next;
    }

    compilerError(E_ACCESS_NON_EXISTING_FIELD_OF_TUPLE, tuple->name, fieldName);
    return __NONE__;
}

void printTupleType(struct TupleType *tuple) {
    struct TupleField* field = tuple->fields;
    while (field) {
        printf("- (%s) %s %d\n", dataTypeToString(field->type), field->name, field->size);
        field = field->next;
    }
}