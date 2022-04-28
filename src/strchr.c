#include "s21_string.h"

char *s21_strchr(const char *str, int c) {
    char *p = (char *)str;
    while (*p != c && *p != '\0')
        p++;

    return p;
}
