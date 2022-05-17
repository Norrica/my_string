#include <stdio.h>
#include "s21_string.h"
int main(int argc, char const *argv[])
{
    char std[50];
    char s21[50];
    int d = 10;
    char *fmt = "|%5.5s|";
    sprintf(std,fmt,"lol");
    s21_sprintf(s21,fmt,"lol");
    puts(std);
    puts(s21);

    return 0;
}
