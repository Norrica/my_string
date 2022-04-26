#include "s21_string.h"

char *strcat(char *dest, const char *src) {
    char *ptr = dest + strlen(dest);
    while (*src !='\0') {
        *ptr++ = *src++;
    }
    *ptr = '\0';
    return dest;
}
