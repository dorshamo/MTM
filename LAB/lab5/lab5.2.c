#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int func1(int *arr1, int *arr2);

int main(){
    int arr1[7],arr2[7],i=0,maxValue;
    srand(time(0));

    for (i=0;i<7;i++){ 
        int n;
        printf("Enter arr[%d]: ",i);
        scanf("%d",&n);
        arr1[i]=n;
    }

    printf("Enter max value greater than zero: ");
    scanf("%d",&maxValue);

    for (i = maxValue;i<=0;i=maxValue){
       printf("Error, try again!\n");
       printf("Enter max value greater than zero: ");
       scanf("%d\n",&maxValue); 
    }

    for (i=0;i<7;i++){
        arr2[i]=rand()%maxValue+1; 
    }


    printf("Array 1: ");
    for (i=0;i<7;i++){
        printf("%d ",arr1[i]);
    }
    printf("\nArray 2: ");
    for (i=0;i<7;i++){
        printf("%d ",arr2[i]);
    }

    func1(arr1,arr2);
    
    return 0;
}

int func1(int *arr1, int *arr2){
    int i=0,count=0;

    for (i=0;arr1[i]<arr2[i];i++){
        count++;
    } 
    if (count == 0){
        printf("\nno!!!");
    }
    else {
        printf("\nThe index is %d(numbers %d and %d)",count--,count--,count);}

}
