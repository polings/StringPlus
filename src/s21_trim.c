#include "s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  char *result = S21_NULL;
  if (!trim_chars || !trim_chars[0]) trim_chars = "\t\n ";

  if (src) {
    char *ptr_start = (char *)src;
    char *ptr_end = (char *)src + s21_strlen(src) - 1;
    while (*ptr_start && s21_strchr(trim_chars, *ptr_start)) ptr_start++;
    if (!*ptr_start) ptr_end = ptr_start;
    while (*ptr_end && s21_strchr(trim_chars, *ptr_end)) ptr_end--;
    result = (char *)calloc(ptr_end - ptr_start + 2, sizeof(char));
    if (result) {
      s21_strncpy(result, ptr_start, ptr_end - ptr_start + 1);
    }
  }
  return result;
}
