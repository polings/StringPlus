#include "s21_string_tests.h"

START_TEST(n_spec_with_c) {
  char str[3] = "a c";
  char ch1 = 0;
  char ch2 = 0;
  int mnt = 0;
  s21_sscanf(str, "%c %c%n", &ch1, &ch2, &mnt);
  ck_assert_int_eq(mnt, 3);
}
END_TEST

START_TEST(n_spec_with_s) {
  char str[7] = "string";
  char str1[10] = {"\0"};
  int mnt = 0;
  s21_sscanf(str, "%s%n", str1, &mnt);
  ck_assert_int_eq(mnt, 6);
}
END_TEST

START_TEST(n_spec_with_d) {
  char str[3] = "123";
  int num;
  int mnt;
  s21_sscanf(str, "%d%n", &num, &mnt);
  ck_assert_int_eq(mnt, 3);
}
END_TEST

START_TEST(n_spec_with_i_len) {
  char str[5] = "12345";
  int num;
  int mnt;
  s21_sscanf(str, "%3i%n", &num, &mnt);
  ck_assert_int_eq(mnt, 3);
}
END_TEST

Suite *check_sscanf_n(void) {
  Suite *s;
  TCase *tc_nc, *tc_nd, *tc_ns, *tc_nilen;

  s = suite_create("sscanf_n");

  tc_nc = tcase_create("nc");
  tcase_add_test(tc_nc, n_spec_with_c);
  suite_add_tcase(s, tc_nc);

  tc_nd = tcase_create("nd");
  tcase_add_test(tc_nd, n_spec_with_d);
  suite_add_tcase(s, tc_nd);

  tc_ns = tcase_create("ns");
  tcase_add_test(tc_ns, n_spec_with_s);
  suite_add_tcase(s, tc_ns);

  tc_nilen = tcase_create("nilen");
  tcase_add_test(tc_nilen, n_spec_with_i_len);
  suite_add_tcase(s, tc_nilen);

  return s;
}