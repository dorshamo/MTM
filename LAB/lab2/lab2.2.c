#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(){
    float edge, height;
    printf("Enter a triangle edge and its height respectively, please: ");
    scanf("%f %f", &edge, &height);
    printf("\nThe triangle erea is %.3f\n",(edge*height)/2);


    return 0;
}