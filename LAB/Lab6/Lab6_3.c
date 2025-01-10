#include<stdio.h>
#include<stdlib.h>

// function prototypes
void set_2d(float** a, int m, int n);
void print_2d(float** a, int m, int n);

int main( ){
	int m, n, i;
	float** a;
    // Prompt the user to enter dimensions of the 2d array.
	printf("\nenter m and n, for m*n array: \n");
	scanf("%d %d", &m, &n);
	// Allocate memory for 2D array
	a = (float**)malloc(m*sizeof(float*)); // Allocate memory for m row pointers
	for (int i=0;i<m;i++){
		a[i] = (float*)malloc(n*sizeof(float));// Allocate memory for n columns in each row
	}
    // Set values in the 2D array
	set_2d(a,m,n);
	// Print the 2D array
    print_2d(a,m,n);
	// Free the allocated memory
	for (int i=0;i<m;i++){
		free(a[i]);// Free memory for each row
	}
	free(a);// Free memory for the row pointers
    return 0;   
}
/**
 * Function to set values in the 2D array
 * a Pointer to the 2D array
 * m Number of rows
 * n Number of columns
 */
void set_2d(float** a,int m,int n){
	int k=1;// Initialize the starting value
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			a[i][j]=k++;// Assign values to the array elements incrementally
		}
	}
}
/**
 * Function to print the 2D array
 * a Pointer to the 2D array
 * m Number of rows
 * n Number of columns
 */
void print_2d(float** a,int m,int n){
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			printf("%8.1f",a[i][j]);// Print each element formatted to 1 decimal place
		}
		printf("\n");// Move to the next line after each row
	}
}
