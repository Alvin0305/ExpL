#ifndef NODE_ARRAY_H
#define NODE_ARRAY_H

struct tnode;

struct tnode *createNewArrayNode(struct tnode *idNode, struct tnode *sizeNode);
struct tnode *createArrayAssignNode(struct tnode *idNode, struct tnode *indexExprNode, struct tnode *valueNode);
struct tnode *createArrayAccessNode(struct tnode *idNode, struct tnode *indexExprNode);

#endif