#include "s21_string_tests.h"

START_TEST(test_1) {
  const char *str = "To Lower";
  char *result = s21_to_lower(str);
  char *expected = "to lower";
  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(test_2) {
  const char *str = "T@ 3Lower";
  char *result = s21_to_lower(str);
  char *expected = "t@ 3lower";
  ck_assert_str_eq(result, expected);
}
END_TEST

Suite *check_TO_LOWER(void) {
  Suite *s;
  TCase *tc_core_1, *tc_core_2;

  s = suite_create("to_lower");

  tc_core_1 = tcase_create("test_1");
  tcase_add_test(tc_core_1, test_1);
  suite_add_tcase(s, tc_core_1);

  tc_core_2 = tcase_create("test_2");
  tcase_add_test(tc_core_2, test_2);
  suite_add_tcase(s, tc_core_2);

  return s;
}