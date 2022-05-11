#include <stdarg.h>
#include <math.h>
#include <ctype.h>
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

//TODO проверить
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

//TODO проверить
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

//TODO проверить
size s21_strspn(const char *str1, const char *str2) {
    size_t res = 0;
    while (*str1 && s21_strchr(str2, *str1++)) {
        res++;
    }
    return res;
}

//TODO проверить
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

//char *s21_strtok(char *str, const char *delim) {
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
#if defined(__APPLE__) && (__MACH__)
    static char *str[] =
        {"Undefined error: 0",
         "Operation not permitted",
         "No such file or directory",
         "No such process", "Interrupted system call",
         "Input/output error", "Device not configured",
         "Argument list too long", "Exec format error",
         "Bad file descriptor", "No child processes", "Resource deadlock avoided",
         "Cannot allocate memory", "Permission denied", "Bad address",
         "Block device required",
         "Resource busy", "File exists", "Cross-device link",
         "Operation not supported by device",
         "Not a directory", "Is a directory", "Invalid argument",
         "Too many open files in system",
         "Too many open files", "Inappropriate ioctl for device",
         "Text file busy", "File too large",
         "No space left on device", "Illegal seek", "Read-only file system",
         "Too many links", "Broken pipe", "Numerical argument out of domain",
         "Result too large", "Resource temporarily unavailable",
         "Operation now in progress", "Operation already in progress",
         "Socket operation on non-socket", "Destination address required",
         "Message too long", "Protocol wrong type for socket",
         "Protocol not available", "Protocol not supported",
         "Socket type not supported", "Operation not supported",
         "Protocol family not supported",
         "Address family not supported by protocol family",
         "Address already in use", "Can't assign requested address",
         "Network is down", "Network is unreachable",
         "Network dropped connection on reset",
         "Software caused connection abort",
         "Connection reset by peer", "No buffer space available",
         "Socket is already connected", "Socket is not connected",
         "Can't send after socket shutdown", "Too many references: can't splice",
         "Operation timed out", "Connection refused", "Too many levels of symbolic links",
         "File name too long", "Host is down", "No route to host", "Directory not empty",
         "Too many processes", "Too many users", "Disc quota exceeded",
         "Stale NFS file handle",
         "Too many levels of remote in path", "RPC struct is bad", "RPC version wrong",
         "RPC prog. not avail", "Program version wrong", "Bad procedure for program",
         "No locks available", "Function not implemented",
         "Inappropriate file type or format",
         "Authentication error",
         "Need authenticator", "Device power is off", "Device error",
         "Value too large to be stored in data type",
         "Bad executable (or shared library)",
         "Bad CPU type in executable", "Shared library version mismatch",
         "Malformed Mach-o file", "Operation canceled", "Identifier removed",
         "No message of desired type", "Illegal byte sequence",
         "Attribute not found", "Bad message", "EMULTIHOP (Reserved)",
         "No message available on STREAM", "ENOLINK (Reserved)",
         "No STREAM resources", "Not a STREAM", "Protocol error",
         "STREAM ioctl timeout", "Operation not supported on socket", "Policy not found",
         "State not recoverable", "Previous owner died", "Interface output queue is full"};
#else
    static char *str[] ={ "Success", "Operation not permitted", "No such file or directory",
      "No such process", "Interrupted system call", "Input/output error",
      "No such device or address", "Argument list too long", "Exec format error",
      "Bad file descriptor", "No child processes", "Resource temporarily unavailable",
      "Cannot allocate memory", "Permission denied", "Bad address", "Block device required",
      "Device or resource busy", "File exists", "Invalid cross-device link", "No such device",
      "Not a directory", "Is a directory", "Invalid argument", "Too many open files in system",
      "Too many open files", "Inappropriate ioctl for device", "Text file busy", "File too large",
      "No space left on device", "Illegal seek", "Read-only file system", "Too many links",
      "Broken pipe", "Numerical argument out of domain", "Numerical result out of range",
      "Resource deadlock avoided", "File name too long", "No locks available",
      "Function not implemented", "Directory not empty", "Too many levels of symbolic links",
      "Unknown error 41", "No message of desired type", "Identifier removed",
      "Channel number out of range", "Level 2 not synchronized", "Level 3 halted",
      "Level 3 reset", "Link number out of range", "Protocol driver not attached",
      "No CSI structure available", "Level 2 halted", "Invalid exchange",
      "Invalid request descriptor", "Exchange full", "No anode", "Invalid request code",
      "Invalid slot", "Unknown error 58", "Bad font file format", "Device not a stream",
      "No data available", "Timer expired", "Out of streams resources",
      "Machine is not on the network", "Package not installed", "Object is remote",
      "Link has been severed", "Advertise error", "Srmount error", "Communication error on send",
      "Protocol error", "Multihop attempted", "RFS specific error", "Bad message",
      "Value too large for defined data type", "Name not unique on network",
      "File descriptor in bad state",
      "Remote address changed", "Can not access a needed shared library",
      "Accessing a corrupted shared library",
      ".lib section in a.out corrupted", "Attempting to link in too many shared libraries",
      "Cannot exec a shared library directly", "Invalid or incomplete multibyte or wide character",
      "Interrupted system call should be restarted", "Streams pipe error", "Too many users",
      "Socket operation on non-socket", "Destination address required",
      "Message too long", "Protocol wrong type for socket",
      "Protocol not available", "Protocol not supported",
      "Socket type not supported", "Operation not supported",
      "Protocol family not supported", "Address family not supported by protocol",
      "Address already in use", "Cannot assign requested address",
      "Network is down", "Network is unreachable", "Network dropped connection on reset",
      "Software caused connection abort", "Connection reset by peer", "No buffer space available",
      "Transport endpoint is already connected", "Transport endpoint is not connected",
      "Cannot send after transport endpoint shutdown", "Too many references: cannot splice",
      "Connection timed out", "Connection refused", "Host is down", "No route to host",
      "Operation already in progress", "Operation now in progress", "Stale file handle",
      "Structure needs cleaning", "Not a XENIX named type file",
      "No XENIX semaphores available", "Is a named type file",
      "Remote I/O error", "Disk quota exceeded", "No medium found",
      "Wrong medium type", "Operation canceled", "Required key not available",
      "Key has expired", "Key has been revoked", "Key was rejected by service",
      "Owner died", "State not recoverable", "Operation not possible due to RF-kill",
      "Memory page has hardware error" }
#endif
    int max;
    char error[4096] = {'\0'};
    char stt[10];
    static char string[4096] = {'\0'};
    for (int i = 0; i < 4096; i++) string[i] = '\0';
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
    s21_strcat(string, error);
    return string;
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
    int i = 0, start_n = -1, temp = 0;
    if (src != S21_NULL) {
        int len = s21_strlen(src);
        int last_n = len;
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
        i = 0;
        result = (char *) calloc(1, sizeof(char *));
        for (int j = start_n + 1; j < last_n; j++) {
            result = (char *) realloc(result, (temp + 2) * sizeof(char *));
            result[temp] = src[j];
            temp++;
        }
        result[temp] = '\0';
    }
    return result;
}




//int my_atoi(const char *c) {
//    char *ch = (char *) c;
//    int res = 0, sign = 1;
//    while (*ch == ' ') {
//        ch++;
//    }
//    if (*ch == '-' || *ch == '+') {
//        sign = 1 - 2 * (*ch++ == '-');
//    }
//    while (*ch != '\0') {
//        if (*ch >= '0' && *ch <= '9')
//            res = res * 10 + *ch++ - '0';
//        else
//            break;
//    }
//    return res * sign;
//}
//
//double my_atof(const char *c) {
//    char *ch = (char *) c;
//    int start_position = 0, sign = 1, dot_position = 0;
//    /*удалить пробелы*/
//    for (int i = 0; ch[i] != '\0'; i++) {
//        if (ch[i] == ' ')
//            start_position++;
//    }
//
//    /*проверить положительное или отрицательное*/
//    if (ch[start_position] == '-' || ch[start_position] == '+') {
//        sign = 1 - 2 * (ch[start_position] == '-');
//        start_position++;
//    }
//
//    /*найти точку - разделитель*/
//    for (int i = start_position; ch[i] != '\0'; i++) {
//        if (ch[i] == '.') {
//            dot_position = i;
//            break;
//        }
//    }
//
//    /*если нет нуля*/
//    if (!dot_position) {
//        return my_atoi(c);
//    } else {
//        /*если есть нуль, то подсчитать int*/
//        double integer_part = 0;
//        for (int i = start_position;
//             i < dot_position &&
//                 ch[i] != '\0' &&
//                 ch[i] >= '0' &&
//                 ch[i] <= '9';
//             i++, start_position++) {
//            integer_part = integer_part * 10 + (ch[i] - '0');
//        }
//        if (start_position < dot_position) {
//            return integer_part;
//        }
//        /*подсчитать float*/
//        double float_part = 0;
//        for (int i = dot_position + 1;
//             ch[i] != '\0' && ch[i] >= '0' && ch[i] <= '9';
//             i++) {
//            float_part = float_part + (ch[i] - '0') * pow(10, dot_position - i);
//        }
//        return (integer_part + float_part) * sign;
//    }
//}
//

//
//char *my_ftoa(float num, int precision) {
//    int int_part = (int) num;
//    float float_part = num - int_part;
//    char *int_res = my_itoa(int_part);
//    int float_num = (float_part * pow(10, precision));
//    char *float_res = my_itoa(float_num);
//    char *res = malloc(s21_strlen(int_res) + 1 + s21_strlen(float_res));
//    s21_strcat(res, int_res);
//    s21_strcat(res, ".");
//    s21_strcat(res, float_res);
//    return res;
//}
//
////  c, d, i, f, s, u, %
////  %.5f
////  Это gbpltw
//typedef int bool;
//#define true 1;
//#define false 0;
//typedef struct {
//  int fmt_str_len; /*optional*/
//  char type_specifier; /*c, d, i, f, s, u, %*/
//  int sign; /* + - ' '*/ /* ' ' - всегда +1 пробел слева*/
//  char pad_with; /* ' ' or '0' */
//  int l_pad_len;
//  int r_pad_len;
//  int precision;
//} FMT;
//
//void init_FMT(FMT *fmt) {
//    //  *fmt = {'\0',}
//}
//char *const TYPE_SPECIFIERS = "cdifsu";
//char *const LEN_SPECIFIERS = "lh";
//char *const DIGITS = "0123456789";
//char *const PUNCTS = "+-.";
//char *const SIGNS = "+- ";
//char *const ALL_SPECIFIERS = "+-.0123456789cdifsuhl";
//
//void print(char *str) {
//    for (int i = 0; str[i] != '\0'; ++i) {
//        printf("%c", str[i]);
//    }
//    puts("");
//}
//
//typedef enum datatype { CHAR, INT1, INT2, FLOAT, STRING, UINT, ERROR = -1 }
//    datatype;
//
//char find_specifier(char *string) {
//    char *spec = s21_strpbrk(string, TYPE_SPECIFIERS);
//    //  if (spec)
//    //      return spec[0];
//    //  else
//    //      return '\0';
//    return spec[0];
//}
//
//int find_sign(char *string, size len) {
//    char sign/* = s21_strpbrk(string, SIGNS)*/;
//    /*TODO Возможен баг, что мы найдем %3d+, который не должен учитываться.*/
//    /*В следующей строке вроде без него*/
//
//    sign = string[0];
//    switch (sign) {
//        case '-':return -1;
//        case '+':
//        default:return 1;   /*Нет явно знака - '+'*/
//    }
//}
//int find_filler(char *string, size len) {
//    char filler = string[0];
//    switch (filler) {
//        case '0':return 0; /*Надо заполнять нулями*/
//        case ' ':return 1;/*Заполнять пробелами*/
//        default:return -1;
//    }
//}
//int find_length(char *string, size len) {
//    char *var_len = s21_strpbrk(string, SIGNS);
//    if (var_len) {
//        switch (var_len[0]) {
//            case 'l':return 1;
//            case 'h':return -1;
//        }
//    }
//    return 0;
//}
//
//int find_width(char *string, size len) {
//    /* Найти все символы от + и/или 0(если они есть) до . (если она есть) */
//    /*Вернуть atoi(символов)*/
//    /*Учесть что передается len и за длину формат-строки(от % до d) не заходить*/
//}
//int find_precision(char *string, size len) {
//    /*Аналогично предыдущему, от . до d/f*/
//}
//
///* % 12.5f*/
//int s21_sprintf(char *str, char *fmt, ...) {
//    /*TODO padding*/
//    va_list args;
//    va_start(args, fmt);
//    int va_len = 0;
//    for (size i = 0; i < s21_strlen(fmt); ++i) {
//        if (fmt[i] == '%') {
//            if (fmt[i + 1] != '%')
//                va_len++;
//            else
//                ++i;
//        }
//    }
//    /*s21_size_t is_float;*/
//    /*s21_size_t curr = 0;*/
//    FMT curr_fmt;
//    for (size i = 0; i < s21_strlen(fmt); ++i) {
//        if (fmt[i] == '%' && fmt[i + 1] != '%') {
//            char datatype = find_specifier(&fmt[i] + 1);
//            if (datatype == '\0') {
//                return ERROR;
//            }
//            size format_len = s21_strchr(fmt, datatype) - &fmt[i]; /*if len NULL - return error*/
//            int sign = find_sign(&fmt[i] + 1, format_len);
//            if (sign == -10) return ERROR;
//            int length = find_length(&fmt[i] + 1, format_len);
//            int width = find_width(&fmt[i] + 1, format_len);
//        } else {
//            str[i] = fmt[i];
//        }
//    }
//    return 0; /*TODO remove*/
//}

#ifdef DEVstring
#include <string.h>
#include <stdio.h>

int main() {
    //  printf("%s %d",__FILE__, __LINE__);
    char str[50];
    char *fmt = "%+0123.5dd";
    //  puts("");
    float o = 50;
    for (int i = 0; i < 10; ++i) {
        o/=10;
    }
    printf("%.10f\n", o);
    printf("%100.10d", 5);
}
#endif
