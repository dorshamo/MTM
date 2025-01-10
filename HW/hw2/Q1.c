#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define MAX 99
typedef struct Student
{
	char* student_name;
	long student_id;
	float student_grade;
	char arr_grades[5];
	char student_final_grade;
}Student;//student structure
typedef struct University
{
	Student* studant_arr;
	int number_of_studant;
}University;//University structure

void Input_From_File_1(University* univ, FILE* in);//function declaration 1
void Output_To_File_2(University* univ, FILE* out);//function declaration 2
void Finel_Grade_Calculation_3(University* p_univ, FILE* out);//function declaration 3
void Black_List_4(University* p_univ, FILE* out);//function declaration 4
void Edit_Studant_Status_5(University* p_univ, FILE* out);//function declaration 5
void Error_Msg(char* msg, University* univ);//function declaration

int main()//function will present an action menu in which includes the action options 1,2,3,4,5,6
{
	FILE* in, * out;//variables declaration
	University univ, * p_univ;//variables declaration
	int i, pick, flag1 = 0, flagEnd = 1;//variables declaration
	p_univ = &univ;//set pointer
	univ.studant_arr = (Student*)malloc(sizeof(Student) * 1);//initial definition for dynamic memory
	if (univ.studant_arr == NULL)//if did not succeed
	{
		printf("MEMORY ERORR");
		return 1;
	}
	univ.number_of_studant = 0;//set number of studant to 0

	printf("Pick one of the option and press enter:\n");
	printf("1.Input of student data\n2.Output of student data\n3.Calculation of the final grade\n4.Black List\n5.Edit studant status\n6.End program\n(Please note: at the beginning you have to choose option 1, you can choose this option only once)\n");
	while (1)//while loop until user pick 1
	{
		if (scanf("%d", &pick) != 1)
			Error_Msg("Scanning pick Erorr", p_univ);//call erorr function
		if (pick == 1)
			break;
		else if (pick == 6)//if user pick 6 to end program
			break;
		else
			printf("You need to pick option 1 first\n");
	}
	while (1)//while loop for the options(main while loop)
	{
		if (pick == 1 && flag1 == 0)//if user pick option 1
		{
			out = fopen("output.txt", "wt");//open file to write
			if (out == NULL)//if did not succeed
				Error_Msg("ERORR writting output.txt file", p_univ);//call erorr function
			fprintf(out, "Input accepted\n");
			fclose(out);//close file

			in = fopen("input.txt", "rt");//open file to read
			if (in == NULL)//if did not succeed
				Error_Msg("ERORR reading input.txt file", p_univ);//call erorr function
			flag1 = 1;//set flag to indicate that option 1 was selected
			Input_From_File_1(p_univ, in);//call function 1
			fclose(in);//close file
		}
		else if (pick == 1)//if user pick option 1 secound time
		{
			printf("You alrady pick option 1,please choose other option\n\n");
		}
		if (pick == 2)//if user pick option 2
		{
			out = fopen("output.txt", "at");//open file to add or write
			if (out == NULL)//if did not succeed
			{
				Error_Msg("ERORR writting output.txt file", p_univ);//call erorr function
			}
			Output_To_File_2(p_univ, out);//call function 2
			fclose(out);//close file
		}
		if (pick == 3)//if user pick option 3
		{
			out = fopen("output.txt", "at");//open file to add or write
			if (out == NULL)//if did not succeed
			{
				Error_Msg("ERORR writting output.txt file", p_univ);//call erorr function
			}
			Finel_Grade_Calculation_3(p_univ, out);//call function 3
			fclose(out);//close file
		}
		if (pick == 4)//if user pick option 4
		{
			out = fopen("output.txt", "at");//open file to add or write
			if (out == NULL)//if did not succeed
			{
				Error_Msg("ERORR writting output.txt file", p_univ);//call erorr function
			}
			Black_List_4(p_univ, out);//call function 4
			fclose(out);//close file
		}
		if (pick == 5)//if user pick option 5
		{
			out = fopen("output.txt", "at");//open file to add or write
			if (out == NULL)//if did not succeed
			{
				Error_Msg("ERORR writting output.txt file", p_univ);//call erorr function
			}
			Edit_Studant_Status_5(p_univ, out);//call function 5
			fclose(out);//close file
		}
		if (pick == 6)//if user pick option 6
		{
			out = fopen("output.txt", "at");//open file to add or write
			if (out == NULL)//if did not succeed
			{
				Error_Msg("ERORR writting output.txt file", p_univ);//call erorr function
			}
			fprintf(out, "\nOption 6\n");
			fprintf(out, "End Of Program");
			fclose(out);//close file
			printf("Finish");
			for (i = 0; i < p_univ->number_of_studant; i++)//clear memory
			{
				free(p_univ->studant_arr[i].student_name);
			}
			free(univ.studant_arr);
			break;//end while loop
		}
		else if (pick > 6 || pick < 1)//if user did not pick a good option
		{
			printf("Error please choose other option\n");
		}
		printf("\n1.Input of student data\n2.Output of student data\n3.Calculation of the final grade\n4.Black List\n5.Edit studant status\n6.End program\n(Please note: at the beginning you have to choose option 1, you can choose this option only once)\n");
		if (scanf("%d", &pick) != 1)
			Error_Msg("Scanning pick Erorr", p_univ);//call erorr function	
	}
	return 0;
}
void Input_From_File_1(University* p_univ, FILE* in)//function 1 input data from the input file into a university structure. The student data must be recorded As long as there is data in the input file. 
{
	char name[MAX];//variables declaration
	Student* temp;//variables declaration
	while (fscanf(in, "%s", &name) != EOF)//while loop run until end of file
	{
		temp = (Student*)realloc(p_univ->studant_arr, (p_univ->number_of_studant + 1) * sizeof(Student));//increase the dynamic memory of studnet arr by 1
		if (temp == NULL)//if did not succeed
			Error_Msg("Memory ERORR", p_univ);//call erorr function
		else
			p_univ->studant_arr = temp;
		p_univ->studant_arr[p_univ->number_of_studant].student_name = (char*)malloc(sizeof(char) * (strlen(name) + 1));//set dynamic memory of studnet name to length of the name
		if (p_univ->studant_arr[p_univ->number_of_studant].student_name == NULL)//if did not succeed
			Error_Msg("Memory ERORR", p_univ);//call erorr function
		else
			strcpy(p_univ->studant_arr[p_univ->number_of_studant].student_name, name);//copy the name to the dynamic memory name

		if (fscanf(in, "%ld", &p_univ->studant_arr[p_univ->number_of_studant].student_id) != 1)//scan file for id
			Error_Msg("Scanning id Erorr", p_univ);//call erorr function
		if (fscanf(in, "%f", &p_univ->studant_arr[p_univ->number_of_studant].student_grade) != 1)//scan file for studant_grade
			Error_Msg("Scanning grade Erorr", p_univ);//call erorr function
		if (fscanf(in, "%s", &p_univ->studant_arr[p_univ->number_of_studant].arr_grades) != 1)//scan file for arr_grades
			Error_Msg("Scanning 5 grade Erorr", p_univ);//call erorr function
		p_univ->number_of_studant++;//add 1 to the number of studnet
	}
}
void Output_To_File_2(University* p_univ, FILE* out)//function 2 output of the students' data to the output file in the following format: A grade of 1 will be given to each student who submitted 3 exercises and above, otherwise a score of 0 will be given
{
	int i, j, count;//variables declaration
	fprintf(out, "\nOption 2\n");
	for (i = 0; i < p_univ->number_of_studant; i++)//for loop to print to file
	{
		count = 0;
		for (j = 0; j < 5; j++)//for loop to count number of 1 grades for each student
		{
			if (p_univ->studant_arr[i].arr_grades[j] == '1')
				count++;
		}
		if (count >= 3)//if has 3 grades == 1 
		{
			p_univ->studant_arr[i].student_final_grade = '1';
			fprintf(out, "Student %d: %s %ld %0.2f 1\n", i + 1, p_univ->studant_arr[i].student_name, p_univ->studant_arr[i].student_id, p_univ->studant_arr[i].student_grade);
		}
		else
		{
			p_univ->studant_arr[i].student_final_grade = '0';
			fprintf(out, "Student %d: %s %ld %0.2f 0\n", i + 1, p_univ->studant_arr[i].student_name, p_univ->studant_arr[i].student_id, p_univ->studant_arr[i].student_grade);
		}
	}
}
void Finel_Grade_Calculation_3(University* p_univ, FILE* out)//function calculat the final grade:The final grade also added to the data according to the following breakdown : The exercise score 1 - means 100. The exercise score 0 - means 0.To pass the course, it is mandatory to pass the exam with a score of at least 55 (if the test score is less then 55 - This is the final score, without weighting with the exercises).Otherwise, the grade of the exercises constitutes a valid grade, which is worth 15% of the final grade.Therefore, a test grade constitutes 85% of the final grade.
{
	int i, j, count;//variables declaration
	fprintf(out, "\nOption 3\n");
	fprintf(out, "BEFOR:\n");
	for (i = 0; i < p_univ->number_of_studant; i++)//for loop to print to file
	{
		count = 0;
		for (j = 0; j < 5; j++)//for loop to count number of 1 grades for each student
		{
			if (p_univ->studant_arr[i].arr_grades[j] == '1')
				count++;
		}
		if (count >= 3)
		{
			p_univ->studant_arr[i].student_final_grade = '1';
			fprintf(out, "Student %d: %s %ld %0.2f 1\n", i + 1, p_univ->studant_arr[i].student_name, p_univ->studant_arr[i].student_id, p_univ->studant_arr[i].student_grade);
		}
		else
		{
			p_univ->studant_arr[i].student_final_grade = '0';
			fprintf(out, "Student %d: %s %ld %0.2f 0\n", i + 1, p_univ->studant_arr[i].student_name, p_univ->studant_arr[i].student_id, p_univ->studant_arr[i].student_grade);
		}
	}
	fprintf(out, "\n\nAFTER:\n");
	for (i = 0; i < p_univ->number_of_studant; i++)//for loop to print to file AFTER
	{
		count = 0;
		for (j = 0; j < 5; j++)//for loop to count number of 1 grades for each student
		{
			if (p_univ->studant_arr[i].arr_grades[j] == '1')
				count++;
		}
		if (count >= 3 && p_univ->studant_arr[i].student_grade >= 55)
		{
			p_univ->studant_arr[i].student_final_grade = '1';
			fprintf(out, "Student %d: %s %ld %0.2f %c  final:%0.2f\n", i + 1, p_univ->studant_arr[i].student_name, p_univ->studant_arr[i].student_id, p_univ->studant_arr[i].student_grade, p_univ->studant_arr[i].student_final_grade, p_univ->studant_arr[i].student_grade * 0.85 + 15);
		}
		else
		{
			p_univ->studant_arr[i].student_final_grade = '0';
			fprintf(out, "Student %d: %s %ld %0.2f %c  final:%0.2f\n", i + 1, p_univ->studant_arr[i].student_name, p_univ->studant_arr[i].student_id, p_univ->studant_arr[i].student_grade, p_univ->studant_arr[i].student_final_grade, p_univ->studant_arr[i].student_grade);
		}
	}
}
void Black_List_4(University* p_univ, FILE* out)//function presentat student data that did not submit at least 3 labs.The name and ID number of these students.
{
	int i, j, count;//variables declaration
	fprintf(out, "\nOption 4\n");
	fprintf(out, "No hw submission:\n");
	for (i = 0; i < p_univ->number_of_studant; i++)//for loop to print to file 
	{
		count = 0;
		for (j = 0; j < 5; j++)//for loop to count number of 1 grades for each student
		{
			if (p_univ->studant_arr[i].arr_grades[j] == '1')
				count++;
		}
		if (count < 3)
		{
			fprintf(out, "%s %ld\n", p_univ->studant_arr[i].student_name, p_univ->studant_arr[i].student_id);
		}
	}
}
void Edit_Studant_Status_5(University* p_univ, FILE* out)//function changing the submission status of a certain student's homework exercise
{
	char name[MAX];//variables declaration
	int number_of_exercise, i, j, count, found_flag = 0, flag = 1;//variables declaration
	char new_grade;//variables declaration
	fprintf(out, "\nOption 5\n");
	printf("Enter student name:\n");
	if (scanf("%s", &name) != 1)//receives from the user
		Error_Msg("Scanning name Erorr", p_univ);//call erorr function
	rewind(stdin);//clear buffer
	printf("Enter exercise number(1-5):\n");
	if (scanf("%d", &number_of_exercise) != 1)//receives from the user
		Error_Msg("Scanning number_of_exercise Erorr", p_univ);//call erorr function
	rewind(stdin);//clear buffer
	printf("Enter new grade(0-1):\n");
	if (scanf("%c", &new_grade) != 1)//receives from the user
		Error_Msg("Scanning new_grade Erorr", p_univ);//call erorr function
	rewind(stdin);//clear buffer
	if (number_of_exercise > 5 || number_of_exercise < 1)//if a user has not entered valid number_of_exercise
	{
		flag = 0;
		fprintf(out, "You entered not valid number of exercise\n");
	}
	if (!(new_grade == '0' || new_grade == '1'))//if a user has not entered valid new_grade
	{
		flag = 0;
		fprintf(out, "You entered not valid new grade\n");
	}
	if (flag)//if user enter correct veribles
	{
		for (i = 0; i < p_univ->number_of_studant; i++)//for loop to find the name 
		{
			if (strcmp(p_univ->studant_arr[i].student_name, name) == 0)
			{
				found_flag = 1;//set flag to found 1
				p_univ->studant_arr[i].arr_grades[number_of_exercise - 1] = new_grade;//set the arr_grades in the correct postion
			}
		}
		if (found_flag)//if a user has entered exist name
		{
			for (i = 0; i < p_univ->number_of_studant; i++)//for loop to print to file similer function 2
			{
				count = 0;
				for (j = 0; j < 5; j++)
				{
					if (p_univ->studant_arr[i].arr_grades[j] == '1')
						count++;
				}
				if (count >= 3)
				{
					p_univ->studant_arr[i].student_final_grade = '1';
					fprintf(out, "Student %d: %s %ld %0.2f 1\n", i + 1, p_univ->studant_arr[i].student_name, p_univ->studant_arr[i].student_id, p_univ->studant_arr[i].student_grade);
				}
				else
				{
					p_univ->studant_arr[i].student_final_grade = '0';
					fprintf(out, "Student %d: %s %ld %0.2f 0\n", i + 1, p_univ->studant_arr[i].student_name, p_univ->studant_arr[i].student_id, p_univ->studant_arr[i].student_grade);
				}
			}
		}
		else//if a user has not entered valid name
		{
			fprintf(out, "%s was not found in the system", name);
		}
	}
}
void Error_Msg(char* msg, University* p_univ)//function for erorr msg and free memory
{
	int i;//variables declaration
	printf("\n%s", msg);
	for (i = 0; i < p_univ->number_of_studant; i++)//for loop to free memory
	{
		free(p_univ->studant_arr[i].student_name);
	}
	free(p_univ->studant_arr);
	exit(1);
}


