#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(){
    char chr;
    printf("Enter an English lower case letter, please: ");
    scanf("%c",&chr);
    printf("The ascii code of '%c' is %d.",chr ,chr);
    chr-=('a'-'A');
    printf("\nThe ascii code of '%c' is %d.\n",chr ,chr);

return 0;

}