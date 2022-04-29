#include "s21_string.h"

void *to_upper(const char *str) {
    s21_size_t len = s21_strlen(str);
    char *result = malloc(len*sizeof(char));
    if (result == S21_NULL) {
        return S21_NULL; }
    s21_strcpy(result, str);
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
