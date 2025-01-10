#include<stdio.h>
#include<stdlib.h>

typedef struct Item
{
	int num;
	struct Item* next;
}Item;

typedef struct List
{
    struct Item *head;
    struct Item *tail;
    int count;
}List;

void Error_Msg(char*);
void AddAsFirst(Item* ,List* );
void AddAsLast(Item* ,List* );
void MoveToAnotherList(List* ,List* ,List* );
void CreateList(List* ,FILE *);
void PrintItem(Item* );
void PrintList(List* ,char*);
void DeleteList(List*);

int main()
{
    List L,Posit,Negat;
    FILE *in=fopen("ThreeLists.txt","rt");
    if(in == NULL)
    Error_Msg("input file is wrong");
    L.head=NULL;
    L.tail=NULL;
    L.count=0;
	
    Posit.head=NULL;
    Posit.tail=NULL;
    Posit.count=0;

    Negat.head=NULL;
    Negat.tail=NULL;
    Negat.count=0;

    CreateList(&L,in);
    PrintList(&L,"\nMy List:\n");
    MoveToAnotherList(&L,&Posit,&Negat);
    PrintList(&Posit,"\n\nThe Positive List:\n");
    PrintList(&Negat,"\n\nThe Negative List:\n\n");

    fclose(in);
    DeleteList(&Posit);
    DeleteList(&Negat);
    return 0;
}



void Error_Msg(char* msg)
{
	printf("\n%s",msg);
	exit(1);
}

void CreateList(List* L, FILE *f)
{
	int value;
	Item *temp;
	while(fscanf(f,"%d",&value)==1)
        {
		temp=(Item*)malloc(sizeof(struct Item));
		if(temp == NULL)
                {
                   DeleteList(L);
                   Error_Msg("Memmory!");
		}

		temp->num=value;
		temp->next=NULL;
		if(L->head==NULL)
			L->head=temp;
		else
			L->tail->next=temp;
		    L->tail=temp;
		L->count++;
	}
}


void PrintItem(Item* node)
{
	printf("%d--> ",node->num);
}


void PrintList(List* L,char* title)
{
	Item* temp=L->head;
	printf("%s",title);
	while(temp)
        {
		PrintItem(temp);
		temp=temp->next;
	}
	printf("\nThere are %d items in the list",L->count);
}

void AddAsFirst(Item* a,List* b){
    if (b->head == NULL)
    {
        b->head = a;
        b->tail = a;
        a->next = NULL;
    }
    else
    {
        a->next = b->head;
        b->head = a; 
    }
    b->count++;
    
}

void AddAsLast(Item* a,List* b){
    if (b->head == NULL)
    {
        b->head = a;
        b->tail = a;
        a->next = NULL;
    }
    else
    {
        b->tail->next = a;
        b->tail = a;
        a->next = NULL;
    }
    b->count++;
}

void DeleteList(List* b){
    Item *a;
    while(b->head != NULL)
    {
        a = b->head;
        b->head = (b->head)->next;
        free(a);
    }
    b->count = 0;
    b->tail = NULL;
}

void MoveToAnotherList(List* Posit,List* Negat,List* b){
    Item* temp = b->head;
    while (temp != NULL)
    {
       Item* a = temp->next;
       if (temp->num >= 0)
       {
         AddAsLast(temp,Posit);
       }
       else
       {
        AddAsFirst(temp,Negat);
       }
       temp = a;
    }
    b->count = 0;
    b->tail = NULL;
}