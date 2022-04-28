/* 
searches for the FIRST occurrence of the character c (an unsigned char) in the string pointed to by the argument str and 
returns a pointer to the first occurrence of the character c in the string str, or NULL if the character is not found.
*/
#include <stdio.h>

char *s21_strchr(const char *str, int c) {
    char *p = (char *)str;
    while (*p != c && *p != '\0')
        p++;

    return p;
}
