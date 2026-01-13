#include "util.h"
#include "../class_table/class_table.h"
#include "../define/constants.h"
#include "../g_symbol_table/g_symbol_table.h"
#include "../node/node.h"
#include "../type_table/type_table.h"

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

char *booleanToString(bool b) {
    if (b) {
        return "TRUE";
    } else {
        return "FALSE";
    }
}

char *dataTypeToString(enum Kind dataType) {
    switch (dataType) {
        case INT:
            return "INT";
        case STRING:
            return "STRING";
        case BOOL:
            return "BOOL";
        case TUPLE:
            return "TUPLE";
        case TYPE:
            return "TYPE";
        case VOID:
            return "VOID";
        case NULL_TYPE:
            return "NULL_TYPE";
        case CLASS:
            return "CLASS";
        default:
            return "NONE";
    }
}

char *opToString(int op) {
    switch (op) {
        case NODE_ADD:
            return "+";
        case NODE_SUB:
            return "-";
        case NODE_MUL:
            return "*";
        case NODE_DIV:
            return "/";
        case NODE_MOD:
            return "\%";
        default:
            return "UNKNOWN OP";
    }
}

void printNode(struct Node *node) {

    switch (node->nodeType) {
        case NODE_CONNECTOR:
            printf("CONNECTOR\n");
            break;

        case NODE_FUNC_CALL:
            printf("FUNC CALL\n");
            break;

        case NODE_DEREFERENCE:
            printf("*\n");
            break;

        case NODE_ADDRESS_TO:
            printf("&\n");
            break;

        case NODE_ASSIGN_TO_DEREFERENCED:
            printf("ASSIGN TO DEREFERENCE\n");
            break;

        case NODE_ASSIGN:
            printf("ASSIGN\n");
            break;

        case NODE_READ:
            printf("READ\n");
            break;

        case NODE_WRITE:
            printf("WRITE\n");
            break;

        case NODE_WHILE:
            printf("WHILE\n");
            break;

        case NODE_IF_ELSE:
            printf("IF_ELSE\n");
            break;

        case NODE_IF:
            printf("IF\n");
            break;

        case NODE_GE:
            printf(">=\n");
            break;

        case NODE_GT:
            printf(">\n");
            break;

        case NODE_LE:
            printf("<=\n");
            break;

        case NODE_LT:
            printf("<\n");
            break;

        case NODE_EQ:
            printf("==\n");
            break;

        case NODE_NE:
            printf("!=\n");
            break;

        case NODE_AND:
            printf("AND\n");
            break;

        case NODE_OR:
            printf("OR\n");
            break;

        case NODE_NOT:
            printf("NOT\n");
            break;

        case NODE_EMPTY:
            printf("EMPTY\n");
            break;

        case NODE_CONSTANT:
            printf("%d\n", node->numVal);
            break;

        case NODE_STRING_LITERAL:
            printf("%s\n", node->strVal);
            break;

        case NODE_VARIABLE:
            printf("VARIABLE: %s\n", node->varName);
            break;

        case NODE_ADD:
            printf("+\n");
            break;

        case NODE_SUB:
            printf("-\n");
            break;

        case NODE_MUL:
            printf("*\n");
            break;

        case NODE_DIV:
            printf("/\n");
            break;

        case NODE_TUPLE_ASSIGN:
            printf("TUPLE ASSIGN\n");
            break;

        case NODE_TUPLE_ACCESS:
            printf("TUPLE ACCESS\n");
            break;

        case NODE_USER_DEF_TYPE_ACCESS:
            printf("USER TYPE ACCESS\n");
            break;

        case NODE_USER_DEF_TYPE_ASSIGNMENT:
            printf("USER TYPE ASSIGNMENT\n");
            break;

        case NODE_ALLOC:
            printf("ALLOC\n");
            break;

        case NODE_FREE:
            printf("FREE\n");
            break;

        case NODE_BREAK_POINT:
            printf("BRKP\n");
            break;

        case NODE_ARRAY_ACCESS:
            printf("ARRAY ACCESS\n");
            break;

        case NODE_CLASS_FIELD_ACCESS:
            printf("CLASS FIELD ACCESS\n");
            break;

        case NODE_CLASS_METHOD_ACCESS:
            printf("CLASS METHOD ACCESS\n");
            break;

        case NODE_CLASS_FIELD_ASSIGNMENT:
            printf("CLASS FIELD ASSIGN\n");
            break;

        case NODE_RETURN:
            printf("RETURN\n");
            break;

        default:
            printf("Unhandled Node printed: %d\n", node->nodeType);
            break;
    }
}