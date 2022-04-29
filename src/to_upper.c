#include "s21_string.h"

void *to_upper(const char *str) {
    char *result = (char*)str;
    if (s21_strlen(str) == 0) {
        result = S21_NULL;
    } else { 
        for (int i=0; str[i]!= '\0'; i++)
            if (str[i] >= 97 && str[i] <= 122)
                result[i] = str[i] - 32;
            else
                result[i] = str[i];
        return result;
    }
}

int main() {
    char c[100] = "12312Eegoroerwe";
    printf("%s", to_upper(c));
}
