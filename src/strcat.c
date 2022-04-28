/* 
The strcat() function concatenates the destination string and the source string, 
and the result is stored in the destination string.
*/

#include "s21_string.h"

char *s21_strcat(char *dest, const char *src) {
    if ((dest == NULL) && (src == NULL))
        return NULL;

    char *start = dest;
    while (*start != '\0') {
        start++;
    }
    while (*src != '\0') {
        *start++ = *src++;
    }
    *start = '\0';
    return dest;
}
