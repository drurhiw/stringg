
#include "../s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  // проверяем, что указатель на строку не NULL
  if (str == S21_NULL || src == S21_NULL) {
    return S21_NULL;
  }

  s21_size_t src_lenght = s21_strlen(src);  // S21
  s21_size_t str_lenght = s21_strlen(str);  // S21

  if (start_index > src_lenght) {
    return S21_NULL;
  }

  s21_size_t new_lenght = src_lenght + str_lenght;
  char *new_str = (char *)malloc(new_lenght + 1);
  if (new_str == S21_NULL) {
    return S21_NULL;
  }

  // копирование первой части строки src до staart_index
  for (s21_size_t i = 0; i < start_index; i++) {
    new_str[i] = src[i];
  }

  // копирование строки str в новую строку
  for (s21_size_t i = 0; i < str_lenght; i++) {
    new_str[start_index + i] = str[i];
  }

  // копирование оставшейся части строки src после start_index
  for (s21_size_t i = start_index; i < src_lenght; i++) {
    new_str[i + str_lenght] = src[i];
  }

  new_str[new_lenght] = '\0';

  return new_str;
}