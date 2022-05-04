#all, clean, test, s21_string.a, gcov_report
CC = gcc
FLAGS = -Wall -Werror -Wextra -fprofile-arcs -ftest-coverage

TARGET=test.c my_atof.c

all: build

build: s21_string.a test

debug:
FLAGS += -g -O0


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
	FLAGS += -fprofile-arcs -ftest-coverage
	$(CC) $(FLAGS) -lcheck s21_string.a test.c  -o test

gcov_report: test
	./test
	gcov test.c
	geninfo . -b . -o ./test.info
	genhtml test.info --output-directory report

local_debug:
		$(CC) -Wall -Werror -Wextra s21_string.c -o local_test
.PHONY : all build clean
