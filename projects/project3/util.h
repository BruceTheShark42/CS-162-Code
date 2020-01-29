// Made by Bruce Cosgrove

#ifndef UTIL_H
#define UTIL_H
#define MAX_CHARS 100

char* getString(const char* message);
int getInt(const char* message, int returnError = 0);
bool contains(char* str1, const char* str2);
bool contains(char* str, char c);

#endif
