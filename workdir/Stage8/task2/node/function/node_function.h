#ifndef NODE_FUNCTION_H
#define NODE_FUNCTION_H

struct Node;

struct Node *createFunctionCallNode(struct Node *functionNameNode, struct Node *argListNode);
struct Node *createReturnNode(struct Node *exprNode);

#endif