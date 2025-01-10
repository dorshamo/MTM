#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 100
#define ROWS 3
#define COLS 5

void order(int a[][MAX], int rows, int cols, int x);//declare function

int main()//function that receives data from the user into some two-dimensional array .function print and order and print the 2D array.
{
    int x;//defining variables
    printf("Enter x: ");// Prompt the user to enter the value of x
    if(scanf("%d", &x) != 1)
    {
        printf("Erorr with scanf");
        return 1;
    }
    int a[ROWS][COLS], i = 0, flag = 0; 
    printf("\nEnter elements: ");// Prompt the user to enter the elements of the matrix
    for (i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if(scanf("%d", &a[i][j]) != 1)
            {
                printf("Erorr with scanf");
                return 1;
            }
            if (a[i][j] == x) {
                flag = 1; // Set flag if x is found in the matrix
            }
        }
    }
    if (flag != 1)// If x is not found in the matrix, print an error message and exit
    {
        printf("\nNOT A GOOD MATRIX!\n");
        return 1;
    }
    printf("\nMatrix:\n");// Print the original matrix
    for (int t = 0; t < ROWS; t++) {
        for (int s = 0; s < COLS; s++) {
            printf("%3d ", a[t][s]);
        }
        printf("\n");
    }
    order(a, ROWS, COLS, x); //Call the order function to reorder the matrix based on x
    printf("\nThe fixed matrix:\n");//Print the reordered matrix
    for (i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%3d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
void order(int a[][MAX], int rows, int cols, int x)//function that accepts a two-dimensional array of integers a and its dimensions, as well as an integer x.The function rearrange the elements of the array so that all the elements smaller than x occupy cells preceding the cell containing x, and all other elements will occupy subsequent cells.
{
    int *start = &a[0][0],*end = &a[0][0] + rows * cols,*x_under = start;//defining variables
    int temp;//defining variables

    for (int* ptr = start; ptr < end; ptr++)// First pass: separate elements smaller than x

    {
        if (*ptr < x)// Swap elements      
        {
            temp = *x_under;
            *x_under = *ptr;
            *ptr = temp;
            x_under++;
        }
    }
    for (int* ptr = x_under; ptr < end; ptr++)//Second pass: place elements equal to x in their correct position
    {
        if (*ptr == x)// Swap elements
        {
            temp = *x_under;
            *x_under = *ptr;
            *ptr = temp;
            x_under++;
        }
    }
}