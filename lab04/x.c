#include <stdio.h>

int main (void) {
    int size;
    
    printf("Enter size: ");
    scanf("%d", &size);
    
    int counter = 0;
    int x = 1;
    int position = 1;
    int bound = size;
    int a = 0;
    while (counter < size) {
    
    while (a < size) {
    if (x == position || x == bound) {
    printf("*");
    
    } else {printf("-");}
    a++;
    position++;
    bound--;
    
    }
    a = 0;
    position = 1;
    bound = size;
    
  
   
    
    
   
    
    printf("\n");   
    counter++;
    x++;
    }
    
}
    
