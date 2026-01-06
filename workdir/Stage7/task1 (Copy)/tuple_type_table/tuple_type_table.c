#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tuple_type_table.h"
#include "../util/util.h"
#include "../define/constants.h"
#include "../error_handler/error_handler.h"

static int currentTupleFieldType = NONE;
static struct TupleType *tupleTableHead = NULL;

// static methods

static struct TupleField *createTupleField(char *name, int type) {
    struct TupleField *field = (struct TupleField *) malloc(sizeof(struct TupleField));

    field->name = strdup(name);
    field->type = type;
    field->next = NULL;
    field->size = getSizeOfDataType(type);

    return field;
}

static struct TupleType *createTupleType(char *name, struct TupleFieldInfo fields[], int n) {
    struct TupleField *head = NULL;
    struct TupleField *tail = NULL;
    int size = 0;
    
    for (int i = 0; i < n; i++) {
        struct TupleField *field = createTupleField(fields[i].name, fields[i].type);
        size += getSizeOfDataType(fields[i].type);

        if (!head) {
            head = field;
            tail = field;
        } else if (tail) {
            tail->next = field;
            tail = tail->next;
        }
    }

    struct TupleType *tuple = (struct TupleType *) malloc(sizeof(struct TupleType));

    tuple->name = strdup(name);
    tuple->fields = head;
    tuple->size = size;
    tuple->numFields = n;
    tuple->next = NULL;

    return tuple;
}

static void createTupleFromNodeHelper(struct tnode *paramListNode, int *i, struct TupleFieldInfo fields[]) {
    if (!paramListNode) return;

    switch (paramListNode->nodeType) {
        case NODE_CONNECTOR:
            createTupleFromNodeHelper(paramListNode->left, i, fields);
            createTupleFromNodeHelper(paramListNode->right, i, fields);
            break;

        case NODE_TYPE:
            currentTupleFieldType = paramListNode->type;
            break;

        case NODE_VARIABLE: {
            struct TupleFieldInfo newField;
            newField.name = strdup(paramListNode->varName);
            newField.type = currentTupleFieldType;

            fields[*i] = newField;
            (*i)++;
            break;
        }

        default:
            printf("[WARNING]: Unexpected Node found in tuple param list:");
            printNode(paramListNode);
            break;
    }
}

static void countNumFieldsFromNode(struct tnode *paramListNode, int *n) {
    switch (paramListNode->nodeType) {
        case NODE_CONNECTOR:
            countNumFieldsFromNode(paramListNode->left, n);
            countNumFieldsFromNode(paramListNode->right, n);
            return;

        case NODE_VARIABLE:
            (*n)++;
            return;

        case NODE_TYPE:
            return;
        
        default:
            printf("[WARNING]: Unhandled node while counting num of fields:\n");
            printNode(paramListNode);
            return;
    }
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

struct TupleType *installTupleType(char *name, struct TupleFieldInfo fields[], int n) {
    struct TupleType *newTupleType = createTupleType(name, fields, n);

    if (!tupleTableHead) {
        tupleTableHead = newTupleType;
    } else {
        struct TupleType *head = tupleTableHead;
        while (head->next) {
            head = head->next;
        } 
        head->next = newTupleType;
    }

    return newTupleType;
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

struct TupleType *createTupleTypeFromNode(char *name, struct tnode *paramListNode) {
    currentTupleFieldType = NONE;

    int n = 0;
    countNumFieldsFromNode(paramListNode, &n);

    int i = 0;
    struct TupleFieldInfo fields[n];
    createTupleFromNodeHelper(paramListNode, &i, fields);

    return installTupleType(name, fields, n);
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