#include <stdio.h>
#include <math.h>

#define MAX_SIZE 1000


double distance(int length, double vector1[MAX_SIZE], double vector2[MAX_SIZE]);
       
int main (void) {
    int length;
    
    printf("Enter vector length: ");
    scanf("%d", &length);
    
    double vector1[MAX_SIZE] = {0};
    double vector2[MAX_SIZE] = {0};
    
    printf("Enter vector 1: ");
    int i = 0;
    while (i < length) {
        scanf("%lf", &vector1[i]);
    i++;
    }
    
    printf("Enter vector 2: ");
    i = 0;
    while (i < length) {
        scanf("%lf", &vector2[i]);
    i++;
    }
    
    printf("Euclidean distance = %lf\n", distance(length, vector1, vector2));
    
    
    return 0;
    
}

double distance(int length, double vector1[MAX_SIZE], double vector2[MAX_SIZE]) {
    double D;
    double sum = 0;
    int i = 0;
    while (i < length) {       
        sum += (vector1[i] - vector2[i]) * (vector1[i] - vector2[i]);
        i++;
    }
        
    D = sqrt(sum);
    
    return D;
    }
 


