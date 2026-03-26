#ifndef NODE_CONTROL_FLOW_H
#define NODE_CONTROL_FLOW_H

struct Node;
enum NodeType;

struct Node *createConditionNode(enum NodeType nodeType, Node *left, Node *right);
struct Node *createWhileNode(Node *conditionNode, Node *statementsNode);
struct Node *createIfElseNode(Node *conditionNode, Node *ifStatementsNode, Node *elseStatementsNode);
struct Node *createIfNode(Node *conditionsNode, Node *statementsNode);
struct Node *createBreakNode();
struct Node *createContinueNode();
struct Node *createRepeatUntilNode(struct Node *statementsNode, struct Node *conditionNode);
struct Node *createDoWhileNode(struct Node *statementsNode, struct Node *conditionNode);

#endif