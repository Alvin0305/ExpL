#include "g_symbol_table.h"
#include "../define/constants.h"
#include "../error_handler/error_handler.h"
#include "../label/label.h"
#include "../type_table/type_table.h"
#include "../util/util.h"
#include "param_list.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int stackTop = STACK_START;

static struct GSymbol *GSTHead;
static struct TupleType *currentTupleType = NULL;
static struct TypeTable *currentType = NULL;

// -------------- helper definitions -----------------

static struct GSymbol *createSymbolTableEntry(char *name, enum Type type, int size, bool isPtr, int functionLabel, bool isArray,
                                              struct TupleType *tupleType, struct TypeTable *typeTableEntry) {
    struct GSymbol *entry = (struct GSymbol *)malloc(sizeof(struct GSymbol));

    entry->name = strdup(name);
    entry->type = type;
    entry->size = functionLabel == NO_LABEL ? size : 0;
    entry->binding = stackTop;
    entry->next = NULL;
    entry->dimensions = NULL;
    entry->numDimensions = 0;
    entry->isPtr = type == USER_TYPE ? true : isPtr;
    entry->functionLabel = functionLabel;

    entry->paramList = NULL;
    entry->tupleType = tupleType;
    entry->typeTableEntry = typeTableEntry;

    if (functionLabel != NO_LABEL) {

    } else if (isArray) {
        stackTop += size;
    } else if (type == USER_TYPE) {
        stackTop += 1;
    } else {
        stackTop += size;
    }

    if (stackTop >= STACK_END) {
        compilerError(E_STACK_MEMORY_EXHAUSTED);
    }

    return entry;
}

static int computeDimensionProduct(struct tnode *dimensionDeclNode, int *dimensionCount) {
    if (!dimensionDeclNode) return 1;

    if (dimensionDeclNode->nodeType == NODE_CONSTANT) {
        (*dimensionCount)++;
        return dimensionDeclNode->numVal;
    }

    return computeDimensionProduct(dimensionDeclNode->left, dimensionCount) *
           computeDimensionProduct(dimensionDeclNode->right, dimensionCount);
}

static int computerArraySize(struct tnode *dimensionDeclNode, int *dimensionCount) {
    return computeDimensionProduct(dimensionDeclNode, dimensionCount) * currentType->size;
}

static void extractArrayDimensions(struct GSymbol *entry, struct tnode *dimensionDeclNode) {
    if (!dimensionDeclNode) return;

    if (dimensionDeclNode->nodeType == NODE_CONSTANT) {
        entry->dimensions[entry->numDimensions++] = dimensionDeclNode->numVal;
        return;
    }

    extractArrayDimensions(entry, dimensionDeclNode->left);
    extractArrayDimensions(entry, dimensionDeclNode->right);
}

static void addParamsToFunction(struct GSymbol *entry, struct tnode *paramListNode) {
    if (!paramListNode) return;

    struct tnode *typeNode;
    struct tnode *paramIdNode;
    struct TupleType *tupleType;
    struct TypeTable *typeTableEntry;

    switch (paramListNode->nodeType) {
        case NODE_CONNECTOR:
            addParamsToFunction(entry, paramListNode->left);
            addParamsToFunction(entry, paramListNode->right);
            break;

        case NODE_PARAM:
        case NODE_TUPLE_PARAM:
            typeNode = paramListNode->left;
            paramIdNode = paramListNode->right;
            tupleType = typeNode->tupleType;
            typeTableEntry = typeNode->typeTableEntry;
            addParam(entry, paramIdNode->varName, typeNode->type, false, tupleType, typeTableEntry);
            break;

        case NODE_POINTER_PARAM:
        case NODE_TUPLE_POINTER_PARAM:
        case NODE_USER_DEF_TYPE_PARAM:
            typeNode = paramListNode->left;
            paramIdNode = paramListNode->right;
            tupleType = typeNode->tupleType;
            typeTableEntry = typeNode->typeTableEntry;
            addParam(entry, paramIdNode->varName, typeNode->type, true, tupleType, typeTableEntry);
            break;

        default:
            printf("[WARNING]: Unknown node while adding params to function\n");
            printNode(paramListNode);
    }
}

static void populateGST(struct tnode *root) {
    if (!root) return;

    struct GSymbol *entry;
    struct tnode *idNode;
    int size;

    switch (root->nodeType) {
        case NODE_CONNECTOR:
        case NODE_DECL:
            populateGST(root->left);
            populateGST(root->right);
            break;

        case NODE_TYPE:
            if (root->type == TUPLE) {
                currentTupleType = root->tupleType;
                currentType = lookupTT(currentTupleType->name);
            } else if (root->type == USER_TYPE) {
                currentTupleType = NULL;
                currentType = root->typeTableEntry;
            } else {
                currentTupleType = NULL;
                currentType = root->typeTableEntry;
            }
            break;

        case NODE_VARIABLE:
            if (currentType->kind == VOID) {
                compilerError(E_VARIABLE_WITH_TYPE_VOID, root->varName);
            }

            size = currentType->size;
            entry = installGST(root->varName, currentType->kind, size, currentTupleType, currentType, NO_LABEL, false, false);
            break;

        case NODE_DEREFERENCE:
            idNode = root->left;
            if (currentType->kind == VOID) {
                compilerError(E_VARIABLE_WITH_TYPE_VOID, idNode->varName);
            }

            size = currentType->size;
            entry = installGST(idNode->varName, currentType->kind, size, currentTupleType, currentType, NO_LABEL, false, true);
            break;

        case NODE_ARRAY_DECL:
            int dimensionCount = 0;
            idNode = root->left;
            if (currentType->kind == VOID) {
                compilerError(E_VARIABLE_WITH_TYPE_VOID, idNode->varName);
            }

            entry = installGST(idNode->varName, currentType->kind, computerArraySize(root->right, &dimensionCount), NULL,
                               currentType, NO_LABEL, true, true);

            entry->dimensions = (int *)malloc(dimensionCount * sizeof(int));
            extractArrayDimensions(entry, root->right);
            break;

        case NODE_FUNC_DECL:
            idNode = root->left;
            struct tnode *paramListNode = root->right;

            struct GSymbol *alreadyExisting = lookupGST(idNode->varName);
            if (alreadyExisting != NULL) {
                compilerError(E_FUNCTION_REDECLARATION, idNode->varName);
            }

            entry = installGST(idNode->varName, currentType->kind, getSizeOfDataType(currentType->kind), currentTupleType,
                               currentType, createNewLabel(), false, false);
            addParamsToFunction(entry, paramListNode);
            break;

        case NODE_TUPLE_DECL:
            idNode = root->left;
            struct tnode *fieldList = root->right->left;
            struct tnode *idList = root->right->right;

            struct TupleType *tupleType = createTupleTypeFromNode(idNode->varName, fieldList);
            currentTupleType = tupleType;

            populateGST(idList);
            break;

        default:
            printf("[WARNING]: Unhandled node while populating global symbol table: ");
            printNode(root);
            break;
    }
}

static bool checkParamsForFunction(struct tnode *node, struct Param **param, char *functionName) {
    if (!node) return true;

    bool leftOK, rightOK;
    struct tnode *typeNode, *idNode;
    bool typeMatch, nameMatch;

    switch (node->nodeType) {
        case NODE_CONNECTOR:
            leftOK = checkParamsForFunction(node->left, param, functionName);
            rightOK = checkParamsForFunction(node->right, param, functionName);
            return leftOK && rightOK;

        case NODE_PARAM:
        case NODE_POINTER_PARAM:
            if (!*param) compilerError(E_FUNCTION_SIGNATURE_MORE_ARG, functionName);

            typeNode = node->left;
            idNode = node->right;
            typeMatch = areTypeCompatible(typeNode->typeTableEntry, (*param)->typeTableEntry);
            nameMatch = (strcmp(idNode->varName, (*param)->name) == 0);

            if (!typeMatch) {
                compilerError(E_FUNCTION_SIGNATURE_TYPE_MISMATCH, functionName, idNode->varName, (*param)->type, typeNode->type);
            } else if (!nameMatch) {
                compilerError(E_FUNCTION_SIGNATURE_VARNAME_MISMATCH, functionName, (*param)->type, idNode->varName);
            }

            (*param) = (*param)->next;
            break;

        case NODE_TUPLE_PARAM:
        case NODE_TUPLE_POINTER_PARAM:
            if (!*param) compilerError(E_FUNCTION_SIGNATURE_MORE_ARG, functionName);

            typeNode = node->left;
            idNode = node->right;

            typeMatch = areTypeCompatible(typeNode->typeTableEntry, (*param)->typeTableEntry);
            nameMatch = (strcmp(idNode->varName, (*param)->name) == 0);

            if (!typeMatch) {
                compilerError(E_FUNCTION_SIGNATURE_TYPE_MISMATCH, functionName, idNode->varName, (*param)->type, TUPLE);
            } else if (!nameMatch) {
                compilerError(E_FUNCTION_SIGNATURE_VARNAME_MISMATCH, functionName, (*param)->name, idNode->varName);
            }

            (*param) = (*param)->next;
            break;

        case NODE_USER_DEF_TYPE_PARAM:
            if (!*param) {
                compilerError(E_FUNCTION_SIGNATURE_MORE_ARG, functionName);
            }

            typeNode = node->left;
            idNode = node->right;

            typeMatch = areTypeCompatible(typeNode->typeTableEntry, (*param)->typeTableEntry);
            nameMatch = (strcmp(idNode->varName, (*param)->name) == 0);

            if (!typeMatch) {
                compilerError(E_FUNCTION_SIGNATURE_TYPE_MISMATCH, functionName, idNode->varName, (*param)->type, USER_TYPE);
            } else if (!nameMatch) {
                compilerError(E_FUNCTION_SIGNATURE_VARNAME_MISMATCH, functionName, (*param)->name, idNode->varName);
            }

            (*param) = (*param)->next;
            break;

        default:
            printf("[WARNING]: Unhandled node while checking params for function: ");
            printNode(node);
            break;
    }

    return true;
}

// ------------------ core methods --------------------

struct GSymbol *lookupGST(char *name) {
    struct GSymbol *head = GSTHead;

    while (head) {
        if (strcmp(head->name, name) == 0) {
            return head;
        }
        head = head->next;
    }

    return NULL;
}

struct GSymbol *installGST(char *name, enum Type type, int size, struct TupleType *tupleType, struct TypeTable *typeTableEntry,
                           int functionLabel, bool isArray, bool isPtr) {
    struct GSymbol *head = GSTHead;

    // printf("installing %s with type %s size: %d: %s\n", name, typeTableEntry->name, size, booleanToString(isPtr));

    if (lookupGST(name)) {
        compilerError(E_VARIABLE_REDECLARATION, name);
    }

    struct GSymbol *newEntry =
        createSymbolTableEntry(name, typeTableEntry->kind, size, isPtr, functionLabel, isArray, tupleType, typeTableEntry);

    if (!GSTHead) {
        GSTHead = newEntry;
    } else {
        head = GSTHead;
        while (head->next)
            head = head->next;
        head->next = newEntry;
    }

    return newEntry;
}

void printGST() {
    struct GSymbol *head = GSTHead;
    printf("\n-------------[SYMBOL TABLE]--------------\n");
    printf("[VarName][DataType][Size][Binding][isPtr]\n");
    while (head) {
        printf("%s [%s] %d %d %s", head->name, head->typeTableEntry->name, head->size, head->binding,
               booleanToString(head->isPtr));
        if (head->dimensions) {
            printf(" %d: ", head->numDimensions);
            printDimensions(head);
        } else {
            printf("\n");
            printParamList(head->paramList);
        }

        if (head->type == TUPLE) {
            printTupleType(head->tupleType);
        }
        head = head->next;
    }

    printf("\n");
}

void printDimensions(struct GSymbol *entry) {
    for (int i = 0; i < entry->numDimensions; i++) {
        printf("%d,", entry->dimensions[i]);
    }
    printf("\n");
}

void addToGST(struct tnode *typeNode, struct tnode *varListNode) {
    currentTupleType = typeNode->tupleType;
    currentType = typeNode->typeTableEntry;

    populateGST(varListNode);
}

void addNewTupleTypeToGST(struct tnode *idNode, struct tnode *tupleFieldNode, struct tnode *idListNode) {
    struct TupleType *alreadyExisting = lookupTupleTypeTable(idNode->varName);
    if (alreadyExisting) {
        compilerError(E_TUPLE_TYPE_REDECLARATION, idNode->varName);
    }

    currentTupleType = createTupleTypeFromNode(idNode->varName, tupleFieldNode);

    createNewTypeForTuple(currentTupleType);
    currentType = lookupTT(currentTupleType->name);

    populateGST(idListNode);
}

bool checkFunctionSignature(struct tnode *functionDefinitionNode) {
    if (functionDefinitionNode->nodeType != NODE_FUNC_DEF) return false;

    struct tnode *returnAndNameNode = functionDefinitionNode->left;
    struct tnode *paramDeclAndBodyNode = functionDefinitionNode->right;
    struct tnode *returnTypeNode = returnAndNameNode->left;
    struct tnode *functionNameNode = returnAndNameNode->right;
    struct tnode *paramListNode = paramDeclAndBodyNode->left;

    struct GSymbol *entry = lookupGST(functionNameNode->varName);
    if (!entry) {
        compilerError(E_FUNCTION_USED_BEFORE_DECLARATION, functionNameNode->varName);
    }

    if (returnTypeNode->type != entry->type) {
        compilerError(E_FUNCTION_SIGNATURE_RETURN_TYPE_MISMATCH, functionNameNode->varName, entry->type, returnTypeNode->type);
    }

    struct Param *paramList = entry->paramList;

    int check = checkParamsForFunction(paramListNode, &paramList, functionNameNode->varName);
    if (paramList) {
        compilerError(E_FUNCTION_SIGNATURE_TOO_FEW_ARG, functionNameNode->varName);
        exit(1);
    }

    return check;
}
