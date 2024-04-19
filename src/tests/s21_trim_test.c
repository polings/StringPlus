#include "s21_string_tests.h"

START_TEST(test_trim_01) {
  const char str[] = "*** .Much Ado About. Nothing\\***";
  const char str2[] = "*** .Much Ado \\About. Nothing\\***";
  const char st[] = ".* \\";

  ck_assert_str_eq((char *)s21_trim(str, st), "Much Ado About. Nothing");
  ck_assert_str_eq((char *)s21_trim(st, st), "");
  ck_assert_str_eq((char *)s21_trim(str2, st), "Much Ado \\About. Nothing");
  ck_assert_str_eq((char *)s21_trim(str, "\n"),
                   "*** .Much Ado About. Nothing\\***");
  ck_assert_str_eq((char *)s21_trim(str, "\0"),
                   "*** .Much Ado About. Nothing\\***");
}
END_TEST

START_TEST(test_trim_02) {
  char s1[30] = "-?hello, world!";
  char s3[] = "!?-";
  char s4[] = "hello, world";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_trim_03) {
  char s1[30] = "";
  char s3[] = "";
  char *s4 = "";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_trim_04) {
  char *s1 = S21_NULL;
  char s3[] = "";
  char *s4 = S21_NULL;
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_trim_05) {
  char s1[30] = "!!!prunesga!?!";
  char s3[] = "!?";
  char s4[] = "prunesga";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_trim_06) {
  char s1[] = " arborio ";
  char *s3 = "";
  char *s4 = "arborio";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_trim_07) {
  char *s1 = S21_NULL;
  char *s3 = S21_NULL;
  char *s4 = S21_NULL;
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

Suite *check_TRIM(void) {
  Suite *s = suite_create("trim");
  TCase *test_case = tcase_create("s21_trim_tests");

  tcase_add_test(test_case, test_trim_01);
  tcase_add_test(test_case, test_trim_02);
  tcase_add_test(test_case, test_trim_03);
  tcase_add_test(test_case, test_trim_04);
  tcase_add_test(test_case, test_trim_05);
  tcase_add_test(test_case, test_trim_06);
  tcase_add_test(test_case, test_trim_07);

  suite_add_tcase(s, test_case);

  return s;
}