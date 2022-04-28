#all, clean, test, s21_string.a, gcov_report
CC = gcc
FLAGS = -Wall -Werror -Wextra

TARGET=test.c

all: build

build: s21_string.a test

clean:
	rm s21_string.a
	rm s21_string.o
	rm test

rebuild: clean build

s21_string.a:
	$(CC) $(FLAGS) -c -o s21_string.o s21_string.c
	ar rcs s21_string.a s21_string.o

test: s21_string.a
	$(CC) $(FLAGS) -lcheck s21_string.c test.c  -o test

gcov_report: test
	#TODO jarrusab

run_test:
	$(MAKE) clean
	$(MAKE) test
	./test
