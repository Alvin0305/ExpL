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

static struct GSymbol *GSTHead;
static int currentDataType = NONE;
static struct TupleType *currentTupleType = NULL;

// ------------- static helper headers ----------------
static void populateGST(struct tnode *node);
static struct GSymbol *createSymbolTableEntry(char *name, int type, int size, bool isPtr);
static void addParamsToFunction(struct GSymbol *entry, struct tnode *paramListNode);
static bool checkParamsForFunction(struct tnode *node, struct Param **param, char *functionName);
static int computerArraySize(struct tnode *dimensionDeclNode, int *dimensionCount);
static int computeDimensionProduct(struct tnode *dimensionDeclNode, int *dimensionCount);
static void extractArrayDimensions(struct GSymbol *entry, struct tnode *dimensionDeclNode);

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

struct GSymbol *installGST(char *name, int type, int size, bool isPtr, struct TupleType *tupleType) {
    struct GSymbol *head = GSTHead;

    if (lookupGST(name)) {
        compilerError(E_VARIABLE_REDECLARATION, name);
    }

    struct GSymbol *newEntry = createSymbolTableEntry(name, type, size, isPtr);
    newEntry->tupleType = tupleType;

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

void printGSymbolTable() {
    struct GSymbol *head = GSTHead;
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
    currentDataType = typeNode->type;
    currentTupleType = typeNode->tupleType;
    populateGST(varListNode);
}

void addTupleTypeToGST(struct tnode *idNode, struct tnode *tupleFieldNode, struct tnode *idListNode) {
    struct TupleType *alreadyExisting = lookupTupleTypeTable(idNode->varName);
    if (alreadyExisting) {
        compilerError(E_TUPLE_TYPE_REDECLARATION, idNode->varName);
    }

    currentDataType = TUPLE;
    currentTupleType = createTupleTypeFromNode(idNode->varName, tupleFieldNode);
    populateGST(idListNode);
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
        compilerError(E_FUNCTION_USED_BEFORE_DECLARATION, functionNameNode->varName);
    }

    if (returnTypeNode->type != entry->type) {
        compilerError(E_FUNCTION_SIGNATURE_RETURN_TYPE_MISMATCH, functionNameNode->varName, entry->type, returnTypeNode->type);
    }

    printParamList(entry->paramList);
    struct Param *paramList = entry->paramList;

    print(paramListNode);

    int check = checkParamsForFunction(paramListNode, &paramList, functionNameNode->varName);
    if (paramList) {
        compilerError(E_FUNCTION_SIGNATURE_TOO_FEW_ARG, functionNameNode->varName);
        exit(1);
    }

    return check;
}

// -------------- helper definitions -----------------

static struct GSymbol *createSymbolTableEntry(char *name, int type, int size, bool isPtr) {
    struct GSymbol *entry = (struct GSymbol *)malloc(sizeof(struct GSymbol));

    entry->name = strdup(name);
    entry->type = type;
    entry->size = size;
    entry->binding = stackTop;
    entry->next = NULL;
    entry->dimensions = NULL;
    entry->numDimensions = 0;
    entry->isPtr = isPtr;
    entry->functionLabel = NO_LABEL;

    entry->paramList = NULL;
    entry->tupleType = NULL;

    stackTop += size;

    if (stackTop >= STACK_END) {
        compilerError(E_STACK_MEMORY_EXHAUSTED);
    }

    return entry;
}

static void populateGST(struct tnode *root) {
    if (!root)
        return;

    struct GSymbol *entry;
    switch (root->nodeType) {
        case NODE_CONNECTOR:
        case NODE_DECL:
            populateGST(root->left);
            populateGST(root->right);
            break;

        case NODE_TYPE:
            {
                currentDataType = root->type;
                if (root->type == TUPLE) {
                    currentTupleType = root->tupleType;
                } else {
                    currentTupleType = NULL;
                }
                break;
            }

        case NODE_VARIABLE:
            {
                if (currentDataType == VOID) {
                    compilerError(E_VARIABLE_WITH_TYPE_VOID, root->varName);
                }

                int size = currentDataType == TUPLE ? currentTupleType->size : getSizeOfDataType(currentDataType);
                entry = installGST(root->varName, currentDataType, size, false, currentTupleType);

                root->gSymbolTableEntry = entry;
                root->type = root->gSymbolTableEntry->type;
                break;
            }

        case NODE_DEREFERENCE:
            {
                struct tnode *idNode = root->left;
                if (currentDataType == VOID) {
                    compilerError(E_VARIABLE_WITH_TYPE_VOID, idNode->varName);
                }

                int size = currentDataType == TUPLE ? currentTupleType->size : getSizeOfDataType(currentDataType);
                entry = installGST(idNode->varName, currentDataType, size, true, currentTupleType);

                root->gSymbolTableEntry = entry;
                root->type = root->gSymbolTableEntry->type;
                break;
            }

        case NODE_ARRAY_DECL:
            {
                int dimensionCount = 0;
                struct tnode *idNode = root->left;
                if (currentDataType == VOID) {
                    compilerError(E_VARIABLE_WITH_TYPE_VOID, idNode->varName);
                }
                entry = installGST(idNode->varName, currentDataType, computerArraySize(root->right, &dimensionCount), true, NULL);

                entry->dimensions = (int *)malloc(dimensionCount * sizeof(int));
                extractArrayDimensions(entry, root->right);

                root->gSymbolTableEntry = entry;
                root->type = entry->type;
                break;
            }

        case NODE_FUNC_DECL:
            {
                struct tnode *idNode = root->left;
                struct tnode *paramListNode = root->right;

                struct GSymbol *alreadyExisting = lookupGST(idNode->varName);
                if (alreadyExisting != NULL) {
                    compilerError(E_FUNCTION_REDECLARATION, idNode->varName);
                }

                entry = installGST(idNode->varName, currentDataType, getSizeOfDataType(currentDataType), false, currentTupleType);
                entry->functionLabel = createNewLabel();
                addParamsToFunction(entry, paramListNode);
                break;
            }

        case NODE_TUPLE_DECL:
            {
                struct tnode *idNode = root->left;
                struct tnode *fieldList = root->right->left;
                struct tnode *idList = root->right->right;

                struct TupleType *tupleType = createTupleTypeFromNode(idNode->varName, fieldList);
                currentTupleType = tupleType;
                currentDataType = TUPLE;

                populateGST(idList);
                break;
            }

        default:
            {
                printf("[WARNING]: Unhandled node while populating global symbol table: ");
                printNode(root);
                break;
            }
    }
}

static void addParamsToFunction(struct GSymbol *entry, struct tnode *paramListNode) {
    if (!paramListNode)
        return;

    switch (paramListNode->nodeType) {
        case NODE_CONNECTOR:
            addParamsToFunction(entry, paramListNode->left);
            addParamsToFunction(entry, paramListNode->right);
            break;

        case NODE_PARAM:
            {
                struct tnode *typeNode = paramListNode->left;
                struct tnode *paramIdNode = paramListNode->right;
                addParam(entry, paramIdNode->varName, typeNode->type, false, NULL);
                break;
            }

        case NODE_POINTER_PARAM:
            {
                struct tnode *typeNode = paramListNode->left;
                struct tnode *paramIdNode = paramListNode->right;
                addParam(entry, paramIdNode->varName, typeNode->type, true, NULL);
                break;
            }

        case NODE_TUPLE_PARAM:
            {
                struct tnode *typeNode = paramListNode->left;
                struct tnode *paramIdNode = paramListNode->right;
                struct TupleType *tupleType = typeNode->tupleType;
                addParam(entry, paramIdNode->varName, TUPLE, false, tupleType);
                break;
            }

        case NODE_TUPLE_POINTER_PARAM:
            {
                struct tnode *typeNode = paramListNode->left;
                struct tnode *paramIdNode = paramListNode->right;
                struct TupleType *tupleType = typeNode->tupleType;
                addParam(entry, paramIdNode->varName, TUPLE, true, tupleType);
                break;
            }

        default:
            {
                printf("[WARNING]: Unknown node while adding params to function\n");
                printNode(paramListNode);
            }
    }
}

static bool checkParamsForFunction(struct tnode *node, struct Param **param, char *functionName) {
    if (!node) return true;

    switch (node->nodeType) {
        case NODE_CONNECTOR:
            {
                bool leftOK = checkParamsForFunction(node->left, param, functionName);
                bool rightOK = checkParamsForFunction(node->right, param, functionName);
                return leftOK && rightOK;
            }

        case NODE_PARAM:
        case NODE_POINTER_PARAM:
            {
                if (!*param) {
                    compilerError(E_FUNCTION_SIGNATURE_MORE_ARG, functionName);
                }

                struct tnode *typeNode = node->left;
                struct tnode *idNode = node->right;
                bool typeMatch = (typeNode->type == (*param)->type);
                bool nameMatch = (strcmp(idNode->varName, (*param)->name) == 0);

                if (!typeMatch) {
                    compilerError(E_FUNCTION_SIGNATURE_TYPE_MISMATCH, functionName, idNode->varName, (*param)->type, typeNode->type);
                } else if (!nameMatch) {
                    compilerError(E_FUNCTION_SIGNATURE_VARNAME_MISMATCH, functionName, (*param)->type, idNode->varName);
                }

                (*param) = (*param)->next;
                break;
            }

        case NODE_TUPLE_PARAM:
        case NODE_TUPLE_POINTER_PARAM:
            {
                if (!*param) {
                    compilerError(E_FUNCTION_SIGNATURE_MORE_ARG, functionName);
                }

                struct tnode *typeNode = node->left;
                struct tnode *idNode = node->right;
                struct TupleType *tupleType = typeNode->tupleType;

                if (!(*param)->tupleType) {
                    printf("[ERROR]: Param is TUPLE type but does not have a tuple type\n");
                }

                bool typeMatch = ((*param)->type == TUPLE) && (strcmp(tupleType->name, (*param)->tupleType->name) == 0);
                bool nameMatch = (strcmp(idNode->varName, (*param)->name) == 0);

                if (!typeMatch) {
                    compilerError(E_FUNCTION_SIGNATURE_TYPE_MISMATCH, functionName, idNode->varName, (*param)->type, TUPLE);
                } else if (!nameMatch) {
                    compilerError(E_FUNCTION_SIGNATURE_VARNAME_MISMATCH, functionName, (*param)->name, idNode->varName);
                }

                (*param) = (*param)->next;
                break;
            }
    }

    return true;
}

static int computerArraySize(struct tnode *dimensionDeclNode, int *dimensionCount) {
    return computeDimensionProduct(dimensionDeclNode, dimensionCount) * getSizeOfDataType(currentDataType);
}

static int computeDimensionProduct(struct tnode *dimensionDeclNode, int *dimensionCount) {
    if (!dimensionDeclNode)
        return 1;

    if (dimensionDeclNode->nodeType == NODE_CONSTANT) {
        (*dimensionCount)++;
        return dimensionDeclNode->numVal;
    }

    return computeDimensionProduct(dimensionDeclNode->left, dimensionCount) *
           computeDimensionProduct(dimensionDeclNode->right, dimensionCount);
}

static void extractArrayDimensions(struct GSymbol *entry, struct tnode *dimensionDeclNode) {
    if (!dimensionDeclNode)
        return;

    if (dimensionDeclNode->nodeType == NODE_CONSTANT) {
        entry->dimensions[entry->numDimensions++] = dimensionDeclNode->numVal;
        return;
    }

    extractArrayDimensions(entry, dimensionDeclNode->left);
    extractArrayDimensions(entry, dimensionDeclNode->right);
}