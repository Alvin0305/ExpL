#include "label_stack.h"
#include <stdio.h>
#include <stdlib.h>

static struct LabelStackNode *stackHead = NULL;

void pushToLabelStack(int loopConditionLabel, int restOfCodeLabel) {
    struct LabelStackNode *node = (struct LabelStackNode *)malloc(sizeof(struct LabelStackNode));

    node->loopConditionLabel = loopConditionLabel;
    node->restOfCodeLabel = restOfCodeLabel;
    node->next = stackHead;

    stackHead = node;
}

struct LabelStackNode *popFromLabelStack() {
    struct LabelStackNode *node = stackHead;

    stackHead = stackHead->next;
    return node;
}

struct LabelStackNode *peekFromLabelStack() {
    return stackHead;
}