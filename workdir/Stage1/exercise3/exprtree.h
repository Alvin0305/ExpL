typedef struct tnode {
    int val;
    char *op;
    int flag;
    int regNo;
    struct tnode *left;
    struct tnode *right;
} tnode;

struct tnode *createLeafNode(int val);
struct tnode *createOperatorNode(char c, struct tnode *left, struct tnode *right);
int evaluate(struct tnode *root);
void print(struct tnode *root);
void prefix(struct tnode *root);
void postfix(struct tnode *root);