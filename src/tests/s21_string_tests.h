#ifndef S21_STRING_TESTS_H
#define S21_STRING_TESTS_H

#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_string.h"

Suite *check_MEMCHR(void);
Suite *check_MEMCMP(void);
Suite *check_MEMCPY(void);
Suite *check_MEMSET(void);
Suite *check_STRNCAT(void);
Suite *check_STRCHR(void);
Suite *check_STRNCMP(void);
Suite *check_STRNCPY(void);
Suite *check_STRCSPN(void);
Suite *check_STRERROR(void);
Suite *check_STRLEN(void);
Suite *check_STRPBRK(void);
Suite *check_STRRCHR(void);
Suite *check_STRSTR(void);
Suite *check_STRTOK(void);

Suite *check_spritnf_d(void);
Suite *check_spritnf_c(void);
Suite *check_spritnf_f(void);
Suite *check_spritnf_s(void);
Suite *check_spritnf_u(void);

Suite *check_sscanf_c(void);
Suite *check_sscanf_n(void);
Suite *check_sscanf_s(void);
Suite *check_sscanf_eEfgG(void);
Suite *check_sscanf_diouxX(void);

Suite *check_TO_UPPER(void);
Suite *check_TO_LOWER(void);
Suite *check_INSERT(void);
Suite *check_TRIM(void);

#endif