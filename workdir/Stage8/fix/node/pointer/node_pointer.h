#ifndef NODE_POINTER_H
#define NODE_POINTER_H

struct Node *createDereferenceNode(struct Node *idNode);
struct Node *createAddressToNode(struct Node *idNode);
struct Node *createAssignToDereferencedNode(struct Node *idNode, struct Node *exprNode);

#endif