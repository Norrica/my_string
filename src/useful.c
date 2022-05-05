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
  /*Добавить флаг на флоат*/
};

static char *sitoa(char *buf, unsigned int num, int width, enum flag_itoa flags) {
    unsigned int base;
    if (flags & BASE_2)
        base = 2;
    else if (flags & BASE_10)
        base = 10;
    else
        base = 16;
    char tmp[32];
    char *p = tmp;
    do {
        int rem = num % base;
        *p++ = (rem <= 9) ? (rem + '0') : (rem + 'a' - 0xA);
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
                case 'd': {}
                    int num = va_arg(va, int);
                    if (num < 0) {
                        num = -num;
                        flags |= PUT_MINUS;
                    }
                    buf = sitoa(buf, num, width, flags | BASE_10);
                    break;
                case 'u':buf = sitoa(buf, va_arg(va, unsigned int), width, flags | BASE_10);
                    break;
                case 'x':buf = sitoa(buf, va_arg(va, unsigned int), width, flags);
                    break;
                case 'b':buf = sitoa(buf, va_arg(va, unsigned int), width, flags | BASE_2);
                    break;
                case 'f': /*что-нибудь придумать. */
                case 's': {}
                    const char *p = va_arg(va, const char *);
                    if (p)
                        while (*p)
                            *(buf++) = *(p++);
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
                case '0':
                    if (!width)
                        flags |= FILL_ZERO;
                    // fall through
                case '1'...'9': {}
                    width = width * 10 + c - '0';
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
int main(int argc, char *argv[]) {
    char b[256];
    char c[256];
    int val = 10;
       sprintf(c, "%07+d", val);
    my_sprintf(b, "%07+d", val);
    puts(b);
    puts(c);
}
#endif
