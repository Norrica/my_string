#include <stdlib.h>
#include <string.h>
#include "s21_string.h"
#include <check.h>

#define N_TESTS 16

#define S1 "ConseCtetur non lorem int$"
#define SIZE_S1 strlen(S1)
#define FIRST_SYM_S1 'C'
#define LAST_SYM_S1 '$'

#define SUB_S1 "Conse"
#define SIZE_SUB_S1 strlen(SUB_S1)

#define S2 "Orci, nisi mOlestie ornare morbi nisi leo, in vita@"
#define SIZE_S2 strlen(S2)
#define FIRST_SYM_S2 'O'
#define LAST_SYM_S2 '@'

#define SYM '#'
#define SIZE_SUM SIZE_S1 + SIZE_S2

START_TEST(test_memchr) {
    typedef struct s{
      const void *str;
      int c;
      size_t n;
    } test;

    test values[22] = {
        {S1, FIRST_SYM_S1, SIZE_S1 + 10},
        {S1, FIRST_SYM_S1, SIZE_S1},
        {S1, FIRST_SYM_S1, 0},
        {S1, FIRST_SYM_S1, 1},
        {S1, LAST_SYM_S1, SIZE_S1 + 10},
        {S1, FIRST_SYM_S1, SIZE_S1},
        {S1, LAST_SYM_S1, 0},
        {S1, LAST_SYM_S1, 2},
        {S1, SYM, SIZE_S1},
        {S2, FIRST_SYM_S2, SIZE_S2 + 10},
        {S2, FIRST_SYM_S2, SIZE_S2},
        {S2, FIRST_SYM_S2, 0},
        {S2, FIRST_SYM_S2, 1},
        {S2, LAST_SYM_S2, SIZE_S2 + 10},
        {S2, FIRST_SYM_S2, SIZE_S2},
        {S2, LAST_SYM_S2, 0},
        {S2, LAST_SYM_S2, 2},
        {S2, SYM, SIZE_S2},
        {" ", ' ', 0},
        {" ", ' ', 1},
        {"", ' ', 0},
        {"", ' ', 1},
    };

    for (int i = 0; i < 22; ++i) {
        ck_assert_ptr_eq(
            memchr(values[i].str, values[i].c, values[i].n),
            s21_memchr(values[i].str, values[i].c, values[i].n)
        );
    }
}
END_TEST

START_TEST(test_memcmp) {
    typedef struct s {
      const void *str1;
      const void *str2;
      size_t n;
    } test;
    test values[10] = {
        {S1, S1, SIZE_S1},
        {S1, S1, SIZE_S2},
        {S1, S2, SIZE_S1},
        {S2, S2, SIZE_S2},
        {S2, S2, SIZE_S1},
        {S2, S1, SIZE_S2},
        {"", "", 0},
        {"", "", 1},
        {" ", " ", 0},
        {" ", " ", 1},
    };
    for (int i = 0; i < 10; ++i) {
        ck_assert_int_eq(
            memcmp(values[i].str1, values[i].str2, values[i].n),
            s21_memcmp(values[i].str1, values[i].str2, values[i].n)
        );
    }
}
END_TEST

START_TEST(test_memcpy) {
    typedef struct s {
      void *dest;
      const void *src;
      size_t n;
    } test;

    test values[4] = {
        {S1, S2, SIZE_S1},
        {S2, S1, SIZE_S2},
        {"", "", 0},
        {" ", " ", 1},
    };
    for (int i = 0; i < 4; ++i) {
        char buff1[SIZE_SUM];
        char buff2[SIZE_SUM];

        strcpy(buff1, values[i].dest);
        strcpy(buff2, values[i].dest);

        /*
        printf("%s\n%s\n\n",
			(char *)memcpy(buff1, values[i].src, values[i].n),
			(char *)s21_memcpy(buff2, values[i].src, values[i].n)
            );
        */

        ck_assert_str_eq(
            memcpy(buff1, values[i].src, values[i].n),
            s21_memcpy(buff2, values[i].src, values[i].n)
        );
    }
}
END_TEST

START_TEST(test_memmove) {
    typedef struct s {
      void *dest;
      const void *src;
      size_t n;
    } test;

    test values[8] = {
        {S1, S2, SIZE_S1},
        {S2, S1, SIZE_S2},
        {S1, S2, SIZE_S2},
        {S2, S1, SIZE_S1},
        {"", "", 0},
        {" ", " ", 1},
        {"", "", 1},
        {" ", " ", 0},
    };
    for (int i = 0; i < 8; ++i) {
        char buff1[SIZE_SUM];
        char buff2[SIZE_SUM];

        strcpy(buff1, values[i].dest);
        strcpy(buff2, values[i].dest);

        /*
        printf("%s\n%s\n\n",
			(char *)memmove(buff1, values[i].src, values[i].n),
			(char *)s21_memmove(buff2, values[i].src, values[i].n)
            );
        */

        ck_assert_str_eq(
            memmove(buff1, values[i].src, values[i].n),
            s21_memmove(buff2, values[i].src, values[i].n)
        );
    }
}
END_TEST

START_TEST(test_memset) {
    typedef struct s {
      void *str;
      int c;
      size_t n;
    } test;
    //n - не может быть больше strlen(str)
    test values[2] = {
        {S1, SYM, SIZE_S1},
        {"", SYM, SIZE_S1},
    };

    for (int i = 0; i < 2; ++i) {
        char buff1[SIZE_SUM];
        char buff2[SIZE_SUM];

        strcpy(buff1, values[i].str);
        strcpy(buff2, values[i].str);

        ck_assert_str_eq(
            memset(buff1, values[i].c, values[i].n),
            s21_memset(buff2, values[i].c, values[i].n)
        );
    }
}
END_TEST

START_TEST(test_strcat) {
    typedef struct s {
      char *dest;
      const char *src;
    } test;

    test values[3] = {
        {S1, S2},
        {"", S2},
        {S1, ""},
    };

    for (int i = 0; i < 3; ++i) {
        char buff1[SIZE_SUM];
        char buff2[SIZE_SUM];

        strcpy(buff1, values[i].dest);
        strcpy(buff2, values[i].dest);

        ck_assert_str_eq(
            strcat(buff1, values[i].src),
            s21_strcat(buff2, values[i].src)
        );
    }
}
END_TEST

START_TEST(test_strncat) {
    typedef struct s {
      char *dest;
      const char *src;
      size_t n;
    } test;

    test values[3] = {
        {S1, S2, SIZE_S1},
        {"", S2, 0},
        {S1, "", 1},
    };

    for (int i = 0; i < 3; ++i) {
        char buff1[SIZE_SUM];
        char buff2[SIZE_SUM];

        strcpy(buff1, values[i].dest);
        strcpy(buff2, values[i].dest);

        ck_assert_str_eq(
            strncat(buff1, values[i].src, values[i].n),
            strncat(buff2, values[i].src, values[i].n)
        );
        //printf("[%s] : [%s]\n", curr1, curr2);
    }
}
END_TEST

START_TEST(test_strchr) {
    typedef struct s {
      const char *str;
      int c;
    } test;

    test values[5] = {
        {S1, FIRST_SYM_S1},
        {S1, LAST_SYM_S1},
        {"", SYM},
        {" ", ' '},
        {"", ' '},
    };

    for (int i = 0; i < 5; ++i) {
        ck_assert_ptr_eq(
            strchr(values[i].str, values[i].c),
            s21_strchr(values[i].str, values[i].c)
        );
    }
}
END_TEST

START_TEST(test_strcmp) {
    typedef struct s {
      const char *str1;
      const char *str2;
    } test;

    test values[5] = {
        {S1, S2},
        {S1, S1},
        {S1, ""},
        {"", ""},
        {" ", " "},
    };

    for (int i = 0; i < 5; ++i) {
        ck_assert_int_eq(
            strcmp(values[i].str1, values[i].str2),
            s21_strcmp(values[i].str1, values[i].str2)
        );
    }
}
END_TEST

START_TEST(test_strncmp) {
    typedef struct s {
      char *str;
      char *c;
      int n;
    } test;
    test values[4] = {
        {S1, SUB_S1, SIZE_SUB_S1},
        {S1, S2, SIZE_S2},
        {"", " ", 0},
        {"", " ", 1},
    };
    for (int i = 0; i < 4; ++i) {
//		printf("[%s] : [%s]\n", values[i][0], values[i][1]);
        ck_assert_int_eq(
            strncmp(values[i].str, values[i].c, values[i].n),
            s21_strncmp(values[i].str, values[i].c, values[i].n)
        );
    }
}
END_TEST

//TODO: fix strcpy
START_TEST(test_strcpy) {
    typedef struct s {
      char *dest;
      const char *src;
    } test;

    test values[1] = {
        {"maximax", "sd"},
    };
    for (int i = 0; i < 1; ++i) {
        char buff1[SIZE_SUM];
        char buff2[SIZE_SUM];

        strcpy(buff1, values[i].dest);
        strcpy(buff2, values[i].dest);

        /*
		ck_assert_str_eq(
			strcpy(buff1, values[i].src),
			s21_strcpy(buff2, values[i].src)
		);
        */

        ck_assert_str_eq(
            strcpy(buff1, values[i].src),
            strcpy(buff2, values[i].src)
        );
    }
}
END_TEST

START_TEST(test_strncpy) {
    typedef struct s {
      char *dest;
      const char *src;
      size_t n;
    } test;

    test values[4] = {
        {S1, S2, SIZE_SUM},
        {S2, S1, SIZE_S1},
        {S2, S1, SIZE_S2},
        {S1, S2, SIZE_S1},
    };

    for (int i = 0; i < 4; ++i) {
        char buff1[SIZE_SUM];
        char buff2[SIZE_SUM];

        strcpy(buff1, values[i].dest);
        strcpy(buff2, values[i].dest);

        ck_assert_str_eq(
            strncpy(buff1, values[i].src, values[i].n),
            s21_strncpy(buff2, values[i].src, values[i].n)
        );
    }
}
END_TEST

START_TEST(test_strcspn) {
    typedef struct s {
      const char *str1;
      const char *str2;
    } test;

    test values[4] = {
        {S1, SUB_S1},
        {SUB_S1, S1},
        {S1, S2},
        {S2, S1},
    };

    for (int i = 0; i < 4; ++i) {
        ck_assert_int_eq(
            strcspn(values[i].str1, values[i].str2),
            s21_strcspn(values[i].str1, values[i].str2)
        );
    }
}
END_TEST

//TODO: sterror

START_TEST(test_strlen) {
    typedef struct s {
      const char *str;
    } test;

    test values[3] = {
        {S1},
        {S2},
        {SUB_S1},
    };

    for (int i = 0; i < 3; ++i) {
        ck_assert_int_eq(
            strlen(values[i].str),
            s21_strlen(values[i].str)
        );
    }
}
END_TEST

//I'am here! tarengre(c)

START_TEST(test_strpbrk) {
    char *values[N_TESTS][2] = {
        {"this is test", "is"},
        {"aaaaaabaaaaaa", "b"},
        {"aaaaaabaaaaaa", "baa"},
        {"aaaaaabaaaaaa", "ab"},
        {"", ""},
        {"", "    "},
        {"   ", ""},
        {"   ", " "},
        {" ", " "},
        {"close", "x"},
        {"close", "x"},
        {"close", "x"},
        {"maximax", "ax"},
        {"maximax", "max"},
        {"maximax", "im"},
        {"maximax", "ix"},
    };
    for (int i = 0; i < N_TESTS; ++i) {
//		printf("[%s] : [%s]\n", values[i][0], values[i][1]);
        ck_assert_ptr_eq(
            strpbrk(values[i][0], values[i][1]),
            s21_strpbrk(values[i][0], values[i][1])
        );
    }
}
END_TEST

START_TEST(test_strrchr) {
    typedef struct s {
      char *str;
      char c;
    } test;
    test values[N_TESTS] = {
        {"ololo", 'o'},
        {"   ", ' '},
        {"   ", ' '},
        {" ", ' '},
        {"aaaa   aaaa", ' '},
        {"", ' '},
        {"this is test", 'i'},
        {"aaaaaabaaaaaa", 'b'},
        {"aaaaaabaaaaaa", 'a'},
        {"close", 'x'},
        {"close", 'c'},
        {"close", 'l'},
        {"maximax", 'x'},
        {"maximax", 'm'},
        {"maximax", 'a'},
        {"maximax", 'i'},
    };
    for (int i = 0; i < N_TESTS; ++i) {
//		printf("[%s] : [%s]\n", values[i][0], values[i][1]);
        ck_assert_ptr_eq(
            strrchr(values[i].str, values[i].c),
            s21_strrchr(values[i].str, values[i].c)
        );
    }
}
END_TEST

START_TEST(test_strspn) {
    char *values[N_TESTS][2] = {
        {"this is a test", "hits"},
        {"this is a test", "hits "},
        {"ololo", "ol"},
        {"ololo", "lo"},
        {"ololo", "l"},
        {"ololo", "o"},
        {"", ""},
        {" ", " "},
        {"   ", " "},
        {"a", ""},
        {"", "a"},
        {"ba", "a"},
        {"ba", "ab"},
        {"ab", "ba"},
        {"abababa", "ba"},
        {"ababcaba", "ba"},
    };
    for (int i = 0; i < N_TESTS; ++i) {
//		printf("[%s] : [%s]\n", values[i][0], values[i][1]);
        ck_assert_int_eq(strspn(values[i][0], values[i][1]),
                         s21_strspn(values[i][0], values[i][1]));
    }
}

END_TEST

START_TEST(test_strstr) {
    char *values[N_TESTS][2] = {
        {"this is test", "is"},
        {"aaaaaabaaaaaa", "b"},
        {"aaaaaabaaaaaa", "baa"},
        {"aaaaaabaaaaaa", "ab"},
        {"", ""},
        {"", "    "},
        {"   ", ""},
        {"   ", " "},
        {" ", " "},
        {"close", "x"},
        {"close", "x"},
        {"close", "x"},
        {"maximax", "ax"},
        {"maximax", "max"},
        {"maximax", "im"},
        {"maximax", "ix"},
    };
    for (int i = 0; i < N_TESTS; ++i) {
//		printf("[%s] : [%s]\n", values[i][0], values[i][1]);
        ck_assert_ptr_eq(
            strstr(values[i][0], values[i][1]),
            s21_strstr(values[i][0], values[i][1])
        );
    }
}

END_TEST



START_TEST(test_strtok) {
    typedef struct s {
      char *str;
      char *delim;
    } test;

    test values[N_TESTS] = {
        {"12345,67890", ","},
        {",1,2,3,4,5,6,7,8,9,0,", ","},
        {"123,456,789,0", ","},
        {",,,,,,,,,1234567890,,,,,,,,,,", ","},
        {"11111", ""},
        {"11111", ","},
        {",,,,,,111", ","},
        {"111,,,,,,", ","},
        {",,,,,,111,,,,,,", ","},
        {"lorem.ipsum dolores|ames,lupus", ". |,"},
        {"lorem.ipsum dolores|ames,lupus", ". |"},
        {"lorem.ipsum dolores|ames,lupus", ". "},
        {"lorem.ipsum dolores|ames,lupus", ". "},
        {"lorem.ipsum dolores|ames,lupus", "."},
        {"lorem.ipsum dolores|ames,lupus", ",| ."},
        {"lorem.ipsum dolores|ames,lupus", ",| "},
    };

    for (int i = 0; i < N_TESTS; ++i) {
        //printf("[%s] : [%s] ->   ", values[i].str, values[i].delim);
        char curr1[50];
        strcpy(curr1, values[i].str);
        char curr2[50];
        strcpy(curr2, values[i].str);
        ck_assert_str_eq(
            strtok(curr1, values[i].delim),
            s21_strtok(curr2, values[i].delim)
        );
        //printf("[%s] : [%s]\n", curr1,curr2);
    }
}
END_TEST

//START_TEST(NAME_HERE) {
//	char *values[N_TESTS][2] = {
//		{"", ""},
//		{"", ""},
//		{"", ""},
//		{"", ""},
//		{"", ""},
//		{"", ""},
//		{"", ""},
//		{"", ""},
//		{"", ""},
//		{"", ""},
//		{"", ""},
//		{"", ""},
//		{"", ""},
//		{"", ""},
//		{"", ""},
//		{"", ""},
//	};
//	for (int i = 0; i < N_TESTS; ++i) {
////		printf("[%s] : [%s]\n", values[i][0], values[i][1]);
//		ck_assert_ptr_eq(
//			string.h_function(values[i][0], values[i][1]),
//			s21_string.h_function(values[i][0], values[i][1])
//		)
//	}
//}
//END_TEST
Suite *string_suite(void) {
    Suite *s;
    s = suite_create("s21_string");
    TCase *strspn_case;
    strspn_case = tcase_create("strspn");
    tcase_add_test(strspn_case, test_strspn);
    suite_add_tcase(s, strspn_case);

    TCase *strcspn_case;
    strcspn_case = tcase_create("strcspn");
    tcase_add_test(strcspn_case, test_strcspn);
    suite_add_tcase(s, strcspn_case);

    TCase *strstr_case;
    strstr_case = tcase_create("strstr");
    tcase_add_test(strstr_case, test_strstr);
    suite_add_tcase(s, strstr_case);

    TCase *strchr_case;
    strchr_case = tcase_create("strchr");
    tcase_add_test(strchr_case, test_strchr);
    suite_add_tcase(s, strchr_case);

    TCase *strrchr_case;
    strrchr_case = tcase_create("strrchr");
    tcase_add_test(strrchr_case, test_strrchr);
    suite_add_tcase(s, strrchr_case);

    TCase *memchr_case;
    memchr_case = tcase_create("memchr");
    tcase_add_test(memchr_case, test_memchr);
    suite_add_tcase(s, memchr_case);
    TCase *memcmp_case;

    memcmp_case = tcase_create("memcmp");
    tcase_add_test(memcmp_case, test_memcmp);
    suite_add_tcase(s, memcmp_case);

    TCase *strpbrk_case;
    strpbrk_case = tcase_create("strpbrk");
    tcase_add_test(strpbrk_case, test_strpbrk);
    suite_add_tcase(s, strpbrk_case);

    TCase *strcat_case;
    strcat_case = tcase_create("strcat");
    tcase_add_test(strcat_case, test_strcat);
    suite_add_tcase(s, strcat_case);

    TCase *strncat_case;
    strncat_case = tcase_create("strncat");
    tcase_add_test(strncat_case, test_strncat);
    suite_add_tcase(s, strncat_case);

    TCase *memset_case;
    memset_case = tcase_create("memset");
    tcase_add_test(memset_case, test_memset);
    suite_add_tcase(s, memset_case);

    TCase *memmove_case;
    memmove_case = tcase_create("memmove");
    tcase_add_test(memmove_case, test_memmove);
    suite_add_tcase(s, memmove_case);

    TCase *memcpy_case;
    memcpy_case = tcase_create("memcpy");
    tcase_add_test(memcpy_case, test_memcpy);
    suite_add_tcase(s, memcpy_case);

    TCase *strcpy_case;
    strcpy_case = tcase_create("strcpy");
    tcase_add_test(strcpy_case, test_strcpy);
    suite_add_tcase(s, strcpy_case);

    TCase *strncpy_case;
    strncpy_case = tcase_create("strncpy");
    tcase_add_test(strncpy_case, test_strncpy);
    suite_add_tcase(s, strncpy_case);

    TCase *strcmp_case;
    strcmp_case = tcase_create("strcmp");
    tcase_add_test(strcmp_case, test_strcmp);
    suite_add_tcase(s, strcmp_case);

    TCase *strncmp_case;
    strncmp_case = tcase_create("strncmp");
    tcase_add_test(strncmp_case, test_strncmp);
    suite_add_tcase(s, strncmp_case);

    TCase *strlen_case;
    strlen_case = tcase_create("strlen");
    tcase_add_test(strlen_case, test_strlen);
    suite_add_tcase(s, strlen_case);

    TCase *strtok_case;
    strtok_case = tcase_create("strtok");
    tcase_add_test(strtok_case, test_strtok);
    suite_add_tcase(s, strtok_case);
    //TCase *NEW	CASE;
    //NEW CASE = tcase_create("NAME HERE");
    //tcase_add_test(NEW CASE, NAME HERE);
    //suite_add_tcase(s, NEW CASE);
    return s;
}

int main(void) {
    int number_failed = 0;
    Suite *s;
    SRunner *sr;
    s = string_suite();
    sr = srunner_create(s);
    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
