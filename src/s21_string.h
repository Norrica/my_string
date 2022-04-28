#include <stdio.h>

typedef long unsigned s21_size_t;
#define S21_NULL ((void *)0)

void *s21_memchr(const void *str, int c, s21_size_t n);// jarrusab
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n); 
void *s21_memmove(void *dest, const void *src, s21_size_t n); 
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strcat(char *dest, const char *src);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strchr(const char *str, int c);
int s21_strcmp(const char *str1, const char *str2);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strcpy(char *dest, const char *src); // tarengre
char *s21_strncpy(char *dest, const char *src, s21_size_t n); // tarengre
s21_size_t s21_strcspn(const char *str1, const char *str2); // tarengre
char *s21_strerror(int errnum); // tarengre
s21_size_t s21_strlen(const char *str); // tarengre
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c); // gladisar
char *s21_strstr(const char *str, const char *substr);
char *s21_strtok(char *str, const char *delim); // gladisar
s21_size_t s21_strspn(const char *str1, const char *str2);
