#include <stdio.h>

int main (void) {
    int dividend;
    int counter = 0;
    
    printf("Enter number:");
    scanf("%d", &dividend);
    
    int factor = 1, total = 0;
    printf("The factors of %d are:\n", dividend);
    while (counter <= dividend) {   
     
    if (dividend % factor == 0) {    
    printf("%d\n", factor);
    total += factor;
    
    }
    factor++;
    counter++;
    
    }
    printf("Sum of factors = %d\n", total); 
    if (dividend == total - dividend) {
    printf("%d is a perfect number\n", dividend);
    } else { printf("%d is not a perfect number\n", dividend);}
    
    return 0;
    }
    
    
    
    
