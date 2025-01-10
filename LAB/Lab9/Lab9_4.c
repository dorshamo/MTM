#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
unsigned char check_ms(unsigned char x);
unsigned char change_bit(unsigned char x,int num);
void BinPrint(unsigned char ch);


int main()
{
	unsigned char num1 = 102,num2 = 58;
	int n;

	printf("\nThe first part :");
	printf("\nThe number is %d   ", num1);
	BinPrint(num1);
	num1 = check_ms(num1);
	printf ("\nThe new number is: %d   ", num1);
	BinPrint(num1);

	printf("\n\nThe second part :");
	printf("\nThe number is %d   ", num2);
	BinPrint(num2);
	printf ("\nEnter a number of the bit to change(1-8)");
	scanf ("%d",&n);
	num2 = change_bit(num2, n);
	printf("\nThe new number is: %d   ", num2);
	BinPrint(num2);
	return 0;
}



void BinPrint(unsigned char ch)
{
    unsigned char temp=1;
    temp = temp << sizeof(char)*8-1;
    for (int i=0;i<sizeof(char)*8;i++){
        if ((temp & ch) == temp){
            printf("1");
        }
        else{
            printf("0");
        }
        ch=ch<<1;
    }
 
}

unsigned char check_ms(unsigned char x){
    unsigned int temp = 1;
    temp = temp<<sizeof(char)*8 - 1;
    if ((temp & x) == temp){
        return x;
    }
    else{
        return temp | x;

    }
}

unsigned char change_bit(unsigned char x,int num){
    unsigned int temp = 1;
    temp = temp<<sizeof(char)*8-1;
    temp = temp>>num-1;
    if ((temp & x)==temp){
        return x & (~temp);
    }
    else{
        return x | temp;
    }
}