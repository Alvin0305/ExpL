#ifndef CONTROL_FLOW_H
#define CONTROL_FLOW_H

#include <stdio.h>
#include "../../node/node.h"

extern FILE *target_file;

// generate code for condition
void generateConditionCode(struct tnode *node, int trueLabel, int falseLabel);
void generateLogicalConditionCode(struct tnode *node, int trueLabel, int falseLabel);

// generate code for if, and if else
void generateIfCode(struct tnode *node);
void generateIfElseCode(struct tnode *node);

// generate code for loops
void generateWhileLoopCode(struct tnode *node);
void generateRepeatUntilCode(struct tnode *node);
void generateDoWhileCode(struct tnode *node);

// generate code for break, continue
void generateBreakCode();
void generateContinueCode();

// helpers
void generateLabelHeader(int label);
void generateJumpOnZeroCode(int reg, int label);
void generateJumpOnNonZeroCode(int reg, int label);
void generateJumpCode(int label);

#endif