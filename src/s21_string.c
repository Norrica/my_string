//
// Created by Gladis Ariane on 4/28/22.
//

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
		result = NULL;
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
	for (int i = 0; str[i] != '\0'; ++i) {
		if (str[i] == c) {
			return (char *) &str[i];
		}
	}
	return NULL;
}

char *s21_strpbrk(const char *str1, const char *str2) {
	while (*str1)
		if (s21_strchr(str2, *str1++))
			return (char *) --str1;
	return 0;
}

s21_size_t s21_strspn(const char *str1, const char *str2) {
	if (*str1 == '\0' || *str2 == '\0') {
		return 0;
	}
	for (char *s1 = (char *) str1; s1 != NULL; s1++) {
		for (char *s2 = (char *) str2; s2 != NULL; s2++) {
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

char *s21_strstr(const char *str, const char *substr) {
	const char *a = str, *b = substr;
	while (1) {
		if (!*b) return (char *) str;
		if (!*a) return NULL;
		if (*a++ != *b++) {
			a = ++str;
			b = substr;
		}
	}
}