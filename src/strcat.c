/* 
The strcat() function concatenates the destination string and the source string, 
and the result is stored in the destination string.
--------------------------------------------
    char str1[100] = "This is ", str2[] = "programiz.com";
    strcat(str1, str2);
    puts(str1);
--------------------------------------------
>> This is programiz.com
--------------------------------------------
*/

#include "s21_string.h"
s21_size_t s21_strlen(const char *str)
{
    s21_size_t len = 0;
    for(; str[len]; len++);
    return len + 1;
}

char *s21_strcat(char *dest, const char *src) {
    char *ptr = dest + s21_strlen(dest);
    while (*src !='\0') {
        *ptr++ = *src++; }
    *ptr = '\0';
    return dest;
}

int main() {
    char str1[100] = "This is ", str2[] = "programiz.com";
    printf("%ld", s21_strlen(str2));
    s21_strcat(str1, str2);
    puts(str1);
    return 0;
}