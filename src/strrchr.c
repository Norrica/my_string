/*
The strrchr function returns a pointer to the located character, 
or a null pointer if the character does not occur in the string.
--------------------------------------------
int len;
const char str[] = "http://www.tutorialspoint.com";
const char ch = '.';
char *ret;

ret = strrchr(str, ch);

printf("String after |%c| is - |%s|\n", ch, ret);
--------------------------------------------
>> String after |.| is - |.com|
*/

#include "s21_string.h"

char *s21_strchr(const char *str, int c) {
	
}