#all, clean, test, s21_string.a, gcov_report
CC = gcc
FLAGS = -Wall -Werror -Wextra

TARGET=test.c

all: build

build: s21_string.a test

global_debug: FLAGS += -g -O0
global_debug: test

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

local_debug:
		$(CC) $(FLAGS) -g s21_string.c -o local_test
.PHONY : all debug_test clean