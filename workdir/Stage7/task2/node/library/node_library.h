#ifndef NODE_LIBRARY_H
#define NODE_LIBRARY_H

struct Node;
extern int lineNumber;

// read write
struct Node *createReadNode(Node *idNode);
struct Node *createReadToArrayNode(struct Node *idNode, struct Node *dimensionNode);
struct Node *createWriteNode(Node *exprNode);

// dynamic memory allocation
struct Node *createInitNode();
struct Node *createAllocNode(struct Node *node);
struct Node *createFreeNode(struct Node *idNode);

#endif