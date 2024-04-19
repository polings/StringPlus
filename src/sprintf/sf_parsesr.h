#ifndef SF_PARSER_H
#define SF_PARSER_H
#include <math.h>
#include <stdarg.h>
#include <stdlib.h>

#include "sprintf_struct.h"

struct sf_flag parserFormat(char *pattern, char fc);
int intToChar(long long val, char *str, size_t *i);
int floatToChar(double val, char *str, size_t *i, int acc);
int lenInt(long long int val);
long unsigned int wcharLen(wchar_t *stroke);
int addSymbols(char *str, size_t *i, char c, int count);
int containtStr(char c, char *str);
#endif