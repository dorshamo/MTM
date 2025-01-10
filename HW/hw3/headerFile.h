#ifndef headerFile
#define headerFile

#define _CRT_SECURE_NO_WARNINGS  
#include <stdio.h>               
#include <stdlib.h>              
#include <string.h>              
#define N 10                     

typedef struct Node {
	int num;//integer data in the node
	struct Node* next;//pointer to the next node in the list
	struct Node* prev;//pointer to the previous node in the list
} Node;

void Error_Msg(char*);//function to display an error message and exit
void CreateListFromArray(Node**, int*);//function to create a linked list from an array
void DeleteList(Node**);//function to delete the entire list and free the memory
void ListDisplay(Node*);//function to display the list
Node* DeleteItem(Node* item);//function to delete a specific node

#endif
