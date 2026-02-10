### Support Pointers as arguments

- add the isPtr attribute to the LocalSymbol struct so that we can handle pointers also

```C
typedef struct LSymbol {
    char *name;
    int type;
    int binding;
    struct LSymbol *next;
    bool isPtr;
} LSymbol;
```

