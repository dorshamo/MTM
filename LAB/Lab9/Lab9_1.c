#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
    char name[7];
    char class[5];
    char grade1[4];
    char grade2[4];
    double average;
}students;

void Error_Msg(char* str);

int main()
{
    students s;
	FILE *in,*out;

	if((in=fopen("Students.txt","r")) == NULL)
             Error_Msg("The input file is wrong");
	if((out=fopen("StudentsNew.txt","w")) == NULL)
             Error_Msg("The output file is wrong");
    while (fscanf(in, "%6s %4s %3s %3s",s.name,s.class,s.grade1,s.grade2) == 4){
        if (strcmp(s.class,"Comp")==0){
            s.average = (atof(s.grade1)+ atof(s.grade2))/2;
            fprintf(out,"%s %.2lf\n", s.name, s.average);
        }
    }

	fclose(in);
    fclose(out);
    return 0;
}


void Error_Msg(char* str)
{
	printf("\n%s",str);
        exit(1);
}




