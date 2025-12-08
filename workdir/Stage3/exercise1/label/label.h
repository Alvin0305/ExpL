#ifndef LABEL_H
#define LABEL_H

#define MAX_LABEL_LENGTH 10

typedef struct LabelTableEntry {
    char labelName[MAX_LABEL_LENGTH];
    int memAddr;
    struct LabelTableEntry *next;

} LabelTableEntry;

extern int labelCount;
extern struct LabelTableEntry *head;
extern struct LabelTableEntry *tail;

char *createNewLabel();
struct LabelTableEntry *createNewLabelTableEntry(char *labelName, int memAddr);
int getMemAddrForLabel(char *labelName);
int addNewLabel(char *labelName, int memAddr);
void removeLabel(char *labelName);

#endif