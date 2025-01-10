#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 5
typedef struct Item
{
	int code;
	char name[11];
	struct Item* next;

}Item;





int main()
{
	int i;
	Item *Head=NULL, *temp;
	for(i=1;i<=N;i++){
		temp =(Item*)malloc(sizeof(Item));	
		printf("Enter a new code and name: ");
		scanf("%d %s",&temp->code,temp->name);
		if (temp == NULL)
		{
		  printf("Error");
		  exit(1);
		}
		temp->next = Head;
		Head = temp;	

	}

	
	printf("\n\nThe List is:  ");
	while(Head != NULL)
        {
		printf("%d,%s --> ",Head->code,Head->name);
		Head = Head->next;
	
	}

	while(Head != NULL)
	{
		temp = Head;
		Head = Head->next;
		free(temp);
	
	}
        return 0;
}
