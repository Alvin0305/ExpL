#ifndef LABEL_H
#define LABEL_H

#define MAX_LABEL_LENGTH 10

typedef struct LabelTableEntry {
    char labelName[MAX_LABEL_LENGTH];
    int memAddr;
    struct LabelTableEntry *next;

} LabelTableEntry;

int createNewLabel();
int getMemAddrForLabel(char *labelName);
int addNewLabel(char *labelName, int memAddr);
void removeLabel(char *labelName);

#endif