typedef struct tnode {
    int val;
    int type;
    char *varName;
    int nodeType;
    struct tnode *left;
    struct tnode *right;
} tnode;

void print(struct tnode *root);

struct tnode *createTreeNode(int val, int type, char *varName, struct tnode *left, struct tnode *right);

struct tnode *createEmptyNode();
struct tnode *createConstantNode(int val, int type);
struct tnode *createVariableNode(char *varName, int type);
struct tnode *createArithOpNode(int nodeType, tnode *left, tnode *right);
struct tnode *createAssignNode(tnode *left, tnode *right);
struct tnode *createConnectorNode(tnode *left, tnode *right);
struct tnode *createReadNode(tnode *idNode);
struct tnode *createWriteNode(tnode *writeNode);