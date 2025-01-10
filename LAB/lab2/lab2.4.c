#include <stdio.h>
#include <math.h>
int main(){

    printf("Given the equation a^x=b");
    double a,b;
    printf("\nEnter a and b, repectively please: ");
    scanf("%lf%lf",&a,&b);
    printf("x is: %g\n",log(b)/log(a));

    return 0;
}