#include "s21_string_tests.h"

START_TEST(test_1) {
  char str1[] = "Best test ever";
  char str2[] = "forever";
  ck_assert_str_eq(s21_memcpy(str1, str2, 7), memcpy(str1, str2, 7));
}
END_TEST

START_TEST(test_2) {
  char str1[] = "copy here:";
  char str2[] = " this";
  ck_assert_str_eq(s21_memcpy(str1, str2, 5), memcpy(str1, str2, 5));
}
END_TEST

START_TEST(test_3) {
  char str1[20] = "maybe";
  char str2[] = " and perhaps";
  ck_assert_str_eq(s21_memcpy(str1, str2, 12), memcpy(str1, str2, 12));
}
END_TEST

START_TEST(test_4) {
  char str1[] = "Best\n test ever";
  char str2[] = "for\0ever";
  ck_assert_str_eq(s21_memcpy(str1, str2, 5), memcpy(str1, str2, 5));
}
END_TEST

START_TEST(test_5) {
  char str1[] = "1986 \0year - ";
  char str2[] = "2023 year";
  ck_assert_str_eq(s21_memcpy(str1, str2, 4), memcpy(str1, str2, 4));
}
END_TEST
START_TEST(test_6) {
  char str1[] = "\01986 year - ";
  char str2[] = "2023 year";
  ck_assert_str_eq(s21_memcpy(str1, str2, 0), memcpy(str1, str2, 0));
}
END_TEST

Suite *check_MEMCPY(void) {
  Suite *s = suite_create("memcpy");
  TCase *tc_core = tcase_create("memcpy_test");
  tcase_add_test(tc_core, test_1);
  tcase_add_test(tc_core, test_2);
  tcase_add_test(tc_core, test_3);
  tcase_add_test(tc_core, test_4);
  tcase_add_test(tc_core, test_5);
  tcase_add_test(tc_core, test_6);
  suite_add_tcase(s, tc_core);

  return s;
}