#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "s21_string.H"
#include <check.h>

START_TEST(test_strspn) {
    char *test_str1 = "Escape Meta Alt Control Shift";
    char *test_str2 = "Escape from school 21";
    ck_assert_int_eq(strspn(test_str1, test_str2), s21_strspn(test_str1, test_str2));
//    ck_assert(1 == 2);
//    ck_assert_msg(1 == 2, "Was expecting 2, but got 1");
}
END_TEST

Suite* string_suite(void) {
    Suite* s;
    TCase *tc_core;
    s = suite_create("s21_string");
    tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_strspn);
    suite_add_tcase(s, tc_core);
    return s;
}

int main(void) {
    size_t p;
    int number_failed = 0;
    Suite* s;
    SRunner *sr;
    s = string_suite();
    sr = srunner_create(s);
    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
//	return 0;
}
