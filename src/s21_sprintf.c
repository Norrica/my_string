#include "s21_string.h"

char *SetFill(char *buf, int width, char fill) {
    while (width-- > 0) {
        *buf++ = fill;
    }
    return buf;
}
char *SetSign(char *buf, enum conversion_flags flags) {
    if (flags & IS_NEGATIVE) {
        *buf++ = '-';
    } else if ((flags) & PUT_PLUS) {
        *buf++ = '+';
    }
    return buf;
}

char *s21_ftoa(char *buf, long double num, int width, int precision, enum conversion_flags flags) {
    char fill/* = (flags & FILL_ZERO) ? '0' : ' '*/;
    if (flags & FILL_ZERO) {
        fill = '0';
    } else {
        fill = ' ';
    }
    if ((flags & PUT_SPACE) && width == 0) {
        width++;
    }
    if (precision == 0 && !(flags & SET_PRECISION)) {
        precision = 6;
    } else if (precision == 0 && (flags & SET_PRECISION)) {
        precision = 0;
    }

    if (flags & IS_NEGATIVE) {
        num *= -1;
    }

    int int_part = (int) num;
    double float_part = num - int_part;

    char int_res[50];
    s21_itoa(int_part, int_res);

    long long float_num = float_part * pow(10, precision);
    char float_res[50];
    s21_itoa(float_num, float_res);

    char new_float_res[50] = "";
    if ((size) precision > s21_strlen(float_res))
        s21_memset(new_float_res, '0', precision - s21_strlen(float_res));
    s21_strcat(new_float_res, float_res);
    s21_strcpy(float_res, new_float_res);

    char res_buf[100];
    s21_strcpy(res_buf, int_res);
    if (precision != 0) {
        s21_strcat(res_buf, ".");
        s21_strcat(res_buf, float_res);
    }

    if (flags & IS_NEGATIVE || flags & PUT_PLUS) {
        --width;
    }
    s21_size_t res_len = s21_strlen(res_buf);
    width -= res_len;
    char *b = res_buf;
    if (flags & PUT_SPACE && !((flags & PUT_PLUS) || (flags & IS_NEGATIVE))) {
        *buf++ = ' ';
        width--;
    }
    if ((flags & JUSTIFY_LEFT)) {
        buf = SetSign(buf, flags);
        while (*b != '\0') {
            *buf++ = *b++;
        }
        if (fill == ' ') {
            buf = SetFill(buf, width, fill);
        } else {
            buf = SetSign(buf, flags);
            buf = SetFill(buf, width, fill);
        }
    } else {
        if (fill == ' ') {
            buf = SetFill(buf, width, fill);
            buf = SetSign(buf, flags);
        } else {
            buf = SetSign(buf, flags);
            buf = SetFill(buf, width, fill);
        }
        while (*b != '\0') {
            *buf++ = *b++;
        }
    }
    if ((int) s21_strlen(res_buf) < width + precision) {
        for (int i = 0; i < width + precision; ++i) {
            s21_strcat(res_buf, "0");
        }
    }
    return buf;
}

char *s21_sitoa(char *buf, long long int num, int width, int precision, enum conversion_flags flags) {
    unsigned int base;
    char hex_size = 'a';
    /*region BASE*/
    if (flags & BASE_2) {
        base = 2;
    } else if (flags & BASE_8) {
        base = 8;
    } else if (flags & BASE_10) {
        base = 10;
    } else {
        base = 16;
        if (flags & BIG_HEX) {
            hex_size = 'A';
        }
    }
    /*endregion*/
    /*region HEX*/
    if (flags & IS_ADDRESS) {
        *buf++ = '0';
        if (hex_size == 'a')
            *buf++ = 'x';
        else
            *buf++ = 'X';
        buf = s21_strcpy(buf, "7ffe");/*Костыль*/
        buf += 4;
    }
    /*endregion*/

    if (num < 0) {
        num = -num;
        flags |= IS_NEGATIVE;
    }

    char tmp[32];
    char *p = tmp;
    do {
        int rem = num % base;
        *p++ = (rem <= 9) ? (rem + '0') : (rem + hex_size - 0xA);
    } while ((num /= base));
    precision -= p - tmp;
    while (precision-- > 0) {
        *p++ = '0';
    }
    width -= p - tmp;

    char fill;
    if (flags & FILL_ZERO) {
        fill = '0';
    } else {
        fill = ' ';
    }
    if (flags & PUT_SPACE && !((flags & PUT_PLUS) || (flags & IS_NEGATIVE))) {
        *buf++ = ' ';
        width--;
    }
    if ((flags & PUT_PLUS) || (flags & IS_NEGATIVE)) {
        width--;
    }
    if ((flags & JUSTIFY_LEFT)) {
        fill = ' ';
        buf = SetSign(buf, flags);
        do {
            *(buf++) = *(--p);
        } while (tmp < p);
        buf = SetFill(buf, width, fill);
    } else {
        if (fill == '0') {
            buf = SetSign(buf, flags);
            buf = SetFill(buf, width, fill);
        } else {
            buf = SetFill(buf, width, fill);
            buf = SetSign(buf, flags);
        }
        do {
            *(buf++) = *(--p);
        } while (tmp < p);
    }
    return buf;
}

char *stringer(enum conversion_flags flags, const char *p, char *buf, int width) {
    int a = s21_strlen(p);
    // char *string = (char *) malloc(a + width);
    // width -= a;
    if (width < a) {
        width = 0;
    }
    if (!(flags & JUSTIFY_LEFT)) {
        while ((((width)--) - a) > 0) {
            if (flags & FILL_ZERO)
                *buf++ = '0';
            else
                *buf++ = ' ';
        }
        /* char *save = buf; */
        while (*p)
            *buf++ = *(p++);
    } else {
        while (*p)
            *buf++ = *(p++);
        while ((((width)--) - a) > 0) {
            *buf++ = ' ';
        }
    }
    return buf;
}
int s21_vsprintf(char *buf, const char *fmt, va_list va) {
    char c;
    const char *save = buf;
    while ((c = *fmt++)) {
        int width = 0;
        int precision = 0;
        enum conversion_flags flags = 0;
        if (c != '%') {
            *(buf++) = c;
            continue;
        }
        int start_fmt = 1;
        for (char *i = (char *) fmt; start_fmt; ++i) {
            c = *fmt++;
            switch (c) {
                case '%': {}
                    char b[2] = "";
                    b[0] = '%';
                    b[1] = '\0';
                    buf = stringer(flags, b, buf, width);
                    start_fmt = 0;
                    continue;
                case 'L':flags |= L;
                    continue;
                case 'h':flags |= h;
                    continue;
                case 'l':flags |= l;
                    if (*(fmt + 1) == 'l') {
                        flags |= ll;
                        flags &= ~l;
                    }
                    continue;
                case 'c': {}
                    // *buf++ = ;
                    char a[2] = "";
                    a[0] = va_arg(va, int);
                    a[1] = '\0';
                    buf = stringer(flags, a, buf, width);
                    start_fmt = 0;
                    continue;
                case 'i':
                case 'd': {}
                    long long int num;
                    if (flags & l) {
                        num = va_arg(va, long int);
                    } else {
                        if (flags & ll) {
                            num = va_arg(va, long long int);
                        } else if (flags & h) {
                            num = va_arg(va, int);
                            num = (short int) num;
                        } else {
                            num = va_arg(va, int);
                        }
                    }
                    buf = s21_sitoa(buf, num, width, precision, flags | BASE_10);
                    start_fmt = 0;
                    continue;
                case 'X': {}
                    buf = s21_sitoa(buf, va_arg(va, unsigned int), width, precision, flags | BIG_HEX);
                    start_fmt = 0;
                    continue;
                case 'x': {}
                    buf = s21_sitoa(buf, va_arg(va, unsigned int), width, precision, flags);
                    start_fmt = 0;
                    continue;
                case 'p':buf = s21_sitoa(buf, va_arg(va, unsigned int), width, precision, flags | IS_ADDRESS);
                    start_fmt = 0;
                    continue;
                case 'b': {}
                    buf = s21_sitoa(buf, va_arg(va, unsigned int), width, precision, flags | BASE_2);
                    start_fmt = 0;
                    continue;
                case 'f': {}
                    long double d;
                    if (flags & L)
                        d = (long double) va_arg(va, long double);
                    else
                    d = (double) va_arg(va, double);
                    if (d < 0)
                        flags |= IS_NEGATIVE;
                    if (precision)
                        d = roundl(d * pow(10, precision)) / pow(10, precision);
                    else
                        d = roundl(d * pow(10, 6)) / pow(10, 6);
                    buf = s21_ftoa(buf, d, width, precision, flags);
                    start_fmt = 0;
                    continue;
                case 's': {}
                    const char *p = va_arg(va, const char *);
                    if (p) {
                        if (width == 0 && (flags & SET_PRECISION)) {
                            width = s21_strlen(p);
                        }
                    } else {
                        p = "(null)";
                    }
                    buf = stringer(flags, p, buf, width);
                    start_fmt = 0;
                    continue;
                case 'u': {}
                    flags &= ~IS_NEGATIVE;
                    flags &= ~PUT_PLUS;
                    flags &= ~PUT_SPACE;
                    buf = s21_sitoa(buf, va_arg(va, long unsigned int), width, precision, flags | BASE_10);
                    start_fmt = 0;
                    continue;
                case 'o': {}
                    buf = s21_sitoa(buf, va_arg(va, unsigned int), width, precision, flags | BASE_8);
                    start_fmt = 0;
                    continue;
                case 'm': {}
                    const uint8_t *m = va_arg(va, const uint8_t *);
                    width = min(width, 64);
                    if (m) {
                        for (;;) {
                            buf = s21_sitoa(buf, *(m++), 2, precision, FILL_ZERO);
                            if (--width <= 0)
                                break;
                            *(buf++) = ':';
                        }
                    }
                    start_fmt = 0;
                    continue;
                case '.': {}
                    if (!(flags & SET_PRECISION))
                        flags |= SET_PRECISION;
                    continue;
                case '0':
                    if (!width) {
                        flags |= FILL_ZERO;
                    }
                    // fall through
                case '1'...'9': {}
                    if (!(flags & SET_PRECISION))
                        width = width * 10 + c - '0';
                    else
                        precision = precision * 10 + c - '0';
                    continue;
                case '*': {}
                    if (flags & SET_PRECISION) {
                        precision = va_arg(va, unsigned int);
                    } else {
                        width = va_arg(va, unsigned int);
                    }
                    continue;
                case '+': {}
                    flags |= PUT_PLUS;
                    continue;
                case '-': {}
                    flags |= JUSTIFY_LEFT;
                    continue;
                case ' ':
                    if (!(flags & PUT_SPACE) && width == 0) {
                        flags |= PUT_SPACE;
                    }
                    continue;
                case 'g':
                case 'G':
                case 'e':
                case 'E':
                case 'n':

                default:continue;
            }
        }
    }
    *buf = '\0';
    return buf - save;
}
int s21_sprintf(char *buf, const char *fmt, ...) {
    va_list va;
    va_start(va, fmt);
    int ret = s21_vsprintf(buf, fmt, va);
    va_end(va);
    return ret;
}
