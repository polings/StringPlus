#include "s21_string_tests.h"

START_TEST(test_1) {
  char *str = "Hello everybody";
  int c = 'o';
  ck_assert_str_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(test_2) {
  char *str = "Hello everybody";
  int c = 'h';
  ck_assert_pstr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(test_3) {
  char *str = "Hello everybody";
  int c = '\0';
  ck_assert_pstr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(test_4) {
  char *str = "Hello everybody";
  int c = 'K';
  ck_assert_pstr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

Suite *check_STRRCHR(void) {
  Suite *s;
  TCase *tc_core_1, *tc_core_2, *tc_core_3, *tc_core_4;

  s = suite_create("strrchr");

  tc_core_1 = tcase_create("strrchr_test_1");
  tcase_add_test(tc_core_1, test_1);
  suite_add_tcase(s, tc_core_1);

  tc_core_2 = tcase_create("strrchr_test_2");
  tcase_add_test(tc_core_2, test_2);
  suite_add_tcase(s, tc_core_2);

  tc_core_3 = tcase_create("strrchr_test_3");
  tcase_add_test(tc_core_3, test_3);
  suite_add_tcase(s, tc_core_3);

  tc_core_4 = tcase_create("strrchr_test_4");
  tcase_add_test(tc_core_4, test_4);
  suite_add_tcase(s, tc_core_4);

  return s;
}