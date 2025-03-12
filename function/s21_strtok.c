#include "../s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *lastToken = S21_NULL;
  char *tokenStart = S21_NULL;

  if ((str != S21_NULL || (lastToken != S21_NULL && *lastToken != '\0'))) {
    if (str != S21_NULL) {
      lastToken = str;
    }

    while (*lastToken && s21_strchr(delim, *lastToken) != S21_NULL) {
      ++lastToken;
    }

    if (*lastToken != '\0') {
      tokenStart = lastToken;

      while (*lastToken && s21_strchr(delim, *lastToken) == S21_NULL) {
        ++lastToken;
      }

      if (*lastToken != '\0') {
        *lastToken = '\0';
        ++lastToken;
      }
    }
  }

  return tokenStart;
}