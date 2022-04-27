#include "s21_string.h"

s21_size_t s21_strspn(const char *str1, const char *str2) {
	s21_size_t retval = 0;
	if (*str1 == '\0' || *str2 == '\0') {
		retval = 0;
	} else {
		for (char *s1 = (char *) str1; s1 != NULL; s1++) {
			for (char *s2 = (char *) str2; s2 != NULL; s2++) {
				if (*s1 == *s2) {
					s2 = (char *) str2 - 1;
					s1++;
				} else if (*s2 == '\0' || *s1 == '\0') {
					retval = s1 - str1;
				}
			}
		}
	}
	return retval;
}



