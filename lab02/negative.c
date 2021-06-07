//Don't be negative 
//setup number variables
//ask users to enter number
//check the number is positive or negative or zero
//show "u have entered a positive number." if users enter positive number, when users enter negative number then show "Don't be negative." otherwise show "u have entered zero."

#include <stdio.h>

int main (void) {
    int number;
    
    printf(" ");
    scanf("%d", &number);
    
    if(number > 0) {
     printf("You have entered a positive number.\n");
    } 
     else if(number == 0) {
     printf("You have entered zero.\n");
     }
     else {
     printf("Don't be so negative!\n");
     }
    
    return 0;
}    
    
