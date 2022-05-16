#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_
#include <stdlib.h>
#include <stdarg.h>

typedef unsigned long s21_size_t;
typedef s21_size_t size;
#define s21_NULL (void *)0
#if defined(__APPLE__) && (__MACH__)
#define ERRORS                                                                              \
    { "Undefined error: 0",                                                                     \
      "Operation not permitted",                                                                \
      "No such file or directory",                                                              \
      "No such process", "Interrupted system call",                                             \
      "Input/output error", "Device not configured",                                            \
      "Argument list too long", "Exec format error",                                            \
      "Bad file descriptor", "No child processes", "Resource deadlock avoided",                 \
      "Cannot allocate memory", "Permission denied", "Bad address", "Block device required",    \
      "Resource busy", "File exists", "Cross-device link", "Operation not supported by device", \
      "Not a directory", "Is a directory", "Invalid argument", "Too many open files in system", \
      "Too many open files", "Inappropriate ioctl for device",                                  \
      "Text file busy", "File too large",                                                       \
      "No space left on device", "Illegal seek", "Read-only file system",                       \
      "Too many links", "Broken pipe", "Numerical argument out of domain",                      \
      "Result too large", "Resource temporarily unavailable",                                   \
      "Operation now in progress", "Operation already in progress",                             \
      "Socket operation on non-socket", "Destination address required",                         \
      "Message too long", "Protocol wrong type for socket",                                     \
      "Protocol not available", "Protocol not supported",                                       \
      "Socket type not supported", "Operation not supported",                                   \
      "Protocol family not supported",                                                          \
      "Address family not supported by protocol family",                                        \
      "Address already in use", "Can't assign requested address",                               \
      "Network is down", "Network is unreachable",                                              \
      "Network dropped connection on reset",                                                    \
      "Software caused connection abort",                                                       \
      "Connection reset by peer", "No buffer space available",                                  \
      "Socket is already connected", "Socket is not connected",                                 \
      "Can't send after socket shutdown", "Too many references: can't splice",                  \
      "Operation timed out", "Connection refused", "Too many levels of symbolic links",         \
      "File name too long", "Host is down", "No route to host", "Directory not empty",          \
      "Too many processes", "Too many users", "Disc quota exceeded", "Stale NFS file handle",   \
      "Too many levels of remote in path", "RPC struct is bad", "RPC version wrong",            \
      "RPC prog. not avail", "Program version wrong", "Bad procedure for program",              \
      "No locks available", "Function not implemented", "Inappropriate file type or format",    \
      "Authentication error", "Need authenticator", "Device power is off", "Device error",      \
      "Value too large to be stored in data type",                                              \
      "Bad executable (or shared library)",                                                     \
      "Bad CPU type in executable", "Shared library version mismatch",                          \
      "Malformed Mach-o file", "Operation canceled", "Identifier removed",                      \
      "No message of desired type", "Illegal byte sequence",                                    \
      "Attribute not found", "Bad message", "EMULTIHOP (Reserved)",                             \
      "No message available on STREAM", "ENOLINK (Reserved)",                                   \
      "No STREAM resources", "Not a STREAM", "Protocol error",                                  \
      "STREAM ioctl timeout", "Operation not supported on socket", "Policy not found",          \
      "State not recoverable", "Previous owner died", "Interface output queue is full"}
#else
#define ERRORS                                                                                  \
    { "Success", "Operation not permitted", "No such file or directory",                            \
      "No such process", "Interrupted system call", "Input/output error",                           \
      "No such device or address", "Argument list too long", "Exec format error",                   \
      "Bad file descriptor", "No child processes", "Resource temporarily unavailable",              \
      "Cannot allocate memory", "Permission denied", "Bad address", "Block device required",        \
      "Device or resource busy", "File exists", "Invalid cross-device link", "No such device",      \
      "Not a directory", "Is a directory", "Invalid argument", "Too many open files in system",     \
      "Too many open files", "Inappropriate ioctl for device", "Text file busy", "File too large",  \
      "No space left on device", "Illegal seek", "Read-only file system", "Too many links",         \
      "Broken pipe", "Numerical argument out of domain", "Numerical result out of range",           \
      "Resource deadlock avoided", "File name too long", "No locks available",                      \
      "Function not implemented", "Directory not empty", "Too many levels of symbolic links",       \
      "Unknown error 41", "No message of desired type", "Identifier removed",                       \
      "Channel number out of range", "Level 2 not synchronized", "Level 3 halted",                  \
      "Level 3 reset", "Link number out of range", "Protocol driver not attached",                  \
      "No CSI structure available", "Level 2 halted", "Invalid exchange",                           \
      "Invalid request descriptor", "Exchange full", "No anode", "Invalid request code",            \
      "Invalid slot", "Unknown error 58", "Bad font file format", "Device not a stream",            \
      "No data available", "Timer expired", "Out of streams resources",                             \
      "Machine is not on the network", "Package not installed", "Object is remote",                 \
      "Link has been severed", "Advertise error", "Srmount error", "Communication error on send",   \
      "Protocol error", "Multihop attempted", "RFS specific error", "Bad message",                  \
      "Value too large for defined data type", "Name not unique on network",                        \
      "File descriptor in bad state",                                                               \
      "Remote address changed", "Can not access a needed shared library",                           \
      "Accessing a corrupted shared library",                                                       \
      ".lib section in a.out corrupted", "Attempting to link in too many shared libraries",         \
      "Cannot exec a shared library directly", "Invalid or incomplete multibyte or wide character", \
      "Interrupted system call should be restarted", "Streams pipe error", "Too many users",        \
      "Socket operation on non-socket", "Destination address required",                             \
      "Message too long", "Protocol wrong type for socket",                                         \
      "Protocol not available", "Protocol not supported",                                           \
      "Socket type not supported", "Operation not supported",                                       \
      "Protocol family not supported", "Address family not supported by protocol",                  \
      "Address already in use", "Cannot assign requested address",                                  \
      "Network is down", "Network is unreachable", "Network dropped connection on reset",           \
      "Software caused connection abort", "Connection reset by peer", "No buffer space available",  \
      "Transport endpoint is already connected", "Transport endpoint is not connected",             \
      "Cannot send after transport endpoint shutdown", "Too many references: cannot splice",        \
      "Connection timed out", "Connection refused", "Host is down", "No route to host",             \
      "Operation already in progress", "Operation now in progress", "Stale file handle",            \
      "Structure needs cleaning", "Not a XENIX named type file",                                    \
      "No XENIX semaphores available", "Is a named type file",                                      \
      "Remote I/O error", "Disk quota exceeded", "No medium found",                                 \
      "Wrong medium type", "Operation canceled", "Required key not available",                      \
      "Key has expired", "Key has been revoked", "Key was rejected by service",                     \
      "Owner died", "State not recoverable", "Operation not possible due to RF-kill",               \
      "Memory page has hardware error" }
#endif
void *s21_memchr(const void *str, int c, s21_size_t n);

int s21_memcmp(const void *str1, const void *str2, s21_size_t n);

void *s21_memcpy(void *dest, const void *src, s21_size_t n);

void *s21_memmove(void *dest, const void *src, s21_size_t n);

void *s21_memset(void *str, int c, s21_size_t n);

char *s21_strcat(char *dest, const char *src);

char *s21_strncat(char *dest, const char *src, s21_size_t n);

char *s21_strchr(const char *str, int c);

int s21_strcmp(const char *str1, const char *str2);

int s21_strncmp(const char *str1, const char *str2, s21_size_t n);

char *s21_strcpy(char *dest, const char *src);

char *s21_strncpy(char *dest, const char *src, s21_size_t n);

s21_size_t s21_strcspn(const char *str1, const char *str2);

char *s21_strerror(int errnum);

s21_size_t s21_strlen(const char *str);

char *s21_strpbrk(const char *str1, const char *str2);

char *s21_strrchr(const char *str, int c);

char *s21_strstr(const char *haystack, const char *needle);

char *s21_strtok(char *str, const char *delim);

s21_size_t s21_strspn(const char *str1, const char *str2);

// int my_atoi(const char *c);
//
// double my_atof(const char *c);
//
void s21_reverse(char *str, int len);

char *s21_itoa(long long n, char *str);
//
// char *my_ftoa(float num, int precision);

// char find_specifier(char *string);
//
// int s21_sprintf(char *str, char *fmt, ...);
// int s21_sprintf(char *str, char *fmt, ...);

void *s21_to_upper(const char *str);

void *s21_to_lower(const char *str);

void *s21_insert(const char *src, const char *str, s21_size_t start_index);

void *s21_trim(const char *src, const char *trim_chars);

typedef struct {
  int plus;
  int gird;
  int minus;
  int zero;
  int space;
  int leng;
  int width;
  int point;
  int precision;
  int type;
  int star;
} parsing;

typedef struct {
  int specifier;
  int flag;
  int width;
  int precision;
  int dot;
  int length;
  int star;
  int negative
} parsing_foramt;


void form_number(char *str, int *len, parsing_foramt *pf);
char sign_func_subst(long double *number, parsing_foramt pf);
int c_or_percent_func(parsing_foramt pf, va_list arg, int *len_buf, char *str);
long double subst_input(parsing_foramt pf, va_list arg);

char *s21_wchstrcat(char *dest, const wchar_t *src);
int def_number(char c);





int whole_part(long double n, int *array);
int round_number(int *buff, int len, int *buff1, int *whole);
int str_form(parsing pars, int *buff1, int whole, char c, char *str, int *len_str);
int consider_g(char *str, int *len_str, int *len, int from_g_gird);
int form_power(int power, char e, char *str, int *len_buf);
int form_number_d(parsing pars, long int number, char *str);
int consider_precision_d(parsing pars, int i, char sign, char *str, int *precision);
int format_d(parsing pars, int len, char *str, char sign, int *len_buf);
int format_x(parsing pars, int len, char *str, int *len_buf);
char sign_func_whole(long int *number, int *plus, int *space);
int consider_precision_x(parsing pars, int i, int *precision, char *str);
int s21_sprintf(char *str, char *format, ...);

int d_or_i_func(parsing pars, va_list args, int *len_buf, char *str);
int f_func(parsing pars, int *len_buf, char *str, long double number, int from_g_gird);
int u_func(parsing pars, va_list args, int *len_buf, char *str);
int n_func(va_list args, int length);
char convertTox(int value);
char convertToX(int value);
int convert(parsing pars, long unsigned num, long unsigned divider, char *data, char spec);
int x_or_X_func(parsing pars, va_list args, int *len_buf, char *str);
int e_or_E_func(parsing pars, int *len_buf, char *str, long double number, int from_g_gird);
int s_func(parsing pars, va_list args, int *len_buf, char *str);
int p_func(parsing pars, va_list args, int *len_buf, char *str);
int g_or_G_func(parsing pars, int *len_buf, char *str, long double number);
int calling_function(parsing pars, va_list args, int *len_buf, char *str_add, int length);
#endif  //  SRC_S21_STRING_H_
