#include "s21_string.h"

void *s21_to_lower(const char *str) {
  char *res;
  void *temp = S21_NULL;
  res = (char *)malloc(s21_strlen(str) * sizeof(char) + 1);
  unsigned int i = 0;
  while (i <= s21_strlen(str)) {
    if (str[i] >= 65 && str[i] <= 90) {
      res[i] = str[i] + 32;
    } else {
      res[i] = str[i];
    }
    i++;
  }
  temp = (void *)res;
  return temp;
}