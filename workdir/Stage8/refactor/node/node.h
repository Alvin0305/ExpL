#ifndef NODE_H
#define NODE_H

#include "../type_info/type_info.h"

struct GSymbol;
struct LSymbol;
struct TupleType;
struct TypeTable;
struct ClassTable;

enum NodeType {
    NODE_EMPTY,
    NODE_ASSIGN,
    NODE_CONNECTOR,

    NODE_FUNC_CALL,
    NODE_RETURN,

    NODE_NULL,

    NODE_CLASS_FIELD_ACCESS,
    NODE_CLASS_METHOD_ACCESS,
    NODE_CLASS_FIELD_ASSIGNMENT,
    NODE_NEW,

    NODE_INIT,
    NODE_ALLOC,
    NODE_ALLOC_ARRAY,
    NODE_FREE,

    NODE_TUPLE_ACCESS,
    NODE_TUPLE_POINTER_ACCESS,
    NODE_TUPLE_ASSIGN,
    NODE_TUPLE_POINTER_ASSIGN,

    NODE_USER_DEF_TYPE_ACCESS,
    NODE_USER_DEF_TYPE_ASSIGNMENT,

    NODE_BREAK_POINT,

    NODE_VARIABLE,
    NODE_CONSTANT,
    NODE_STRING_LITERAL,

    NODE_ARRAY_ASSIGN,
    NODE_ARRAY_ACCESS,

    NODE_DEREFERENCE,
    NODE_ADDRESS_TO,
    NODE_ASSIGN_TO_DEREFERENCED,

    NODE_INC,
    NODE_DEC,

    NODE_READ,
    NODE_READ_TO_ARRAY,
    NODE_READ_TO_MEMBER,
    NODE_WRITE,

    NODE_GT,
    NODE_GE,
    NODE_EQ,
    NODE_NE,
    NODE_LE,
    NODE_LT,

    NODE_OR,
    NODE_AND,
    NODE_NOT,

    NODE_WHILE,
    NODE_BREAK,
    NODE_CONTINUE,
    NODE_REPEAT_UNTIL,
    NODE_DO_WHILE,

    NODE_IF_ELSE,
    NODE_IF,

    NODE_ADD,
    NODE_SUB,
    NODE_MUL,
    NODE_DIV,
    NODE_MOD
};

typedef struct Node {
    union {
        int numVal;
        char *strVal;
    };
    enum Kind type;
    char *varName;
    enum NodeType nodeType;

    struct GSymbol *gSymbolTableEntry;
    struct LSymbol *lSymbolTableEntry;
    
    struct TypeInfo *typeInfo;

    struct Node *left;
    struct Node *right;
} Node;


#include <stdbool.h>

#include "array/node_array.h"
#include "control_flow/node_control_flow.h"
#include "function/node_function.h"
#include "tuple/node_tuple.h"

// helpers
void print(struct Node *root);
void print_inorder(struct Node *root);

// methods for creating nodes
struct Node *createEmptyNode();
struct Node *createLeafNode(enum NodeType nodeType);

struct Node *createConstantNode(int val);
struct Node *createStringLiteralNode(char *stringLiteral);
struct Node *createNewVariableNode(char *varName);
struct Node *createVariableUsageNode(char *varName);

struct Node *createArithOpNode(enum NodeType nodeType, Node *left, Node *right);
struct Node *createAssignNode(Node *left, Node *right);

struct Node *createIncrementNode(struct Node *idNode);
struct Node *createDecrementNode(struct Node *idNode);
struct Node *createCompoundAssignNode(enum NodeType nodeType, struct Node *idNode, struct Node *exprNode);

struct Node *createConnectorNode(Node *left, Node *right);

struct Node *createBreakPointNode();

struct Node *createNullNode();

struct Node *createNewNode(struct Node *varNameNode, struct Node *classNameNode);

#endif