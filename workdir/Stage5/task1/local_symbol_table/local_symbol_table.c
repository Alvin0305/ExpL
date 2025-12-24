#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "local_symbol_table.h"
#include "../g_symbol_table/g_symbol_table.h"
#include "../error_handler/error_handler.h"
#include "../util/util.h"

int getNextBinding(int size) {
    if (size <= 0) {
        throwError(E_INVALID_ARGUMENT, "size");
    }

    if (stackTop > STACK_END || stackTop + size - 1 > STACK_END) {
        throwError(E_STACK_MEMORY_EXHAUSTED, NULL);
    }

    int binding = stackTop;
    stackTop += size;

    return binding;
}

struct LSymbol *local_st_install(char *name, int type) {
    struct LSymbol *entry = (struct LSymbol *) malloc(sizeof(struct LSymbol));
    entry->name = (char *) malloc(strlen(name) + 1);

    strcpy(entry->name, name);
    entry->type = type;
    entry->binding = getNextBinding(getSizeOfDataType(type));
    entry->next = NULL;

    if (!local_symbol_table_head) {
        local_symbol_table_head = entry;
        return entry;
    }
    
    struct LSymbol *head = local_symbol_table_head;

    while (head->next) {
        head = head->next;
    }

    head->next = entry;
    return entry;
}

struct LSymbol *local_st_lookup(char *name) {
    struct LSymbol *head = local_symbol_table_head;

    while (head) {
        if (strcmp(name, head->name) == 0) {
            return head;
        }

        head = head->next;
    }

    return NULL;
}

void freeLocalSymbolTable() {
    struct LSymbol *head = local_symbol_table_head;

    while (head) {
        struct LSymbol *temp = head;
        head = head->next;

        free(temp);
    }

    local_symbol_table_head = NULL;
}