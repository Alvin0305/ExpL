#include "label.h"
#include "../define/constants.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int labelCount = 0;
struct LabelTableEntry *head = NULL;
struct LabelTableEntry *tail = NULL;

int createNewLabel() {
    return labelCount++;
}

struct LabelTableEntry *createNewLabelTableEntry(char *labelName, int memAddr) {
    struct LabelTableEntry *node = (struct LabelTableEntry *) malloc(sizeof(LabelTableEntry));

    strcpy(node->labelName, labelName);
    node->memAddr = memAddr;
    node->next = NULL;

    return node;
}

int getMemAddrForLabel(char *labelName) {
    LabelTableEntry *temp = head;

    while (temp) {
        if (strcmp(temp->labelName, labelName) == 0) {
            return temp->memAddr;
        }

        temp = temp->next;
    }

    return -1;
}

int addNewLabel(char *labelName, int memAddr) {
    int alreadyExisting = getMemAddrForLabel(labelName);

    if (alreadyExisting != -1) {
        return E_LABEL_EXISTS;
    }

    struct LabelTableEntry *newEntry = createNewLabelTableEntry(labelName, memAddr);

    if (!head) {
        head = newEntry;
        tail = newEntry;
        return SUCCESS;
    }

    tail->next = newEntry;
    tail = newEntry;

    return SUCCESS;
}

void removeLabel(char *labelName) {
    LabelTableEntry *prev = NULL;
    LabelTableEntry *current = head;

    while (current) {
        if (strcmp(current->labelName, labelName) == 0) {
            if (current == tail) {
                tail = prev;
            }

            if (current == head) {
                head = current->next;
            }

            if (prev) {
                prev->next = current->next;
            }
        }

        current = current->next;
    }
}