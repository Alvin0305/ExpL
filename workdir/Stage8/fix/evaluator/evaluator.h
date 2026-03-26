#ifndef EVALUATOR_H
#define EVALUATOR_H

#include "../node/node.h"

#define NUM_VARS 26

extern int variables[NUM_VARS];

void evaluateAndPrint(struct Node *root);
int evaluate(struct Node *root);
int getVariableIndex(struct Node *root);

#endif