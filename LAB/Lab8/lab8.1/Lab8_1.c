#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct Person
{
	char ID[10];
	char F_name[11];
	char L_name[16];
	int Age;
	char Addr[51];
}Person;

void Error_Msg(char*);

int main()
{
	Person temp;
	FILE *in,*out;
    in = fopen("the_first.txt","rt");
    if (in == NULL) {
        Error_Msg("Error file");
    }
    out = fopen("the_second.txt","wt");
    if (out == NULL) {
        Error_Msg("Error file");
    }
    if (fscanf(in,"%s",&temp.ID) != 1){
        fclose(in);
        fclose(out);
        Error_Msg("Error id");
    }

    if (fscanf(in,"%s",&temp.F_name) != 1){
        fclose(in);
        fclose(out);
        Error_Msg("Error first name");
    }

    if (fscanf(in,"%s",&temp.L_name) != 1){
        fclose(in);
        fclose(out);
        Error_Msg("Error last name");
    }

    if (fscanf(in,"%d",&temp.Age) != 1){
        fclose(in);
        fclose(out);
        Error_Msg("Error age");
    }

    if (fscanf(in,"%s",&temp.Addr) != 1){
        fclose(in);
        fclose(out);
        Error_Msg("Error address");
    }

    fprintf(out,"ID:%s\n",temp.ID);
    fprintf(out,"FULL name:%s %s\n",temp.F_name,temp.L_name);
    fprintf(out,"Age:%d\n",temp.Age);
    fprintf(out,"Address:%s\n",temp.Addr);

    fclose(in);
    fclose(out);
	return 0;	
}



void Error_Msg(char* msg)
{
	printf("\n%s",msg);
	exit(1);             /*Exit() closes any open files in the program*/
}