#all, clean, test, s21_string.a, gcov_report
CC = gcc
FLAGS =   #-Wall -Werror -Wextra

TARGET=test.c

all: build
.DBG: FLAGS += -g -O0
build: s21_string.a test

debug:FLAGS += -DDEV
debug:FLAGS += -g -O0
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
	$(CC) $(FLAGS) -c -o s21_string.o s21_string.c
	ar rcs s21_string.a s21_string.o

test: s21_string.a
	$(CC) $(FLAGS) -lcheck s21_string.a test.c  -o test

gcov_report:FLAGS += -fprofile-arcs -ftest-coverage
gcov_report: test
	./test
	gcov test.c
	geninfo . -b . -o ./test.info
	genhtml test.info --output-directory report

local_debug:
		$(CC) $(FLAGS) s21_string.c -o local_test

.PHONY : all build clean
