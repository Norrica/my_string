#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>
#include <stdint.h>

typedef unsigned long s21_size_t;
typedef s21_size_t size;
#define s21_NULL (void *)0

void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memmove(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strcat(char *dest, const char *src);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strchr(const char *str, int c);
int s21_strcmp(const char *str1, const char *str2);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strcpy(char *dest, const char *src);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strerror(int errnum);
s21_size_t s21_strlen(const char *str);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);
s21_size_t s21_strspn(const char *str1, const char *str2);
void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);
typedef struct {
  int plus;
  int gird;
  int minus;
  int zero;
  int space;
  int leng;
  int width;
  int point;
  int precision;
  int type;
  int star;
} parsing;
int def_number(char c);
int form_number(char *str, int *len);
char *s21_wchstrcat(char *dest, const wchar_t *src);
int spec(char c);
int leng(char c);
long double subst_input(parsing pars, va_list args);
char sign_func_subst(long double *number, int *plus, int *space);
int whole_part(long double number, int *buff);
int round_number(int *buff, int len, int *buff1, int *whole);
int str_form(parsing pars, int *buff1, int whole, char c, char *str, int *len_str);
int consider_g(char *str, int *len_str, int *len, int from_g_gird);
int form_power(int power, char e, char *str, int *len_buf);
int form_number_d(parsing pars, long int number, char *str);
int consider_precision_d(parsing pars, int i, char sign, char *str, int *precision);
int format_d(parsing pars, int len, char *str, char sign, int *len_buf);
int format_x(parsing pars, int len, char *str, int *len_buf);
char sign_func_whole(long int *number, int *plus, int *space);
int consider_precision_x(parsing pars, int i, int *precision, char *str);
int s21_sprintf(char *str, char *format, ...);
int c_or_percent_func(parsing pars, va_list args, int *len_buf, char *str);
int d_or_i_func(parsing pars, va_list args, int *len_buf, char *str);
int f_func(parsing pars, int *len_buf, char *str, long double number, int from_g_gird);
int u_func(parsing pars, va_list args, int *len_buf, char *str);
int n_func(va_list args, int length);
char convertTox(int value);
char convertToX(int value);
int convert(parsing pars, long unsigned num, long unsigned divider, char *data, char spec);
int x_or_X_func(parsing pars, va_list args, int *len_buf, char *str);
int e_or_E_func(parsing pars, int *len_buf, char *str, long double number, int from_g_gird);
int s_func(parsing pars, va_list args, int *len_buf, char *str);
int p_func(parsing pars, va_list args, int *len_buf, char *str);
int g_or_G_func(parsing pars, int *len_buf, char *str, long double number);
int calling_function(parsing pars, va_list args, int *len_buf, char *str_add, int length);
#endif  //  SRC_S21_STRING_H_
