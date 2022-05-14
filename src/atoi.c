
int my_atoi (const char *c) {
    char *ch = (char *) c;
    int res = 0, sign = 1;
    while (*ch == ' ') {
        ch++; }

    if (*ch == '-' || *ch == '+') {
        sign = 1 - 2 * (*ch++ == '-');}

    while (*ch >= '0' && *ch <= '9') {
        res = res * 10 + *ch++ - '0'; }
    return res*sign;
 }




//    // checking for valid input
//    while (str[i] >= '0' && str[i] <= '9')
//    {
//        // handling overflow test case
//        if (base > INT_MAX / 10
//            || (base == INT_MAX / 10
//                && str[i] - '0' > 7))
//        {
//            if (sign == 1)
//                return INT_MAX;
//            else
//                return INT_MIN;
//        }
//        base = 10 * base + (str[i++] - '0');
//    }
//    return base * sign;


//}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "s21_string.h"

int main() {
    int counter = 0, len1 = 0;
    char c[100] = "-123";
    printf("%d \n",strlen(c));
    while (c[counter] != '\0') {
        if (c[counter] >= 48 && c[counter] <= 57) {
            len1++; }
        counter++;
    }
    printf("%d \n", len1);
    printf("my: %d\n", my_atoi(c));
    printf("original: %d", atoi(c));

//    printf("%d\n", strcmp("atoi", "a"));
//    printf("%d", s21_strcmp("atoi", "a"));
}

