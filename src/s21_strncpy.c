#include "s21_string.h"

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  char *ptr = dest;
  s21_size_t i;
  for (i = 0; i < n && src[i] != '\0'; i++) {
    dest[i] = src[i];
  }
  for (unsigned int j = i; j < n; ++j) {
    dest[j] = '\0';
  }
  return ptr;
}