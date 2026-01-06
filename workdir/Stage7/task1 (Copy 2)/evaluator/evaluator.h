#ifndef EVALUATOR_H
#define EVALUATOR_H

#include "../node/node.h"

#define NUM_VARS 26

extern int variables[NUM_VARS];

void evaluateAndPrint(struct tnode *root);
int evaluate(struct tnode *root);
int getVariableIndex(struct tnode *root);

#endif