#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_sprintf.h"
#include "../s21_sscanf.h"
#include "../s21_string.h"

/////////////////////////  s21_sprintf///////////////////
// c//
START_TEST(test_s21_sprintf_c) {
  char str1[20] = {0};
  char str2[20] = {0};
  char x = 'c';

  sprintf(str1, "%c", x);

  s21_sprintf(str2, "%c", x);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_c_left_align) {
  char str1[20] = {0};
  char str2[20] = {0};
  char x = 'c';

  sprintf(str1, "%-5c", x);

  s21_sprintf(str2, "%-5c", x);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_c_width) {
  char str1[20] = {0};
  char str2[20] = {0};
  char x = 'c';

  sprintf(str1, "%5c", x);

  s21_sprintf(str2, "%5c", x);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_c_width_2) {
  char str1[20] = {0};
  char str2[20] = {0};
  char x = 'c';

  sprintf(str1, "%*c", 5, x);

  s21_sprintf(str2, "%*c", 5, x);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_c_length_l) {
  char str1[20] = {0};
  char str2[20] = {0};
  char x = 'c';

  sprintf(str1, "%lc", x);

  s21_sprintf(str2, "%lc", x);
  ck_assert_str_eq(str1, str2);
}
END_TEST

// d
START_TEST(test_s21_sprintf_d) {
  char str1[20] = {0};
  char str2[20] = {0};
  int value = 123;

  sprintf(str1, "%d", value);

  s21_sprintf(str2, "%d", value);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_d_left_align) {
  char str1[20] = {0};
  char str2[20] = {0};
  int value = 123;

  sprintf(str1, "%-5d", value);

  s21_sprintf(str2, "%-5d", value);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_d_plus) {
  char str1[20] = {0};
  char str2[20] = {0};
  int value = 123;

  sprintf(str1, "%+d", value);

  s21_sprintf(str2, "%+d", value);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_d_space) {
  char str1[20] = {0};
  char str2[20] = {0};
  int value = 123;

  sprintf(str1, "% d", value);

  s21_sprintf(str2, "% d", value);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_d_width) {
  char str1[20] = {0};
  char str2[20] = {0};
  int value = 123;

  sprintf(str1, "%5d", value);

  s21_sprintf(str2, "%5d", value);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_d_width_2) {
  char str1[20] = {0};
  char str2[20] = {0};
  int value = 123;

  sprintf(str1, "%*d", 5, value);

  s21_sprintf(str2, "%*d", 5, value);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_d_precision) {
  char str1[20] = {0};
  char str2[20] = {0};
  int value = 123;

  sprintf(str1, "%.5d", value);

  s21_sprintf(str2, "%.5d", value);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_d_precision_2) {
  char str1[20] = {0};
  char str2[20] = {0};
  int value = 123;

  sprintf(str1, "%.*d", 5, value);

  s21_sprintf(str2, "%.*d", 5, value);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_d_lenght_h) {
  char str1[20] = {0};
  char str2[20] = {0};
  int value = 123;

  sprintf(str1, "%hd", value);

  s21_sprintf(str2, "%hd", value);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_d_lenght_l) {
  char str1[20] = {0};
  char str2[20] = {0};
  long int value = 123;

  sprintf(str1, "%ld", value);

  s21_sprintf(str2, "%ld", value);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_d_flag_zero) {
  char str1[20] = {0};
  char str2[20] = {0};
  int value = 123;

  sprintf(str1, "%010d", value);

  s21_sprintf(str2, "%010d", value);
  ck_assert_str_eq(str1, str2);
}
END_TEST

// u
START_TEST(test_s21_sprintf_u) {
  char buff1[20];
  char buff2[20];

  sprintf(buff1, "%u", 123);

  s21_sprintf(buff2, "%u", 123);
  ck_assert_str_eq(buff1, buff2);
}
END_TEST

START_TEST(test_s21_sprintf_u_precision) {
  char buff[20];
  char buff2[20];

  sprintf(buff, "%.4u", 123);

  s21_sprintf(buff2, "%.4u", 123);
  ck_assert_str_eq(buff, buff2);
}
END_TEST

START_TEST(test_s21_sprintf_u_precision_2) {
  char buff[20];
  char buff2[20];

  sprintf(buff, "%.*u", 4, 123);

  s21_sprintf(buff2, "%.*u", 4, 123);
  ck_assert_str_eq(buff, buff2);
}
END_TEST

START_TEST(test_s21_sprintf_u_left_align) {
  char buff[20];
  char buff2[20];

  sprintf(buff, "%-5u", 123);

  s21_sprintf(buff2, "%-5u", 123);
  ck_assert_str_eq(buff, buff2);
}
END_TEST

START_TEST(test_s21_sprintf_u_width) {
  char buff[20];
  char buff2[20];

  sprintf(buff, "%5u", 123);

  s21_sprintf(buff2, "%5u", 123);
  ck_assert_str_eq(buff, buff2);
}
END_TEST

START_TEST(test_s21_sprintf_u_width_2) {
  char buff[20];
  char buff2[20];

  sprintf(buff, "%*u", 5, 123);

  s21_sprintf(buff2, "%*u", 5, 123);
  ck_assert_str_eq(buff, buff2);
}
END_TEST

START_TEST(test_s21_sprintf_u_lenght_h) {
  char buff[20];
  char buff2[20];

  sprintf(buff, "%hu", 123);

  s21_sprintf(buff2, "%hu", 123);
  ck_assert_str_eq(buff, buff2);
}
END_TEST

START_TEST(test_s21_sprintf_u_lenght_l) {
  char buff[20];
  char buff2[20];
  long unsigned int n = 123;

  sprintf(buff, "%lu", n);

  s21_sprintf(buff2, "%lu", n);
  ck_assert_str_eq(buff, buff2);
}
END_TEST

START_TEST(test_s21_sprintf_u_flag_zero) {
  char buff[20];
  char buff2[20];

  sprintf(buff, "%010u", 123);

  s21_sprintf(buff2, "%010u", 123);
  ck_assert_str_eq(buff, buff2);
}
END_TEST

// percent
START_TEST(test_s21_sprintf_percent) {
  char buff[20];
  char buff2[20];

  sprintf(buff, "%%%%");

  s21_sprintf(buff2, "%%%%");
  ck_assert_str_eq(buff, buff2);
}
END_TEST

// f
START_TEST(test_s21_sprintf_f) {
  char buffer[100];
  char buffer2[100];

  sprintf(buffer, "%f", 3.143748);

  s21_sprintf(buffer2, "%f", 3.143748);
  ck_assert_str_eq(buffer, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_f_left_align) {
  char buffer[100];
  char buffer2[100];

  sprintf(buffer, "%-5f", 3.145);

  s21_sprintf(buffer2, "%-5f", 3.145);
  ck_assert_str_eq(buffer, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_f_plus) {
  char buffer[100];
  char buffer2[100];

  sprintf(buffer, "%+f", 3.145);

  s21_sprintf(buffer2, "%+f", 3.145);
  ck_assert_str_eq(buffer, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_f_plus_2) {
  char buffer[100];
  char buffer2[100];

  sprintf(buffer, "%+f", -3.145);

  s21_sprintf(buffer2, "%+f", -3.145);
  ck_assert_str_eq(buffer, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_f_space) {
  char buffer[100];
  char buffer2[100];

  sprintf(buffer, "% f", 3.145);

  s21_sprintf(buffer2, "% f", 3.145);
  ck_assert_str_eq(buffer, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_f_width) {
  char buffer[100];
  char buffer2[100];

  sprintf(buffer, "%9f", 3.145);

  s21_sprintf(buffer2, "%9f", 3.145);
  ck_assert_str_eq(buffer, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_f_width_2) {
  char buffer[100];
  char buffer2[100];

  sprintf(buffer, "%*f", 9, 3.145);

  s21_sprintf(buffer2, "%*f", 9, 3.145);
  ck_assert_str_eq(buffer, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_f_presicion) {
  char buffer[100];
  char buffer2[100];

  sprintf(buffer, "%.2f", 3.143);

  s21_sprintf(buffer2, "%.2f", 3.143);
  ck_assert_str_eq(buffer, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_f_presicion_2) {
  char buffer[100];
  char buffer2[100];

  sprintf(buffer, "%.*f", 2, 3.143);

  s21_sprintf(buffer2, "%.*f", 2, 3.143);
  ck_assert_str_eq(buffer, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_f_lenght_l) {
  char buffer[100];
  char buffer2[100];

  sprintf(buffer, "%lf", 3.143333);

  s21_sprintf(buffer2, "%lf", 3.143333);
  ck_assert_str_eq(buffer, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_f_lenght_L) {
  char buffer[100];
  char buffer2[100];

  sprintf(buffer, "%Lf", 5.45L);

  s21_sprintf(buffer2, "%Lf", 5.45L);
  ck_assert_str_eq(buffer, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_f_flag_zero) {
  char buffer[100];
  char buffer2[100];

  sprintf(buffer, "%010f", 54.5);

  s21_sprintf(buffer2, "%010f", 54.5);
  ck_assert_str_eq(buffer, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_f_lattice) {
  char buffer[100];
  char buffer2[100];

  sprintf(buffer, "%#f", 54.5);

  s21_sprintf(buffer2, "%#f", 54.5);
  ck_assert_str_eq(buffer, buffer2);
}
END_TEST

// s
START_TEST(test_s21_sprintf_s) {
  char buffer[100];
  char buffer2[100];

  sprintf(buffer, "%s", "hiii");

  s21_sprintf(buffer2, "%s", "hiii");
  ck_assert_str_eq(buffer, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_s_left_align) {
  char buffer[100];
  char buffer2[100];

  sprintf(buffer, "%-6s", "hiii");

  s21_sprintf(buffer2, "%-6s", "hiii");
  ck_assert_str_eq(buffer, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_s_width) {
  char buffer[100];
  char buffer2[100];

  sprintf(buffer, "%6s", "hiii");

  s21_sprintf(buffer2, "%6s", "hiii");
  ck_assert_str_eq(buffer, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_s_width_2) {
  char buffer[100];
  char buffer2[100];

  sprintf(buffer, "%*s", 6, "hiii");

  s21_sprintf(buffer2, "%*s", 6, "hiii");
  ck_assert_str_eq(buffer, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_s_presicion) {
  char buffer[100];
  char buffer2[100];

  sprintf(buffer, "%.9s", "hiii");

  s21_sprintf(buffer2, "%.9s", "hiii");
  ck_assert_str_eq(buffer, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_s_presicion_2) {
  char buffer[100];
  char buffer2[100];

  sprintf(buffer, "%.*s", 9, "hiii");

  s21_sprintf(buffer2, "%.*s", 9, "hiii");
  ck_assert_str_eq(buffer, buffer2);
}
END_TEST

// o
START_TEST(test_s21_sprintf_o) {
  char buffer[100];
  char buffer2[100];

  sprintf(buffer, "%o", 87);

  s21_sprintf(buffer2, "%o", 87);
  ck_assert_str_eq(buffer, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_o_left_align) {
  char buffer[100];
  char buffer2[100];

  sprintf(buffer, "%-6o", 87);

  s21_sprintf(buffer2, "%-6o", 87);
  ck_assert_str_eq(buffer, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_o_width) {
  char buffer[100];
  char buffer2[100];

  sprintf(buffer, "%6o", 8799);

  s21_sprintf(buffer2, "%6o", 8799);
  ck_assert_str_eq(buffer, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_o_width_2) {
  char buffer[100];
  char buffer2[100];

  sprintf(buffer, "%*o", 6, 87);

  s21_sprintf(buffer2, "%*o", 6, 87);
  ck_assert_str_eq(buffer, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_o_lattice) {
  char buffer[100];
  char buffer2[100];

  sprintf(buffer, "%#o", 87);

  s21_sprintf(buffer2, "%#o", 87);
  ck_assert_str_eq(buffer, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_o_flag_zero) {
  char buffer[100];
  char buffer2[100];

  sprintf(buffer, "%06o", 87);

  s21_sprintf(buffer2, "%06o", 87);
  ck_assert_str_eq(buffer, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_o_presicion) {
  char buffer[100];
  char buffer2[100];

  sprintf(buffer, "%.6o", 87);

  s21_sprintf(buffer2, "%.6o", 87);
  ck_assert_str_eq(buffer, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_o_presicion_2) {
  char buffer[100];
  char buffer2[100];

  sprintf(buffer, "%.*o", 6, 87);

  s21_sprintf(buffer2, "%.*o", 6, 87);
  ck_assert_str_eq(buffer, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_o_lenght_l) {
  char buffer[100];
  char buffer2[100];
  unsigned long int number = 87;

  sprintf(buffer, "%lo", number);

  s21_sprintf(buffer2, "%lo", number);
  ck_assert_str_eq(buffer, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_o_lenght_h) {
  char buffer[100];
  char buffer2[100];
  unsigned short int number = 87;

  sprintf(buffer, "%ho", number);

  s21_sprintf(buffer2, "%ho", number);
  ck_assert_str_eq(buffer, buffer2);
}
END_TEST

// x
START_TEST(test_s21_sprintf_x) {
  char buffer[100];
  char buffer2[100];

  sprintf(buffer, "%x", 87553455);

  s21_sprintf(buffer2, "%x", 87553455);
  ck_assert_str_eq(buffer, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_X) {
  char buffer[100];
  char buffer2[100];

  sprintf(buffer, "%X", 87553455);

  s21_sprintf(buffer2, "%X", 87553455);
  ck_assert_str_eq(buffer, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_X_left_align) {
  char buffer[100];
  char buffer2[100];

  sprintf(buffer, "%-8X", 87553455);

  s21_sprintf(buffer2, "%-8X", 87553455);
  ck_assert_str_eq(buffer, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_X_width) {
  char buffer[100];
  char buffer2[100];

  sprintf(buffer, "%8X", 87553455);

  s21_sprintf(buffer2, "%8X", 87553455);
  ck_assert_str_eq(buffer, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_X_width_2) {
  char buffer[100];
  char buffer2[100];

  sprintf(buffer, "%*X", 8, 87553455);

  s21_sprintf(buffer2, "%*X", 8, 87553455);
  ck_assert_str_eq(buffer, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_X_flag_zero) {
  char buffer[100];
  char buffer2[100];

  sprintf(buffer, "%08X", 87553455);

  s21_sprintf(buffer2, "%08X", 87553455);
  ck_assert_str_eq(buffer, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_X_lattice) {
  char buffer[100];
  char buffer2[100];

  sprintf(buffer, "%#X", 87553455);

  s21_sprintf(buffer2, "%#X", 87553455);
  ck_assert_str_eq(buffer, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_x_lattice) {
  char buffer[100];
  char buffer2[100];

  sprintf(buffer, "%#x", 87553455);

  s21_sprintf(buffer2, "%#x", 87553455);
  ck_assert_str_eq(buffer, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_x_presicion) {
  char buffer[100];
  char buffer2[100];

  sprintf(buffer, "%.8x", 87553455);

  s21_sprintf(buffer2, "%.8x", 87553455);
  ck_assert_str_eq(buffer, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_x_presicion_2) {
  char buffer[100];
  char buffer2[100];

  sprintf(buffer, "%.*x", 8, 87553455);

  s21_sprintf(buffer2, "%.*x", 8, 87553455);
  ck_assert_str_eq(buffer, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_x_lenght_l) {
  char buffer[100];
  char buffer2[100];
  unsigned long int number = 123456789;

  sprintf(buffer, "%lx", number);

  s21_sprintf(buffer2, "%lx", number);
  ck_assert_str_eq(buffer, buffer2);
}
END_TEST

// p
START_TEST(test_s21_sprintf_p) {
  char buffer[100];
  char expected[100];
  void *ptr = (void *)0x12345678;
  s21_sprintf(buffer, "%p", ptr);
  sprintf(expected, "%p", ptr);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_s21_sprintf_p_left_align) {
  char buffer[100];
  char expected[100];
  void *ptr = (void *)0x12345678;
  s21_sprintf(buffer, "%-10p", ptr);
  sprintf(expected, "%-10p", ptr);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_s21_sprintf_p_width) {
  char buffer[100];
  char expected[100];
  void *ptr = (void *)0x12345678;
  s21_sprintf(buffer, "%10p", ptr);
  sprintf(expected, "%10p", ptr);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_s21_sprintf_p_width_2) {
  char buffer[100];
  char expected[100];
  void *ptr = (void *)0x12345678;
  s21_sprintf(buffer, "%*p", 10, ptr);
  sprintf(expected, "%*p", 10, ptr);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

// trim
START_TEST(test_trim_spaces) {
  const char *src = "   Hello, World!   ";
  const char *trim_chars = " ";
  char *result = s21_trim(src, trim_chars);

  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, "Hello, World!");

  free(result);
}
END_TEST

// Тест на обрезку символов с обеих сторон строки
START_TEST(test_trim_specific_chars) {
  const char *src = "---Hello, World!---";
  const char *trim_chars = "-";
  char *result = s21_trim(src, trim_chars);

  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, "Hello, World!");

  free(result);
}
END_TEST

// Тест на обрезку строки, содержащей только символы для обрезки
START_TEST(test_trim_only_trim_chars) {
  const char *src = "######";
  const char *trim_chars = "#";
  char *result = s21_trim(src, trim_chars);

  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, "");

  free(result);
}
END_TEST

// Тест на строку без символов для обрезки
START_TEST(test_trim_no_trim_chars) {
  const char *src = "Hello, World!";
  const char *trim_chars = "-";
  char *result = s21_trim(src, trim_chars);

  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, "Hello, World!");

  free(result);
}
END_TEST

// Тест на пустую строку
START_TEST(test_trim_empty_string) {
  const char *src = "";
  const char *trim_chars = " ";
  char *result = s21_trim(src, trim_chars);

  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, "");

  free(result);
}
END_TEST

// Тест на NULL указатели
START_TEST(test_trim_null_pointers) {
  char *result = s21_trim(S21_NULL, " ");
  ck_assert_ptr_null(result);

  result = s21_trim("Hello, World!", S21_NULL);
  ck_assert_ptr_null(result);
}
END_TEST

// insert
START_TEST(test_s21_insert) {
  const char *src = "Hello, World!";
  const char *str = "Beautiful ";
  s21_size_t start_index = 7;
  char *result = (char *)s21_insert(src, str, start_index);
  ck_assert_str_eq(result, "Hello, Beautiful World!");

  free(result);
}
END_TEST

START_TEST(test_s21_insert_null) {
  char *result = (char *)s21_insert(S21_NULL, "test", 0);
  ck_assert_ptr_null(result);

  result = (char *)s21_insert("test", S21_NULL, 0);
  ck_assert_ptr_null(result);
}
END_TEST

START_TEST(test_s21_insert_index) {
  const char *src = "Hello, World!";
  const char *str = "Beautiful ";
  s21_size_t start_index = 70;
  char *result = (char *)s21_insert(src, str, start_index);
  ck_assert_ptr_null(result);
}
END_TEST

// to_lower
START_TEST(test_s21_to_lower) {
  const char str[] = "HELLO";
  char *result = s21_to_lower(str);
  ck_assert_str_eq(result, "hello");
  free(result);
}
END_TEST

START_TEST(test_s21_to_lower_2) {
  const char str[] = "Hello, World";
  char *result = s21_to_lower(str);
  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, "hello, world");
  free(result);
}
END_TEST

START_TEST(test_s21_to_lower_3) {
  const char str[] = "hello, world";
  char *result = s21_to_lower(str);
  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, "hello, world");
  free(result);
}
END_TEST

START_TEST(test_s21_to_lower_4) {
  const char str[] = "";
  char *result = s21_to_lower(str);
  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, "");
  free(result);
}
END_TEST

START_TEST(test_s21_to_lower_null) {
  char *result = s21_to_lower(S21_NULL);
  ck_assert_ptr_null(result);
}
END_TEST

// to_upper
START_TEST(test_s21_to_upper) {
  const char str[] = "hello";
  char *result = s21_to_upper(str);
  ck_assert_str_eq(result, "HELLO");
  free(result);
}
END_TEST

START_TEST(test_s21_to_upper_2) {
  const char str[] = "HELLO";
  char *result = s21_to_upper(str);
  ck_assert_str_eq(result, "HELLO");
  free(result);
}
END_TEST

START_TEST(test_s21_to_upper_3) {
  const char str[] = "";
  char *result = s21_to_upper(str);
  ck_assert_str_eq(result, "");
  free(result);
}
END_TEST

START_TEST(test_s21_to_upper_null) {
  char *result = s21_to_upper(S21_NULL);
  ck_assert_ptr_null(result);
}
END_TEST

////////////////////////////sscanf/////////////////
START_TEST(test_specifier_d) {
  const char *str = "1234";
  int num = 0;
  int num2 = 0;

  // Проверка успешного преобразования положительного числа
  int ret = s21_sscanf(str, "%d", &num);
  sscanf(str, "%d", &num2);
  ck_assert_int_eq(ret, 1);
  ck_assert_int_eq(num, num2);

  // Проверка успешного преобразования отрицательного числа
  str = "-5678";
  ret = s21_sscanf(str, "%d", &num);
  sscanf(str, "%d", &num2);
  ck_assert_int_eq(ret, 1);
  ck_assert_int_eq(num, num2);

  // Проверка успешного преобразования числа с модификатором h
  short int short_num = 0;
  short int short_num2 = 0;
  str = "2345";
  ret = s21_sscanf(str, "%hd", &short_num);
  sscanf(str, "%hd", &short_num2);
  ck_assert_int_eq(ret, 1);
  ck_assert_int_eq(short_num, short_num2);

  // Проверка успешного преобразования числа с модификатором l
  long int long_num = 0;
  long int long_num2 = 0;
  str = "67891234";
  ret = s21_sscanf(str, "%ld", &long_num);
  sscanf(str, "%ld", &long_num2);
  ck_assert_int_eq(ret, 1);
  ck_assert_int_eq(long_num, long_num2);
}
END_TEST

START_TEST(test_sscanf_width_d) {
  const char *str = "12345";
  int num1 = 0;
  int num2 = 0;

  // Выполняем sscanf с шириной для первого числа
  s21_sscanf(str, "%3d", &num1);
  sscanf(str, "%3d", &num2);

  // Проверяем, что num1 считывается правильно
  ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(test_specifier_s) {
  char str[20];
  char str2[20];
  char input[] = "Hello";
  int count = s21_sscanf(input, "%s", str);
  sscanf(input, "%s", str2);
  ck_assert_int_eq(count, 1);
  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(test_sscanf_width_s) {
  char s1[1024], s2[1024], s3[1024];
  char res_s1[1024], res_s2[1024], res_s3[1024];

  sscanf("a12basd2-c", "%3s%2s%1s", s1, s2, s3);
  s21_sscanf("a12basd2-c", "%3s%2s%1s", res_s1, res_s2, res_s3);
  ck_assert_str_eq(s1, res_s1);
  ck_assert_str_eq(s2, res_s2);
  ck_assert_str_eq(s3, res_s3);
}
END_TEST

START_TEST(test_specifier_p) {
  void *ptr;
  void *ptr2;
  char input[] = "0x7ffee5bff618";
  int count = s21_sscanf(input, "%p", &ptr);
  sscanf(input, "%p", &ptr2);
  ck_assert_int_eq(count, 1);
  ck_assert_ptr_eq(ptr, ptr2);
}
END_TEST

START_TEST(test_specifier_n) {
  int num;
  int num2;
  char input[] = "Hello, world!";
  s21_sscanf(input, "Hello, %n", &num);
  sscanf(input, "Hello, %n", &num2);
  ck_assert_int_eq(num, num2);
}
END_TEST

START_TEST(test_specifier_u) {
  const char *str = "12345";
  unsigned int num = 0;
  unsigned int num2 = 0;

  int ret = s21_sscanf(str, "%u", &num);
  sscanf(str, "%u", &num2);
  ck_assert_int_eq(ret, 1);
  ck_assert_uint_eq(num, num2);

  unsigned short int short_num = 0;
  unsigned short int short_num2 = 0;
  str = "23456";
  ret = s21_sscanf(str, "%hu", &short_num);
  sscanf(str, "%hu", &short_num2);
  ck_assert_int_eq(ret, 1);
  ck_assert_uint_eq(short_num, short_num2);

  unsigned long int long_num = 0;
  unsigned long int long_num2 = 0;
  str = "67891234";
  ret = s21_sscanf(str, "%lu", &long_num);
  sscanf(str, "%lu", &long_num2);
  ck_assert_int_eq(ret, 1);
  ck_assert_uint_eq(long_num, long_num2);
}
END_TEST

START_TEST(test_sscanf_width_u) {
  const char *str = "12345";
  int num1 = 0;
  int num2 = 0;

  // Выполняем sscanf с шириной для первого числа
  s21_sscanf(str, "%3u", &num1);
  sscanf(str, "%3u", &num2);

  // Проверяем, что num1 считывается правильно
  ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(test_specifier_o) {
  const char *str = "12345";
  unsigned int num = 0;
  unsigned int num2 = 0;

  int ret = s21_sscanf(str, "%o", &num);
  sscanf(str, "%o", &num2);
  ck_assert_int_eq(ret, 1);
  ck_assert_uint_eq(num, num2);

  unsigned short int short_num = 0;
  unsigned short int short_num2 = 0;
  str = "23456";
  ret = s21_sscanf(str, "%ho", &short_num);
  sscanf(str, "%ho", &short_num2);
  ck_assert_int_eq(ret, 1);
  ck_assert_uint_eq(short_num, short_num2);

  unsigned long int long_num = 0;
  unsigned long int long_num2 = 0;
  str = "76543";
  ret = s21_sscanf(str, "%lo", &long_num);
  sscanf(str, "%lo", &long_num2);
  ck_assert_int_eq(ret, 1);
  ck_assert_uint_eq(long_num, long_num2);
}
END_TEST

START_TEST(test_sscanf_width_o) {
  const char *str = "12345";
  int num1 = 0;
  int num2 = 0;

  // Выполняем sscanf с шириной для первого числа
  s21_sscanf(str, "%3o", &num1);
  sscanf(str, "%3o", &num2);

  // Проверяем, что num1 считывается правильно
  ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(test_specifier_x) {
  const char *str = "1a2b3c4d";
  unsigned int num = 0;
  unsigned int num2 = 0;

  int ret = s21_sscanf(str, "%x", &num);
  sscanf(str, "%x", &num2);
  ck_assert_int_eq(ret, 1);
  ck_assert_uint_eq(num, num2);

  unsigned short int short_num = 0;
  unsigned short int short_num2 = 0;
  str = "1a2b";
  ret = s21_sscanf(str, "%hx", &short_num);
  sscanf(str, "%hx", &short_num2);
  ck_assert_int_eq(ret, 1);
  ck_assert_uint_eq(short_num, short_num2);

  unsigned long int long_num = 0;
  unsigned long int long_num2 = 0;
  str = "1a2b3c4d";
  ret = s21_sscanf(str, "%lx", &long_num);
  sscanf(str, "%lx", &long_num2);
  ck_assert_int_eq(ret, 1);
  ck_assert_uint_eq(long_num, long_num2);
}
END_TEST

START_TEST(test_sscanf_width_x) {
  const char *str = "1a2b3c";
  unsigned int num1 = 0;
  unsigned int num2 = 0;

  // Выполняем sscanf с шириной для первого числа
  s21_sscanf(str, "%3x", &num1);
  sscanf(str, "%3x", &num2);

  // Проверяем, что num1 считывается правильно
  ck_assert_uint_eq(
      num1, num2);  // 0x1a2 в шестнадцатеричной системе равно 418 в десятичной
}
END_TEST

START_TEST(test_specifier_X) {
  unsigned int num;
  unsigned int num2;
  char input[] = "A1F";
  int cont = s21_sscanf(input, "%X", &num);
  sscanf(input, "%X", &num2);
  ck_assert_int_eq(cont, 1);
  ck_assert_uint_eq(num, num2);
}
END_TEST

START_TEST(test_specifier_i_1) {
  const char *str = "1234";
  int num = 0;
  int num2 = 0;

  int ret = s21_sscanf(str, "%i", &num);
  sscanf(str, "%i", &num2);
  ck_assert_int_eq(ret, 1);
  ck_assert_int_eq(num, num2);

  str = "01234";
  ret = s21_sscanf(str, "%i", &num);
  sscanf(str, "%i", &num2);
  ck_assert_int_eq(ret, 1);
  ck_assert_int_eq(num, num2);

  str = "0x1a2b";
  ret = s21_sscanf(str, "%i", &num);
  sscanf(str, "%i", &num2);
  ck_assert_int_eq(ret, 1);
  ck_assert_int_eq(num, num2);
}
END_TEST

START_TEST(test_specifier_i_2) {
  int num;
  int num2;
  char input[] = "0x1A3";
  int count = s21_sscanf(input, "%i", &num);
  sscanf(input, "%i", &num2);
  ck_assert_int_eq(count, 1);
  ck_assert_int_eq(num, num2);
}
END_TEST

START_TEST(test_specifier_i_3) {
  int num;
  int num2;
  char input[] = "075";
  int count = s21_sscanf(input, "%i", &num);
  sscanf(input, "%i", &num2);
  ck_assert_int_eq(count, 1);
  ck_assert_int_eq(num, num2);
}
END_TEST

START_TEST(test_sscanf_specifier_hi) {
  const char *str;
  short num;
  short num2;
  int ret;

  // Тест для короткого десятичного числа
  str = "1234";
  num = 0;
  num2 = 0;
  ret = s21_sscanf(str, "%hi", &num);
  sscanf(str, "%hi", &num2);
  ck_assert_int_eq(ret, 1);
  ck_assert_int_eq(num, num2);

  // Тест для короткого восьмеричного числа
  str = "01234";
  num = 0;
  num2 = 0;
  ret = s21_sscanf(str, "%hi", &num);
  sscanf(str, "%hi", &num2);
  ck_assert_int_eq(ret, 1);
  ck_assert_int_eq(num, num2);  // восьмеричное 1234 это десятичное 668

  // Тест для короткого шестнадцатеричного числа
  str = "0x1a2b";
  num = 0;
  num2 = 0;
  ret = s21_sscanf(str, "%hi", &num);
  sscanf(str, "%hi", &num2);
  ck_assert_int_eq(ret, 1);
  ck_assert_int_eq(num, num2);  // шестнадцатеричное 1a2b это десятичное 6699
}
END_TEST

START_TEST(test_sscanf_specifier_li) {
  const char *str;
  long num;
  long num2;
  int ret;

  // Тест для длинного десятичного числа
  str = "1234";
  num = 0;
  num2 = 0;
  ret = s21_sscanf(str, "%li", &num);
  sscanf(str, "%li", &num2);
  ck_assert_int_eq(ret, 1);
  ck_assert_int_eq(num, num2);

  // Тест для длинного восьмеричного числа
  str = "01234";
  num = 0;
  num2 = 0;
  ret = s21_sscanf(str, "%li", &num);
  sscanf(str, "%li", &num2);
  ck_assert_int_eq(ret, 1);
  ck_assert_int_eq(num, num2);  // восьмеричное 1234 это десятичное 668

  // Тест для длинного шестнадцатеричного числа
  str = "0x1a2b";
  num = 0;
  num2 = 0;
  ret = s21_sscanf(str, "%li", &num);
  sscanf(str, "%li", &num2);
  ck_assert_int_eq(ret, 1);
  ck_assert_int_eq(num, num2);  // шестнадцатеричное 1a2b это десятичное 6699
}
END_TEST

START_TEST(test_sscanf_specifier_c) {
  wchar_t ch1, ch2, ch12, ch22;
  const char *str = "abc def";
  int result = s21_sscanf(str, "%lc", &ch1);
  sscanf(str, "%lc", &ch12);
  ck_assert_int_eq(result, 1);
  ck_assert_int_eq(ch1, ch12);

  result = s21_sscanf(str + 4, "%lc", &ch2);
  sscanf(str + 4, "%lc", &ch22);
  ck_assert_int_eq(result, 1);
  ck_assert_int_eq(ch2, ch22);
}
END_TEST

START_TEST(test_sscanf_specifier_Le) {
  const char *input = "1.23e4";
  long double value;
  long double value2;
  int result = s21_sscanf(input, "%Le", &value);
  sscanf(input, "%Le", &value2);

  ck_assert_int_eq(result, 1);  // Проверка, что один аргумент успешно считан
  ck_assert_int_eq(
      value, value2);  // Проверка значения с учетом допустимой погрешности
}
END_TEST

START_TEST(test_sscanf_specifier_e) {
  const char *input = "1.23e4";
  double value;
  double value2;
  int result = s21_sscanf(input, "%le", &value);
  sscanf(input, "%le", &value2);

  ck_assert_int_eq(result, 1);  // Проверка, что один аргумент успешно считан
  ck_assert_int_eq(
      value, value2);  // Проверка значения с учетом допустимой погрешности
}
END_TEST
// sprintf e

START_TEST(test_s21_sprintf_e_default) {
  char buffer[100];
  char expected[100];
  double value = 1234.56789;
  s21_sprintf(buffer, "%e", value);
  sprintf(expected, "%e", value);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_s21_sprintf_e_precision) {
  char buffer[100];
  char expected[100];
  double value = 1234.56789;
  s21_sprintf(buffer, "%.6e", value);
  sprintf(expected, "%.6e", value);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_s21_sprintf_e_precision_2) {
  char buffer[100];
  char expected[100];
  double value = 1234.56789;
  s21_sprintf(buffer, "%.*e", 6, value);
  sprintf(expected, "%.*e", 6, value);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_s21_sprintf_e_width) {
  char buffer[100];
  char expected[100];
  double value = 1234.56789;
  s21_sprintf(buffer, "%15e", value);
  sprintf(expected, "%15e", value);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_s21_sprintf_e_width_2) {
  char buffer[100];
  char expected[100];
  double value = 1234.56789;
  s21_sprintf(buffer, "%*e", 15, value);
  sprintf(expected, "%*e", 15, value);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_s21_sprintf_e_width_and_precision) {
  char buffer[100];
  char expected[100];
  double value = 1234.56789;
  s21_sprintf(buffer, "%15.6e", value);
  sprintf(expected, "%15.6e", value);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_s21_sprintf_e_zero) {
  char buffer[100];
  char expected[100];
  double value = 0.0;
  s21_sprintf(buffer, "%e", value);
  sprintf(expected, "%e", value);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_s21_sprintf_e_negative) {
  char buffer[100];
  char expected[100];
  double value = -1234.56789;
  s21_sprintf(buffer, "%e", value);
  sprintf(expected, "%e", value);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_s21_sprintf_e_large_number) {
  char buffer[100];
  char expected[100];
  double value = 1.23456789e+300;
  s21_sprintf(buffer, "%e", value);
  sprintf(expected, "%e", value);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_s21_sprintf_e_small_number) {
  char buffer[100];
  char expected[100];
  double value = 1.23456789e-300;
  s21_sprintf(buffer, "%e", value);
  sprintf(expected, "%e", value);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_s21_sprintf_E_default) {
  char buffer[100];
  char expected[100];
  double value = 1234.56789;
  s21_sprintf(buffer, "%E", value);
  sprintf(expected, "%E", value);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_s21_sprintf_E_precision) {
  char buffer[100];
  char expected[100];
  double value = 1234.56789;
  s21_sprintf(buffer, "%.6E", value);
  sprintf(expected, "%.6E", value);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_s21_sprintf_E_precision_2) {
  char buffer[100];
  char expected[100];
  double value = 1234.56789;
  s21_sprintf(buffer, "%.*E", 6, value);
  sprintf(expected, "%.*E", 6, value);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_s21_sprintf_E_width) {
  char buffer[100];
  char expected[100];
  double value = 1234.56789;
  s21_sprintf(buffer, "%20E", value);
  sprintf(expected, "%20E", value);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_s21_sprintf_E_width_2) {
  char buffer[100];
  char expected[100];
  double value = 1234.56789;
  s21_sprintf(buffer, "%*E", 20, value);
  sprintf(expected, "%*E", 20, value);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_s21_sprintf_E_width_and_precision) {
  char buffer[100];
  char expected[100];
  double value = 1234.56789;
  s21_sprintf(buffer, "%20.6E", value);
  sprintf(expected, "%20.6E", value);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

// Тест для успешного считывания числа с плавающей точкой и пропуска оставшихся
// символов
START_TEST(test_sscanf_exponential_with_width_and_remainder) {
  double value;
  double value2;
  char *str = "1.23e4extra";
  char *format = "%8le";
  int result = s21_sscanf(str, format, &value);
  sscanf(str, format, &value2);

  ck_assert_int_eq(result, 1);
  ck_assert_int_eq(value, value2);
}
END_TEST

START_TEST(test_sscanf_width_2) {
  int value;
  int value2;
  s21_sscanf("123", "%2i", &value);
  sscanf("123", "%2i", &value2);
  ck_assert_int_eq(value, value2);
}
END_TEST

START_TEST(test_sscanf_width_3) {
  int value;
  int value2;
  s21_sscanf("-123", "%3i", &value);
  sscanf("-123", "%3i", &value2);
  ck_assert_int_eq(value, value2);
}
END_TEST

START_TEST(test_sscanf_width_1) {
  int value;
  int value2;
  s21_sscanf("5", "%1i", &value);
  sscanf("5", "%1i", &value2);
  ck_assert_int_eq(value, value2);
}
END_TEST

START_TEST(test_sscanf_width_hex_2) {
  int value;
  int value2;
  s21_sscanf("0x10", "%2i", &value);
  sscanf("0x10", "%2i", &value2);
  ck_assert_int_eq(value, value2);
}
END_TEST

START_TEST(test_s21_sscanf_d_0) {
  long x11 = 0, y11 = 0;
  long long x21 = 0, y21 = 0;
  ck_assert_int_eq(
      sscanf("4294967594 7 4294967299", "%ld%*d%lld", &x11, &x21),
      s21_sscanf("4294967594 7 4294967299", "%ld%*d%lld", &y11, &y21));
}
END_TEST

START_TEST(test_s21_sscanf_p_wight) {
  void *p1, *p2;

  ck_assert_int_eq(sscanf("0x7fff5a6e42f8 0x7ffeebfe7758", "%p%*p", &p1),
                   s21_sscanf("0x7fff5a6e42f8 0x7ffeebfe7758", "%p%*p", &p2));
  ck_assert_int_eq((long)p1, (long)p2);
}
END_TEST

START_TEST(test_s21_sscanf_c_wight) {
  char x1, y1;

  ck_assert_int_eq(sscanf("aaaaaa", "%*3c%c", &x1),
                   s21_sscanf("aaaaaa", "%*3c%c", &y1));
  ck_assert_int_eq(x1, y1);

  ck_assert_int_eq(sscanf("a", "%4c", &x1), s21_sscanf("a", "%4c", &y1));
  ck_assert_int_eq(x1, y1);
}
END_TEST

// memchr
START_TEST(test_s21_memchr_1) {
  char str[] = "Hello, World!";
  char *result;
  char *result2;
  char c = 'W';

  result = (char *)s21_memchr(str, c, sizeof(str));
  result2 = (char *)memchr(str, c, sizeof(str));
  ck_assert_ptr_nonnull(result);
  ck_assert_ptr_eq(result, result2);
  ck_assert_int_eq(*result, *result2);
}
END_TEST

START_TEST(test_s21_memchr_2) {
  char *result;
  char c = 'W';
  char empty_str[] = " ";

  result = s21_memchr(empty_str, c, s21_strlen(empty_str));
  ck_assert_ptr_null(result);
}
END_TEST

START_TEST(test_s21_memchr_3) {
  char s = 'Z';
  char str[] = "Hello, World!";

  char *result1 = (char *)s21_memchr(str, s, sizeof(str));
  ck_assert_ptr_null(result1);
}
END_TEST

START_TEST(test_s21_memchr_4) {
  char c = 'W';
  char str2[] = "";

  char *result2 = (char *)s21_memchr(str2, c, sizeof(str2));
  ck_assert_ptr_null(result2);
}
END_TEST

START_TEST(test_s21_memcmp_1) {
  char str[] = "0123456789";
  char str2[] = "0123456789";

  int result = s21_memcmp(str, str2, 10);
  int result2 = memcmp(str, str2, 10);

  ck_assert_int_eq(result, result2);
}
END_TEST

START_TEST(test_s21_memcmp_2) {
  char str5[] = "";
  char str6[] = "";

  int result3 = s21_memcmp(str5, str6, 0);
  int result4 = memcmp(str5, str6, 0);

  ck_assert_int_eq(result3, result4);
}
END_TEST

START_TEST(test_s21_memcmp_3) {
  char str[] = "0123456789";
  char str7[] = "01234";

  int result4 = s21_memcmp(str, str7, 5);
  int result5 = memcmp(str, str7, 5);

  ck_assert_int_eq(result4, result5);
}
END_TEST

START_TEST(test_s21_memcmp_4) {
  char str8[] = "abcdefgh";
  char str9[] = "abcdef";

  int result5 = s21_memcmp(str8, str9, 6);
  int result6 = memcmp(str8, str9, 6);

  ck_assert_int_eq(result5, result6);
}
END_TEST

START_TEST(test_s21_memcpy_1) {
  char str1[] = "123456789";
  char str2[] = "9876";
  char *result = s21_memcpy(str1, str2, 4);
  char *result2 = memcpy(str1, str2, 4);

  ck_assert_str_eq(result, result2);
}
END_TEST

START_TEST(test_s21_memcpy_2) {
  char str1[] = "123456789";
  char str3[10] = "";
  char *result2 = s21_memcpy(str3, str1, 3);
  char *result3 = memcpy(str3, str1, 3);

  ck_assert_str_eq(result2, result3);
}
END_TEST

START_TEST(test_s21_memset_1) {
  char str[20] = "Hello, World!";
  void *result = s21_memset(str, 'X', 5);
  void *result2 = memset(str, 'X', 5);

  ck_assert_str_eq(result, result2);
}
END_TEST

START_TEST(test_s21_memset_2) {
  char str2[20] = "";
  void *result2 = s21_memset(str2, '\0', 0);
  void *result3 = memset(str2, '\0', 0);

  ck_assert_ptr_nonnull(result2);
  ck_assert_str_eq((char *)result2, (char *)result3);
}
END_TEST

START_TEST(test_s21_memset_3) {
  char str[20] = "Hello, World!";
  void *result4 = s21_memset(str, '\0', 3);
  void *result5 = memset(str, '\0', 3);

  ck_assert_str_eq(result4, result5);
}
END_TEST

START_TEST(test_s21_strchr_1) {
  char str[] = "Hello, World!";
  char c = 'o';
  char *result;
  char *result2;

  result = s21_strchr(str, c);
  result2 = strchr(str, c);

  ck_assert_ptr_nonnull(result);
  ck_assert_ptr_eq(result, result2);
  ck_assert_int_eq(*result, *result2);
}
END_TEST

START_TEST(test_s21_strchr_2) {
  char c = 'o';
  char empty_str[] = "";
  char *result;
  result = s21_strchr(empty_str, c);

  ck_assert_ptr_null(result);
}
END_TEST

START_TEST(test_s21_strcspn_1) {
  const char str1[] = "0123456789";
  const char str2[] = "6789";
  s21_size_t result1;
  s21_size_t result2;
  result1 = s21_strcspn(str1, str2);
  result2 = strcspn(str1, str2);

  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_s21_strcspn_2) {
  const char str3[] = "";
  const char str4[] = "";
  s21_size_t result2;
  s21_size_t result3;
  result2 = s21_strcspn(str3, str4);
  result3 = strcspn(str3, str4);

  ck_assert_int_eq(result2, result3);
}
END_TEST

START_TEST(test_s21_strcspn_3) {
  const char str2[] = "6789";
  const char str5[] = "6789";
  s21_size_t result3;
  s21_size_t result4;
  result3 = s21_strcspn(str2, str5);
  result4 = strcspn(str2, str5);

  ck_assert_int_eq(result3, result4);
}
END_TEST

START_TEST(test_s21_strcspn_4) {
  const char str1[] = "0123456789";
  const char str3[] = "";
  s21_size_t result4;
  s21_size_t result5;
  result4 = s21_strcspn(str1, str3);
  result5 = strcspn(str1, str3);

  ck_assert_int_eq(result4, result5);
}
END_TEST

START_TEST(test_s21_strerror) {
  for (int i = -50; i < 150; i++) {
    ck_assert_str_eq(s21_strerror(i), strerror(i));
  }
}
END_TEST

START_TEST(test_s21_strlen_1) {
  const char str1[] = "123456";
  s21_size_t result1;
  s21_size_t result2;
  result1 = s21_strlen(str1);
  result2 = strlen(str1);

  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_s21_strlen_2) {
  const char str2[] = "";
  s21_size_t result2;
  s21_size_t result3;
  result2 = s21_strlen(str2);
  result3 = strlen(str2);

  ck_assert_int_eq(result2, result3);
}
END_TEST

START_TEST(test_s21_strlen_3) {
  const char str3[] = "12345678912345678900";
  s21_size_t result3;
  s21_size_t result4;
  result3 = s21_strlen(str3);
  result4 = strlen(str3);

  ck_assert_int_eq(result3, result4);
}
END_TEST

START_TEST(test_s21_strncat) {
  char case_2[4] = "<<<";
  char case_4[2] = "5";
  char case_44[2] = "5";
  const char case_5[] = "";
  ck_assert_str_eq(s21_strncat(case_2, case_4, 1), "<<<5");
  ck_assert_str_eq(s21_strncat(case_44, case_5, 0), strncat(case_4, case_5, 0));
}
END_TEST

START_TEST(test_s21_strncmp_1) {
  char str1[] = "Hello, World!";
  char str2[] = "Hello, World!";
  ck_assert_int_eq(s21_strncmp(str1, str2, 5), strncmp(str1, str2, 5));
}
END_TEST

START_TEST(test_s21_strncmp_3) {
  char str1[] = "Hello, World!";
  char str4[] = "";
  ck_assert_int_eq(s21_strncmp(str1, str4, 0), strncmp(str1, str4, 0));
}
END_TEST

START_TEST(test_s21_strncpy_1) {
  char dest[20] = "1234567890";
  char str[] = "Hello, World!";
  char *result = s21_strncpy(dest, str, 5);
  char *result2 = strncpy(dest, str, 5);
  ck_assert_str_eq(result, result2);
}
END_TEST

START_TEST(test_s21_strncpy_2) {
  char dest1[20] = "";
  char str[] = "Hello, World!";
  char *result2 = s21_strncpy(dest1, str, 5);
  char *result3 = strncpy(dest1, str, 5);
  ck_assert_str_eq(result2, result3);
}
END_TEST

START_TEST(test_s21_strncpy_3) {
  char dest[20] = "1234567890";
  char str[] = "Hello, World!";
  char *result3 = s21_strncpy(dest, str, 15);
  char *result4 = strncpy(dest, str, 15);
  ck_assert_str_eq(result3, result4);
}
END_TEST

START_TEST(test_s21_strpbrk_1) {
  const char str1[] = "0123456789";
  const char str2[] = "278";
  char *result1;
  char *result2;
  result1 = s21_strpbrk(str1, str2);
  result2 = strpbrk(str1, str2);
  ck_assert_ptr_eq(result1, result2);
}
END_TEST

START_TEST(test_s21_strpbrk_2) {
  char *result2;
  const char str1[] = "0123456789";
  const char str3[] = "qwerty";
  result2 = s21_strpbrk(str1, str3);
  ck_assert_ptr_eq(result2, S21_NULL);
}
END_TEST

START_TEST(test_s21_strpbrk_3) {
  char *result3;
  const char str1[] = "0123456789";
  const char str4[] = "";
  result3 = s21_strpbrk(str1, str4);
  ck_assert_ptr_eq(result3, S21_NULL);
}
END_TEST

START_TEST(test_s21_strrchr_1) {
  char str[] = "Hello, World!";
  char c = 'o';
  char *result;
  result = s21_strrchr(str, c);
  ck_assert_ptr_nonnull(result);
}
END_TEST

START_TEST(test_s21_strrchr_2) {
  char str[] = "Hello, World!";
  char c = 'o';
  char *result;
  char *result2;
  result = s21_strrchr(str, c);
  result2 = strrchr(str, c);
  ck_assert_ptr_eq(result, result2);
}
END_TEST

START_TEST(s21_strtok_test) {
  char str_strtok1[] = "one/two/three(four)five";
  const char delim1[] = "/()";
  char str_strtok2[] = "one/two/three(four)five";
  const char delim2[] = "/()";
  char *my_strtok = s21_strtok(str_strtok1, delim1);
  char *origin_strtok = strtok(str_strtok2, delim2);
  while (my_strtok != S21_NULL) {
    ck_assert_str_eq(my_strtok, origin_strtok);
    my_strtok = s21_strtok(S21_NULL, delim1);
    origin_strtok = strtok(S21_NULL, delim2);
  }

  char str_strtok3[] = "/()";
  const char delim3[] = "/()";
  char str_strtok4[] = "/()";
  const char delim4[] = "/()";
  const char *my_strtok1 = s21_strtok(str_strtok3, delim3);
  const char *origin_strtok1 = strtok(str_strtok4, delim4);
  ck_assert(my_strtok1 == S21_NULL);
  ck_assert(origin_strtok1 == S21_NULL);
}
END_TEST

START_TEST(test_s21_strrchr_3) {
  char c = 'o';
  char str[] = "Hello, World!";
  char *result;
  char *result2;
  result = s21_strrchr(str, c);
  result2 = strrchr(str, c);
  ck_assert_int_eq(*result, *result2);
}
END_TEST

START_TEST(test_s21_strrchr_4) {
  char c = 'o';
  char empty_str[] = "";
  char *result;
  result = s21_strrchr(empty_str, c);

  ck_assert_ptr_null(result);
}
END_TEST

START_TEST(test_s21_strstr_1) {
  const char haystack[] = "0123456789";
  const char needle[] = "345";
  char *result1;
  char *result2;
  result1 = s21_strstr(haystack, needle);
  result2 = strstr(haystack, needle);
  ck_assert_ptr_eq(result1, result2);
}
END_TEST

START_TEST(test_s21_strstr_2) {
  const char haystack[] = "0123456789";
  const char needle2[] = "qwerty";
  char *result2;
  result2 = s21_strstr(haystack, needle2);
  ck_assert_ptr_eq(result2, S21_NULL);
}
END_TEST

START_TEST(test_sscanf_width_star_i) {
  const char *input = "123456";
  int number;
  int number2;

  // Используем sscanf с указанием ширины поля через *
  s21_sscanf(input, "%4i", &number);
  sscanf(input, "%4i", &number2);
  ck_assert_int_eq(number, number2);

  // Проверка с использованием ширины поля через *
  s21_sscanf(input, "%*4i%i", &number);
  sscanf(input, "%*4i%i", &number2);
  ck_assert_int_eq(number, number2);
}
END_TEST

START_TEST(test_sscanf_pointer) {
  void *ptr;
  char *str = "0x7fff5fbff7a0";
  char *format = "%p";
  int result = s21_sscanf(str, format, &ptr);

  ck_assert_int_eq(result, 1);
  ck_assert_ptr_nonnull(ptr);
}
END_TEST

// Тест для считывания null-указателя
START_TEST(test_sscanf_null_pointer) {
  void *ptr;
  char *str = "(nil)";
  char *format = "%p";
  int result = s21_sscanf(str, format, &ptr);

  ck_assert_int_eq(result, 1);
  ck_assert_ptr_null(ptr);
}
END_TEST

START_TEST(test_sscanf_exponential_with_width) {
  double value;
  double value2;
  char *str = "1.23e4 extra";
  char *format = "%8le";
  int result = s21_sscanf(str, format, &value);
  sscanf(str, format, &value2);

  ck_assert_int_eq(result, 1);
  ck_assert_int_eq(value, value2);
}
END_TEST

// Функция для добавления тестового случая в набор тестов
Suite *s21_sprintf_suite(void) {
  Suite *s = suite_create("s21_sprintf Test Suite");

  TCase *tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_s21_memchr_1);
  tcase_add_test(tc_core, test_s21_memchr_2);
  tcase_add_test(tc_core, test_s21_memchr_3);
  tcase_add_test(tc_core, test_s21_memchr_4);

  tcase_add_test(tc_core, test_s21_memcmp_1);
  tcase_add_test(tc_core, test_s21_memcmp_2);
  tcase_add_test(tc_core, test_s21_memcmp_3);
  tcase_add_test(tc_core, test_s21_memcmp_4);

  tcase_add_test(tc_core, test_s21_memcpy_1);
  tcase_add_test(tc_core, test_s21_memcpy_2);

  tcase_add_test(tc_core, test_s21_memset_1);
  tcase_add_test(tc_core, test_s21_memset_2);
  tcase_add_test(tc_core, test_s21_memset_3);

  tcase_add_test(tc_core, test_s21_strchr_1);
  tcase_add_test(tc_core, test_s21_strchr_2);

  tcase_add_test(tc_core, test_s21_strcspn_1);
  tcase_add_test(tc_core, test_s21_strcspn_2);
  tcase_add_test(tc_core, test_s21_strcspn_3);
  tcase_add_test(tc_core, test_s21_strcspn_4);

  tcase_add_test(tc_core, test_s21_strerror);

  tcase_add_test(tc_core, test_s21_strlen_1);
  tcase_add_test(tc_core, test_s21_strlen_2);
  tcase_add_test(tc_core, test_s21_strlen_3);

  tcase_add_test(tc_core, test_s21_strncat);

  tcase_add_test(tc_core, test_s21_strncmp_1);
  tcase_add_test(tc_core, test_s21_strncmp_3);

  tcase_add_test(tc_core, test_s21_strncpy_1);
  tcase_add_test(tc_core, test_s21_strncpy_2);
  tcase_add_test(tc_core, test_s21_strncpy_3);

  tcase_add_test(tc_core, test_s21_strpbrk_1);
  tcase_add_test(tc_core, test_s21_strpbrk_2);
  tcase_add_test(tc_core, test_s21_strpbrk_3);

  tcase_add_test(tc_core, test_s21_strrchr_1);
  tcase_add_test(tc_core, test_s21_strrchr_2);
  tcase_add_test(tc_core, test_s21_strrchr_3);
  tcase_add_test(tc_core, test_s21_strrchr_4);

  tcase_add_test(tc_core, test_s21_strstr_1);
  tcase_add_test(tc_core, test_s21_strstr_2);

  tcase_add_test(tc_core, s21_strtok_test);

  tcase_add_test(tc_core, test_s21_sprintf_c);
  tcase_add_test(tc_core, test_s21_sprintf_c_left_align);
  tcase_add_test(tc_core, test_s21_sprintf_c_width);
  tcase_add_test(tc_core, test_s21_sprintf_c_width_2);
  tcase_add_test(tc_core, test_s21_sprintf_c_length_l);

  tcase_add_test(tc_core, test_s21_sprintf_d);
  tcase_add_test(tc_core, test_s21_sprintf_d_left_align);
  tcase_add_test(tc_core, test_s21_sprintf_d_plus);
  tcase_add_test(tc_core, test_s21_sprintf_d_space);
  tcase_add_test(tc_core, test_s21_sprintf_d_width);
  tcase_add_test(tc_core, test_s21_sprintf_d_width_2);
  tcase_add_test(tc_core, test_s21_sprintf_d_precision);
  tcase_add_test(tc_core, test_s21_sprintf_d_precision_2);
  tcase_add_test(tc_core, test_s21_sprintf_d_lenght_h);
  tcase_add_test(tc_core, test_s21_sprintf_d_lenght_l);
  tcase_add_test(tc_core, test_s21_sprintf_d_flag_zero);

  tcase_add_test(tc_core, test_s21_sprintf_u);
  tcase_add_test(tc_core, test_s21_sprintf_u_precision);
  tcase_add_test(tc_core, test_s21_sprintf_u_precision_2);
  tcase_add_test(tc_core, test_s21_sprintf_u_left_align);
  tcase_add_test(tc_core, test_s21_sprintf_u_width);
  tcase_add_test(tc_core, test_s21_sprintf_u_width_2);
  tcase_add_test(tc_core, test_s21_sprintf_u_lenght_h);
  tcase_add_test(tc_core, test_s21_sprintf_u_lenght_l);
  tcase_add_test(tc_core, test_s21_sprintf_u_flag_zero);

  tcase_add_test(tc_core, test_s21_sprintf_percent);

  tcase_add_test(tc_core, test_s21_sprintf_f);
  tcase_add_test(tc_core, test_s21_sprintf_f_left_align);
  tcase_add_test(tc_core, test_s21_sprintf_f_plus);
  tcase_add_test(tc_core, test_s21_sprintf_f_plus_2);
  tcase_add_test(tc_core, test_s21_sprintf_f_space);
  tcase_add_test(tc_core, test_s21_sprintf_f_width);
  tcase_add_test(tc_core, test_s21_sprintf_f_width_2);
  tcase_add_test(tc_core, test_s21_sprintf_f_presicion);
  tcase_add_test(tc_core, test_s21_sprintf_f_presicion_2);
  tcase_add_test(tc_core, test_s21_sprintf_f_lenght_l);
  tcase_add_test(tc_core, test_s21_sprintf_f_lenght_L);
  tcase_add_test(tc_core, test_s21_sprintf_f_flag_zero);
  tcase_add_test(tc_core, test_s21_sprintf_f_lattice);

  tcase_add_test(tc_core, test_s21_sprintf_s);
  tcase_add_test(tc_core, test_s21_sprintf_s_left_align);
  tcase_add_test(tc_core, test_s21_sprintf_s_width);
  tcase_add_test(tc_core, test_s21_sprintf_s_width_2);
  tcase_add_test(tc_core, test_s21_sprintf_s_presicion);
  tcase_add_test(tc_core, test_s21_sprintf_s_presicion_2);

  tcase_add_test(tc_core, test_s21_sprintf_o);
  tcase_add_test(tc_core, test_s21_sprintf_o_left_align);
  tcase_add_test(tc_core, test_s21_sprintf_o_width);
  tcase_add_test(tc_core, test_s21_sprintf_o_width_2);
  tcase_add_test(tc_core, test_s21_sprintf_o_lattice);
  tcase_add_test(tc_core, test_s21_sprintf_o_flag_zero);
  tcase_add_test(tc_core, test_s21_sprintf_o_presicion);
  tcase_add_test(tc_core, test_s21_sprintf_o_presicion_2);
  tcase_add_test(tc_core, test_s21_sprintf_o_lenght_l);
  tcase_add_test(tc_core, test_s21_sprintf_o_lenght_h);

  tcase_add_test(tc_core, test_s21_sprintf_x);
  tcase_add_test(tc_core, test_s21_sprintf_X);
  tcase_add_test(tc_core, test_s21_sprintf_X_left_align);
  tcase_add_test(tc_core, test_s21_sprintf_X_width);
  tcase_add_test(tc_core, test_s21_sprintf_X_width_2);
  tcase_add_test(tc_core, test_s21_sprintf_X_flag_zero);
  tcase_add_test(tc_core, test_s21_sprintf_x_lattice);
  tcase_add_test(tc_core, test_s21_sprintf_X_lattice);
  tcase_add_test(tc_core, test_s21_sprintf_x_presicion);
  tcase_add_test(tc_core, test_s21_sprintf_x_presicion_2);
  tcase_add_test(tc_core, test_s21_sprintf_x_lenght_l);

  tcase_add_test(tc_core, test_s21_sprintf_p);
  tcase_add_test(tc_core, test_s21_sprintf_p_left_align);
  tcase_add_test(tc_core, test_s21_sprintf_p_width);
  tcase_add_test(tc_core, test_s21_sprintf_p_width_2);

  tcase_add_test(tc_core, test_trim_spaces);
  tcase_add_test(tc_core, test_trim_specific_chars);
  tcase_add_test(tc_core, test_trim_only_trim_chars);
  tcase_add_test(tc_core, test_trim_no_trim_chars);
  tcase_add_test(tc_core, test_trim_empty_string);
  tcase_add_test(tc_core, test_trim_null_pointers);

  tcase_add_test(tc_core, test_s21_insert);
  tcase_add_test(tc_core, test_s21_insert_null);
  tcase_add_test(tc_core, test_s21_insert_index);

  tcase_add_test(tc_core, test_s21_to_lower);
  tcase_add_test(tc_core, test_s21_to_lower_2);
  tcase_add_test(tc_core, test_s21_to_lower_3);
  tcase_add_test(tc_core, test_s21_to_lower_4);
  tcase_add_test(tc_core, test_s21_to_lower_null);

  tcase_add_test(tc_core, test_s21_to_upper);
  tcase_add_test(tc_core, test_s21_to_upper_2);
  tcase_add_test(tc_core, test_s21_to_upper_3);
  tcase_add_test(tc_core, test_s21_to_upper_null);

  tcase_add_test(tc_core, test_specifier_d);
  tcase_add_test(tc_core, test_sscanf_width_d);
  tcase_add_test(tc_core, test_specifier_s);
  tcase_add_test(tc_core, test_sscanf_width_s);
  tcase_add_test(tc_core, test_specifier_p);
  tcase_add_test(tc_core, test_specifier_n);
  tcase_add_test(tc_core, test_specifier_u);
  tcase_add_test(tc_core, test_sscanf_width_u);
  tcase_add_test(tc_core, test_specifier_o);
  tcase_add_test(tc_core, test_sscanf_width_o);
  tcase_add_test(tc_core, test_sscanf_specifier_c);
  tcase_add_test(tc_core, test_specifier_x);
  tcase_add_test(tc_core, test_sscanf_width_x);
  tcase_add_test(tc_core, test_specifier_X);
  tcase_add_test(tc_core, test_specifier_i_1);
  tcase_add_test(tc_core, test_specifier_i_2);
  tcase_add_test(tc_core, test_specifier_i_3);
  tcase_add_test(tc_core, test_sscanf_specifier_li);
  tcase_add_test(tc_core, test_sscanf_specifier_hi);
  tcase_add_test(tc_core, test_sscanf_specifier_Le);
  tcase_add_test(tc_core, test_sscanf_specifier_e);

  tcase_add_test(tc_core, test_s21_sprintf_e_default);
  tcase_add_test(tc_core, test_s21_sprintf_e_precision);
  tcase_add_test(tc_core, test_s21_sprintf_e_precision_2);
  tcase_add_test(tc_core, test_s21_sprintf_e_width);
  tcase_add_test(tc_core, test_s21_sprintf_e_width_2);
  tcase_add_test(tc_core, test_s21_sprintf_e_large_number);
  tcase_add_test(tc_core, test_s21_sprintf_e_negative);
  tcase_add_test(tc_core, test_s21_sprintf_e_default);
  tcase_add_test(tc_core, test_s21_sprintf_e_small_number);
  tcase_add_test(tc_core, test_s21_sprintf_e_width_and_precision);
  tcase_add_test(tc_core, test_s21_sprintf_e_zero);

  tcase_add_test(tc_core, test_s21_sprintf_E_default);
  tcase_add_test(tc_core, test_s21_sprintf_E_precision);
  tcase_add_test(tc_core, test_s21_sprintf_E_precision_2);
  tcase_add_test(tc_core, test_s21_sprintf_E_width);
  tcase_add_test(tc_core, test_s21_sprintf_E_width_2);
  tcase_add_test(tc_core, test_s21_sprintf_E_width_and_precision);

  tcase_add_test(tc_core, test_sscanf_pointer);
  tcase_add_test(tc_core, test_sscanf_null_pointer);
  tcase_add_test(tc_core, test_sscanf_exponential_with_width);
  tcase_add_test(tc_core, test_sscanf_exponential_with_width_and_remainder);
  tcase_add_test(tc_core, test_sscanf_width_2);
  tcase_add_test(tc_core, test_sscanf_width_3);
  tcase_add_test(tc_core, test_sscanf_width_1);
  tcase_add_test(tc_core, test_sscanf_width_hex_2);
  tcase_add_test(tc_core, test_s21_sscanf_d_0);
  tcase_add_test(tc_core, test_s21_sscanf_p_wight);
  tcase_add_test(tc_core, test_s21_sscanf_c_wight);
  tcase_add_test(tc_core, test_sscanf_width_star_i);

  suite_add_tcase(s, tc_core);

  return s;
}

// Функция main для запуска тестов
int main(void) {
  int number_failed;
  Suite *s = s21_sprintf_suite();
  SRunner *sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
