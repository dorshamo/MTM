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
}Person;//Person struct


int main()//function open the file the_first.txt (the input file) as read-only and the file the_second.txt (the output file) as write-only. Both files will be pointed to by the FILE *in and FILE *out pointers, respectively.
{
    Person temp;
    FILE* in, * out;
    in = fopen("the_first.txt", "rt");//opening file for reading
    if(in == NULL)
    {
        printf("ERORR reading file");
        return 1;
    }
    out = fopen("the_secound.txt", "wt");//opening file for writing
    if (out == NULL)
    {
        printf("ERORR writing file");
        return 1;
    }
    if(fscanf(in,"%s",&temp.ID) != 1)//scan until space
    {
        fclose(in);
        fclose(out);
        printf("ERORR ID");
        return 1;
    }
    if (fscanf(in, "%s", &temp.F_name) != 1)//scan until space
    {
        fclose(in);
        fclose(out);
        printf("ERORR F_name");
        return 1;
    }
    if (fscanf(in, "%s", &temp.L_name) != 1)//scan until space
    {
        fclose(in);
        fclose(out);
        printf("ERORR L_name");
        return 1;
    }
    if (fscanf(in, "%d", &temp.Age) != 1)//scan until space
    {
        fclose(in);
        fclose(out);
        printf("ERORR Age");
        return 1;
    }
    if (fscanf(in, "%s", &temp.Addr) != 1)//scan until space
    {
        fclose(in);
        fclose(out);
        printf("ERORR Addr");
        return 1;
    }
    fprintf(out, "ID:%s\n", temp.ID);//write the secound file
    fprintf(out, "Full name:%s %s\n", temp.F_name,temp.L_name);//write the secound file
    fprintf(out, "Age:%d\n", temp.Age);//write the secound file
    fprintf(out, "Address:%s\n", temp.Addr);//write the secound file
    fclose(in);
    fclose(out);

    return 0;
}

