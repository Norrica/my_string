#include <stdlib.h>
#include <string.h>
#include "s21_string.h"
#include <check.h>

#define N_TESTS 16

START_TEST(test_strspn) {
	char *a[0 + N_TESTS][2] = {
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
		{"ololo",'o'},
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
