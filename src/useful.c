//
// Created by Gladis Ariane on 5/5/22.
//

char *convert(unsigned int num, int base) {
    static char Representation[] = "0123456789ABCDEF";
    static char buffer[50];
    char *ptr;
    ptr = &buffer[49];
    *ptr = '\0';
    do {
        *--ptr = Representation[num % base];
        num /= base;
    } while (num != 0);
    return (ptr);
}
#include <stdarg.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include "s21_string.h"

#define min(a, b) __extension__\
    ({ __typeof__(a) _a = (a); \
       __typeof__(b) _b = (b); \
       _a < _b ? _a : _b; })
enum flag_itoa {
  FILL_ZERO = 1,
  PUT_PLUS = 2,
  PUT_MINUS = 4,
  BASE_2 = 8,
  BASE_10 = 16,
  FLOAT = 32,
  BIG_HEX = 64,
  SET_PRECISION = 128,
  SET_WIDTH = 256
};
//char *s21_itoa(int n, char *str) {
//    int len = 0, i = 0, f = 0;
//    if (n < 0) {
//        n *= -1;
//        f = 1;
//    }
//    do {
//        str[i++] = n % 10 + '0';
//        n /= 10;
//        len++;
//    } while (n);
//    if (f) {
//        str[i++] = '-';
//        len++;
//    }
//    str[i] = '\0';
//    reverse(str, len);
//    return str;
//}
char *s21_ftoa(char *buf, double num, int width, int precision, enum flag_itoa flags) {
    char fill = (flags & FILL_ZERO) ? '0' : ' ';
    if (precision == 0)
        precision = 6;
    int int_part = (int) num;
    double float_part = num - int_part;
    char int_res[50];
    s21_itoa(int_part, int_res);
    long long float_num = float_part * pow(10, precision);
    char float_res[50];
    s21_itoa(float_num, float_res);
    char res_buf[100];
    s21_strcat(res_buf, int_res);
    s21_strcat(res_buf, ".");
    s21_strcat(res_buf, float_res);
    s21_size_t res_len = s21_strlen(res_buf);
    if (flags & PUT_MINUS || flags & PUT_PLUS) {
        --width;
    }
    if (fill == ' ')
        while ((int) res_len <= --width)
            *(buf++) = fill;
    if (flags & PUT_MINUS) *(buf++) = '-';
    else if (flags & PUT_PLUS) *(buf++) = '+';
    while ((int) res_len <= --width) {
        *(buf++) = fill;
    }
    s21_strcat(buf, res_buf);
    buf += s21_strlen(res_buf);
    return buf;
}

static char *sitoa(char *buf, unsigned int num, int width, enum flag_itoa flags) {
    unsigned int base;
    char hex_size;
    if (flags & BASE_2)
        base = 2;
    else if (flags & BASE_10)
        base = 10;
    else {
        base = 16;
        if (flags & BIG_HEX) {
            hex_size = 'A';
        } else { hex_size = 'a'; }
    }
    char tmp[32];
    char *p = tmp;
    do {
        int rem = num % base;
        *p++ = (rem <= 9) ? (rem + '0') : (rem + hex_size - 0xA);
    } while ((num /= base));
    width -= p - tmp;
    char fill = (flags & FILL_ZERO) ? '0' : ' ';
    if (flags & PUT_MINUS || flags & PUT_PLUS) {
        --width;
    }
    if (fill == ' ')
        while (0 <= --width)
            *(buf++) = fill;
    if (flags & PUT_MINUS) *(buf++) = '-';
    else if (flags & PUT_PLUS) *(buf++) = '+';
    while (0 <= --width) {
        *(buf++) = fill;
    }
    do {
        *(buf++) = *(--p);
    } while (tmp < p);
    return buf;
}

int my_vsprintf(char *buf, const char *fmt, va_list va) {
    char c;
    const char *save = buf;
    while ((c = *fmt++)) {
        int width = 0;
        int precision = 0;
        int precision_flag = 0;
        enum flag_itoa flags = 0;
        if (c != '%') {
            *(buf++) = c;
            continue;
        }
        for (char *i = (char *) fmt; *fmt; ++i) {
            c = *fmt++;
            switch (c) {
                case '%': {}
                    *(buf++) = c;
                    break;
                case 'c': {}
                    *(buf++) = va_arg(va, int);
                    break;
                case 'i':
                case 'd': {}
                    int num = va_arg(va, int);
                    if (num < 0) {
                        num = -num;
                        flags |= PUT_MINUS;
                    }
                    buf = sitoa(buf, num, width, flags | BASE_10);
                    break;
                case 'X': {}
                    buf = sitoa(buf, va_arg(va, unsigned int), width, flags | BIG_HEX);
                    break;
                case 'x': {}
                    buf = sitoa(buf, va_arg(va, unsigned int), width, flags);
                    break;
                case 'b':buf = sitoa(buf, va_arg(va, unsigned int), width, flags | BASE_2);
                    break;
                case 'f': {}/*что-нибудь придумать. */
                    double f_num = va_arg(va, double);
                    buf = s21_ftoa(buf, f_num, width, precision, flags);
                    break;
                case 's': {}
                    const char *p = va_arg(va, const char *);
                    if (p)
                        while (*p)
                            *(buf++) = *(p++);
                    break;
                case 'u':buf = sitoa(buf, va_arg(va, unsigned int), width, flags | BASE_10);
                    break;
                case 'm': {}
                    const uint8_t *m = va_arg(va, const uint8_t *);
                    width = min(width, 64);
                    if (m) {
                        for (;;) {
                            buf = sitoa(buf, *(m++), 2, FILL_ZERO);
                            if (--width <= 0)
                                break;
                            *(buf++) = ':';
                        }
                    }
                    break;
                case '.': {}
                    if (!precision_flag)
                        precision_flag = 1;
                    else
                        *(buf++) = '?';
                    break;
                case '0':
                    if (!width) {
                        flags |= FILL_ZERO;
                    }
                    // fall through
                case '1'...'9': {}
                    if (!precision_flag)
                        width = width * 10 + c - '0';
                    else
                        precision = precision * 10 + c - '0';
                    continue;
                case '*': {}
                    width = va_arg(va, unsigned int);
                    continue;
                case ' ': {}
                    continue;
                case '+': {}
                    flags |= PUT_PLUS;
                    continue;
                case '\0':
                default:*(buf++) = '?';
            }
        }
        //  width = 0;
    }
    *buf = '\0';
    return buf - save;
}

int my_sprintf(char *buf, const char *fmt, ...) {
    va_list va;
    va_start(va, fmt);
    int ret = my_vsprintf(buf, fmt, va);
    va_end(va);
    return ret;
}
#ifdef DEV
#include <stdio.h>
#include <string.h>

int main() {
    char b[256];
    char c[256];
    double val = 1.58;
    char *fmt = "%+013.11f";
    my_sprintf(b, fmt, val);
    sprintf(c, fmt, val);
    puts(b);
    puts(c);
}
#endif
