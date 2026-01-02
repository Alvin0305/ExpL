#include "../define/constants.h"
#include "../node/node.h"
#include "../type_table/type_table.h"

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isTypeCompatible(enum Type leftType, enum Type rightType) {
    if (leftType == USER_TYPE && rightType == NULL_TYPE) {
        return true;
    } else {
        return leftType == rightType;
    }
}

bool areSameUserType(struct TypeTable *leftType, struct TypeTable *rightType) {
    return (strcmp(leftType->name, rightType->name) == 0);
}

char *booleanToString(bool b) {
    if (b) {
        return "TRUE";
    } else {
        return "FALSE";
    }
}

char *dataTypeToString(enum Type dataType) {
    switch (dataType) {
        case INT:
            return "INT";
        case STRING:
            return "STRING";
        case BOOL:
            return "BOOL";
        case TUPLE:
            return "TUPLE";
        case USER_TYPE:
            return "USER TYPE";
        case VOID:
            return "VOID";
        default:
            return "NONE";
    }
}

int typeTableEntryToType(struct TypeTable *type) {
    // printf("got %s\n", type->name);
    if (strcmp(type->name, "INT") == 0) {
        return INT;
    } else if (strcmp(type->name, "STRING") == 0) {
        return STRING;
    } else if (strcmp(type->name, "VOID") == 0) {
        return VOID;
    } else if (strcmp(type->name, "BOOL") == 0) {
        return BOOL;
    } else if (strcmp(type->name, "TUPLE") == 0) {
        return TUPLE;
    } else if (strcmp(type->name, "NONE") == 0) {
        return NONE;
    } else if (strcmp(type->name, "NULL_TYPE") == 0) {
        return NULL_TYPE;
    } else {
        return USER_TYPE;
    }
}

int getSizeOfDataType(enum Type dataType) {
    switch (dataType) {
        case INT:
            return INT_SIZE;
        case STRING:
            return STRING_SIZE;
        case TUPLE:
            printf("[COMPILER ERROR]: tuple size cannot be found by this function\n");
            return NONE_SIZE;
        case USER_TYPE:
            printf("[COMPILER ERROR]: user defined type size cannot be found by this function\n");
            return NONE_SIZE;
        default:
            printf("[COMPILER ERROR]: unhandled type given for calculating size\n");
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

        case NODE_USER_DEF_TYPE_ACCESS:
            printf("USER TYPE ACCESS\n");
            break;

        case NODE_USER_DEF_TYPE_ASSIGNMENT:
            printf("USER TYPE ASSIGNMENT\n");
            break;

        case NODE_USER_DEF_TYPE_PARAM:
            printf("USER TYPE PARAM\n");
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

        default:
            printf("Unhandled Node printed: %d\n", node->nodeType);
            break;
    }
}