#include <stdio.h>

int main (void){
    int number;
    
    printf("Please enter an integer: ");
    scanf("%d", &number);
    
    if (number > 5) {
    
    printf(" You entered a number greater than five.\n");
    
    } else if (number < 1) {
      
      printf("You entered a number less than one.\n");
      
      } else if (number == 1) {
        
        printf("You entered one.\n");
        
        } else if (number == 2) {
          printf("You entered two.\n");
          } else if (number == 3) {
            printf("You entered Three.\n");
            } else if (number == 4) {
              printf("You entered four.\n");
              } else {
                printf("You entered five.\n");
                }
     
     return 0;
}  
