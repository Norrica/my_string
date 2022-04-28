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
