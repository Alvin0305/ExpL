### Use populated GST to generate code

```C
int getAddressOfVariable(struct tnode *node) {
    GSymbol *entry = node->gSymbolTableEntry;
    return entry->binding;
}
```

- updates the `getAddressOfVariable` method in the `code_gen.c` file to take the address of the variable from the GST instead of hardcoded values.

- and add the below code to make the code capable of handling single dimensional array's code generation.

```C
int generateArrayElementAddress(struct tnode *arrayAccessNode) {
    struct tnode *idNode = arrayAccessNode->left;
    struct tnode *indexExprNode = arrayAccessNode->right;
    struct GSymbol *entry = idNode->gSymbolTableEntry;

    int type = entry->type;
    int size = getSizeOfDataType(type);
    int baseAddr = entry->binding;

    int indexReg = generateUserCode(indexExprNode);

    fprintf(target_file, "MUL R%d, %d\n", indexReg, size);
    fprintf(target_file, "ADD R%d, %d\n", indexReg, baseAddr);

    return indexReg;
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
    int memAddr = generateUserCode(left);

    int indexReg = generateArrayAccessCode(arrayAssignNode->right);
    fprintf(target_file, "MOV [%d], R%d\n", memAddr, indexReg);

    releaseRegister(indexReg);
}


void generateAssignmentToArray(struct tnode *arrayAssignNode) {
    int indexReg = generateArrayElementAddress(arrayAssignNode->left);
    int valueReg = generateUserCode(arrayAssignNode->right);

    fprintf(target_file, "MOV [R%d], R%d\n", indexReg, valueReg);

    releaseRegister(indexReg);
    releaseRegister(valueReg);
}
```