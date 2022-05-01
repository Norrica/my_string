#include <stdio.h>
#include <stdlib.h>

char* convert_to_char(int num) {
    char * nums = "0123456789";
    int len = 0, temp = num;
    while (temp) {
        // int curr = temp %10;
        temp /= 10;
        len++;
        }
    
    char *converted = malloc(len*sizeof(char));
    int i = len-1;
    while (num)
    {
        converted[i--]=nums[num%10];
        num/=10;
    }
    
    return converted;
}



int main() {
    int num = 999;
    convert_to_char(num);

    printf("%s", convert_to_char(num));
    return 0;
}