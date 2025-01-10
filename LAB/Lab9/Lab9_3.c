#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int Bit_Count(unsigned int x);
void Bin_Print(unsigned int x);

int main()
 {
	unsigned int x;

	printf("Enter a number");
        scanf("%d",&x);
        printf("There are %d bits equal to one in %d\n", Bit_Count(x),x);
	printf("The binary representation of %d is ",x); 
	Bin_Print(x);

        return 0;
}


int Bit_Count(unsigned int x)
 {
    int count = 0;
     unsigned int temp = 1; //00000001
	for (int i=0;i<sizeof(int)*8;i++){
        if( (temp & x )== 1) { //00000000
                               //00000001
            count++;
        }
        x=x>>1;
    }
    return count;
 }



void Bin_Print(unsigned int x)  //00000000
 {
  unsigned int temp = 1;
  temp = temp << sizeof(int)*8 - 1;
  for (int i=0;i<sizeof(int)*8;i++){
      if((temp & x )== temp) {
          printf("1");
      }
      else {
          printf("0");
      }
      x = x<<1;
  }
 }
