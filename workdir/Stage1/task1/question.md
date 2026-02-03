## Build AST

```C
typedef struct tnode {
    int val;
    char *op;
    struct tnode *left;
    struct tnode *right;
} tnode;

struct tnode *createLeafNode(int val);
struct tnode *createOperatorNode(char c, struct tnode *left, struct tnode *right);
int evaluate(struct tnode *root);
void print(struct tnode *root);
```

- In this stage, we support only arithmetic expressions.
- Create the AST for the expression and print it.