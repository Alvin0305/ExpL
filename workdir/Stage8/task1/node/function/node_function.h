#ifndef NODE_FUNCTION_H
#define NODE_FUNCTION_H

struct Node;

#include "../../g_symbol_table/param_list.h"

struct Node *createFunctionCallNode(struct Node *functionNameNode, struct Node *argListNode);
struct Node *createReturnNode(struct Node *exprNode);
bool checkArgs(Param **param, struct Node *argListNode, char *functionName);

#endif