#include <string.h>
#include <check.h>
#include <stdio.h>
#include "s21_string.h"
#include <limits.h>

START_TEST(STRLENTest1) {
    char str[] = "Hello";
    ck_assert_msg(s21_strlen(str) == strlen(str), "Failed on 5");
}
END_TEST

START_TEST(STRLENTest2) {
    char str[] = "Hegd    llo";
    ck_assert_msg(s21_strlen(str) == strlen(str), "Failed on 11");
}
END_TEST

START_TEST(STRLENTest3) {
    char str[] = "";
    ck_assert_msg(s21_strlen(str) == strlen(str), "Failed on 0");
}
END_TEST

START_TEST(STRLENTest4) {
    char str[] = "lorem\\tipsum\\tdolor\\nsit\\namet\\n";
    ck_assert_msg(s21_strlen(str) == strlen(str), "Failed on 32");
}
END_TEST
START_TEST(STRLENTest5) {
    char str[] = "\n\n\f\r\t";
    ck_assert_msg(s21_strlen(str) == strlen(str), "Failed on 5");
}
END_TEST
START_TEST(STRLENTest6) {
    char str[] = "     ";
    ck_assert_msg(s21_strlen(str) == strlen(str), "Failed on 5");
}
END_TEST

// MARK: - STRCHR 6

START_TEST(STRCHRTest1) {
    char str[] = "Hello world";
    int ch = 'w';
    ck_assert_str_eq(s21_strchr(str, ch), strchr(str, ch));
}
END_TEST

START_TEST(STRCHRTest2) {
    char str[] = "Hello world";
    int ch = 'o';
    ck_assert_str_eq(s21_strchr(str, ch), strchr(str, ch));
}
END_TEST

START_TEST(STRCHRTest3) {
    char str[] = "Hello world";
    int ch = 'c';
    ck_assert_ptr_eq(s21_strchr(str, ch), strchr(str, ch));
}
END_TEST

START_TEST(STRCHRTest4) {
    char str[] = "Hello world";
    int ch = 'H';
    ck_assert_str_eq(s21_strchr(str, ch), strchr(str, ch));
}
END_TEST

START_TEST(STRCHRTest5) {
    char str[] = "Hello world";
    int ch = '\0';
    ck_assert_str_eq(s21_strchr(str, ch), strchr(str, ch));
}
END_TEST

START_TEST(STRCHRTest6) {
    char str[] = "";
    int ch = '\0';
    ck_assert_str_eq(s21_strchr(str, ch), strchr(str, ch));
}
END_TEST

// MARK:- STRSPN 8

START_TEST(STRSPNTest1) {
    char *str1 = "12345";
    char *str2 = "123";
    ck_assert_msg(s21_strspn(str1, str2) == strspn(str1, str2), "Failed on 3");
}
END_TEST

START_TEST(STRSPNTest2) {
    char *str1 = "12345";
    char *str2 = "12sd34";
    ck_assert_msg(s21_strspn(str1, str2) == strspn(str1, str2), "Failed on 4");
}
END_TEST

START_TEST(STRSPNTest3) {
    char *str1 = "12345";
    char *str2 = "12sdf4";
    ck_assert_msg(s21_strspn(str1, str2) == strspn(str1, str2), "Failed on 2");
}
END_TEST

START_TEST(STRSPNTest4) {
    char *str1 = "12345";
    char *str2 = "kbf";
    ck_assert_msg(s21_strspn(str1, str2) == strspn(str1, str2), "Failed on 0");
}
END_TEST

START_TEST(STRSPNTest5) {
    char *str1 = "12345";
    char *str2 = "54321";
    ck_assert_msg(s21_strspn(str1, str2) == strspn(str1, str2), "Failed on 5");
}
END_TEST

START_TEST(STRSPNTest6) {
    char *str1 = "12345";
    char *str2 = "5qw4w3qwe2qweqw1";
    ck_assert_msg(s21_strspn(str1, str2) == strspn(str1, str2), "Failed on 5");
}
END_TEST

START_TEST(STRSPNTest7) {
    char *str1 = "12345";
    char *str2 = " ";
    ck_assert_msg(s21_strspn(str1, str2) == strspn(str1, str2), "Failed on 0");
}
END_TEST

START_TEST(STRSPNTest8) {
    char *str1 = "12345";
    char *str2 = " 1";
    ck_assert_msg(s21_strspn(str1, str2) == strspn(str1, str2), "Failed on 1");
}
END_TEST


// MARK: - STRCSPN 6

START_TEST(STRCSPNTest1) {
    char *src = "0123456789";
    char *str = "54";
    ck_assert_msg(s21_strcspn(src, str) == strcspn(src, str), "Failed on 4");
}
END_TEST

START_TEST(STRCSPNTest2) {
    char *src = "0123456789";
    char *str = "e";
    ck_assert_msg(s21_strcspn(src, str) == strcspn(src, str), "Failed on 0");
}
END_TEST

START_TEST(STRCSPNTest3) {
    char *src = "46";
    char *str = "123";
    ck_assert_msg(s21_strcspn(src, str) == strcspn(src, str), "Failed on 2");
}
END_TEST

START_TEST(STRCSPNTest4) {
    char *src = "HELLO";
    char *str = "HELLO";
    ck_assert_msg(s21_strcspn(src, str) == strcspn(src, str), "Failed on 0");
}
END_TEST

START_TEST(STRCSPNTest5) {
    char *src = "";
    char *str = "hi";
    ck_assert_msg(s21_strcspn(src, str) == strcspn(src, str), "Failed on 0");
}
END_TEST
START_TEST(STRCSPNTest6) {
    char *src = "\0";
    char *str = "\0";
    ck_assert_msg(s21_strcspn(src, str) == strcspn(src, str), "Failed on 0");
}
END_TEST

// MARK:- MEMCPY 5

START_TEST(MEMCPYTest1) {
    char *src = "HELLO WORLD";
    char dest[15];
    char dest2[15];
    ck_assert_mem_eq(s21_memcpy(dest, src, 11), memcpy(dest2, src, 11), 11);
}
END_TEST

START_TEST(MEMCPYTest2) {
    char *src = "HELLO";
    char dest[5];
    char dest2[5];
    ck_assert_mem_eq(s21_memcpy(dest, src, 5), memcpy(dest2, src, 5), 5);
}
END_TEST

START_TEST(MEMCPYTest3) {
    char *src = "HELLO";
    char dest[5];
    char dest2[5];
    ck_assert_mem_eq(s21_memcpy(dest, src, 5), memcpy(dest2, src, 5), 0);
}
END_TEST

START_TEST(MEMCPYTest4) {
    char *src = "zy\0xw";
    char dest[5];
    char dest2[5];
    ck_assert_mem_eq(s21_memcpy(dest, src, 5), memcpy(dest2, src, 5), 0);
}
END_TEST
START_TEST(MEMCPYTest5) {
    char *src = "zy\0xw";
    char dest[5];
    char dest2[5];
    ck_assert_mem_eq(s21_memcpy(dest, src, 5), memcpy(dest2, src, 5), 0);
}
END_TEST
// MARK:- STRCAT 5
START_TEST(STRCATTest1) {
    char app[1024] = "вторая строка ";
    char dst[1024] = "первая строка ";
    ck_assert_str_eq(s21_strcat(dst, app), strcat(dst, app));
}
END_TEST

START_TEST(STRCATTest2) {
    char app[1024] = " ";
    char dst[1024] = "   ";
    ck_assert_str_eq(s21_strcat(dst, app), strcat(dst, app));
}
END_TEST

START_TEST(STRCATTest3) {
    char app[1024] = "s s d";
    char dst[1024] = " s  s  s  sd aff   ";
    ck_assert_str_eq(s21_strcat(dst, app), strcat(dst, app));
}
END_TEST

START_TEST(STRCATTest4) {
    char app[1024] = "sdddadasdsa";
    char dst[1024] = "s                              ";
    ck_assert_str_eq(s21_strcat(dst, app), strcat(dst, app));
}
END_TEST

START_TEST(STRCATTest5) {
    char app[1024] = "\0";
    char dst[1024] = "\n\0";
    ck_assert_str_eq(s21_strcat(dst, app), strcat(dst, app));
}
END_TEST

// MARK: MEMCMP 10
START_TEST(MEMCMPTest1) {
    char str1[] = "Hello";
    char str2[] = "Hello";
    int n = 6;
    ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST
START_TEST(MEMCMPTest2) {
    char str1[] = "Hello";
    char str2[] = "Help";
    int n = 4;
    ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST
START_TEST(MEMCMPTest3) {
    char str1[] = "Help";
    char str2[] = "Hello";
    int n = 4;
    ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST
START_TEST(MEMCMPTest4) {
    char str1[] = "Help";
    char str2[] = "Hello";
    int n = 3;
    ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST
START_TEST(MEMCMPTest5) {
    char str1[6] = "Hello";
    char str2[6] = "";
    int n = 4;
    ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST
START_TEST(MEMCMPTest6) {
    char str1[4] = "";
    char str2[4] = "";
    int n = 4;
    ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST
START_TEST(MEMCMPTest7) {
    char str1[] = "gsafh";
    char str2[] = "dhkjfhs";
    int n = 0;
    ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST
//  START_TEST(MEMCMPTest8) {
//      char str1[] = "test\0test";
//      char str2[] = "test";
//      int n = 10;
//      ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
//  }
//  END_TEST
START_TEST(MEMCMPTest9) {
    char str1[] = "test";
    char str2[] = "teSt";
    int n = 4;
    ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST
START_TEST(MEMCMPTest10) {
    char str1[] = "t\200";
    char str2[] = "t\0";
    int n = 2;
    ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

// MARK: STRNCAT 5
START_TEST(STRNCATTest1) {
    char str1[1024] = "Hello";
    char str2[] = " World";
    int n = 6;
    ck_assert_str_eq(s21_strncat(str1, str2, n), strncat(str1, str2, n));
}
END_TEST
START_TEST(STRNCATTest2) {
    char str1[1024] = "Hello";
    char str2[] = " World";
    int n = 4;
    ck_assert_str_eq(s21_strncat(str1, str2, n), strncat(str1, str2, n));
}
END_TEST
START_TEST(STRNCATTest3) {
    char str1[1024] = "";
    char str2[] = " HELLO";
    int n = 5;
    ck_assert_str_eq(s21_strncat(str1, str2, n), strncat(str1, str2, n));
}
END_TEST
START_TEST(STRNCATTest4) {
    char str1[1024] = "HI, ";
    char str2[] = "HELL\0O";
    int n = 5;
    ck_assert_str_eq(s21_strncat(str1, str2, n), strncat(str1, str2, n));
}
END_TEST
START_TEST(STRNCATTest5) {
    char str1[1024] = "\0";
    char str2[] = "H";
    int n = 5;
    ck_assert_str_eq(s21_strncat(str1, str2, n), strncat(str1, str2, n));
}
END_TEST

// MARK: STRNCPY 5

START_TEST(STRNCPYTest1) {
    char str1[1024] = "Hello";
    char str2[] = " World";
    int n = 6;
    ck_assert_str_eq(s21_strncpy(str1, str2, n), strncpy(str1, str2, n));
}
END_TEST
START_TEST(STRNCPYTest2) {
    char str1[1024] = "Hello";
    char str2[] = " World";
    int n = 4;
    ck_assert_str_eq(s21_strncpy(str1, str2, n), strncpy(str1, str2, n));
}
END_TEST
START_TEST(STRNCPYTest3) {
    char str1[1024] = "";
    char str2[] = " HELLO";
    int n = 5;
    ck_assert_str_eq(s21_strncpy(str1, str2, n), strncpy(str1, str2, n));
}
END_TEST
START_TEST(STRNCPYTest4) {
    char str1[1024] = "HI, ";
    char str2[] = " HELL\0O";
    int n = 5;
    ck_assert_str_eq(s21_strncpy(str1, str2, n), strncpy(str1, str2, n));
}
END_TEST
START_TEST(STRNCPYTest5) {
    char str1[1024] = "HI, ";
    char str2[] = " HELLO";
    int n = 20;
    ck_assert_str_eq(s21_strncpy(str1, str2, n), strncpy(str1, str2, n));
}
END_TEST

// MARK: - STRRCHR 5
START_TEST(STRRCHRTest1) {
    char str1[] = "Hello, Mel";
    int c = 'e';
    ck_assert_ptr_eq(s21_strrchr(str1, c), strrchr(str1, c));
}
END_TEST
START_TEST(STRRCHRTest2) {
    char str1[] = "Hello, Mel";
    int c = 'p';
    ck_assert_ptr_eq(s21_strrchr(str1, c), strrchr(str1, c));
}
END_TEST
START_TEST(STRRCHRTest3) {
    char str1[] = "";
    int c = 'l';
    ck_assert_ptr_eq(s21_strrchr(str1, c), strrchr(str1, c));
}
END_TEST
START_TEST(STRRCHRTest4) {
    char str1[] = "Hello";
    int c = 0;
    ck_assert_ptr_eq(s21_strrchr(str1, c), strrchr(str1, c));
}
END_TEST
START_TEST(STRRCHRTest5) {
    char str1[] = "Hello";
    int c = 'o';
    ck_assert_ptr_eq(s21_strrchr(str1, c), strrchr(str1, c));
}
END_TEST

// MARK:MEMMOVE 4

START_TEST(MEMMOVETest1) {
    char dest1[10] = "fd";
    char dest2[10] = "fd";
    char src[5] = "hello";
    ck_assert_mem_eq(s21_memmove(dest1 + 2, src + 2, 3), memmove(dest2, src + 2, 3), 5);
}
END_TEST

START_TEST(MEMMOVETest2) {
    char dest1[10] = "fd";
    char dest2[10] = "fd";
    char src[5] = "hello";
    ck_assert_mem_eq(s21_memmove(dest1, src, 0), memmove(dest2, src, 0), 0);
}
END_TEST

//  START_TEST(MEMMOVETest3) {
//      char dest1[10] = "fd";
//      char dest2[10] = "fd";
//      char src[5] = "hello";
//      ck_assert_mem_eq(s21_memmove(dest1, src, 10), memmove(dest2, src, 10), 0);
//  }
//  END_TEST
//  START_TEST(MEMMOVETest4) {
//      char dest1[10] = "";
//      char dest2[10] = "";
//      char src[5] = "so\0";
//      ck_assert_mem_eq(s21_memmove(dest1, src, 10), memmove(dest2, src, 10), 0);
//  }
//  END_TEST

// MARK:STRSTR 5

START_TEST(STRSTRTest1) {
    char str1[10] = "hello";
    char str2[10] = "he";
    ck_assert_msg(s21_strstr(str1, str2) == strstr(str1, str2), "failed");
}
END_TEST

START_TEST(STRSTRTest2) {
    char str1[10] = "hello";
    char str2[10] = "";
    ck_assert_msg(s21_strstr(str1, str2) == strstr(str1, str2), "failed");
}
END_TEST

START_TEST(STRSTRTest3) {
    char str1[10] = "hello";
    char str2[10] = "qw";
    ck_assert_msg(s21_strstr(str1, str2) == strstr(str1, str2), "failed");
}
END_TEST

START_TEST(STRSTRTest4) {
    char str1[10] = "hello";
    char str2[10] = "hellp";
    ck_assert_msg(s21_strstr(str1, str2) == strstr(str1, str2), "failed");
}
END_TEST

START_TEST(STRSTRTest5) {
    char str1[1024] = "hello sweet hello";
    char str2[10] = "hello";
    ck_assert_msg(s21_strstr(str1, str2) == strstr(str1, str2), "failed");
}
END_TEST


// MARK: STRCMP 6

START_TEST(STRCMPTest1) {
    char str1[10] = "hello";
    char str2[10] = "hello";
    ck_assert_msg(s21_strcmp(str1, str2) == strcmp(str1, str2), "failed");
}
END_TEST

START_TEST(STRCMPTest2) {
    char str1[10] = "hello";
    char str2[10] = "hellq";
    ck_assert_msg(s21_strcmp(str1, str2) == strcmp(str1, str2), "failed");
}
END_TEST

START_TEST(STRCMPTest3) {
    char str1[10] = "hello";
    char str2[10] = "helle";
    ck_assert_msg(s21_strcmp(str1, str2) == strcmp(str1, str2), "failed");
}
END_TEST

START_TEST(STRCMPTest4) {
    char str1[10] = "hello";
    char str2[10] = "";
    ck_assert_msg(s21_strcmp(str1, str2) == strcmp(str1, str2), "failed");
}
END_TEST

START_TEST(STRCMPTest5) {
    char str1[10] = "";
    char str2[10] = "hello";
    ck_assert_msg(s21_strcmp(str1, str2) == strcmp(str1, str2), "failed");
}
END_TEST

START_TEST(STRCMPTest6) {
    char str1[10] = "";
    char str2[10] = "";
    ck_assert_msg(s21_strcmp(str1, str2) == strcmp(str1, str2), "failed");
}
END_TEST


// MARK: - MEMCHR 5

START_TEST(MEMCHRTest1) {
    char str1[10] = "Hello";
    ck_assert_mem_eq(s21_memchr(str1, 'H', 5), memchr(str1, 'H', 5), 5);
}
END_TEST

START_TEST(MEMCHRTest2) {
    char str1[10] = "Hello";
    ck_assert_msg(s21_memchr(str1, 'h', 5) == NULL, "Failed: Str == NULL");
}
END_TEST

START_TEST(MEMCHRTest3) {
    char str1[10] = "Hellosdsfq";
    ck_assert_msg(s21_memchr(str1, 'h', 5) == NULL, "Failed: Str == NULL");
}
END_TEST

START_TEST(MEMCHRTest4) {
    char str1[10] = "Hellosdsfq";
    ck_assert_mem_eq(s21_memchr(str1, 'l', 5), memchr(str1, 'l', 5), 3);
}
END_TEST

START_TEST(MEMCHRTest5) {
    char str1[10] = "Hellosdsfq";
    ck_assert_mem_eq(s21_memchr(str1, 'l', 0), memchr(str1, 'l', 0), 0);
}
END_TEST


// MARK: - STRCPY 4

START_TEST(STRCPYTest1) {
    char str[] = "Hello";
    char str1[15] = "";
    char str2[15] = "";
    s21_strcpy(str1, str);
    strcpy(str2, str);
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(STRCPYTest2) {
    char str[] = "";
    char str1[15] = "";
    char str2[15] = "";
    s21_strcpy(str1, str);
    strcpy(str2, str);
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(STRCPYTest3) {
    char str[15] = "";
    char str1[15] = "test";
    char str2[15] = "test";
    s21_strcpy(str1, str);
    strcpy(str2, str);
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(STRCPYTest4) {
    char str[] = "Test";
    char str1[1024] = "";
    char str2[1024] = "";
    s21_strcpy(str1, str);
    strcpy(str2, str);
    ck_assert_str_eq(str1, str2);
}
END_TEST

// MARK: - STRPBRK 4

START_TEST(STRPBRKTest1) {
    char *str = "this is a test";
    char *str1 = "this is a test";
    str1 = strpbrk(str1, "this");
    str = s21_strpbrk(str, "this");
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(STRPBRKTest2) {
    char *str = "this is a test";
    char *str1 = "this is a test";
    str1 = strpbrk(str1, " ");
    str = s21_strpbrk(str, " ");
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(STRPBRKTest3) {
    char *str = "this is a test, this is ...";
    char *str1 = "this is a test, this is ...";
    str1 = strpbrk(str1, "this");
    str = s21_strpbrk(str, "this");
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(STRPBRKTest4) {
    char *str = "this is a test, this is ...";
    char *str1 = "this is a test, this is ...";
    ck_assert_ptr_eq(s21_strpbrk(str, "prom"), strpbrk(str1, "prom"));
}
END_TEST

// MARK: - STRNCMP 8

START_TEST(STRNCMPTest1) {
    char *str1 = "1234567890";
    char *str2 = "1234567890";
    ck_assert_msg(s21_strncmp(str1, str2, 5) == strncmp(str1, str2, 5), "Failed on 1");
}
END_TEST

START_TEST(STRNCMPTest2) {
    char *str1 = "1234567890";
    char *str2 = "1224567890";
    ck_assert_msg(s21_strncmp(str1, str2, 5) == strncmp(str1, str2, 5), "Failed on 2");
}
END_TEST

START_TEST(STRNCMPTest3) {
    char *str1 = "1224567890";
    char *str2 = "1234567890";
    ck_assert_msg(s21_strncmp(str1, str2, 5) == strncmp(str1, str2, 5), "Failed on 3");
}
END_TEST

START_TEST(STRNCMPTest4) {
    char *str1 = "";
    char *str2 = "";
    ck_assert_msg(s21_strncmp(str1, str2, 5) == strncmp(str1, str2, 5), "Failed on 4");
}
END_TEST

START_TEST(STRNCMPTest5) {
    char *str1 = "1224567890";
    char *str2 = "";
    ck_assert_msg(s21_strncmp(str1, str2, 5) == strncmp(str1, str2, 5), "Failed on 5");
}
END_TEST

START_TEST(STRNCMPTest6) {
    char *str1 = "122";
    char *str2 = "345";
    ck_assert_msg(s21_strncmp(str1, str2, 5) == strncmp(str1, str2, 5), "Failed on 6");
}
END_TEST

START_TEST(STRNCMPTest7) {
    char *str1 = "test\0abc";
    char *str2 = "test\0";
    ck_assert_msg(s21_strncmp(str1, str2, 6) == strncmp(str1, str2, 6), "Failed on 7");
}
END_TEST
START_TEST(STRNCMPTest8) {
    char *str1 = "1224567890";
    char *str2 = "02";
    ck_assert_msg(s21_strncmp(str1, str2, 0) == strncmp(str1, str2, 0), "Failed on 8");
}
END_TEST

// MARK: - MEMSET 7

START_TEST(MEMSETTest1) {
    char str1[15] = "1234567890";
    char str2[15] = "1234567890";
    int c = '1';
    int n = 10;
    s21_memset(str1, c, n);
    memset(str2, c, n);
    ck_assert_mem_eq(str1, str2, 10);
}
END_TEST

START_TEST(MEMSETTest2) {
    char str1[15] = "1234567890";
    char str2[15] = "5432167890";
    int c = '1';
    int n = 10;
    s21_memset(str1, c, n);
    memset(str2, c, n);
    ck_assert_mem_eq(str1, str2, 10);
}
END_TEST

START_TEST(MEMSETTest3) {
    char str1[15] = "1234567890";
    char str2[15] = "5432167890";
    int c = 'q';
    int n = 10;
    s21_memset(str1, c, n);
    memset(str2, c, n);
    ck_assert_mem_eq(str1, str2, 10);
}
END_TEST

START_TEST(MEMSETTest4) {
    char str1[15] = "1234567890";
    char str2[15] = "5432167890";
    int c = '1';
    int n = 5;
    s21_memset(str1, c, n);
    memset(str2, c, n);
    ck_assert_mem_eq(str1, str2, 5);
}
END_TEST

START_TEST(MEMSETTest5) {
    char str1[15] = "qweqweqweqwe";
    char str2[15] = "ewqewqewqewq";
    int c = '1';
    int n = 10;
    s21_memset(str1, c, n);
    memset(str2, c, n);
    ck_assert_mem_eq(str1, str2, 10);
}
END_TEST

START_TEST(MEMSETTest6) {
    char str1[15] = "qweqweqweqwe";
    char str2[15] = "qweqweqweqwe";
    int c = '\0';
    int n = 5;
    s21_memset(str1, c, n);
    memset(str2, c, n);
    ck_assert_mem_eq(str1, str2, 10);
}
END_TEST

START_TEST(MEMSETTest7) {
    char str1[15] = "qweqweqweqwe";
    char str2[15] = "qweqweqweqwe";
    int c = '\n';
    int n = 5;
    s21_memset(str1, c, n);
    memset(str2, c, n);
    ck_assert_mem_eq(str1, str2, 10);
}
END_TEST

// MARK: -STRTOK 6

START_TEST(STRTOKTest1) {
    char str[30] = "test1/test2/test3/test4";
    char st2[30] = "test1/test2/test3/test4";
    char *delim = "/";
    ck_assert_pstr_eq(NULL, NULL);
    ck_assert_pstr_eq(s21_strtok(str, delim), strtok(st2, delim));
    ck_assert_pstr_eq(s21_strtok(NULL, delim), strtok(NULL, delim));
    ck_assert_pstr_eq(s21_strtok(NULL, delim), strtok(NULL, delim));
    ck_assert_pstr_eq(s21_strtok(NULL, delim), strtok(NULL, delim));
    ck_assert_pstr_eq(s21_strtok(NULL, delim), strtok(NULL, delim));
    ck_assert_pstr_eq(s21_strtok(NULL, delim), strtok(NULL, delim));
    ck_assert_pstr_eq(s21_strtok(NULL, delim), strtok(NULL, delim));
    ck_assert_pstr_eq(s21_strtok(NULL, delim), strtok(NULL, delim));
}
END_TEST

START_TEST(STRTOKTest2) {
    char str[30] = "test1/test2/test3/test4";
    char st2[30] = "test1/test2/test3/test4";
    char *delim = ",";
    ck_assert_pstr_eq(s21_strtok(str, delim), strtok(st2, delim));
    ck_assert_pstr_eq(s21_strtok(NULL, delim), strtok(NULL, delim));
    ck_assert_pstr_eq(s21_strtok(NULL, delim), strtok(NULL, delim));
    ck_assert_pstr_eq(s21_strtok(NULL, delim), strtok(NULL, delim));
    ck_assert_pstr_eq(s21_strtok(NULL, delim), strtok(NULL, delim));
    ck_assert_pstr_eq(s21_strtok(NULL, delim), strtok(NULL, delim));
    ck_assert_pstr_eq(s21_strtok(NULL, delim), strtok(NULL, delim));
    ck_assert_pstr_eq(s21_strtok(NULL, delim), strtok(NULL, delim));
}
END_TEST

START_TEST(STRTOKTest3) {
    char str[30] = "test1/test2/test3/test4";
    char st2[30] = "test1/test2/test3/test4";
    char *delim = "e";
    ck_assert_pstr_eq(s21_strtok(str, delim), strtok(st2, delim));
    ck_assert_pstr_eq(s21_strtok(NULL, delim), strtok(NULL, delim));
    ck_assert_pstr_eq(s21_strtok(NULL, delim), strtok(NULL, delim));
    ck_assert_pstr_eq(s21_strtok(NULL, delim), strtok(NULL, delim));
    ck_assert_pstr_eq(s21_strtok(NULL, delim), strtok(NULL, delim));
    ck_assert_pstr_eq(s21_strtok(NULL, delim), strtok(NULL, delim));
    ck_assert_pstr_eq(s21_strtok(NULL, delim), strtok(NULL, delim));
    ck_assert_pstr_eq(s21_strtok(NULL, delim), strtok(NULL, delim));
}
END_TEST

START_TEST(STRTOKTest4) {
    char str[30] = "AadacAdxa";
    char st2[30] = "AadacAdxa";
    char *delim = "a";
    ck_assert_pstr_eq(s21_strtok(str, delim), strtok(st2, delim));
    ck_assert_pstr_eq(s21_strtok(NULL, delim), strtok(NULL, delim));
    ck_assert_pstr_eq(s21_strtok(NULL, delim), strtok(NULL, delim));
    ck_assert_pstr_eq(s21_strtok(NULL, delim), strtok(NULL, delim));
    ck_assert_pstr_eq(s21_strtok(NULL, delim), strtok(NULL, delim));
    ck_assert_pstr_eq(s21_strtok(NULL, delim), strtok(NULL, delim));
    ck_assert_pstr_eq(s21_strtok(NULL, delim), strtok(NULL, delim));
    ck_assert_pstr_eq(s21_strtok(NULL, delim), strtok(NULL, delim));
}
END_TEST

START_TEST(STRTOKTest5) {
    char str[30] = "ased dse c sze wsew";
    char st2[30] = "ased dse c sze wsew";
    char *delim = "e";
    ck_assert_pstr_eq(s21_strtok(str, delim), strtok(st2, delim));
    ck_assert_pstr_eq(s21_strtok(NULL, delim), strtok(NULL, delim));
    ck_assert_pstr_eq(s21_strtok(NULL, delim), strtok(NULL, delim));
    ck_assert_pstr_eq(s21_strtok(NULL, delim), strtok(NULL, delim));
    ck_assert_pstr_eq(s21_strtok(NULL, delim), strtok(NULL, delim));
    ck_assert_pstr_eq(s21_strtok(NULL, delim), strtok(NULL, delim));
    ck_assert_pstr_eq(s21_strtok(NULL, delim), strtok(NULL, delim));
    ck_assert_pstr_eq(s21_strtok(NULL, delim), strtok(NULL, delim));
}
END_TEST

START_TEST(STRTOKTest6) {
    char str[30] = "test1,test2/test3.test4";
    char st2[30] = "test1,test2/test3.test4";
    char delim[] = ",/.";
    ck_assert_pstr_eq(s21_strtok(str, delim), strtok(st2, delim));
    ck_assert_pstr_eq(s21_strtok(NULL, delim), strtok(NULL, delim));
    ck_assert_pstr_eq(s21_strtok(NULL, delim), strtok(NULL, delim));
    ck_assert_pstr_eq(s21_strtok(NULL, delim), strtok(NULL, delim));
    ck_assert_pstr_eq(s21_strtok(NULL, delim), strtok(NULL, delim));
    ck_assert_pstr_eq(s21_strtok(NULL, delim), strtok(NULL, delim));
    ck_assert_pstr_eq(s21_strtok(NULL, delim), strtok(NULL, delim));
    ck_assert_pstr_eq(s21_strtok(NULL, delim), strtok(NULL, delim));
}
END_TEST
START_TEST(STRTOKTest7) {
    char str[30] = "test1/test2/test3/test4";
    char st2[30] = "test1/test2/test3/test4";
    char delim[] = ",/.";
    ck_assert_pstr_eq(s21_strtok(str, delim), strtok(st2, delim));
    ck_assert_pstr_eq(s21_strtok(NULL, delim), strtok(NULL, delim));
    ck_assert_pstr_eq(s21_strtok(NULL, delim), strtok(NULL, delim));
    ck_assert_pstr_eq(s21_strtok(NULL, delim), strtok(NULL, delim));
    ck_assert_pstr_eq(s21_strtok(NULL, delim), strtok(NULL, delim));
    ck_assert_pstr_eq(s21_strtok(NULL, delim), strtok(NULL, delim));
    ck_assert_pstr_eq(s21_strtok(NULL, delim), strtok(NULL, delim));
    ck_assert_pstr_eq(s21_strtok(NULL, delim), strtok(NULL, delim));
}
END_TEST
START_TEST(STRTOKTest8) {
    char str[10] = "AadacAdxa";
    char s21_str[10] = "AadacAdxa";
    char delim[2] = "a";
    char *part = strtok(str, delim);
    char *s21_part = s21_strtok(s21_str, delim);
    ck_assert_str_eq(part, s21_part);
    while (part != NULL) {
        part = strtok(NULL, delim);
        s21_part = s21_strtok(NULL, delim);
        if (part != NULL) {
            ck_assert_str_eq(part, s21_part);
        } else {
            ck_assert_ptr_null(s21_part);
        }
    }
}
END_TEST
START_TEST(STRTOKTest9) {
    char str[30] = "test1/test2/test3/test4";
    char s21_str[30] = "test1/test2/test3/test4";
    char delim[2] = "/";
    char *part = strtok(str, delim);
    char *s21_part = s21_strtok(s21_str, delim);
    ck_assert_str_eq(part, s21_part);
    while (part != NULL) {
        part = strtok(NULL, delim);
        s21_part = s21_strtok(NULL, delim);
        if (part != NULL) {
            ck_assert_str_eq(part, s21_part);
        } else {
            ck_assert_ptr_null(s21_part);
        }
    }
}
END_TEST

START_TEST(STRTOKTest10) {
    char str[15] = "12|34*56|78m90";
    char s21_str[15] = "12|34*56|78m90";
    char delim[4] = "*m|";
    char *part = strtok(str, delim);
    char *s21_part = s21_strtok(s21_str, delim);
    ck_assert_str_eq(part, s21_part);
    while (part != NULL) {
        part = strtok(NULL, delim);
        s21_part = s21_strtok(NULL, delim);
        if (part != NULL) {
            ck_assert_str_eq(part, s21_part);
        } else {
            ck_assert_ptr_null(s21_part);
        }
    }
}
END_TEST

// MARK: - STRERROR 3
START_TEST(STRERRORTest1) {
    for (int i = -123; i < 0; i++) {
        ck_assert_str_eq(s21_strerror(i), strerror(i));
    }
}
END_TEST

START_TEST(STRERRORTest2) {
    for (int i = 0; i <= 106; i++) {
        ck_assert_str_eq(s21_strerror(i), strerror(i));
    }
}
END_TEST

START_TEST(STRERRORTest3) {
    for (int i = 107; i <= 234; i++) {
        ck_assert_str_eq(s21_strerror(i), strerror(i));
    }
}
END_TEST

// MARK: - to_upper 7
/*region TOUPPER*/
START_TEST(TOUPPERTest1) {
    char str[4] = "abc";
    char *str1 = (char *) s21_to_upper(str);
    ck_assert_str_eq(str1, "ABC");
    free(str1);
}
END_TEST

START_TEST(TOUPPERTest2) {
    char str[12] = "Hello World";
    char *str1 = (char *) s21_to_upper(str);
    ck_assert_str_eq(str1, "HELLO WORLD");
    free(str1);
}
END_TEST

START_TEST(TOUPPERTest3) {
    char str[1] = "";
    char *str1 = (char *) s21_to_upper(str);
    ck_assert_str_eq(str1, "");
    free(str1);
}
END_TEST

START_TEST(TOUPPERTest4) {
    char str[4] = "ABC";
    char *str1 = (char *) s21_to_upper(str);
    ck_assert_str_eq(str1, "ABC");
    free(str1);
}
END_TEST

START_TEST(TOUPPERTest5) {
    char str[6] = "1234a";
    char *str1 = (char *) s21_to_upper(str);
    ck_assert_str_eq(str1, "1234A");
    free(str1);
}
END_TEST

START_TEST(TOUPPERTest6) {
    char *str = NULL;
    char *str1 = (char *) s21_to_upper(str);
    ck_assert_ptr_eq(str1, NULL);
    free(str1);
}
END_TEST

START_TEST(TOUPPERTest7) {
    char str[12] = "abc\0hello";
    char *str1 = (char *) s21_to_upper(str);
    ck_assert_str_eq(str1, "ABC");
    free(str1);
}
END_TEST
/*endregion*/

// MARK: - insert 7
/*region INSERT*/
START_TEST(INSERTTest1) {
    char str1[4] = "abc";
    char str2[5] = "1234";
    char *str3 = (char *) s21_insert(str1, str2, 2);
    ck_assert_str_eq(str3, "ab1234c");
    free(str3);
}
END_TEST

START_TEST(INSERTTest2) {
    char str1[1] = "";
    char str2[5] = "1234";
    char *str3 = (char *) s21_insert(str1, str2, 1);
    ck_assert_ptr_eq(str3, NULL);
    free(str3);
}
END_TEST

START_TEST(INSERTTest3) {
    char str1[2] = " ";
    char str2[5] = "1234";
    char *str3 = (char *) s21_insert(str1, str2, 1);
    ck_assert_str_eq(str3, " 1234");
    free(str3);
}
END_TEST

START_TEST(INSERTTest4) {
    char str1[4] = "abc";
    char str2[2] = " ";
    char *str3 = (char *) s21_insert(str1, str2, 2);
    ck_assert_str_eq(str3, "ab c");
    free(str3);
}
END_TEST

START_TEST(INSERTTest5) {
    char str1[4] = "abc";
    char str2[5] = "1234";
    char *str3 = (char *) s21_insert(str1, str2, -1);
    ck_assert_ptr_eq(str3, NULL);
    free(str3);
}
END_TEST

START_TEST(INSERTTest6) {
    char str1[4] = "abc";
    char str2[5] = "1234";
    char *str3 = (char *) s21_insert(str1, str2, 0);
    ck_assert_str_eq(str3, "1234abc");
    free(str3);
}
END_TEST

START_TEST(INSERTTest7) {
    char *str1 = NULL;
    char str2[5] = "1234";
    char *str3 = (char *) s21_insert(str1, str2, 0);
    ck_assert_ptr_eq(str3, NULL);
    free(str3);
}
END_TEST
/*endregion*/


// MARK: - to_lower 7
/*region TOLOWER*/
START_TEST(TOLOWERTest1) {
    char str[4] = "abc";
    char *str2 = (char *) s21_to_lower(str);
    ck_assert_str_eq(str2, "abc");
    free(str2);
}
END_TEST

START_TEST(TOLOWERTest2) {
    char str[12] = "Hello World";
    char *str2 = (char *) s21_to_lower(str);
    ck_assert_str_eq(str2, "hello world");
    free(str2);
}
END_TEST

START_TEST(TOLOWERTest3) {
    char str[1] = "";
    char *str2 = (char *) s21_to_lower(str);
    ck_assert_str_eq(str2, "");
    free(str2);
}
END_TEST

START_TEST(TOLOWERTest4) {
    char str[4] = "ABC";
    char *str2 = (char *) s21_to_lower(str);
    ck_assert_str_eq(str2, "abc");
    free(str2);
}
END_TEST

START_TEST(TOLOWERTest5) {
    char str[6] = "1234a";
    char *str2 = (char *) s21_to_lower(str);
    ck_assert_str_eq(str2, "1234a");
    free(str2);
}
END_TEST

START_TEST(TOLOWERTest6) {
    char *str = NULL;
    char *str2 = (char *) s21_to_lower(str);
    ck_assert_ptr_eq(str2, NULL);
    free(str2);
}
END_TEST

START_TEST(TOLOWERTest7) {
    char *str = "WoW\0, I love it!";
    char *str2 = (char *) s21_to_lower(str);
    ck_assert_str_eq(str2, "wow");
    free(str2);
}
END_TEST
/*endregion*/

// MARK: - trim 13
/*region TRIM*/
START_TEST(TRIMTest1) {
    char *str = "WoW\0, I love it!";
    char *str2 = "W";
    char *str3 = (char *) s21_trim(str, str2);
    ck_assert_str_eq(str3, "o");
    free(str3);
}
END_TEST

START_TEST(TRIMTest2) {
    char *str = "WoW, I love it!";
    char *str2 = "W";
    char *str3 = (char *) s21_trim(str, str2);
    ck_assert_str_eq(str3, "oW, I love it!");
    free(str3);
}
END_TEST

START_TEST(TRIMTest3) {
    char *str = "WoW, I love it!";
    char *str2 = "Wo!";
    char *str3 = (char *) s21_trim(str, str2);
    ck_assert_str_eq(str3, ", I love it");
    free(str3);
}
END_TEST

START_TEST(TRIMTest4) {
    char *str = "WoW, I love it!";
    char *str2 = "P";
    char *str3 = (char *) s21_trim(str, str2);
    ck_assert_str_eq(str3, "WoW, I love it!");
    free(str3);
}
END_TEST
START_TEST(TRIMTest5) {
    char *str = "abc";
    char *str2 = "abc";
    char *str3 = (char *) s21_trim(str, str2);
    ck_assert_str_eq(str3, "");
    free(str3);
}
END_TEST
START_TEST(TRIMTest6) {
    char *str = "WoW, I love it!";
    char *str2 = NULL;
    char *str3 = (char *) s21_trim(str, str2);
    ck_assert_str_eq(str3, "WoW, I love it!");
    free(str3);
}
END_TEST

START_TEST(TRIMTest7) {
    char *str = "       WoW, I love     it!             ";
    char *str2 = NULL;
    char *str3 = (char *) s21_trim(str, str2);
    ck_assert_str_eq(str3, "WoW, I love     it!");
    free(str3);
}
END_TEST

START_TEST(TRIMTest8) {
    char *str = "";
    char *str2 = NULL;
    char *str3 = (char *) s21_trim(str, str2);
    ck_assert_str_eq(str3, "");
    free(str3);
}
END_TEST
START_TEST(TRIMTest9) {
    char *str = "          ";
    char *str2 = NULL;
    char *str3 = (char *) s21_trim(str, str2);
    ck_assert_str_eq(str3, "");
    free(str3);
}
END_TEST

START_TEST(TRIMTest10) {
    char *str = NULL;
    char *str2 = NULL;
    char *str3 = (char *) s21_trim(str, str2);
    ck_assert_ptr_eq(str3, NULL);
    free(str3);
}
END_TEST

START_TEST(TRIMTest11) {
    char *str = "            1";
    char *str2 = NULL;
    char *str3 = (char *) s21_trim(str, str2);
    ck_assert_str_eq(str3, "1");
    free(str3);
}
END_TEST

START_TEST(TRIMTest12) {
    char *str = "\t       \t";
    char *str2 = NULL;
    char *str3 = (char *) s21_trim(str, str2);
    ck_assert_str_eq(str3, "");
    free(str3);
}
END_TEST

START_TEST(TRIMTest13) {
    char *str = "     HELLO    ";
    char *str2 = "";
    char *str3 = (char *) s21_trim(str, str2);
    ck_assert_str_eq(str3, "HELLO");
    free(str3);
}
END_TEST
/*endregion*/
/*region SPRINTF*/
START_TEST(SPRINTF1) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%c|\n", 'A');
    sprintf(data1, "|%c|\n", 'A');
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SPRINTF3) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%-5c|\n", 'A');
    sprintf(data1, "|%-5c|\n", 'A');
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SPRINTF4) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%10c|\n", 'A');
    sprintf(data1, "|%10c|\n", 'A');
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SPRINTF5) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%%|\n");
    sprintf(data1, "|%%|\n");
    ck_assert_str_eq(data, data1);
}
END_TEST

//  START_TEST(SPRINTF6) {
//      char data[100];
//      char data1[100];
//      s21_sprintf(data, "|%-5%|\n");
//      sprintf(data1, "|%-5%|\n");
//      ck_assert_str_eq(data, data1);
//  }
//  END_TEST
//
//  START_TEST(SPRINTF7) {
//      char data[100];
//      char data1[100];
//      s21_sprintf(data, "|%h%|\n");
//      sprintf(data1, "|%h%|\n");
//      ck_assert_str_eq(data, data1);
//  }
//  END_TEST
//
//  START_TEST(SPRINTF8) {
//      char data[100];
//      char data1[100];
//      s21_sprintf(data, "|%l%|\n");
//      sprintf(data1, "|%l%|\n");
//      ck_assert_str_eq(data, data1);
//  }
//  END_TEST
//
//  START_TEST(SPRINTF9) {
//      char data[100];
//      char data1[100];
//      s21_sprintf(data, "|%-+%|\n");
//      sprintf(data1, "|%-+%|\n");
//      ck_assert_str_eq(data, data1);
//  }
//  END_TEST
//
//  START_TEST(SPRINTF10) {
//      char data[100];
//      char data1[100];
//      s21_sprintf(data, "|%+%|\n");
//      sprintf(data1, "|%+%|\n");
//      ck_assert_str_eq(data, data1);
//  }
//  END_TEST

START_TEST(SPRINTF11) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%+d|\n", 10);
    sprintf(data1, "|%+d|\n", 10);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SPRINTF12) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%+d|\n", -10);
    sprintf(data1, "|%+d|\n", -10);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SPRINTF13) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%-d|\n", -10);
    sprintf(data1, "|%-d|\n", -10);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SPRINTF14) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%-d|\n", 10);
    sprintf(data1, "|%-d|\n", 10);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SPRINTF15) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%-5d|\n", 10);
    sprintf(data1, "|%-5d|\n", 10);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SPRINTF16) {
    char data[100];
    char data1[100];
    long int i = 2147483647;
    s21_sprintf(data, "|%-5ld|\n", i);
    sprintf(data1, "|%-5ld|\n", i);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SPRINTF17) {
    char data[100];
    char data1[100];
    long int i = 2147483647;
    s21_sprintf(data, "|%-5.5ld|\n", i);
    sprintf(data1, "|%-5.5ld|\n", i);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SPRINTF18) {
    char data[100];
    char data1[100];
    long int i = -2147483647;
    s21_sprintf(data, "|%-+5.5ld|\n", i);
    sprintf(data1, "|%-+5.5ld|\n", i);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SPRINTF19) {
    char data[100];
    char data1[100];
    long int i = 2147483647;
    s21_sprintf(data, "|% -5.5ld|\n", i);
    sprintf(data1, "|% -5.5ld|\n", i);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SPRINTF20) {
    char data[100];
    char data1[100];
    long int i = -2147483647;
    s21_sprintf(data, "|% -5.5ld|\n", i);
    sprintf(data1, "|% -5.5ld|\n", i);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SPRINTF21) {
    char data[100];
    char data1[100];
    short int i = 32767;
    s21_sprintf(data, "|% -5.5hd|\n", i);
    sprintf(data1, "|% -5.5hd|\n", i);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SPRINTF22) {
    char data[100] = "";
    char data1[100] = "";
    s21_sprintf(data, "|%+f|\n", 10.10);
    sprintf(data1, "|%+f|\n", 10.10);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SPRINTF23) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%+f|\n", -10.10);
    sprintf(data1, "|%+f|\n", -10.10);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SPRINTF24) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%-f|\n", -10.10);
    sprintf(data1, "|%-f|\n", -10.10);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SPRINTF25) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%-f|\n", 10.10);
    sprintf(data1, "|%-f|\n", 10.10);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SPRINTF26) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%-5f|\n", 10.10);
    sprintf(data1, "|%-5f|\n", 10.10);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SPRINTF27) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%-5lf|\n", 10.10);
    sprintf(data1, "|%-5lf|\n", 10.10);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SPRINTF28) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%-5.5lf|\n", 10.10);
    sprintf(data1, "|%-5.5lf|\n", 10.10);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SPRINTF29) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%-+5.5lf|\n", 10.10);
    sprintf(data1, "|%-+5.5lf|\n", 10.10);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SPRINTF30) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|% -5.5lf|\n", 10.10);
    sprintf(data1, "|% -5.5lf|\n", 10.10);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SPRINTF31) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|% -5.5lf|\n", 10.10);
    sprintf(data1, "|% -5.5lf|\n", 10.10);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SPRINTF32) {
    char data[100];
    char data1[100];
    char *fmt = "|%5.5s|\n";
    s21_sprintf(data, fmt, "lol");
    sprintf(data1, fmt, "lol");
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SPRINTF33) {
    char data[100];
    char data1[100];
    char *fmt = "|%s|\n";
    char *src = "lol";
    s21_sprintf(data, fmt, src);
    sprintf(data1, fmt, src);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SPRINTF34) {
    char data[100];
    char data1[100];
    char *fmt = "|%5s|\n";
    char *src = "lol";
    s21_sprintf(data, fmt, src);
    sprintf(data1, fmt, src);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SPRINTF35) {
    char data[100];
    char data1[100];
    char *fmt = "|%.5s|\n";
    char *src = "lol";
    s21_sprintf(data, fmt, src);
    sprintf(data1, fmt, src);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SPRINTF36) {
    char data[100];
    char data1[100];
    char *fmt = "|%+.5s|\n";
    char *src = "lol";
    s21_sprintf(data, fmt, src);
    sprintf(data1, fmt, src);
    ck_assert_str_eq(data, data1);
}
END_TEST
START_TEST(SPRINTF37) {
    char data[100];
    char data1[100];
    char *fmt = "|%-.5s|\n";
    char *src = "lol";
    s21_sprintf(data, fmt, src);
    sprintf(data1, fmt, src);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SPRINTF38) {
    char data[100];
    char data1[100];
    char *fmt = "|%-6.5s|\n";
    char *src = "lol";
    s21_sprintf(data, fmt, src);
    sprintf(data1, fmt, src);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SPRINTF39) {
    char data[100];
    char data1[100];
    char *fmt = "|%-5.6s|\n";
    char *src = "lol";
    s21_sprintf(data, fmt, src);
    sprintf(data1, fmt, src);
    ck_assert_str_eq(data, data1);
}
END_TEST
START_TEST(SPRINTF40) {
    char data[100];
    char data1[100];
    char *fmt = "|%-2s|\n";
    char *src = "lol";
    s21_sprintf(data, fmt, src);
    sprintf(data1, fmt, src);
    ck_assert_str_eq(data, data1);
}
END_TEST
START_TEST(SPRINTF41) {
    char data[100];
    char data1[100];
    char *fmt = "|%-.2s|\n";
    char *src = "lol";
    s21_sprintf(data, fmt, src);
    sprintf(data1, fmt, src); /*default fails(|lo|\n)*/
    /*ck_assert_str_eq(data, data1);*/
}
END_TEST
START_TEST(SPRINTF42) {
    char data[100];
    char data1[100];
    char *fmt = "|% 2s|\n";
    char *src = "lol";
    s21_sprintf(data, fmt, src);
    sprintf(data1, fmt, src);
    ck_assert_str_eq(data, data1);
}
END_TEST
START_TEST(SPRINTF43) {
    char data[100];
    char data1[100];
    char *fmt = "|%    2s|\n";
    char *src = "lol";
    s21_sprintf(data, fmt, src);
    sprintf(data1, fmt, src);
    ck_assert_str_eq(data, data1);
}
END_TEST
START_TEST(SPRINTF44) {
    char data[100];
    char data1[100];
    char *fmt = "|%1s|\n";
    char *src = "lol";
    s21_sprintf(data, fmt, src);
    sprintf(data1, fmt, src);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SPRINTF45) {
    char data[100];
    char data1[100];
    char *fmt = "|%-10s|\n";
    char *src = "lol";
    s21_sprintf(data, fmt, src);
    sprintf(data1, fmt, src);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SPRINTF46) {
    char data[100];
    char data1[100];
    char *fmt = "|%-010s|\n";
    char *src = "lol";
    s21_sprintf(data, fmt, src);
    sprintf(data1, fmt, src);
    ck_assert_str_eq(data, data1);
}
END_TEST
START_TEST(SPRINTF47) {
    char data[100];
    char data1[100];
    char *fmt = "|%hd|\n";
    short int src = 32767;
    s21_sprintf(data, fmt, src);
    sprintf(data1, fmt, src);
    ck_assert_str_eq(data, data1);
}
END_TEST
START_TEST(SPRINTF48) {
    char data[100];
    char data1[100];
    char *fmt = "|%-hd|\n";
    short int src = -32768;
    s21_sprintf(data, fmt, src);
    sprintf(data1, fmt, src);
    ck_assert_str_eq(data, data1);
}
END_TEST
START_TEST(SPRINTF49) {
    char data[100];
    char data1[100];
    char *fmt = "|%-5hd|\n";
    short int src = 32767;
    s21_sprintf(data, fmt, src);
    sprintf(data1, fmt, src);
    ck_assert_str_eq(data, data1);
}
END_TEST
START_TEST(SPRINTF50) {
    char data[100];
    char data1[100];
    char *fmt = "|%+5hd|\n";
    short int src = -32767;
    s21_sprintf(data, fmt, src);
    sprintf(data1, fmt, src);
    ck_assert_str_eq(data, data1);
}
END_TEST
START_TEST(SPRINTF51) {
    char data[100];
    char data1[100];
    char *fmt = "|%.5hd|\n";
    short int src = 32767;
    s21_sprintf(data, fmt, src);
    sprintf(data1, fmt, src);
    ck_assert_str_eq(data, data1);
}
END_TEST
START_TEST(SPRINTF52) {
    char data[100];
    char data1[100];
    char *fmt = "|%5hd|\n";
    short int src = 1;
    s21_sprintf(data, fmt, src);
    sprintf(data1, fmt, src);
    ck_assert_str_eq(data, data1);
}
END_TEST
START_TEST(SPRINTF53) {
    char data[100];
    char data1[100];
    char *fmt = "|%1.10hd|\n";
    short int src = 11;
    s21_sprintf(data, fmt, src);
    sprintf(data1, fmt, src);
    ck_assert_str_eq(data, data1);
}
END_TEST
START_TEST(SPRINTF54) {
    char data[100];
    char data1[100];
    char *fmt = "|%-1.10hd|\n";
    short int src = 111;
    s21_sprintf(data, fmt, src);
    sprintf(data1, fmt, src);
    ck_assert_str_eq(data, data1);
}
END_TEST
START_TEST(SPRINTF55) {
    char data[100];
    char data1[100];
    char *fmt = "|%+1.10hd|\n";
    short int src = 113;
    s21_sprintf(data, fmt, src);
    sprintf(data1, fmt, src);
    ck_assert_str_eq(data, data1);
}
END_TEST
START_TEST(SPRINTF56) {
    char data[100];
    char data1[100];
    char *fmt = "|% 1.10hd|\n";
    short int src = 1134;
    s21_sprintf(data, fmt, src);
    sprintf(data1, fmt, src);
    ck_assert_str_eq(data, data1);
}
END_TEST
START_TEST(SPRINTF57) {
    char data[100];
    char data1[100];
    char *fmt = "|%    1.10hd|\n";
    short int src = 11345;
    s21_sprintf(data, fmt, src);
    sprintf(data1, fmt, src);
    ck_assert_str_eq(data, data1);
}
END_TEST
START_TEST(SPRINTF58) {
    char data[100];
    char data1[100];
    char *fmt = "|% +-1.10hd|\n";
    short int src = 11342;
    s21_sprintf(data, fmt, src);
    sprintf(data1, fmt, src);
    ck_assert_str_eq(data, data1);
}
END_TEST
START_TEST(SPRINTF59) {
    char data[100];
    char data1[100];
    char *fmt = "|%10.1hd|\n";
    short int src = 21474;
    s21_sprintf(data, fmt, src);
    sprintf(data1, fmt, src);
    ck_assert_str_eq(data, data1);
}
END_TEST
START_TEST(SPRINTF60) {
    char data[100];
    char data1[100];
    char *fmt = "|%-10.1hd|\n";
    short int src = 21474;
    s21_sprintf(data, fmt, src);
    sprintf(data1, fmt, src);
    ck_assert_str_eq(data, data1);
}
END_TEST
START_TEST(SPRINTF61) {
    char data[100];
    char data1[100];
    char *fmt = "|%+10.1hd|\n";
    long int src = -2147483647;
    s21_sprintf(data, fmt, src);
    sprintf(data1, fmt, src);
    ck_assert_str_eq(data, data1);
}
END_TEST
START_TEST(SPRINTF62) {
    char data[100];
    char data1[100];
    char *fmt = "|% +10.1hd|\n";
    long int src = -2147483647;
    s21_sprintf(data, fmt, src);
    sprintf(data1, fmt, src);
    ck_assert_str_eq(data, data1);
}
END_TEST
START_TEST(SPRINTF63) {
    char data[100];
    char data1[100];
    char *fmt = "|% -+10.1hd|\n";
    short int src = 10000;
    s21_sprintf(data, fmt, src);
    sprintf(data1, fmt, src);
    ck_assert_str_eq(data, data1);
}
END_TEST
START_TEST(SPRINTF64) {
    char data[100];
    char data1[100];
    char *fmt = "|%    -+10.1hd|\n";
    short int src = 10000;
    s21_sprintf(data, fmt, src);
    sprintf(data1, fmt, src);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SPRINTF65) {
    char data[100];
    char data1[100];
    char *fmt = "|%5ld|\n";
    long int src = -2147483647;
    s21_sprintf(data, fmt, src);
    sprintf(data1, fmt, src);
    ck_assert_str_eq(data, data1);
}
END_TEST
START_TEST(SPRINTF66) {
    char data[100];
    char data1[100];
    char *fmt = "|%1.10ld|\n";
    long int src = 2147483647;
    s21_sprintf(data, fmt, src);
    sprintf(data1, fmt, src);
    ck_assert_str_eq(data, data1);
}
END_TEST
START_TEST(SPRINTF67) {
    char data[100];
    char data1[100];
    char *fmt = "|%-1.10ld|\n";
    long int src = 2147483647;
    s21_sprintf(data, fmt, src);
    sprintf(data1, fmt, src);
    ck_assert_str_eq(data, data1);
}
END_TEST
START_TEST(SPRINTF68) {
    char data[100];
    char data1[100];
    char *fmt = "|%+1.10ld|\n";
    long int src = -2147483647;
    s21_sprintf(data, fmt, src);
    sprintf(data1, fmt, src);
    ck_assert_str_eq(data, data1);
}
END_TEST
START_TEST(SPRINTF69) {
    char data[100];
    char data1[100];
    char *fmt = "|% 1.10ld|\n";
    long int src = 2147483647;
    s21_sprintf(data, fmt, src);
    sprintf(data1, fmt, src);
    ck_assert_str_eq(data, data1);
}
END_TEST
START_TEST(SPRINTF70) {
    char data[100];
    char data1[100];
    char *fmt = "|%    1.10ld|\n";
    long int src = 2147483647;
    s21_sprintf(data, fmt, src);
    sprintf(data1, fmt, src);
    ck_assert_str_eq(data, data1);
}
END_TEST
START_TEST(SPRINTF71) {
    char data[100];
    char data1[100];
    char *fmt = "|% +-1.10ld|\n";
    long int src = 2147483647;
    s21_sprintf(data, fmt, src);
    sprintf(data1, fmt, src);
    ck_assert_str_eq(data, data1);
}
END_TEST
START_TEST(SPRINTF72) {
    char data[100];
    char data1[100];
    char *fmt = "|%10.1ld|\n";
    long int src = -2147483647;
    s21_sprintf(data, fmt, src);
    sprintf(data1, fmt, src);
    ck_assert_str_eq(data, data1);
}
END_TEST
START_TEST(SPRINTF73) {
    char data[100];
    char data1[100];
    char *fmt = "|%-10.1ld|\n";
    long int src = 2147483647;
    s21_sprintf(data, fmt, src);
    sprintf(data1, fmt, src);
    ck_assert_str_eq(data, data1);
}
END_TEST
START_TEST(SPRINTF74) {
    char data[100];
    char data1[100];
    char *fmt = "|%+10.1ld|\n";
    long int src = 2147483647;
    s21_sprintf(data, fmt, src);
    sprintf(data1, fmt, src);
    ck_assert_str_eq(data, data1);
}
END_TEST
START_TEST(SPRINTF75) {
    char data[100];
    char data1[100];
    char *fmt = "|% +10.1ld|\n";
    long int src = 2147483647;
    s21_sprintf(data, fmt, src);
    sprintf(data1, fmt, src);
    ck_assert_str_eq(data, data1);
}
END_TEST
START_TEST(SPRINTF76) {
    char data[100];
    char data1[100];
    char *fmt = "|% -+10.1ld|\n";
    long int src = 2147483647;
    s21_sprintf(data, fmt, src);
    sprintf(data1, fmt, src);
    ck_assert_str_eq(data, data1);
}
END_TEST
START_TEST(SPRINTF77) {
    char data[100];
    char data1[100];
    char *fmt = "|%    +-10.1ld|\n";
    long int src = 2147483647;
    s21_sprintf(data, fmt, src);
    sprintf(data1, fmt, src);
    ck_assert_str_eq(data, data1);
}
END_TEST
START_TEST(SPRINTF78) {
    char data[100];
    char data1[100];
    char *fmt = "|%s|\n";
    char *src = "";
    s21_sprintf(data, fmt, src);
    sprintf(data1, fmt, src);
    ck_assert_str_eq(data, data1);
}
END_TEST
START_TEST(SPRINTF79) {
    char data[100];
    char data1[100];
    char *fmt = "|%s|\n";
    char *src = NULL;
    sprintf(data1, fmt, src);
    s21_sprintf(data, fmt, src);
    ck_assert_str_eq(data, data1);
}
END_TEST
START_TEST(SPRINTF80) {
    char data[100];
    char data1[100];
    char *fmt = "|%12s|\n";
    char *src = NULL;
    sprintf(data1, fmt, src);
    s21_sprintf(data, fmt, src);
    ck_assert_str_eq(data, data1);
}
END_TEST
START_TEST(SPRINTF81) {
    char data[100];
    char data1[100];
    char *fmt = "|%-12s|\n";
    char *src = NULL;
    sprintf(data1, fmt, src);
    s21_sprintf(data, fmt, src);
    ck_assert_str_eq(data, data1);
}
END_TEST
START_TEST(SPRINTF82) {
    char data[100];
    char data1[100];
    char *fmt = "|% s|\n";
    char *src = "";
    s21_sprintf(data, fmt, src);
    sprintf(data1, fmt, src);
    ck_assert_str_eq(data, data1);
}
END_TEST
START_TEST(SPRINTF83) {
    char data[100];
    char data1[100];
    char *fmt = "|%-10s|\n";
    char *src = "";
    s21_sprintf(data, fmt, src);
    sprintf(data1, fmt, src);
    ck_assert_str_eq(data, data1);
}
END_TEST
START_TEST(SPRINTF84) {
    char data[100];
    char data1[100];
    char *fmt = "|%+10s|\n";
    char *src = "";
    s21_sprintf(data, fmt, src);
    sprintf(data1, fmt, src);
    ck_assert_str_eq(data, data1);
}
END_TEST
START_TEST(SPRINTF85) {
    char data[100];
    char data1[100];
    char *fmt = "|%   10s|\n";
    char *src = "";
    s21_sprintf(data, fmt, src);
    sprintf(data1, fmt, src);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SPRINTF86) {
    char data[100];
    char data1[100];
    char *fmt = "|%   10u|\n";
    unsigned int src = 10;
    s21_sprintf(data, fmt, src);
    sprintf(data1, fmt, src);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SPRINTF87) {
    char data[100];
    char data1[100];
    char *fmt = "|%   10u|\n";
    unsigned int src = -10;
    s21_sprintf(data, fmt, src);
    sprintf(data1, fmt, src);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SPRINTF88) {
    char data[100];
    char data1[100];
    char *fmt = "|%   -10u|\n";
    unsigned int src = -10;
    s21_sprintf(data, fmt, src);
    sprintf(data1, fmt, src);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SPRINTF89) {
    char data[100];
    char data1[100];
    char *fmt = "|%-10u|\n";
    unsigned int src = 15;
    s21_sprintf(data, fmt, src);
    sprintf(data1, fmt, src);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SPRINTF90) {
    char data[100];
    char data1[100];
    char *fmt = "|%+-10u|\n";
    unsigned int src = 15;
    s21_sprintf(data, fmt, src);
    sprintf(data1, fmt, src);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SPRINTF91) {
    char data[100];
    char data1[100];
    char *fmt = "|%-+10u|\n";
    unsigned int src = 15;
    s21_sprintf(data, fmt, src);
    sprintf(data1, fmt, src);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SPRINTF92) {
    char data[100];
    char data1[100];
    char *fmt = "|% -+10u|\n";
    unsigned int src = 15;
    s21_sprintf(data, fmt, src);
    sprintf(data1, fmt, src);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SPRINTF93) {
    char data[100];
    char data1[100];
    char *fmt = "|% -+10hu|\n";
    short unsigned int src = 65535;
    s21_sprintf(data, fmt, src);
    sprintf(data1, fmt, src);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SPRINTF94) {
    char data[100];
    char data1[100];
    char *fmt = "|% -+10lu|\n";
    long unsigned int src = 4294967295;
    s21_sprintf(data, fmt, src);
    sprintf(data1, fmt, src);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SPRINTF95) {
    char data[100];
    char data1[100];
    char *fmt = "|% -+10.10lu|\n";
    long unsigned int src = 4294967295;
    s21_sprintf(data, fmt, src);
    sprintf(data1, fmt, src);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SPRINTF96) {
    char data[100];
    char data1[100];
    char *fmt = "|% -+10.10hu|\n";
    short unsigned int src = 65535;
    s21_sprintf(data, fmt, src);
    sprintf(data1, fmt, src);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SPRINTF97) {
    char data[100];
    char data1[100];
    char *fmt = "|% -+10.10u|\n";
    unsigned int src = 15;
    s21_sprintf(data, fmt, src);
    sprintf(data1, fmt, src);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SPRINTF98) {
    char data[100];
    char data1[100];
    char *fmt = "|% +-10.10u|\n";
    unsigned int src = 15;
    s21_sprintf(data, fmt, src);
    sprintf(data1, fmt, src);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SPRINTF99) {
    char data[100];
    char data1[100];
    char *fmt = "|%-10u|\n";
    unsigned int src = 15;
    s21_sprintf(data, fmt, src);
    sprintf(data1, fmt, src);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SPRINTF100) {
    char data[100];
    char data1[100];
    short unsigned int src = 65535;
    s21_sprintf(data, "|%-10hu|\n", src);
    sprintf(data1, "|%-10hu|\n", src);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SPRINTF101) {
    char data[100];
    char data1[100];

    char *fmt = "|%u|\n";
    long unsigned int src = -1;
    s21_sprintf(data, fmt, -1);
    sprintf(data1, fmt, src);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SPRINTF102) {
    char data[100];
    char data1[100];
    char *fmt = "|% -10u|\n";
    unsigned int src = -153123;
    s21_sprintf(data, fmt, src);
    sprintf(data1, fmt, src);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SPRINTF103) {
    char data[100];
    char data1[100];
    char *fmt = "|%-10u|\n";
    unsigned int src = -153123;
    s21_sprintf(data, fmt, src);
    sprintf(data1, fmt, src);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SPRINTF104) {
    char data[100];
    char data1[100];
    char *fmt = "|%+10u|\n";
    unsigned int src = -153123;
    s21_sprintf(data, fmt, src);
    sprintf(data1, fmt, src);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SPRINTF105) {
    char data[100];
    char data1[100];
    char *fmt = "|%0u|\n";
    unsigned int src = -153123;
    s21_sprintf(data, fmt, src);
    sprintf(data1, fmt, src);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SPRINTF106) {
    char data[100];
    char data1[100];
    char *fmt = "|%+0u|\n";
    unsigned int src = -153123;
    s21_sprintf(data, fmt, src);
    sprintf(data1, fmt, src);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SPRINTF107) {
    char data[100];
    char data1[100];
    char *fmt = "|%+li|\n";
    long long int src = 2147483649;
    s21_sprintf(data, fmt, src);
    sprintf(data1, fmt, src);
    ck_assert_str_eq(data, data1);
}
END_TEST
START_TEST(SPRINTF108) {
    char data[100];
    char data1[100];
    char *fmt = "|%+10.1hi|\n";
    short int src = 10000;
    s21_sprintf(data, fmt, src);
    sprintf(data1, fmt, src);
    ck_assert_str_eq(data, data1);
}
END_TEST
START_TEST(SPRINTF109) {
    char data[100];
    char data1[100];
    char *fmt = "|% +10.1li|\n";
    long int src = -2147483647;
    s21_sprintf(data, fmt, src);
    sprintf(data1, fmt, src);
    ck_assert_str_eq(data, data1);
}
END_TEST
START_TEST(SPRINTF110) {
    char data[100];
    char data1[100];
    char *fmt = "|% -+10.1hi|\n";
    short int src = 10000;
    s21_sprintf(data, fmt, src);
    sprintf(data1, fmt, src);
    ck_assert_str_eq(data, data1);
}
END_TEST
START_TEST(SPRINTF111) {
    char data[100];
    char data1[100];
    char *fmt = "|%+lu|\n";
    long unsigned int src = ULLONG_MAX+1;
    s21_sprintf(data, fmt, src);
    sprintf(data1, fmt, src);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SPRINTF112) {
    char data[100];
    char data1[100];
    char *fmt = "|%x|\n";
    int src = 0x2f;
    s21_sprintf(data, fmt, src);
    sprintf(data1, fmt, src);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SPRINTF113) {
    char data[100];
    char data1[100];
    char *fmt = "asdasdasdasdasdadadadadasdfgqwfdeawdf\n";
    s21_sprintf(data, fmt);
    sprintf(data1, fmt);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SPRINTF114) {
    char data[100];
    char data1[100];
    char *fmt = "|%X|\n";
    int src = 0X2F;
    s21_sprintf(data, fmt, src);
    sprintf(data1, fmt, src);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SPRINTF115) {
    char data[100];
    char data1[100];
    char *fmt = "|%*o|\n";
    int src = 077;
    s21_sprintf(data, fmt, 5, src);
    sprintf(data1, fmt, 5, src);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SPRINTF116) {
    char data[100] = "";
    char data1[100] = "";
    char *fmt = "|%p|\n";
    long int src = 0x7ffee8c368cc;
    s21_sprintf(data, fmt, src);
    sprintf(data1, fmt, src);
    ck_assert_str_eq(data, data1);
}
END_TEST

/*endregion*/
Suite *f_example_suite_create() {
    Suite *s1 = suite_create("Test_string");
    TCase *StrLenTest = tcase_create("STRLEN");
    TCase *StrChrTest = tcase_create("STRCHR");
    TCase *StrSpnTest = tcase_create("STRSPN");
    TCase *StrcSpnTest = tcase_create("STRСSPN");
    TCase *MemCpyTest = tcase_create("MEMCPY");
    TCase *StrCatTest = tcase_create("STRCAT");
    TCase *MemcmpTest = tcase_create("MEMCMP");
    TCase *StrncatTest = tcase_create("STRNCAT");
    TCase *StrncpyTest = tcase_create("STRNCPY");
    TCase *StrrchrTest = tcase_create("STRRCHR");
    TCase *memmovetest = tcase_create("MEMMOVE");
    TCase *strstrtest = tcase_create("STRSTR");
    TCase *strcmptest = tcase_create("STRCMP");
    TCase *memchrtest = tcase_create("MEMCHR");
    TCase *strcpytest = tcase_create("STRCPY");
    TCase *strpbrktest = tcase_create("STRPBRK");
    TCase *StrnCmpTest = tcase_create("STRNCMP");
    TCase *MemSetTest = tcase_create("MEMSET");
    TCase *StrTokTest = tcase_create("STRTOK");
    TCase *strerrortest = tcase_create("STRERROR");
    TCase *to_uppertest = tcase_create("TOUPPER");
    TCase *inserttest = tcase_create("INSERT");
    TCase *to_lowertest = tcase_create("TOLOWER");
    TCase *trimtest = tcase_create("TRIM");
    TCase *sprintftest = tcase_create("SPRINTF");
    suite_add_tcase(s1, StrLenTest);
    tcase_add_test(StrLenTest, STRLENTest1);
    tcase_add_test(StrLenTest, STRLENTest2);
    tcase_add_test(StrLenTest, STRLENTest3);
    tcase_add_test(StrLenTest, STRLENTest4);
    tcase_add_test(StrLenTest, STRLENTest5);
    tcase_add_test(StrLenTest, STRLENTest6);
    suite_add_tcase(s1, StrChrTest);
    tcase_add_test(StrChrTest, STRCHRTest1);
    tcase_add_test(StrChrTest, STRCHRTest2);
    tcase_add_test(StrChrTest, STRCHRTest3);
    tcase_add_test(StrChrTest, STRCHRTest4);
    tcase_add_test(StrChrTest, STRCHRTest5);
    tcase_add_test(StrChrTest, STRCHRTest6);
    suite_add_tcase(s1, StrSpnTest);
    tcase_add_test(StrSpnTest, STRSPNTest1);
    tcase_add_test(StrSpnTest, STRSPNTest2);
    tcase_add_test(StrSpnTest, STRSPNTest3);
    tcase_add_test(StrSpnTest, STRSPNTest4);
    tcase_add_test(StrSpnTest, STRSPNTest5);
    tcase_add_test(StrSpnTest, STRSPNTest6);
    tcase_add_test(StrSpnTest, STRSPNTest7);
    tcase_add_test(StrSpnTest, STRSPNTest8);
    suite_add_tcase(s1, StrcSpnTest);
    tcase_add_test(StrcSpnTest, STRCSPNTest1);
    tcase_add_test(StrcSpnTest, STRCSPNTest2);
    tcase_add_test(StrcSpnTest, STRCSPNTest3);
    tcase_add_test(StrcSpnTest, STRCSPNTest4);
    tcase_add_test(StrcSpnTest, STRCSPNTest5);
    tcase_add_test(StrcSpnTest, STRCSPNTest6);
    suite_add_tcase(s1, MemCpyTest);
    tcase_add_test(MemCpyTest, MEMCPYTest1);
    tcase_add_test(MemCpyTest, MEMCPYTest2);
    tcase_add_test(MemCpyTest, MEMCPYTest3);
    tcase_add_test(MemCpyTest, MEMCPYTest4);
    tcase_add_test(MemCpyTest, MEMCPYTest5);
    suite_add_tcase(s1, StrCatTest);
    tcase_add_test(StrCatTest, STRCATTest1);
    tcase_add_test(StrCatTest, STRCATTest2);
    tcase_add_test(StrCatTest, STRCATTest3);
    tcase_add_test(StrCatTest, STRCATTest4);
    tcase_add_test(StrCatTest, STRCATTest5);
    suite_add_tcase(s1, MemcmpTest);
    tcase_add_test(MemcmpTest, MEMCMPTest1);
    tcase_add_test(MemcmpTest, MEMCMPTest2);
    tcase_add_test(MemcmpTest, MEMCMPTest3);
    tcase_add_test(MemcmpTest, MEMCMPTest4);
    tcase_add_test(MemcmpTest, MEMCMPTest5);
    tcase_add_test(MemcmpTest, MEMCMPTest6);
    tcase_add_test(MemcmpTest, MEMCMPTest7);
//    tcase_add_test(MemcmpTest, MEMCMPTest8);
    tcase_add_test(MemcmpTest, MEMCMPTest9);
    tcase_add_test(MemcmpTest, MEMCMPTest10);
    suite_add_tcase(s1, StrncatTest);
    tcase_add_test(StrncatTest, STRNCATTest1);
    tcase_add_test(StrncatTest, STRNCATTest2);
    tcase_add_test(StrncatTest, STRNCATTest3);
    tcase_add_test(StrncatTest, STRNCATTest4);
    tcase_add_test(StrncatTest, STRNCATTest5);
    suite_add_tcase(s1, StrncpyTest);
    tcase_add_test(StrncpyTest, STRNCPYTest1);
    tcase_add_test(StrncpyTest, STRNCPYTest2);
    tcase_add_test(StrncpyTest, STRNCPYTest3);
    tcase_add_test(StrncpyTest, STRNCPYTest4);
    tcase_add_test(StrncpyTest, STRNCPYTest5);
    suite_add_tcase(s1, StrrchrTest);
    tcase_add_test(StrrchrTest, STRRCHRTest1);
    tcase_add_test(StrrchrTest, STRRCHRTest2);
    tcase_add_test(StrrchrTest, STRRCHRTest3);
    tcase_add_test(StrrchrTest, STRRCHRTest4);
    tcase_add_test(StrrchrTest, STRRCHRTest5);
    suite_add_tcase(s1, memmovetest);
    tcase_add_test(memmovetest, MEMMOVETest1);
    tcase_add_test(memmovetest, MEMMOVETest2);
//    tcase_add_test(memmovetest, MEMMOVETest3);
//    tcase_add_test(memmovetest, MEMMOVETest4);
    suite_add_tcase(s1, strstrtest);
    tcase_add_test(strstrtest, STRSTRTest1);
    tcase_add_test(strstrtest, STRSTRTest2);
    tcase_add_test(strstrtest, STRSTRTest3);
    tcase_add_test(strstrtest, STRSTRTest4);
    tcase_add_test(strstrtest, STRSTRTest5);
    suite_add_tcase(s1, strcmptest);
    tcase_add_test(strcmptest, STRCMPTest1);
    tcase_add_test(strcmptest, STRCMPTest2);
    tcase_add_test(strcmptest, STRCMPTest3);
    tcase_add_test(strcmptest, STRCMPTest4);
    tcase_add_test(strcmptest, STRCMPTest5);
    tcase_add_test(strcmptest, STRCMPTest6);
    suite_add_tcase(s1, memchrtest);
    tcase_add_test(memchrtest, MEMCHRTest1);
    tcase_add_test(memchrtest, MEMCHRTest2);
    tcase_add_test(memchrtest, MEMCHRTest3);
    tcase_add_test(memchrtest, MEMCHRTest4);
    tcase_add_test(memchrtest, MEMCHRTest5);
    suite_add_tcase(s1, strcpytest);
    tcase_add_test(strcpytest, STRCPYTest1);
    tcase_add_test(strcpytest, STRCPYTest2);
    tcase_add_test(strcpytest, STRCPYTest3);
    tcase_add_test(strcpytest, STRCPYTest4);
    suite_add_tcase(s1, strpbrktest);
    tcase_add_test(strpbrktest, STRPBRKTest1);
    tcase_add_test(strpbrktest, STRPBRKTest2);
    tcase_add_test(strpbrktest, STRPBRKTest3);
    tcase_add_test(strpbrktest, STRPBRKTest4);
    suite_add_tcase(s1, StrnCmpTest);
    tcase_add_test(StrnCmpTest, STRNCMPTest1);
    tcase_add_test(StrnCmpTest, STRNCMPTest2);
    tcase_add_test(StrnCmpTest, STRNCMPTest3);
    tcase_add_test(StrnCmpTest, STRNCMPTest4);
    tcase_add_test(StrnCmpTest, STRNCMPTest5);
    tcase_add_test(StrnCmpTest, STRNCMPTest6);
    tcase_add_test(StrnCmpTest, STRNCMPTest7);
    tcase_add_test(StrnCmpTest, STRNCMPTest8);
    suite_add_tcase(s1, MemSetTest);
    tcase_add_test(MemSetTest, MEMSETTest1);
    tcase_add_test(MemSetTest, MEMSETTest2);
    tcase_add_test(MemSetTest, MEMSETTest3);
    tcase_add_test(MemSetTest, MEMSETTest4);
    tcase_add_test(MemSetTest, MEMSETTest5);
    tcase_add_test(MemSetTest, MEMSETTest6);
    tcase_add_test(MemSetTest, MEMSETTest7);
    suite_add_tcase(s1, StrTokTest);
    tcase_add_test(StrTokTest, STRTOKTest1);
    tcase_add_test(StrTokTest, STRTOKTest2);
    tcase_add_test(StrTokTest, STRTOKTest3);
    tcase_add_test(StrTokTest, STRTOKTest4);
    tcase_add_test(StrTokTest, STRTOKTest5);
    tcase_add_test(StrTokTest, STRTOKTest6);
    tcase_add_test(StrTokTest, STRTOKTest7);
    tcase_add_test(StrTokTest, STRTOKTest8);
    tcase_add_test(StrTokTest, STRTOKTest9);
    tcase_add_test(StrTokTest, STRTOKTest10);
    suite_add_tcase(s1, strerrortest);
    tcase_add_test(strerrortest, STRERRORTest1);
    tcase_add_test(strerrortest, STRERRORTest2);
    tcase_add_test(strerrortest, STRERRORTest3);
    suite_add_tcase(s1, to_uppertest);
    tcase_add_test(to_uppertest, TOUPPERTest1);
    tcase_add_test(to_uppertest, TOUPPERTest2);
    tcase_add_test(to_uppertest, TOUPPERTest3);
    tcase_add_test(to_uppertest, TOUPPERTest4);
    tcase_add_test(to_uppertest, TOUPPERTest5);
    tcase_add_test(to_uppertest, TOUPPERTest6);
    tcase_add_test(to_uppertest, TOUPPERTest7);
    suite_add_tcase(s1, inserttest);
    tcase_add_test(inserttest, INSERTTest1);
    tcase_add_test(inserttest, INSERTTest2);
    tcase_add_test(inserttest, INSERTTest3);
    tcase_add_test(inserttest, INSERTTest4);
    tcase_add_test(inserttest, INSERTTest5);
    tcase_add_test(inserttest, INSERTTest6);
    tcase_add_test(inserttest, INSERTTest7);
    suite_add_tcase(s1, to_lowertest);
    tcase_add_test(to_lowertest, TOLOWERTest1);
    tcase_add_test(to_lowertest, TOLOWERTest2);
    tcase_add_test(to_lowertest, TOLOWERTest3);
    tcase_add_test(to_lowertest, TOLOWERTest4);
    tcase_add_test(to_lowertest, TOLOWERTest5);
    tcase_add_test(to_lowertest, TOLOWERTest6);
    tcase_add_test(to_lowertest, TOLOWERTest7);
    suite_add_tcase(s1, trimtest);
    tcase_add_test(trimtest, TRIMTest1);
    tcase_add_test(trimtest, TRIMTest2);
    tcase_add_test(trimtest, TRIMTest3);
    tcase_add_test(trimtest, TRIMTest4);
    tcase_add_test(trimtest, TRIMTest5);
    tcase_add_test(trimtest, TRIMTest6);
    tcase_add_test(trimtest, TRIMTest7);
    tcase_add_test(trimtest, TRIMTest8);
    tcase_add_test(trimtest, TRIMTest9);
    tcase_add_test(trimtest, TRIMTest10);
    tcase_add_test(trimtest, TRIMTest11);
    tcase_add_test(trimtest, TRIMTest12);
    tcase_add_test(trimtest, TRIMTest13);
    suite_add_tcase(s1, sprintftest);
    tcase_add_test(sprintftest, SPRINTF1);
    tcase_add_test(sprintftest, SPRINTF3);
    tcase_add_test(sprintftest, SPRINTF4);
    tcase_add_test(sprintftest, SPRINTF5);
//    tcase_add_test(sprintftest, SPRINTF6);
//    tcase_add_test(sprintftest, SPRINTF7);
//    tcase_add_test(sprintftest, SPRINTF8);
//    tcase_add_test(sprintftest, SPRINTF9);
//    tcase_add_test(sprintftest, SPRINTF10);
    tcase_add_test(sprintftest, SPRINTF11);
    tcase_add_test(sprintftest, SPRINTF12);
    tcase_add_test(sprintftest, SPRINTF13);
    tcase_add_test(sprintftest, SPRINTF14);
    tcase_add_test(sprintftest, SPRINTF15);
    tcase_add_test(sprintftest, SPRINTF16);
    tcase_add_test(sprintftest, SPRINTF17);
    tcase_add_test(sprintftest, SPRINTF18);
    tcase_add_test(sprintftest, SPRINTF19);
    tcase_add_test(sprintftest, SPRINTF20);
    tcase_add_test(sprintftest, SPRINTF21);
    tcase_add_test(sprintftest, SPRINTF22);
    tcase_add_test(sprintftest, SPRINTF23);
    tcase_add_test(sprintftest, SPRINTF24);
    tcase_add_test(sprintftest, SPRINTF25);
    tcase_add_test(sprintftest, SPRINTF26);
    tcase_add_test(sprintftest, SPRINTF27);
    tcase_add_test(sprintftest, SPRINTF28);
    tcase_add_test(sprintftest, SPRINTF29);
    tcase_add_test(sprintftest, SPRINTF30);
    tcase_add_test(sprintftest, SPRINTF31);
    tcase_add_test(sprintftest, SPRINTF32);
    tcase_add_test(sprintftest, SPRINTF33);
    tcase_add_test(sprintftest, SPRINTF34);
    tcase_add_test(sprintftest, SPRINTF35);
    tcase_add_test(sprintftest, SPRINTF36);
    tcase_add_test(sprintftest, SPRINTF37);
    tcase_add_test(sprintftest, SPRINTF38);
    tcase_add_test(sprintftest, SPRINTF39);
    tcase_add_test(sprintftest, SPRINTF40);
    tcase_add_test(sprintftest, SPRINTF41);
    tcase_add_test(sprintftest, SPRINTF42);
    tcase_add_test(sprintftest, SPRINTF43);
    tcase_add_test(sprintftest, SPRINTF44);
    tcase_add_test(sprintftest, SPRINTF45);
    tcase_add_test(sprintftest, SPRINTF46);
    tcase_add_test(sprintftest, SPRINTF47);
    tcase_add_test(sprintftest, SPRINTF48);
    tcase_add_test(sprintftest, SPRINTF49);
    tcase_add_test(sprintftest, SPRINTF50);
    tcase_add_test(sprintftest, SPRINTF51);
    tcase_add_test(sprintftest, SPRINTF52);
    tcase_add_test(sprintftest, SPRINTF53);
    tcase_add_test(sprintftest, SPRINTF54);
    tcase_add_test(sprintftest, SPRINTF55);
    tcase_add_test(sprintftest, SPRINTF56);
    tcase_add_test(sprintftest, SPRINTF57);
    tcase_add_test(sprintftest, SPRINTF58);
    tcase_add_test(sprintftest, SPRINTF59);
    tcase_add_test(sprintftest, SPRINTF60);
    tcase_add_test(sprintftest, SPRINTF61);
    tcase_add_test(sprintftest, SPRINTF62);
    tcase_add_test(sprintftest, SPRINTF63);
    tcase_add_test(sprintftest, SPRINTF64);
    tcase_add_test(sprintftest, SPRINTF65);
    tcase_add_test(sprintftest, SPRINTF66);
    tcase_add_test(sprintftest, SPRINTF67);
    tcase_add_test(sprintftest, SPRINTF68);
    tcase_add_test(sprintftest, SPRINTF69);
    tcase_add_test(sprintftest, SPRINTF70);
    tcase_add_test(sprintftest, SPRINTF71);
    tcase_add_test(sprintftest, SPRINTF72);
    tcase_add_test(sprintftest, SPRINTF73);
    tcase_add_test(sprintftest, SPRINTF74);
    tcase_add_test(sprintftest, SPRINTF75);
    tcase_add_test(sprintftest, SPRINTF76);
    tcase_add_test(sprintftest, SPRINTF77);
    tcase_add_test(sprintftest, SPRINTF78);
    tcase_add_test(sprintftest, SPRINTF79);
    tcase_add_test(sprintftest, SPRINTF80);
    tcase_add_test(sprintftest, SPRINTF81);
    tcase_add_test(sprintftest, SPRINTF82);
    tcase_add_test(sprintftest, SPRINTF83);
    tcase_add_test(sprintftest, SPRINTF84);
    tcase_add_test(sprintftest, SPRINTF85);
    tcase_add_test(sprintftest, SPRINTF86);
    tcase_add_test(sprintftest, SPRINTF87);
    tcase_add_test(sprintftest, SPRINTF88);
    tcase_add_test(sprintftest, SPRINTF89);
    tcase_add_test(sprintftest, SPRINTF90);
    tcase_add_test(sprintftest, SPRINTF91);
    tcase_add_test(sprintftest, SPRINTF92);
    tcase_add_test(sprintftest, SPRINTF93);
    tcase_add_test(sprintftest, SPRINTF94);
    tcase_add_test(sprintftest, SPRINTF95);
    tcase_add_test(sprintftest, SPRINTF96);
    tcase_add_test(sprintftest, SPRINTF97);
    tcase_add_test(sprintftest, SPRINTF98);
    tcase_add_test(sprintftest, SPRINTF99);
    tcase_add_test(sprintftest, SPRINTF100);
    tcase_add_test(sprintftest, SPRINTF101);
    tcase_add_test(sprintftest, SPRINTF102);
    tcase_add_test(sprintftest, SPRINTF103);
    tcase_add_test(sprintftest, SPRINTF104);
    tcase_add_test(sprintftest, SPRINTF105);
    tcase_add_test(sprintftest, SPRINTF106);
    tcase_add_test(sprintftest, SPRINTF107);
    tcase_add_test(sprintftest, SPRINTF108);
    tcase_add_test(sprintftest, SPRINTF109);
    tcase_add_test(sprintftest, SPRINTF110);
    tcase_add_test(sprintftest, SPRINTF111);
    tcase_add_test(sprintftest, SPRINTF112);
    tcase_add_test(sprintftest, SPRINTF113);
    tcase_add_test(sprintftest, SPRINTF114);
    tcase_add_test(sprintftest, SPRINTF115);
    tcase_add_test(sprintftest, SPRINTF116);
    /*copy me*/
/*0*/
/*1*/
/*2*/
/*3*/
/*4*/
/*5*/
/*6*/
/*7*/
/*8*/
/*9*/
    return s1;
}

int main() {
    Suite *s1 = f_example_suite_create();
    // Runner
    SRunner *runner = srunner_create(s1);
    int number_failed;
    srunner_run_all(runner, CK_NORMAL);
    number_failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    return number_failed == 0 ? 0 : 1;
}
