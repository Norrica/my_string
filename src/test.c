#include <stdlib.h>
#include <string.h>
#include "s21_string.h"
#include <check.h>

#define N_TESTS 16

START_TEST(test_strspn) {
	char *a[N_TESTS][2] = {
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
//		printf("[%s] : [%s]\n", a[i][0], a[i][1]);
		ck_assert_int_eq(strspn(a[i][0], a[i][1]),
						 s21_strspn(a[i][0], a[i][1]));
	}
}

END_TEST
START_TEST(test_strcspn) {
	char *a[N_TESTS][2] = {
		{"this is a test", "t"},
		{"this is a test", " "},
		{"ololo", "o"},
		{"ololo", "l"},
		{"ololo", "z"},
		{"", ""},
		{" ", " "},
		{" ", ""},
		{"", " "},
		{"a", ""},
		{"", "a"},
		{"ba", "a"},
		{"ba", "b"},
		{"ab", "ba"},
		{"ababcaba", "ca"},
		{"ababcaba", "ac"},
	};
	for (int i = 0; i < N_TESTS; ++i) {
		printf("[%s] : [%s]\n", a[i][0], a[i][1]);
		size_t i1 = strcspn(a[i][0], a[i][1]);
		s21_size_t i2 = s21_strcspn(a[i][0], a[i][1]);
		ck_assert_int_eq(i1, i2);
	}
}

END_TEST
START_TEST(test_strstr) {
	char *a[N_TESTS][2] = {
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
//		printf("[%s] : [%s]\n", a[i][0], a[i][1]);
		ck_assert_ptr_eq(
			strstr(a[i][0], a[i][1]),
			s21_strstr(a[i][0], a[i][1])
		);
	}
}

END_TEST
START_TEST(test_strchr) {
	typedef struct s {
	  char *str;
	  char c;
	} test;
	test a[N_TESTS] = {
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
//		printf("[%s] : [%s]\n", a[i][0], a[i][1]);
		ck_assert_ptr_eq(
			strchr(a[i].str, a[i].c),
			s21_strchr(a[i].str, a[i].c)
		);
	}
}

END_TEST
START_TEST(test_strrchr) {
	typedef struct s {
	  char *str;
	  char c;
	} test;
	test a[N_TESTS] = {
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
//		printf("[%s] : [%s]\n", a[i][0], a[i][1]);
		ck_assert_ptr_eq(
			strrchr(a[i].str, a[i].c),
			s21_strrchr(a[i].str, a[i].c)
		);
	}
}

END_TEST
START_TEST(test_strpbrk) {
	char *a[N_TESTS][2] = {
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
//		printf("[%s] : [%s]\n", a[i][0], a[i][1]);
		ck_assert_ptr_eq(
			strpbrk(a[i][0], a[i][1]),
			s21_strpbrk(a[i][0], a[i][1])
		);
	}
}

END_TEST
START_TEST(test_memchr) {
	typedef struct s {
	  char *str;
	  char c;
	  int n;
	} test;
	test a[N_TESTS] = {
		{"ololo", 'o', 1},
		{"", ' ', 1},
		{"   ", ' ', 1},
		{" ", ' ', 1},
		{"this is test", 'i', 1},
		{"aaaaaabaaaaaa", 'b', 1},
		{"aaaaaabaaaaaa", 'a', 1},
		{"aaaaaabaaaaaa", 'b', 7},
		{"aaaaaabaaaaaa", 'a', 7},
		{"close", 'x', 5},
		{"close", 'c', 3},
		{"close", 'l', 3},
		{"maximax", 'x', 1},
		{"maximax", 'm', 1},
		{"maximax", 'x', 3},
		{"maximax", 'm', 3},
	};
	for (int i = 0; i < N_TESTS; ++i) {
//		printf("[%s] : [%s]\n", a[i][0], a[i][1]);
		ck_assert_ptr_eq(
			memchr(a[i].str, a[i].c, a[i].n),
			s21_memchr(a[i].str, a[i].c, a[i].n)
		);
	}
}

END_TEST
START_TEST(test_memcmp) {
	typedef struct s {
	  char *str;
	  char *c;
	  int n;
	} test;
	test a[N_TESTS] = {
		{"this is test", "is", 1},
		{"this is test", "is", 10},
		{"abaaaaaa", "baa", 1},
		{"abaaaaaa", "baa", 3},
		{"abaaaaaa", "baa", 4},
		{"abaaaaaa", "ab", 1},
		{"", "", 1},
		{"", "    ", 1},
		{"   ", "", 1},
		{"   ", " ", 1},
		{" ", " ", 1},
		{"close", "x", 5},
		{"maximax", "ax", 7},
		{"maximax", "max", 7},
		{"maximax", "im", 7},
		{"maximax", "ix", 7},
	};
	for (int i = 0; i < N_TESTS; ++i) {
//		printf("[%s] : [%s]\n", a[i][0], a[i][1]);
		ck_assert_int_eq(
			memcmp(a[i].str, a[i].c, a[i].n),
			s21_memcmp(a[i].str, a[i].c, a[i].n)
		);
	}
}

END_TEST
START_TEST(test_memcpy) {
	typedef struct s {
	  char *str;
	  char *c;
	  int n;
	} test;
	test a[N_TESTS] = {
		{"this is test", "is", 1},
		{"this is test", "is", 10},
		{"abaaaaaa", "baa", 1},
		{"abaaaaaa", "baa", 3},
		{"abaaaaaa", "baa", 4},
		{"abaaaaaa", "ab", 1},
		{"", "", 1},
		{"", "    ", 1},
		{"   ", "", 1},
		{"   ", " ", 1},
		{" ", " ", 1},
		{"close", "x", 5},
		{"maximax", "ax", 7},
		{"maximax", "max", 7},
		{"maximax", "im", 7},
		{"maximax", "ix", 7},
	};
	for (int i = 0; i < N_TESTS; ++i) {
//		printf("[%s] : [%s]\n", a[i][0], a[i][1]);
		char s1[20];
		strcpy(s1, a[i].str);
		char s2[20];
		strcpy(s2, a[i].str);
		ck_assert_mem_eq(
			memcpy(s1, a[i].c, a[i].n),
			s21_memcpy(s2, a[i].c, a[i].n),
			strlen(s1)
		);
	}
}

END_TEST
START_TEST(test_strcpy) {
	typedef struct s {
	  char str[25];
	} test;
	test a[N_TESTS] = {
		{"this is test"},
		{"this is test"},
		{"abaaaaaa"},
		{"abaaaaaa"},
		{"abaaaaaa"},
		{"abaaaaaa"},
		{""},
		{"        "},
		{"   "},
		{"   "},
		{" "},
		{"close"},
		{"maximax"},
		{"maximax"},
		{"maximax"},
		{"maximax"},
	};
	for (int i = 0; i < N_TESTS; ++i) {
		char s1[20];
		char s2[20];
		ck_assert_mem_eq(
			strcpy(s1, a[i].str),
			s21_strcpy(s2, a[i].str),
			strlen(s1)
		);
	}
}

END_TEST

START_TEST(test_strncpy) {
	typedef struct s {
	  char str[25];
	  int n;
	} test;
	test a[N_TESTS] = {
		{"this is test", 4},
		{"this is test", 4},
		{"abaaaaaa", 4},
		{"abaaaaaa", 4},
		{"abaaaaaa", 4},
		{"abaaaaaa", 4},
		{"", 4},
		{"        ", 4},
		{"   ", 4},
		{"   ", 4},
		{" ", 4},
		{"close", 4},
		{"maximax", 4},
		{"maximax", 4},
		{"maximax", 4},
		{"maximax", 4},
	};
	for (int i = 0; i < N_TESTS; ++i) {
		char s1[20];
		char s2[20];
		ck_assert_mem_eq(
			strncpy(s1, a[i].str, a[i].n),
			s21_strncpy(s2, a[i].str, a[i].n),
			strlen(s1)
		);
	}
}

END_TEST

START_TEST(test_memmove) {
	typedef struct s {
	  char *str;
	  char *c;
	  int n;
	} test;
	test a[N_TESTS] = {
		{"this is test", "is", 1},
		{"this is test", "is", 10},
		{"abaaaaaa", "baa", 1},
		{"abaaaaaa", "baa", 3},
		{"abaaaaaa", "baa", 4},
		{"abaaaaaa", "ab", 1},
		{"", "", 1},
		{"", "    ", 1},
		{"   ", "", 1},
		{"   ", " ", 1},
		{" ", " ", 1},
		{"close", "x", 4},
		{"maximax", "ax", 4},
		{"maximax", "max", 4},
		{"maximax", "im", 4},
		{"maximax", "ix", 4},
	};
	for (int i = 0; i < N_TESTS; ++i) {
//		printf("[%s] : [%s]\n", a[i][0], a[i][1]);
		char s1[20];
		strcpy(s1, a[i].str);
		char s2[20];
		strcpy(s2, a[i].str);
		ck_assert_mem_eq(
			memmove(s1, a[i].c, a[i].n),
			s21_memmove(s2, a[i].c, a[i].n),
			strlen(s1)
		);
	}
}

END_TEST
START_TEST(test_memset) {
	typedef struct s {
	  char *str;
	  int c;
	  int n;
	} test;
	test a[N_TESTS] = {
		{"this is test", 48, 1},
		{"this is test", 48, 10},
		{"aaaaaaaa", 48, 1},
		{"aaaaaaaa", 48, 3},
		{"aaaaaaaa", 48, 4},
		{"", 48, 1},
		{"", 48, 2},
		{"   ", 48, 1},
		{"   ", 48, 3},
		{" ", 48, 1},
		{" ", 48, 1},
		{"close", 48, 5},
		{"maximax", 48, 1},
		{"maximax", 48, 1},
		{"maximax", 48, 7},
		{"maximax", 48, 4},
	};
	for (int i = 0; i < N_TESTS; ++i) {
//		printf("[%s] : [%s]\n", a[i][0], a[i][1]);
		char s1[20];
		strcpy(s1, a[i].str);
		char s2[20];
		strcpy(s2, a[i].str);
		ck_assert_mem_eq(
			memset(s1, a[i].c, a[i].n),
			s21_memset(s2, a[i].c, a[i].n),
			strlen(a[i].str)
		);
	}
}

END_TEST
START_TEST(test_strcat) {
	typedef struct s {
	  char *str;
	  char *c;
	} test;

	char dest[50] = "abc";

	test a[N_TESTS];
	for (int i = 0; i < N_TESTS; ++i) {
		a[i].str = dest;
	}
	a[0].c = " ";
	a[1].c = "";
	a[2].c = "a";
	a[3].c = "a ";
	a[4].c = " a";
	a[5].c = "ab";
	a[6].c = " ab";
	a[7].c = " ab ";
	a[8].c = "abcd";
	a[9].c = "   ";
	a[10].c = "abcdeftgh";
	a[11].c = ".a.b";
	a[12].c = "a/a/a";
	a[13].c = "ABCD";
	a[14].c = " ABCD";
	a[15].c = " ABCD ";
	for (int i = 0; i < N_TESTS; ++i) {
		//printf("[%s] : [%s] ->   ", a[i].str, a[i].c);
		char curr1[50];
		strcpy(curr1, a[i].str);
		char curr2[50];
		strcpy(curr2, a[i].str);
		ck_assert_mem_eq(
			strcat(curr1, a[i].c),
			s21_strcat(curr2, a[i].c),
			strlen(curr1)
		);
		//printf("[%s] : [%s]\n", curr1,curr2);
	}
}

END_TEST
START_TEST(test_strncat) {
	typedef struct s {
	  char *str;
	  char *c;
	  int n;
	} test;

	char dest[50] = "abc";

	test a[N_TESTS];
	for (int i = 0; i < N_TESTS; ++i) {
		a[i].str = dest;
	}
	a[0].c = "";
	a[0].n = 5;
	a[1].c = " ";
	a[1].n = 5;
	a[2].c = "a";
	a[2].n = 5;
	a[3].c = "a ";
	a[3].n = 5;
	a[4].c = " a";
	a[4].n = 5;
	a[5].c = "ab";
	a[5].n = 5;
	a[6].c = " ab";
	a[6].n = 5;
	a[7].c = " ab ";
	a[7].n = 5;
	a[8].c = "abcd";
	a[8].n = 5;
	a[9].c = "   ";
	a[9].n = 5;
	a[10].c = "abcdeftgh";
	a[10].n = 5;
	a[11].c = ".a.b";
	a[11].n = 5;
	a[12].c = "a/a/a";
	a[12].n = 5;
	a[13].c = "ABCD";
	a[13].n = 5;
	a[14].c = " ABCD";
	a[14].n = 5;
	a[15].c = " ABCD ";
	a[15].n = 5;

	//};
	for (int i = 0; i < N_TESTS; ++i) {
		char curr1[50];
		strcpy(curr1, a[i].str);
		char curr2[50];
		strcpy(curr2, a[i].str);
		ck_assert_mem_eq(
			strncat(curr1, a[i].c, a[i].n),
			s21_strncat(curr2, a[i].c, a[i].n),
			strlen(curr1)
		);
		//printf("[%s] : [%s]\n", curr1, curr2);
	}
}

END_TEST
START_TEST(test_strcmp) {
	char *a[N_TESTS][2] = {
		{"this is test", "this is test"},
		{"aaaaaabaaaaaa", "aaaaaabaaaaaab"},
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
//		printf("[%s] : [%s]\n", a[i][0], a[i][1]);
		ck_assert_int_eq(
			strcmp(a[i][0], a[i][1]),
			s21_strcmp(a[i][0], a[i][1])
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
	test a[N_TESTS] = {
		{"this is test", "this is test", 5},
		{"aaaaaabaaaaaa", "aaaaaabaaaaaab", 5},
		{"aaaaaabaaaaaa", "baa", 5},
		{"aaaaaabaaaaaa", "ab", 5},
		{"", "", 5},
		{"", "    ", 5},
		{"   ", "", 5},
		{"   ", " ", 5},
		{" ", " ", 5},
		{"close", "x", 5},
		{"close", "x", 5},
		{"close", "x", 5},
		{"maximax", "ax", 5},
		{"maximax", "max", 5},
		{"maximax", "im", 5},
		{"maximax", "ix", 5},
	};
	for (int i = 0; i < N_TESTS; ++i) {
//		printf("[%s] : [%s]\n", a[i][0], a[i][1]);
		ck_assert_int_eq(
			strncmp(a[i].str, a[i].c, a[i].n),
			s21_strncmp(a[i].str, a[i].c, a[i].n)
		);
	}
}

END_TEST
START_TEST(test_strlen) {
	typedef struct s {
	  char *str;
	} test;
	test a[N_TESTS] = {
		{"this is test"},
		{"!№;%:?*"},
		{"aaaaaabaaaaaa"},
		{"aaaaaabaaaaaa"},
		{""},
		{""},
		{"   "},
		{"   "},
		{" "},
		{"close"},
		{"close"},
		{"close"},
		{"maximax"},
		{"maximax"},
		{"maximax"},
		{"maximax"},
	};
	for (int i = 0; i < N_TESTS; ++i) {
//		printf("[%s] : [%s]\n", a[i][0], a[i][1]);
		ck_assert_int_eq(
			strlen(a[i].str),
			s21_strlen(a[i].str)
		);
	}
}

END_TEST

//START_TEST(NAME_HERE) {
//	char *a[N_TESTS][2] = {
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
////		printf("[%s] : [%s]\n", a[i][0], a[i][1]);
//		ck_assert_ptr_eq(
//			string.h_function(a[i][0], a[i][1]),
//			s21_string.h_function(a[i][0], a[i][1])
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
