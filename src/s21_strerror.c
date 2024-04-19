#include "s21_errormsg_list.h"
#include "s21_string.h"

char *s21_strerror(int errnum) {
  static char ret_error[100] = {'\0'};
  static const int num_errors =
      sizeof(s21_sys_errorlist) / sizeof(*s21_sys_errorlist);
  if (errnum < 0 || errnum >= num_errors) {
#ifdef __APPLE__
    s21_sprintf(ret_error, "Unknown error: %d", errnum);
#elif __linux__
    s21_sprintf(ret_error, "Unknown error %d", errnum);
#endif
  } else {
    s21_sprintf(ret_error, "%s", s21_sys_errorlist[errnum]);
  }
  return ret_error;
}