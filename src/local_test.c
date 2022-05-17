#include <stdio.h>
#include "s21_string.h"
int main(int argc, char const *argv[])
{
    char std[20];
    char s21[20];
    int d = 10;
    char *fmt = "|%.5%|";
    sprintf(std,fmt,48);
    s21_sprintf(s21,fmt,48);
    puts(std);
    puts(s21);

    return 0;
}
