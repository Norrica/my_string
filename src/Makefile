#all, clean, test, s21_string.a, gcov_report
CC = gcc
FLAGS = -Wall -Werror -Wextra


all: build

build: s21_string.a

clean:
	rm s21_string.a

rebuild: clean build

s21_string.a:
	$(CC) $(FLAGS) -c -o s21_string.o s21_string.c
	ar rcs s21_string.a s21_string.o

test: build
	$(CC) $(FLAGS) -lcheck s21_string.c test.c
gcov_report: test
	#TODO jarrusab

run_test: test
	./a.out