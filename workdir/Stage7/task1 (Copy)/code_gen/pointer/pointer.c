#include "../../define/constants.h"
#include "../../node/node.h"
#include "../../register/register.h"
#include "../../error_handler/error_handler.h"
#include "../code_gen.h"

#include "pointer.h"

int generateAddressToCode(struct tnode *addressToNode) {
    struct tnode *idNode = addressToNode->left;

    return getAddressOfVariable(idNode);
}

int generateDereferenceCode(struct tnode *dereferenceNode) {
    struct tnode *idNode = dereferenceNode->left;

    int freeReg = getFreeRegister();
    int idReg = generateCode(idNode);

    if (idReg == __NONE__) {
        compilerError(E_INVALID_REGISTER);
    }

    fprintf(target_file, "MOV R%d, [R%d]\n", freeReg, idReg);

    releaseRegister(idReg);
    return freeReg;
}

void generateAssignToDereferencedCode(struct tnode *assignNode) {
    struct tnode *dereferencedNode = assignNode->left;
    struct tnode *exprNode = assignNode->right;

    int exprReg = generateCode(exprNode);
    int memAddrReg = generateCode(dereferencedNode);

    if (exprReg == __NONE__ || memAddrReg == __NONE__) {
        compilerError(E_INVALID_REGISTER);
    }

    fprintf(target_file, "MOV [R%d], R%d\n", memAddrReg, exprReg);

    releaseRegister(exprReg);
    releaseRegister(memAddrReg);
}
