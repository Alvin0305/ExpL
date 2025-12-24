#include "label_stack.h"
#include <stdio.h>
#include <stdlib.h>

struct LabelStackNode *stack_head = NULL;

void pushToLabelStack(int loopConditionLabel, int restOfCodeLabel) {
    struct LabelStackNode *node = (struct LabelStackNode*) malloc(sizeof(struct LabelStackNode));

    node->loopConditionLabel = loopConditionLabel;
    node->restOfCodeLabel = restOfCodeLabel;
    node->next = stack_head;

    stack_head = node;
}

struct LabelStackNode *popFromLabelStack() {
    struct LabelStackNode *node = stack_head;

    stack_head = stack_head->next;
    return node;
}

struct LabelStackNode *peekFromLabelStack() {
    return stack_head;
}