#include "s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  unsigned char *p1 = (unsigned char *)str1, *p2 = (unsigned char *)str2;

  int cmp_result = 0;

  for (s21_size_t i = 0; i < n && !cmp_result; i++ /*, p1++, p2++*/) {
    if (*(p1 + i) != *(p2 + i)) cmp_result = (int)*(p1 + i) - (int)*(p2 + i);
  }

  return cmp_result;
}