#include "s21_string_tests.h"

START_TEST(test_s21_sprintf_len) {
  char origin[90];
  char create[90];
  const char* format_1 = "value %d";
  const char* format_2 = "value%05d";
  const char* format_3 = "value %*d xx %d";
  const char* format_4 = "value %-*d xx %d";
  const char* format_5 = "value %-0*d xx %d";
  const char* format_6 = "value% 10.6u";
  const char* format_7 = "value% 5ld";

  for (int d = -100; d < 100; d++) {
    ck_assert_int_eq(s21_sprintf(create, format_1, d),
                     sprintf(origin, format_1, d));
  }

  for (int d = -100; d < 100; d++) {
    ck_assert_int_eq(s21_sprintf(create, format_2, d),
                     sprintf(origin, format_2, d));
  }

  for (int d = -100; d < 100; d++) {
    ck_assert_int_eq(s21_sprintf(create, format_3, 5, d, d),
                     sprintf(origin, format_3, 5, d, d));
  }
  for (int d = -100; d < 100; d++) {
    ck_assert_int_eq(s21_sprintf(create, format_4, 5, d, d),
                     sprintf(origin, format_4, 5, d, d));
  }
  for (int d = -100; d < 100; d++) {
    ck_assert_int_eq(s21_sprintf(create, format_5, 5, d, d),
                     sprintf(origin, format_5, 5, d, d));
  }
  for (int d = -100; d < 100; d++) {
    ck_assert_int_eq(s21_sprintf(create, format_6, d),
                     sprintf(origin, format_6, d));
  }
  for (long int d = -10000000; d < 10000000; d += 15687) {
    ck_assert_int_eq(s21_sprintf(create, format_7, d),
                     sprintf(origin, format_7, d));
  }
}
END_TEST
START_TEST(test_s21_sprintf_str) {
  char origin[90];
  char create[90];
  const char* format_1 = "value %d";
  const char* format_2 = "value%05d";
  const char* format_3 = "value %*.4d xx %d";
  const char* format_4 = "value %-*d xx %d";
  const char* format_5 = "value %-0*d xx %d";
  const char* format_6 = "value% 5d";
  const char* format_7 = "value% +5ld";
  const char* format_8 = "value% +5ld";
  const char* format_9 = "value% 5d";
  const char* format_10 = "value% -+5d";
  for (int d = -100; d < 100; d++) {
    s21_sprintf(create, format_1, d);
    sprintf(origin, format_1, d);
    ck_assert_str_eq(create, origin);
  }

  for (int d = -100; d < 100; d++) {
    s21_sprintf(create, format_2, d);
    sprintf(origin, format_2, d);
    ck_assert_str_eq(create, origin);
  }

  for (int d = -100; d < 100; d++) {
    s21_sprintf(create, format_3, 5, d, d);
    sprintf(origin, format_3, 5, d, d);
    ck_assert_str_eq(create, origin);
  }
  for (int d = -100; d < 100; d++) {
    s21_sprintf(create, format_4, 5, d, d);
    sprintf(origin, format_4, 5, d, d);
    ck_assert_str_eq(create, origin);
  }
  for (int d = -100; d < 100; d++) {
    s21_sprintf(create, format_5, 5, d, d);
    sprintf(origin, format_5, 5, d, d);
    ck_assert_str_eq(create, origin);
  }
  for (int d = -100; d < 100; d++) {
    s21_sprintf(create, format_6, d);
    sprintf(origin, format_6, d);
    ck_assert_str_eq(create, origin);
  }
  for (long int d = -10000000; d < 10000000; d += 15687) {
    s21_sprintf(create, format_7, d);
    sprintf(origin, format_7, d);
    ck_assert_str_eq(create, origin);
  }
  for (long int d = -10000000; d < 10000000; d += 15687) {
    s21_sprintf(create, format_8, d);
    sprintf(origin, format_8, d);
    ck_assert_str_eq(create, origin);
  }
  for (long int d = -10000000; d < 10000000; d += 15687) {
    s21_sprintf(create, format_9, d);
    sprintf(origin, format_9, d);
    ck_assert_str_eq(create, origin);
  }
  for (long int d = -10000000; d < 10000000; d += 15687) {
    s21_sprintf(create, format_10, d);
    sprintf(origin, format_10, d);
    ck_assert_str_eq(create, origin);
  }
}
END_TEST

Suite* check_spritnf_d(void) {
  Suite* s;
  TCase *tc_l, *tc_s;
  s = suite_create("sprintf_d");

  tc_l = tcase_create("flag_len");
  tcase_add_test(tc_l, test_s21_sprintf_len);
  suite_add_tcase(s, tc_l);

  tc_s = tcase_create("flag_str");
  tcase_add_test(tc_s, test_s21_sprintf_str);
  suite_add_tcase(s, tc_s);

  return s;
}
