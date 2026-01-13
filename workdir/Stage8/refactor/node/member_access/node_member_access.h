#ifndef NODE_MEMBER_ACCESS_H
#define NODE_MEMBER_ACCESS_H

typedef enum { ACCESS_DOT, ACCESS_ARROW } AccessType;

extern int lineNumber;

struct Node *createMemberAssignmentNode(struct Node *fieldAccess, struct Node *exprNode);
struct Node *createMemberAccessNode(struct Node *baseExprNode, struct Node *memberIdNode, AccessType accessType,
                                    bool isMethodCall, struct Node *argList);

#endif