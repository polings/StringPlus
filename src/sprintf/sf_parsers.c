#include "../s21_string.h"
#include "sf_parsesr.h"

struct sf_flag parserFormat(char *pattern, char fc) {
  struct sf_flag f = {0};
  int n = 0, ch_z = 0;
  char num[256];
  for (const char *c = pattern; *c && *c != '\0'; c++) {
    if (*c == '-') {
      f.minus += 1;
    } else if (*c == '+' && !containtStr(fc, "u")) {
      f.plus += 1;
    } else if (*c == ' ' && !containtStr(fc, "u")) {
      f.space += 1;
    } else if (*c == '#') {
      f.octot += 1;
    } else if (*c >= 48 && *c <= 57) {
      if (*c == '0' && !ch_z) {
        f.zero += 1;
        ch_z = 1;
      }
      num[n++] = *c;
      num[n] = '\0';
      ch_z = -1;
      if (f.dot == 1) {
        f.acc = atoi(num);
      } else {
        f.width = atoi(num);
      }
    } else if (f.dot && *c == '*') {
      f.starE += 1;
    } else if (*c == '*') {
      f.starS += 1;
    } else if (*c == '.') {
      n = 0;
      f.dot += 1;
    } else if (*c == 'h' && containtStr(fc, "idouxX")) {
      f.h += 1;
    } else if (*c == 'l' && containtStr(fc, "idouxXcs")) {
      f.lowL += 1;
    } else if (*c == 'L' && containtStr(fc, "eEfgG")) {
      f.upL += 1;
    }
  }
  if (f.plus) f.space = 0;
  return f;
}

int containtStr(char c, char *str) {
  int i = 0, res = 0;
  for (; str[i] != '\0'; i++) {
    if (c == str[i]) {
      res = 1;
      break;
    }
  }
  return res;
}
int intToChar(long long val, char *str, s21_size_t *i) {
  if (val < 0) {
    val *= -1;
    str[*i] = '-';
    *i += 1;
  }
  if (val >= 10) {
    intToChar(val / 10, str, i);
    str[*i] = val % 10 + '0';
    *i += 1;
  } else {
    str[*i] = '0' + val % 10;
    *i += 1;
  }
  str[*i] = '\0';
  return 1;
}

int lenInt(long long int val) {
  if (val < 0) {
    val *= -1;
  }
  int count = 0;
  if (val > 9)
    while (val != 0) {
      val /= 10;
      count++;
    }
  else
    count = 1;
  return count;
}
int addSymbols(char *str, s21_size_t *i, char c, int count) {
  for (int p = 0; p < count; p++) {
    str[*i] = c;
    *i += 1;
  }
  return 0;
}
/*!
 *@function      floatToChar
 *@discussion    Фунция перевода и записи десятичного числа в строку.
 *               Полученное число необходимо разлелить на значение до и после
 *запятой. Отбрасывае от whole (целая часть) дробную часть. И переводим его в
 *строку. Далее переходим к fract (дробная часть). Если у нас точность больше
 *нуля начинаем запись fract в строку. Так как дробная часть может иметь нули
 *(0.00001), то мы добавляем их в строку сразу до тех пор пока не встретим
 *первое отличное от нуля число. Эти числа мы конвертируем в целочисленное
 *значение. Полученное число записываем в строку.
 * @param whole значение целой части.
 * @param fract значение дробной части.
 * @param valueFract значение дробной части певеденное в целое.
 */
int floatToChar(double val, char *str, s21_size_t *i, int acc) {
  int startZero = 0;
  long count = 0;
  long double whole;
  long double fract;
  fract = modfl(val, &whole);
  count = lenInt((long long)whole);
  intToChar((long)whole, str, i);

  if (acc > 0) {
    str[*i] = '.';
    *i += 1;
    count++;
    long long len = 0;
    long long valueFract = 0;
    while (len < acc) {
      fract *= 10;
      if (len + 1 == acc) fract += 0.5;
      int fInt = (int)fract;
      if (!startZero && fInt == 0) {
        str[*i] = '0';
        *i += 1;
      } else
        startZero = 1;
      valueFract = valueFract * 10 + fInt;
      if (fInt == 10) fInt = 0;
      fract -= fInt;
      len++;
      count++;
    }
    if (valueFract != 0) intToChar(valueFract, str, i);
  }
  return count;
}

long unsigned int wcharLen(wchar_t *stroke) {
  long unsigned int i = 0;
  for (; stroke[i] != '\0'; i++)
    ;
  return i;
}