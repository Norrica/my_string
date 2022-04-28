#include <string.h>
#include "s21_string.h"

char *s21_strcpy(char *dest, const char *src) {
	if (s21_strlen(dest) < s21_strlen(src)) {
		return NULL;
	}
	char *d = dest;
	char *s = (char *) src;
	for (; *d || *s; d++, s++) {
		*d = *s;
	}
	return dest;
}