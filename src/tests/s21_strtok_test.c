#include "s21_string_tests.h"

START_TEST(test_1) {
  char str1[] = "Hello, everybody";
  char str2[] = "Hello, everybody";
  char delim[] = ",";
  ck_assert_pstr_eq(s21_strtok(str1, delim), strtok(str2, delim));
}
END_TEST

START_TEST(test_2) {
  char str1[] = "";
  char str2[] = "";
  char delim[] = "";
  ck_assert_pstr_eq(s21_strtok(str1, delim), strtok(str2, delim));
}
END_TEST

START_TEST(test_3) {
  char str1[] = "Hello, everybody";
  char str2[] = "Hello, everybody";
  char delim[] = "";
  ck_assert_pstr_eq(s21_strtok(str1, delim), strtok(str2, delim));
}
END_TEST

START_TEST(test_4) {
  char str1[] = "Hello, everybody";
  char str2[] = "Hello, everybody";
  char delim[] = "l";
  ck_assert_pstr_eq(s21_strtok(str1, delim), strtok(str2, delim));
}
END_TEST

START_TEST(test_5) {
  char str1[] = "Hello, everybody";
  char str2[] = "Hello, everybody";
  char delim[] = ",eb";
  ck_assert_pstr_eq(s21_strtok(str1, delim), strtok(str2, delim));
}
END_TEST

START_TEST(test_6) {
  char str1[] = "\0Hello, world!";
  char str2[] = "\0Hello, world!";
  char delim[] = "\0";
  ck_assert_pstr_eq(s21_strtok(str1, delim), strtok(str2, delim));
}
END_TEST

Suite *check_STRTOK(void) {
  Suite *s;
  TCase *tc_core_1, *tc_core_2, *tc_core_3, *tc_core_4, *tc_core_5, *tc_core_6;

  s = suite_create("strtok");

  tc_core_1 = tcase_create("strtok_test_1");
  tcase_add_test(tc_core_1, test_1);
  suite_add_tcase(s, tc_core_1);

  tc_core_2 = tcase_create("strtok_test_2");
  tcase_add_test(tc_core_2, test_2);
  suite_add_tcase(s, tc_core_2);

  tc_core_3 = tcase_create("strtok_test_3");
  tcase_add_test(tc_core_3, test_3);
  suite_add_tcase(s, tc_core_3);

  tc_core_4 = tcase_create("strtok_test_4");
  tcase_add_test(tc_core_4, test_4);
  suite_add_tcase(s, tc_core_4);

  tc_core_5 = tcase_create("strtok_test_5");
  tcase_add_test(tc_core_5, test_5);
  suite_add_tcase(s, tc_core_5);

  tc_core_6 = tcase_create("strtok_test_6");
  tcase_add_test(tc_core_6, test_6);
  suite_add_tcase(s, tc_core_6);

  return s;
}