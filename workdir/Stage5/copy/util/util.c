#include "../define/constants.h"
#include "../node/node.h"

#include <stdio.h>
#include <stdbool.h>

char *booleanToString(bool b) {
    if (b) {
        return "TRUE";
    } else {
        return "FALSE";
    }
}

char *dataTypeToString(int dataType) {
    switch (dataType) {
        case INT:
            return "INT";
        case STRING:
            return "STRING";
        case BOOL:
            return "BOOL";
        case TUPLE:
            return "TUPLE";
        default:
            return "NONE";
    }
}

int getSizeOfDataType(int dataType) {
    switch (dataType) {
        case INT:
            return INT_SIZE;
        case STRING:
            return STRING_SIZE;
        case TUPLE:
            printf("[COMPILER ERROR]: tuple size cannot be found by this function\n");
            return NONE_SIZE;
        default:
            return NONE_SIZE;
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

void printNode(struct tnode *node) {

    switch(node->nodeType) {
        case NODE_CONNECTOR:
            printf("CONNECTOR\n");
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

        case NODE_DECL:
            printf("DECL\n");
            break;

        case NODE_TYPE:
            printf("%s\n", dataTypeToString(node->type));
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

        case NODE_FUNC_DECL:
            printf("FUNC DECL\n");
            break;

        case NODE_PARAM:
            printf("PARAM\n");
            break;

        case NODE_LOCAL_DECL:
            printf("LOCAL DECL\n");
            break;

        case NODE_POINTER_PARAM:
            printf("POINTER PARAM\n");
            break;

        case NODE_TUPLE_DECL:
            printf("TUPLE DECL\n");
            break;

        case NODE_TUPLE_ASSIGN:
            printf("TUPLE ASSIGN\n");
            break;

        case NODE_TUPLE_ACCESS:
            printf("TUPLE ACCESS\n");
            break;

        default:
            printf("Unhandled Node printed: %d\n", node->nodeType);
            break;
    }
}