#ifndef NODE_MEMBER_ACCESS_H
#define NODE_MEMBER_ACCESS_H

enum AccessType { ACCESS_DOT, ACCESS_ARROW };
typedef enum AccessType AccessType;

extern int lineNumber;

struct Node *createMemberAssignmentNode(struct Node *fieldAccess, struct Node *exprNode);
struct Node *createMemberAccessNode(struct Node *baseExprNode, struct Node *memberIdNode, enum AccessType accessType,
                                    bool isMethodCall, struct Node *argList);

#endif