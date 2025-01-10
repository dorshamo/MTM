#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Define a structure for a 2D point
typedef struct {
    double x;
    double y;
} point;

// Define a structure for a circle, which includes a radius and a center point
typedef struct {
    double r;         // Radius of the circle
    point center;     // Center point of the circle
} circle;

// Function prototype for checking if a point is inside or on a circle
int InCircle(point p, circle c);

int main() {
    double x, y, x_m, y_m, r;
    
    // Prompt the user to enter coordinates for a point
    printf("Enter the coordinates of your point: ");
    scanf("%lf %lf", &x, &y);
    
    // Prompt the user to enter the radius and center coordinates of the circle
    printf("Enter the radius and the center of your circle: ");
    scanf("%lf %lf %lf", &r, &x_m, &y_m);

    // Create a point structure with user-entered coordinates
    point p = {x, y};
    
    // Create a circle structure with user-entered radius and center coordinates
    circle c = {r, {x_m, y_m}};

    // Check if the point is inside or on the circle using the InCircle function
    if (InCircle(p, c)) {
        printf("The point is included in the circle\n");
    } else {
        printf("The point is not included in the circle\n");
    }
    
    return 0;
}

// Function definition to determine if a point is inside or on a circle
int InCircle(point p, circle c) {
    // Calculate the squared distance from the point p to the center of the circle c
    double dsq = (p.x - c.center.x) * (p.x - c.center.x) + (p.y - c.center.y) * (p.y - c.center.y);
    
    // Calculate the squared radius of the circle c
    double rsq = c.r * c.r;

    // Compare the squared distance with the squared radius to determine inclusion
    if (dsq <= rsq) {
        return 1; // Return 1 if the point is inside or on the circle
    } else {
        return 0; // Return 0 if the point is outside the circle
    }
}
