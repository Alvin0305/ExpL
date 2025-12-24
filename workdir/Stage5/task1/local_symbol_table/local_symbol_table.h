#ifndef LOCAL_SYMBOL_TABLE_H
#define LOCAL_SYMBOL_TABLE_H

typedef struct LSymbol {
    char *name;
    int type;
    int binding;
    struct LSymbol *next;
} LSymbol;

extern struct LSymbol *local_symbol_table_head;

struct LSymbol *local_st_install(char *name, int type);
struct LSymbol *local_st_lookup(char *name);

#endif