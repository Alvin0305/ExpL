#ifndef NODE_POINTER_H
#define NODE_POINTER_H

struct tnode *createNewPointerNode(struct tnode *idNode);
struct tnode *createDereferenceNode(struct tnode *idNode);
struct tnode *createAddressToNode(struct tnode *idNode);
struct tnode *createAssignToDereferencedNode(struct tnode *idNode, struct tnode *exprNode);

#endif