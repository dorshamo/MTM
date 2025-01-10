#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

void set_mid( double x1, double y1,double x2, double y2 , double * p_mx, double * p_my );   
int main(){
    double x1, y1, x2, y2, mx, my;
    printf("Please enter two endpoints: ");
    scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);

    set_mid(x1, y1, x2, y2, &mx, &my);

    printf("The mid point is: (%g , %g)", mx, my);

    return 0;
}
void set_mid( double x1, double y1,double x2, double y2 , double * p_mx, double * p_my ){

    *p_mx = (x1 + x2) / 2;
    *p_my = (y1 + y2) / 2;


}