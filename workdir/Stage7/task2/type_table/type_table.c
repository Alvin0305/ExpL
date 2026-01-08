#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../define/constants.h"
#include "../error_handler/error_handler.h"
#include "../tuple_type_table/tuple_type_table.h"
#include "../util/util.h"
#include "type_table.h"

static TypeTable *typeTableHead = NULL;

static int numPrimitiveTypes = 5;
static enum Kind primitiveTypes[] = {INT, STRING, VOID, BOOL, NULL_TYPE};
static int fieldIndex = 0;

// static helpers

static int getSizeFromFields(struct TypeField *fields) {
    struct TypeField *head = fields;
    int size = 0;
    while (head) {
        size++;
        head = head->next;
    }

    return (size == 0) ? 1 : size;
}

static struct TypeTable *createTypeTableEntry(char *name, struct TypeField *fields, enum Kind kind, bool isPtr) {
    struct TypeTable *typeTableEntry = (struct TypeTable *)malloc(sizeof(struct TypeTable));
    int size = getSizeFromFields(fields);

    if (size > DYNAMIC_MEM_ALLOC_BLOCK_SIZE) {
        compilerError(E_INVALID_UDT_SIZE, size);
    }

    typeTableEntry->name = strdup(name);
    typeTableEntry->size = getSizeFromFields(fields);
    typeTableEntry->fields = fields;
    typeTableEntry->next = NULL;
    typeTableEntry->kind = kind;

    return typeTableEntry;
}

static struct TypeField *createTypeFieldEntry(char *name, struct TypeTable *type) {
    struct TypeField *field = (struct TypeField *)malloc(sizeof(struct TypeField));

    field->name = strdup(name);
    field->fieldIndex = fieldIndex;
    field->type = type;
    field->next = NULL;

    fieldIndex++;
    if (fieldIndex > DYNAMIC_MEM_ALLOC_BLOCK_SIZE) {
        compilerError(E_INVALID_UDT_SIZE);
    }

    return field;
}

static void printFields(struct TypeField *fields) {
    struct TypeField *head = fields;
    while (head) {
        printf("- %d %s %s\n", head->fieldIndex, head->name, head->type ? head->type->name : "NULL");
        head = head->next;
    }
}

// core methods

struct TypeTable *createNewTypeForTuple(struct TupleType *tupleType) {
    struct TypeTable *type = createNewType(tupleType->name, TUPLE);
    struct TupleField *tupleField = tupleType->fields;

    struct TypeField *head = NULL;
    while (tupleField) {
        struct TypeField *fieldType = createNewTypeField(tupleField->name, lookupTT(dataTypeToString(tupleField->type)));
        head = mergeTypeFields(head, fieldType);

        tupleField = tupleField->next;
    }

    setFieldsOfType(type->name, head);
    return type;
}

struct TypeTable *createNewType(char *name, enum Kind kind) {
    struct TypeTable *alreadyExisting = lookupTT(name);
    if (alreadyExisting) {
        compilerError(E_USER_TYPE_REDECLARATION, name);
    }

    struct TypeTable *entry = createTypeTableEntry(name, NULL, kind, true);
    installTT(entry);
    fieldIndex = 0;

    return entry;
}

struct TypeField *createNewTypeField(char *name, struct TypeTable *type) {
    if (!type) {
        compilerError(E_FIELD_TYPE_UNDEFINED, name);
    }

    return createTypeFieldEntry(name, type);
}

struct TypeField *mergeTypeFields(struct TypeField *field1, struct TypeField *field2) {
    if (!field1 && !field2) return NULL;
    if (!field1) return field2;
    if (!field2) return field1;

    struct TypeField *tail = field1;
    while (tail->next) {
        tail = tail->next;
    }

    tail->next = field2;
    return field1;
}

struct TypeTable *lookupTT(char *name) {
    struct TypeTable *head = typeTableHead;

    while (head) {
        if (strcmp(head->name, name) == 0) {
            return head;
        }
        head = head->next;
    }

    printTypeTable();

    return NULL;
}

void setFieldsOfType(char *name, struct TypeField *fields) {
    struct TypeTable *type = lookupTT(name);
    if (!type) {
        compilerError(E_FIELD_TYPE_UNDEFINED, name);
    }

    type->fields = fields;
    type->size = getSizeFromFields(fields);
}

void installTT(struct TypeTable *type) {
    struct TypeTable *head = typeTableHead;
    if (!head) {
        typeTableHead = type;
    } else {
        while (head->next) {
            head = head->next;
        }

        head->next = type;
    }
}

struct TypeField *fieldListLookup(struct TypeTable *type, char *name) {
    struct TypeField *field = type->fields;

    while (field) {
        if (strcmp(field->name, name) == 0) {
            return field;
        }
        field = field->next;
    }

    return NULL;
}

bool isPrimitive(enum Kind kind) {
    for (int i = 0; i < numPrimitiveTypes; i++) {
        if (primitiveTypes[i] == kind) {
            return true;
        }
    }

    return false;
}

void initializeTypeTable() {
    for (int i = 0; i < numPrimitiveTypes; i++) {
        installTT(createTypeTableEntry(dataTypeToString(primitiveTypes[i]), NULL, primitiveTypes[i], false));
    }
}

void printTypeTable() {
    struct TypeTable *head = typeTableHead;

    printf("\n---------[TYPE TABLE]----------\n");
    while (head) {
        printf("%s %d %s\n", head->name, head->size, dataTypeToString(head->kind));
        printFields(head->fields);

        head = head->next;
    }
    printf("\n");
}