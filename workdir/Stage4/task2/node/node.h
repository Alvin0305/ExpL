#ifndef NODE_H
#define NODE_H

struct GSymbol;

typedef struct tnode {
    union {
        int numVal;
        char *strVal;
    };
    int type;
    char *varName;
    int nodeType;
    struct GSymbol *gSymbolTableEntry;
    struct tnode *left;
    struct tnode *right;
} tnode;

// helpers
void print(struct tnode *root);
void print_inorder(struct tnode *root);

// not used
struct tnode *createTreeNode(int val, int type, char *varName, struct tnode *left, struct tnode *right);

// methods for creating nodes
struct tnode *createEmptyNode();

struct tnode *createConstantNode(int val);
struct tnode *createStringLiteralNode(char *stringLiteral);
struct tnode *createNewVariableNode(char *varName);
struct tnode *createVariableUsageNode(char *varName);

struct tnode *createNewArrayNode(struct tnode *varListNode, struct tnode *idNode, struct tnode *sizeNode);
struct tnode *createArrayAssignNode(struct tnode *idNode, struct tnode *indexExprNode, struct tnode *valueNode);
struct tnode *createArrayAccessNode(struct tnode *idNode, struct tnode *indexExprNode);

struct tnode *createArithOpNode(int nodeType, tnode *left, tnode *right);
struct tnode *createAssignNode(tnode *left, tnode *right);

struct tnode *createConnectorNode(tnode *left, tnode *right);

struct tnode *createReadNode(tnode *idNode);
struct tnode *createWriteNode(tnode *exprNode);

struct tnode *createConditionNode(int nodeType, tnode *left, tnode *right);
struct tnode *createWhileNode(tnode *conditionNode, tnode *statementsNode);
struct tnode *createIfElseNode(tnode *conditionNode, tnode *ifStatementsNode, tnode *elseStatementsNode);
struct tnode *createIfNode(tnode *conditionsNode, tnode *statementsNode);
struct tnode *createBreakNode();
struct tnode *createContinueNode();
struct tnode *createRepeatUntilNode(struct tnode *statementsNode, struct tnode *conditionNode);
struct tnode *createDoWhileNode(struct tnode *statementsNode, struct tnode *conditionNode);

struct tnode *createTypeNode(int type);
struct tnode *createDeclarationNode(struct tnode *typeNode, struct tnode *varListNode);

#endif