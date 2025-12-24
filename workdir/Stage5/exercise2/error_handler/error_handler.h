#ifndef ERROR_HANDLER_H
#define ERROR_HANDLER_H

void throwError(int error, void *arg1);
void throwTypeMismatchError(char *location, int expectedType, int givenType);
void throwFunctionSignatureMismatchError(int error, int expectedType, int givenType, char *expectedName, char *givenName);
void throwFunctionCallError(int error);
void compilerError(int error, ...);

#endif