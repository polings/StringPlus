#include "s21_string_tests.h"

START_TEST(sign_int_dec) {
  char format[5][5] = {"%d", "%1i", "%2d", "%3i", "%d"};
  char str[21][21] = {"-21000000", "-1800000", "-160000", "-14000", "-1200",
                      "-100",      "-8",       "-6",      "-4",     "-2",
                      "0",         "2",        "4",       "6",      "8",
                      "100",       "1200",     "14000",   "160000", "1800000",
                      "21000000"};
  int myInt = 0, origInt = 0;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 21; j++) {
      myInt = 0;
      origInt = 0;
      s21_sscanf(str[j], format[i], &myInt);
      sscanf(str[j], format[i], &origInt);
      ck_assert_int_eq(myInt, origInt);
    }
  }
}
END_TEST

START_TEST(sign_int_octal) {
  char format[5][5] = {"%i", "%1i", "%2i", "%3i", "%4i"};
  char str[15][21] = {"-01234567", "-0123456", "-012345", "-01234",
                      "-0123",     "-012",     "-01",     "0",
                      "01",        "012",      "0123",    "01234",
                      "012345",    "0123456",  "01234567"};
  int myInt = 0, origInt = 0;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 15; j++) {
      myInt = 0;
      origInt = 0;
      s21_sscanf(str[j], format[i], &myInt);
      sscanf(str[j], format[i], &origInt);
      ck_assert_int_eq(myInt, origInt);
    }
  }
}
END_TEST

START_TEST(sign_int_hexadec) {
  char format[5][5] = {"%i", "%1i", "%2i", "%3i", "%4i"};
  char str[33][21] = {
      "-0xfF",      "-0xeE",        "-0xdD",       "-0xcC",      "-0xbB",
      "-0xaA",      "-0x123456789", "-0x12345678", "-0x1234567", "-0x123456",
      "-0x12345",   "-0x1234",      "-0x123",      "-0x12",      "-0x10",
      "-0x1",       "0x0",          "0x1",         "0x10",       "0x12",
      "0x123",      "0x1234",       "0x12345",     "0x123456",   "0x1234567",
      "0x12345678", "0x123456789",  "0xaA",        "0xbB",       "0xcC",
      "0xdD",       "0xeE",         "0xfF"};
  int myInt = 0, origInt = 0;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 33; j++) {
      myInt = 0;
      origInt = 0;
      s21_sscanf(str[j], format[i], &myInt);
      sscanf(str[j], format[i], &origInt);
      ck_assert_int_eq(myInt, origInt);
    }
  }
}
END_TEST

START_TEST(unsign_int_octal) {
  char format[5][5] = {"%o", "%1o", "%2o", "%3o", "%4o"};
  char str[8][21] = {"0",     "01",     "012",     "0123",
                     "01234", "012345", "0123456", "01234567"};
  unsigned int myInt = 0, origInt = 0;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 8; j++) {
      myInt = 0;
      origInt = 0;
      s21_sscanf(str[j], format[i], &myInt);
      sscanf(str[j], format[i], &origInt);
      ck_assert_uint_eq(myInt, origInt);
    }
  }
}
END_TEST

START_TEST(unsign_int_dec) {
  char format[5][5] = {"%u", "%1u", "%2u", "%3u", "%4u"};
  char str[11][21] = {"0",    "2",     "4",      "6",       "8",       "100",
                      "1200", "14000", "160000", "1800000", "21000000"};
  unsigned int myInt = 0, origInt = 0;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 11; j++) {
      myInt = 0;
      origInt = 0;
      s21_sscanf(str[j], format[i], &myInt);
      sscanf(str[j], format[i], &origInt);
      ck_assert_uint_eq(myInt, origInt);
    }
  }
}
END_TEST

START_TEST(unsign_int_hexadec) {
  char format[5][5] = {"%x", "%1X", "%2x", "%3X", "%4x"};
  char str[17][21] = {
      "0x0",     "0x1",      "0x10",      "0x12",       "0x123",       "0x1234",
      "0x12345", "0x123456", "0x1234567", "0x12345678", "0x123456789", "0xaA",
      "0xbB",    "0xcC",     "0xdD",      "0xeE",       "0xfF"};
  unsigned int myInt = 0, origInt = 0;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 17; j++) {
      myInt = 0;
      origInt = 0;
      s21_sscanf(str[j], format[i], &myInt);
      sscanf(str[j], format[i], &origInt);
      ck_assert_uint_eq(myInt, origInt);
    }
  }
}
END_TEST

START_TEST(ret_test) {
  char format[5][5] = {"%d", "%1i", "%2d", "%3i", "%4d"};
  char str[21][21] = {"-21000000", "-1800000", "-160000", "-14000", "-1200",
                      "-100",      "-8",       "-6",      "-4",     "-2",
                      "0",         "2",        "4",       "6",      "8",
                      "100",       "1200",     "14000",   "160000", "1800000",
                      "21000000"};
  int myInt = 0, origInt = 0;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 21; j++) {
      ck_assert_int_eq(s21_sscanf(str[j], format[i], &myInt),
                       sscanf(str[j], format[i], &origInt));
    }
  }
}
END_TEST

START_TEST(test_with_another_spec) {
  int myInt = 0, origInt = 0;
  char myChar = 0, origChar = 0;
  char myStr[100] = {"\0"}, origStr[100] = {"\0"};
  float myFloat = 0.0, origFloat = 0.0;

  s21_sscanf("Y21", "%c%d", &myChar, &myInt);
  sscanf("Y21", "%c%d", &origChar, &origInt);
  ck_assert_int_eq(myInt, origInt);

  s21_sscanf("SCHOOL 021", "%s%i", myStr, &myInt);
  sscanf("SCHOOL 021", "%s%i", origStr, &origInt);
  ck_assert_int_eq(myInt, origInt);

  s21_sscanf("21.21 0x8A", "%f%x", &myFloat, &myInt);
  sscanf("21.21 0x8A", "%f%x", &origFloat, &origInt);
  ck_assert_int_eq(myInt, origInt);
}
END_TEST

START_TEST(short_int_dec) {
  char format[5][5] = {"%hd", "%hi"};
  char str[21][21] = {"-21000000", "-1800000", "-160000", "-14000", "-1200",
                      "-100",      "-8",       "-6",      "-4",     "-2",
                      "0",         "2",        "4",       "6",      "8",
                      "100",       "1200",     "14000",   "160000", "1800000",
                      "21000000"};
  short int myShortInt = 0, origShortInt = 0;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 21; j++) {
      myShortInt = 0;
      origShortInt = 0;
      s21_sscanf(str[j], format[i], &myShortInt);
      sscanf(str[j], format[i], &origShortInt);
      ck_assert_int_eq(myShortInt, origShortInt);
    }
  }
}
END_TEST

START_TEST(long_int_dec) {
  char format[5][5] = {"%hd", "%hi"};
  char str[21][21] = {"-21000000", "-1800000", "-160000", "-14000", "-1200",
                      "-100",      "-8",       "-6",      "-4",     "-2",
                      "0",         "2",        "4",       "6",      "8",
                      "100",       "1200",     "14000",   "160000", "1800000",
                      "21000000"};
  long int myLongInt = 0, origLongInt = 0;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 21; j++) {
      myLongInt = 0;
      origLongInt = 0;
      s21_sscanf(str[j], format[i], &myLongInt);
      sscanf(str[j], format[i], &origLongInt);
      ck_assert_int_eq(myLongInt, origLongInt);
    }
  }
}
END_TEST

Suite *check_sscanf_diouxX(void) {
  Suite *s;
  TCase *tc_sign_int_dec, *tc_sign_int_octal, *tc_sign_int_hexadec,
      *tc_unsign_int_octal, *tc_unsign_int_dec, *tc_unsign_int_hexadec,
      *tc_ret_test, *tc_test_with_another_spec, *tc_short_int_dec,
      *tc_long_int_dec;

  s = suite_create("sscnaf_diouxX");

  tc_sign_int_dec = tcase_create("sign_int_dec");
  tcase_add_test(tc_sign_int_dec, sign_int_dec);
  suite_add_tcase(s, tc_sign_int_dec);

  tc_sign_int_octal = tcase_create("sign_int_octal");
  tcase_add_test(tc_sign_int_octal, sign_int_octal);
  suite_add_tcase(s, tc_sign_int_octal);

  tc_sign_int_hexadec = tcase_create("sign_int_hexadec");
  tcase_add_test(tc_sign_int_hexadec, sign_int_hexadec);
  suite_add_tcase(s, tc_sign_int_hexadec);

  tc_unsign_int_octal = tcase_create("unsign_int_octal");
  tcase_add_test(tc_unsign_int_octal, unsign_int_octal);
  suite_add_tcase(s, tc_unsign_int_octal);

  tc_unsign_int_dec = tcase_create("unsign_int_dec");
  tcase_add_test(tc_unsign_int_dec, unsign_int_dec);
  suite_add_tcase(s, tc_unsign_int_dec);

  tc_unsign_int_hexadec = tcase_create("unsign_int_hexadec");
  tcase_add_test(tc_unsign_int_hexadec, unsign_int_hexadec);
  suite_add_tcase(s, tc_unsign_int_hexadec);

  tc_ret_test = tcase_create("ret_test");
  tcase_add_test(tc_ret_test, ret_test);
  suite_add_tcase(s, tc_ret_test);

  tc_test_with_another_spec = tcase_create("test_with_another_spec");
  tcase_add_test(tc_test_with_another_spec, test_with_another_spec);
  suite_add_tcase(s, tc_test_with_another_spec);

  tc_short_int_dec = tcase_create("short_int_dec");
  tcase_add_test(tc_short_int_dec, short_int_dec);
  suite_add_tcase(s, tc_short_int_dec);

  tc_long_int_dec = tcase_create("long_int_dec");
  tcase_add_test(tc_long_int_dec, long_int_dec);
  suite_add_tcase(s, tc_long_int_dec);

  return s;
}