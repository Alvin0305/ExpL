#ifndef DIMENSION_H
#define DIMENSION_H

struct GSymbol;

typedef struct Dimension {
    int value;
    struct Dimension *next;
} Dimension;

void printDimensions(struct GSymbol *entry);

struct Dimension *createDimension(int value);
struct Dimension *mergeDimensions(struct Dimension *dimensions, struct Dimension *dimension);
int getNumDimensions(struct Dimension *dim);
int getDimensionProduct(struct Dimension *dim);
int *convertDimToArray(struct Dimension *dim);


#endif