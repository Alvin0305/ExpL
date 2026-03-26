#ifndef NODE_TUPLE_H
#define NODE_TUPLE_H

struct Node;
extern int lineNumber;

struct Node *createTupleAccessNode(struct Node *idNode, struct Node *fieldNode);
struct Node *createTupleAssignmentNode(struct Node *idNode, struct Node *fieldNode, struct Node *exprNode);

struct Node *createTuplePointerAccessNode(struct Node *idNode, struct Node *fieldNode);
struct Node *createTuplePointerAssignmentNode(struct Node *idNode, struct Node *fieldNode, struct Node *exprNode);

#endif