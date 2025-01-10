#define _CRT_SECURE_NO_WARNINGS  // Disable warnings for using unsafe functions like scanf
#include <stdio.h>
#include <stdlib.h>

// Function declarations
double *inputArithmetic(double *a1, double *d, int *n);
double setArithmetic(double a1, double d, double *arr, int n);

int main() {
    double a1, d, sum, *A;
    int n;

    while (1) {
        // Get user input for arithmetic sequence parameters
        A = inputArithmetic(&a1, &d, &n);
        
        // If input is invalid, exit the loop
        if (A == NULL) {
            printf("Thank you for exploring arithmetic sequences and dynamic allocations of arrays.\n");
            break;
        }

        // Set arithmetic sequence and calculate its sum
        sum = setArithmetic(a1, d, A, n);
        
        // Print the sequence elements
        for (int i = 0; i < n; i++) {
            printf(" %10lf", A[i]);
            if ((i + 1) % 5 == 0) {
                printf("\n\n");
            }
        }
        
        // Print the sum of the sequence elements
        printf("\nThe sum of the sequence elements is: %lf\n", sum);
        
        // Free the allocated memory
        free(A);
    }

    return 0;
}

/**
 * inputArithmetic - Prompts the user to input the first term, common difference, and number of terms for an arithmetic sequence.
 *  a1: Pointer to store the first term of the sequence.
 *  d: Pointer to store the common difference of the sequence.
 *  n: Pointer to store the number of terms in the sequence.
 * return: Pointer to the dynamically allocated array for the sequence or NULL if n <= 0.
 */
double *inputArithmetic(double *a1, double *d, int *n) {
    printf("Please enter a1, d and n: ");
    scanf("%lf %lf %d", a1, d, n);
    
    // If the number of terms is not positive, return NULL
    if (*n <= 0) {
        return NULL;
    }
    
    // Allocate memory for the sequence
    double *A = (double *)malloc(*n * sizeof(double));
    if (A == NULL) {
        printf("Error: memory allocation failed.\n");
        exit(1);
    }
    return A;
}

/**
 * setArithmetic - Fills an array with the elements of an arithmetic sequence and calculates the sum of the elements.
 *  a1: The first term of the sequence.
 *  d: The common difference of the sequence.
 *  arr: The array to be filled with the sequence elements.
 *  n: The number of terms in the sequence.
 * return: The sum of the sequence elements.
 */
double setArithmetic(double a1, double d, double *arr, int n) {
    double sum = 0;
    
    // Calculate each term of the sequence and accumulate the sum
    for (int i = 0; i < n; i++) {
        arr[i] = a1 + i * d;
        sum += arr[i];
    }
    return sum;
}






