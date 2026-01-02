#include "../../define/constants.h"
#include "../../g_symbol_table/g_symbol_table.h"
#include "../../local_symbol_table/local_symbol_table.h"
#include "../../node/node.h"
#include "../../register/register.h"
#include "../../type_table/type_table.h"
#include "../array/array.h"

#include "../code_gen.h"
#include "user_type.h"

#include <stdlib.h>

void findUserTypeFieldAddr(int *fieldAddrReg, struct tnode *node, struct TypeTable **activeType) {
    switch (node->nodeType) {
        case NODE_CONNECTOR:
        case NODE_USER_DEF_TYPE_ACCESS:
            findUserTypeFieldAddr(fieldAddrReg, node->left, activeType);
            findUserTypeFieldAddr(fieldAddrReg, node->right, activeType);
            break;

        case NODE_ARRAY_ACCESS:
            if (*fieldAddrReg == -1) {
                *activeType = node->left->typeTableEntry;
                char *name = node->left->varName;

                printf("name: %s\n", name);
            }

            *fieldAddrReg = generateArrayElementAddress(node);
            break;

        case NODE_VARIABLE:
            if (*fieldAddrReg == -1) {
                *activeType = node->typeTableEntry;
                char *name = node->varName;

                printf("name: %s\n", name);

                struct GSymbol *globalEntry = lookupGST(name);
                struct LSymbol *localEntry = lookupLST(name);

                *fieldAddrReg = getFreeRegister();
                if (localEntry) {
                    int binding = localEntry->binding;
                    fprintf(target_file, "MOV R%d, BP\n", *fieldAddrReg);
                    fprintf(target_file, "ADD R%d, %d\n", *fieldAddrReg, binding);
                } else if (globalEntry) {
                    int binding = globalEntry->binding;
                    fprintf(target_file, "MOV R%d, %d\n", *fieldAddrReg, binding);
                } else {
                    printf("error\n");
                }
            } else {
                printf("offsetting: %s on %s\n", node->varName, (*activeType)->name);
                struct FieldList *field = fieldListLookup(*activeType, node->varName);
                *activeType = field->type;
                fprintf(target_file, "MOV R%d, [R%d]\n", *fieldAddrReg, *fieldAddrReg);
                fprintf(target_file, "ADD R%d, %d\n", *fieldAddrReg, field->fieldIndex);
            }
            break;

        default:
            printf("unhandled node in user type access helper: %d\n", node->nodeType);
            break;
    }
}

int generateUserTypeAccessCode(struct tnode *root) {
    int addrReg = -1;
    struct TypeTable *type = NULL;
    findUserTypeFieldAddr(&addrReg, root, &type);

    fprintf(target_file, "MOV R%d, [R%d]\n", addrReg, addrReg);
    return addrReg;
}

void generateUserTypeAssignmentCode(struct tnode *root) {
    struct tnode *accessNode = root->left;

    int addrReg = -1;
    struct TypeTable *type = NULL;
    findUserTypeFieldAddr(&addrReg, accessNode, &type);

    int valueReg = generateCode(root->right);
    fprintf(target_file, "MOV [R%d], R%d\n", addrReg, valueReg);

    releaseRegister(addrReg);
    releaseRegister(valueReg);
}
