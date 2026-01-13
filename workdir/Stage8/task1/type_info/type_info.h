#ifndef TYPE_INFO_H
#define TYPE_INFO_H

#include "../define/constants.h"
#include <stdbool.h>

struct TupleType;
struct TypeTable;
struct ClassTable;
struct Dimension;

enum Kind { INT, STRING, BOOL, TUPLE, VOID, TYPE, NONE, NULL_TYPE, CLASS, UNKNOWN };
enum Size {
    INT_SIZE = 1,
    STRING_SIZE = 1,
    NONE_SIZE = 0,
    VOID_SIZE = 0,
    TUPLE_PTR_SIZE = 1,
    UDT_PTR_SIZE = 1,
    CLASS_PTR_SIZE = 1
};

typedef struct TypeInfo {
    enum Kind kind;
    struct TupleType *tupleType;
    struct TypeTable *type;
    struct ClassTable *_class;
} TypeInfo;

struct TypeInfo *createTypeInfo(enum Kind kind, struct TupleType *tupleType, struct TypeTable *type, struct ClassTable *_class);

bool isTypeCompatible(struct TypeInfo *leftType, struct TypeInfo *rightType);
int sizeOfTypeOnStack(struct TypeInfo *typeInfo, struct Dimension *dimensions, bool isPtr, bool isFunction);
int typeTableEntryToType(struct TypeTable *type);

#endif