#ifndef NODE_TUPLE_H
#define NODE_TUPLE_H

struct tnode;

struct tnode *createTupleTypeNode(struct tnode *tupleTypeName);

struct tnode *createGlobalTupleTypeDeclarationNode(struct tnode *idNode, struct tnode *paramListNode, struct tnode *idListNode);
struct tnode *createLocalTupleTypeDeclarationNode(struct tnode *idNode, struct tnode *paramListNode, struct tnode *idListNode);

struct tnode *createTupleAccessNode(struct tnode *idNode, struct tnode *fieldNode);
struct tnode *createTupleAssignmentNode(struct tnode *idNode, struct tnode *fieldNode, struct tnode *exprNode);

struct tnode *createTuplePointerAccessNode(struct tnode *idNode, struct tnode *fieldNode);
struct tnode *createTuplePointerAssignmentNode(struct tnode *idNode, struct tnode *fieldNode, struct tnode *exprNode);

#endif