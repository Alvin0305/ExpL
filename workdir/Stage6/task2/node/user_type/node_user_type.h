#ifndef NODE_USER_TYPE_H
#define NODE_USER_TYPE_H

typedef enum {
    ACCESS_DOT,
    ACCESS_ARROW
} AccessType;

struct tnode *createUserTypeNode(struct tnode *typeNameNode);
struct tnode *createMemberAssignmentNode(struct tnode *fieldAccess, struct tnode *exprNode);
struct tnode *createMemberAccessNode(struct tnode *field1Node, struct tnode *field2Node, AccessType accessType);

#endif