
#include "../s21_string.h"

void *s21_to_upper(const char *str) {
  // проверяем, что указатель на строку не NULL
  if (str == S21_NULL) {
    return S21_NULL;
  }

  s21_size_t lenght = s21_strlen(str);  // S21

  char *upper_str = (char *)malloc(lenght + 1);
  if (upper_str == S21_NULL) {
    return S21_NULL;
  }

  for (s21_size_t i = 0; i < lenght; i++) {
    char c = str[i];
    if (c >= 'a' && c <= 'z') {
      upper_str[i] = c - 32;
    } else {
      upper_str[i] = c;
    }
  }

  upper_str[lenght] = '\0';

  return upper_str;
}