#include "../../define/constants.h"
#include "../../error_handler/error_handler.h"
#include "../../node/node.h"
#include "../../register/register.h"
#include "../code_gen.h"

#include "pointer.h"

int generateAddressToCode(struct Node *addressToNode) {
    struct Node *idNode = addressToNode->left;

    return getAddressOfVariable(idNode);
}

int generateDereferenceCode(struct Node *dereferenceNode) {
    struct Node *idNode = dereferenceNode->left;

    int freeReg = getFreeRegister();
    int idReg = generateCode(idNode);

    if (idReg == __NONE__) {
        compilerError(E_INVALID_REGISTER);
    }

    fprintf(target_file, "MOV R%d, [R%d]\n", freeReg, idReg);

    releaseRegister(idReg);
    return freeReg;
}

void generateAssignToDereferencedCode(struct Node *assignNode) {
    struct Node *dereferencedNode = assignNode->left;
    struct Node *exprNode = assignNode->right;

    int exprReg = generateCode(exprNode);
    int memAddrReg = generateCode(dereferencedNode);

    if (exprReg == __NONE__ || memAddrReg == __NONE__) {
        compilerError(E_INVALID_REGISTER);
    }

    fprintf(target_file, "MOV [R%d], R%d\n", memAddrReg, exprReg);

    releaseRegister(exprReg);
    releaseRegister(memAddrReg);
}
