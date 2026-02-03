### Here we will be implementing GST and its methods

```C++
typedef struct GSymbol {
    char *name;
    int type;
    int size;
    int binding;
    struct GSymbol *next;
} GSymbol;

struct GSymbol *lookupGST(char *name);
struct GSymbol *install(char *name, int type, int size);

void printGSymbolTable();
void populateGST(struct tnode *node);
```

- We implements these methods and populates the GST based on user given code
- GST will be a linked list
- installing to GST checks whether a variable is redeclared
- In this stage we just populate and print the GST, no code generation