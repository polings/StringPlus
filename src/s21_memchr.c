#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  bool flag = 0;
  char const *ptr = (char *)str;

  while (n-- && !flag) {
    if (*ptr == (char)c) {
      flag = 1;
      break;
    }
    ptr++;
  }

  return flag ? (void *)ptr : S21_NULL;
}