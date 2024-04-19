#include "s21_string_tests.h"

START_TEST(test_memset) {
  char str[] = "School21 is a programming school";
  char str2[] = "School21 is a programming school";
  char st[] = " \0";
  char st2[] = " \0";

  ck_assert_str_eq(s21_memset(str, 'o', 10), memset(str2, 'o', 10));
  ck_assert_str_eq(s21_memset(str, '\n', 10), memset(str2, '\n', 10));
  ck_assert_str_eq(s21_memset(str, '\0', 10), memset(str2, '\0', 10));
  ck_assert_str_eq(s21_memset(str, 'g', 1), memset(str2, 'g', 1));
  ck_assert_str_eq(s21_memset(str + 3, 'o', 10), memset(str2 + 3, 'o', 10));
  ck_assert_str_eq(s21_memset(str, '2', strlen(str)),
                   memset(str2, '2', strlen(str2)));
  ck_assert_str_eq(s21_memset(str, 'm', strlen(str) + 10),
                   memset(str2, 'm', strlen(str2) + 10));
  ck_assert_str_eq(s21_memset(st, '1', strlen(st)),
                   memset(st2, '1', strlen(st2)));
  ck_assert_str_eq(s21_memset(st, ' ', strlen(st)),
                   memset(st2, ' ', strlen(st2)));
}
END_TEST

Suite *check_MEMSET(void) {
  Suite *s = suite_create("memset");
  TCase *test_case = tcase_create("s21_memset_tests");

  tcase_add_test(test_case, test_memset);

  suite_add_tcase(s, test_case);

  return s;
}