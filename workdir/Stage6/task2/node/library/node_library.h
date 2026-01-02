#ifndef NODE_LIBRARY_H
#define NODE_LIBRARY_H

// read write
struct tnode *createReadNode(tnode *idNode);
struct tnode *createReadToArrayNode(struct tnode *idNode, struct tnode *dimensionNode);
struct tnode *createWriteNode(tnode *exprNode);

// dynamic memory allocation
struct tnode *createAllocNode(struct tnode *node);
struct tnode *createFreeNode(struct tnode *idNode);

#endif