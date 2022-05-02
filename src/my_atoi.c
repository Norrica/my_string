//
// Created by Ululate Leoma on 5/2/22.
//
int my_atoi(const char *c) {
    char *ch = (char *) c;
    int res = 0, sign = 1;
    while (*ch == ' ') {
        ch++;
    }

    if (*ch == '-' || *ch == '+') {
        sign = 1 - 2 * (*ch++ == '-');
    }

    while (*ch != '\0') {
        if (*ch >= '0' && *ch <= '9')
            res = res * 10 + *ch++ - '0';
        else
            break;
    }
    return res * sign;
}

// TODO
// !Проверить!
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "s21_string.h"

int main() {
    int counter = 0, len1 = 0;
    char c[100] = "67.7";
    printf("      my: %d\n", my_atoi(c));
    printf("original: %d", atoi(c));
    return 0;
}
