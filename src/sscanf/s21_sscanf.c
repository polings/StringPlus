#include "s21_string.h"

int checkFormBefPerc(char *str, const char *form, int *iterStr, int *flLoop) {
  // variables
  int sum = 0, count = 0, flag = 1;
  char strBefPerc[100] = {"\0"};

  // write string before percent in array
  for (int i = 0; i < (int)s21_strlen(form) && flag; i++) {
    if (form[i] == '%' && form[i + 1] != '%')
      flag = 0;
    else if (form[i] == '%' && form[i + 1] == '%') {
      strBefPerc[count++] = '%';
      i += 1;
      sum += 1;
    } else if (form[i] != '%')
      strBefPerc[count++] = form[i];
  }

  // compare str and strBefPerc
  if (strBefPerc[0] != '\0' && s21_strstr(str, strBefPerc) == str) {
    *iterStr += (int)s21_strlen(strBefPerc);
  } else if (strBefPerc[0] != '\0' && s21_strstr(str, strBefPerc) != str) {
    *flLoop = 0;
  }

  return count + sum;
}

int checkSpec(int i, const char *format) {
  int ret = 0;
  // skip identical symbol
  while (format[i + 1] == format[i]) {
    i += 1;
  }
  // check the correctness of h-lenght specifier
  if (format[i] == 'h' &&
      (format[i + 1] == 'i' || format[i + 1] == 'd' || format[i + 1] == 'o' ||
       format[i + 1] == 'u' || format[i + 1] == 'x' || format[i + 1] == 'X')) {
    ret = 1;
  }
  // check the correctness of l-lenght specifier
  if (format[i] == 'l' &&
      (format[i + 1] == 'i' || format[i + 1] == 'd' || format[i + 1] == 'o' ||
       format[i + 1] == 'u' || format[i + 1] == 'x' || format[i + 1] == 'X' ||
       format[i + 1] == 'c' || format[i + 1] == 's')) {
    ret = 1;
  }
  // check the correctness of L-lenght specifier
  if (format[i] == 'L' &&
      (format[i + 1] == 'e' || format[i + 1] == 'E' || format[i + 1] == 'f' ||
       format[i + 1] == 'g' || format[i + 1] == 'G')) {
    ret = 1;
  }
  return ret;
}

int parseFormatAndExecFunc(char *str, const char *format, va_list args,
                           specifiers *mySpec) {
  // variables
  long int numWight = 0;
  int flLoop = 1, mnt_n = 0, mntRec = 0, iterStr = 0, flWork = 1, flPerc = 0;

  // check format before percent and skip found string or block func
  int startParseForm = checkFormBefPerc(str, format, &iterStr, &flLoop);
  mnt_n += startParseForm;

  // parse format
  for (int i = startParseForm; i < (int)s21_strlen(format) && flLoop; i++) {
    // check percent
    if (format[i] == '%' && format[i + 1] != '%') {
      flPerc = 1;
      continue;
    }
    if (format[i] == '%' && format[i + 1] != '%' && flPerc == 1) {
      flWork = 0;
      printf("--- checkPerc: invalid format ---\n");
      continue;
    }

    // end parsing format if string end
    if ((iterStr > (int)s21_strlen(str) - 1) && format[i + 1] != 'n' &&
        format[i] != 'n') {
      flWork = 0;
      continue;
    }

    // skip space if format and str contain space
    if (format[i] == ' ' && str[iterStr] == ' ' && flWork && !flPerc) {
      iterStr += 1;
      mnt_n += 1;
    }

    else if (format[i] == '*' && format[i - 1] == '%' && flWork && flPerc) {
      mySpec->star = 1;
    }

    // check case %%
    else if (format[i] == '%' && format[i + 1] == '%' && str[iterStr] == '%') {
      iterStr += 1;
      mnt_n += 1;
      i += 1;
    }

    // check wight
    else if (format[i] >= '0' && format[i] <= '9' && flWork && flPerc &&
             (format[i - 1] == '%' || format[i - 1] == '*')) {
      numWight = 0;
      charToInt(format, mySpec, &i, &numWight, 0, NULL);
      if (numWight == 0) {
        flWork = 0;
        printf("--- checkWight : invalid format ---\n");
      }
      i -= 1;
    }

    else if (format[i] == 'h' && flWork && flPerc) {
      if (checkSpec(i, format)) mySpec->h = 1;
    }

    else if (format[i] == 'l' && flWork && flPerc) {
      if (checkSpec(i, format)) mySpec->l = 1;
    }

    else if (format[i] == 'L' && flWork && flPerc) {
      if (checkSpec(i, format)) mySpec->L = 1;
    }

    else if (format[i] == 'c' && flWork && flPerc) {
      mntRec += write_c(str, &iterStr, &mnt_n, mySpec, args);
      flPerc = 0;
    }

    else if ((format[i] == 'd' || format[i] == 'i' || format[i] == 'o' ||
              format[i] == 'u' || format[i] == 'x' || format[i] == 'X' ||
              format[i] == 'p') &&
             flWork && flPerc) {
      // activate some specifiers
      if (format[i] == 'd') {
        mySpec->d = 1;
      } else if (format[i] == 'i') {
        mySpec->i = 1;
      } else if (format[i] == 'p') {
        mySpec->p = 1;
        mySpec->unsig = 1;
      } else if (format[i] == 'o') {
        mySpec->o = 1;
        mySpec->unsig = 1;
      } else if (format[i] == 'u') {
        mySpec->d = 1;
        mySpec->unsig = 1;
      } else if (format[i] == 'x' || format[i] == 'X') {
        mySpec->xX = 1;
        mySpec->unsig = 1;
      }

      // call execute function
      mntRec +=
          write_diouxX(str, mySpec, &iterStr, &mnt_n, numWight, &flWork, args);
      flPerc = 0;
    }

    else if ((format[i] == 'e' || format[i] == 'E' || format[i] == 'f' ||
              format[i] == 'g' || format[i] == 'G') &&
             flWork && flPerc) {
      mntRec +=
          write_eEfgG(str, mySpec, &iterStr, &mnt_n, numWight, &flWork, args);
      flPerc = 0;
    }

    else if (format[i] == 's' && flWork && flPerc) {
      mntRec += write_s(str, &iterStr, numWight, &mnt_n, mySpec, args);
      flPerc = 0;
    }

    else if (format[i] == 'n' && flPerc) {
      write_n(mnt_n, mySpec, args);
      flPerc = 0;
    }

    else if (format[i] == str[iterStr]) {
      iterStr += 1;
      mnt_n += 1;
    }
  }
  return mntRec;
}

int s21_sscanf(char *str, const char *format, ...) {
  va_list args;
  va_start(args, format);

  specifiers mySpec = {0};
  int mntRecord = parseFormatAndExecFunc(str, format, args, &mySpec);

  va_end(args);

  if (mntRecord == 0 && mySpec.startRead == 0) mntRecord = -1;
  return mntRecord;
}