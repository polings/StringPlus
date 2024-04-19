#include "s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *new_str = S21_NULL;
  if (src && str) {
    s21_size_t src_len = s21_strlen(src);
    s21_size_t str_len = s21_strlen(str);
    s21_size_t total_len = src_len + str_len + 1;
    if (start_index <= src_len) {
      new_str = (char *)malloc(sizeof(char *) * (total_len + 1));
      if (new_str != S21_NULL) {
        s21_size_t i = 0, j = 0, k = 0;
        while (i < start_index) {
          new_str[i] = src[i];
          i++;
          k++;
        }
        while (i < start_index + str_len) {
          new_str[i] = str[j];
          i++;
          j++;
        }
        while (i < total_len) {
          new_str[i] = src[k];
          i++;
          k++;
        }
        new_str[i] = '\0';
      }
    }
  }
  return new_str;
}