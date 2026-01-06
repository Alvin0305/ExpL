#ifndef REGISTER_H
#define REGISTER_H

#include <stdbool.h>
#include "../define/constants.h"

void initializeRegisters();
int getFreeRegister();
void releaseRegister(int regNo);

#endif