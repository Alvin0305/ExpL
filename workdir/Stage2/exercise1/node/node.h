#ifndef NODE_H
#define NODE_H

typedef struct tnode {
    int val;
    int type;
    char *varName;
    int nodeType;
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
struct tnode *createConstantNode(int val, int type);
struct tnode *createVariableNode(char *varName, int type);
struct tnode *createArithOpNode(int nodeType, tnode *left, tnode *right);
struct tnode *createAssignNode(tnode *left, tnode *right);
struct tnode *createConnectorNode(tnode *left, tnode *right);
struct tnode *createReadNode(tnode *idNode);
struct tnode *createWriteNode(tnode *writeNode);

#endif