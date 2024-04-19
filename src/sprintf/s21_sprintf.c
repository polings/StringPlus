#include "s21_sprintf.h"

#include "../s21_string.h"

int s21_sprintf(char* str, const char* format, ...) {
  s21_size_t i = 0, p = 0, perc = 0;
  str[0] = '\0';
  va_list factor;
  va_start(factor, format);
  char pattern[256];
  for (const char* c = format; *c; c++) {
    if (*c != '%' && perc == 0) {
      str[i++] = *c;
      continue;
    }
    if (*c == '%') {
      if (perc == 1) {
        str[i++] = *c;
        perc = 0;
      } else {
        perc = 1;
      }
      p = 0;
    } else if (perc == 1) {
      pattern[p] = '\0';
      if (*c == 'c') {
        perc = fl_c(factor, str, &i, pattern, *c);
      } else if (*c == 'd' || *c == 'u' || *c == 'i') {
        perc = fl_d_u_i(factor, str, &i, pattern, *c);
      } else if (*c == 'f') {
        perc = fl_f(str, &i, pattern, factor, *c);
      } else if (*c == 'o')
        printf("flag o\n");
      else if (*c == 's')
        perc = flag_s(factor, str, &i, pattern, *c);
      else
        pattern[p++] = *c;
    }
  }
  str[i] = '\0';
  va_end(factor);
  return i;
}
/*!
 *@function      fl_c
 *@discussion    Эта фунция записывает в указанную строку один char по
 *преданному паттерну.
 *@param factor  лист возможных параметров.
 *@param str     строка в которую записыввем.
 *@param i       указатель на позицию текущей ячеки записи в строке.
 *@param pattern условия по которым необходимо записать полученное значение в
 *строку.
 *@param fc      идентификотор ожидаемого значения.
 */
int fl_c(va_list factor, char* str, s21_size_t* i, char* pattern, char fc) {
  struct sf_flag flag = parserFormat(pattern, fc);
  if (flag.starS) flag.width = va_arg(factor, long);
  addSymbols(str, i, ' ', flag.width - 1);
  if (flag.lowL) {
    wchar_t c = va_arg(factor, wchar_t);
    str[*i] = c;
  } else {
    char c = va_arg(factor, int);
    str[*i] = c;
  }
  *i += 1;
  return 0;
}
/*!
 *@function      fl_d_u_i
 *@discussion    Эта фунция записывает в указанную строку целое число, алгоритм
 *записи зависит от наличия точности ( . - точки (acc)) в паттерне.
 */
int fl_d_u_i(va_list factor, char* str, s21_size_t* i, char* pattern, char fc) {
  struct sf_flag flag = parserFormat(pattern, fc);
  if (flag.dot)
    d_u_i_is_dot(str, i, flag, factor, fc);
  else
    d_u_i_not_dot(str, i, flag, factor, fc);
  return 0;
}
/*!
 *@function      d_u_i_is_dot
 *@discussion    Фунция записи целого числа при наличии точности.
 *               Через полученыей флаги паттерна мы определяем, есть ли у нас *
 *до точности и после точности. Если да, то записываем новые параметры ширины и
 *точности из переданного листа factor. Создаем три типа переменных, так как у
 *нас может быть флаг - l и ожидаемое число длинное безнаковое - u. Для того
 *чтобы вычислить новые значения точности и ширины, на нужен третий параметр -
 *длина числа. Инициализируем значения переменных исользу @function
 *get_value_d_u Если значение числа отрицательное, выставляем флаг + в занчение
 *1 (true). Если значение числа > 0 и флаг space 1, добавляем пробел в начало
 *строки, при этом уменьшая ширину на 1. Если флаг minus 1, выставляем знак
 *числа (если флаги 1), далее записываем '0' (точность), число, пробелы
 *(ширина). Если флаг minus 0, выводим пробелы, знак числа, нули, число.
 * @param value_d длина целого знакового числа.
 * @param value_u длина целого без знакового числа.
 */
int d_u_i_is_dot(char* str, s21_size_t* i, struct sf_flag flag, va_list factor,
                 char fc) {
  if (flag.starS) flag.width = va_arg(factor, int);
  if (flag.starE) flag.acc = va_arg(factor, int);
  long long value_d = 0;
  unsigned long value_u = 0;
  long long lenValue = 0;
  get_value_d_u(&value_u, &value_d, &lenValue, flag, factor, fc);
  flag.acc -= lenValue;
  flag.width -= (flag.acc > 0) ? flag.acc + lenValue : lenValue;
  if (value_d < 0) {
    flag.plus = 1;
    flag.width--;
  }
  if (flag.space && value_d > 0) {
    addSymbols(str, i, ' ', 1);
    flag.width--;
  }
  if (flag.minus) {
    if (flag.plus) {
      addSymbols(str, i, (value_d > 0) ? '+' : '-', 1);
      if (value_d < 0) value_d *= -1;
    }
    addSymbols(str, i, '0', flag.acc);
    (fc == 'u') ? intToChar(value_u, str, i) : intToChar(value_d, str, i);
    addSymbols(str, i, ' ', flag.width);
  } else {
    addSymbols(str, i, ' ', flag.width);
    if (flag.plus) {
      addSymbols(str, i, (value_d > 0) ? '+' : '-', 1);
      if (value_d < 0) value_d *= -1;
    }
    addSymbols(str, i, '0', flag.acc);
    (fc == 'u') ? intToChar(value_u, str, i) : intToChar(value_d, str, i);
  }
  return 0;
}
/*!
 *@function      d_u_i_not_dot
 *@discussion    Фунция записи целого числа при отсутсвии точности.
 *               Через полученыей флаги паттерна мы определяем, есть ли у нас *
 *. Если да, то записываем новый параметр ширины переданного листа factor.
 *               Создаем три типа переменных, так как у нас может быть флаг - l
 *и ожидаемое число длинное безнаковое - u. Инициализируем значения переменных
 *исользу @function get_value_d_u Если значение числа отрицательное, выставляем
 *флаг + в занчение 1 (true). Если значение числа > 0 и флаг space 1, добавляем
 *пробел в начало строки, при этом уменьшая ширину на 1. Если флаг minus 1,
 *выставляем знак числа (если флаги 1), далее записываем число и пробелы
 *(ширина), флаг '0' (zero) игнорируется. Если флаг minus 0, тут необходимо
 *проверить флаг '0', если его нет, то записываем пробели  + знак чила (если
 *надо)
 *               + число. Если флаг '0' 1 , то сначала записываем знак числа,
 *затем число.
 * @param value_d длина целого знакового числа.
 * @param value_u длина целого без знакового числа.
 */
int d_u_i_not_dot(char* str, s21_size_t* i, struct sf_flag flag, va_list factor,
                  char fc) {
  if (flag.starS) flag.width = va_arg(factor, int);
  long long value_d = 0;
  unsigned long value_u = 0;
  long long lenValue = 0;
  get_value_d_u(&value_u, &value_d, &lenValue, flag, factor, fc);
  long long countSymb = flag.width - lenValue;
  if (flag.space && value_d > 0) {
    addSymbols(str, i, ' ', 1);
    countSymb--;
  }
  if (flag.plus || (value_d < 0 && flag.minus) ||
      (value_d < 0 && flag.zero && !flag.minus)) {
    addSymbols(str, i, (value_d > 0) ? '+' : '-', 1);
    if (value_d < 0) value_d *= -1;
    flag.plus = 1;
  }
  char symb = ' ';
  if (flag.zero && !flag.minus) symb = '0';
  if (flag.plus || value_d < 0) countSymb -= 1;
  if (flag.minus) {
    if (fc == 'u')
      intToChar(value_u, str, i);
    else
      intToChar(value_d, str, i);
  }
  addSymbols(str, i, symb, countSymb);
  if (!flag.minus) {
    if (fc == 'u')
      intToChar(value_u, str, i);
    else
      intToChar(value_d, str, i);
  }
  return 0;
}
void get_value_d_u(unsigned long* value_u, long long* value_d,
                   long long* lenValue, struct sf_flag flag, va_list factor,
                   char fc) {
  if (fc == 'd') {
    if (flag.lowL && !flag.h)
      *value_d = va_arg(factor, long);
    else if (flag.h)
      *value_d = (short)va_arg(factor, int);
    else
      *value_d = va_arg(factor, int);
    *lenValue = lenInt(*value_d);
  } else if (fc == 'u') {
    if (flag.lowL && !flag.h)
      *value_u = va_arg(factor, long unsigned);
    else if (flag.h)
      *value_u = (short unsigned)va_arg(factor, unsigned int);
    else
      *value_u = va_arg(factor, int unsigned);
    *lenValue = lenInt(*value_u);
  }
}
int fl_f(char* str, s21_size_t* i, char* pattern, va_list factor, char fc) {
  struct sf_flag flag = parserFormat(pattern, fc);
  if (flag.starS) flag.width = va_arg(factor, int);
  if (flag.starE) flag.acc = va_arg(factor, int);
  long double value =
      (flag.upL) ? va_arg(factor, long double) : va_arg(factor, double);
  flag.acc = (flag.dot) ? flag.acc : 6;
  if (value < 0) {
    flag.plus = 1;
  }
  if (flag.space && !flag.plus) {
    str[*i] = ' ';
    *i += 1;
    flag.width--;
  }
  if (flag.plus) flag.width--;
  if (flag.acc != 0) flag.width--;
  f_dot(str, i, flag, value);
  str[*i] = '\0';
  return 0;
}
void f_dot(char* str, s21_size_t* i, sf_flag flag, long double value) {
  char symb = ' ';
  if (flag.zero && !flag.minus) symb = '0';
  long int lenValue = lenInt((long int)value);
  flag.width = flag.width - lenValue - flag.acc;
  if (flag.plus && (symb == '0' || flag.minus)) {
    addSymbols(str, i, (value > 0) ? '+' : '-', 1);
    if (value < 0) value *= -1;
  }
  if (!flag.minus) {
    addSymbols(str, i, symb, flag.width);
    if (flag.plus && symb == ' ') {
      addSymbols(str, i, (value > 0) ? '+' : '-', 1);
      if (value < 0) value *= -1;
    }
    floatToChar(value, str, i, flag.acc);
    if (flag.octot && flag.acc == 0) addSymbols(str, i, '.', 1);
  } else if (flag.minus) {
    floatToChar(value, str, i, flag.acc);
    if (flag.octot && flag.acc == 0) addSymbols(str, i, '.', 1);
    addSymbols(str, i, symb, flag.width);
  }
}

int flag_s(va_list factor, char* str, s21_size_t* i, char* pattern, char fc) {
  struct sf_flag flag = parserFormat(pattern, fc);
  if (flag.starS) flag.width = va_arg(factor, int);
  if (flag.starE) flag.acc = va_arg(factor, int);
  long long len = (flag.dot) ? flag.acc : 1;
  if (flag.lowL) {
    flag_s_wchar(str, i, factor, flag, len);
  } else {
    flag_s_char(str, i, factor, flag, len);
  }
  return 0;
}
void flag_s_wchar(char* str, s21_size_t* i, va_list factor, sf_flag flag,
                  long long len) {
  (void)setlocale(LC_ALL, "");
  wchar_t* stroke = va_arg(factor, wchar_t*);
  if (flag.dot) {
    flag.width -= flag.acc;
  } else {
    flag.width -= wcharLen(stroke);
  }
  if (!flag.minus) {
    addSymbols(str, i, ' ', flag.width);
  }
  for (wchar_t* c = stroke; *c != '\0' && len > 0; c++, *i += 1) {
    if (flag.dot) len--;
    str[*i] = *c;
  }
  if (flag.minus) {
    addSymbols(str, i, ' ', flag.width);
  }
}
void flag_s_char(char* str, s21_size_t* i, va_list factor, sf_flag flag,
                 long long len) {
  char* stroke = va_arg(factor, char*);
  if (flag.dot) {
    flag.width -= flag.acc;
  } else {
    flag.width -= s21_strlen(stroke);
  }
  if (!flag.minus) {
    addSymbols(str, i, ' ', flag.width);
  }
  for (char* c = stroke; *c != '\0' && len > 0; c++) {
    if (flag.dot) len--;
    str[*i] = *c;
    *i += 1;
  }
  if (flag.minus) {
    addSymbols(str, i, ' ', flag.width);
  }
}