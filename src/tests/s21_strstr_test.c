#include "s21_string_tests.h"

START_TEST(test_1) {
  char *haystack = "Hello, everybody!";
  char *needle = "o, ev";
  ck_assert_str_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(test_2) {
  char *haystack = "Hello, everybody!";
  char *needle = "Hy";
  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(test_3) {
  char *haystack = "Hello, everybody!";
  char *needle = ",";
  ck_assert_str_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(test_4) {
  char *haystack = "Hello, everybody!";
  char *needle = "@";
  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(test_5) {
  char *haystack = "Hello, everybody!";
  char *needle = "\0";
  ck_assert_str_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(test_6) {
  char *haystack = "Hello";
  char *needle = "Hello, everybody!";
  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

Suite *check_STRSTR(void) {
  Suite *s;
  TCase *tc_core_1, *tc_core_2, *tc_core_3, *tc_core_4, *tc_core_5, *tc_core_6;

  s = suite_create("strstr");

  tc_core_1 = tcase_create("strstr_test_1");
  tcase_add_test(tc_core_1, test_1);
  suite_add_tcase(s, tc_core_1);

  tc_core_2 = tcase_create("strstr_test_2");
  tcase_add_test(tc_core_2, test_2);
  suite_add_tcase(s, tc_core_2);

  tc_core_3 = tcase_create("strstr_test_3");
  tcase_add_test(tc_core_3, test_3);
  suite_add_tcase(s, tc_core_3);

  tc_core_4 = tcase_create("strstr_test_4");
  tcase_add_test(tc_core_4, test_4);
  suite_add_tcase(s, tc_core_4);

  tc_core_5 = tcase_create("strstr_test_5");
  tcase_add_test(tc_core_5, test_5);
  suite_add_tcase(s, tc_core_5);

  tc_core_6 = tcase_create("strstr_test_5");
  tcase_add_test(tc_core_6, test_6);
  suite_add_tcase(s, tc_core_6);

  return s;
}