// Made by Bruce Cosgrove

#ifndef UTIL_H
#define UTIL_H

#include "String.h"

String getString(const char *message);
int getInt(const char *message, const int &returnError = 0);
bool contains(char *str1, const char *str2);
bool contains(char *str, char c);

#endif
