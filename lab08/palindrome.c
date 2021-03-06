//This program reads input and check it is palindrome or not
//Written by Xiao Hu z5223731 in 14/04/2019

#include <stdio.h>
#define MAX 4096

int main (void) {
    char str[MAX];
    printf("Enter a string: ");
    fgets(str, MAX, stdin);
    int i = 0, j = 0, index = 1;
    while (str[i] != '\n' && str[i] != '\0') {
        i++;
    }

    while (j < i) {
        if (str[j] != str[i-1]) {
            index = 0;
            j = i;
        }
        i--;
        j++;
    }
    
    if (index == 1) {
        printf("String is a palindrome\n");
    } else {
        printf("String is not a palindrome\n");
    }
    
    return 0;
}
        
