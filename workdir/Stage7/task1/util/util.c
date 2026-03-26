#include "util.h"
#include "../class_table/class_table.h"
#include "../define/constants.h"
#include "../g_symbol_table/g_symbol_table.h"
#include "../node/node.h"
#include "../type_table/type_table.h"

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int calcSizeOfType(struct TupleType *tupleType, struct TypeTable *type, struct ClassTable *_class, struct Dimension *dimensions,
                   bool isFunction) {
    int baseSize;
    if (tupleType) {
        baseSize = tupleType->size;
    } else if (type) {
        baseSize = 1;
    } else if (_class) {
        baseSize = 1;
    } else if (isFunction) {
        baseSize = 0;
    } else {
        printf("[WARNING]: Unhandled type.\n");
    }

    if (dimensions) {
        baseSize *= getDimensionProduct(dimensions);
    }

    return baseSize;
}

bool isTypeCompatible(enum Type leftType, enum Type rightType) {
    if (leftType == TYPE && rightType == NULL_TYPE) {
        return true;
    } else if (leftType == CLASS && rightType == NULL_TYPE) {
        return true;
    } else {
        return leftType == rightType;
    }
}

bool areTypeCompatible(struct TypeInfo *leftType, struct TypeInfo *rightType) {
    if (leftType->kind == TYPE && rightType->kind == NULL_TYPE) return true;
    if (leftType->kind == CLASS && rightType->kind == NULL_TYPE) return true;
    if (leftType->kind != rightType->kind) return false;
    
    if (leftType->kind == TUPLE) {
        return (strcmp(leftType->tupleType->name, rightType->tupleType->name) == 0);
    }
    if (leftType->kind == CLASS) {
        return (strcmp(leftType->_class->name, rightType->_class->name) == 0);
    }

    return (strcmp(leftType->type->name, rightType->type->name) == 0);
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

int typeTableEntryToType(struct TypeTable *type) {
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
        return TYPE;
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
        case TYPE:
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

    switch (node->nodeType) {
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

        default:
            printf("Unhandled Node printed: %d\n", node->nodeType);
            break;
    }
}