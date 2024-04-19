#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  char *result = S21_NULL;
  s21_size_t needle_len = s21_strlen(needle);
  s21_size_t haystack_len = s21_strlen(haystack);
  if (needle_len > haystack_len) {
    return S21_NULL;
  }
  if (*needle == '\0') {
    result = (char *)haystack;
  } else {
    for (s21_size_t i = 0; i <= haystack_len - needle_len; ++i) {
      if (s21_strncmp(&haystack[i], needle, needle_len) == 0) {
        result = &((char *)haystack)[i];
      }
    }
  }
  return result;
}