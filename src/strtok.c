#include "s21_string.h"
#include <string.h>

char *s21_strtok(char *str, const char *delim) {
    s21_size_t len = s21_strlen(str);
    //char *result = malloc(len*sizeof(char));
    for (int i = 0; str[i] != '\0'; i++) {


}

int main() {
    char a[100] = "cccab=cccefgc";
    char *c;
    *c = 'c-=/';
    s21_strtok(a, c);
}
