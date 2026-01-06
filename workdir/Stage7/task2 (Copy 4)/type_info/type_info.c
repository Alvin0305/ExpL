#include "type_info.h"
#include "../class_table/class_table.h"
#include "../define/constants.h"
#include "../g_symbol_table/g_symbol_table.h"
#include "../tuple_type_table/tuple_type_table.h"
#include "../type_info/dimension.h"
#include "../type_table/type_table.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TypeInfo *createTypeInfo(enum Kind kind, struct TupleType *tupleType, struct TypeTable *type, struct ClassTable *_class) {
    struct TypeInfo *typeInfo = (struct TypeInfo *)malloc(sizeof(struct TypeInfo));

    if (kind == UNKNOWN) {
        kind = _class ? CLASS : type ? TYPE : NONE;
    }
    // printf("creating type: %s %p %p %p [%d]\n", dataTypeToString(kind), tupleType, type, _class, lineNumber);

    typeInfo->kind = kind;
    typeInfo->type = type;
    typeInfo->tupleType = tupleType;
    typeInfo->_class = _class;

    return typeInfo;
}

bool isTypeCompatible(struct TypeInfo *leftType, struct TypeInfo *rightType) {
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

int sizeOfTypeOnStack(struct TypeInfo *typeInfo, struct Dimension *dimensions, bool isPtr, bool isFunction) {
    if (isFunction) return 0;

    int baseSize;
    switch (typeInfo->kind) {
        case CLASS:
            baseSize = 1;
            break;
        case TYPE:
            baseSize = 1;
            break;
        case TUPLE:
            baseSize = isPtr ? 1 : typeInfo->tupleType->size;
            break;
        case INT:
            baseSize = INT_SIZE;
            break;
        case STRING:
            baseSize = STRING_SIZE;
            break;
        case NONE:
            baseSize = NONE_SIZE;
            break;
        case NULL_TYPE:
            baseSize = NONE_SIZE;
            break;
        default:
            printf("[WARNING]: Unknown type given to calculate size\n");
            baseSize = NONE_SIZE;
            break;
    }

    if (dimensions) {
        baseSize *= getDimensionProduct(dimensions);
    }

    return baseSize;
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
