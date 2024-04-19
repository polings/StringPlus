#include "s21_string_tests.h"

START_TEST(test_1) { ck_assert_str_eq(s21_strerror(11), strerror(11)); }
END_TEST

START_TEST(test_2) { ck_assert_str_eq(s21_strerror(-3), strerror(-3)); }
END_TEST

START_TEST(test_3) { ck_assert_str_eq(s21_strerror(140), strerror(140)); }
END_TEST

Suite *check_STRERROR(void) {
  Suite *s;
  TCase *tc_core_1, *tc_core_2, *tc_core_3;

  s = suite_create("strerror");

  tc_core_1 = tcase_create("strerror_test_1");
  tcase_add_test(tc_core_1, test_1);
  suite_add_tcase(s, tc_core_1);

  tc_core_2 = tcase_create("strerror_test_2");
  tcase_add_test(tc_core_2, test_2);
  suite_add_tcase(s, tc_core_2);

  tc_core_3 = tcase_create("strerror_test_3");
  tcase_add_test(tc_core_3, test_3);
  suite_add_tcase(s, tc_core_3);

  return s;
}