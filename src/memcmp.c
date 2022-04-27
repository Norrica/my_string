#include "s21_string.h"

int
memcmp(const void *str1, const void *str2, size_t n)
{
    int result = 0;
    const char *s1 = str1, *s2 = str2;
    while (n--) {
        if (*s1++ != *s2++) {
            result = *--s1 - *--s2;
            break;
        }
    }
    return result;
}
