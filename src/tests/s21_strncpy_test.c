#include "s21_string_tests.h"

START_TEST(test_1) {
  char dest[15] = {'\0'};
  const char *src = "strncpy test";
  s21_strncpy(dest, src, 7);
  char expected[15] = "strncpy";
  ck_assert_str_eq(dest, expected);
}
END_TEST

START_TEST(test_2) {
  char dest[15] = {'\0'};
  const char *src = "str";
  s21_strncpy(dest, src, 7);
  char expected[15] = "str";
  ck_assert_str_eq(dest, expected);
}
END_TEST

Suite *check_STRNCPY(void) {
  Suite *s;
  TCase *tc_core_1, *tc_core_2;

  s = suite_create("strncpy");

  tc_core_1 = tcase_create("strncpy_test_1");
  tcase_add_test(tc_core_1, test_1);
  suite_add_tcase(s, tc_core_1);

  tc_core_2 = tcase_create("strncpy_test_2");
  tcase_add_test(tc_core_2, test_2);
  suite_add_tcase(s, tc_core_2);

  return s;
}