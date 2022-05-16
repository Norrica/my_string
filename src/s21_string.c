#include <stdarg.h>
#include <math.h>
#include <ctype.h>
#include <stdint.h>
#include <stdlib.h>
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
    //while (*str != '\0' && *str != c)
    //    ++str;
    //return (char *) (c == *str ? str : s21_NULL);
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
//TODO: не решено
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
    for (; str[len]; len++);
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
    if (delim != NULL && *delim) {
        if (str != s21_NULL && *str) {
            /*remove delims from start*/
            str = &str[s21_strspn(str, delim)];
            s21_size_t first = s21_strspn(str, delim);
            s21_size_t second = s21_strcspn(str, delim);
            if (second == s21_strlen(str) || first == s21_strlen(str)) {
                if (current != s21_NULL)
                    result = str;
                else
                    result = s21_NULL;
            } else {
                current = &str[second] + 1;
                str[second] = '\0';
                result = str;
            }
        } else {
            if (current == s21_NULL || current[0] == '\0') {
                result = s21_NULL;
            } else {
                result = s21_strtok(current, delim);
                current = &current[s21_strspn(current, result)];
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

char *s21_wchstrcat(char *dest, const wchar_t *src) {
    s21_size_t l = s21_strlen(dest);
    int x = 0;
    for (int i = 0; src[i] != '\0'; i++) {
        dest[l + i] = src[i];
        x++;
    }
    dest[l + x] = '\0';
    return dest;
}

int g_or_G_func(parsing pars, int *len_buf, char *str, long double number) {
    int len_e = 0;
    char *str_e = NULL;
    str_e = (char *) malloc(200 * sizeof(char));
    // change type
    if (pars.type == 'g') {
        pars.type = 'e';
    } else {
        pars.type = 'E';
    }
    // consider precision
    if (!pars.point || pars.precision < 0)
        pars.precision = 6;
    if (!pars.precision)
        pars.precision = 1;
    pars.precision -= 1;
    int power = e_or_E_func(pars, &len_e, str_e, number, pars.gird + 1);
    if (power < -4 || (power > 0 && pars.precision + 1 <= power + 1)) {
        *len_buf = len_e;
        s21_strcat(str, str_e);
    } else {
        pars.precision -= power;
        f_func(pars, &len_e, str_e, number, pars.gird + 1);
        *len_buf = len_e;
        s21_strcat(str, str_e);
    }
    free(str_e);
    return 1;
}

char sign_func_whole(long int *number, int *plus, int *space) {
    char c;
    if (*number < 0) {
        *number = *number * (-1);
        c = '-';
        *plus = 1;
        *space = 0;
    } else {
        c = '+';
    }
    return c;
}

char sign_func_subst(long double *n, parsing_format pf) {
    char c;
    if (*n < 0) {
        *n = *n * (-1);
        c = '-';
        pf.flag = '+';
    } else {
        c = '+';
    }
    return c;
}

int whole_part(long double n, int *array) {
    long double temp_1;
    int temp_array[100], i = 0;

    modfl(n, &temp_1);
    long int temp_2 = (long int) temp_1;

    if (temp_2) {
        while (temp_2) {
            temp_array[i] = temp_2 % 10;
            temp_2 = temp_2 / 10;
            i++;
        }
    } else {
        temp_array[i] = 0;
        i++;
    }

    for (int j = 0; j < i; j++) {
        array[j] = temp_array[i - j - 1];
    }
    return i;
}

int fraction_part(int shortage, long double number, int *buff, int whole) {
    long double buf, temp = modfl(number, &buf);
    for (int j = 0; j <= shortage; j++) {
        temp = temp * 10.0;
        temp = modfl(temp, &buf);
        buff[whole + j] = (int) buf;
    }
    return 1;
}

int round_number(int *buff, int len, int *buff1, int *whole) {
    int i = len;
    if (buff[len] >= 5) {
        int flag = 1;
        while (flag) {
            i--;
            if (i == -1)
                flag = 0;
            buff[i]++;
            if (buff[i] > 9 && i != 0) {
                buff[i] = 0;
                continue;
            } else {
                flag = 0;
            }
        }
    }
    // form new finish array with numbers
    if (buff[0] > 9) {
        buff1[0] = 1;
        buff1[1] = 0;
        for (int j = 1; j < len; j++)
            buff1[j + 1] = buff[j];
        *whole += 1;
    } else {
        for (int j = 0; j < len; j++)
            buff1[j] = buff[j];
    }
    return 1;
}

int str_form(parsing pars, int *buff1, int whole, char c, char *str, int *len_str) {
    for (int j = 0; j < whole; j++)
        str[j] = buff1[j] + 48;

    // consider the existence of point
    if (pars.precision == 0 && pars.gird == 0) {
        str[whole] = '\0';
        *len_str = whole;
    } else {
        str[whole] = '.';
        for (int j = 0; j < pars.precision; j++) {
            str[whole + 1 + j] = buff1[whole + j] + 48;
        }
        str[whole + pars.precision + 1] = '\0';
        *len_str = whole + pars.precision + 1;
    }
    int len = *len_str;
    // consider sign
    if (pars.plus) {
        s21_memmove(str + 1, str, *len_str);
        str[0] = c;
        str[*len_str + 1] = '\0';
        *len_str += 1;
    } else {
        if (pars.space) {
            s21_memmove(str + 1, str, *len_str);
            str[0] = ' ';
            str[*len_str + 1] = '\0';
            *len_str += 1;
        }
    }
    return len;
}

int consider_g(char *str, int *len_str, int *len, int from_g_gird) {
    if (from_g_gird == 1) {
        while (str[*len_str - 1] == 48) {
            str[*len_str - 1] = '\0';
            *len_str -= 1;
            *len -= 1;
        }
        if (str[*len_str - 1] == '.') {
            str[*len_str - 1] = '\0';
            *len_str -= 1;
            *len -= 1;
        }
    }
    return 1;
}

int format_f(parsing pars, int len1, int len, char c, char *str, int *len_buf) {
    if (pars.width > len) {
        if (!pars.minus) {
            s21_memmove(str + pars.width - len1, str, len1);
            if (pars.zero) {
                for (int j = 0; j < pars.width - len; j++)
                    str[j] = '0';
                if (pars.plus) {
                    str[0] = c;
                } else if (pars.space) {
                    str[0] = ' ';
                }
            } else {
                for (int j = 0; j < pars.width - len; j++)
                    str[j] = ' ';

                if (pars.plus) {
                    str[pars.width - len - 1] = c;
                }
            }
        } else {
            for (int j = len1; j < pars.width; j++) {
                str[j] = ' ';
            }
        }
        *len_buf = pars.width;
        str[pars.width] = '\0';
    } else {
        *len_buf = len1;
    }
    return 1;
}

int form_power(int power, char e, char *str, int *len_buf) {
    char sign;
    if (power >= 0) {
        sign = '+';
    } else {
        power = power * (-1);
        sign = '-';
    }
    int pow[2];
    if (power >= 10) {
        int i = 0;
        while (i != 2) {
            pow[1 - i] = power % 10;
            power = power / 10;
            i++;
        }
    } else {
        pow[0] = 0;
        pow[1] = power;
    }
    str[*len_buf] = e;
    str[*len_buf + 1] = sign;
    str[*len_buf + 2] = pow[0] + 48;
    str[*len_buf + 3] = pow[1] + 48;
    str[*len_buf + 4] = '\0';
    *len_buf = *len_buf + 4;
    return *len_buf;
}

int e_or_E_func(parsing pars, int *len_buf, char *str, long double number, int from_g_gird) {
    long double const_zero = pow(10, -50);
    *len_buf = 0;
    char e = pars.type, sign = sign_func_subst(&number, &pars.plus, &pars.space);
    if (!pars.point || pars.precision < 0)
        pars.precision = 6;
    int power = 0, whole, len;
    long double buf_number = number;
    int *buff1 = (int *) malloc(100 * sizeof(int));
    int *buff = (int *) malloc(100 * sizeof(int));
    if (number < const_zero) {
        power = 0;
        whole = 1;
        for (int i = 0; i < whole + pars.precision; i++) {
            buff[i] = 0;
        }
    } else {
        while (buf_number > 10) {
            buf_number = buf_number / 10;
            power++;
        }
        while (buf_number < 1) {
            buf_number = buf_number * 10;
            power--;
        }
        number = buf_number;
        whole = whole_part(number, buff);
        fraction_part(pars.precision, number, buff, whole);
        round_number(buff, whole + pars.precision, buff1, &whole);
        if (whole == 2) {
            number = number / 10;
            power++;
        }
        whole = whole_part(number, buff);
        fraction_part(pars.precision, number, buff, whole);
    }
    len = str_form(pars, buff1, whole, sign, str, len_buf);
    consider_g(str, len_buf, &len, from_g_gird);
    int len1 = form_power(power, e, str, len_buf);
    len += 4;
    format_f(pars, len1, len, sign, str, len_buf);
    free(buff);
    free(buff1);
    return power;
}

int consider_precision_x(parsing pars, int i, int *precision, char *str) {
    if (pars.precision < 0)
        pars.precision = i;
    // precision solve
    if (pars.precision > i) {
        s21_memmove(str + pars.precision - i, str, i);
        for (int j = 0; j < pars.precision - i; j++) {
            str[j] = '0';
        }
    } else if (pars.precision == 0) {
        pars.precision = i;
    } else {
        pars.precision = i;
    }
    // consider gird
    int len;
    if (pars.gird) {
        len = pars.precision + 2;
    } else {
        len = pars.precision;
    }
    // str after with precision
    if (pars.gird) {
        s21_memmove(str + 2, str, pars.precision);
        str[0] = '0';
        str[1] = pars.type;
        str[pars.precision + 2] = '\0';
    } else {
        str[pars.precision] = '\0';
    }
    *precision = pars.precision;
    return len;
}

int f_func(parsing_format pf, int *len_buf, char *str, long double number, int from_g_gird) {
    char sign = sign_func_subst(&number, &pf);
    if (pf.precision < 0)
        pf.precision = 6;
    int *array_1 = (int *) malloc(100 * sizeof(int));

    int whole = whole_part(number, array_1);

    fraction_part(pf.precision, number, array_1, whole);

    int *buff1 = (int *) malloc(100 * sizeof(int));
    round_number(array_1, whole + pf.precision, buff1, &whole);
    int len = str_form(pf, buff1, whole, sign, str, len_buf);
    consider_g(str, len_buf, &len, from_g_gird);
    int len1 = *len_buf;
    format_f(pf, len1, len, sign, str, len_buf);
    free(array_1);
    free(buff1);
    return 1;
}

int format_x(parsing pars, int len, char *str, int *len_buf) {
    if (pars.width > len) {
        if (!pars.minus) {
            s21_memmove(str + pars.width - len, str, len);
            if (pars.zero) {
                for (int j = 0; j < pars.width - pars.precision; j++)
                    str[j] = '0';
                if (pars.gird) {
                    str[0] = '0';
                    str[1] = pars.type;
                }
            } else {
                for (int j = 0; j < pars.width - pars.precision; j++)
                    str[j] = ' ';

                if (pars.gird) {
                    str[pars.width - pars.precision - 1] = pars.type;
                    str[pars.width - pars.precision - 2] = '0';
                }
            }
        } else {
            for (int j = len; j < pars.width; j++) {
                str[j] = ' ';
            }
            str[pars.width] = '\0';
        }
        *len_buf = pars.width;
    } else {
        *len_buf = len;
    }
    return 1;
}

int x_or_X_func(parsing pars, va_list args, int *len_buf, char *str) {
    long unsigned number = va_arg(args, long unsigned);
    if (pars.leng == 0) {
        number = (unsigned int) number;
    } else if (pars.leng == 'h') {
        number = (short unsigned int) number;
    }
    // form number 16-system
    char *data = malloc(sizeof(char *));
    int index = convert(pars, number, 16, data, pars.type);
    for (int i = index; i >= 0; i--)
        str[index - i] = data[i];
    str[index + 1] = '\0';
    int i = index + 1;
    if (pars.point != 0 && pars.precision >= 0) {
        pars.zero = 0;
    }
    if (number == 0) {
        if (pars.point == 0) {
            str[0] = '0';
            str[1] = '\0';
            i = 1;
        }
        pars.gird = 0;
    }
    // precision solve
    int len = consider_precision_x(pars, i, &pars.precision, str);
    // if width > len
    format_x(pars, len, str, len_buf);
    free(data);
    return *len_buf;
}

int u_func(parsing pars, va_list args, int *len_buf, char *str) {
    if (pars.point && pars.precision >= 0) {
        pars.zero = 0;
    }
    long unsigned int number = va_arg(args, long unsigned int);
    if (pars.leng == 0) {
        number = (unsigned int) number;
    } else if (pars.leng == 'h') {
        number = (short unsigned int) number;
    }
    // parsing number
    long unsigned int buf = number;
    int i = 0;
    int buff[100];
    if (buf) {
        while (buf) {
            buff[i] = buf % 10;
            buf = buf / 10;
            i++;
        }
    } else {
        if (pars.precision != 0 || pars.point == 0) {
            buff[i] = 0;
            i++;
        }
    }
    // switch numbers to the right direction
    for (int j = 0; j < i; j++) {
        str[j] = buff[i - j - 1] + 48;
    }
    str[i] = '\0';
    // precision solve
    if (pars.precision > i) {
        s21_memmove(str + pars.precision - i, str, i);
        for (int j = 0; j < pars.precision - i; j++) {
            str[j] = '0';
        }
    } else {
        pars.precision = i;
    }
    int len = pars.precision;
    str[pars.precision] = '\0';
    // str after with precision
    // if width > len
    if (pars.width > len) {
        if (!pars.minus) {
            s21_memmove(str + pars.width - len, str, len);
            if (pars.zero) {
                for (int j = 0; j < pars.width - pars.precision; j++)
                    str[j] = '0';
            } else {
                for (int j = 0; j < pars.width - pars.precision; j++)
                    str[j] = ' ';
            }
        } else {
            for (int j = len; j < pars.width; j++) {
                str[j] = ' ';
            }
            str[pars.width] = '\0';
        }
        *len_buf = pars.width;
    } else {
        *len_buf = len;
    }
    return 1;
}

int form_number_d(parsing pars, long int number, char *str) {
    int i = 0;
    int buff[100];
    if (number) {
        while (number) {
            buff[i] = number % 10;
            number = number / 10;
            i++;
        }
    } else {
        if (pars.precision < 0 || pars.point == 0) {
            buff[i] = 0;
            i++;
        }
    }
    for (int j = 0; j < i; j++) {
        str[j] = buff[i - j - 1] + 48;
    }
    str[i] = '\0';
    return i;
}

int consider_precision_d(parsing pars, int i, char sign, char *str, int *precision) {
    // precision solve
    if (pars.precision > i) {
        s21_memmove(str + pars.precision - i, str, i);
        for (int j = 0; j < pars.precision - i; j++) {
            str[j] = '0';
        }
    } else {
        *precision = i;
        pars.precision = i;
    }
    // consider plus
    int len;
    if (pars.plus || pars.space) {
        len = pars.precision + 1;
    } else {
        len = pars.precision;
    }
    // str after with precision
    if (pars.plus) {
        s21_memmove(str + 1, str, pars.precision);
        str[0] = sign;
        str[pars.precision + 1] = '\0';
    } else {
        if (pars.space) {
            s21_memmove(str + 1, str, pars.precision);
            str[0] = ' ';
            str[pars.precision + 1] = '\0';
        } else {
            str[pars.precision] = '\0';
        }
    }
    return len;
}

int format_d(parsing pars, int len, char *str, char sign, int *len_buf) {
    // if width > len
    if (pars.width > len) {
        if (!pars.minus) {
            s21_memmove(str + pars.width - len, str, len);
            if (pars.zero) {
                for (int j = 0; j < pars.width - pars.precision; j++)
                    str[j] = '0';
                if (pars.plus) {
                    str[0] = sign;
                } else if (pars.space) {
                    str[0] = ' ';
                }
            } else {
                for (int j = 0; j < pars.width - pars.precision; j++)
                    str[j] = ' ';

                if (pars.plus) {
                    str[pars.width - pars.precision - 1] = sign;
                }
            }
        } else {
            for (int j = len; j < pars.width; j++) {
                str[j] = ' ';
            }
            str[pars.width] = '\0';
        }
        *len_buf = pars.width;
    } else {
        *len_buf = len;
    }
    return 1;
}

int d_or_i_func(parsing pars, va_list args, int *len_buf, char *str) {
    if (pars.point && pars.precision >= 0)
        pars.zero = 0;
    long int number = va_arg(args, long int);
    if (pars.leng == 0) {
        number = (int) number;
    } else if (pars.leng == 'h') {
        number = (short int) number;
    }
    char sign = sign_func_whole(&number, &pars.plus, &pars.space);
    // size of number
    int i = form_number_d(pars, number, str);
    // consider precision
    int len = consider_precision_d(pars, i, sign, str, &pars.precision);
    // fornmat d_func
    format_d(pars, len, str, sign, len_buf);
    return 1;
}

int o_func(parsing pars, va_list args, int *len_buf, char *str) {
    long unsigned number = va_arg(args, long unsigned);
    if (pars.leng == 0) {
        number = (unsigned int) number;
    } else if (pars.leng == 'h') {
        number = (short unsigned int) number;
    }
    // form number 8-system
    char *data = (char *) malloc(200 * sizeof(char));
    int index = convert(pars, number, 8, data, pars.type);
    for (int i = index; i >= 0; i--)
        str[index - i] = data[i];
    str[index + 1] = '\0';
    int i = index + 1;
    if (pars.point)
        pars.zero = 0;
    if (pars.precision < 0)
        pars.precision = i;
    // consider gird
    if (pars.gird && number != 0) {
        s21_memmove(str + 1, str, i);
        str[0] = '0';
        i++;
        str[i] = '\0';
    } else {
        str[i] = '\0';
    }
    // precision solve
    if (pars.precision > i) {
        s21_memmove(str + pars.precision - i, str, i);
        for (int j = 0; j < pars.precision - i; j++) {
            str[j] = '0';
        }
    } else {
        pars.precision = i;
    }
    // if width > len
    pars.plus = 0;
    pars.space = 0;
    format_d(pars, pars.precision, str, '+', len_buf);
    free(data);
    return *len_buf;
}

int p_func(parsing pars, va_list args, int *len_buf, char *str) {
    int size = 0;
    unsigned long num = va_arg(args, unsigned long);
    char *data = malloc(200 * sizeof(char *));
    char *reverse = malloc(200 * sizeof(char *));
    char *src = malloc(sizeof(char *));
    char *tmp = malloc(sizeof(char *));
    int index = convert(pars, num, 16, data, 'x');
    for (int i = index; i >= 0; i--)
        reverse[index - i] = data[i];
    reverse[index + 1] = '\0';
    src[0] = '0';
    src[1] = 'x';
    src[2] = '\0';
    if ((void *) num == NULL) {
        if (pars.point != 0) {
            src[2] = '\0';
        } else {
            src[2] = '0';
            src[3] = '\0';
        }
    }
    s21_strcat(src, reverse);
    if (pars.width) {
        if (pars.width > (int) s21_strlen(src)) {
            size = pars.width - (int) s21_strlen(src);
        }
        if (pars.minus) {
            for (int i = 0; i < (int) s21_strlen(src); i++) {
                str[i] = src[i];
            }
            for (int j = (int) s21_strlen(src); j < pars.width; j++) {
                str[j] = ' ';
            }
        } else {
            for (int i = 0; i < (int) s21_strlen(src); i++) {
                tmp[i] = src[i];
            }
            for (int i = 0; i < size; i++) {
                str[i] = ' ';
            }
            int index = 0;
            for (int i = size; i < size + (int) s21_strlen(tmp); i++) {
                str[i] = tmp[index];
                index++;
            }
        }
    } else {
        for (int i = 0; i < (int) s21_strlen(src); i++) {
            str[i] = src[i];
        }
    }
    *len_buf = (int) s21_strlen(str);
    free(data);
    free(reverse);
    free(src);
    free(tmp);
    return 0;
}

int s_func(parsing pars, va_list args, int *len_buf, char *str) {
    if (pars.leng == 0) {
        char *src;
        src = va_arg(args, char *);
        s21_strcat(str, src);
    } else {
        wchar_t *src;
        src = (wchar_t *) va_arg(args, wchar_t *);
        s21_wchstrcat(str, src);
    }
    if (pars.precision >= (int) s21_strlen(str) || (pars.precision == 0 && pars.point == 0)
        || pars.precision < 0)
        pars.precision = (int) s21_strlen(str);
    str[pars.precision] = '\0';

    if (pars.width > pars.precision) {
        if (!pars.minus) {
            s21_memmove(str + pars.width - pars.precision, str, pars.precision);
            if (pars.zero) {
                for (int i = 0; i < pars.width - pars.precision; i++)
                    str[i] = '0';
            } else {
                for (int i = 0; i < pars.width - pars.precision; i++)
                    str[i] = ' ';
            }
        } else {
            for (int i = pars.precision; i < pars.width; i++)
                str[i] = ' ';
        }
        str[pars.width] = '\0';
        *len_buf = pars.width;
    } else {
        *len_buf = pars.precision;
    }
    return 1;
}

char convertToX(int value) {
    char ch;
    if (value >= 0 && value < 10) {
        ch = value + 48;
    } else {
        ch = value + 55;
    }
    return ch;
}

char convertTox(int value) {
    char ch;
    if (value >= 0 && value < 10) {
        ch = value + 48;
    } else {
        ch = value + 87;
    }
    return ch;
}

int convert(parsing pars, long unsigned num, long unsigned divider, char *data, char spec) {
    long unsigned rem = num;
    char ch;
    int index = 0;
    if (num) {
        while (num) {
            rem = num % divider;
            num = num / divider;
            if ((spec == 'x') || (spec == 'o')) {
                ch = convertTox(rem);
            }
            if (spec == 'X') {
                ch = convertToX(rem);
            }
            data[index] = ch;
            index++;
        }
    } else {
        if (pars.precision < 0) {
            data[index] = '0';
            index++;
        }
    }
    return index - 1;
}

int n_func(va_list args, int length) {
    int *number = va_arg(args, int*);
    *number = length;
    return 1;
}

int def_number(char c) {
    int result = 0;
    if (c >= '0' && c <= '9') {
        result = 1;
    }
    return result;
}

int spec(char c) {
    int result = 0;
    int code[16] = {99, 100, 101, 102, 105, 69, 71, 103, 111, 115, 117, 88, 120, 110, 112, 37};
    for (int i = 0; i <= 16; i++) {
        if (c == code[i]) {
            result = code[i];
        }
    }
    return result;
}

long double subst_input(parsing_format pf, va_list arg) {
    long double number;
    if (pf.length == 0) {
        number = (long double) va_arg(arg, double);
    } else {
        number = va_arg(arg, long double);
    }
    return number;
}

int c_or_percent_func(parsing_format pf, va_list args, int *len_buf, char *str) {
    char c;
    if (pf.specifier == '%') {
        c = '%';
    } else {
        c = va_arg(args, int);
    }
    if (pf.width == 0)
        pf.width = 1;
    if (pf.flag == '-') {
        str[0] = c;
        for (int i = 1; i < pf.width; i++) {
            str[i] = ' ';
        }
        str[pf.width] = '\0';
    } else {
        if (pf.flag == '0') {
            for (int i = 0; i < pf.width - 1; i++)
                str[i] = '0';
        } else {
            for (int i = 0; i < pf.width - 1; i++)
                str[i] = ' ';
        }
        str[pf.width - 1] = c;
        str[pf.width] = '\0';
    }
    if (pf.width) {
        *len_buf = pf.width;
    } else {
        *len_buf = 1;
    }
    return 1;
}

void form_number(char *str, int *len, parsing_format *pf) {
    int factor = 0;
    char *tmp = str;
    if (*tmp >= '0' && *tmp <= '9') {
        int len1 = 0;
        while (def_number(*tmp)) {
            factor = (factor * 10) + (*tmp) - 48;
            tmp++;
            len1++;
        }
        *len = len1;
        if (pf->star == '*') {
            factor = 0;
        }
        if (pf->dot == '.') {
            pf->precision = factor;
            pf->dot = 0;
        } else {
            pf->width = factor;
        }
    }
}

int s21_sprintf(char *str, char *format, ...) {
    va_list arg;
    parsing pars;

    parsing_format pf;
    int len_add = 0;
    char *str_add;
    str_add = (char *) malloc(200 * sizeof(char));
    int length = 0;
    va_start(arg, format);
    while (*format) {
        if (*format == '%') {
            // the initialization of the struct
            pars.plus = 0;
            pars.gird = 0;
            pars.minus = 0;
            pars.zero = 0;
            pars.space = 0;
            pars.leng = 0;
            pars.width = 0;
            pars.point = 0;
            pars.precision = 0;
            pars.type = 0;
            pars.star = 0;
            format++;
            int flag = 1;

            pf.specifier = 0;
            pf.flag = 0;
            pf.width = 0;
            pf.precision = 0;
            pf.dot = 0;
            pf.length = 0;
            pf.star = 0;
            pf.negative = 0;

            for (int i = 0; i < 200; i++)
                str_add[i] = '\0';
            len_add = 0;

            long double number = 0.0;
            int from_g_gird = 0;

            while (flag) {
                switch (*format) {
                    case '-':pf.flag = '-';
                    case '+':pf.flag = '+';
                    case ' ':
                        if (pf.flag != '+')
                            pf.flag = ' ';
                    case '#':pf.flag = '#';
                    case '0':pf.flag = '0';
                        break;
                    case '*':pf.star = '*';
                        int i = va_arg(arg, int);
                        if (i < 0) {
                            pf.flag = '-';
                            i *= -1;
                        }
                        if (pf.dot == '.') {
                            pf.width = i;
                        } else {
                            pf.precision = i;
                            pf.dot = 0;
                        }
                        break;
                    case '.':pf.dot = '.';
                        break;
                    case 'h':pf.length = 'h';
                        break;
                    case 'l':pf.length = 'l';
                        break;
                    case 'L':pf.length = 'L';
                        break;
                    case 'c':
                    case '%':pf.specifier = (int) *format;
                        c_or_percent_func(pf, arg, &len_add, str_add);
                        flag = 0;
                        break;
                    case 'f':pf.specifier = 'f';
                        number = subst_input(pf, arg);
                        f_func(pars, &len_add, str_add, number, from_g_gird);
                        break;
                    case 'd':
                    case 'i':pf.specifier = (int) *format;
                        d_or_i_func(pars, arg, &len_add, str_add);
                        break;
                    case 'u':pf.specifier = 'u';
                        u_func(pars, arg, &len_add, str_add);
                        break;
                    case 'n':pf.specifier = 'n';
                        n_func(arg, length);
                        break;
                    case 'o':pf.specifier = 'o';
                        o_func(pars, arg, &len_add, str_add);
                        break;
                    case 'x':
                    case 'X':pf.specifier = (int) *format;
                        x_or_X_func(pars, arg, &len_add, str_add);
                        break;
                    case 'e':
                    case 'E':pf.specifier = (int) *format;
                        number = subst_input(pars, arg);
                        e_or_E_func(pars, &len_add, str_add, number, from_g_gird);
                        break;
                    case 'g':
                    case 'G':pf.specifier = (int) *format;
                        number = subst_input(pars, arg);
                        g_or_G_func(pars, &len_add, str_add, number);
                        break;
                    case 'p':pf.specifier = 'p';
                        p_func(pars, arg, &len_add, str_add);
                        break;
                    case 's':pf.specifier = 's';
                        s_func(pars, arg, &len_add, str_add);
                        flag = 0;
                        break;
                }
                s21_memmove(str + length, str_add, len_add);
                length += len_add;
                int len = 0;
                form_number(format, &len, &pf);
                format = format + len;
                format++;
            }
        } else {
            *(str + length) = *format;
            length++;
            format++;
            continue;
        }
    }
    *(str + length) = '\0';
    va_end(arg);
    free(str_add);
    return length;
}

#ifdef DEV
#include <stdio.h>
#include <string.h>

void leaks(){
    //char dest[50];
    /*s21_memchr("qweqweqw", 6, 5);*/
    //s21_memcpy(dest, "qweqweqweq", 6);
    //s21_memmove(dest, "qweqweqweq", 6);
    //s21_memset(dest, 1, 10);
    //s21_strcat(dest, "12");
    //s21_strncat(dest, "000", 50);
    //s21_strchr("123124", 3);
    //s21_memcmp("qweqweqq", "rtertet", 10);
    //s21_strcmp("qweqweq", "ererer");
    //s21_strncmp("qweqwe", "tgtbr", 10);
    //char *r = s21_to_upper("qweqweqwe");
    //free(r);
    //char *l = (char*)s21_to_lower("qweqsda");
    //free(l);
    //char* i = s21_insert("qweqweq", "qweqweq", 2);
    //free(i);
    //s21_trim("   qqwe", "qweq ");
    //s21_itoa(4, dest);
    //s21_strpbrk("qweqweq", "sdsdsd");
    //s21_strrchr("qweqweq", 10);
    //s21_strstr("qweqeqe", "fvvbgg");
    //s21_strtok("a.b.c.d.e.d.f.g.h.", ".");
    //s21_strtok(NULL, ".");
    //s21_strtok(NULL, ".");
    //s21_strtok(NULL, ".");
    //s21_strtok(NULL, ".");
    //s21_strtok(NULL, ".");
    //s21_strtok(NULL, ".");
    //s21_strtok(NULL, ".");
    //s21_strspn("qweqeq", "wqwqwqwqw");
    //s21_strerror(1);
    //s21_strlen("hgdfjkghdkj");
    //s21_strcpy(dest, "qweqweq");
    //s21_strncpy(dest, "1231wq", 3);
    //s21_strcspn("qweqweqe", "ofjfdifdi");
}

int main() {
    //char a[50];
    //strcpy(a,"a.b.c.d.e.d.f.g.h.");
    //char* b = s21_strtok(a, ".");
    //puts(b);
    //b = s21_strtok(NULL, ".");
    //puts(b);
    //b = s21_strtok(NULL, ".");
    //puts(b);
    //b = s21_strtok(NULL, ".");
    //puts(b);
    //b = s21_strtok(NULL, ".");
    //puts(b);
    //b = s21_strtok(NULL, ".");
    //puts(b);
    //b = s21_strtok(NULL, ".");
    //puts(b);
    //b = s21_strtok(NULL, ".");
    //puts(b);
    //strcpy(a,"a.b.c.d.e.d.f.g.h.");
    //char* c = strtok(a, ".");
    //puts(c);
    //c = strtok(NULL, ".");
    //puts(c);
    //c = strtok(NULL, ".");
    //puts(c);
    //c = strtok(NULL, ".");
    //puts(c);
    //c = strtok(NULL, ".");
    //puts(c);
    //c = strtok(NULL, ".");
    //puts(c);
    //c = strtok(NULL, ".");
    //puts(c);
    //c = strtok(NULL, ".");
    //puts(c);
    char st[50];
    s21_sprintf(st,"% d",15);
    puts(st);

}
#endif