#include "s21_string.h"

size_t strlen(const char *str) {
    char *p = str;
    size_t length = 0;
    while (p != '\0') {
        length++;
        p++;
    }
    return length;
}