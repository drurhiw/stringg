#include "../s21_string.h"

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  char *start = dest;
  while (n > 0 && *src != '\0') {
    *dest++ = *src++;
    n--;
  }
  *dest = '\0';
  return start;
}
