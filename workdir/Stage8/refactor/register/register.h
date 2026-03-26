#ifndef REGISTER_H
#define REGISTER_H

#include "../define/constants.h"
#include <stdbool.h>

void initializeRegisters();
int getFreeRegister();
void releaseRegister(int regNo);
bool *copyRegisterStatus();
void regainRegisterStatus(bool copy[]);

#endif