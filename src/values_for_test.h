//
// Created by Taren Greyjoy on 5/6/22.
//

typedef struct s {
  const void *str1;
  const void *str2;
  int c;
  size_t n;
} test;

static test values[5] = {
    {"Hello world\0", "Hello world\0", '\0', 12},
    {"Hello world\n\0", "Hello world\n", '\n', 12},
    {"a\n\0", "a\n", 'a', 2},
    {" \0", " ", ' ', 1},
    {"\n\0", "\n", ' ', 1},
};