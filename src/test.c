#include <stdio.h>
#include <string.h>
#include "s21_string.h"

int main(void) {
	s21_size_t p;
	char *tested = "this is a test";
	char *a = "shit ";
	p = strspn(tested,a);
	printf("%zu\n", p);


	p = s21_strspn(tested, a);
	printf("%zu", p);

	return 0;
}