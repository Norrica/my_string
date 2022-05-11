#include <stdarg.h>
#include <math.h>
#include <ctype.h>
#include <stdint.h>
#include <stdlib.h>
#include "s21_string.h"

void *s21_memchr(const void *str, int c, size_t n) {
    const char *s = str;
    int flg = 0;
    while (n--)
        if (*s++ == c) {
            flg = 1;
            break;
        }
    void *result = (void *) s - 1;
    if (!flg)
        result = S21_NULL;
    return result;
}

int s21_memcmp(const void *str1, const void *str2, size_t n) {
    int result = 0;
    unsigned const char *s1 = str1, *s2 = str2;
    if (n != 0) {
        while (n-- != 0) {
            if (*s1++ != *s2++) {
                result = *--s1 - *--s2;
                break;
            }
        }
    }
    return result;
}

void *s21_memcpy(void *dest, const void *src, size_t n) {
    char *d = dest;
    const char *s = src;
    while (n--)
        *d++ = *s++;
    return dest;
}

char *s21_strcpy(char *dest, const char *src) {
    //  if (s21_strlen(dest) < s21_strlen(src)) {
    //    return S21_NULL;
    //  }
    char *d = dest;
    char *s = (char *) src;
    for (; *d || *s; d++, s++) {
        *d = *s;
    }
    return dest;
}

char *s21_strncpy(char *dest, const char *src, size n) {
    return s21_memcpy(dest, src, n);
}

void *s21_memmove(void *dest, const void *src, size_t n) {
    char *d = dest;
    const char *s = src;
    if (d < s) {
        while (n--)
            *d++ = *s++;
    } else {
        char *lasts = (char *) s + (n - 1);
        char *lastd = d + (n - 1);
        while (n--)
            *lastd-- = *lasts--;
    }
    return dest;
}

void *s21_memset(void *str, int c, size_t n) {
    char *s = str;
    while (n--) {
        *s++ = (char) c;
    }
    return str;
}

char *s21_strchr(const char *str, int c) {
    char *result = S21_NULL;
    do {
        if (*str == c) {
            result = (char *) str;
        }
    } while (*str++);
    return result;
}

char *s21_strrchr(const char *str, int c) {
    const char *ptr, *found;
    c = (unsigned char) c;
    if (c == '\0')
        return s21_strchr(str, '\0');
    found = S21_NULL;
    while ((ptr = s21_strchr(str, c)) != S21_NULL) {
        found = ptr;
        str = ptr + 1;
    }
    return (char *) found;
}

char *s21_strpbrk(const char *str1, const char *str2) {
    int flag = 0;
    char *res = S21_NULL;
    while (*str1 != '\0' && !flag) {
        for (int i = 0; i < (int) s21_strlen(str2); i++) {
            if (*str1 == *(str2 + i)) {
                flag = 1;
                res = (char *) str1;
            }
        }
        str1++;
    }
    return res;
}

size s21_strspn(const char *str1, const char *str2) {
    size_t res = 0;
    while (*str1 && s21_strchr(str2, *str1++)) {
        res++;
    }
    return res;
}

size s21_strcspn(const char *str1, const char *str2) {
    size_t count = 0;
    while (*str1 && !s21_strchr(str2, *str1++)) {
        count++;
    }
    return count;
}

char *s21_strstr(const char *str, const char *substr) {
    const char *a = str, *b = substr;
    while (1) {
        if (!*b) return (char *) str;
        if (!*a) return S21_NULL;
        if (*a++ != *b++) {
            a = ++str;
            b = substr;
        }
    }
}

char *s21_strcat(char *dest, const char *src) {
    if ((dest == S21_NULL) && (src == S21_NULL))
        return S21_NULL;
    char *start = dest;
    while (*start != '\0') {
        start++;
    }
    while (*src != '\0') {
        *start++ = *src++;
    }
    *start = '\0';
    return dest;
}

char *s21_strncat(char *dest, const char *src, size n) {
    char *ptr = dest;
    while (*ptr != '\0')
        ptr++;
    while (*src != '\0' && n--) {
        *ptr++ = *src++;
    }
    *ptr++ = '\0';
    return dest;
}

int s21_strcmp(const char *str1, const char *str2) {
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return *(const unsigned char *) str1 - *(const unsigned char *) str2;
}

int s21_strncmp(const char *str1, const char *str2, size n) {
    int result;
    while (n && *str1 && (*str1 == *str2)) {
        str1++;
        str2++;
        n--;
    }
    if (n == 0)
        result = 0;
    else
        result = *(unsigned char *) str1 - *(unsigned char *) str2;
    return result;
}

size s21_strlen(const char *str) {
    size len = 0;
    for (; str[len]; len++) {}
    return len;
}

// char *s21_strtok(char *str, const char *delim) {
//    char *s21_strtok(char *str, const char *delim) {
//        int i = 0;
//        while (str[i] != '\0') {
//            for (int j = 0; j < (int) s21_strlen(delim); j++) {
//                if (str[i] == delim[j]) {
//                    str[i] = '\0';
//                }
//            }
//            i++;
//        }
//        if (*str == '\0') {
//            return S21_NULL;
//        } else {
//            return str;
//        }
//    }
//}

char *s21_strtok(char *str, const char *delim) {
    static char *buffer;
    char *token = S21_NULL;
    if (str) {
        buffer = str;
        while (*buffer && s21_strchr(delim, *buffer)) {
            *buffer++ = '\0';
        }
    }
    if (buffer && *buffer) {
        str = buffer;
        while (*buffer && !s21_strchr(delim, *buffer)) {
            ++buffer;
        }
        while (*buffer && s21_strchr(delim, *buffer)) {
            *buffer++ = '\0';
        }
        token = str;
    }
    return token;
}

void reverse(char *str, int len) {
    int s = 0;
    int e = len - 1;
    while (s < e) {
        int tmp = *(str + s);
        *(str + s) = *(str + e);
        *(str + e) = tmp;
        s++;
        e--;
    }
}

char *s21_itoa(long long n, char *str) {
    int len = 0, i = 0, f = 0;
    if (n < 0) {
        n *= -1;
        f = 1;
    }
    do {
        str[i++] = n % 10 + '0';
        n /= 10;
        len++;
    } while (n);
    if (f) {
        str[i++] = '-';
        len++;
    }
    str[i] = '\0';
    reverse(str, len);
    return str;
}

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
    char *result = S21_NULL;

    int len_src = s21_strlen(src);
    int len_str = s21_strlen(str);
    int len_total = len_src + len_str;
    if (len_src >= (int) start_index) {
        result = (char *) malloc(len_total * sizeof(char));
        if (result != S21_NULL) {
            for (int i = 0; i < len_src; i++) {
                result[i] = src[i];
            }
            for (int i = start_index; i < len_total; i++) {
                result[i] = str[i - start_index];
            }
            for (int i = start_index + len_str; i < len_total; i++) {
                result[i] = src[i - s21_strlen(str)];
            }
            result[len_total] = '\0';
        }
    }
    return result;
}

char *s21_strerror(int errnum) {
    static char *str[] = ERRORS;
    int max;
    char error[4096] = {'\0'};
    char stt[10];
    static char strr[4096] = {'\0'};
    for (int i = 0; i < 4096; i++) strr[i] = '\0';
#if defined(__APPLE__) && defined(__MACH__)
    max = 106;
#else
    max = 133;
#endif
    if (errnum > max || errnum < 0) {
        s21_itoa(errnum, stt);
        s21_strcpy(error, "Unknown error: ");
        s21_strncat(error, stt, s21_strlen(error));
    } else {
        s21_strcat(error, str[errnum]);
    }
    s21_strcat(strr, error);
    return strr;
}

void *s21_to_lower(const char *str) {
    int len = s21_strlen(str);
    char *result = malloc(len * sizeof(char));
    if (result == S21_NULL) {
        return S21_NULL;
    }
    s21_strcpy(result, str);
    for (int i = 0; i < len; i++) {
        if (str[i] >= 65 && str[i] <= 90)
            result[i] = str[i] + 32;
        else
            result[i] = str[i];
    }
    return result;
}

void *s21_to_upper(const char *str) {
    s21_size_t len = s21_strlen(str);
    char *result = malloc(len * sizeof(char));
    if (result == S21_NULL) {
        return S21_NULL;
    }
    s21_strcpy(result, str);
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] >= 97 && str[i] <= 122)
            result[i] = str[i] - 32;
        else
            result[i] = str[i];
    return result;
}

int isthere(char c, const char *trim_chars) {
    int res = 0;
    if ((trim_chars != S21_NULL) && (s21_strlen(trim_chars) > 0)) {
        int len = s21_strlen(trim_chars);
        for (int i = 0; i <= len; i++) {
            if (trim_chars[i] == c) {
                res = 1;
            }
        }
    } else {
        res = isspace(c);
    }
    return res;
}

void *s21_trim(const char *src, const char *trim_chars) {
    char *result = S21_NULL;
    if (src != S21_NULL) {
        int len = s21_strlen(src);
        int last_n = len;
        int i = 0;
        int start_n = -1;
        while (i <= len) {
            if (isthere(src[i], trim_chars) == 1) {
                start_n = i;
                i++;
            } else {
                i = len + 1;
            }
        }
        i = len - 1;
        while (i >= 0) {
            if (isthere(src[i], trim_chars) == 1) {
                last_n = i;
                i--;
            } else {
                i = -1;
            }
        }
        result = (char *) calloc(1, sizeof(char));
        int temp = 0;
        for (int j = start_n + 1; j < last_n; j++) {
            char *tmp = (char *) realloc(result, (temp + 2) * sizeof(char *));
            if (!tmp) {
                return S21_NULL;
            } else {
                result = tmp;
            }
            result[temp] = src[j];
            temp++;
        }
        result[temp] = '\0';
    }
    return result;
}


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

char *s21_sitoa(char *buf, unsigned int num, int width, enum flag_itoa flags) {
    unsigned int base;
    char hex_size = 'a';
    if (flags & BASE_2) {
        base = 2;
    } else if (flags & BASE_10) {
        base = 10;
    } else {
        base = 16;
        if (flags & BIG_HEX) {
            hex_size = 'A';
        } else {
            hex_size = 'a';
        }
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

int s21_vsprintf(char *buf, const char *fmt, va_list va) {
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
                    buf = s21_sitoa(buf, num, width, flags | BASE_10);
                    break;
                case 'X': {}
                    buf = s21_sitoa(buf, va_arg(va, unsigned int), width, flags | BIG_HEX);
                    break;
                case 'x': {}
                    buf = s21_sitoa(buf, va_arg(va, unsigned int), width, flags);
                    break;
                case 'b':buf = s21_sitoa(buf, va_arg(va, unsigned int), width, flags | BASE_2);
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
                case 'u':buf = s21_sitoa(buf, va_arg(va, unsigned int), width, flags | BASE_10);
                    break;
                case 'm': {}
                    const uint8_t *m = va_arg(va, const uint8_t *);
                    width = min(width, 64);
                    if (m) {
                        for (;;) {
                            buf = s21_sitoa(buf, *(m++), 2, FILL_ZERO);
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

int s21_sprintf(char *buf, const char *fmt, ...) {
    va_list va;
    va_start(va, fmt);
    int ret = s21_vsprintf(buf, fmt, va);
    va_end(va);
    return ret;
}
