#include "s21_string_tests.h"

START_TEST(just_string) {
  char str[11] = "juststring";
  char myStr[11] = {"\0"};
  char origStr[11] = {"\0"};
  s21_sscanf(str, "%s", myStr);
  sscanf(str, "%s", origStr);
  ck_assert_str_eq(myStr, origStr);
}
END_TEST

START_TEST(two_string) {
  char str[15] = "This is string";
  char myStr1[15] = {"\0"};
  char myStr2[15] = {"\0"};
  char origStr1[15] = {"\0"};
  char origStr2[15] = {"\0"};
  s21_sscanf(str, "%s%s", myStr1, myStr2);
  sscanf(str, "%s%s", origStr1, origStr2);
  ck_assert_str_eq(myStr1, origStr1);
  ck_assert_str_eq(myStr2, origStr2);
}
END_TEST

START_TEST(s_with_d_spec) {
  char str[15] = "228 string";
  char myStr[10] = {"\0"};
  char origStr[10] = {"\0"};
  int myNum;
  int origNum;
  s21_sscanf(str, "%d%s", &myNum, myStr);
  sscanf(str, "%d%s", &origNum, origStr);
  ck_assert_str_eq(myStr, origStr);
}
END_TEST

START_TEST(s_without_record) {
  char str[15] = "228 string";
  char myStr[10] = {"\0"};
  char origStr[10] = {"\0"};
  int myNum;
  int origNum;
  ck_assert_int_eq(s21_sscanf(str, "%d%*s", &myNum),
                   sscanf(str, "%d%*s", &origNum));
  ck_assert_str_eq(myStr, origStr);
}
END_TEST

START_TEST(mnt_record) {
  char str[15] = "This is string";
  char myStr1[10];
  char myStr2[10];
  char origStr1[10];
  char origStr2[10];
  ck_assert_int_eq(s21_sscanf(str, "%s is %s", myStr1, myStr2),
                   sscanf(str, "%s is %s", origStr1, origStr2));
}
END_TEST

Suite* check_sscanf_s(void) {
  Suite* s;
  TCase *tc_justStr, *tc_twoStr, *tc_sd, *tc_sWoutRec, *tc_mntRec;
  s = suite_create("sscanf_s");
  tc_justStr = tcase_create("justStr");
  tcase_add_test(tc_justStr, just_string);
  suite_add_tcase(s, tc_justStr);
  tc_twoStr = tcase_create("twoStr");
  tcase_add_test(tc_twoStr, two_string);
  suite_add_tcase(s, tc_twoStr);
  tc_sd = tcase_create("sd");
  tcase_add_test(tc_sd, s_with_d_spec);
  suite_add_tcase(s, tc_sd);
  tc_sWoutRec = tcase_create("sWoutRec");
  tcase_add_test(tc_sWoutRec, s_without_record);
  suite_add_tcase(s, tc_sWoutRec);
  tc_mntRec = tcase_create("mntRec");
  tcase_add_test(tc_mntRec, mnt_record);
  suite_add_tcase(s, tc_mntRec);
  return s;
}