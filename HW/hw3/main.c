#include "headerFile.h"

int main()
/*Receive the N integers from the user and build the list 
2. Pick up the maximum number of steps for the game 
3. Start the game according to the instructions
4. They announce the situation in which the game ended and in how many steps it ended.
    o Dead end.
    o Deviation from the list.
    o We have reached the maximum number of steps.
5. Print the list at the end of the game*/
{
    int arr[N], i, numMoves, k,countMoves=0,flagOutOfList = 0;
    Node* head = NULL, * temp,*p;
    printf("Enter %d numbers: ", N);
    for (i = 0; i < N; i++) //get N integers from the user
    {
        if (scanf("%d", &arr[i]) != 1)
        {
            Error_Msg("scanf error");
        }
    }
    printf("Enter numbers of moves: ");
    if (scanf("%d", &numMoves) != 1)//get the number of moves allowed
    {
        Error_Msg("scanf error");
    }
    CreateListFromArray(&head, arr);//create the linked list from the array
    temp = head;
    while (numMoves != 0 && temp != NULL)//start the game loop
    {
        if (temp->num == 0)//check if the current node value is zero (dead end)
        {
            countMoves++;
            printf("Dead end in %d moves\n",countMoves);
            break;
        }
        else if (temp->num > 0)//if the current node value is positive
        {
            if (temp->num == 1)//if the value is 1, delete the current node
            {
                temp = DeleteItem(temp);
                countMoves++;
                if (temp == NULL)//if the list is empty after node delete
                {
                    flagOutOfList = 1;
                    head = temp;
                    break;
                }
                if (temp->prev == NULL)//update head if first node is deleted
                    head = temp; 
            }
            else//positive number bigger then 1
            {
                k = temp->num;
                countMoves++;
                for (i = 0; i < k; i++)//move forward by node num value 
                {
                    if (temp->next != NULL)
                        temp = temp->next;
                    else//reached the end of the list
                    {
                        flagOutOfList = 1;
                        break;
                    }
                }
            }
        }
        else if(temp->num < 0)//if the current node value is negative
        {
            if (temp->num == -1)//if the value is -1, delete the current node
            {
                temp = DeleteItem(temp);
                countMoves++;
                if (temp == NULL)//if the list is empty after node delete
                {
                    flagOutOfList = 1;
                    head = temp;
                    break;
                }
                if (temp->prev != NULL)//move temp to the prev node
                {
                    temp = temp->prev;
                    if (temp->prev == NULL)//update head if first node is deleted
                    {
                        head = temp;
                    }
                }
                else if (temp->prev == NULL)//if -1 was the head then it brake
                {
                    head = temp;
                    flagOutOfList = 1;
                    break;
                }
            }
            else//negative number smaller then -1
            {
                k = temp->num * (-1);
                countMoves++;
                for (i = 0; i < k; i++)//move backward by node num value
                {
                    if (temp->prev != NULL)
                        temp = temp->prev;
                    else//reached the end of the list
                    {
                        flagOutOfList = 1;
                        break;
                    }
                }
            }
        }
        if (flagOutOfList)//exit if moved out of list
            break;
        numMoves--;//decrease the number of remaining moves
    }
    if (numMoves == 0)//if no moves are left
        printf("We have reached the maximum number of steps.\n");
    else
        printf("Exceeding the list with %d moves\n", countMoves);

    printf("\nThe list is:\n");
    ListDisplay(head);//print the final list
    DeleteList(&head);//delete list and free the memory
    return 0;
}
