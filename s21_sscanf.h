#ifndef S21_SSCANF_H
#define S21_SSCANF_H

#include <ctype.h>
#include <math.h>
#include <stdarg.h>
#include <stdlib.h>
#include <wchar.h>

#include "string.h"

void sscanf_specifier_d(va_list args, const char **pstr, int is_long,
                        int is_short, int width, int suppress);
void sscanf_specifier_s(va_list args, const char **pstr, int is_long,
                        int width);
void sscanf_specifier_p(va_list args, const char **pstr, int width,
                        int suppress);
void sscanf_specifier_u(va_list args, const char **pstr, int is_long,
                        int is_short, int width);
void sscanf_specifier_n(va_list args, const char *start, const char *current);
void sscanf_specifier_o(va_list args, const char **pstr, int is_long,
                        int is_short, int width, int suppress);
void sscanf_specifier_e(va_list args, const char **pstr, int is_long_double,
                        int width);
void sscanf_specifier_xX(va_list args, const char **pstr, int is_long,
                         int is_short, int width);
void sscanf_specifier_i(va_list args, const char **pstr, int is_long,
                        int is_short, int width, int suppress);
void sscanf_specifier_c(va_list args, const char **pstr, int is_long,
                        int suppress);

double strtod_custom(const char **pstr, int width);
long double strtold_custom(const char **pstr, int width);
long strtol_custom(const char **pstr, int base, int width, int i);
void specifier_width(const char **pfmt, int width);
int skip_entry(const char **pfmt, int suppress);

#endif  // S21_SSCANF_H
