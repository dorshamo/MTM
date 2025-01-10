#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int InputThree(int *p1, int *p2, int *p3); // section A
void SortTwo(int *p1, int *p2); // section B
void SortThree(int *q1, int *q2, int *q3); // section C

int main(){ // section D
    int n1,n2,n3;
    while (InputThree(&n1, &n2, &n3)){
         SortThree(&n1, &n2, &n3);
         printf("The sorted values: %d, %d, %d\n", n1, n2, n3);
    }
    printf("FINISH\n");
    return 0;
}

int InputThree(int *p1, int *p2, int *p3){

    printf("Please enter 3 integers: ");
    if(scanf("%d %d %d", p1, p2, p3) == 3){
       return 1;
    }
    return 0;
}

void SortTwo(int *p1, int *p2){
    int temp;
    if (*p1 > *p2){
        temp = *p1;
        *p1 = *p2;
        *p2 = temp;
    }
}

void SortThree(int *q1, int *q2, int *q3){
    SortTwo(q1, q2);
    SortTwo(q2, q3);
    SortTwo(q1, q2);

}
