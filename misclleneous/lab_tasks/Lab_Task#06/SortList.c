#include <stdio.h>
#include <conio.h>
#include "NodeSinglyLinkedList.h"
void sortList(Node* head)
{
    Node* iterator = head;
    Node* temp;
    while (iterator->next != NULL)
    {
        temp = iterator->next;
        while (temp != NULL)
        {
            if (temp->data < iterator->data)
            {
                int data = temp->data;
                temp->data = iterator->data;
                iterator->data = data;
            }
            temp = temp->next;
           
        }
        iterator =iterator->next;
    }
    printf("\n------------Sorted List is ------------\n");
    displaySingly(head);

    
}
int main(int argc, char const *argv[])
{
    Node *head = NULL;
    int input = 0;
    for (int i = 0; i < 10; i++)
    {
        printf("Enter the %d Element: ",i+1);
        scanf("%d",&input);
        head = insertFrontSingly(head,input);
    }   
    

    printf("\n------------UnSorted List is ------------\n");
    displaySingly(head);

    sortList(head);
    getch();
    return 0;
}
