#all, clean, test, s21_string.a, gcov_report
CC = gcc
CFLAGS =   -Wall -Werror -Wextra -ggdb3

TARGET=test.c

.PHONY : all build clean

all: build
.DBG: CFLAGS += -g
build: test

debug:CFLAGS += -DDEV
debug:CFLAGS += -g
debug: local_debug
	./local_test

clean:
	-rm s21_string.a
	-rm s21_string.o
	-rm test
	-rm *.gc*
	-rm -rf report
	-rm *.info

rebuild: clean build

s21_string.a: clean
	$(CC) $(CFLAGS) -c s21_string.c -o s21_string.o
	ar rcs s21_string.a s21_string.o

test: s21_string.a
	$(CC) $(CFLAGS) s21_string.c test.c  -o test -lcheck

gcov_report:CFLAGS += -fprofile-arcs -ftest-coverage
gcov_report: test
	./test
	gcov test.c
	geninfo . -b . -o ./test.info
	genhtml test.info --output-directory report

local_debug:
		$(CC) $(CFLAGS) -DDEV -g s21_string.c useful.c -o local_test


