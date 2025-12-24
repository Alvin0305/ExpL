#include "node.h"
#include "../code_gen/code_gen.h"
#include "../define/constants.h"
#include "../error_handler/error_handler.h"
#include "../g_symbol_table/g_symbol_table.h"
#include "../local_symbol_table/local_symbol_table.h"
#include "../tuple_type_table/tuple_type_table.h"
#include "../util/util.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../code_gen/function/function.h"

extern int lineNumber;

struct tnode *createTreeNode(int val, int nodeType, char *varName, struct tnode *left, struct tnode *right) {
    if (val != NOT_CONSTANT) {
        return createConstantNode(val);
    } else if (varName) {
        return createNewVariableNode(varName);
    } else {
        struct tnode *node = (tnode *)malloc(sizeof(tnode));

        node->left = left;
        node->right = right;
        node->nodeType = nodeType;
        node->varName = NULL;
        node->numVal = NOT_CONSTANT;

        return node;
    }
}

struct tnode *createLeafNode(int nodeType) {
    struct tnode *node = createEmptyNode();

    node->nodeType = nodeType;
    node->gSymbolTableEntry = NULL;
    node->lSymbolTableEntry = NULL;
    node->numVal = __NONE__;
    node->type = NONE;
    node->varName = NULL;

    return node;
}

struct tnode *createEmptyNode() {
    struct tnode *node = (struct tnode *)malloc(sizeof(tnode));

    node->left = NULL;
    node->right = NULL;
    node->nodeType = NODE_EMPTY;

    return node;
}

struct tnode *createConstantNode(int val) {
    struct tnode *node = createLeafNode(NODE_CONSTANT);

    node->numVal = val;
    node->type = INT;

    return node;
}

struct tnode *createStringLiteralNode(char *stringLiteral) {
    struct tnode *node = createLeafNode(NODE_STRING_LITERAL);

    node->strVal = strdup(stringLiteral);
    node->type = STRING;

    return node;
}

struct tnode *createNewVariableNode(char *varName) {
    struct tnode *node = createLeafNode(NODE_VARIABLE);

    node->varName = strdup(varName);

    return node;
}

struct tnode *createNewArrayNode(struct tnode *varListNode, struct tnode *idNode, struct tnode *dimListNode) {
    struct tnode *node = createEmptyNode();
    struct tnode *connector = createConnectorNode(varListNode, node);

    node->left = idNode;
    node->right = dimListNode;
    node->nodeType = NODE_ARRAY_DECL;
    node->type = NONE;
    node->varName = NULL;
    node->numVal = NOT_CONSTANT;

    return connector;
}

struct tnode *createArrayAssignNode(struct tnode *idNode, struct tnode *dimensionUsageNode, struct tnode *valueNode) {
    struct tnode *arrayNode = createConnectorNode(createVariableUsageNode(idNode->varName), dimensionUsageNode);
    struct tnode *assignNode = createConnectorNode(arrayNode, valueNode);

    assignNode->nodeType = NODE_ARRAY_ASSIGN;
    assignNode->type = NONE;
    assignNode->numVal = NOT_CONSTANT;
    assignNode->varName = NULL;

    return assignNode;
}

struct tnode *createArrayAccessNode(struct tnode *idNode, struct tnode *indexExprNode) {
    struct tnode *idUsageNode = createVariableUsageNode(idNode->varName);
    struct tnode *arrayNode = createConnectorNode(idUsageNode, indexExprNode);

    arrayNode->nodeType = NODE_ARRAY_ACCESS;
    arrayNode->numVal = NOT_CONSTANT;
    arrayNode->type = idUsageNode->type;
    arrayNode->varName = NULL;

    return arrayNode;
}

struct tnode *createVariableUsageNode(char *varName) {
    struct tnode *node = createLeafNode(NODE_VARIABLE);

    node->varName = strdup(varName);

    LSymbol *localEntry = local_st_lookup(varName);
    GSymbol *globalEntry = lookupGST(varName);

    if (localEntry) {
        node->type = localEntry->type;
        node->gSymbolTableEntry = NULL;
        node->lSymbolTableEntry = localEntry;
    } else if (globalEntry) {
        node->type = globalEntry->type;
        node->gSymbolTableEntry = globalEntry;
        node->lSymbolTableEntry = NULL;
    } else {
        throwError(E_VARIABLE_USED_BEFORE_DECLARATION, varName);
    }

    return node;
}

struct tnode *createArithOpNode(int nodeType, tnode *left, tnode *right) {
    if (left->type != INT || right->type != INT) {
        printf("[ERROR]: [%d] Type of mismatch in %s %s %s\n", lineNumber, dataTypeToString(left->type), opToString(nodeType), dataTypeToString(right->type));
        exit(1);
    }

    struct tnode *node = createEmptyNode();

    node->left = left;
    node->right = right;
    node->nodeType = nodeType;
    node->numVal = NOT_CONSTANT;
    node->varName = NULL;
    node->type = INT;

    return node;
}

struct tnode *createAssignNode(tnode *idNode, tnode *exprNode) {
    struct tnode *idUsageNode = createVariableUsageNode(idNode->varName);

    if (idUsageNode->type != exprNode->type) {
        printf("[ERROR]: [%d] Type mismatch in assignment %s = %s\n", lineNumber, dataTypeToString(idUsageNode->type), dataTypeToString(exprNode->type));
        exit(1);
    }

    idUsageNode->type = exprNode->type;

    struct tnode *node = createEmptyNode();

    node->left = idUsageNode;
    node->right = exprNode;
    node->nodeType = NODE_ASSIGN;
    node->numVal = NOT_CONSTANT;
    node->varName = NULL;
    node->type = NONE;

    return node;
}

struct tnode *createConnectorNode(tnode *left, tnode *right) {
    struct tnode *node = createEmptyNode();

    node->left = left;
    node->right = right;
    node->nodeType = NODE_CONNECTOR;
    node->type = NONE;
    node->numVal = NOT_CONSTANT;
    node->varName = NULL;

    return node;
}

struct tnode *createReadNode(tnode *idNode) {
    struct tnode *node = createEmptyNode();
    struct tnode *idUsageNode = createVariableUsageNode(idNode->varName);

    node->left = idUsageNode;
    node->nodeType = NODE_READ;
    node->type = NONE;
    node->numVal = NOT_CONSTANT;
    node->varName = NULL;

    return node;
}

struct tnode *createReadToArrayNode(struct tnode *idNode, struct tnode *dimensionNode) {
    struct tnode *node = createEmptyNode();
    struct tnode *newIdNode = createArrayAccessNode(idNode, dimensionNode);

    node->left = newIdNode;
    node->right = NULL;
    node->nodeType = NODE_READ_TO_ARRAY;
    node->numVal = NOT_CONSTANT;
    node->type = NONE;
    node->varName = NULL;

    return node;
}

struct tnode *createWriteNode(tnode *exprNode) {
    struct tnode *node = createEmptyNode();

    if (exprNode->type != INT && exprNode->type != STRING) {
        printf("[ERROR]: [%d] Type mismatch, type is: %s\n", lineNumber, dataTypeToString(exprNode->type));
        exit(1);
    }

    node->left = exprNode;
    node->nodeType = NODE_WRITE;
    node->type = NONE;
    node->numVal = NOT_CONSTANT;
    node->varName = NULL;

    return node;
}

struct tnode *createConditionNode(int nodeType, tnode *left, tnode *right) {
    // if (left->type != INT || right->type != INT) {
    //     printf("[ERROR]: [%d] Type of both variables in a condition should be INT, got %s and %s\n", lineNumber, dataTypeToString(left->type), dataTypeToString(right->type));
    //     exit(1);
    // }

    struct tnode *node = createEmptyNode();

    node->left = left;
    node->right = right;
    node->numVal = NOT_CONSTANT;
    node->type = BOOL;
    node->varName = NULL;
    node->nodeType = nodeType;

    return node;
}

struct tnode *createWhileNode(tnode *conditionNode, tnode *statementsNode) {
    if (conditionNode->type != BOOL) {
        throwTypeMismatchError("condition for while loop", BOOL, conditionNode->type);
    }

    struct tnode *node = createEmptyNode();

    node->left = conditionNode;
    node->right = statementsNode;
    node->nodeType = NODE_WHILE;
    node->type = NONE;
    node->numVal = NOT_CONSTANT;
    node->varName = NULL;

    return node;
}

struct tnode *createIfElseNode(tnode *conditionNode, tnode *ifStatementsNode, tnode *elseStatementsNode) {
    if (conditionNode->type != BOOL) {
        throwTypeMismatchError("condition for if else", BOOL, conditionNode->type);
    }

    struct tnode *node = createEmptyNode();
    struct tnode *connector = createConnectorNode(ifStatementsNode, elseStatementsNode);

    node->left = conditionNode;
    node->right = connector;
    node->numVal = NOT_CONSTANT;
    node->nodeType = NODE_IF_ELSE;
    node->type = NONE;
    node->varName = NULL;

    return node;
}

struct tnode *createIfNode(tnode *conditionNode, tnode *statementsNode) {
    if (conditionNode->type != BOOL) {
        throwTypeMismatchError("condition for if", BOOL, conditionNode->type);
    }

    struct tnode *node = createEmptyNode();

    node->left = conditionNode;
    node->right = statementsNode;
    node->nodeType = NODE_IF;
    node->type = NONE;
    node->numVal = NOT_CONSTANT;
    node->varName = NULL;

    return node;
}

struct tnode *createBreakNode() {
    return createLeafNode(NODE_BREAK);
}

struct tnode *createContinueNode() {
    return createLeafNode(NODE_CONTINUE);
}

struct tnode *createRepeatUntilNode(struct tnode *statementsNode, struct tnode *conditionNode) {
    if (conditionNode->type != BOOL) {
        throwTypeMismatchError("condition for repeat until loop", BOOL, conditionNode->type);
    }

    struct tnode *node = createEmptyNode();

    node->left = statementsNode;
    node->right = conditionNode;
    node->nodeType = NODE_REPEAT_UNTIL;
    node->numVal = NOT_CONSTANT;
    node->type = NONE;
    node->varName = NULL;

    return node;
}

struct tnode *createDoWhileNode(struct tnode *statementsNode, struct tnode *conditionNode) {
    if (conditionNode->type != BOOL) {
        throwTypeMismatchError("condition for do while loop", BOOL, conditionNode->type);
    }

    struct tnode *node = createEmptyNode();

    node->left = conditionNode;
    node->right = statementsNode;
    node->type = NONE;
    node->nodeType = NODE_DO_WHILE;
    node->varName = NULL;
    node->numVal = NOT_CONSTANT;

    return node;
}

struct tnode *createTypeNode(int type) {
    struct tnode *node = createLeafNode(NODE_TYPE);
    node->type = type;

    return node;
}

struct tnode *createTupleTypeNode(struct tnode *tupleTypeName) {
    struct tnode *node = createLeafNode(NODE_TYPE);
    node->type = TUPLE;
    struct TupleType *tupleType = lookupTupleTypeTable(tupleTypeName->varName);

    if (!tupleType) {
        compilerError(E_TUPLE_TYPE_USED_BEFORE_DECLARATION, tupleTypeName->varName);
    }

    node->tupleType = tupleType;

    return node;
}

struct tnode *createDeclarationNode(struct tnode *typeNode, struct tnode *varListNode) {
    struct tnode *node = createConnectorNode(typeNode, varListNode);
    int type = typeNode->type;

    if (type == TUPLE) {
        struct TupleType *tupleType = typeNode->tupleType;
        if (!tupleType) {
            printf("[ERROR]: tuple type is NULL\n");
            exit(1);
        }

        node->nodeType = NODE_TUPLE_VAR_DECL;
        populateTuplesToGST(varListNode, tupleType);
        return node;
    } else {
        node->nodeType = NODE_DECL;
        node->type = NONE;
        node->numVal = NOT_CONSTANT;
        node->varName = NULL;

        return node;
    }
}

struct tnode *createNewPointerNode(struct tnode *idNode) {
    struct tnode *node = createEmptyNode();

    node->nodeType = NODE_DEREFERENCE;
    node->left = idNode;
    node->right = NULL;
    node->numVal = NOT_CONSTANT;
    node->varName = NULL;

    return node;
}

struct tnode *createDereferenceNode(struct tnode *idNode) {
    struct tnode *node = createEmptyNode();
    struct tnode *newIdNode = createVariableUsageNode(idNode->varName);

    node->nodeType = NODE_DEREFERENCE;
    node->left = newIdNode;
    node->right = NULL;
    node->numVal = NOT_CONSTANT;
    if (newIdNode->gSymbolTableEntry) {
        node->type = newIdNode->gSymbolTableEntry->type;

        if (!newIdNode->gSymbolTableEntry->isPtr) {
            throwError(E_DEREFERENCING_NON_POINTER_VARIABLE, newIdNode->varName);
        }
    } else if (newIdNode->lSymbolTableEntry) {
        node->type = newIdNode->lSymbolTableEntry->type;
    }
    node->varName = NULL;

    return node;
}

struct tnode *createAddressToNode(struct tnode *idNode) {
    struct tnode *node = createEmptyNode();
    struct tnode *newIdNode = createVariableUsageNode(idNode->varName);

    node->nodeType = NODE_ADDRESS_TO;
    node->left = newIdNode;
    node->right = NULL;
    node->numVal = NOT_CONSTANT;
    if (newIdNode->gSymbolTableEntry) {
        node->type = newIdNode->gSymbolTableEntry->type;

        if (newIdNode->gSymbolTableEntry->isPtr) {
            throwError(E_POINTER_TO_POINTER, newIdNode->varName);
        }
    } else if (newIdNode->lSymbolTableEntry) {
        node->type = newIdNode->lSymbolTableEntry->type;
    }
    node->varName = NULL;

    return node;
}

struct tnode *createAssignToDereferencedNode(struct tnode *idNode, struct tnode *exprNode) {
    struct tnode *node = createEmptyNode();
    struct tnode *newIdNode = createVariableUsageNode(idNode->varName);

    node->nodeType = NODE_ASSIGN_TO_DEREFERENCED;
    node->left = newIdNode;
    node->right = exprNode;
    node->numVal = NOT_CONSTANT;
    node->type = NONE;
    node->varName = NULL;

    if (newIdNode->gSymbolTableEntry && !newIdNode->gSymbolTableEntry->isPtr) {
        throwError(E_DEREFERENCING_NON_POINTER_VARIABLE, newIdNode->varName);
    }

    return node;
}

struct tnode *createIncrementNode(struct tnode *idNode) {
    struct tnode *node = createEmptyNode();
    struct tnode *newIdNode = createVariableUsageNode(idNode->varName);

    node->nodeType = NODE_INC;
    node->left = newIdNode;
    node->right = NULL;
    node->type = newIdNode->gSymbolTableEntry->type;
    node->numVal = NOT_CONSTANT;
    node->varName = NULL;

    return node;
}

struct tnode *createDecrementNode(struct tnode *idNode) {
    struct tnode *node = createEmptyNode();
    struct tnode *newIdNode = createVariableUsageNode(idNode->varName);

    node->nodeType = NODE_DEC;
    node->left = newIdNode;
    node->right = NULL;
    node->type = newIdNode->gSymbolTableEntry->type;
    node->numVal = NOT_CONSTANT;
    node->varName = NULL;

    return node;
}

struct tnode *createCompoundAssignNode(int nodeType, struct tnode *idNode, struct tnode *exprNode) {
    struct tnode *leftIdNode = createVariableUsageNode(idNode->varName);
    struct tnode *rightIdNode = createVariableUsageNode(idNode->varName);
    struct tnode *opNode = createArithOpNode(nodeType, rightIdNode, exprNode);

    return createAssignNode(leftIdNode, opNode);
}

struct tnode *createFunctionDeclarationNode(struct tnode *functionNameNode, struct tnode *paramListNode) {
    struct tnode *node = createConnectorNode(functionNameNode, paramListNode);

    node->nodeType = NODE_FUNC_DECL;

    return node;
}

struct tnode *createParamNode(struct tnode *typeNode, struct tnode *idNode, bool addToLocalSymbolTable, bool isPtr) {
    struct tnode *node = createConnectorNode(typeNode, idNode);
    int type = typeNode->type;

    if (type == TUPLE) {
        struct TupleType *tupleType = typeNode->tupleType;
        if (!tupleType) {
            printf("[ERROR]: tuple type is NULL but type is tuple type\n");
            exit(1);
        }

        if (addToLocalSymbolTable) {
            local_st_tuple_install(idNode->varName, tupleType, true, true);
        }

        node->nodeType = NODE_TUPLE_POINTER_PARAM;

        return node;
    } else {
        if (addToLocalSymbolTable) {
            local_st_install(idNode->varName, typeNode->type, true, false);
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
    case NODE_CONNECTOR: {
        printf("CONNECTOR, ");
        bool leftOK = checkArgs(param, argListNode->left, functionName);
        bool rightOK = checkArgs(param, argListNode->right, functionName);
        return leftOK && rightOK;
    }

    default:
        printNode(argListNode);
        if ((*param)->type != argListNode->type) {
            throwFunctionSignatureMismatchError(E_FUNCTION_PASSED_ARG_MISMATCH, (*param)->type, argListNode->type, (*param)->name, "");
        }
        *param = (*param)->next;
        return true;
    }
}

struct tnode *createFunctionCallNode(struct tnode *functionNameNode, struct tnode *argListNode) {
    struct tnode *node = createConnectorNode(functionNameNode, argListNode);

    GSymbol *entry = lookupGST(functionNameNode->varName);

    if (!entry) {
        throwError(E_FUNCTION_USED_BEFORE_DECLARATION, functionNameNode->varName);
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

struct tnode *createMainNode(struct tnode *localDeclarationsNode, struct tnode *bodyNode) {
    struct tnode *node = createConnectorNode(localDeclarationsNode, bodyNode);

    node->nodeType = NODE_FUNC_DEF;

    printLocalSymbolTable();
    generateMainCode(bodyNode);

    freeLocalSymbolTable();
    return NULL;
}

struct tnode *createFunctionDefinitionNode(struct tnode *returnTypeNode, struct tnode *functionNameNode, struct tnode *paramListNode,
                                           struct tnode *localDeclarationsNode, struct tnode *functionBodyNode) {

    if (returnTypeNode->type == TUPLE) {
        struct TupleType *tupleType = returnTypeNode->tupleType;

        if (!tupleType) {
            printf("[ERROR]: TupleType is null\n");
            exit(1);
        }
    }

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
        throwError(E_FUNCTION_USED_BEFORE_DECLARATION, functionNameNode->varName);
    }

    generateFunctionCode(functionEntry->functionLabel, functionBodyNode);

    freeLocalSymbolTable();
    return NULL;
}

struct tnode *createLocalDeclarationNode(struct tnode *typeNode, struct tnode *idListNode) {
    struct tnode *node = createConnectorNode(typeNode, idListNode);
    int type = typeNode->type;

    if (type == TUPLE) {
        struct TupleType *tupleType = typeNode->tupleType;
        if (!tupleType) {
            printf("[ERROR]: Tuple type is null\n");
            exit(1);
        }

        populateTuplesToLST(idListNode, tupleType);

        node->nodeType = NODE_TUPLE_VAR_DECL;
        return node;
    } else {
        node->nodeType = NODE_LOCAL_DECL;

        populateLocalSymbolTable(node);
        printLocalSymbolTable();

        return node;
    }
}

struct tnode *createReturnNode(struct tnode *exprNode) {
    struct tnode *node = createEmptyNode();

    if (!currentFunction) {
        return NULL;
    }

    if (!currentFunction || currentFunction->type != exprNode->type) {
        throwFunctionSignatureMismatchError(E_FUNCTION_RETURN_TYPE_MISMATCH, currentFunction->type, exprNode->type, "", currentFunction->name);
    }

    node->left = exprNode;
    node->right = NULL;
    node->nodeType = NODE_RETURN;

    return node;
}

struct tnode *createBreakPointNode() {
    return createLeafNode(NODE_BREAK_POINT);
}

struct tnode *createGlobalTupleTypeNode(struct tnode *idNode, struct tnode *paramListNode, struct tnode *idListNode) {
    struct tnode *paramIdConnector = createConnectorNode(paramListNode, idListNode);
    struct tnode *node = createConnectorNode(idNode, paramIdConnector);

    struct TupleType *alreadyExisting = lookupTupleTypeTable(idNode->varName);
    if (alreadyExisting) {
        compilerError(E_TUPLE_TYPE_REDECLARATION, idNode->varName);
    }

    populateTuplesToGST(idListNode, createTupleTypeFromNode(idNode->varName, paramListNode));

    node->nodeType = NODE_TUPLE_DECL;

    return node;
}

struct tnode *createLocalTupleTypeDeclarationNode(struct tnode *idNode, struct tnode *paramListNode, struct tnode *idListNode) {
    struct tnode *paramIdConnector = createConnectorNode(paramListNode, idListNode);
    struct tnode *node = createConnectorNode(idNode, paramIdConnector);

    node->nodeType = NODE_TUPLE_DECL;

    struct TupleType *tupleType = createTupleTypeFromNode(idNode->varName, paramListNode);
    populateTuplesToLST(idListNode, tupleType);

    return node;
}

struct tnode *createTupleAccessNode(struct tnode *idNode, struct tnode *fieldNode) {
    struct tnode *idUsageNode = createVariableUsageNode(idNode->varName);

    struct TupleType *tupleType = NULL;
    if (idUsageNode->lSymbolTableEntry) {
        tupleType = idUsageNode->lSymbolTableEntry->tupleEntry;
    } else if (idUsageNode->gSymbolTableEntry) {
        tupleType = idUsageNode->gSymbolTableEntry->tupleEntry;
    } else {
        compilerError(E_VARIABLE_USED_BEFORE_DECLARATION, idNode->varName);
    }

    struct TupleField *fieldEntry = getFieldOfTuple(tupleType, fieldNode->varName);

    if (!fieldEntry) {
        compilerError(E_ACCESS_NON_EXISTING_FIELD_OF_TUPLE, idNode->varName, fieldNode->varName);
    }

    struct tnode *node = createConnectorNode(idUsageNode, fieldNode);

    node->nodeType = NODE_TUPLE_ACCESS;
    node->type = fieldEntry->type;

    return node;
}

struct tnode *createTuplePointerAccessNode(struct tnode *idNode, struct tnode *fieldNode) {
    struct tnode *idUsageNode = createVariableUsageNode(idNode->varName);

    struct TupleType *tupleType = NULL;
    if (idUsageNode->lSymbolTableEntry) {
        tupleType = idUsageNode->lSymbolTableEntry->tupleEntry;

        if (!idUsageNode->lSymbolTableEntry->isPtr) {
            compilerError(E_DEREFERENCE_NON_POINTER_TUPLE, idUsageNode->varName);
        }
    } else if (idUsageNode->gSymbolTableEntry) {
        tupleType = idUsageNode->gSymbolTableEntry->tupleEntry;

        if (!idUsageNode->gSymbolTableEntry->isPtr) {
            compilerError(E_DEREFERENCE_NON_POINTER_TUPLE, idUsageNode->varName);
        }
    } else {
        compilerError(E_VARIABLE_USED_BEFORE_DECLARATION, idNode->varName);
    }

    struct TupleField *fieldEntry = getFieldOfTuple(tupleType, fieldNode->varName);

    if (!fieldEntry) {
        compilerError(E_ACCESS_NON_EXISTING_FIELD_OF_TUPLE, idNode->varName, fieldNode->varName);
    }

    struct tnode *node = createConnectorNode(idUsageNode, fieldNode);

    node->nodeType = NODE_TUPLE_POINTER_ACCESS;
    node->type = fieldEntry->type;

    return node;
}

struct tnode *createTupleAssignmentNode(struct tnode *idNode, struct tnode *fieldNode, struct tnode *exprNode) {
    struct tnode *idUsageNode = createVariableUsageNode(idNode->varName);

    struct TupleType *tupleType;
    if (idUsageNode->gSymbolTableEntry) {
        tupleType = idUsageNode->gSymbolTableEntry->tupleEntry;
    } else if (idUsageNode->lSymbolTableEntry) {
        tupleType = idUsageNode->lSymbolTableEntry->tupleEntry;
    } else {
        compilerError(E_VARIABLE_USED_BEFORE_DECLARATION, idNode->varName);
    }

    struct TupleField *fieldEntry = getFieldOfTuple(tupleType, fieldNode->varName);

    if (!fieldEntry) {
        compilerError(E_ACCESS_NON_EXISTING_FIELD_OF_TUPLE, idNode->varName, fieldNode->varName);
    }

    struct tnode *tupleNode = createConnectorNode(idUsageNode, fieldNode);
    // tupleNode->nodeType = NODE_TUPLE_ACCESS;
    struct tnode *node = createConnectorNode(tupleNode, exprNode);
    node->nodeType = NODE_TUPLE_ASSIGN;

    return node;
}

struct tnode *createTuplePointerAssignmentNode(struct tnode *idNode, struct tnode *fieldNode, struct tnode *exprNode) {
    struct tnode *idUsageNode = createVariableUsageNode(idNode->varName);

    struct TupleType *tupleType = NULL;
    if (idUsageNode->lSymbolTableEntry) {
        tupleType = idUsageNode->lSymbolTableEntry->tupleEntry;

        if (!idUsageNode->lSymbolTableEntry->isPtr) {
            compilerError(E_DEREFERENCE_NON_POINTER_TUPLE, idUsageNode->varName);
        }
    } else if (idUsageNode->gSymbolTableEntry) {
        tupleType = idUsageNode->gSymbolTableEntry->tupleEntry;

        if (!idUsageNode->gSymbolTableEntry->isPtr) {
            compilerError(E_DEREFERENCE_NON_POINTER_TUPLE, idUsageNode->varName);
        }
    } else {
        compilerError(E_VARIABLE_USED_BEFORE_DECLARATION, idNode->varName);
    }

    struct TupleField *fieldEntry = getFieldOfTuple(tupleType, fieldNode->varName);

    if (!fieldEntry) {
        compilerError(E_ACCESS_NON_EXISTING_FIELD_OF_TUPLE, idNode->varName, fieldNode->varName);
    }

    struct tnode *tupleNode = createConnectorNode(idNode, fieldNode);
    tupleNode->nodeType = NODE_TUPLE_POINTER_ACCESS;
    struct tnode *node = createConnectorNode(tupleNode, exprNode);
    node->nodeType = NODE_TUPLE_POINTER_ASSIGN;

    return node;
}

void print_helper(struct tnode *root) {
    if (!root)
        return;

    printNode(root);

    print_helper(root->left);
    print_helper(root->right);
}

void print(struct tnode *root) {
    printf("[Printing AST]\n");
    print_helper(root);
    printf("\n");
}

void inorder_helper(struct tnode *root) {
    if (!root)
        return;

    inorder_helper(root->left);
    printNode(root);
    inorder_helper(root->right);
}

void print_inorder(struct tnode *root) {
    printf("[PRINTING IN INORDER]\n");
    inorder_helper(root);
    printf("\n");
}