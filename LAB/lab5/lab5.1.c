#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(){
    double times[10],sum=0;
    int i,count=0;
    printf("Enter times, please: ");

    for (i=0;i<10;i++){
        scanf("%lf",&times[i]);

    }for (i=0;i<10;i++){
        sum=sum+times[i];

    }for (i=0;i<10;i++){
        if (times[i]<(sum/10)){
            count++;
        }
    }
    printf("The number of runners, running below the average time is: %d\n", count);
    
    return 0;
}