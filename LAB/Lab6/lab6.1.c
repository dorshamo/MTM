#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Matrix dimensions
#define N 5
#define M 4

// Function prototypes
double average(int Matrix[][M], int ROWS, int COLS, int r, int c);
int is_legal(int ROWS, int COLS, int r, int c);

int main() {
    // Initialize matrix
    int m[N][M] = {
        {11, 12, 13, 14},
        {0, -7, 18, 7},
        {1, 2, -1, -2},
        {6, -9, -19, 9},
        {300, 149, 267, 10}
    };
    int rows = N, cols = M, r, c;
    double x;

    // Get matrix index from user
    printf("Enter matrix index [r][c]: ");
    scanf("%d %d", &r, &c);

    // Check if indices are valid
    if (is_legal(rows, cols, r, c)) {
        // Calculate and print average of neighbors
        x = average(m, rows, cols, r, c);
        printf("The average is: %g\n", x);
    } else {
        printf("Index not found\n");
    }

    return 0;
}

// Function to calculate average of neighboring elements
double average(int Matrix[][M], int ROWS, int COLS, int r, int c) {
    double sum = 0;
    int count = 0;

    // Iterate over neighbors
    for (int t = r - 1; t <= r + 1; t++) {
        for (int u = c - 1; u <= c + 1; u++) {
            // Check if neighbor is valid and not the element itself
            if (is_legal(ROWS, COLS, t, u) && !(t == r && u == c)) {
                sum += Matrix[t][u];
                count++;
            }
        }
    }

    // Return average or 0 if no valid neighbors
    return (count > 0) ? (sum / count) : 0;
}

// Function to check if indices are within matrix bounds
int is_legal(int ROWS, int COLS, int r, int c) {
    return (r >= 0 && r < ROWS && c >= 0 && c < COLS);
}

