#include "s21_string_tests.h"

START_TEST(test_1) {
  char *ins = s21_insert("prunes", "ga", 6);
  ck_assert_str_eq(ins, "prunesga");
  free(ins);
}
END_TEST

START_TEST(test_2) {
  char *ins = s21_insert("ga", "prunes", 0);
  ck_assert_str_eq(ins, "prunesga");
  free(ins);
}
END_TEST

START_TEST(test_3) {
  char *ins = s21_insert("pruga", "nes", 3);
  ck_assert_str_eq(ins, "prunesga");
  free(ins);
}
END_TEST

START_TEST(test_4) {
  char *ins = s21_insert("prunes", "ga", -10);
  ck_assert_ptr_null(ins);
  free(ins);
}
END_TEST

START_TEST(test_5) {
  char *ins = s21_insert("prunes", "ga", 20);
  ck_assert_ptr_null(ins);
  free(ins);
}
END_TEST

START_TEST(test_6) {
  char *ins = s21_insert("prunesga", "", 4);
  ck_assert_str_eq(ins, "prunesga");
  free(ins);
}
END_TEST

START_TEST(test_7) {
  char *ins = s21_insert("", "prunesga", 0);
  ck_assert_str_eq(ins, "prunesga");
  free(ins);
}
END_TEST

START_TEST(test_8) {
  char *ins = s21_insert("", "", 0);
  ck_assert_str_eq(ins, "");
  free(ins);
}
END_TEST

Suite *check_INSERT(void) {
  Suite *s = suite_create("insert");
  TCase *tc_core = tcase_create("insert_test");
  tcase_add_test(tc_core, test_1);
  tcase_add_test(tc_core, test_2);
  tcase_add_test(tc_core, test_3);
  tcase_add_test(tc_core, test_4);
  tcase_add_test(tc_core, test_5);
  tcase_add_test(tc_core, test_6);
  tcase_add_test(tc_core, test_7);
  tcase_add_test(tc_core, test_8);
  suite_add_tcase(s, tc_core);

  return s;
}