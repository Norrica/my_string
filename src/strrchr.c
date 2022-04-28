#include <s21_string.h>

char *s21_strrchr(const char *str, int c) {
	char *res = NULL;
	for (int i = 0; str[i] != '\0'; ++i) {
		if (str[i] == c) {
			res = (char *) &str[i];
		}
	}
	return res;
}
