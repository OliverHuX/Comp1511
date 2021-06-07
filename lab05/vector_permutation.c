#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1000

void permutation1(int length,int vector[MAX_SIZE], int permutation[MAX_SIZE]);


int main (void) {
    int length;
    
    printf("Enter vector length: ");
    scanf("%d", &length);
    
    int vector[MAX_SIZE] = {0};
    
    printf("Enter vector: ");
    int i = 0;
    while (i < length) {
        scanf("%d", &vector[i]);
    i++;
    }
    
    int permutation[MAX_SIZE] = {0};
    printf("Enter permutation: ");
    i = 0;
    while (i < length) {
        scanf("%d", &permutation[i]);
    i++;
    }
    
    permutation1(length, vector, permutation);
    
    printf("\n");
    
    return 0;
}
    
    
void permutation1(int length,int vector[MAX_SIZE], int permutation[MAX_SIZE]) {
    int a = 0;
    int b = 0;
    
    while (b < length) {
       
        while (a < length) {
            if (permutation[a] >= length) {
                printf("Invalid permutation\n");
                exit(0);          
            }
        a++;
        }
        printf("%d ", vector[permutation[b]]);
        b++;
    }
    
    return;
}
    
    
    
