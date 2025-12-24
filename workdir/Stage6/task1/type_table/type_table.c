#include <stdbool.h>
#include <stdio.h>

#include "../define/constants.h"
#include "../util/util.h"
#include "type_table.h"

static TypeTable *typeTableHead = NULL;

static int numPrimitiveTypes = 4;
static Type primitiveTypes[] = {INT, STRING, VOID, BOOL};

// static helpers

static struct TypeTable *createTypeTableEntry(char *name, int size, struct FieldList *fields) {
    struct TypeTable *typeTableEntry = (struct TypeTable *)malloc(sizeof(struct TypeTable));

    typeTableEntry->name = strdup(name);
    typeTableEntry->size = size;
    typeTableEntry->fields = fields;
    typeTableEntry->next = NULL;

    return typeTableEntry;
}

static struct FieldList *createField(char *name, int fieldIndex, struct TypeTable *type) {
    struct FieldList *field = (struct FieldList *)malloc(sizeof(struct FieldList));

    field->name = strdup(name);
    field->fieldIndex = fieldIndex;
    field->type = type;
    field->next = NULL;

    return field;
}

static bool isPrimitiveType(Type type) {
    for (int i = 0; i < numPrimitiveTypes; i++) {
        if (primitiveTypes[i] == type) {
            return true;
        }
    }

    return false;
}

// core methods

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

struct TypeTable *typeTableInstall(char *name, int size, struct FieldList *fields) {
    struct TypeTable *typeTableEntry = createTypeTableEntry(name, size, fields);

    struct TypeTable *head = typeTableHead;
    if (!head) {
        typeTableHead = typeTableEntry;
    } else {
        while (head->next) {
            head = head->next;
        }

        head->next = typeTableEntry;
    }

    return typeTableEntry;
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
        typeTableInstall(dataTypeToString(primitiveTypes[i]), getSizeOfDataType(primitiveTypes[i]), NULL);
    }
}

int getSizeOfType(TypeTable *type) {
    return type->size;
}