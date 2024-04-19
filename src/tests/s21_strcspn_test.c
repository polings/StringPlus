#include "s21_string_tests.h"

START_TEST(test_strcspn) {
  const char str[] = "School21 is a programming school";
  const char st[] = " \0";

  ck_assert_int_eq(s21_strcspn(str, "Sch"), strcspn(str, "Sch"));
  ck_assert_int_eq(s21_strcspn(str, "is"), strcspn(str, "is"));
  ck_assert_int_eq(s21_strcspn(str, str), strcspn(str, str));
  ck_assert_int_eq(s21_strcspn(str, st), strcspn(str, st));
  ck_assert_int_eq(s21_strcspn(str + 3, " "), strcspn(str + 3, " "));
  ck_assert_int_eq(s21_strcspn(st, "\0"), strcspn(st, "\0"));
  ck_assert_int_eq(s21_strcspn(str, "z"), strcspn(str, "z"));
}
END_TEST

Suite *check_STRCSPN(void) {
  Suite *s = suite_create("strcspn");
  TCase *test_case = tcase_create("s21_strcspn_tests");

  tcase_add_test(test_case, test_strcspn);

  suite_add_tcase(s, test_case);

  return s;
}