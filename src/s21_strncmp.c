#include "s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int cmp_result = 0;
  for (s21_size_t i = 0; i < n && !cmp_result && (*str1 || *str2);
       i++, str1++, str2++) {
    if (*str1 != *str2) cmp_result = *str1 - *str2;
  }
  return cmp_result;
}