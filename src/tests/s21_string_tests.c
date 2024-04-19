#include "s21_string_tests.h"

void run_test(Suite *s, int *fail) {
  SRunner *runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  *fail = srunner_ntests_failed(runner);
  srunner_free(runner);
}

int main(void) {
  int fail = 0;

  run_test(check_MEMCHR(), &fail);
  run_test(check_MEMCMP(), &fail);
  run_test(check_MEMCPY(), &fail);
  run_test(check_MEMSET(), &fail);
  run_test(check_STRNCAT(), &fail);
  run_test(check_STRCHR(), &fail);
  run_test(check_STRNCMP(), &fail);
  run_test(check_STRNCPY(), &fail);
  run_test(check_STRCSPN(), &fail);
  run_test(check_STRERROR(), &fail);
  run_test(check_STRLEN(), &fail);
  run_test(check_STRPBRK(), &fail);
  run_test(check_STRRCHR(), &fail);
  run_test(check_STRSTR(), &fail);
  run_test(check_STRTOK(), &fail);

  run_test(check_spritnf_c(), &fail);
  run_test(check_spritnf_d(), &fail);
  run_test(check_spritnf_u(), &fail);
  run_test(check_spritnf_f(), &fail);
  run_test(check_spritnf_s(), &fail);

  run_test(check_sscanf_c(), &fail);
  run_test(check_sscanf_n(), &fail);
  run_test(check_sscanf_s(), &fail);
  run_test(check_sscanf_eEfgG(), &fail);
  run_test(check_sscanf_diouxX(), &fail);

  run_test(check_TO_UPPER(), &fail);
  run_test(check_TO_LOWER(), &fail);
  run_test(check_INSERT(), &fail);
  run_test(check_TRIM(), &fail);

  return (fail == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}