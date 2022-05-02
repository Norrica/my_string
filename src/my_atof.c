//
// Created by Ululate Leoma on 5/2/22.
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double my_atof (const char *c) {
    char *ch = (char *) c;
    int start_position = 0, sign = 1, dot_position = 0;
    double integer_part = 0;

    // удалить пробелы
    for (int i=0; ch[i] != '\0'; i++) {
        if (ch[i] == ' ')
            start_position++;
    }

    // проверить положительное или отрицательное
    if (ch[start_position] == '-' || ch[start_position] == '+') {
        sign = 1 - 2 * (ch[start_position] == '-');
        start_position++;
    }

    // найти точку - разделитель
    for (int i = start_position; ch[i] != '\0'; i++) {
        if (ch[i] == '.') {
            dot_position = i;
            break;
        }
    }

    // если нет нуля
    if (!dot_position) {
        for (int i = start_position; ch[i] != '\0'; i++) {
            integer_part = integer_part * 10 + (ch[i] - '0');
        }
        return integer_part*sign;
    }

    // если есть нуль, то подсчитать int

    for (int i = start_position; i < dot_position; i++) {
        integer_part = integer_part * 10 + (ch[i] - '0');
    }

     // подсчитать float
    double float_part = 0;
    for (int i = dot_position+1; ch[i] != '\0'; i++) {
       // printf("%d ", ch[i]-'0');
        float_part = float_part + (ch[i] - '0') * pow(10, dot_position - i);
    }

    return (integer_part + float_part) * sign;
}


int main() {
    char c[100] = "       1234.22a33";
    int a = 2;
    printf("\nor: %lf\n", atof(c));
    printf("my: %lf", my_atof(c));
}

