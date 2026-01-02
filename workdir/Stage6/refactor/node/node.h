#ifndef NODE_H
#define NODE_H

#include "../define/constants.h"

struct GSymbol;
struct LSymbol;
struct TupleType;
struct TypeTable;

enum NodeType;

typedef struct tnode {
    union {
        int numVal;
        char *strVal;
    };
    enum Type type;
    char *varName;
    enum NodeType nodeType;

    struct GSymbol *gSymbolTableEntry;
    struct LSymbol *lSymbolTableEntry;
    
    struct TupleType *tupleType;

    struct TypeTable *typeTableEntry;

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
struct tnode *createLeafNode(enum NodeType nodeType);

struct tnode *createConstantNode(int val);
struct tnode *createStringLiteralNode(char *stringLiteral);
struct tnode *createNewVariableNode(char *varName);
struct tnode *createVariableUsageNode(char *varName);

struct tnode *createArithOpNode(enum NodeType nodeType, tnode *left, tnode *right);
struct tnode *createAssignNode(tnode *left, tnode *right);

struct tnode *createIncrementNode(struct tnode *idNode);
struct tnode *createDecrementNode(struct tnode *idNode);
struct tnode *createCompoundAssignNode(enum NodeType nodeType, struct tnode *idNode, struct tnode *exprNode);

struct tnode *createConnectorNode(tnode *left, tnode *right);

struct tnode *createTypeNode(enum Type type);

struct tnode *createDeclarationNode(struct tnode *typeNode, struct tnode *varListNode);

struct tnode *createBreakPointNode();

struct tnode *createNullNode();

#endif