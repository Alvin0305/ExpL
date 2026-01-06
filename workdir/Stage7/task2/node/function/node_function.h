#ifndef NODE_FUNCTION_H
#define NODE_FUNCTION_H

struct Node;

struct Node *createFunctionDeclarationNode(struct Node *functionNameNode, struct Node *paramListNode);
struct Node *createParamNode(struct Node *typeNode, struct Node *idNode, bool addToLocalSymbolTable, bool isPtr);

struct Node *createFunctionDefinitionNode(struct Node *returnTypeNode, struct Node *functionNameNode, struct Node *paramListNode,
                                          struct Node *localDeclarationsNode, struct Node *functionBodyNode);

struct Node *createFunctionCallNode(struct Node *functionNameNode, struct Node *argListNode);
struct Node *createReturnNode(struct Node *exprNode);

#endif