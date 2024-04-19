#include "s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  const char *ret = S21_NULL;
  const char *p1 = str1;
  int match = 0;
  while (*p1 != '\0' && !match) {
    const char *p2 = str2;
    while (*p2 != '\0' && !match) {
      if (*p1 == *p2) {
        match = 1;
        ret = p1;
      }
      p2++;
    }
    p1++;
  }
  return (char *)ret;
}