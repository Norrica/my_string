#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
    void *result = s21_NULL;
    const unsigned char *p = str;
    while (n--)
        if (*p++ == c) {
            result = (void *) p - 1;
            break;
        }
    return result;
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
    int result = 0;
    unsigned const char *p1 = str1, *p2 = str2;
    while (n--) {
        if (*p1++ != *p2++) {
            result = *--p1 - *--p2;
            break;
        }
    }
    return result;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
    unsigned char *p1 = dest;
    const unsigned char *p2 = src;
    while (n--)
        *p1++ = *p2++;
    return dest;
}

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
    unsigned char *p1 = dest;
    const unsigned char *p2 = src;
    if (p1 < p2) {
        while (n--)
            *p1++ = *p2++;
    } else {
        p1 = p1 + (n - 1);
        p2 = p2 + (n - 1);
        while (n--)
            *p1-- = *p2--;
    }
    return dest;
}

void *s21_memset(void *str, int c, s21_size_t n) {
    unsigned char *p = str;
    while (n--)
        *p++ = c;
    return str;
}

char *s21_strcat(char *dest, const char *src) {
    char *p = dest;
    while (*p)
        p++;
    while (*src)
        *p++ = *src++;
    *p = '\0';
    return dest;
}

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
    char *p = dest;
    while (*p)
        p++;
    while (*src && n--)
        *p++ = *src++;
    *p++ = '\0';
    return dest;
}

char *s21_strchr(const char *str, int c) {
    //  while (*str != '\0' && *str != c)
    //      ++str;
    //  return (char *) (c == *str ? str : s21_NULL);
    while (*str != '\0') {
        if (*str == c) {
            return (char *) str;
        }
        str++;
    }
    return (s21_NULL);
}

int s21_strcmp(const char *str1, const char *str2) {
    int result = 0;
    s21_size_t size_str1 = s21_strlen(str1);
    s21_size_t size_str2 = s21_strlen(str2);
    s21_size_t size_max = size_str1 > size_str2 ? size_str1 : size_str2;
    for (size_t i = 0; i < size_max; i++) {
        if (str1[i] != str2[i]) {
            result = str1[i] - str2[i];
            break;
        }
    }
    return result;
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
    int result = 0;
    for (size_t i = 0; i < n && str1[i]; i++) {
        if (str1[i] != str2[i]) {
            result = str1[i] - str2[i];
            break;
        }
    }
    return result;
}

char *s21_strcpy(char *dest, const char *src) {
    char *p = dest;
    while (*p || *src)
        *p++ = *src++;
    return dest;
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
    s21_size_t size = s21_strlen(src);
    if (size < n)
        s21_memset(dest + size, '\0', n - size);
    return s21_memcpy(dest, src, n);
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
    s21_size_t result = 0;
    while (*str1 && !s21_strchr(str2, *str1++)) {
        result++;
    }
    return result;
}
// TODO(f): не решено
char *s21_strerror(int errnum) {
    static char result[100];
#if defined(__APPLE__) || defined(__MACH__)
    int n = 106;
    const char *str_error[] = {
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
    int n = 131;
    const char *str_error[] = {
        "No error information",
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
        "Socket not connected",
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
    if (errnum > n || errnum < 0) {
#if defined(__APPLE__) || defined(__MACH__)
        char res[30];
        s21_sprintf(res, "Unknown error: %d", errnum);
        s21_strcpy(result, res);
#elif defined(__linux__)
        s21_strcpy(result, "No error information");
#endif
    } else {
        s21_strcpy(result, str_error[errnum]);
    }
    return result;
}

s21_size_t s21_strlen(const char *str) {
    s21_size_t len = 0;
    for (; str[len]; len++) {}   /* changed ; to {} */
    return len;
}

char *s21_strpbrk(const char *str1, const char *str2) {
    char *result = s21_NULL;
    s21_size_t size_str1 = s21_strlen(str1);
    s21_size_t size_str2 = s21_strlen(str2);
    for (s21_size_t i = 0; i < size_str1 && result == s21_NULL; i++) {
        for (s21_size_t j = 0; j < size_str2 && result == s21_NULL; j++) {
            if (str1[i] == str2[j]) {
                result = (char *) &str1[i];
            }
        }
    }
    return result;
}

char *s21_strrchr(const char *str, int c) {
    s21_size_t size = s21_strlen(str) + 1;
    char *result = s21_NULL;
    for (s21_size_t i = 0; i < size; i++) {
        if (str[i] == c) {
            result = (char *) &str[i];
        }
    }
    return result;
}

s21_size_t s21_strspn(const char *str1, const char *str2) {
    s21_size_t result = 0;
    while (*str1 && s21_strchr(str2, *str1++)) {
        result++;
    }
    return result;
}

char *s21_strstr(const char *haystack, const char *needle) {
    char *result = s21_NULL;
    const char *p1 = haystack, *p2 = needle;
    int i = 1;
    while (i) {
        if (!*p2) {
            result = (char *) haystack;
            i = 0;
        }
        if (!*p1)
            i = 0;
        if (*p1++ != *p2++) {
            p1 = ++haystack;
            p2 = needle;
        }
    }
    return result;
}

char *s21_strtok(char *str, const char *delim) {
    static char *current;
    char *result = str;
    if (delim != s21_NULL && *delim) {
        if (str != s21_NULL && *str) {
            /*remove delims from start*/
            str = &str[s21_strspn(str, delim)];
            s21_size_t first = s21_strspn(str, delim);
            s21_size_t second = s21_strcspn(str, delim);
            current = &str[second] + 1;
            str[second] = '\0';
            result = str;
        } else {
            current = &current[s21_strspn(current, delim)];
            s21_size_t first = s21_strspn(current, delim);
            s21_size_t second = s21_strcspn(current, delim);
            str = &current[first];
            str[second] = '\0';
            current = &current[second] + 1;
            result = str;
            if (*result=='\0'){
                result = s21_NULL;
            }
        }
    }
    return result;
}

void s21_reverse(char *str, int len) {
    int p1 = 0;
    int p2 = len - 1;
    while (p1 < p2) {
        char temp = *(str + p1);
        *(str + p1) = *(str + p2);
        *(str + p2) = temp;
        p1++;
        p2--;
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
    s21_reverse(str, len);
    return str;
}

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
    char *result = s21_NULL;
    if (src != s21_NULL && str != s21_NULL) {
        s21_size_t size_src = s21_strlen(src);
        s21_size_t size_str = s21_strlen(str);
        s21_size_t size_total = size_src + size_str;
        if (size_src >= start_index) {
            result = (char *) malloc(size_total * sizeof(char));
            if (result != s21_NULL) {
                for (s21_size_t i = 0; i < size_src; i++) {
                    result[i] = src[i];
                }
                for (s21_size_t i = start_index; i < size_total; i++) {
                    result[i] = str[i - start_index];
                }
                for (s21_size_t i = start_index + size_str; i < size_total; i++) {
                    result[i] = src[i - s21_strlen(str)];
                }
                result[size_total] = '\0';
            }
        }
    }
    return result;
}

void *s21_to_lower(const char *str) {
    if (str == s21_NULL) {
        return s21_NULL;
    }
    int len = s21_strlen(str);
    char *result = malloc(len * sizeof(char));
    if (result == s21_NULL) {
        return s21_NULL;
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
    if (str == s21_NULL) {
        return s21_NULL;
    }
    s21_size_t len = s21_strlen(str);
    char *result = malloc(len * sizeof(char));
    if (result == s21_NULL) {
        return s21_NULL;
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
    if ((trim_chars != s21_NULL) && (s21_strlen(trim_chars) > 0)) {
        int len = s21_strlen(trim_chars);
        for (int i = 0; i <= len; i++) {
            if (trim_chars[i] == c) {
                res = 1;
            }
        }
    }
    return res;
}

void *s21_trim(const char *src, const char *trim_chars) {
    char *result = s21_NULL;
    if (trim_chars == s21_NULL || *trim_chars == '\0') {
        trim_chars = " \f\n\r\t\v";
    }
    if (src != s21_NULL) {
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
                return s21_NULL;
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

char *SetFill(char *buf, int width, char fill) {
    while (width-- > 0) {
        *buf++ = fill;
    }
    return buf;
}
char *SetSign(char *buf, enum conversion_flags *flags) {
    if (*flags & IS_NEGATIVE) {
        *buf++ = '-';
    } else if ((*flags) & PUT_PLUS) {
        *buf++ = '+';
    }
    return buf;
}

char *s21_ftoa(char *buf, long double num, int width, int precision, enum conversion_flags flags) {
    char fill/* = (flags & FILL_ZERO) ? '0' : ' '*/;
    __attribute__((unused)) char *save = buf;
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
        buf = SetSign(buf, &flags);
        while (*b != '\0') {
            *buf++ = *b++;
        }
        if (fill == ' ') {
            buf = SetFill(buf, width, fill);
        } else {
            buf = SetSign(buf, &flags);
            buf = SetFill(buf, width, fill);
        }
    } else {
        if (fill == ' ') {
            buf = SetFill(buf, width, fill);
            buf = SetSign(buf, &flags);
        } else {
            buf = SetSign(buf, &flags);
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
    //region HEX
    if (flags & IS_ADDRESS) {
        *buf++ = '0';
        if (hex_size == 'a')
            *buf++ = 'x';
        else
            *buf++ = 'X';
        buf = s21_strcpy(buf, "7ffe");/*Костыль*/
        buf += 4;
    }
    //endregion

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
        buf = SetSign(buf, &flags);
        do {
            *(buf++) = *(--p);
        } while (tmp < p);
        buf = SetFill(buf, width, fill);
    } else {
        if (fill == '0') {
            buf = SetSign(buf, &flags);
            buf = SetFill(buf, width, fill);
        } else {
            buf = SetFill(buf, width, fill);
            buf = SetSign(buf, &flags);
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
        if (p)
            while (*p)
                *buf++ = *(p++);
    } else {
        if (p)
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
                    //if (flags & SET_PRECISION) {
                    //    width = precision + 1;
                    //    flags |= FILL_ZERO;
                    //    flags &= ~JUSTIFY_LEFT;
                    //}
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
                    if (width == 0 && (flags & SET_PRECISION)) {
                        width = s21_strlen(p);
                    }
                    buf = stringer(flags, p, buf, width);
                    start_fmt = 0;
                    continue;
                case 'u': {}
                    buf = s21_sitoa(buf, va_arg(va, unsigned int), width, precision, flags | BASE_10);
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
