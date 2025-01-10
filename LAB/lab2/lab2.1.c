#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main(){
    int num;
    printf("Enter number: ");
    scanf("%d",&num);
    printf("\nNumber\t\tSquare\t\tCube\n");
    int num2 = num+1;
    int num3 = num2+1;
    int num4 = num3+1;
    int num5 = num4+1;
    printf(" %3d\t\t%4g\t\t%4g\n",num,pow(num,2),pow(num,3));
    printf(" %3d\t\t%4g\t\t%4g\n",num2,pow(num2,2),pow(num2,3));
    printf(" %3d\t\t%4g\t\t%4g\n",num3,pow(num3,2),pow(num3,3));
    printf(" %3d\t\t%4g\t\t%4g\n",num4,pow(num4,2),pow(num4,3));
    printf(" %3d\t\t%4g\t\t%4g\n",num5,pow(num5,2),pow(num5,3));

    return 0;
}