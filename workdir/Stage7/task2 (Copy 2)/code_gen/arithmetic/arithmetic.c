#include "../../register/register.h"
#include "../../node/node.h"

#include "../code_gen.h"
#include "arithmetic.h"

int generateAddRegCode(int leftReg, int rightReg) {
    fprintf(target_file, "ADD R%d, R%d\n", leftReg, rightReg);
    releaseRegister(rightReg);
    return leftReg;
}

int generateSubtractRegCode(int leftReg, int rightReg) {
    fprintf(target_file, "SUB R%d, R%d\n", leftReg, rightReg);
    releaseRegister(rightReg);
    return leftReg;
}

int generateMultiplyRegCode(int leftReg, int rightReg) {
    fprintf(target_file, "MUL R%d, R%d\n", leftReg, rightReg);
    releaseRegister(rightReg);
    return leftReg;
}

int generateDivideRegCode(int leftReg, int rightReg) {
    fprintf(target_file, "DIV R%d, R%d\n", leftReg, rightReg);
    releaseRegister(rightReg);
    return leftReg;
}

int generateModuloRegCode(int leftReg, int rightReg) {
    fprintf(target_file, "MOD R%d, R%d\n", leftReg, rightReg);
    releaseRegister(rightReg);
    return leftReg;
}

void generateIncrementCode(struct tnode *node) {
    struct tnode *idNode = node->left;

    int addrReg = getAddressOfVariable(idNode);
    int valReg = getFreeRegister();

    fprintf(target_file, "MOV R%d, [R%d]\n", valReg, addrReg);
    fprintf(target_file, "INR R%d\n", valReg);
    fprintf(target_file, "MOV [R%d], R%d\n", addrReg, valReg);
    
    releaseRegister(addrReg);
    releaseRegister(valReg);
}

void generateDecrementCode(struct tnode *node) {
    struct tnode *idNode = node->left;

    int addrReg = getAddressOfVariable(idNode);
    int valReg = getFreeRegister();

    fprintf(target_file, "MOV R%d, [R%d]\n", valReg, addrReg);
    fprintf(target_file, "DCR R%d\n", valReg);
    fprintf(target_file, "MOV [R%d], R%d\n", addrReg, valReg);
    
    releaseRegister(addrReg);
    releaseRegister(valReg);
}

