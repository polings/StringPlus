#include "s21_string_tests.h"

START_TEST(mnt_record) {
  char c[2] = {"\0"};
  char myChar;
  char origChar;
  for (int i = 0; i < 128; i++) {
    c[0] = i;
    ck_assert_int_eq(s21_sscanf(c, "%c", &myChar), sscanf(c, "%c", &origChar));
  }
}
END_TEST

START_TEST(one_char) {
  char c[2] = {"\0"};
  char myChar = 0;
  char origChar = 0;
  for (int i = 0; i < 128; i++) {
    c[0] = (char)i;
    s21_sscanf(c, "%c", &myChar);
    sscanf(c, "%c", &origChar);
    ck_assert_int_eq(myChar, origChar);
  }
}
END_TEST

START_TEST(one_char_without_write) {
  char c[2] = {"\0"};
  char myChar = 0;
  char origChar = 0;
  for (int i = 0; i < 128; i++) {
    c[0] = i;
    s21_sscanf(c, "%*c", &myChar);
    sscanf(c, "%*c");
    ck_assert_int_eq(myChar, origChar);
  }
}
END_TEST

START_TEST(one_char_from_string) {
  char* c = "string";
  char* format1 = "%c";
  char* format2 = "s%c";
  char myChar;
  char origChar;
  s21_sscanf(c, format1, &myChar);
  sscanf(c, format1, &origChar);
  ck_assert_int_eq(myChar, origChar);
  s21_sscanf(c, format2, &myChar);
  sscanf(c, format2, &origChar);
  ck_assert_int_eq(myChar, origChar);
}
END_TEST

START_TEST(some_char_from_string) {
  char* str = "string";
  char* format1 = "s%c%c";
  char* format2 = "s%cr%c";
  char myChar1;
  char origChar1;
  char myChar2;
  char origChar2;
  s21_sscanf(str, format1, &myChar1, &myChar2);
  sscanf(str, format1, &origChar1, &origChar2);
  ck_assert_int_eq(myChar1, origChar1);
  s21_sscanf(str, format2, &myChar1, &myChar2);
  sscanf(str, format2, &origChar1, &origChar2);
  ck_assert_int_eq(myChar2, origChar2);
}
END_TEST

Suite* check_sscanf_c(void) {
  Suite* s;
  TCase *tc_mntRec, *tc_oneChar, *tc_woutWrite, *tc_fromStr, *tc_someChar;
  s = suite_create("sscanf_c");
  tc_mntRec = tcase_create("mntWrite");
  tcase_add_test(tc_mntRec, mnt_record);
  suite_add_tcase(s, tc_mntRec);
  tc_oneChar = tcase_create("oneChar");
  tcase_add_test(tc_oneChar, one_char);
  suite_add_tcase(s, tc_oneChar);
  tc_woutWrite = tcase_create("woutWrite");
  tcase_add_test(tc_woutWrite, one_char_without_write);
  suite_add_tcase(s, tc_woutWrite);
  tc_fromStr = tcase_create("fromStr");
  tcase_add_test(tc_fromStr, one_char_from_string);
  suite_add_tcase(s, tc_fromStr);
  tc_someChar = tcase_create("someChar");
  tcase_add_test(tc_someChar, some_char_from_string);
  suite_add_tcase(s, tc_someChar);
  return s;
}