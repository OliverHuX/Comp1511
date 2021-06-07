//This C program reads characters from its input and writes the same characters to its output, except it does not write lower case vowel(a, e, i, o, u)
//This program is wirten by XIAO HU(z5223731) in 04/04/2019.


#include <stdio.h>

void hidden_lower_case_vowel(int read_character,char v1, char v2, char v3, char v4, char v5);

int main (void) {
    char v1 = 'a', v2 = 'e', v3 = 'i', v4 = 'o', v5 = 'u';
    int read_character = getchar();
    
    while (read_character != EOF) {
        
        hidden_lower_case_vowel(read_character, v1, v2, v3, v4, v5);
        read_character = getchar(); 
        
    }
    return 0;
}

void hidden_lower_case_vowel(int read_character, char v1, char v2, char v3, char v4, char v5) {
    int lower_case = read_character;
    if (read_character != v1 && read_character != v2 &&
        read_character != v3 && read_character != v4 &&
        read_character != v5) {
        putchar(lower_case);
    }
    return;   
}
        

