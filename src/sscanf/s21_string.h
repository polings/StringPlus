#ifndef S21_SSCANF_H
#define S21_SSCANF_H

#include <math.h>
#include <stdarg.h>
#include <stdio.h>

#include "../s21_string.h"

typedef long unsigned s21_size_t;

typedef struct specifiers {
  int star;
  int h;
  int l;
  int L;
  int i;
  int d;
  int o;
  int u;
  int xX;
  int p;
  int unsig;
  int startRead;
  int flagSuccessWrite;
} specifiers;

int charToInt(const char* str, specifiers* mySpec, int* i, long int* num,
              int lim, int* countSymbols);
int write_c(const char* str, int* iterStr, int* mnt_n, specifiers* mySpec,
            va_list args);
int write_s(const char* str, int* iterStr, int lim, int* mnt_n,
            specifiers* mySpec, va_list args);
void write_n(const int mnt_n, specifiers* mySpec, va_list args);
int write_diouxX(const char* str, specifiers* mySpec, int* iterStr, int* mnt_n,
                 int lim, int* flWork, va_list args);
int write_eEfgG(const char* str, specifiers* mySpec, int* iterStr, int* mnt_n,
                int lim, int* flWork, va_list args);
int s21_sscanf(char* str, const char* format, ...);

#endif