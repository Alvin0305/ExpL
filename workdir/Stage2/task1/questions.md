## Build AST

- Now we add
    - variables
    - statements
        - input statment
        - output statement
        - assignment statement

- We will build the AST on the updated grammar.
- There will new nodes like:
    - connector
    - read
    - write
    - variable
    - assign

```C
typedef struct tnode {
    int val;
    int type;
    char *varName;
    int nodeType;
    struct tnode *left;
    struct tnode *right;
} tnode;
```

- varName are for variables only.
- type refers to the type of the value represented by the node
    - int
    - str
- nodeType is the type of the node
    - NODE_READ
    - NODE_WRITE ...
- val is for numerical value
