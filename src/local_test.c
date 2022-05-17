#include <stdio.h>
#include "s21_string.h"
int main(int argc, char const *argv[])
{
    char std[20];
    char s21[20];
    int d = -48;
    char *fmt = "|%5.10d|";
    sprintf(std,fmt,d);
    s21_sprintf(s21,fmt,d);
    printf("std - %s\n",std);
    printf("s21 - %s\n",s21);

    return 0;
}
