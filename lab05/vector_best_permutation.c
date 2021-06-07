#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX_SIZE 100

//This is what I create to calculate the distance between two vectors 
double distance(int length, double vector1[MAX_SIZE], double vector2[MAX_SIZE]);             
//permutation function      
void Permutation(int length, int permutation[MAX_SIZE], double vector2[MAX_SIZE], double vector1[MAX_SIZE]);
       
       
int main (void) {
    int length;
    
    printf("Enter vector length: ");
    scanf("%d", &length);
    
    double vector1[MAX_SIZE] = {0};
    double vector2[MAX_SIZE] = {0};
    int permutation[MAX_SIZE] = {0};
    
    printf("Enter vector1: ");
    int i = 0;
    while (i < length) {
        scanf("%lf", &vector1[i]);
    i++;
    }
    
    printf("Enter vector2: ");
    i = 0;
    while (i < length) {
        scanf("%lf", &vector2[i]);
    i++;
    }
    
    
    
/*    int g = 0;
    while (g < length) {
        int e = 0;
        int f = 1;
        int tepV = vector1[e];
        while (f < length) {
            
            if (vector1[e] < vector1[f]) {         //loop for decreasing order
                vector1[e] = vector1[f];
                vector1[f] = tepV;
                }
                e++;
                f++;
                }
        g++;
    }
        
    g = 0;    
    while (g < length) {
        int e = 0;
        int f = 1;
        int tepV = vector2[e];
        while (f < length) {
            
            if (vector2[e] < vector2[f]) {
                vector2[e] = vector2[f];
                vector2[f] = tepV;
                }
                e++;
                f++;
                }
        g++;
    }            
*/    
       
    Permutation(length, permutation, vector1, vector2);
    
    printf("Euclidean distance = %lf\n", distance(length, vector1, vector2));
    
    
    return 0;
    
}

void Permutation(int length, int permutation[MAX_SIZE], double vector2[MAX_SIZE], double vector1[MAX_SIZE]) {
    int a = 0, rank[MAX_SIZE], rank1[MAX_SIZE], rank2[MAX_SIZE], b = 0, r = 0, j = 0;   
    while (a < length) {
        b = 0;
        r = 0;
        while (b < length) {
        if (vector2[a] < vector2[b]) {
        r++;
        }
        b++;
        }
        rank2[a] = r;
        a++;
    }
    
    a = 0;
    while (a < length) {
        b = 0;
        r = 0;
        while (b < length) {
        if (vector1[a] < vector1[b]) {
        r++;
        }
        b++;
        }
        rank1[a] = r;
        a++;
    }
    
    a = 0;
    while (a < length) {
        b = 0;
        while (b < length) {
        if (rank1[b] == rank2[a]) {
            rank[j] = b;
            j++;
        }
        b++;
        }
        a++;
        }
    
    a = 0;
    printf("Optimal permutation: ");
    while (a < length) {
        if (a == length - 1) {
        printf("%d\n", rank[a]);
        } else {
        printf("%d ", rank[a]);
        }
        a++;
    }

   
    return;
}
 
 
double distance(int length, double vector1[MAX_SIZE], double vector2[MAX_SIZE]) {
    double D;
    double sum = 0;
    int c = 0;
    while (c < length) {       
        sum += (vector1[c] - vector2[c]) * (vector1[c] - vector2[c]);
        c++;
    }
        
    D = sqrt(sum);
    
    return D;
    } 
