#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../define/constants.h"
#include "../error_handler/error_handler.h"
#include "register.h"

bool registers[TOTAL_REGISTERS];

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
    exit(1);
}

void releaseRegister(int regNo) {
    registers[regNo] = true;
}