#include "s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *next_token = S21_NULL;
  if (str) {
    next_token = str;
    while (s21_strchr(delim, *next_token)) {
      *next_token++ = '\0';
    }
  }
  int token = 0;
  if (!*next_token) {
    token = 1;
  } else {
    str = next_token;
    while (*next_token && !s21_strchr(delim, *next_token)) next_token++;
    while (*next_token && s21_strchr(delim, *next_token)) *next_token++ = '\0';
  }
  return token ? S21_NULL : str;
}
