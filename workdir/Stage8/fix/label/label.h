#ifndef LABEL_H
#define LABEL_H

typedef struct LabelTableEntry {
    char *labelName;
    int memAddr;
    struct LabelTableEntry *next;

} LabelTableEntry;

int createNewLabel();
int getMemAddrForLabel(char *labelName);
int addNewLabel(char *labelName, int memAddr);
void removeLabel(char *labelName);

#endif