#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	char code[11];
	char *name;
	char Dep[4];
	int marks[3];
	float avg;
	struct node* next;
}std;

void Error_Msg(char* str);
std* FromFileToList(FILE *in);
std* Delete_Stud(std* toDel,std* head);
std* DeleteList(std* head);
void PrintList(std* head);
std* FindMax(std* head);

int main()
{
	int i;
	FILE *f;
	std *Head=NULL, *temp;

	if((f=fopen("List1.txt","rt")) == NULL)
           Error_Msg("input error");
	Head=FromFileToList(f);
        if(Head == NULL)
          Error_Msg("The input file is empty");

        fclose(f);
	printf("\nThe list is:\n");
	PrintList(Head);
	
	temp = FindMax(Head);
        printf("\n\nthe student with max average:\n");
	printf("%s %s %s ",temp->code,temp->name,temp->Dep);
        for(i=0;i<3;i++)
          printf(" %d ",temp->marks[i]);

	printf("\n\nThe list after change:\n");
	Head=Delete_Stud(FindMax(Head),Head);
	PrintList(Head);
	Head = DeleteList(Head);        /*Head = NULL */
        return 0;
}

void Error_Msg(char* str)
{
	printf("\n%s",str);
        exit(1);
}



std* Delete_Stud(std* toDel,std* head)
{
	std* temp;
  if(head == NULL)
    return NULL;

  if(toDel==head)
  {
	head = head->next;
	free(toDel->name);
	free(toDel);
	
  }
  else
  {
	temp = head;
	while (temp->next != toDel && temp->next != NULL)
	{
		temp = temp->next;
	}
	if (temp->next == toDel)
	{
	temp->next = toDel->next;
	free(toDel->name);
	free(toDel);
	}
  }
  return head;
}

std* FromFileToList(FILE *in){
	char name[257];
	std* temp;
	std* head = NULL;
	temp = (std*)malloc(sizeof(std));
	while (fscanf(in,"%s %s %s %d %d %d", temp->code, name, temp->Dep, &temp->marks[0], &temp->marks[1], &temp->marks[2]) != EOF){
	    temp->name = (char*)malloc((strlen(name) + 1) * sizeof(char));
	    if (temp->name == NULL){
		    Error_Msg("Error");
	    }
	    strcpy(temp->name, name);
	    temp->avg = (temp->marks[0] + temp->marks[1] + temp->marks[2]) / 3.0;
	    temp->next = head;
	    head = temp;
	    temp = (std*)malloc(sizeof(std)); 
	    if (temp == NULL){
		    Error_Msg("Error");
	    }
	}
	free(temp); 
	return head;
}

void PrintList(std* head){
	while (head != NULL)
	{
		printf("%s %s %s %d %d %d\n",head->code,head->name,head->Dep,head->marks[0],head->marks[1],head->marks[2]);
		head = head->next;
	}
}

std* FindMax(std* head){
	std* temp = NULL;
	float max = 0;
	while (head != NULL){
		if (head->avg > max){
			max = head->avg;
			temp = head;
		}
		head = head->next;
	}
	return temp;
}

std* DeleteList(std* head){
	std* temp;
	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp->name);
		free(temp);
	}
	return NULL;
}
