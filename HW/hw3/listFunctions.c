#include "headerFile.h"

void ListDisplay(Node* p)//function to display the list(recursive)
{
    if (p != NULL)//until end of list
    {
        if (p->next == NULL)//if last node
            printf("%d", p->num);
        else
        {
            printf("%d -> ", p->num);
            ListDisplay(p->next);
        }
    }
}
void Error_Msg(char* msg)//function to display an error message and exit
{
    printf("\n%s", msg);
    exit(1);
}

void CreateListFromArray(Node** head, int* arr)//function to create a linked list from an array
{
    Node* temp;
    for (int i = 0; i < N; i++)
    {
        temp = (Node*)malloc(sizeof(Node));//crate new node
        if (temp == NULL)//if failed to crate
        {
            DeleteList(head);
            Error_Msg("Memory allocation failed!");
        }
        temp->num = arr[i];
        temp->next = *head;//next point to the head
        temp->prev = NULL;
        if (*head != NULL)//if not the first node
        {
            (*head)->prev = temp;//set head prev to temp
        }
        *head = temp;//set new head to temp
    }
}


Node* DeleteItem(Node* temp)//function to delete a specific node
{
    Node* p;
    if (temp->next == NULL && temp->prev == NULL)//if there only one node
    {
        free(temp);
        p = NULL;
    }
    else if (temp->next == NULL)//if node dont have next
    {
        temp->prev->next = NULL;
        free(temp);
        p = NULL;
    } 
    else if (temp->prev == NULL)//if node dont have prev
    {
        p = temp->next;
        temp->next->prev = NULL;
        free(temp);
    }
    else//if node have next and prev
    {
        p = temp->next;
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
    }
    return p;
}

void DeleteList(Node** head)//function to delete the entire list and free the memory
{
    Node* tmp = *head;
    while (*head != NULL)//until end of list
    {
        tmp = *head;
        *head = (*head)->next;
        free(tmp);
    }
    *head = NULL;
}
