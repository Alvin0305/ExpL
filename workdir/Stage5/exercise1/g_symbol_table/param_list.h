#ifndef PARAM_LIST_H
#define PARAM_LIST_H

typedef struct Param {
    char *name;
    int type;
    struct Param *next;

    bool isPtr;
} Param;

struct Param *addParam(struct GSymbol *GSymbolTableEntry, char *name, int type, bool isPtr);
struct Param *lookupParam(struct GSymbol *GSymbolTableEntry, char *name);
void printParamList(struct Param *head);
int getNumOfParams(struct Param *paramList);
int getTotalSizeOfParams(struct Param *paramList);

#endif