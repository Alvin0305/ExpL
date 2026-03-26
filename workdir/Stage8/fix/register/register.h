#ifndef REGISTER_H
#define REGISTER_H

#include "../define/constants.h"
#include <stdbool.h>

#define RETURN_REG 19;

void initializeRegisters();

int getFreeRegister();
void releaseRegister(int regNo);

int getNumOfRegistersUsed();

#endif