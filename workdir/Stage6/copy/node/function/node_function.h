#ifndef NODE_FUNCTION_H
#define NODE_FUNCTION_H

struct tnode;

struct tnode *createFunctionDeclarationNode(struct tnode *functionNameNode, struct tnode *paramListNode);
struct tnode *createParamNode(struct tnode *typeNode, struct tnode *idNode, bool addToLocalSymbolTable, bool isPtr);

struct tnode *createFunctionDefinitionNode(struct tnode *returnTypeNode, struct tnode *functionNameNode, struct tnode *paramListNode,
                                           struct tnode *localDeclarationsNode, struct tnode *functionBodyNode);

struct tnode *createFunctionCallNode(struct tnode *functionNameNode, struct tnode *argListNode);
struct tnode *createReturnNode(struct tnode *exprNode);

#endif