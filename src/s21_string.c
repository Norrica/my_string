//
// Created by Gladis Ariane on 4/28/22.
//

#include <stdarg.h>
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
	const char *s1 = str1, *s2 = str2;
	while (n--) {
		if (*s1++ != *s2++) {
			result = *--s1 - *--s2;
			break;
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
	//if (s21_strlen(dest) < s21_strlen(src)) {
	//	return S21_NULL;
	//}
	char *d = dest;
	char *s = (char *) src;
	for (; *d || *s; d++, s++) {
		*d = *s;
	}
	return dest;
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
	char *d = dest;
	char *s = (char *) src;
	for (; (*d || *s) && n; d++, s++, n--) {
		*d = *s;
	}
	return dest;
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
	char *p = (char *) str;
	while (*p != c && *p != '\0')
		p++;
	if (*p) {
		return p;
	} else {
		return S21_NULL;
	}
}

char *s21_strrchr(const char *str, int c) {
	char *res = S21_NULL;
	for (int i = 0; str[i] != '\0'; ++i) {
		if (str[i] == c) {
			res = (char *) &str[i];
		}
	}
	return res;
}

char *s21_strpbrk(const char *str1, const char *str2) {
	while (*str1)
		if (s21_strchr(str2, *str1++))
			return (char *) --str1;
	return 0;
}

s21_size_t s21_strspn(const char *str1, const char *str2) {
	if (str1 == S21_NULL || str2 == S21_NULL
		|| *str1 == '\0' || *str2 == '\0') {
		return 0;
	}

	for (char *s1 = (char *) str1; s1 != S21_NULL; s1++) {
		for (char *s2 = (char *) str2; s2 != S21_NULL; s2++) {
			if (*s1 == *s2) {
				s2 = (char *) str2 - 1;
				s1++;
			} else if (*s2 == '\0' || *s1 == '\0') {
				return s1 - str1;
			}
		}
	}
	return 0;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
	if (*str1 == '\0') {
		return 0;
	} else if (*str2 == '\0') {
		return s21_strlen(str1);
	} else {
		char *s1 = (char *) str1;
		char *s2 = (char *) str2;
		while (*s1 != '\0') {
			if (*s1 == *s2++) {
				return s1 - str1;
			} else if (*s2 == '\0') {
				s2 = (char *) str2;
				s1++;
			}
		}
		return s21_strlen(str1);
	}
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

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
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

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
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

s21_size_t s21_strlen(const char *str) {
	s21_size_t len = 0;
	for (; str[len]; len++);
	return len;
}

char *s21_strtok(char *str, const char *delim) {
	static char *current;
	char *result;
	if (str != S21_NULL) {
		/*remove delims from start*/
		str = &str[s21_strspn(str, delim)];
		s21_size_t first = s21_strspn(str, delim);
		s21_size_t second = s21_strcspn(str, delim);
		if (second == s21_strlen(str) || first == s21_strlen(str)) {
			if (current != NULL)
				return str;
			else
				return S21_NULL;
		}
		current = &str[second] + 1;
		result = malloc((first + second) * sizeof(char));
		for (s21_size_t i = first; i < second; ++i) {
			result[i - first] = str[i];
		}
		result[first + second] = '\0';
		str[second] = '\0';
		return result;
	} else {
		if (current == NULL || current[0] == '\0') {
			return S21_NULL;
		} else {
			result = s21_strtok(current, delim);
			current = &current[s21_strspn(current, result)];
			return result;
		}
	}
}

char *s21_strerror(int errnum) {
	char *errors[107] = {
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
	if (errnum > 106 || errnum < 0) {
		return "Unknown error: ";
	}
	return errors[errnum];
}

void *insert(char *dest, char *src, int x) {
	char *res;
	res = (char *) malloc(s21_strlen(dest) + s21_strlen(src) + 1);
	s21_strncpy(res, dest, x);
	res[x] = '\0';
	s21_strcat(res, src);
	s21_strcat(res, dest + x);
	s21_strcpy(dest, res); //Удалить если не понадобится
	//free(res);
	return res;
}

char *str_replace(char *orig, char *rep, char *with) {
	char *result;
	char *ins;
	char *tmp;
	s21_size_t len_rep;
	s21_size_t len_with;

	int count;

	if (!orig || !rep)
		return NULL;
	len_rep = s21_strlen(rep);
	if (len_rep == 0)
		return NULL;
	if (!with)
		with = "";
	len_with = s21_strlen(with);

	ins = orig;
	for (count = 0; (tmp = s21_strstr(ins, rep)); ++count) {
		ins = tmp + len_rep;
	}
	tmp = result = malloc(s21_strlen(orig) + (len_with - len_rep) * count + 1);
	if (!result)
		return NULL;

	while (count--) {
		size_t len_front;
		ins = s21_strstr(orig, rep);
		len_front = ins - orig;
		tmp = s21_strncpy(tmp, orig, len_front) + len_front;
		tmp = s21_strcpy(tmp, with) + len_with;
		orig += len_front + len_rep;
	}
	s21_strcpy(tmp, orig);
	return result;
}
//Нужно для sprintf:
//void swap(char *x, char *y) {
//	char t = *x; *x = *y; *y = t;
//}
//
//// Function to reverse `buffer[i…j]`
//char* reverse(char *buffer, int i, int j)
//{
//	while (i < j) {
//		swap(&buffer[i++], &buffer[j--]);
//	}
//
//	return buffer;
//}
//char* itoa(int value, char* buffer, int base)
//{
//	// invalid input
//	if (base < 2 || base > 32) {
//		return buffer;
//	}
//
//	// consider the absolute value of the number
//	int n = abs(value);
//
//	int i = 0;
//	while (n)
//	{
//		int r = n % base;
//
//		if (r >= 10) {
//			buffer[i++] = 65 + (r - 10);
//		}
//		else {
//			buffer[i++] = 48 + r;
//		}
//
//		n = n / base;
//	}
//
//	// if the number is 0
//	if (i == 0) {
//		buffer[i++] = '0';
//	}
//
//	// If the base is 10 and the value is negative, the resulting string
//	// is preceded with a minus sign (-)
//	// With any other base, value is always considered unsigned
//	if (value < 0 && base == 10) {
//		buffer[i++] = '-';
//	}
//
//	buffer[i] = '\0'; // null terminate string
//
//	// reverse the string and return it
//	return reverse(buffer, 0, i - 1);
//}
//c, d, i, f, s, u, %
//%.5f
//Это gbpltw
//int s21_sprintf(char *str, char *fmt, ...) {
//	va_list args;
//	va_start(args, fmt);
//	int va_len = 0;
//	int va_curr = 0;
//	for (s21_size_t i = 0; i < s21_strlen(fmt); ++i) {
//		if (fmt[i] == '%') {
//			va_len++;
//		}
//	}
//
//	for (s21_size_t i = 0; i < s21_strlen(fmt); ++i) {
//		if (fmt[i] == '%') {
//			if (fmt[i + 1] == 'd' || fmt[i + 1] == 'i' || fmt[i + 1] == 'u') {
//				int next = va_arg(args,int);
//				str_replace(fmt, "%5d");//
//				str_replace(fmt, "%432d");//
//			}
//		}
//	}
//}
