#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/* Function prototype declaration */
void f(char chr ,int num);
int main()
{
    int num;
    char chr;
    /*ask from the user for a character and a integer*/
    printf("Enter a character and integer, please: ");
    scanf(" %c %d",&chr,&num);
    /*check if the number is valid*/
    if (num <= 0){
    printf("Error\n");
    } else{
      /*call for the function*/
       f(chr,num);
    }

    return 0;
}
/*Function definition to print a character 'num' times*/
void f(char chr ,int num )
{
   int i;
   /*while loopthat runs "num" times*/
   while (num>0)
   {
    /*for loop to print "chr" "num" times in a row*/
    for(i=1;i<=num;i++)
   {
    printf("%c",chr);
   }
   /*go down a row and sbtracts one from the "num" */
   printf("\n");
   num--;
   }
}

