#include "../s21_sscanf.h"

int s21_sscanf(const char *str, const char *format, ...) {
  const char *pstr = str;
  const char *pfmt = format;
  int count = 0;
  va_list args;
  va_start(args, format);

  while (*pfmt != '\0') {
    if (*pfmt == '%') {
      pfmt++;

      // Пропускать ли запись
      int suppress = 0;
      if (*pfmt == '*') {
        suppress = 1;
        pfmt++;
      }

      // Ширина, какая я молодец
      // Сделать функцией нужно, но позже
      int width = 4096;
      if (*pfmt >= '0' && *pfmt <= '9') {
        width = 0;
        int sign = 1;
        if (*pfmt == '-') {
          sign = -1;
          pfmt++;
        }
        while (*pfmt >= '0' && *pfmt <= '9') {
          width = width * 10 + (*pfmt - '0');
          pfmt++;
        }
        width *= sign;
      }

      int is_long = 0;
      int is_short = 0;
      int is_long_double = 0;

      if (*pfmt == 'l') {
        is_long = 1;
        pfmt++;
      } else if (*pfmt == 'h') {
        is_short = 1;
        pfmt++;
      } else if (*pfmt == 'L') {
        is_long_double = 1;
        pfmt++;
      }

      if (*pfmt == 'd' || *pfmt == 'i') {
        sscanf_specifier_i(args, &pstr, is_long, is_short, width, suppress);
        count++;
      }
      if (*pfmt == 's') {
        sscanf_specifier_s(args, &pstr, is_long, width);
        count++;
      } else if (*pfmt == 'p') {
        sscanf_specifier_p(args, &pstr, width, suppress);
        if (!suppress) count++;
      } else if (*pfmt == 'u') {
        sscanf_specifier_u(args, &pstr, is_long, is_short, width);
        count++;
      } else if (*pfmt == 'n') {
        sscanf_specifier_n(args, str, pstr);
        pstr--;
      } else if (*pfmt == 'o') {
        sscanf_specifier_o(args, &pstr, is_long, is_short, width, suppress);
        if (!suppress) count++;
      } else if (*pfmt == 'e' || *pfmt == 'E' || *pfmt == 'f' || *pfmt == 'g' ||
                 *pfmt == 'G') {
        sscanf_specifier_e(args, &pstr, is_long_double, width);
        count++;
      } else if (*pfmt == 'x' || *pfmt == 'X') {
        sscanf_specifier_xX(args, &pstr, is_long, is_short, width);
        count++;
      } else if (*pfmt == 'c') {
        sscanf_specifier_c(args, &pstr, is_long, suppress);
        if (!suppress) count++;
      } else if (*pfmt == '%') {
        pstr++;
      }
    } else {
      if (*pfmt != *pstr) {
        return count;  // Error: Несоответствие формата
      }
      pstr++;
    }
    pfmt++;
  }

  va_end(args);
  return count;
}

void sscanf_specifier_s(va_list args, const char **pstr, int is_long,
                        int width) {
  // ширина * не используется
  if (is_long) {
    wchar_t *str = va_arg(args, wchar_t *);
    int i = 0;
    while (**pstr != ' ' && **pstr != '\0' && i < width) {
      i++;
      *str = (wchar_t) * *pstr;
      str++;
      (*pstr)++;
    }
    while (width != 4096 && i < width) {
      i++;
      *str = ' ';
      str++;
    }
    *str = L'\0';
  } else {
    char *str = va_arg(args, char *);
    int i = 0;
    while (**pstr != ' ' && **pstr != '\0' && i < width) {
      i++;
      *str = **pstr;
      str++;
      (*pstr)++;
    }
    while (width != 4096 && i < width) {
      i++;
      *str = ' ';
      str++;
    }
    *str = '\0';
  }
}

void sscanf_specifier_p(va_list args, const char **pstr, int width,
                        int suppress) {
  unsigned long long ptr_value = 0;
  int i = 0;

  // Пропуск префикса 0x или 0X, если он присутствует
  if (**pstr == '0' && ((*pstr)[1] == 'x' || (*pstr)[1] == 'X')) {
    *pstr += 2;
  }

  while (isxdigit(**pstr) && i < width) {
    i++;
    char digit = **pstr;
    if (isdigit(digit)) {
      ptr_value = ptr_value * 16 + (digit - '0');
    } else if (isxdigit(digit)) {
      ptr_value = ptr_value * 16 + (tolower(digit) - 'a' + 10);
    }
    (*pstr)++;
  }

  if (!suppress) {
    void **ptr = va_arg(args, void **);
    *ptr = (void *)ptr_value;
  }
}

void sscanf_specifier_u(va_list args, const char **pstr, int is_long,
                        int is_short, int width) {
  if (is_long) {
    unsigned long int *num = va_arg(args, unsigned long int *);
    *num = 0;
    int i = 0;

    while (**pstr >= '0' && **pstr <= '9' && i < width) {
      i++;
      *num = *num * 10 + (**pstr - '0');
      (*pstr)++;
    }
  } else if (is_short) {
    unsigned short int *num = va_arg(args, unsigned short int *);
    *num = 0;
    int i = 0;

    while (**pstr >= '0' && **pstr <= '9' && i < width) {
      i++;
      *num = *num * 10 + (**pstr - '0');
      (*pstr)++;
    }
  } else {
    unsigned int *num = va_arg(args, unsigned int *);
    *num = 0;
    int i = 0;

    while (**pstr >= '0' && **pstr <= '9' && i < width) {
      i++;
      *num = *num * 10 + (**pstr - '0');
      (*pstr)++;
    }
  }
}

void sscanf_specifier_n(va_list args, const char *start, const char *current) {
  int *num = va_arg(args, int *);
  *num = current - start;
}

void sscanf_specifier_o(va_list args, const char **pstr, int is_long,
                        int is_short, int width, int suppress) {
  long long num = 0;
  int i = 0;

  while (**pstr >= '0' && **pstr <= '7' && i < width) {
    i++;
    num = num * 8 + (**pstr - '0');
    (*pstr)++;
  }

  if (!suppress) {
    if (is_long) {
      unsigned long int *pnum = va_arg(args, unsigned long int *);
      *pnum = (unsigned long int)num;
    } else if (is_short) {
      unsigned short int *pnum = va_arg(args, unsigned short int *);
      *pnum = (unsigned short int)num;
    } else {
      unsigned int *pnum = va_arg(args, unsigned int *);
      *pnum = (unsigned int)num;
    }
  }
}

void sscanf_specifier_e(va_list args, const char **pstr, int is_long_double,
                        int width) {
  if (is_long_double) {
    long double *p = va_arg(args, long double *);
    *p = strtold_custom(pstr, width);
  } else {
    double *p = va_arg(args, double *);
    *p = strtod_custom(pstr, width);
  }
}

void sscanf_specifier_xX(va_list args, const char **pstr, int is_long,
                         int is_short, int width) {
  if (is_long) {
    unsigned long int *num = va_arg(args, unsigned long int *);
    *num = 0;
    int i = 0;

    while (isxdigit(**pstr) && i < width) {
      i++;
      if (**pstr >= '0' && **pstr <= '9')
        *num = *num * 16 + (**pstr - '0');
      else if (**pstr >= 'a' && **pstr <= 'f')
        *num = *num * 16 + (**pstr - 'a' + 10);
      else if (**pstr >= 'A' && **pstr <= 'F')
        *num = *num * 16 + (**pstr - 'A' + 10);
      (*pstr)++;
    }
  } else if (is_short) {
    unsigned short int *num = va_arg(args, unsigned short int *);
    *num = 0;
    int i = 0;

    while (isxdigit(**pstr) && i < width) {
      i++;
      if (**pstr >= '0' && **pstr <= '9')
        *num = *num * 16 + (**pstr - '0');
      else if (**pstr >= 'a' && **pstr <= 'f')
        *num = *num * 16 + (**pstr - 'a' + 10);
      else if (**pstr >= 'A' && **pstr <= 'F')
        *num = *num * 16 + (**pstr - 'A' + 10);
      (*pstr)++;
    }
  } else {
    unsigned int *num = va_arg(args, unsigned int *);
    *num = 0;
    int i = 0;

    while (isxdigit(**pstr) && i < width) {
      i++;
      if (**pstr >= '0' && **pstr <= '9')
        *num = *num * 16 + (**pstr - '0');
      else if (**pstr >= 'a' && **pstr <= 'f')
        *num = *num * 16 + (**pstr - 'a' + 10);
      else if (**pstr >= 'A' && **pstr <= 'F')
        *num = *num * 16 + (**pstr - 'A' + 10);
      (*pstr)++;
    }
  }
}

void sscanf_specifier_i(va_list args, const char **pstr, int is_long,
                        int is_short, int width, int suppress) {
  int base = 10;
  int i = 0;
  if (**pstr == '0' && i < width) {
    i++;
    (*pstr)++;
    if ((**pstr == 'x' || **pstr == 'X') && i < width) {
      i++;
      base = 16;
      (*pstr)++;
    } else {
      base = 8;
    }
  }

  long long num = 0;
  num = strtol_custom(pstr, base, width, i);

  if (!suppress) {
    if (is_long) {
      long int *pnum = va_arg(args, long int *);
      *pnum = (long int)num;
    } else if (is_short) {
      short int *pnum = va_arg(args, short int *);
      *pnum = (short int)num;
    } else {
      int *pnum = va_arg(args, int *);
      *pnum = (int)num;
    }
  }
}

void sscanf_specifier_c(va_list args, const char **pstr, int is_long,
                        int suppress) {
  char value = 0;
  value = **pstr;
  (*pstr)++;

  if (!suppress) {
    if (is_long) {
      wchar_t *pvalue = va_arg(args, wchar_t *);
      *pvalue = (wchar_t)value;
    } else {
      char *pvalue = va_arg(args, char *);
      *pvalue = value;
    }
  }
}

double strtod_custom(const char **pstr, int width) {
  double result = 0.0;
  double divisor = 10.0;
  int sign = 1;

  if (**pstr == '-') {
    sign = -1;
    (*pstr)++;
  }

  int i = 0;
  while (**pstr >= '0' && **pstr <= '9' && i < width) {
    i++;
    result = result * 10.0 + (**pstr - '0');
    (*pstr)++;
  }

  if (**pstr == '.') {
    (*pstr)++;
    i++;
    while (**pstr >= '0' && **pstr <= '9' && i < width) {
      i++;
      result += (**pstr - '0') / divisor;
      divisor *= 10.0;
      (*pstr)++;
    }
  }

  if (**pstr == 'e' || **pstr == 'E') {
    i++;
    (*pstr)++;
    int exp_sign = 1;
    if (**pstr == '-') {
      exp_sign = -1;
      (*pstr)++;
    } else if (**pstr == '+') {
      (*pstr)++;
    }
    int exponent = 0;
    while (**pstr >= '0' && **pstr <= '9' && i < width) {
      i++;
      exponent = exponent * 10 + (**pstr - '0');
      (*pstr)++;
    }
    result *= pow(10, exp_sign * exponent);
  }

  return result * sign;
}

long double strtold_custom(const char **pstr, int width) {
  long double result = 0.0;
  long double divisor = 10.0;
  int sign = 1;

  if (**pstr == '-') {
    sign = -1;
    (*pstr)++;
  }

  int i = 0;
  while (**pstr >= '0' && **pstr <= '9' && i < width) {
    i++;
    result = result * 10.0 + (**pstr - '0');
    (*pstr)++;
  }

  if (**pstr == '.') {
    (*pstr)++;
    int i = 0;
    while (**pstr >= '0' && **pstr <= '9' && i < width) {
      i++;
      result += (**pstr - '0') / divisor;
      divisor *= 10.0;
      (*pstr)++;
    }
  }

  if (**pstr == 'e' || **pstr == 'E') {
    (*pstr)++;
    int exp_sign = 1;
    if (**pstr == '-') {
      exp_sign = -1;
      (*pstr)++;
    } else if (**pstr == '+') {
      (*pstr)++;
    }
    int exponent = 0;
    int i = 0;
    while (**pstr >= '0' && **pstr <= '9' && i < width) {
      i++;
      exponent = exponent * 10 + (**pstr - '0');
      (*pstr)++;
    }
    result *= powl(10, exp_sign * exponent);
  }

  return result * sign;
}

long strtol_custom(const char **pstr, int base, int width, int i) {
  long result = 0;
  int sign = 1;

  if (**pstr == '-' && i < width) {
    i++;
    sign = -1;
    (*pstr)++;
  }
  while (((**pstr >= '0' && **pstr <= '9') ||
          (**pstr >= 'a' && **pstr <= 'f') ||
          (**pstr >= 'A' && **pstr <= 'F')) &&
         i < width) {
    if (**pstr >= '0' && **pstr <= '9') {
      result = result * base + (**pstr - '0');
      (*pstr)++;
    } else if (**pstr >= 'a' && **pstr <= 'f') {
      result = result * base + (**pstr - 'a' + 10);
      (*pstr)++;
    } else if (**pstr >= 'A' && **pstr <= 'F') {
      result = result * base + (**pstr - 'A' + 10);
      (*pstr)++;
    }
    i++;
  }

  return result * sign;
}
