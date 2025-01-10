#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define N 6

int f(int A[], int n);//declare function
void noDoublesArr(int A[], int n);//declare function

int main()//function shows the number of participants who performed the run in a time lower than the average time of all participants.
{
    int arr[N],i,length;//defining variables
    printf("Enter array length: ");
    if(scanf("%d", &length) != 1)//receive length from user
    {
        printf("Erorr in scanf");
        return 1;
    }
    printf("Enter %d integer numbers: ",length);
    for(i = 0; i < length; i++)
    {
        if (scanf("%d", &arr[i]) != 1)//receive arr items from user
        {
            printf("Erorr in scanf");
            return 1;
        }
    }
    noDoublesArr(arr, length);// call noDoubleArr function to remove duplicates from the array

    if(f(arr, length) == 1)// Check if the array meets the requirement
        printf("The array meets the requirement");
    else
        printf("The array does not meets the requirement");
}

int f(int A[], int n)//function test for each element x in the array, if x is even then the array contains a even number of values ​​smaller than it, and if x is odd, then there is an odd number of values ​​smaller than it in the array.Other,The function will return 0.
{
    int i,j,num,count = 0;//defining variables
    for (i = 0; i < n; i++)
    {
        num = A[i];
        count = 0;
        if (num % 2 == 0)// if even number
        {
            for (j = 0; i < n; i++)
            {
                if (num > A[j])
                    count++;//add 1 to counter
            }
            if (count % 2 == 1)
                return 0;
        }
        else //if odd number
        {
            for (j = 0; i < n; i++)
            {
                if (num > A[j])
                    count++;//add 1 to counter
            }
            if (count % 2 == 0)
                return 0;
        }
    }
    return 1;
}
void noDoublesArr(int arr[], int n)//function to remove duplicates from the array
{
    int i,counter=1,isDuplicate;//defining variables
    if (n == 0)
        return;
    for (i = 1; i < n; i++)
    {
        isDuplicate = 0;
        for (int j = 0; j < counter; j++)
        {
            if (arr[i] == arr[j])
                isDuplicate = 1;//change the flag verible
        }
        if (!isDuplicate)
        {
            arr[counter] = arr[i];
            counter++;//add 1 to counter
        }
    }
}
