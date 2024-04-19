#include "s21_string.h"

void converter8to10(const char *str, specifiers *mySpec, int *i,
                    long int *value, int lim, int *countSymbols) {
  int count = 0;  // count shows amount of written 8-e digits
  int intArr[100] = {0};

  // write 8-e digits to array
  while (str[*i] >= '0' && str[*i] <= '7' &&
         (lim == 0 || (*countSymbols < lim))) {
    intArr[count++] = (int)str[*i] - 48;
    *countSymbols += 1;
    *i += 1;
  }

  // change 8-e num to 10-e num
  for (int j = 0; j < count; j++) {
    *value += intArr[j] * (int)pow(8, count - 1 - j);
    if (j == 0) mySpec->flagSuccessWrite = 1;
  }
}

void converter16to10(const char *str, specifiers *mySpec, int *i,
                     long int *value, int lim, int *countSymbols) {
  int count = 0;
  long int intArr[100] = {0};

  // write 16-e digits to array
  while (((str[*i] >= '0' && str[*i] <= '9') ||
          (str[*i] >= 'a' && str[*i] <= 'f') ||
          (str[*i] >= 'A' && str[*i] <= 'F') ||
          (str[*i] == 'x' && str[*i - 1] == '0')) &&
         (lim == 0 || (*countSymbols < lim))) {
    // if digit
    if (str[*i] >= '0' && str[*i] <= '9') {
      intArr[count++] = (int)str[*i] - 48;
      *countSymbols += 1;
    }

    // if letter
    else if (str[*i] >= 'A' && str[*i] <= 'F') {
      intArr[count++] = (int)str[*i] - 55;
      *countSymbols += 1;
    } else if (str[*i] >= 'a' && str[*i] <= 'f') {
      intArr[count++] = (int)str[*i] - 87;
      *countSymbols += 1;
    }

    else {
      count += 1;
      *countSymbols += 1;
      ;
    }

    *i += 1;
  }
  // change 16-e num to 10-e num
  for (int j = 0; j < count; j++) {
    *value += intArr[j] * (long int)pow(16, count - 1 - j);
    if (j == 0) mySpec->flagSuccessWrite = 1;
  }
}

int write_c(const char *str, int *iterStr, int *mnt_n, specifiers *mySpec,
            va_list args) {
  int mntSuccessRecord = 0;
  if (mySpec->star == 1) {
    *iterStr += 1;
    *mnt_n += 1;
    mySpec->star = 0;
  } else if (mySpec->star == 0) {
    *va_arg(args, char *) = str[*iterStr];
    mntSuccessRecord += 1;
    *mnt_n += 1;
    *iterStr += 1;
  }
  return mntSuccessRecord;
}

int write_s(const char *str, int *iterStr, int lim, int *mnt_n,
            specifiers *mySpec, va_list args) {
  // count of written symbols
  int count = 0, mntSuccessRecord = 0;

  // skip excess spaces before string
  while (str[*iterStr] == ' ') {
    *iterStr += 1;
    *mnt_n += 1;
  }

  // star is on
  if (mySpec->star == 1) {
    while ((str[*iterStr] != ' ' && *iterStr < (int)s21_strlen(str)) &&
           (lim == 0 || (count < lim))) {
      *iterStr += 1;
      count += 1;
    }
  }

  // star is off
  else if (mySpec->star == 0) {
    char *dest = va_arg(args, char *);
    while ((str[*iterStr] != ' ' && *iterStr < (int)s21_strlen(str)) &&
           (lim == 0 || (count < lim))) {
      dest[count++] = str[*iterStr];
      *iterStr += 1;
    }
  }

  if (count > 0) {
    *mnt_n += count;
  }

  if (count > 0 && mySpec->star == 0) {
    mntSuccessRecord += 1;
  }

  mySpec->star = 0;
  return mntSuccessRecord;
}

void write_n(const int mnt_n, specifiers *mySpec, va_list args) {
  if (mySpec->star == 0) {
    if (mnt_n > 0)
      *va_arg(args, int *) = mnt_n;
    else
      *va_arg(args, int *) = -1;
  } else {
    mySpec->star = 0;
  }
}

int charToInt(const char *str, specifiers *mySpec, int *i, long int *num,
              int lim, int *countSymbols) {
  int count = 0;
  long int intArr[100] = {0};

  // write digits in array
  while (str[*i] >= '0' && str[*i] <= '9' &&
         (lim == 0 || (*countSymbols < lim))) {
    intArr[count++] = (int)str[*i] - 48;
    if (countSymbols != NULL) *countSymbols += 1;
    *i += 1;
  }

  // create number from digits-array
  if (count != 0) *num = 0;
  for (int j = 0; j <= count; j++) {
    if (j == 0) mySpec->flagSuccessWrite = 1;
    if (count != j) {
      *num += intArr[j] * (long int)pow(10, count - 1 - j);
    } else {
      *num += intArr[j];
    }
  }

  return count;
}

int write_diouxX(const char *str, specifiers *mySpec, int *iterStr, int *mnt_n,
                 int lim, int *flWork, va_list args) {
  // variables
  long int value = 0;
  int sign = 1, countSymbols = 0, mntSuccessRecord = 0;
  mySpec->flagSuccessWrite = 0;
  // skip excess spaces
  while (str[*iterStr] == ' ') {
    mySpec->startRead = 1;
    *iterStr += 1;
    countSymbols += 1;
  }

  // check sign
  if (str[*iterStr] == '-') {
    mySpec->startRead = 1;
    if (mySpec->unsig == 0) sign = -1;
    *iterStr += 1;
    countSymbols += 1;
  } else if (str[*iterStr] == '+') {
    mySpec->startRead = 1;
    *iterStr += 1;
    countSymbols += 1;
  }

  // choose execut function
  if (lim == 0 || countSymbols < lim) {
    if ((str[*iterStr] >= '1' && str[*iterStr] <= '9' && mySpec->i == 1) ||
        mySpec->d == 1) {
      // 10-noe
      mySpec->startRead = 1;
      charToInt(str, mySpec, iterStr, &value, lim, &countSymbols);
      mySpec->d = 0;
    }

    else if ((str[*iterStr] == '0' && str[*iterStr + 1] != 'x' &&
              mySpec->i == 1) ||
             mySpec->o == 1) {
      // 8-noe
      mySpec->startRead = 1;
      converter8to10(str, mySpec, iterStr, &value, lim, &countSymbols);
      mySpec->o = 0;
    }

    else if ((str[*iterStr] == '0' && str[*iterStr + 1] == 'x' &&
              mySpec->i == 1) ||
             mySpec->xX == 1 || mySpec->p == 1) {
      // 16-noe
      mySpec->startRead = 1;
      if ((lim == 1 || lim == 2) && mySpec->xX == 0) {
        value = 0;
      } else {
        converter16to10(str, mySpec, iterStr, &value, lim, &countSymbols);
      }
      mySpec->xX = 0;
    }
  }

  // check permission write
  if (mySpec->star == 0 && mySpec->flagSuccessWrite == 1) {
    // check unsigned write
    if (mySpec->unsig == 0) {
      value *= sign;
    }
    // check p and lenght specifiers
    if (mySpec->l == 1 || mySpec->p == 1) {
      *va_arg(args, long int *) = value;
    } else if (mySpec->h == 1) {
      *va_arg(args, short int *) = (short int)value;
    } else {
      *va_arg(args, int *) = (int)value;
    }
  } else {
    mySpec->star = 0;
  }
  mySpec->unsig = 0;

  // check correctness exec func
  if (countSymbols == 0) {
    *flWork = 0;
  } else if (mySpec->flagSuccessWrite == 1) {
    *mnt_n += countSymbols;
    mntSuccessRecord += 1;
    mySpec->flagSuccessWrite = 0;
  }

  return mntSuccessRecord;
}

void charToFloat(const char *str, long double *value, specifiers *mySpec,
                 int *iterStr, int lim, int *countSymbols) {
  long int powExp = 1;
  int iterIntArr = 0, iterMantArr = 0, signExp = 0;
  int intPart[100] = {0};
  int mantissa[100] = {0};

  // write integer part of number to intPart-array
  while (str[*iterStr] >= '0' && str[*iterStr] <= '9' &&
         (lim == 0 || (*countSymbols < lim))) {
    intPart[iterIntArr++] = (int)str[*iterStr] - 48;
    *countSymbols += 1;
    *iterStr += 1;
  }

  // write mantissa to mantissa-array
  if (str[*iterStr] == '.' && (lim == 0 || (*countSymbols < lim))) {
    *countSymbols += 1;
    *iterStr += 1;
    while (str[*iterStr] >= '0' && str[*iterStr] <= '9' &&
           (lim == 0 || (*countSymbols < lim))) {
      mantissa[iterMantArr++] = (int)str[*iterStr] - 48;
      *countSymbols += 1;
      *iterStr += 1;
    }
  }

  // find e expression
  if ((str[*iterStr] == 'e' || str[*iterStr] == 'E') &&
      (lim == 0 || (*countSymbols < lim))) {
    int flChToInt = 0;
    *iterStr += 1;
    *countSymbols += 1;
    if (lim == 0 || (*countSymbols < lim)) {
      signExp = 1;
      if (str[*iterStr] == '-') {
        signExp = -1;
        *iterStr += 1;
        *countSymbols += 1;
      } else if (str[*iterStr] == '+') {
        *iterStr += 1;
        *countSymbols += 1;
      }
      if (lim == 0 || (*countSymbols < lim)) {
        charToInt(str, mySpec, iterStr, &powExp, lim, countSymbols);
        flChToInt = 1;
      }
    }
    if (*countSymbols >= lim && lim != 0 && !flChToInt) signExp = 0;
  }

  // change integer part to float
  for (int i = 0; i < iterIntArr; i++) {
    if (i != iterIntArr - 1) {
      *value +=
          (long double)intPart[i] * (long double)pow(10, iterIntArr - 1 - i);
      mySpec->flagSuccessWrite = 1;
    } else {
      *value += (long double)intPart[i];
      mySpec->flagSuccessWrite = 1;
    }
  }

  // change mantissa to float
  for (int i = 0; i < iterMantArr; i++) {
    *value += (long double)mantissa[i] * (long double)pow(0.1, i + 1);
    mySpec->flagSuccessWrite = 1;
  }

  // create final value with sign end exp
  if (signExp == 1) {
    *value = *value * (long double)pow(10, powExp);
    mySpec->flagSuccessWrite = 1;
  } else if (signExp == -1) {
    *value = *value * (long double)pow(0.1, powExp);
    mySpec->flagSuccessWrite = 1;
  }
}

int write_eEfgG(const char *str, specifiers *mySpec, int *iterStr, int *mnt_n,
                int lim, int *flWork, va_list args) {
  // variables
  long double value = 0.0;
  int sign = 1, countSymbols = 0, mntSuccessRecord = 0;

  // skip excess spaces
  while (str[*iterStr] == ' ') {
    *iterStr += 1;
    *mnt_n += 1;
    countSymbols += 1;
  }

  // check sign
  if (str[*iterStr] == '-') {
    *iterStr += 1;
    countSymbols += 1;
    if (lim == 0 || countSymbols < lim) sign = -1;
  } else if (str[*iterStr] == '+') {
    *iterStr += 1;
    countSymbols += 1;
  }

  if (lim == 0 || countSymbols < lim)
    charToFloat(str, &value, mySpec, iterStr, lim, &countSymbols);

  if (sign == -1 && mySpec->flagSuccessWrite == 0) {
    sign = 1;
  }

  // check permission write
  if (mySpec->star == 0) {
    // check lenght specifiers
    if (mySpec->L == 1) {
      *va_arg(args, long double *) = value * (long double)sign;
    } else {
      *va_arg(args, float *) = (float)value * sign;
    }
  } else {
    mySpec->star = 0;
  }

  // check correctness exec func
  if (countSymbols == 0) {
    *flWork = 0;
  } else if (mySpec->flagSuccessWrite == 1) {
    *mnt_n += countSymbols;
    mntSuccessRecord += 1;
    mySpec->flagSuccessWrite = 0;
  }

  return mntSuccessRecord;
}