/*
The strcmp() compares two strings character by character. 
If the strings are equal, the function returns 0.
--------------------------------------------
    char c1[] = "abcd";
    char c2[] = "abcd";
    char c3[] = "abcde";
    printf("%d", s21_strcmp(c1, c2));
    printf("\n");
    printf("%d", s21_strcmp(c1, c3));
    printf("\n");
--------------------------------------------
>>>0
>>>-101
*/
#include "s21_string.h"
#include <string.h>



int s21_strcmp(const char *str1, const char *str2) {
    while(*str1 && (*str1 == *str2)) {
        str1++;
        str2++; }
    return *(const unsigned char*)str1 - *(const unsigned char*)str2;
}

int main() {
    char c1[] = "abcd";
    char c2[] = "abcd";
    char c3[] = "abcde";
    printf("%d", s21_strcmp(c1, c2));
    printf("\n");
    printf("%d", s21_strcmp(c1, c3));
    printf("\n");
    printf("%d", strcmp(c1, c2));
    printf("\n");
    printf("%d", strcmp(c1, c3));    
    return 0;
}