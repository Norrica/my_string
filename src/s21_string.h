#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>
#include <ctype.h>
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

// int my_atoi(const char *c);
//
// double my_atof(const char *c);
//
void s21_reverse(char *str, int len);

char *s21_itoa(long long n, char *str);
//
// char *my_ftoa(float num, int precision);

// char find_specifier(char *string);
//
// int s21_sprintf(char *str, char *fmt, ...);
// int s21_sprintf(char *str, char *fmt, ...);

void *s21_to_upper(const char *str);

void *s21_to_lower(const char *str);

void *s21_insert(const char *src, const char *str, s21_size_t start_index);

void *s21_trim(const char *src, const char *trim_chars);
#define min(a, b) __extension__\
    ({ __typeof__(a) _a = (a); \
       __typeof__(b) _b = (b); \
       _a < _b ? _a : _b; })
enum conversion_flags {
  FILL_ZERO = 1,
  PUT_PLUS = 2,
  IS_NEGATIVE = 4,
  BASE_2 = 8,
  BASE_8 = 16,
  BASE_10 = 32,
  BIG_HEX = 64,
  SET_PRECISION = 128,
  L = 256,
  h = 512,
  l = 1024,
  ll = 2048,
  PUT_SPACE = 4096,
  JUSTIFY_LEFT = 8192,
  IS_ADDRESS = 16384,
};


char *s21_sitoa(char *buf, long long int num, int width, int precision, enum conversion_flags flags);
char *s21_ftoa(char *buf, long double num, int width, int precision, enum conversion_flags flags);
int s21_vsprintf(char *buf, const char *fmt, va_list va);
int s21_sprintf(char *buf, const char *fmt, ...);
#endif  //  SRC_S21_STRING_H_
