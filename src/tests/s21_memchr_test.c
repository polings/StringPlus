#include "s21_string_tests.h"

START_TEST(test_memchr) {
  const char str[] = "School21 is a programming school";
  const char st[] = " \0";

  ck_assert_ptr_eq(s21_memchr(str, 'o', 10), memchr(str, 'o', 10));
  ck_assert_ptr_eq(s21_memchr(str, 'g', 1), memchr(str, 'g', 1));
  ck_assert_ptr_eq(s21_memchr(str, '2', strlen(str)),
                   memchr(str, '2', strlen(str)));
  ck_assert_ptr_eq(s21_memchr(str, 'z', strlen(str)),
                   memchr(str, 'z', strlen(str)));
  ck_assert_ptr_eq(s21_memchr(str, 'm', strlen(str) + 10),
                   memchr(str, 'm', strlen(str) + 10));
  ck_assert_ptr_eq(s21_memchr(str, 'm', 0), memchr(str, 'm', 0));
  ck_assert_ptr_eq(s21_memchr(st, '\0', strlen(st)),
                   memchr(st, '\0', strlen(st)));
  ck_assert_ptr_eq(s21_memchr(st, ' ', strlen(st)),
                   memchr(st, ' ', strlen(st)));
}
END_TEST

Suite *check_MEMCHR(void) {
  Suite *s;
  TCase *test_case = tcase_create("s21_memchr_tests");

  s = suite_create("memchr");

  tcase_add_test(test_case, test_memchr);
  suite_add_tcase(s, test_case);

  return s;
}