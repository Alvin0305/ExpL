### Add tuples

- Change the grammar to support tuple declaration and access
- Create compile time data structures like Tuple, TupleField and TupleFieldInfo for maintaining the tupletype
```C
typedef struct Tuple {
    char *name;
    int size;
    int n;
    struct TupleField *fields;
} Tuple;

typedef struct TupleField {
    int type;
    int size;
    char *name;
    struct TupleField *next;
} TupleField;

typedef struct TupleFieldInfo {
    int type;
    char *name;
} TupleFieldInfo;
```
- Add methods to tuples for populating and accessing the tuple table
- Parse the declarations and populate them to the tuple table
- While installing them to local or global symbol table:
    - Set the binding like we did before
    - But update the `localBinding` or `stackTop` variable as `localBinding += tuple.size` or `stackTop += tuple.size`
- After installing the tuple types in tuple table, we need to parse the rest of the code and check semantics
- Check whether a non existing field is being accessed from a tuple
- And on accessing a tuple field, we need to offset the fields index from the base address of the tuple variable which can be found by using the local or global table entry's binding + the offset of the tuple field
