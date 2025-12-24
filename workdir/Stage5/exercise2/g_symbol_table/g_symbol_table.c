#include "g_symbol_table.h"
#include "../define/constants.h"
#include "../error_handler/error_handler.h"
#include "../label/label.h"
#include "../util/util.h"
#include "param_list.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int stackTop = STACK_START;
struct GSymbol *g_symbol_table_head;
int currentDataType = NONE;

struct GSymbol *lookupGST(char *name) {
    struct GSymbol *head = g_symbol_table_head;

    while (head) {
        if (strcmp(head->name, name) == 0) {
            return head;
        }
        head = head->next;
    }

    return NULL;
}

struct GSymbol *createSymbolTableEntry(char *name, int type, int size, bool isPtr) {
    struct GSymbol *entry = (struct GSymbol *)malloc(sizeof(struct GSymbol));
    entry->name = (char *)malloc(strlen(name) + 1);

    strcpy(entry->name, name);
    entry->type = type;
    entry->size = size;
    entry->binding = stackTop;
    entry->next = NULL;
    entry->dimensions = NULL;
    entry->numDimensions = 0;
    entry->isPtr = isPtr;
    entry->functionLabel = NO_LABEL;

    stackTop += size;

    return entry;
}

struct GSymbol *install(char *name, int type, int size, bool isPtr) {
    struct GSymbol *head = g_symbol_table_head;
    struct GSymbol *prev = NULL;

    if (!head) {
        g_symbol_table_head = createSymbolTableEntry(name, type, size, isPtr);
        return g_symbol_table_head;
    }

    while (head) {
        if (strcmp(head->name, name) == 0) {
            throwError(E_VARIABLE_REDECLARATION, name);
        }

        prev = head;
        head = head->next;
    }

    prev->next = createSymbolTableEntry(name, type, size, isPtr);
    return prev->next;
}

struct GSymbol *install_gt_tuple(char *name, struct Tuple *tupleType, bool isPtr) {
    struct GSymbol *head = g_symbol_table_head;
    struct GSymbol *prev = NULL;

    if (!head) {
        g_symbol_table_head = createSymbolTableEntry(name, TUPLE, tupleType->size, isPtr);
        g_symbol_table_head->tupleEntry = tupleType;
        return g_symbol_table_head;
    }

    while (head) {
        if (strcmp(head->name, name) == 0) {
            throwError(E_VARIABLE_REDECLARATION, name);
        }

        prev = head;
        head = head->next;
    }

    prev->next = createSymbolTableEntry(name, TUPLE, tupleType->size, isPtr);
    prev->next->tupleEntry = tupleType;
    return prev->next;
}

void printGSymbolTable() {
    struct GSymbol *head = g_symbol_table_head;
    printf("\n[SYMBOL TABLE]\n");
    printf("[VarName][DataType][Size][Binding][isPtr][#Dim]:[Dimensions]\n");
    while (head) {
        printf("%s %s %d %d %s %d: ", head->name, dataTypeToString(head->type), head->size, head->binding, booleanToString(head->isPtr), head->numDimensions);
        if (head->functionLabel == NO_LABEL) {
            printDimensions(head);
        } else {
            printParamList(head->paramList);
        }

        if (head->type == TUPLE) {
            printTuple(head->tupleEntry);
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

void populateTuplesToGST(struct tnode *idListNode, struct Tuple *tupleType) {
    if (!idListNode)
        return;

    switch (idListNode->nodeType) {
    case NODE_CONNECTOR:
        populateTuplesToGST(idListNode->left, tupleType);
        populateTuplesToGST(idListNode->right, tupleType);
        break;

    case NODE_VARIABLE:
        install_gt_tuple(idListNode->varName, tupleType, false);
        break;

    case NODE_DEREFERENCE:
        struct tnode *idNode = idListNode->left;
        install_gt_tuple(idNode->varName, tupleType, true);
        break;

    default:
        printf("Unexpected Node while populating ids of tuple type to LST:");
        printNode(idListNode);
        break;
    }
}

void populateGST(struct tnode *root) {
    if (!root)
        return;
    printf("populating g symbol table\n");
    struct GSymbol *entry;
    switch (root->nodeType) {
    case NODE_CONNECTOR:
    case NODE_DECL:
        populateGST(root->left);
        populateGST(root->right);
        break;

    case NODE_TYPE:
        currentDataType = root->type;
        break;

    case NODE_VARIABLE:
        entry = install(root->varName, currentDataType, getSizeOfDataType(currentDataType), false);
        root->gSymbolTableEntry = entry;
        root->type = root->gSymbolTableEntry->type;
        break;

    case NODE_DEREFERENCE:
        entry = install(root->left->varName, currentDataType, getSizeOfDataType(currentDataType), true);
        root->gSymbolTableEntry = entry;
        root->type = root->gSymbolTableEntry->type;
        break;

    case NODE_ARRAY_DECL:
        int dimensionCount = 0;
        entry = install(root->left->varName, currentDataType, getSizeOfArrayFromAST(root->right, &dimensionCount), true);

        entry->dimensions = (int *)malloc(dimensionCount * sizeof(int));
        addDimensionsOfArray(entry, root->right);

        root->gSymbolTableEntry = entry;
        root->type = entry->type;
        break;

    case NODE_FUNC_DECL:
        struct tnode *idNode = root->left;
        struct tnode *paramListNode = root->right;

        struct GSymbol *alreadyExisting = lookupGST(idNode->varName);
        if (alreadyExisting != NULL) {
            throwError(E_FUNCTION_REDECLARATION, idNode->varName);
        }

        entry = install(idNode->varName, currentDataType, getSizeOfDataType(currentDataType), false);
        entry->functionLabel = createNewLabel();
        addParamsToFunction(entry, paramListNode);
        break;

    case NODE_TUPLE_DECL:
        idNode = root->left;
        struct tnode *fieldList = root->right->left;
        struct tnode *idList = root->right->right;

        struct Tuple *tupleType = createTupleFromNode(idNode->varName, fieldList);
        populateTuplesToGST(idList, tupleType);

        break;
    }
}

void addParamsToFunction(struct GSymbol *entry, struct tnode *paramListNode) {
    if (!paramListNode)
        return;
    if (paramListNode->nodeType == NODE_CONNECTOR) {
        addParamsToFunction(entry, paramListNode->left);
        addParamsToFunction(entry, paramListNode->right);
    } else if (paramListNode->nodeType == NODE_PARAM) {
        struct tnode *typeNode = paramListNode->left;
        struct tnode *paramIdNode = paramListNode->right;

        addParam(entry, paramIdNode->varName, typeNode->type, false);
    } else if (paramListNode->nodeType == NODE_POINTER_PARAM) {
        struct tnode *typeNode = paramListNode->left;
        struct tnode *paramIdNode = paramListNode->right;

        addParam(entry, paramIdNode->varName, typeNode->type, true);
    }
}

bool checkFunctionSignature(struct tnode *functionDefinitionNode) {
    if (functionDefinitionNode->nodeType != NODE_FUNC_DEF)
        return false;

    struct tnode *returnAndNameNode = functionDefinitionNode->left;
    struct tnode *paramDeclAndBodyNode = functionDefinitionNode->right;
    struct tnode *returnTypeNode = returnAndNameNode->left;
    struct tnode *functionNameNode = returnAndNameNode->right;
    struct tnode *paramListNode = paramDeclAndBodyNode->left;

    struct GSymbol *entry = lookupGST(functionNameNode->varName);
    if (!entry) {
        throwError(E_FUNCTION_USED_BEFORE_DECLARATION, functionNameNode->varName);
    }

    if (returnTypeNode->type != entry->type) {
        throwFunctionSignatureMismatchError(E_FUNCTION_SIGNATURE_RETURN_TYPE_MISMATCH, entry->type, returnTypeNode->type, "", "");
    }
    // print(paramListNode);
    printParamList(entry->paramList);
    struct Param *paramList = entry->paramList;
    int check = checkParamsForFunction(paramListNode, &paramList);
    if (paramList) {
        printf("[ERROR]: more arg\n");
        exit(1);
    }

    return check;
}

bool checkParamsForFunction(struct tnode *node, struct Param **param) {
    if (!node)
        return true;

    if (node->nodeType == NODE_CONNECTOR) {
        bool leftOK = checkParamsForFunction(node->left, param);
        bool rightOK = checkParamsForFunction(node->right, param);
        return leftOK && rightOK;
    }

    if (node->nodeType == NODE_PARAM || node->nodeType == NODE_POINTER_PARAM) {
        if (!*param) {
            printf("[ERROR]: less arg\n");
            exit(1);
        }

        struct tnode *typeNode = node->left;
        struct tnode *idNode = node->right;
        bool typeMatch = (typeNode->type == (*param)->type);
        bool nameMatch = (strcmp(idNode->varName, (*param)->name) == 0);
        printf("checking: %s %s %s %s\n", dataTypeToString((*param)->type), dataTypeToString(typeNode->type), (*param)->name, idNode->varName);
        if (!typeMatch) {
            throwFunctionSignatureMismatchError(E_FUNCTION_SIGNATURE_TYPE_MISMATCH, (*param)->type, typeNode->type, (*param)->name, idNode->varName);
        } else if (!nameMatch) {
            throwFunctionSignatureMismatchError(E_FUNCTION_SIGNATURE_VARNAME_MISMATCH, (*param)->type, typeNode->type, (*param)->name, idNode->varName);
        }

        (*param) = (*param)->next;
        return true;
    }

    return true;
}

int getSizeOfArrayFromAST(struct tnode *dimensionDeclNode, int *dimensionCount) {
    return getDimensionProdFromAST(dimensionDeclNode, dimensionCount) * getSizeOfDataType(currentDataType);
}

int getDimensionProdFromAST(struct tnode *dimensionDeclNode, int *dimensionCount) {
    if (!dimensionDeclNode)
        return 1;

    if (dimensionDeclNode->nodeType == NODE_CONSTANT) {
        (*dimensionCount)++;
        return dimensionDeclNode->numVal;
    }

    return getDimensionProdFromAST(dimensionDeclNode->left, dimensionCount) *
           getDimensionProdFromAST(dimensionDeclNode->right, dimensionCount);
}

void addDimensionsOfArray(struct GSymbol *entry, struct tnode *dimensionDeclNode) {
    if (!dimensionDeclNode)
        return;

    if (dimensionDeclNode->nodeType == NODE_CONSTANT) {
        entry->dimensions[entry->numDimensions++] = dimensionDeclNode->numVal;
        return;
    }

    addDimensionsOfArray(entry, dimensionDeclNode->left);
    addDimensionsOfArray(entry, dimensionDeclNode->right);
}