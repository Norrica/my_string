#include "s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
    int result;
    while (n && *str1 && (*str1 == *str2)) {
        str1++;
        str2++;
        n--;
    }
    if (n == 0)
        result = 0;
    else
        result = *(unsigned char*)str1 - *(unsigned char*)str2;
    return result;
}

 int main ()
 {
   char str[][5] = { "R2D2" , "C3PO" , "R2A6" };
   int n;
   puts ("Looking for R2 astromech droids...");
   for (n=0 ; n<3 ; n++)
     if (s21_strncmp (str[n],"R2xx",2) == 0)
     {
       printf ("found %s\n",str[n]);
     }
   return 0;
 }