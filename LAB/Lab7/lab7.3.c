#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

#define NUM 3

typedef struct {
    float Re;
    float Im;
} Complex;

float CRadius(Complex c);
int Cmax(Complex *A, int size);

int main() {
    float a1, b1;
    printf("Enter 3 complex numbers:\n");
    Complex A[NUM];
    for (int i = 0; i < NUM; i++) {
        scanf("%f %f", &a1, &b1); // Use %f for float
        A[i].Re = a1;
        A[i].Im = b1;
    }
    
    int maxone = Cmax(A, NUM);
    printf("The max complex number is %.2f+%.2fi\n", A[maxone].Re, A[maxone].Im);
    printf("The radius of the max number is %.2f\n", CRadius(A[maxone]));

    return 0;
}

float CRadius(Complex c) {
    return sqrt(c.Im * c.Im + c.Re * c.Re);
}

int Cmax(Complex *A, int size) {
    float maxRadius = 0; 
    int locmaxOne = 0;
    for (int i = 0; i < size; i++) {
        float radius = CRadius(A[i]);
        if (maxRadius < radius) {
            maxRadius = radius;
            locmaxOne = i;
        }
    }
    return locmaxOne;
}


