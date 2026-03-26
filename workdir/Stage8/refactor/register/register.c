#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "../define/constants.h"
#include "../error_handler/error_handler.h"
#include "register.h"

static bool registers[TOTAL_REGISTERS];

void initializeRegisters() {
    for (int i = 0; i < TOTAL_REGISTERS; i++) {
        registers[i] = true;
    }
}

int getFreeRegister() {
    for (int i = 0; i < TOTAL_REGISTERS; i++) {
        if (registers[i]) {
            registers[i] = false;
            return i;
        }
    }

    compilerError(E_NO_FREE_REGISTERS);
    return __NONE__;
}

void releaseRegister(int regNo) { registers[regNo] = true; }

bool *copyRegisterStatus() {
    bool *copy = (bool *)malloc(sizeof(TOTAL_REGISTERS));
    for (int i = 0; i < TOTAL_REGISTERS; i++) {
        copy[i] = registers[i];
    }

    return copy;
}

void regainRegisterStatus(bool copy[]) {
    for (int i = 0; i < TOTAL_REGISTERS; i++) {
        registers[i] = copy[i];
    }
}