#include "s21_string.h"

void *
memset(void *str, int c, size_t n)
{
    char *s = str;
    while (n--) {
        *str++ = c;
    }
    return str;
}
