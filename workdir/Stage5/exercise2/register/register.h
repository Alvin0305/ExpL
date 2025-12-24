#ifndef REGISTER_H
#define REGISTER_H

#include <stdbool.h>
#include "../define/constants.h"

extern bool registers[TOTAL_REGISTERS];

void initializeRegisters();
int getFreeRegister();
void releaseRegister(int regNo);

#endif