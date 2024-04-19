#include "s21_string_tests.h"

START_TEST(test_s21_sprintf_len) {
  char origin[90];
  char create[90];
  const char* format_1 = "value %f";
  for (float d = -20; d < 20; d += 0.523456789) {
    ck_assert_int_eq(s21_sprintf(create, format_1, d),
                     sprintf(origin, format_1, d));
  }

  const char* format_2 = "value %f xx %f";
  for (float d = -20; d < 20; d += 0.523456789) {
    ck_assert_int_eq(s21_sprintf(create, format_2, d, d),
                     sprintf(origin, format_2, d, d));
  }

  const char* format_3 = "value % f%-10f%+fxxx";
  for (float d = -20; d < 20; d += 0.523) {
    ck_assert_int_eq(s21_sprintf(create, format_3, d, d, d),
                     sprintf(origin, format_3, d, d, d));
  }
}
START_TEST(test_s21_sprintf_str) {
  char origin[90];
  char create[90];

  const char* format_1 = "value %d";

  for (int d = -20; d < 20; d += 1) {
    s21_sprintf(create, format_1, d);
    sprintf(origin, format_1, d);
    ck_assert_str_eq(create, origin);
  }

  const char* format_2 = "value %f xx %f";
  for (float d = -20; d < 20; d += 0.523456789) {
    s21_sprintf(create, format_2, d, d);
    sprintf(origin, format_2, d, d);
    ck_assert_str_eq(create, origin);
  }

  const char* format_3 = "value % f%-10f%+fxxx";
  for (float d = -20; d < 20; d += 0.523456789) {
    s21_sprintf(create, format_3, d, d, d);
    sprintf(origin, format_3, d, d, d);
    ck_assert_str_eq(create, origin);
  }
}
END_TEST

Suite* check_spritnf_f(void) {
  Suite* s;
  TCase *tc_l, *tc_s;
  s = suite_create("sprintf_f");

  tc_l = tcase_create("flag_len");
  tcase_add_test(tc_l, test_s21_sprintf_len);
  suite_add_tcase(s, tc_l);

  tc_s = tcase_create("flag_str");
  tcase_add_test(tc_s, test_s21_sprintf_str);
  suite_add_tcase(s, tc_s);

  return s;
}
