#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    char name[20];
    int grades[3];
}student;//student struct

void Error_Msg(char*);//declaer function
int InputData(student**, FILE*);//declaer function
void OutputData(int, student*, FILE*);//declaer function

int main()//function goes through the Students.txt file and captures the data of all the students into an array. Change the Students.txt file so that each line contains the student's name and the highest grade among his three grades.
{
    FILE* fp;
    student* arr;
    int size;
    if ((fp = fopen("Students.txt", "rt")) == NULL)//open file to read
    {
        Error_Msg("The input file is wrong");
    }
    size = InputData(&arr, fp);//get number of studnets
    fclose(fp);
    if ((fp = fopen("Students.txt", "wt")) == NULL)//open file to write
    {
        free(arr);
        Error_Msg("The output file is wrong");
    }
    OutputData(size, arr, fp);
    fclose(fp);
    free(arr);

    return 0;
}

int InputData(student** p_array, FILE* fp)//function gets a pointer to an array of students and a pointer to a file , Reads the name and grades of the students from the file and saves it in the array and returns the number of students
{
    student* arr,* temp;
    int i = 1, size = 0;
    arr = (student*)malloc(sizeof(student));//set dynmic memory for arr
    if (arr == NULL)
        Error_Msg("Error");
    while (fscanf(fp, "%s %d %d %d", arr[i - 1].name, &arr[i - 1].grades[0], &arr[i - 1].grades[1], &arr[i - 1].grades[2]) != EOF)
    {
        temp = (student*)realloc(arr, (i + 1) * sizeof(student));//resize the arr
        if (temp == NULL)
        {
            free(arr);
            Error_Msg("Error");
        }
        else
            arr = temp;
        size++;//count students
        i++;
    }
    *p_array = arr;
    return size; //return the number of students
}

void OutputData(int arr_size, student* arr, FILE* fp)//function receives a number of students, a pointer to an array of students and a pointer to a file.Writes the name of the studentand his highest grade to the file
{
    for (int i = 0; i < arr_size; i++) //run the number of students
    {
        int biggest = arr[i].grades[0];
        for (int j = 1; j < 3; j++) //find the biggest grade
        {
            if (biggest < arr[i].grades[j])
                biggest = arr[i].grades[j];
        }
        fprintf(fp, "%s %d\n", arr[i].name, biggest);//print to file
    }
}


void Error_Msg(char* msg)//function for erorr msg
{
    printf("\n%s", msg);
    exit(1);
}
