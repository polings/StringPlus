#include "s21_string_tests.h"

START_TEST(test_memset) {
  const char str[] = "School21 is a programming school";
  const char st[] = " \0";

  ck_assert_ptr_eq(s21_strchr(str, 'o'), strchr(str, 'o'));
  ck_assert_ptr_eq(s21_strchr(str, '\n'), strchr(str, '\n'));
  ck_assert_ptr_eq(s21_strchr(str, '\0'), strchr(str, '\0'));
  ck_assert_ptr_eq(s21_strchr(str + 10, 'g'), strchr(str + 10, 'g'));
  ck_assert_ptr_eq(s21_strchr(str, '3'), strchr(str, '3'));
  ck_assert_ptr_eq(s21_strchr(st, '\0'), strchr(st, '\0'));
  ck_assert_ptr_eq(s21_strchr(st, ' '), strchr(st, ' '));
}
END_TEST

Suite *check_STRCHR(void) {
  Suite *s = suite_create("strchr");
  TCase *test_case = tcase_create("s21_memset_tests");

  tcase_add_test(test_case, test_memset);

  suite_add_tcase(s, test_case);

  return s;
}