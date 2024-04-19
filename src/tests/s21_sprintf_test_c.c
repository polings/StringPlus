#include "s21_string_tests.h"

START_TEST(test_s21_sprintf_len) {
  char origin[256];
  char create[256];
  const char* format_1 = "value %c";
  const char* format_2 = "value %5c";
  const char* format_3 = "value %*c xx %c";
  const char* format_4 = "value %lc";

  for (int d = 0; d < 128; d++)
    ck_assert_int_eq(s21_sprintf(create, format_1, d),
                     sprintf(origin, format_1, d));
  for (int d = 0; d < 128; d++)
    ck_assert_int_eq(s21_sprintf(create, format_2, d),
                     sprintf(origin, format_2, d));
  for (int d = 0; d < 128; d++)
    ck_assert_int_eq(s21_sprintf(create, format_3, 4, d, d),
                     sprintf(origin, format_3, 4, d, d));

  ck_assert_int_eq(s21_sprintf(create, format_4, L'c'),
                   sprintf(origin, format_4, L'c'));
}
END_TEST
START_TEST(test_s21_sprintf_str) {
  char origin[256];
  char create[256];

  const char* format_1 = "value %c";
  const char* format_2 = "value %5c";
  const char* format_3 = "value %*c xx %c";
  const char* format_4 = "value %lc";

  for (int d = 0; d < 128; d++) {
    s21_sprintf(create, format_1, d, d, d);
    sprintf(origin, format_1, d, d, d);
    ck_assert_str_eq(create, origin);
  }
  for (int d = 0; d < 128; d++) {
    s21_sprintf(create, format_2, d);
    sprintf(origin, format_2, d);
    ck_assert_str_eq(create, origin);
  }
  for (int d = 0; d < 128; d++) {
    s21_sprintf(create, format_3, d, d, d);
    sprintf(origin, format_3, d, d, d);
    ck_assert_str_eq(create, origin);
  }

  s21_sprintf(create, format_4, L'd', L'c', L'K');
  sprintf(origin, format_4, L'd', L'c', L'K');
  ck_assert_str_eq(create, origin);
}
END_TEST

Suite* check_spritnf_c(void) {
  Suite* s;
  TCase *tc_l, *tc_s;
  s = suite_create("sprintf_c");

  tc_l = tcase_create("flag_len");
  tcase_add_test(tc_l, test_s21_sprintf_len);
  suite_add_tcase(s, tc_l);

  tc_s = tcase_create("flag_c");
  tcase_add_test(tc_s, test_s21_sprintf_str);
  suite_add_tcase(s, tc_s);

  return s;
}
