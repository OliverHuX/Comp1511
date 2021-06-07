#include <stdio.h>

#define STANDARD_AGE 12
#define DIFFERENCE 7

int main (void) {
    int age;
    int minDatingAge;
    int maxDatingAge;
    
    printf("Enter your age: ");
    scanf("%d", &age);
    
    if (age < STANDARD_AGE) {
    printf("You are too young to be dating.\n");
    } else {
      minDatingAge = age/2 + DIFFERENCE;
      maxDatingAge = (age - 7)*2;
      printf("Your dating range is %d to %d years old.\n", minDatingAge, maxDatingAge); 
      }
    return 0;
}  
    
