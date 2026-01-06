#include <stdio.h>
#include <stdlib.h>

#include "../../class_table/class_table.h"
#include "../../code_gen/function/function.h"
#include "../../define/constants.h"
#include "../../error_handler/error_handler.h"
#include "../../g_symbol_table/g_symbol_table.h"
#include "../../local_symbol_table/local_symbol_table.h"
#include "../../type_table/type_table.h"
#include "../../util/util.h"
#include "../node.h"
#include "node_function.h"

bool checkArgs(Param **param, struct Node *argListNode, char *functionName) {
    if (!argListNode) return true;
    if (!*param) compilerError(E_FUNCTION_CALL_MORE_ARG, functionName);

    switch (argListNode->nodeType) {
        case NODE_CONNECTOR:
            bool leftOK = checkArgs(param, argListNode->left, functionName);
            bool rightOK = checkArgs(param, argListNode->right, functionName);
            return leftOK && rightOK;

        default:
            if ((*param)->typeInfo->kind != argListNode->typeInfo->kind) {
                compilerError(E_FUNCTION_PASSED_ARG_MISMATCH, functionName, (*param)->name, (*param)->typeInfo->kind,
                              argListNode->type);
            }
            *param = (*param)->next;
            return true;
    }
}

struct Node *createFunctionCallNode(struct Node *functionNameNode, struct Node *argListNode) {
    struct Node *node = createConnectorNode(functionNameNode, argListNode);

    GSymbol *entry = lookupGST(functionNameNode->varName);

    if (!entry) {
        compilerError(E_FUNCTION_USED_BEFORE_DECLARATION, functionNameNode->varName);
    }

    node->nodeType = NODE_FUNC_CALL;
    node->type = entry->typeInfo->kind;
    node->typeInfo = entry->typeInfo;

    Param *paramIter = entry->paramList;

    checkArgs(&paramIter, argListNode, functionNameNode->varName);
    if (paramIter) {
        compilerError(E_FUNCTION_CALL_TOO_FEW_ARG, functionNameNode->varName);
    }

    return node;
}

// struct tnode *createFunctionDefinitionNode(struct tnode *returnTypeNode, struct tnode *functionNameNode,
//                                            struct tnode *paramListNode, struct tnode *localDeclarationsNode,
//                                            struct tnode *functionBodyNode) {

//     struct tnode *declBodyConnectorNode = createConnectorNode(localDeclarationsNode, functionBodyNode);
//     struct tnode *paramDeclConnectorNode = createConnectorNode(paramListNode, declBodyConnectorNode);
//     struct tnode *typeNameNode = createConnectorNode(returnTypeNode, functionNameNode);
//     struct tnode *definitionNode = createConnectorNode(typeNameNode, paramDeclConnectorNode);

//     definitionNode->nodeType = NODE_FUNC_DEF;
//     checkFunctionSignature(definitionNode);

//     GSymbol *functionEntry = lookupGST(functionNameNode->varName);
//     if (!functionEntry) {
//         compilerError(E_FUNCTION_USED_BEFORE_DECLARATION, functionNameNode->varName);
//     }

//     generateFunctionCode(functionEntry->functionLabel, functionBodyNode);
//     freeLocalSymbolTable();
//     return NULL;
// }

struct Node *createReturnNode(struct Node *exprNode) {
    if (!currentFunction && !activeMethod) return NULL;

    if (currentFunction && currentFunction->typeInfo->kind != exprNode->type) {
        compilerError(E_FUNCTION_RETURN_TYPE_MISMATCH, currentFunction->name, currentFunction->typeInfo->kind, exprNode->type);
    }

    struct Node *node = createEmptyNode();
    node->left = exprNode;
    node->right = NULL;
    node->nodeType = NODE_RETURN;

    return node;
}