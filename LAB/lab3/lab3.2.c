#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(){
    int num;
    int result;
    int count=0;
    /*ask the user for a number*/
    printf("Enter an integer number , please: ");
    scanf("%d",&num);
    /*if the number is below zero we go with 'for' loop over all the numbers from 1 to 'num' including 'num' */
    if (num<0){
    for (int i =1; i <=(-num); i++){
        if ((-num)%i == 0) {
            printf("%d ", i);
            /*updating count every time we find divider */
            count++;
        }
    }
    printf("\ncount=%d\n",count);
    /*if the number is biger than zero we go with 'for' loop over all the numbers from 1 to 'num' without 'num' */
    }if (num>0){
    for (int i =1; i <(num); i++){
        if ((num)%i == 0) {
            printf("%d ", i);
            /*updating count every time we find divider */
            count++;
        }
    }
    printf("\ncount=%d\n",count);
    /*with num == 0 all the numbers are dividers*/
    }if (num==0){ 
        printf("infinity\n");
    }
    return 0;
}