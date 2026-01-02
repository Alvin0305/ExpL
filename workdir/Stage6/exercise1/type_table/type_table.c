#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../define/constants.h"
#include "../util/util.h"
#include "../error_handler/error_handler.h"
#include "type_table.h"

static TypeTable *typeTableHead = NULL;

static int numPrimitiveTypes = 4;
static enum Type primitiveTypes[] = {INT, STRING, VOID, BOOL};
static int fieldIndex = 0;

// static helpers

static int getSizeFromFields(struct FieldList *fields) {
    struct FieldList *head = fields;
    int size = 0;
    while (head) {
        size++;
        head = head->next;
    }

    return (size == 0) ? 1 : size;
}

static struct TypeTable *createTypeTableEntry(char *name, struct FieldList *fields) {
    struct TypeTable *typeTableEntry = (struct TypeTable *)malloc(sizeof(struct TypeTable));
    int size = getSizeFromFields(fields);

    if (size > MAX_USER_DEF_VAR_SIZE) {
        compilerError(E_USER_DEF_VAR_SIZE_OVERFLOW, size);
    }

    typeTableEntry->name = strdup(name);
    typeTableEntry->size = getSizeFromFields(fields);
    typeTableEntry->fields = fields;
    typeTableEntry->next = NULL;

    return typeTableEntry;
}

static struct FieldList *createTypeFieldEntry(char *name, struct TypeTable *type) {
    struct FieldList *field = (struct FieldList *)malloc(sizeof(struct FieldList));

    field->name = strdup(name);
    field->fieldIndex = fieldIndex;
    field->type = type;
    field->next = NULL;

    fieldIndex++;

    return field;
}

static void printFields(struct FieldList *fields) {
    struct FieldList *head = fields;
    while (head) {
        printf("- %d %s %s\n", head->fieldIndex, head->name, head->type ? head->type->name : "NULL");
        head = head->next;
    }
}

// core methods

struct TypeTable *createNewType(char *name) {
    struct TypeTable *alreadyExisting = typeTableLookup(name);
    if (alreadyExisting) {
        compilerError(E_USER_TYPE_REDECLARATION, name);
    }

    struct TypeTable *entry = createTypeTableEntry(name, NULL);
    typeTableInstall(entry);
    fieldIndex = 0;

    return entry;
}

struct FieldList *createNewTypeField(char *name, struct TypeTable *type) {
    if (!type) {
        compilerError(E_FIELD_TYPE_UNDEFINED, name);
    }

    return createTypeFieldEntry(name, type);
}

struct FieldList *mergeTypeFields(struct FieldList *field1, struct FieldList *field2) {
    if (!field1 && !field2) return NULL;
    if (!field1) return field2;
    if (!field2) return field1;

    struct FieldList *tail = field1;
    while (tail->next) {
        tail = tail->next;
    }

    tail->next = field2;
    return field1;
}

struct TypeTable *typeTableLookup(char *name) {
    struct TypeTable *head = typeTableHead;

    while (head) {
        if (strcmp(head->name, name) == 0) {
            return head;
        }
        head = head->next;
    }

    return NULL;
}

void setFieldsOfType(char *name, struct FieldList *fields) {
    struct TypeTable *type = typeTableLookup(name);
    if (!type) {
        compilerError(E_FIELD_TYPE_UNDEFINED, name);
    }

    type->fields = fields;
    type->size = getSizeFromFields(fields);
}

void typeTableInstall(struct TypeTable *type) { 
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

struct FieldList *fieldListLookup(struct TypeTable *type, char *name) {
    struct FieldList *field = type->fields;

    while (field) {
        if (strcmp(field->name, name) == 0) {
            return field;
        }
        field = field->next;
    }

    return NULL;
}

void initializeTypeTable() {
    for (int i = 0; i < numPrimitiveTypes; i++) {
        typeTableInstall(createTypeTableEntry(dataTypeToString(primitiveTypes[i]), NULL));
    }
}

int getSizeOfType(TypeTable *type) {
    return type->size;
}

void printTypeTable() {
    struct TypeTable *head = typeTableHead;

    printf("\n---------[TYPE TABLE]----------\n");
    while (head) {
        printf("%s %d\n", head->name, head->size);
        printFields(head->fields);

        head = head->next;
    }
    printf("\n");
}