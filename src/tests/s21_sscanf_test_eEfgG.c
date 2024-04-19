#include "s21_string_tests.h"

START_TEST(just_num) {
  char format[5][5] = {"%e", "%E", "%2f", "%3g", "%4G"};
  char str[19][20] = {"-21",       "-20.123123", "-20.12312", "-20.1231",
                      "-20.123",   "-20.12",     "-20.1",     "-20.000000",
                      "-0.212121", "0.000000",   "0.212121",  "20.000000",
                      "20.1",      "20.12",      "20.123",    "20.1234",
                      "20.12345",  "20.123456",  "21.0"};
  float myNum = 0.0, origNum = 0.0;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 19; j++) {
      s21_sscanf(str[j], format[i], &myNum);
      sscanf(str[j], format[i], &origNum);
      ck_assert_float_eq(myNum, origNum);
    }
  }
}
END_TEST

START_TEST(just_scientific_notation) {
  char format[5][5] = {"%4e", "%3E", "%2f", "%g", "%G"};
  char str[10][10] = {"-4e-4", "-3e3", "-2e-2", "-1e1", "0e0",
                      "1e-1",  "2e2",  "3e-3",  "4e4"};
  float myNum = 0.0, origNum = 0.0;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j <= 9; j++) {
      s21_sscanf(str[j], format[i], &myNum);
      sscanf(str[j], format[i], &origNum);
      ck_assert_float_eq(myNum, origNum);
    }
  }
}
END_TEST

START_TEST(dificult_numbers) {
  char format[6][6] = {"%4e", "%3E", "%2f", "%g", "%G"};
  char str[10][10] = {"-4.1234e-4", "-3.123e3", "-2.12e-2", "-1.1e1",  "0.0e0",
                      "1.1e-1",     "2.12e2",   "3.123e-3", "4.1234e4"};
  float myNum = 0.0, origNum = 0.0;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j <= 9; j++) {
      s21_sscanf(str[j], format[i], &myNum);
      sscanf(str[j], format[i], &origNum);
      ck_assert_float_eq(myNum, origNum);
    }
  }
}
END_TEST

START_TEST(combinations_specifiers) {
  char myChar = 0;
  char origChar = 0;

  char myStr[10] = {"\0"};
  char origStr[10] = {"\0"};

  int myInt = 0;
  int origInt = 0;

  int myMnt = 0;
  int origMnt = 0;

  float myValue = 0.0;
  float origValue = 0.0;

  s21_sscanf("S21.42", "%c%e", &myChar, &myValue);
  sscanf("S21.42", "%c%e", &origChar, &origValue);
  ck_assert_int_eq(myValue, origValue);

  s21_sscanf("SCHOOL 21.42", "%s%E", myStr, &myValue);
  sscanf("SCHOOL 21.42", "%s%E", origStr, &origValue);
  ck_assert_int_eq(myValue, origValue);

  s21_sscanf("228 21.42", "%d%g", &myInt, &myValue);
  sscanf("228 21.42", "%d%g", &origInt, &origValue);
  ck_assert_int_eq(myValue, origValue);

  s21_sscanf("21.42", "%G%n", &myValue, &myMnt);
  sscanf("21.42", "%G%n", &origValue, &origMnt);
  ck_assert_int_eq(myValue, origValue);
}
END_TEST

START_TEST(long_double_test) {
  char format[5][5] = {"%4e", "%3E", "%2f", "%g", "%G"};
  char str[10][10] = {"-4e-14", "-3e13", "-2e-12", "-1e11", "0e0",
                      "1e-11",  "2e12",  "3e-13",  "4e14"};
  float myNum = 0.0, origNum = 0.0;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j <= 9; j++) {
      s21_sscanf(str[j], format[i], &myNum);
      sscanf(str[j], format[i], &origNum);
      ck_assert_float_eq(myNum, origNum);
    }
  }
}
END_TEST

START_TEST(mnt_record) {
  char format[5][5] = {"%e", "%E", "%2f", "%3g", "%4G"};
  char str[20][20] = {"-21",       "-20.123123", "-20.12312", "-20.1231",
                      "-20.123",   "-20.12",     "-20.1",     "-20.000000",
                      "-0.212121", "0.000000",   "0.212121",  "20.000000",
                      "20.1",      "20.12",      "20.123",    "20.1234",
                      "20.12345",  "20.123456",  "21"};
  float myNum = 0.0, origNum = 0.0;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j <= 19; j++) {
      ck_assert_int_eq(s21_sscanf(str[j], format[i], &myNum),
                       sscanf(str[j], format[i], &origNum));
    }
  }
}
END_TEST

START_TEST(long_num) {
  char format[5][5] = {"%Lf"};
  char str[19][20] = {"-123.123", "123.123"};
  long double myNum = 0.0, origNum = 0.0;
  for (int i = 0; i < 1; i++) {
    for (int j = 0; j < 2; j++) {
      myNum = 0.0;
      origNum = 0.0;
      s21_sscanf(str[j], format[i], &myNum);
      sscanf(str[j], format[i], &origNum);
      ck_assert_double_eq(myNum, origNum);
    }
  }
}
END_TEST

Suite *check_sscanf_eEfgG(void) {
  Suite *s;
  TCase *tc_justNum, *tc_justSienNot, *tc_difNum, *tc_combSpec,
      *tc_longDoublTest, *tc_mntRec, *tc_long_num;

  s = suite_create("sscanf_eEfgG");

  tc_justNum = tcase_create("justNum");
  tcase_add_test(tc_justNum, just_num);
  suite_add_tcase(s, tc_justNum);

  tc_justSienNot = tcase_create("justSienNot");
  tcase_add_test(tc_justSienNot, just_scientific_notation);
  suite_add_tcase(s, tc_justSienNot);

  tc_difNum = tcase_create("difNum");
  tcase_add_test(tc_difNum, dificult_numbers);
  suite_add_tcase(s, tc_difNum);

  tc_combSpec = tcase_create("combSpec");
  tcase_add_test(tc_difNum, combinations_specifiers);
  suite_add_tcase(s, tc_combSpec);

  tc_longDoublTest = tcase_create("longDoublTest");
  tcase_add_test(tc_difNum, long_double_test);
  suite_add_tcase(s, tc_longDoublTest);

  tc_mntRec = tcase_create("mntRec");
  tcase_add_test(tc_difNum, mnt_record);
  suite_add_tcase(s, tc_mntRec);

  tc_long_num = tcase_create("long_num");
  tcase_add_test(tc_long_num, long_num);
  suite_add_tcase(s, tc_long_num);

  return s;
}