#include "dimension.h"
#include "../error_handler/error_handler.h"

#include <stdio.h>
#include <stdlib.h>

struct Dimension *mergeDimensions(struct Dimension *dimensions, struct Dimension *dimension) {
    if (!dimensions) return dimension;
    if (!dimension) return dimensions;

    struct Dimension *head = dimensions;
    while (head->next) {
        head = head->next;
    }

    head->next = dimension;
    return dimensions;
}

struct Dimension *createDimension(int value) {
    if (value <= 0) {
        compilerError(E_INVALID_DIMENSION, value);
    }

    struct Dimension *dim = (struct Dimension *)malloc(sizeof(struct Dimension));
    dim->value = value;
    dim->next = NULL;

    return dim;
}

int *convertDimToArray(struct Dimension *dim) {
    int n = getNumDimensions(dim);
    int *array = (int *)malloc(sizeof(int) * n);
    int i = 0;

    while (dim) {
        array[i++] = dim->value;
        dim = dim->next;
    }

    return array;
}

int getNumDimensions(struct Dimension *dim) {
    int count = 0;
    while (dim) {
        count++;
        dim = dim->next;
    }

    return count;
}

int getDimensionProduct(struct Dimension *dim) {
    int result = 1;
    while (dim) {
        result *= dim->value;
        dim = dim->next;
    }

    return result;
}
