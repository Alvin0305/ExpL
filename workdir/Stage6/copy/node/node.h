#ifndef NODE_H
#define NODE_H

struct GSymbol;
struct LSymbol;

typedef struct tnode {
    union {
        int numVal;
        char *strVal;
    };
    int type;
    char *varName;
    int nodeType;
    struct GSymbol *gSymbolTableEntry;
    struct LSymbol *lSymbolTableEntry;
    struct TupleType *tupleType;

    struct tnode *left;
    struct tnode *right;
} tnode;


#include <stdbool.h>

#include "array/node_array.h"
#include "control_flow/node_control_flow.h"
#include "function/node_function.h"
#include "tuple/node_tuple.h"

// helpers
void print(struct tnode *root);
void print_inorder(struct tnode *root);

// methods for creating nodes
struct tnode *createEmptyNode();
struct tnode *createLeafNode(int nodeType);

struct tnode *createConstantNode(int val);
struct tnode *createStringLiteralNode(char *stringLiteral);
struct tnode *createNewVariableNode(char *varName);
struct tnode *createVariableUsageNode(char *varName);

struct tnode *createArithOpNode(int nodeType, tnode *left, tnode *right);
struct tnode *createAssignNode(tnode *left, tnode *right);

struct tnode *createIncrementNode(struct tnode *idNode);
struct tnode *createDecrementNode(struct tnode *idNode);
struct tnode *createCompoundAssignNode(int nodeType, struct tnode *idNode, struct tnode *exprNode);

struct tnode *createConnectorNode(tnode *left, tnode *right);

struct tnode *createReadNode(tnode *idNode);
struct tnode *createWriteNode(tnode *exprNode);
struct tnode *createReadToArrayNode(tnode *idNode, tnode *dimensionNode);

struct tnode *createTypeNode(int type);
struct tnode *createTupleTypeNode(struct tnode *tupleTypeNameNode);

struct tnode *createDeclarationNode(struct tnode *typeNode, struct tnode *varListNode);

struct tnode *createDereferenceNode(struct tnode *idNode);
struct tnode *createAddressToNode(struct tnode *idNode);
struct tnode *createAssignToDereferencedNode(struct tnode *idNode, struct tnode *exprNode);
struct tnode *createNewPointerNode(struct tnode *idNode);

struct tnode *createBreakPointNode();

#endif