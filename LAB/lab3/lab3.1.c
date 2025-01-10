#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main(){
    /*ask from the user for weight in kg and height in cm */
    int kg,cm;
    printf("Please enter weight (in kg) and height (in cm), respectively: ");
    scanf("%d%d",&kg,&cm);
    /*converting cm to m */
    float M = cm/100.0;
    /*calculates the BMI */
    float BMI = kg/pow(M,2);
    /*for every stage in the BMI number, printing the right message */
    if (BMI < 18.5){
    printf("Underweight\n");
    } if (BMI >= 18.5 && BMI < 25.0){
    printf("Normal weight\n");
    } if (BMI >= 25.0 && BMI < 30.0){
    printf("Increased weight\n");
    } if (BMI >= 30.0 && BMI < 40.0){
     printf("Obese\n");
    } if (BMI >= 40.0){ 
    printf("Very high obese.\n");
    }   
    return 0;
}