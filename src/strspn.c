#include "s21_string.h"

s21_size_t s21_strspn(const char *str1, const char *str2) {
//	s21_size_t l1 = s21_strlen(str1);
//	s21_size_t l2 = s21_strlen(str2);

	for (char *s1 = (char *) str1; s1 != NULL; s1++) {
		for (char *s2 = (char *) str2; s2 != NULL; s2++) {
			if (*s1 == *s2) {
				s2 = (char *) str2 -1;
				s1++;
			} else if (*s2 == '\0') {
				return s1 - str1;
			}
		}
	}
	return 0;
//	for (s21_size_t i = 0; i < l1; ++i) {
//		for (s21_size_t j = 0; j < l2; ++j) {
//			if (str1[i] == str2[j]) {
//				j = -1;
//				i++;
//			} else if (str2[j] == '\0') {
//				return i;
//			}
//		}
//	}
//	return 0;
}



