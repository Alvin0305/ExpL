#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tuple.h"
#include "../util/util.h"
#include "../define/constants.h"
#include "../error_handler/error_handler.h"

int currentTupleFieldType = NONE;

struct TupleField *createTupleField(char *name, int type) {
    struct TupleField *field = (struct TupleField *) malloc(sizeof(struct TupleField));

    printf("name: %s\n", name);
    field->name = strdup(name);
    field->type = type;
    field->next = NULL;
    field->size = getSizeOfDataType(type);

    return field;
}

struct Tuple *createTuple(char *name, struct TupleFieldInfo fields[], int n) {
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

    struct Tuple *tuple = (struct Tuple *) malloc(sizeof(struct Tuple));
    tuple->name = strdup(name);
    tuple->fields = head;
    tuple->size = size;
    tuple->n = n;

    return tuple;
}

struct TupleField *getFieldOfTuple(struct Tuple *tuple, char *name) {
    struct TupleField *head = tuple->fields;

    while (head) {
        if (strcmp(head->name, name) == 0) {
            return head;
        }
        head = head->next;
    }

    return NULL;
}

void createTupleFromNodeHelper(struct tnode *paramListNode, int *i, struct TupleFieldInfo fields[]) {
    if (!paramListNode) return;

    switch (paramListNode->nodeType) {
        case NODE_CONNECTOR:
            createTupleFromNodeHelper(paramListNode->left, i, fields);
            createTupleFromNodeHelper(paramListNode->right, i, fields);
            break;

        case NODE_TYPE:
            currentTupleFieldType = paramListNode->type;
            break;

        case NODE_VARIABLE:
            struct TupleFieldInfo newField;
            newField.name = strdup(paramListNode->varName);
            newField.type = currentTupleFieldType;

            fields[*i] = newField;
            (*i)++;
            break;

        default:
            printf("Unexpected Node found in tuple param list:");
            printNode(paramListNode);
            break;
    }
}

void countNumFieldsFromNode(struct tnode *paramListNode, int *n) {
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
            printf("Unhandled node while counting num of fields: %d\n", paramListNode->nodeType);
            return;
    }
}

struct Tuple *createTupleFromNode(char *name, struct tnode *paramListNode) {
    currentTupleFieldType = NONE;

    int n = 0;
    countNumFieldsFromNode(paramListNode, &n);
    int i = 0;
    struct TupleFieldInfo fields[n];

    createTupleFromNodeHelper(paramListNode, &i, fields);

    for (int i = 0; i < n; i++) {
        printf("[%s] %s\n", dataTypeToString(fields[i].type), fields[i].name);
    }

    printf("%d\n", n);

    return createTuple(name, fields, n);
}

int getOffsetOfTupleField(struct Tuple* tuple, char *fieldName) {
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

void printTuple(struct Tuple *tuple) {
    struct TupleField* field = tuple->fields;
    while (field) {
        printf("- (%s) %s %d\n", dataTypeToString(field->type), field->name, field->size);
        field = field->next;
    }
}