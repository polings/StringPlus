#include "s21_string_tests.h"

START_TEST(test_1) {
  char str[] = "Best test ever";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(test_2) {
  char str[] = "Prunesga1986";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(test_3) {
  char str[] = "";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST
START_TEST(test_4) {
  char str[] = "\0fgdfsrtert";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST
START_TEST(test_5) {
  char str[] = "vera$tet*/";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

Suite *check_STRLEN(void) {
  Suite *s = suite_create("strlen");
  TCase *tc_core = tcase_create("strlen_test");
  tcase_add_test(tc_core, test_1);
  tcase_add_test(tc_core, test_2);
  tcase_add_test(tc_core, test_3);
  tcase_add_test(tc_core, test_4);
  tcase_add_test(tc_core, test_5);
  suite_add_tcase(s, tc_core);

  return s;
}
