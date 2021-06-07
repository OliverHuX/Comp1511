#include <stdio.h>

int main (void) {
    int totalMark;
    double awarded;
    double percentage;
    
    printf("Enter the total number of marks in the exam: ");
    scanf("%d", &totalMark);
    printf("Enter the number of marks the student was awarded: ");
    scanf("%lf", &awarded);
    
    percentage = (awarded/totalMark)*100;
    
    printf("The student scored %.0lf%% in this exam.\n", percentage);
    
    return 0;
    
    }
