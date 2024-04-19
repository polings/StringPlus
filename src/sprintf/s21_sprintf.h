#ifndef S21_SPRINTF_H
#define S21_SPRINTF_H
#include <locale.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>

#include "sf_parsesr.h"

int s21_sprintf(char* str, const char* format, ...);
int fl_c(va_list factor, char* str, size_t* i, char* pattern, char fc);
int fl_d_u_i(va_list factor, char* str, size_t* i, char* pattern, char fc);
int d_u_i_not_dot(char* str, size_t* i, struct sf_flag flag, va_list factor,
                  char fc);
int d_u_i_is_dot(char* str, size_t* i, struct sf_flag flag, va_list factor,
                 char fc);
void get_value_d_u(unsigned long* value_u, long long* value_d,
                   long long* lenValue, struct sf_flag flag, va_list factor,
                   char fc);
int fl_f(char* str, size_t* i, char* pattern, va_list factor, char fc);
void f_dot(char* str, size_t* i, sf_flag flag, long double value);
void f_is_dot(char* str, size_t* i, sf_flag flag, long double value);
int flag_s(va_list factor, char* str, size_t* i, char* pattern, char fc);
void flag_s_wchar(char* str, size_t* i, va_list factor, sf_flag flag,
                  long long len);
void flag_s_char(char* str, size_t* i, va_list factor, sf_flag flag,
                 long long len);
#endif