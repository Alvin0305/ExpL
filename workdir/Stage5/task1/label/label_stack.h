#ifndef LABEL_STACK_H
#define LABEL_STACK_H

typedef struct LabelStackNode {
    int loopConditionLabel;
    int restOfCodeLabel;
    struct LabelStackNode *next;
} LabelStackNode;

extern struct LabelStackNode *stack_head;

void pushToLabelStack(int loopConditionLabel, int restOfCodeLabel);
struct LabelStackNode *popFromLabelStack();
struct LabelStackNode *peekFromLabelStack();

#endif