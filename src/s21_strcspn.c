#include "s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  bool flag = false;
  s21_size_t j = 0, i = 0;

  while (i < s21_strlen(str1)) {
    while (!flag && j < s21_strlen(str2)) {
      if (str1[i] == str2[j++]) flag = true;
    }
    if (!flag) {
      j = 0;
      i++;
    } else
      break;
  }
  return i;
}