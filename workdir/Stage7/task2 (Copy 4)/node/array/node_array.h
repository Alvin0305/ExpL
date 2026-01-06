#ifndef NODE_ARRAY_H
#define NODE_ARRAY_H

struct Node;

struct Node *createNewArrayNode(struct Node *idNode, struct Node *sizeNode);
struct Node *createArrayAssignNode(struct Node *idNode, struct Node *indexExprNode, struct Node *valueNode);
struct Node *createArrayAccessNode(struct Node *idNode, struct Node *indexExprNode);

#endif