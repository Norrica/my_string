#ifndef S21_STRING_H
#define S21_STRING_H
#include <stdio.h>
#include <stdlib.h>

typedef unsigned long s21_size_t;
typedef s21_size_t size;
#define S21_NULL (void *)0

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

char *s21_strstr(const char *str, const char *substr);

char *s21_strtok(char *str, const char *delim);

s21_size_t s21_strspn(const char *str1, const char *str2);

void *insert(char *dest, char *src, int x);

int my_atoi(const char *c);

double my_atof(const char *c);

char *my_itoa(int num);

char *my_ftoa(float num, int precision);

char find_specifier(char *string);

int s21_sprintf(char *str, char *fmt, ...);

#endif