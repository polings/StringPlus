#include "s21_string_tests.h"

START_TEST(test_1) {
  char str1[] = "Best test ever";
  char str2[] = "Best";
  ck_assert_int_eq(s21_strncmp(str1, str2, 4), strncmp(str1, str2, 4));
}
END_TEST

START_TEST(test_2) {
  char str1[] = "copy here:";
  char str2[] = "copy";
  ck_assert_int_eq(s21_strncmp(str1, str2, 5), strncmp(str1, str2, 5));
}
END_TEST

START_TEST(test_3) {
  char str1[20] = "maybe";
  char str2[] = " and perhaps";
  ck_assert_int_eq(s21_strncmp(str1, str2, 0), strncmp(str1, str2, 0));
}
END_TEST

START_TEST(test_4) {
  char str1[] = "Best\n test ever";
  char str2[] = "Best\0ever";
  ck_assert_int_eq(s21_strncmp(str1, str2, 4), strncmp(str1, str2, 4));
}
END_TEST

START_TEST(test_5) {
  char str1[] = "1986 \0year - ";
  char str2[] = "2023 year";
  ck_assert_int_eq(s21_strncmp(str1, str2, 7), strncmp(str1, str2, 7));
}
END_TEST

Suite *check_STRNCMP(void) {
  Suite *s = suite_create("strncmp");
  TCase *tc_core = tcase_create("strncmp_test");
  tcase_add_test(tc_core, test_1);
  tcase_add_test(tc_core, test_2);
  tcase_add_test(tc_core, test_3);
  tcase_add_test(tc_core, test_4);
  tcase_add_test(tc_core, test_5);
  suite_add_tcase(s, tc_core);

  return s;
}
