#include "s21_string.h"

void *memset(void *str, int c, size_t n) {
	char *s = str;
	while (n--) {
		*s++ = (char) c;
	}
	return str;
}
