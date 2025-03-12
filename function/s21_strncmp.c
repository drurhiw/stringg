#include "../s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  for (s21_size_t j = 0; j < n; j++) {
    if (str1[j] != str2[j]) {
      return (unsigned char)str1[j] - (unsigned char)str2[j];
    }
    if (str1[j] == '\0') {
      return 0;
    }
  }
  return 0;
}
