#include <stdio.h>
#include <stdlib.h>

#include "../node.h"
#include "node_function.h"
#include "../../define/constants.h"
#include "../../local_symbol_table/local_symbol_table.h"
#include "../../g_symbol_table/g_symbol_table.h"
#include "../../error_handler/error_handler.h"
#include "../../util/util.h"
#include "../../code_gen/function/function.h"

struct tnode *createFunctionDeclarationNode(struct tnode *functionNameNode, struct tnode *paramListNode) {
    struct tnode *node = createConnectorNode(functionNameNode, paramListNode);

    node->nodeType = NODE_FUNC_DECL;

    return node;
}

struct tnode *createParamNode(struct tnode *typeNode, struct tnode *idNode, bool addToLocalSymbolTable, bool isPtr) {
    struct tnode *node = createConnectorNode(typeNode, idNode);
    int type = typeNode->type;
    printf("type of %s is %s\n", idNode->varName, dataTypeToString(typeNode->type));

    if (type == TUPLE) {
        struct TupleType *tupleType = typeNode->tupleType;
        if (!tupleType) {
            printf("[ERROR]: tuple type is NULL but type is tuple type\n");
            exit(1);
        }

        if (addToLocalSymbolTable) {
            installLST(idNode->varName, TUPLE, true, true, tupleType, NULL);
        }

        node->nodeType = NODE_TUPLE_POINTER_PARAM;

        return node;
    } else if (type == USER_TYPE) {
        struct TypeTable *typeTableEntry = typeNode->typeTableEntry;

        if (addToLocalSymbolTable) {
            installLST(idNode->varName, USER_TYPE, true, true, NULL, typeTableEntry);
        }

        node->nodeType = NODE_USER_DEF_TYPE_PARAM;

        return node;

    } else {
        if (addToLocalSymbolTable) {
            installLST(idNode->varName, typeNode->type, true, false, NULL, NULL);
        }

        node->nodeType = NODE_PARAM;

        return node;
    }
}

bool checkArgs(Param **param, struct tnode *argListNode, char *functionName) {
    if (!argListNode)
        return true;
    if (!*param)
        compilerError(E_FUNCTION_CALL_MORE_ARG, functionName);

    switch (argListNode->nodeType) {
        case NODE_CONNECTOR:
            {
                printf("CONNECTOR, ");
                bool leftOK = checkArgs(param, argListNode->left, functionName);
                bool rightOK = checkArgs(param, argListNode->right, functionName);
                return leftOK && rightOK;
            }

        default:
            printNode(argListNode);
            if ((*param)->type != argListNode->type) {
                compilerError(E_FUNCTION_PASSED_ARG_MISMATCH, functionName, (*param)->name,  (*param)->type, argListNode->type);
            }
            *param = (*param)->next;
            return true;
    }
}

struct tnode *createFunctionCallNode(struct tnode *functionNameNode, struct tnode *argListNode) {
    struct tnode *node = createConnectorNode(functionNameNode, argListNode);

    GSymbol *entry = lookupGST(functionNameNode->varName);

    if (!entry) {
        compilerError(E_FUNCTION_USED_BEFORE_DECLARATION, functionNameNode->varName);
    }

    node->nodeType = NODE_FUNC_CALL;
    node->type = entry->type;

    Param *paramIter = entry->paramList;

    checkArgs(&paramIter, argListNode, functionNameNode->varName);
    if (paramIter) {
        compilerError(E_FUNCTION_CALL_TOO_FEW_ARG, functionNameNode->varName);
    }

    return node;
}

struct tnode *createFunctionDefinitionNode(struct tnode *returnTypeNode, struct tnode *functionNameNode, struct tnode *paramListNode,
                                           struct tnode *localDeclarationsNode, struct tnode *functionBodyNode) {

    struct tnode *declBodyConnectorNode = createConnectorNode(localDeclarationsNode, functionBodyNode);
    struct tnode *paramDeclConnectorNode = createConnectorNode(paramListNode, declBodyConnectorNode);
    struct tnode *typeNameNode = createConnectorNode(returnTypeNode, functionNameNode);
    struct tnode *definitionNode = createConnectorNode(typeNameNode, paramDeclConnectorNode);

    definitionNode->nodeType = NODE_FUNC_DEF;

    int check = checkFunctionSignature(definitionNode);

    if (!check) {
        printf("[ERROR]: Function %s Definition Mismatch\n", functionNameNode->varName);
        exit(1);
    }

    printLocalSymbolTable();

    GSymbol *functionEntry = lookupGST(functionNameNode->varName);
    if (!functionEntry) {
        compilerError(E_FUNCTION_USED_BEFORE_DECLARATION, functionNameNode->varName);
    }

    generateFunctionCode(functionEntry->functionLabel, functionBodyNode);

    freeLocalSymbolTable();
    return NULL;
}

struct tnode *createReturnNode(struct tnode *exprNode) {
    struct tnode *node = createEmptyNode();

    if (!currentFunction) {
        return NULL;
    }

    if (!currentFunction || currentFunction->type != exprNode->type) {
        compilerError(E_FUNCTION_RETURN_TYPE_MISMATCH, currentFunction->name, currentFunction->type, exprNode->type);
    }

    node->left = exprNode;
    node->right = NULL;
    node->nodeType = NODE_RETURN;

    return node;
}