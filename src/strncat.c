/*
Appends source string to the end of a destination string upto n characters long.
--------------------------------------------
char dest[30];
strcpy(dest, "Techie ");

char src[] = "Delight – Implement strncat";

my_strncat(dest, src, 7);

puts(dest);
>> Techie Delight
--------------------------------------------
*/

#include "s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
    char *ptr = dest + s21_strlen(dest);
    while (*src != '\0' && n--) {
        *ptr++ = *src++;
    }
    *ptr = '\0';
    return dest;
}
