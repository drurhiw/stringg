#include "../s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  const char *p = S21_NULL;
  while (*str1 != '\0') {
    for (int j = 0; str2[j] != '\0'; j++) {
      if (*str1 == str2[j]) {
        p = str1;
        return (char *)p;
      }
    }
    str1++;
  }
  return (char *)p;
}