#include "s21_string.h"

void *to_lower(const char *str) {
    s21_size_t len = s21_strlen(str);
    char *result = malloc(len*sizeof(char));
    if (result == S21_NULL) {
        return S21_NULL; }
    s21_strcpy(result, str);
    for (int i=0; i<len; i++) {
        if (str[i] >= 65 && str[i] <= 90)
            result[i] = str[i] + 32;
        else
            result[i] = str[i];
    }
    return result;
}
