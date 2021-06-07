//Reads characters from its input and writes the characters to its output encrypted with a Substitution cipher.
//The mapping will be given to your program as a single command line argument. This command line argument will contain 26 characters: an ordering of the letters 'a'..'z'.
//Written by Xiao Hu z5223731 in 10/04/2019.

#include <stdio.h>
#define Difference 32

int subs_cipher(char *argv[], int read_character);

//Using argv[1][j]
int main (int argc, char *argv[]) {
    int read_character = getchar();
    while (read_character != EOF) {
        
        putchar(subs_cipher(argv, read_character));
        read_character = getchar();
        
    }
    
    return 0;
}

int subs_cipher(char *argv[], int read_character) {
    int diff = 0;
    if (read_character >= 'a' && read_character <= 'z') {   
        diff = read_character - 'a';
        return argv[1][diff];
    } else if (read_character >= 'A' && read_character <= 'Z') {
        diff = read_character - 'A';
        return argv[1][diff] - Difference;
    } else {
        return read_character;
    }
} 
    
