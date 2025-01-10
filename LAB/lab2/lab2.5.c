#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main(){
    double x;
    printf("Enter x please: ");
    scanf("%lf",&x);
    double N = (x + pow((1.0/ 3) * (pow(x, 4)) + 2 * (pow(x, 0.5)), (1.0/ 5)));
    printf("Output using  format with 2 digits after dot.");
    printf("\nx+(1/3x^4+2X^(1/2))^(1/5) = %.2lf+(1/3*%.2lf^4+2*%.2lf^(1/2))^(1/5) = %.2lf\n",x,x,x,N);
    printf("\nOutput using  format:");
    printf("x+(1/3x^4+2X^(1/2))^(1/5) = %g+(1/3*%g^4+2*%g^(1/2))^(1/5) = %g\n",x,x,x,N);
    return 0;
}