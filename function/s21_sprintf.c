#include "../s21_sprintf.h"

#include "../s21_string.h"

void init_format_spec(FormatSpec *spec) {
  spec->left_align = 0;  // выравнивание по левому краю - флаг -
  spec->show_sign = 0;  // выравнивание по правому краю - флаг +
  spec->space = 0;       // пробел
  spec->width = 0;       // число (ширина)
  spec->precision = -1;  // точность
  spec->lenght_h = 0;
  spec->lenght_l = 0;
  spec->lenght_L = 0;
  spec->space_num = 0;
  spec->leading_zero = 0;
  spec->written = 0;
  spec->lattice = 0;  // решетка
  spec->flag_zero = 0;
}

void parse_flags(const char **format, FormatSpec *spec) {
  while (**format == '-' || **format == '+' || **format == ' ' ||
         **format == '#' || **format == '0') {
    if (**format == '-') spec->left_align = 1;
    if (**format == '+') spec->show_sign = 1;
    if (**format == ' ') spec->space = 1;
    if (**format == '#') spec->lattice = 1;
    if (**format == '0') spec->flag_zero = 1;
    (*format)++;
  }
}

void parse_width(const char **format, FormatSpec *spec, va_list args) {
  if (**format == '*') {  // ширина из доп задания
    spec->width = va_arg(args, int);
    (*format)++;
  } else {  // ширина с помощью числа
    while (**format >= '0' && **format <= '9') {
      spec->width = spec->width * 10 + (**format - '0');
      (*format)++;
    }
  }
}

void parse_precision(const char **format, FormatSpec *spec, va_list args) {
  if (**format == '.') {  // точность по точке
    (*format)++;
    if (**format == '*') {  // точность по * из доп
      spec->precision = va_arg(args, int);
      (*format)++;
    } else {
      spec->precision = 0;
      while (**format >= '0' && **format <= '9') {
        spec->precision = spec->precision * 10 + (**format - '0');
        (*format)++;
      }
    }
  }
}

void parse_lenght(const char **format, FormatSpec *spec) {
  if (**format == 'h') {
    spec->lenght_h = 1;
    (*format)++;
  } else if (**format == 'l') {
    spec->lenght_l = 1;
    (*format)++;
  } else if (**format == 'L') {
    spec->lenght_L = 1;
    (*format)++;
  }
}

void specifier_c(va_list args, char *str, int *written, FormatSpec *spec) {
  char value = (char)va_arg(args, int);
  if (spec->left_align) {
    str[(*written)++] = value;
    for (int i = 1; i < spec->width; i++) {
      str[(*written)++] = ' ';
    }
  } else {
    for (int i = 1; i < spec->width; i++) {
      str[(*written)++] = ' ';
    }
    str[(*written)++] = value;
  }
}

void specifier_d(va_list args, char *str, int *written, FormatSpec *spec) {
  int value = va_arg(args, int);
  if (spec->lenght_h) {
    value = (short)value;
  } else if (spec->lenght_l) {
    value = (long)value;
  }

  char buffer[64];
  int i = 0;
  int is_negative = value < 0;
  if (is_negative) {
    value = -value;
  }

  while (value > 0) {
    buffer[i++] = '0' + (value % 10);
    value /= 10;
  }

  if (is_negative) {
    buffer[i++] = '-';
  } else if (spec->show_sign) {
    buffer[i++] = '+';
  } else if (spec->space) {
    buffer[i++] = ' ';
  }

  // Добавляем нули, если точность больше длины числа
  while (i < spec->precision) {
    buffer[i++] = '0';
  }

  int padding = spec->width - i;
  if (!spec->left_align) {
    char pad_char;
    if (spec->flag_zero) {
      pad_char = '0';
    } else {
      pad_char = ' ';
    }
    while (padding-- > 0) {
      str[(*written)++] = pad_char;
    }
  }

  while (i > 0) {
    str[(*written)++] = buffer[--i];
  }

  if (spec->left_align) {
    while (padding-- > 0) {
      str[(*written)++] = ' ';
    }
  }
}

void uint_to_str(
    unsigned int value,
    char *buffer) {  // преобразует беззнаковое целое число в строку
  int i = 0;
  if (value == 0) {
    buffer[i++] = '0';
  } else {
    while (value > 0) {
      buffer[i++] = (value % 10) + '0';
      value /= 10;
    }
  }
  buffer[i] = '\0';

  for (int j = 0; j < i / 2; j++) {
    char temp = buffer[j];
    buffer[j] = buffer[i - j - 1];
    buffer[i - j - 1] = temp;
  }
}

int float_to_string(char *buffer, long double value,
                    FormatSpec *spec) {  // преобразует значение типа long
                                         // double в строку символов
  int len = 0;

  // Определяем, сколько знаков после запятой нужно вывести
  int precision;
  if (spec->precision >= 0) {
    precision = spec->precision;
  } else {
    precision = 6;
  }

  // Округляем число
  long double rounding = 0.5;
  for (int i = 0; i < precision; ++i) {
    rounding /= 10.0;
  }
  if (value < 0) {
    value -= rounding;
  } else {
    value += rounding;
  }

  // Получаем целую и дробную части числа
  long long int_part = (long long)value;
  long double frac_part = fabsl(value - int_part);

  // Преобразуем целую часть в строку
  if (int_part == 0) {
    buffer[len++] = '0';
  } else {
    if (int_part < 0) {
      buffer[len++] = '-';
      int_part = -int_part;
    }
    char int_str[32];
    int int_len = 0;
    while (int_part > 0) {
      int_str[int_len++] = '0' + (int_part % 10);
      int_part /= 10;
    }
    for (int i = int_len - 1; i >= 0; --i) {
      buffer[len++] = int_str[i];
    }
  }

  // Печатаем десятичную точку и дробную часть
  if (precision > 0) {
    buffer[len++] = '.';
    for (int i = 0; i < precision; ++i) {
      frac_part *= 10;
      int digit = (int)frac_part;
      buffer[len++] = '0' + digit;
      frac_part -= digit;
    }
  }

  buffer[len] = '\0';
  return len;
}

void check_minus_flag(char *str, FormatSpec *spec) {
  if (spec->left_align) {
    for (int i = 0; i < spec->space_num; i++) {
      str[spec->written++] = ' ';
    }
  }
}

void specifier_f(va_list args, char *str, int *written, FormatSpec *spec) {
  long double x;

  if (spec->lenght_L) {
    x = va_arg(args, long double);  // Используем long double, если длина L
  } else {
    x = va_arg(args, double);
  }

  if (spec->show_sign && x >= 0) {
    str[(*written)++] = '+';  // Добавляем знак "+" перед положительным числом,
                              // если флаг установлен
  } else if (spec->space && x >= 0) {
    str[(*written)++] = ' ';
  }

  if (spec->width && spec->width > 0) {
    char buffer[64];  // Буфер для хранения числа в строковом виде
    int llen = float_to_string(buffer, x, spec);
    spec->space_num = spec->width - llen;

    if (!spec->left_align) {
      char pad_char;
      if (spec->flag_zero) {
        pad_char = '0';
      } else {
        pad_char = ' ';
      }
      for (int i = 0; i < spec->space_num; i++) {
        str[(*written)++] = pad_char;
      }
    }
  }

  int len = float_to_string(str + *written, x, spec);  // Получаем длину строки
  *written += len;  // Увеличиваем written на длину строки

  if (spec->left_align) {
    for (int i = 0; i < spec->space_num; i++) {
      str[(*written)++] = ' ';
    }
  }

  if (spec->lattice && s21_strchr(str, '.') == S21_NULL) {
    str[(*written)++] = '.';
    str[(*written)++] = '0';
  }
}

void specifier_s(va_list args, char *str, int *written, FormatSpec *spec) {
  const char *x = va_arg(args, const char *);

  s21_size_t len = s21_strlen(x);

  // Вычисляем количество пробелов для выравнивания
  int width_padding;
  if ((s21_size_t)spec->width > len) {
    width_padding = spec->width - len;
  } else {
    width_padding = 0;
  }

  if (!spec->left_align) {
    // Добавляем пробелы до строки (если нужно)
    for (int i = 0; i < width_padding; i++) {
      str[(*written)++] = ' ';
    }
  }

  // Копируем строку в буфер
  for (s21_size_t i = 0; i < len; i++) {
    str[(*written)++] = x[i];
  }

  if (spec->left_align) {
    // Добавляем пробелы после строки (если нужно)
    for (int i = 0; i < width_padding; i++) {
      str[(*written)++] = ' ';
    }
  }
}

void specifier_u(va_list args, char *str, int *written, FormatSpec *spec) {
  unsigned int value = va_arg(args, unsigned int);
  char buffer[20];
  uint_to_str(value, buffer);
  int len = s21_strlen(buffer);

  // Вычисляем, сколько нужно дополнительных нулей для точности
  int precision_padding;
  if (spec->precision > len) {
    precision_padding = spec->precision - len;
  } else {
    precision_padding = 0;
  }

  int total_length = len + precision_padding;
  int width_padding;  // Количество пробелов
  if (spec->width > total_length) {
    width_padding = spec->width - total_length;
  } else {
    width_padding = 0;
  }

  if (!spec->left_align) {
    char pad_char;
    if (spec->flag_zero) {
      pad_char = '0';
    } else {
      pad_char = ' ';
    }
    while (width_padding-- > 0) {
      str[(*written)++] = pad_char;
    }
  }

  // Добавляем нули для точности
  while (precision_padding-- > 0) {
    str[(*written)++] = '0';
  }

  // Копируем само число
  for (int i = 0; i < len; ++i) {
    str[(*written)++] = buffer[i];
  }

  // Выравнивание по левому краю
  if (spec->left_align) {
    while (width_padding-- > 0) {
      str[(*written)++] = ' ';
    }
  }
}

void specifier_percent(char *str, int *written, FormatSpec *spec) {
  int width_padding = spec->width - 1;  // Один %

  if (!spec->left_align) {
    while (width_padding-- > 0) {
      str[(*written)++] = ' ';
    }
  }
  str[(*written)++] = '%';

  if (spec->left_align) {
    while (width_padding-- > 0) {
      str[(*written)++] = ' ';
    }
  }
}

void specifier_o(va_list args, char *str, int *written, FormatSpec *spec) {
  unsigned int value =
      va_arg(args, unsigned int);  // Получаем аргумент из списка аргументов

  char buffer[20];  // Выделение буфера для хранения восьмеричной строки
  int i = 0;        // Индекс для записи в буфер

  // Если число равно 0, то просто записываем '0'
  if (value == 0) {
    buffer[i++] = '0';
  } else {
    // Преобразование числа в восьмеричную строку
    while (value != 0) {
      buffer[i++] =
          (value % 8) +
          '0';  // Получаем остаток от деления на 8 и преобразуем в символ
      value /= 8;  // Делаем целочисленное деление на 8
    }

    // Добавляем префикс '0', если установлен флаг 'lattice' и число не ноль
    if (spec->lattice) {
      buffer[i++] = '0';
    }
  }

  // Если указана точность, выравниваем строку до нужной длины нулями
  while (i < spec->precision) {
    buffer[i++] = '0';
  }

  int total_length = i;

  // Вычисляем количество символов для ширины
  int width_padding;
  if (spec->width > total_length) {
    width_padding = spec->width - total_length;
  } else {
    width_padding = 0;
  }

  // Выравнивание по правому краю с пробелами
  if (!spec->left_align && !spec->flag_zero) {
    while (width_padding-- > 0) {
      str[(*written)++] = ' ';
    }
  }

  // Выравнивание по правому краю с нулями
  if (!spec->left_align && spec->flag_zero) {
    while (width_padding-- > 0) {
      str[(*written)++] = '0';
    }
  }

  // Переносим символы из буфера в выходную строку в обратном порядке
  while (i > 0) {
    str[(*written)++] = buffer[--i];
  }

  // Выравнивание по левому краю с пробелами
  if (spec->left_align) {
    while (width_padding-- > 0) {
      str[(*written)++] = ' ';
    }
  }
}
void specifier_x(va_list args, char *str, int *written, FormatSpec *spec,
                 int uppercase) {
  unsigned int value = va_arg(args, unsigned int);
  unsigned int original_value = value;  // Сохранение исходного значения

  char buffer[20];
  int i = 0;

  // Преобразование числа в шестнадцатеричную систему счисления
  if (value == 0) {
    buffer[i++] = '0';
  } else {
    while (value != 0) {
      int digit = value % 16;
      if (digit < 10) {
        buffer[i++] = (digit + '0');
      } else {
        if (uppercase) {
          buffer[i++] = digit - 10 + 'A';
        } else {
          buffer[i++] = digit - 10 + 'a';
        }
      }
      value /= 16;
    }
  }

  // Обработка precision
  if (spec->precision != -1) {
    while (i < spec->precision) {
      buffer[i++] = '0';
    }
  }

  int prefix_length;
  if (spec->lattice && original_value != 0) {
    prefix_length = 2;
  } else {
    prefix_length = 0;
  }  // Длина префикса "0x" или "0X"
  int total_length = i + prefix_length;  // Общая длина числа с префиксом
  int width_padding;
  if (spec->width > total_length) {
    width_padding = spec->width - total_length;
  } else {
    width_padding = 0;
  }  // Количество символов для заполнения ширины

  // Заполнение ширины символами
  if (!spec->left_align && !spec->flag_zero) {
    while (width_padding-- > 0) {
      str[(*written)++] = ' ';
    }
  }

  // Печать префикса "0x" или "0X"
  if (spec->lattice && original_value != 0) {
    str[(*written)++] = '0';
    if (uppercase) {
      str[(*written)++] = 'X';
    } else {
      str[(*written)++] = 'x';
    }
  }

  // Заполнение нулями, если флаг нуля установлен и нет выравнивания по левому
  // краю
  if (!spec->left_align && spec->flag_zero) {
    while (width_padding-- > 0) {
      str[(*written)++] = '0';
    }
  }

  // Печать числа
  while (i > 0) {
    str[(*written)++] = buffer[--i];
  }

  // Заполнение ширины символами (если выравнивание влево)
  if (spec->left_align) {
    while (width_padding-- > 0) {
      str[(*written)++] = ' ';
    }
  }
}

void specifier_x_lower(va_list args, char *str, int *written,
                       FormatSpec *spec) {
  specifier_x(args, str, written, spec, 0);
}

void specifier_x_upper(va_list args, char *str, int *written,
                       FormatSpec *spec) {
  specifier_x(args, str, written, spec, 1);
}

void specifier_p(va_list args, char *str, int *written, FormatSpec *spec) {
  void *pointer = va_arg(args, void *);
  unsigned long value = (unsigned long)pointer;  // преобразуем указатель в
                                                 // число

  char buffer[20];
  int i = 0;

  if (value == 0) {
    buffer[i++] = '0';
  } else {
    while (value != 0) {
      int digit = value % 16;
      if (digit < 10) {
        buffer[i++] = (digit + '0');
      } else {
        buffer[i++] = digit - 10 + 'a';
      }
      value /= 16;
    }
  }

  buffer[i++] = 'x';
  buffer[i++] = '0';

  int total_length = i;  // Общая длина числа с префиксом
  int width_padding;
  if (spec->width > total_length) {
    width_padding = spec->width - total_length;
  } else {
    width_padding = 0;
  }  // Количество символов для заполнения ширины

  if (!spec->left_align) {
    while (width_padding-- > 0) {
      str[(*written)++] = ' ';
    }
  }

  while (i > 0) {
    str[(*written)++] = buffer[--i];
  }

  if (spec->left_align) {
    while (width_padding-- > 0) {
      str[(*written)++] = ' ';
    }
  }
}

void specifier_e(va_list args, char *str, int *written, FormatSpec *spec,
                 int uppercase) {
  long double value;

  if (spec->lenght_L) {
    value = va_arg(args, long double);
  } else {
    value = va_arg(args, double);
  }

  // Если точность не указана, используем стандартную точность 6
  int precision = (spec->precision == -1) ? 6 : spec->precision;

  // Определение знака числа
  int sign = (value < 0) ? -1 : 1;
  value = fabsl(value);

  // Определение порядка (экспоненты)
  int exponent = 0;
  if (value != 0.0) {
    while (value >= 10.0) {
      value /= 10.0;
      exponent++;
    }
    while (value < 1.0) {
      value *= 10.0;
      exponent--;
    }
  }

  // Округление числа до указанной точности
  long double rounding = 0.5;
  for (int i = 0; i < precision; i++) {
    rounding /= 10.0;
  }
  value += rounding;

  // Пересчитываем порядок после округления
  if (value >= 10.0) {
    value /= 10.0;
    exponent++;
  }

  // Буфер для промежуточной строки
  char temp[100];
  int temp_written = 0;

  // Запись знака числа
  if (sign == -1) {
    temp[temp_written++] = '-';
  } else if (spec->show_sign) {
    temp[temp_written++] = '+';
  } else if (spec->space) {
    temp[temp_written++] = ' ';
  }

  // Запись числа в мантиссе
  temp[temp_written++] = '0' + (int)value;
  value -= (int)value;

  if (precision > 0 || spec->lattice) {
    temp[temp_written++] = '.';
  }

  for (int i = 0; i < precision; i++) {
    value *= 10.0;
    temp[temp_written++] = '0' + (int)value;
    value -= (int)value;
  }

  // Запись экспоненты
  temp[temp_written++] = uppercase ? 'E' : 'e';
  if (exponent < 0) {
    temp[temp_written++] = '-';
    exponent = -exponent;
  } else {
    temp[temp_written++] = '+';
  }

  // Запись порядка в виде двух цифр
  if (exponent >= 100) {
    temp[temp_written++] = '0' + (exponent / 100);
    exponent %= 100;
  }

  temp[temp_written++] = '0' + (exponent / 10);
  temp[temp_written++] = '0' + (exponent % 10);

  // Определяем длину итоговой строки
  int final_length = temp_written;

  // Если ширина больше длины строки и выравнивание не по левому краю
  if (!spec->left_align && spec->width > final_length) {
    for (int i = 0; i < spec->width - final_length; i++) {
      str[(*written)++] = ' ';
    }
  }

  // Копируем временную строку в итоговую
  for (int i = 0; i < temp_written; i++) {
    str[(*written)++] = temp[i];
  }

  // Если выравнивание по левому краю и ширина больше длины строки
  if (spec->left_align && spec->width > final_length) {
    for (int i = 0; i < spec->width - final_length; i++) {
      str[(*written)++] = ' ';
    }
  }
}

// Обновленная функция для обработки спецификатора e
void specifier_e_lower(va_list args, char *str, int *written,
                       FormatSpec *spec) {
  specifier_e(args, str, written, spec, 0);
}

// Новая функция для обработки спецификатора E
void specifier_e_upper(va_list args, char *str, int *written,
                       FormatSpec *spec) {
  specifier_e(args, str, written, spec, 1);
}

int s21_sprintf(char *str, const char *format, ...) {
  if (str == S21_NULL || format == S21_NULL) return -1;

  va_list args;
  va_start(args, format);

  int written = 0;

  while (*format != '\0') {
    if (*format == '%') {
      format++;
      FormatSpec spec;
      init_format_spec(&spec);

      parse_flags(&format, &spec);
      parse_width(&format, &spec, args);
      parse_precision(&format, &spec, args);
      parse_lenght(&format, &spec);

      if (*format == 'd') {
        specifier_d(args, str, &written, &spec);
      } else if (*format == 'c') {
        specifier_c(args, str, &written, &spec);
      } else if (*format == 'u') {
        specifier_u(args, str, &written, &spec);
      } else if (*format == '%') {
        specifier_percent(str, &written, &spec);
      } else if (*format == 'f') {
        specifier_f(args, str, &written, &spec);
      } else if (*format == 's') {
        specifier_s(args, str, &written, &spec);
      } else if (*format == 'o') {
        specifier_o(args, str, &written, &spec);
      } else if (*format == 'x') {
        specifier_x_lower(args, str, &written, &spec);
      } else if (*format == 'X') {
        specifier_x_upper(args, str, &written, &spec);
      } else if (*format == 'p') {
        specifier_p(args, str, &written, &spec);
      } else if (*format == 'e') {
        specifier_e_lower(args, str, &written, &spec);
      } else if (*format == 'E') {
        specifier_e_upper(args, str, &written, &spec);
      }
    } else {
      str[written++] = *format;
    }
    format++;
  }

  str[written] = '\0';
  va_end(args);
  return written;
}
