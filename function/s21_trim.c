
#include "../s21_string.h"

char *s21_trim(const char *src, const char *trim_chars) {
  if (src == S21_NULL || trim_chars == S21_NULL) {
    return S21_NULL;
  }

  const char *start = src;
  const char *end = src + s21_strlen(src) - 1;  // s21

  // Функция проверки, входит ли символ в строку trim_chars
  while (*start) {
    const char *temp = trim_chars;
    int is_trim = 0;
    while (*temp) {
      if (*start == *temp) {
        is_trim = 1;
        break;
      }
      temp++;
    }
    if (!is_trim) {
      break;
    }
    start++;
  }

  // Поиск первого символа, не входящего в trim_chars, с конца строки
  while (end >= start) {
    const char *temp = trim_chars;
    int is_trim = 0;
    while (*temp) {
      if (*end == *temp) {
        is_trim = 1;
        break;
      }
      temp++;
    }
    if (!is_trim) {
      break;
    }
    end--;
  }

  // Вычисление длины новой строки
  s21_size_t new_length = end - start + 1;

  // Создание новой строки
  char *trimmed_str = (char *)malloc(new_length + 1);
  if (trimmed_str == S21_NULL) {
    return S21_NULL;
  }

  // Копирование подстроки в новую строку
  for (s21_size_t i = 0; i < new_length; i++) {
    trimmed_str[i] = start[i];
  }
  trimmed_str[new_length] = '\0';

  return trimmed_str;
}
