#include "s21_string.h"

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
