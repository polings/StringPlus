#include "s21_string_tests.h"

START_TEST(test_s21_sprintf_len) {
  char origin[256];
  char create[256];
  char testString[100] = "123safa8 fadfa fa4 af%%";

  const char* format_1 = "value %s";
  ck_assert_int_eq(s21_sprintf(create, format_1, testString),
                   sprintf(origin, format_1, testString));
}
END_TEST
START_TEST(test_s21_sprintf_ls_8) {
  char origin[256], create[256];
  wchar_t testString[100] = L"123";
  const char* format = "123 % *.2ls";
  s21_sprintf(create, format, 2, testString);
  sprintf(origin, format, 2, testString);
  ck_assert_str_eq(create, origin);
}
END_TEST
START_TEST(test_s21_sprintf_ls_7) {
  char origin[256], create[256];
  wchar_t testString[100] = L"123";
  const char* format = "123 %-*.2ls";
  s21_sprintf(create, format, 10, testString);
  sprintf(origin, format, 10, testString);
  ck_assert_str_eq(create, origin);
}
END_TEST
START_TEST(test_s21_sprintf_ls_6) {
  char origin[256], create[256];
  wchar_t testString[100] = L"123";
  const char* format = "123 %*.2ls";
  s21_sprintf(create, format, 10, testString);
  sprintf(origin, format, 10, testString);
  ck_assert_str_eq(create, origin);
}
END_TEST
START_TEST(test_s21_sprintf_ls_5) {
  char origin[256], create[256];
  wchar_t testString[100] = L"123";
  const char* format = "123 %10.*ls";
  s21_sprintf(create, format, 2, testString);
  sprintf(origin, format, 2, testString);
  ck_assert_str_eq(create, origin);
}
END_TEST
START_TEST(test_s21_sprintf_ls_4) {
  char origin[256], create[256];
  wchar_t testString[100] = L"123";
  const char* format = "123 %.10ls";
  s21_sprintf(create, format, testString);
  sprintf(origin, format, testString);
  ck_assert_str_eq(create, origin);
}
END_TEST
START_TEST(test_s21_sprintf_ls_3) {
  char origin[256], create[256];
  wchar_t testString[100] = L"123";
  const char* format = "123 %5ls";
  s21_sprintf(create, format, testString);
  sprintf(origin, format, testString);
  ck_assert_str_eq(create, origin);
}
END_TEST
START_TEST(test_s21_sprintf_ls_2) {
  char origin[256], create[256];
  wchar_t testString[100] = L"123";
  const char* format = "123 %ls";
  s21_sprintf(create, format, testString);
  sprintf(origin, format, testString);
  ck_assert_str_eq(create, origin);
}
END_TEST

START_TEST(test_s21_sprintf_s_8) {
  char origin[256], create[256];
  char testString[100] = "123";
  const char* format = "123 % *.2s";
  s21_sprintf(create, format, 2, testString);
  sprintf(origin, format, 2, testString);
  ck_assert_str_eq(create, origin);
}
END_TEST
START_TEST(test_s21_sprintf_s_7) {
  char origin[256], create[256];
  char testString[100] = "123";
  const char* format = "123 %-*.2s";
  s21_sprintf(create, format, 10, testString);
  sprintf(origin, format, 10, testString);
  ck_assert_str_eq(create, origin);
}
END_TEST
START_TEST(test_s21_sprintf_s_6) {
  char origin[256], create[256];
  char testString[100] = "123";
  const char* format = "123 %*.2s";
  s21_sprintf(create, format, 10, testString);
  sprintf(origin, format, 10, testString);
  ck_assert_str_eq(create, origin);
}
END_TEST
START_TEST(test_s21_sprintf_s_5) {
  char origin[256], create[256];
  char testString[100] = "123";
  const char* format = "123 %10.*s";
  s21_sprintf(create, format, 2, testString);
  sprintf(origin, format, 2, testString);
  ck_assert_str_eq(create, origin);
}
END_TEST
START_TEST(test_s21_sprintf_s_4) {
  char origin[256], create[256];
  char testString[100] = "123";
  const char* format = "123 %.10s";
  s21_sprintf(create, format, testString);
  sprintf(origin, format, testString);
  ck_assert_str_eq(create, origin);
}
END_TEST
START_TEST(test_s21_sprintf_s_3) {
  char origin[256], create[256];
  char testString[100] = "123";
  const char* format = "123 %5s";
  s21_sprintf(create, format, testString);
  sprintf(origin, format, testString);
  ck_assert_str_eq(create, origin);
}
END_TEST
START_TEST(test_s21_sprintf_s_2) {
  char origin[256], create[256];
  char testString[100] = "123";
  const char* format = "123 %s";
  s21_sprintf(create, format, testString);
  sprintf(origin, format, testString);
  ck_assert_str_eq(create, origin);
}
END_TEST
START_TEST(test_s21_sprintf_s_1) {
  char origin[256], create[256];
  const char* format = "123 %%";
  s21_sprintf(create, format, 1);
  sprintf(origin, format, 1);
  ck_assert_str_eq(create, origin);
}
END_TEST

Suite* check_spritnf_s(void) {
  Suite* s;
  TCase *tc_l, *tc_s_1, *tc_s_2, *tc_s_3, *tc_s_4, *tc_s_5, *tc_s_6, *tc_s_7,
      *tc_s_8, *tc_ls_2, *tc_ls_3, *tc_ls_4, *tc_ls_5, *tc_ls_6, *tc_ls_7,
      *tc_ls_8;
  s = suite_create("sprintf_s");

  tc_l = tcase_create("flag_s_len");
  tcase_add_test(tc_l, test_s21_sprintf_len);
  suite_add_tcase(s, tc_l);

  tc_s_1 = tcase_create("flag_s_1");
  tcase_add_test(tc_s_1, test_s21_sprintf_s_1);
  suite_add_tcase(s, tc_s_1);
  tc_s_2 = tcase_create("flag_s_2");
  tcase_add_test(tc_s_2, test_s21_sprintf_s_2);
  suite_add_tcase(s, tc_s_2);
  tc_s_3 = tcase_create("flag_s_3");
  tcase_add_test(tc_s_3, test_s21_sprintf_s_3);
  suite_add_tcase(s, tc_s_3);
  tc_s_4 = tcase_create("flag_s_4");
  tcase_add_test(tc_s_4, test_s21_sprintf_s_4);
  suite_add_tcase(s, tc_s_4);
  tc_s_5 = tcase_create("flag_s_5");
  tcase_add_test(tc_s_5, test_s21_sprintf_s_5);
  suite_add_tcase(s, tc_s_5);
  tc_s_6 = tcase_create("flag_s_6");
  tcase_add_test(tc_s_6, test_s21_sprintf_s_6);
  suite_add_tcase(s, tc_s_6);
  tc_s_7 = tcase_create("flag_s_7");
  tcase_add_test(tc_s_7, test_s21_sprintf_s_7);
  suite_add_tcase(s, tc_s_7);
  tc_s_8 = tcase_create("flag_s_8");
  tcase_add_test(tc_s_8, test_s21_sprintf_s_8);
  suite_add_tcase(s, tc_s_8);

  tc_ls_2 = tcase_create("flag_ls_2");
  tcase_add_test(tc_ls_2, test_s21_sprintf_ls_2);
  suite_add_tcase(s, tc_ls_2);
  tc_ls_3 = tcase_create("flag_ls_3");
  tcase_add_test(tc_ls_3, test_s21_sprintf_ls_3);
  suite_add_tcase(s, tc_ls_3);
  tc_ls_4 = tcase_create("flag_ls_4");
  tcase_add_test(tc_ls_4, test_s21_sprintf_ls_4);
  suite_add_tcase(s, tc_ls_4);
  tc_ls_5 = tcase_create("flag_ls_5");
  tcase_add_test(tc_ls_5, test_s21_sprintf_ls_5);
  suite_add_tcase(s, tc_ls_5);
  tc_ls_6 = tcase_create("flag_ls_6");
  tcase_add_test(tc_ls_6, test_s21_sprintf_ls_6);
  suite_add_tcase(s, tc_ls_6);
  tc_ls_7 = tcase_create("flag_ls_7");
  tcase_add_test(tc_ls_7, test_s21_sprintf_ls_7);
  suite_add_tcase(s, tc_ls_7);
  tc_ls_8 = tcase_create("flag_ls_8");
  tcase_add_test(tc_ls_8, test_s21_sprintf_ls_8);
  suite_add_tcase(s, tc_ls_8);
  return s;
}
