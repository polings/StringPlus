#include "s21_string_tests.h"

START_TEST(test_1) {
  char *str1 = "Hello, everybody!";
  char *str2 = "e";
  ck_assert_str_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(test_2) {
  char *str1 = "Hello, everybody!";
  char *str2 = "yvl";
  ck_assert_str_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(test_3) {
  char *str1 = "Hello, everybody!";
  char *str2 = "";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(test_4) {
  char *str1 = "Hello, everybody!";
  char *str2 = "@";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(test_5) {
  char *str1 = "Hello, everybody!";
  char *str2 = "\0";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

Suite *check_STRPBRK(void) {
  Suite *s;
  TCase *tc_core_1, *tc_core_2, *tc_core_3, *tc_core_4, *tc_core_5;

  s = suite_create("strpbrk");

  tc_core_1 = tcase_create("strpbrk_test_1");
  tcase_add_test(tc_core_1, test_1);
  suite_add_tcase(s, tc_core_1);

  tc_core_2 = tcase_create("strpbrk_test_2");
  tcase_add_test(tc_core_2, test_2);
  suite_add_tcase(s, tc_core_2);

  tc_core_3 = tcase_create("strpbrk_test_3");
  tcase_add_test(tc_core_3, test_3);
  suite_add_tcase(s, tc_core_3);

  tc_core_4 = tcase_create("strpbrk_test_4");
  tcase_add_test(tc_core_4, test_4);
  suite_add_tcase(s, tc_core_4);

  tc_core_5 = tcase_create("strpbrk_test_5");
  tcase_add_test(tc_core_5, test_5);
  suite_add_tcase(s, tc_core_5);

  return s;
}