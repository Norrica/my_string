/*
Appends source string to the end of a destination string upto n characters long.
*/

#include "s21_string.h"
#include <string.h>

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
    char *ptr = dest;
    while (*ptr != '\0')
        ptr ++;
    while (*src != '\0' && n--) {
        *ptr++ = *src++; }
    *ptr++ = '\0';
    return dest;
}
