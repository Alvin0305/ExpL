### Implementing pointers

- In this exercise, we will implementing pointers. 
- and its done by using the following functions.

```C
int generateAddressToCode(struct tnode *addressToNode) {
    struct tnode *idNode = addressToNode->left;

    int memAddr = getAddressOfVariable(idNode);
    int freeReg = getFreeRegister();

    fprintf(target_file, "MOV R%d, %d\n", freeReg, memAddr);

    return freeReg;
}

int generateDereferenceCode(struct tnode *dereferenceNode) {
    struct tnode *idNode = dereferenceNode->left;

    int freeReg = getFreeRegister();
    int idReg = generateUserCode(idNode);

    fprintf(target_file, "MOV R%d, [R%d]\n", freeReg, idReg);
    
    releaseRegister(idReg);
    return freeReg;
}

void generateAssignToDereferencedCode(struct tnode *assignNode) {
    struct tnode *dereferencedNode = assignNode->left;
    struct tnode *exprNode = assignNode->right;

    int exprReg = generateUserCode(exprNode);
    int memAddrReg = generateUserCode(dereferencedNode);

    fprintf(target_file, "MOV [R%d], R%d\n", memAddrReg, exprReg);

    releaseRegister(exprReg);
    releaseRegister(memAddrReg);
}

```