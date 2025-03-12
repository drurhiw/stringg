
#include "../s21_string.h"

void *s21_to_lower(const char *str) {
  // проверяем, что указатель на строку не NULL
  if (str == S21_NULL) {
    return S21_NULL;
  }

  s21_size_t lenght = s21_strlen(str);  // S21

  char *lower_str = (char *)malloc(lenght + 1);
  if (lower_str == S21_NULL) {
    return S21_NULL;
  }

  for (s21_size_t i = 0; i < lenght; i++) {
    char c = str[i];
    if (c >= 'A' && c <= 'Z') {
      lower_str[i] = c + 32;
    } else {
      lower_str[i] = c;
    }
  }

  lower_str[lenght] = '\0';

  return lower_str;
}