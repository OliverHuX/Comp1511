//This program reads characters from its input and writes the characters to its output encrypted with a Caesar cipher.
//This program is wirten by XIAO HU(z5223731) in 08/04/2019.
#include <stdio.h>
#include <stdlib.h>

int Caesar_cipher(int read_character, char *argv[]);

int main(int argc, char *argv[]) {

    int read_character = getchar();
    
    while (read_character != EOF) {
        
        putchar(Caesar_cipher(read_character, argv));
        read_character = getchar();
    }
    
    return 0;
}

int Caesar_cipher(int read_character, char *argv[]) {
    int Caesar_cipher = 0, num = atoi(argv[1]);
    
    if (num > 26) {
        num = num % 26;
    } else if (num < -26) {
        while (num < -26) {
        num = num + 26;
        } 
    } else {
        num = atoi(argv[1]);
    }
           
    if (read_character >= 'a' && read_character <= 'z') {
        Caesar_cipher = read_character + num;
        if (Caesar_cipher < 'a') {
            while (Caesar_cipher < 'a') {
                Caesar_cipher += 26;
            }
            return Caesar_cipher;
        } else if (Caesar_cipher > 'z') {
            while (Caesar_cipher > 'z') {
                Caesar_cipher -= 26;
            }
            return Caesar_cipher;
        } else {
            return Caesar_cipher;
        }
    } else if (read_character >= 'A' && read_character <= 'Z') {
        Caesar_cipher = read_character + num;
        if (Caesar_cipher < 'A') {
            while (Caesar_cipher < 'A') {
                Caesar_cipher += 26;
            }
            return Caesar_cipher;
        } else if (Caesar_cipher > 'Z') {
            while (Caesar_cipher > 'Z') {
                Caesar_cipher -= 26;
            }
            return Caesar_cipher;
        } else {
            return Caesar_cipher;
        }
    } else {
        return read_character;
    }
}
        
            
    
/*
    while (num > 26) {
        num = atoi(argv[1]) % 26;
    }
    
    Caesar_cipher = read_character + num;  
    if(read_character >= 'a' && read_character <= 'z') {
    
        if (Caesar_cipher < 'a') {
            while (read_character + num < 'a') {
                Caesar_cipher += 26;
            }
        } else {
            while (Caesar_cipher > 'z') {
                Caesar_cipher -= 26;
            }
        } 
     
    }
    
    if(read_character >= 'A' && read_character <= 'Z') {
    
        if (Caesar_cipher < 'A') {
            while (Caesar_cipher < 'A') {
                Caesar_cipher += 26;
            }
        } else {
            while (Caesar_cipher > 'Z') {
                Caesar_cipher -= 26;
            }
        } 
    return Caesar_cipher;
    } 
       
    if (Caesar_cipher <= 'z' && 
        Caesar_cipher >= 'a') {
        
        return Caesar_cipher;
        
    } else if (Caesar_cipher <= 'Z' && 
               Caesar_cipher >= 'A') {
               
        return Caesar_cipher;
    } else {
        return read_character;
    }
}

    */
    
    
        



