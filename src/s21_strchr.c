#include "s21_string.h"

char *s21_strchr(const char *str, int c) {
  char *return_value;
  while (*str != c && *str != '\0') {
    str++;
  }
  if (*str == c) {
    return_value = (char *)str;
  } else {
    return_value = S21_NULL;
  }
  return return_value;
}