#ifndef CONTROL_FLOW_H
#define CONTROL_FLOW_H

#include "../../node/node.h"
#include <stdio.h>

extern FILE *target_file;

// generate code for condition
void generateConditionCode(struct Node *node, int trueLabel, int falseLabel);
void generateLogicalConditionCode(struct Node *node, int trueLabel, int falseLabel);

// generate code for if, and if else
void generateIfCode(struct Node *node);
void generateIfElseCode(struct Node *node);

// generate code for loops
void generateWhileLoopCode(struct Node *node);
void generateRepeatUntilCode(struct Node *node);
void generateDoWhileCode(struct Node *node);

// generate code for break, continue
void generateBreakCode();
void generateContinueCode();

// helpers
void generateLabelHeader(int label);
void generateJumpOnZeroCode(int reg, int label);
void generateJumpOnNonZeroCode(int reg, int label);
void generateJumpCode(int label);

#endif