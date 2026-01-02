#ifndef NODE_CONTROL_FLOW_H
#define NODE_CONTROL_FLOW_H

struct tnode;
enum NodeType;

struct tnode *createConditionNode(enum NodeType nodeType, tnode *left, tnode *right);
struct tnode *createWhileNode(tnode *conditionNode, tnode *statementsNode);
struct tnode *createIfElseNode(tnode *conditionNode, tnode *ifStatementsNode, tnode *elseStatementsNode);
struct tnode *createIfNode(tnode *conditionsNode, tnode *statementsNode);
struct tnode *createBreakNode();
struct tnode *createContinueNode();
struct tnode *createRepeatUntilNode(struct tnode *statementsNode, struct tnode *conditionNode);
struct tnode *createDoWhileNode(struct tnode *statementsNode, struct tnode *conditionNode);

#endif