#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define N 6 //Maximum lengh for strings A and B

int distance(char A[], char B[]);

int main()//function shows the number of participants who performed the run in a time lower than the average time of all participants.
{

    int arr[N], i, len, newArr[N];//defining variables
    char A[N], B[N];//defining variables
    printf("Enter String for A: ");
    if(scanf("%s", &A) != 1)////Read A from user
    {
        printf("Erorr in scanf");
        return 1;
    }
    printf("Enter String for B: ");
    if (scanf("%s", &B) != 1)//Read B from user
    {
        printf("Erorr in scanf");
        return 1;
    }
    printf("The distance between A and B is %d", distance(A, B));
}
int distance(char A[], char B[])//function receives as input two strings A and B. function return the distance between string A and string B.
{
    int i, count = 0, lena = strlen(A), lenb = strlen(B);//defining variables
    if (lena != lenb)//if string length diffrent
        return -1;
    for (i = 0; i < lena; i++)//compare characters and count differences
    {
        if (A[i] != B[i])
            count++;//add 1 to counter
    }
    return count;
}

