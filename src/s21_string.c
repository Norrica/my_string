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

void *s21_memmove(void *dest, const void *src, size n) {
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

void *s21_memset(void *str, int c, s21_size_t n) {
    if (n > 0) {
        char *s = str;
        while (n--) {
            *s++ = (char) c;
        }
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
    static char result[100];
    s21_memset(result, '\0', 100);
    char str_n[100];
#if defined(__APPLE__) || defined(__MACH__)
    int max = 107;
    static char *str_error[107] = {
        "Undefined error: 0",
        "Operation not permitted",
        "No such file or directory",
        "No such process",
        "Interrupted system call",
        "Input/output error",
        "Device not configured",
        "Argument list too long",
        "Exec format error",
        "Bad file descriptor",
        "No child processes",
        "Resource deadlock avoided",
        "Cannot allocate memory",
        "Permission denied",
        "Bad address",
        "Block device required",
        "Resource busy",
        "File exists",
        "Cross-device link",
        "Operation not supported by device",
        "Not a directory",
        "Is a directory",
        "Invalid argument",
        "Too many open files in system",
        "Too many open files",
        "Inappropriate ioctl for device",
        "Text file busy",
        "File too large",
        "No space left on device",
        "Illegal seek",
        "Read-only file system",
        "Too many links",
        "Broken pipe",
        "Numerical argument out of domain",
        "Result too large",
        "Resource temporarily unavailable",
        "Operation now in progress",
        "Operation already in progress",
        "Socket operation on non-socket",
        "Destination address required",
        "Message too long",
        "Protocol wrong type for socket",
        "Protocol not available",
        "Protocol not supported",
        "Socket type not supported",
        "Operation not supported",
        "Protocol family not supported",
        "Address family not supported by protocol family",
        "Address already in use",
        "Can't assign requested address",
        "Network is down",
        "Network is unreachable",
        "Network dropped connection on reset",
        "Software caused connection abort",
        "Connection reset by peer",
        "No buffer space available",
        "Socket is already connected",
        "Socket is not connected",
        "Can't send after socket shutdown",
        "Too many references: can't splice",
        "Operation timed out",
        "Connection refused",
        "Too many levels of symbolic links",
        "File name too long",
        "Host is down",
        "No route to host",
        "Directory not empty",
        "Too many processes",
        "Too many users",
        "Disc quota exceeded",
        "Stale NFS file handle",
        "Too many levels of remote in path",
        "RPC struct is bad",
        "RPC version wrong",
        "RPC prog. not avail",
        "Program version wrong",
        "Bad procedure for program",
        "No locks available",
        "Function not implemented",
        "Inappropriate file type or format",
        "Authentication error",
        "Need authenticator",
        "Device power is off",
        "Device error",
        "Value too large to be stored in data type",
        "Bad executable (or shared library)",
        "Bad CPU type in executable",
        "Shared library version mismatch",
        "Malformed Mach-o file",
        "Operation canceled",
        "Identifier removed",
        "No message of desired type",
        "Illegal byte sequence",
        "Attribute not found",
        "Bad message",
        "EMULTIHOP (Reserved)",
        "No message available on STREAM",
        "ENOLINK (Reserved)",
        "No STREAM resources",
        "Not a STREAM",
        "Protocol error",
        "STREAM ioctl timeout",
        "Operation not supported on socket",
        "Policy not found",
        "State not recoverable",
        "Previous owner died",
        "Interface output queue is full",
    };
#elif defined(__linux__)
    int max = 132;
    static char *str_error[132] = {
        "Success",
        "Operation is not permitted",
        "No such file or directory exists",
        "No such process exists",
        "Interrupted system cal",
        "Input/output error",
        "No such device or address exists.",
        "Argument list is too long",
        "Exec format error",
        "Bad file descriptor",
        "No child process exists",
        "Resource is temporarily unavailable",
        "System cannot allocate memory",
        "Permission is denied",
        "Bad address",
        "Block device is required",
        "Device or resource is busy",
        "File already exists",
        "Invalid cross-device link",
        "No such device",
        "Not a directory",
        "A directory",
        "An invalid argument",
        "Too many open files in system",
        "Too many open files",
        "An inappropriate ioctl for device",
        "Text file is busy",
        "File is too large",
        "No space left on device",
        "Illegal seek",
        "Read-only file system",
        "Too many links",
        "Case of broken pipe",
        "Numerical argument is out of domain",
        "Numerical result is out of range",
        "Resource deadlock is avoided",
        "File name is too long",
        "No locks are available",
        "Function is not implemented",
        "Directory is not empty",
        "Too many levels of symbolic links",
        "No message of desired type",
        "Identifier is removed",
        "Channel number is out of range",
        "Level 2 is not synchronized",
        "Level 3 is halted",
        "Level 3 is reset",
        "Link number is out of range",
        "Protocol driver is not attached",
        "No CSI structure available",
        "Level 2 is halted",
        "Invalid exchange",
        "Invalid request descriptor",
        "Exchange is full",
        "No anode",
        "Invalid request code",
        "Invalid slot",
        "Bad font file format",
        "Device is not a stream",
        "No data available",
        "Timer is expired",
        "Out of streams resources",
        "Machine is not on the network",
        "Package is not installed",
        "Object is remote",
        "The link has been severed",
        "Advertise error",
        "Srmount error",
        "Communication error on send",
        "Protocol error",
        "Multihop attempted",
        "Rfs specific error",
        "Bad message",
        "Value is too large for defined data type",
        "Name is not unique on network",
        "File descriptor is in bad state",
        "Remote address is changed",
        "Cannot access a needed shared library",
        "Accessing a corrupted shared library",
        ".Lib section in a.out is corrupted",
        "Attempting to link in too many shared libraries",
        "Cannot exec a shared library directly",
        "An invalid or incomplete multibyte or wide character",
        "Interrupted system call should be restarted",
        "Streams pipe error",
        "Too many users",
        "Socket operation on non-socket",
        "Destination address is required",
        "Message is too long",
        "Protocol is wrong type for socket",
        "Protocol is not available",
        "Protocol is not supported",
        "Socket type is not supported",
        "Operation is not supported",
        "Protocol family is not supported",
        "Address family is not supported by protocol",
        "Address is already in use",
        "System cannot assign requested address",
        "Network is down",
        "Network is unreachable",
        "Network has dropped connection on reset",
        "Software caused connection abort",
        "Connection is reset by peer",
        "No buffer space available",
        "Transport endpoint is already connected",
        "Transport endpoint is not connected",
        "System cannot send after transport endpoint shutdown",
        "Too many references: cannot splice.",
        "Connection is timed out",
        "Connection is refused",
        "Host is down",
        "No route to host",
        "Operation is already in progress",
        "Operation is now in progress",
        "Stale file handle",
        "Structure needs cleaning",
        "Not a XENIX named type file",
        "No XENIX semaphores are available",
        "Named type file",
        "Remote I/O error",
        "Disk quota is exceeded",
        "No medium found",
        "Wrong medium type",
        "Operation is cancelled",
        "Required key is not available",
        "Key has expired",
        "Key has been revoked",
        "Key was rejected by service",
        "Owner is died",
        "No recoverable state",
        "Operation is not possible due to RF-kill",
        "Memory page has hardware error",
    };
#endif
    if (errnum >= max || errnum <= 0) {
        s21_itoa(errnum, str_n);
        s21_strcpy(result, "Unknown error: ");
        s21_strcat(result, str_n);
    } else {
        s21_strcat(result, str_error[errnum]);
    }
    return result;
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
    if (precision == 0 && !(flags & SET_PRECISION)) {
        precision = 6;
    } else if (precision == 0 && (flags & SET_PRECISION)) {
        precision = 0;
    }

    if (flags & PUT_MINUS) {
        num *= -1;
    }

    int int_part = (int) num;
    double float_part = num - int_part;

    char int_res[50];
    s21_itoa(int_part, int_res);

    long long float_num = float_part * pow(10, precision);
    char float_res[50];
    s21_itoa(float_num, float_res);

    char new_float_res[50];
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

    if (flags & PUT_MINUS || flags & PUT_PLUS) {
        --width;
    }
    s21_size_t res_len = s21_strlen(res_buf);
    if (fill == ' ')
        while ((int) res_len <= --width)
            *(buf++) = fill;
    if (flags & PUT_MINUS) *(buf++) = '-';
    else if (flags & PUT_PLUS) *(buf++) = '+';
    precision = 0;

    while ((int) res_len <= --width) {
        *(buf++) = fill;
    }
    if ((int) s21_strlen(res_buf) < width + precision)
        for (int i = 0; i < width + precision; ++i) {
            s21_strcat(res_buf, "0");
        }
    char *b = res_buf;
    //buf--;
    while (*b != '\0') {
        *buf++ = *b++;
    }
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
        //int precision_flag = 0;
        enum flag_itoa flags = 0;
        if (c == '%') {
            for (char *i = (char *) fmt; *fmt; ++i) {
                c = *fmt++;
                switch (c) {
                    case '%': {}
                        *(buf++) = c;
                        break;
                    case 'l':
                        flags |= IS_LONG;
                        break;
                    case 'h':
                        flags |= IS_SHORT;
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
                    case 'b': {}
                        buf = s21_sitoa(buf, va_arg(va, unsigned int), width, flags | BASE_2);
                        break;
                    case 'f': {}
                        double d = va_arg(va, double);
                        if (d < 0)
                            flags |= PUT_MINUS;
                        buf = s21_ftoa(buf, d, width, precision, flags);
                        break;
                    case 's': {}
                        const char *p = va_arg(va, const char *);
                        if (p)
                            while (*p)
                                *buf++ = *(p++);
                        break;
                    case 'u': {}
                        buf = s21_sitoa(buf, va_arg(va, unsigned int), width, flags | BASE_10);
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
                        if (!(flags & SET_PRECISION))
                            flags |= SET_PRECISION;
                        else
                            *(buf++) = '?';
                        break;
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
                        width = va_arg(va, unsigned int);
                        continue;
                    case '+': {}
                        flags |= PUT_PLUS;
                        continue;
                    case ' ':
                        //case '\0':
                        //    *buf++ = c;
                        //break;
                    default:*buf++ = c;
                        continue;
                }
            }
        }
        *buf = '\0';
    }
    return buf - save;
}
int s21_sprintf(char *buf, const char *fmt, ...) {
    va_list va;
    va_start(va, fmt);
    int ret = s21_vsprintf(buf, fmt, va);
    va_end(va);
    return ret;
}
#ifdef DEV
int main() {
    char temp1[200];
    char temp2[200];
    //char c = 'c';
    //int di = 5;
    //short hdi = 15;
    //size_t u = 10;
    int f = -155;
    char * fmt = "%10";
        sprintf(temp1, fmt,f);
    s21_sprintf(temp2, fmt,f);
    puts(temp1);
    puts(temp2);
}
#endif