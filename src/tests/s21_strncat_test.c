#include "s21_string_tests.h"

START_TEST(test_1) {
  char dest[100] = "Hello, ";
  char src[100] = "everybody!";
  ck_assert_str_eq(s21_strncat(dest, src, 10), strncat(dest, src, 10));
}
END_TEST

START_TEST(test_2) {
  char dest[100] = "Hello";
  char src[100] = "";
  ck_assert_str_eq(s21_strncat(dest, src, 3), strncat(dest, src, 3));
}
END_TEST

START_TEST(test_3) {
  char dest[100] = "";
  char src[100] = "";
  ck_assert_str_eq(s21_strncat(dest, src, 3), strncat(dest, src, 3));
}
END_TEST

START_TEST(test_4) {
  char dest[100] = "906326";
  char src[100] = "8888";
  ck_assert_str_eq(s21_strncat(dest, src, 6), strncat(dest, src, 6));
}
END_TEST

START_TEST(test_5) {
  char dest[100] = "906326";
  char src[100] = "8888";
  ck_assert_str_eq(s21_strncat(dest, src, 3), strncat(dest, src, 3));
}
END_TEST

START_TEST(test_6) {
  char dest[100] = "906326";
  char src[100] = "concatinate8888";
  ck_assert_str_eq(s21_strncat(dest, src, 11), strncat(dest, src, 11));
}
END_TEST

START_TEST(test_7) {
  char dest[100] = "Euler num: ";
  char src[100] = "2.718281828459045235360287471352...";
  ck_assert_str_eq(s21_strncat(dest, src, 10), strncat(dest, src, 10));
}
END_TEST

START_TEST(test_8) {
  char dest[100] = "               ";
  char src[100] = "<- this is backspace";
  ck_assert_str_eq(s21_strncat(dest, src, 20), strncat(dest, src, 20));
}
END_TEST

Suite *check_STRNCAT(void) {
  Suite *s;
  TCase *tc_core_1, *tc_core_2, *tc_core_3, *tc_core_4, *tc_core_5, *tc_core_6,
      *tc_core_7, *tc_core_8;

  s = suite_create("strncat");

  tc_core_1 = tcase_create("strncat_test_1");
  tcase_add_test(tc_core_1, test_1);
  suite_add_tcase(s, tc_core_1);

  tc_core_2 = tcase_create("strncat_test_2");
  tcase_add_test(tc_core_2, test_2);
  suite_add_tcase(s, tc_core_2);

  tc_core_3 = tcase_create("strncat_test_3");
  tcase_add_test(tc_core_3, test_3);
  suite_add_tcase(s, tc_core_3);

  tc_core_4 = tcase_create("strncat_test_4");
  tcase_add_test(tc_core_4, test_4);
  suite_add_tcase(s, tc_core_4);

  tc_core_5 = tcase_create("strncat_test_5");
  tcase_add_test(tc_core_5, test_5);
  suite_add_tcase(s, tc_core_5);

  tc_core_6 = tcase_create("strncat_test_6");
  tcase_add_test(tc_core_6, test_6);
  suite_add_tcase(s, tc_core_6);

  tc_core_7 = tcase_create("strncat_test_7");
  tcase_add_test(tc_core_7, test_7);
  suite_add_tcase(s, tc_core_7);

  tc_core_8 = tcase_create("strncat_test_8");
  tcase_add_test(tc_core_8, test_8);
  suite_add_tcase(s, tc_core_8);

  return s;
}