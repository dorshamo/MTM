#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
    char letter;
    int num1, num2; 
    printf("Please insert a char: ");
    scanf(" %c", &letter);

    while (letter != 'q' && letter != 'Q') {
        switch (letter) {
            case 'a':
            case 'A':
                printf("Please enter two numbers: ");
                scanf("%d %d", &num1, &num2);
                printf("The average is: %g\n", ((float)num1 + (float)num2) / 2);
                break;

            case '*':
                printf("Please enter two numbers: ");
                scanf("%d %d", &num1, &num2);
                printf("The multiply is: %d\n", num1 * num2);
                break;

            case 'm':
                printf("Please enter two numbers: ");
                scanf("%d %d", &num1, &num2);
                printf("The smallest is: %d\n", (num1 < num2) ? num1 : num2);
                break;

            case 'M':
                printf("Please enter two numbers: ");
                scanf("%d %d", &num1, &num2);
                printf("The biggest is: %d\n", (num1 > num2) ? num1 : num2);
                break;

            case '^':
                printf("Please enter two numbers: ");
                scanf("%d %d", &num1, &num2);
                printf("The power is: %g\n", pow((float)num1, (float)num2));
                break;

            default:
                printf("Error\n");
                break;
        }
        printf("Please insert a char: ");
        scanf(" %c", &letter);
    }
    printf("Finish\n");
    return 0;
}
