#include "../s21_string.h"

char *s21_strchr(const char *str, int c) {
  char *result = S21_NULL;
  if (c == '\0') {
    result = "";
  } else {
    while (*str != '\0') {
      if (*str == (char)c) {
        result = (char *)str;
        break;
      }
      str++;
    }
  }
  return result;
}