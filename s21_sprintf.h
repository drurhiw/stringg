#ifndef S21_SPRINTF
#define S21_SPRINTF

#include <ctype.h>
#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdlib.h>

#include "s21_string.h"

typedef unsigned long s21_size_t;

typedef struct {
  int left_align;
  int show_sign;
  int space;
  int width;
  int precision;
  int lenght_h;
  int lenght_l;
  int lenght_L;
  int space_num;
  int leading_zero;
  int written;
  int lattice;
  int flag_zero;

} FormatSpec;

void init_format_spec(FormatSpec *spec);
void parse_flags(const char **format, FormatSpec *spec);
void parse_width(const char **format, FormatSpec *spec, va_list args);
void parse_precision(const char **format, FormatSpec *spec, va_list args);
void parse_lenght(const char **format, FormatSpec *spec);
void uint_to_str(unsigned int value, char *buffer);
char determine_format(double value, int precision);
void check_minus_flag(char *str, FormatSpec *spec);
void double_to_str(double value, char *buffer, int precision);
int float_to_string(char *buffer, long double value, FormatSpec *spec);

void specifier_c(va_list args, char *str, int *written, FormatSpec *spec);
void specifier_d(va_list args, char *str, int *written, FormatSpec *spec);
void specifier_u(va_list args, char *str, int *written, FormatSpec *spec);
void specifier_percent(char *str, int *written, FormatSpec *spec);
void specifier_f(va_list args, char *str, int *written, FormatSpec *spec);
void specifier_s(va_list args, char *str, int *written, FormatSpec *spec);
void specifier_o(va_list args, char *str, int *written, FormatSpec *spec);
void specifier_x(va_list args, char *str, int *written, FormatSpec *spec,
                 int uppercase);
void specifier_x_lower(va_list args, char *str, int *written, FormatSpec *spec);
void specifier_x_lower(va_list args, char *str, int *written, FormatSpec *spec);
void specifier_p(va_list args, char *str, int *written, FormatSpec *spec);
void specifier_e(va_list args, char *str, int *written, FormatSpec *spec,
                 int uppercase);
void specifier_e_upper(va_list args, char *str, int *written, FormatSpec *spec);
void specifier_e_lower(va_list args, char *str, int *written, FormatSpec *spec);

#endif
