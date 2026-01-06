#include "../../define/constants.h"
#include "../../node/node.h"
#include "../../g_symbol_table/g_symbol_table.h"
#include "../../register/register.h"
#include "../../util/util.h"
#include "../../type_table/type_table.h"

#include "array.h"
#include "../code_gen.h"

static void collectArrayIndexRegisters(struct tnode *node, int *indexRegisters, int *count) {
    if (!node) return;

    if (node->nodeType == NODE_CONNECTOR) {
        collectArrayIndexRegisters(node->left, indexRegisters, count);
        collectArrayIndexRegisters(node->right, indexRegisters, count);
    } else {
        indexRegisters[*count] = generateCode(node);
        (*count)++;
    }
}

static void initializeProductArray(int productArray[], struct GSymbol *entry) {
    int numDimensions = entry->numDimensions;
    for (int i = 0; i < numDimensions; i++) {
        productArray[i] = 1;
    }

    for (int i = numDimensions - 2; i >= 0; i--) {
        productArray[i] = productArray[i + 1] * entry->dimensions[i + 1];
    }
}

int generateArrayElementAddress(struct tnode *arrayAccessNode) {
    struct tnode *idNode = arrayAccessNode->left;
    struct GSymbol *entry = idNode->gSymbolTableEntry;
    int numDimensions = entry->numDimensions;

    int productArray[numDimensions];
    initializeProductArray(productArray, entry);

    int indexRegisters[numDimensions];
    int count = 0;
    
    collectArrayIndexRegisters(arrayAccessNode->right, indexRegisters, &count);

    int sumReg = getFreeRegister();
    fprintf(target_file, "MOV R%d, 0\n", sumReg);

    for (int i = 0; i < numDimensions; i++) {
        int idxReg = indexRegisters[i];
        
        if (productArray[i] != 1) {
            fprintf(target_file, "MUL R%d, %d\n", idxReg, productArray[i]);
        }
        
        fprintf(target_file, "ADD R%d, R%d\n", sumReg, idxReg);
        releaseRegister(idxReg);
    }

    int type = entry->type;
    int size;
    if (type != USER_TYPE) {
        size = getSizeOfDataType(type);
    } else {
        size = entry->typeTableEntry->size;
    }
    int baseAddr = entry->binding;

    if (size > 1) {
        fprintf(target_file, "MUL R%d, %d\n", sumReg, size);
    }
    
    fprintf(target_file, "ADD R%d, %d\n", sumReg, baseAddr);

    return sumReg;
}

int generateArrayAccessCode(struct tnode *arrayAccessNode) {
    int indexReg = generateArrayElementAddress(arrayAccessNode);
    int freeReg = getFreeRegister();

    fprintf(target_file, "MOV R%d, [R%d]\n", freeReg, indexReg);
    releaseRegister(indexReg);

    return freeReg;
}

void generateAssignmentFromArray(struct tnode *arrayAssignNode) {
    struct tnode *left = arrayAssignNode->left;
    int memAddr = generateCode(left);

    int indexReg = generateArrayAccessCode(arrayAssignNode->right);
    fprintf(target_file, "MOV [%d], R%d\n", memAddr, indexReg);

    releaseRegister(indexReg);
}

void generateAssignmentToArray(struct tnode *arrayAssignNode) {
    int indexReg = generateArrayElementAddress(arrayAssignNode->left);
    int valueReg = generateCode(arrayAssignNode->right);

    fprintf(target_file, "MOV [R%d], R%d\n", indexReg, valueReg);

    releaseRegister(indexReg);
    releaseRegister(valueReg);
}
