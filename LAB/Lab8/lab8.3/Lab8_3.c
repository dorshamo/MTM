#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define N 4

typedef struct {
    float Re;
    float Im;
}Complex;

float CRadius(Complex c);
void Error_Msg(char* str);
void InputAndWriteToFile(FILE *f);
int CheckFile(FILE *f,float m);

int main()
{
	
	FILE *f;
    f = fopen("complex_number.txt","wt");
    if (f == NULL){
        Error_Msg("Error file");
    }
	InputAndWriteToFile(f);
    fclose(f);
    f = fopen("complex_number.txt","rt");
    if (f == NULL){
        Error_Msg("Error file");
    }
	printf("\nThere are %d big numbers\n",CheckFile(f,4));
    fclose(f);
    return 0;
}
void Error_Msg(char* str)
{
   printf("\n%s",str);
   exit(1);
}

float CRadius(Complex c) {
    return sqrt(c.Im * c.Im + c.Re * c.Re);
}

void InputAndWriteToFile(FILE *F){
    Complex c;
    printf("Enter %d complex numbers: \n",N);
    for (int i = 0;i < N;i++){
       scanf("%f %f",&c.Re,&c.Im);
       fprintf(F, "%f %f %f\n",c.Re,c.Im,CRadius(c));
    }
}

int CheckFile(FILE *f,float m){
    int count=0;
    float re,im,rad;
    for (int i=0;i<N;i++){
        fscanf(f,"%f %f %f",&re,&im,&rad);
        if (rad > m){
            count++;
        }
    }
    return count;
}
