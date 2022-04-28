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
		{"aaaa zaaaa", ' '},
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
			memchr(a[i].str, a[i].c, a[i].n)
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
		{"close", "x", 5},
		{"maximax", "ax", 7},
		{"maximax", "max", 7},
		{"maximax", "im", 7},
		{"maximax", "ix", 7},
	};
	for (int i = 0; i < N_TESTS; ++i) {
//		printf("[%s] : [%s]\n", a[i][0], a[i][1]);
		ck_assert_ptr_eq(
			memmove(a[i].str, a[i].c, a[i].n),
			s21_memmove(a[i].str, a[i].c, a[i].n)
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
		{"",48, 1},
		{"", 48, 2},
		{"   ",48, 1},
		{"   ",48, 3},
		{" ",48, 1},
		{" ",48, 0},
		{"close",48, 5},
		{"maximax", 48, 1},
		{"maximax", 48, 0},
		{"maximax", 48, 7},
		{"maximax", 48, 4},
	};
	for (int i = 0; i < N_TESTS; ++i) {
//		printf("[%s] : [%s]\n", a[i][0], a[i][1]);
		ck_assert_ptr_eq(
			memset(a[i].str, a[i].c, a[i].n),
			s21_memset(a[i].str, a[i].c, a[i].n)
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

	TCase *strstr_case;
	strstr_case = tcase_create("strstr");
	tcase_add_test(strstr_case, test_strstr);
	suite_add_tcase(s, strstr_case);

	TCase *strchr_case;
	strchr_case = tcase_create("strchr");
	tcase_add_test(strchr_case, test_strchr);
	suite_add_tcase(s, strchr_case);

	TCase *memchr_case;
	memchr_case = tcase_create("memchr");
	tcase_add_test(memchr_case, test_memchr);
	suite_add_tcase(s, memchr_case);

	TCase *memcmp_case;
	memcmp_case = tcase_create("memcmp");
	tcase_add_test(memcmp_case, test_memcmp);
	suite_add_tcase(s, memcmp_case);
	TCase *memset_case;
	memset_case = tcase_create("memset");
	tcase_add_test(memset_case, test_memset);
	suite_add_tcase(s, memset_case);

	TCase *strpbrk_case;
	strpbrk_case = tcase_create("strpbrk");
	tcase_add_test(strpbrk_case, test_strpbrk);
	suite_add_tcase(s, strpbrk_case);
	//TCase *NEW CASE;
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
