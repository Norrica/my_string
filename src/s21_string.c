//
// Created by Gladis Ariane on 4/28/22.
//

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
        result = S21_NULL;
    return result;
}

int s21_memcmp(const void *str1, const void *str2, size_t n) {
    int result = 0;
    const char *s1 = str1, *s2 = str2;
    while (n--) {
        if (*s1++ != *s2++) {
            result = *--s1 - *--s2;
            break;
        }
    }
    return result;
}

void *s21_memcpy(void *dest, const void *src, size_t n) {
    char *d = dest;
    const char *s = src;
    while (n--)
        *d++ = *s++;
    return dest;
}

char *s21_strcpy(char *dest, const char *src) {
    //if (s21_strlen(dest) < s21_strlen(src)) {
    //	return S21_NULL;
    //}
    char *d = dest;
    char *s = (char *) src;
    for (; *d || *s; d++, s++) {
        *d = *s;
    }
    return dest;
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
    char *d = dest;
    char *s = (char *) src;
    for (; (*d || *s) && n; d++, s++, n--) {
        *d = *s;
    }
    return dest;
}

void *s21_memmove(void *dest, const void *src, size_t n) {
    char *d = dest;
    const char *s = src;
    if (d < s) {
        while (n--)
            *d++ = *s++;
    } else {
        char *lasts = (char *) s + (n - 1);
        char *lastd = d + (n - 1);
        while (n--)
            *lastd-- = *lasts--;
    }
    return dest;
}

void *s21_memset(void *str, int c, size_t n) {
    char *s = str;
    while (n--) {
        *s++ = (char) c;
    }
    return str;
}

char *s21_strchr(const char *str, int c) {
    char *p = (char *) str;
    while (*p != c && *p != '\0')
        p++;
    if (*p) {
        return p;
    } else {
        return S21_NULL;
    }
}

char *s21_strrchr(const char *str, int c) {
    char *res = S21_NULL;
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == c) {
            res = (char *) &str[i];
        }
    }
    return res;
}

char *s21_strpbrk(const char *str1, const char *str2) {
    while (*str1)
        if (s21_strchr(str2, *str1++))
            return (char *) --str1;
    return 0;
}

s21_size_t s21_strspn(const char *str1, const char *str2) {
    if (*str1 == '\0' || *str2 == '\0') {
        return 0;
    }
    for (char *s1 = (char *) str1; s1 != S21_NULL; s1++) {
        for (char *s2 = (char *) str2; s2 != S21_NULL; s2++) {
            if (*s1 == *s2) {
                s2 = (char *) str2 - 1;
                s1++;
            } else if (*s2 == '\0' || *s1 == '\0') {
                return s1 - str1;
            }
        }
    }
    return 0;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
    if (*str1 == '\0') {
        return 0;
    } else if (*str2 == '\0') {
        return s21_strlen(str1);
    } else {
        // TODO
        return 0;
    }
}

char *s21_strstr(const char *str, const char *substr) {
    const char *a = str, *b = substr;
    while (1) {
        if (!*b) return (char *) str;
        if (!*a) return S21_NULL;
        if (*a++ != *b++) {
            a = ++str;
            b = substr;
        }
    }
}

char *s21_strcat(char *dest, const char *src) {
    if ((dest == S21_NULL) && (src == S21_NULL))
        return S21_NULL;
    char *start = dest;
    while (*start != '\0') {
        start++;
    }
    while (*src != '\0') {
        *start++ = *src++;
    }
    *start = '\0';
    return dest;
}

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
    char *ptr = dest;
    while (*ptr != '\0')
        ptr++;
    while (*src != '\0' && n--) {
        *ptr++ = *src++;
    }
    *ptr++ = '\0';
    return dest;
}

// TODO
int s21_strcmp(const char *str1, const char *str2) {
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return *(const unsigned char *) str1 - *(const unsigned char *) str2;
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
    int result;
    while (n && *str1 && (*str1 == *str2)) {
        str1++;
        str2++;
        n--;
    }
    if (n == 0)
        result = 0;
    else
        result = *(unsigned char *) str1 - *(unsigned char *) str2;
    return result;
}

s21_size_t s21_strlen(const char *str) {
    s21_size_t len = 0;
    for (; str[len]; len++);
    return len;
}

//int main() {
////#include <string.h>
////
////#define N_TESTS 16
////	char *a[N_TESTS][2] = {
////		{"this is a test", "hits"},
////		{"this is a test", "hits "},
////		{"ololo", "ol"},
////		{"ololo", "lo"},
////		{"ololo", "l"},
////		{"ololo", "o"},
////		{"", ""},
////		{" ", " "},
////		{"   ", " "},
////		{"a", ""},
////		{"", "a"},
////		{"ba", "a"},
////		{"ba", "ab"},
////		{"ab", "ba"},
////		{"abababa", "ba"},
////		{"ababcaba", "ba"},
////	};
////	for (int i = 0; i < N_TESTS; ++i) {
////		printf("[%s] : [%s]\n", a[i][0], a[i][1]);
////		printf("%lu:%lu\n",
////			   strcspn(a[i][0], a[i][1]), s21_strcspn(a[i][0], a[i][1]));
////	}
//#include <string.h>
//	//{"this is a test", "hits"}
//	char *str_1 = "this is a test";
//	char *charset = " ";
//	printf("%lu\n", strcspn(str_1, charset));
//	printf("%lu\n", s21_strcspn(str_1, charset));
//}

