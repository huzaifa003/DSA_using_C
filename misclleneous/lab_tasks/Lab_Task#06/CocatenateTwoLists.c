#include <stdio.h>
#include <conio.h>
#include "NodeSinglyLinkedList.h"

void cocatenate(Node* head1, Node* head2)
{
    Node* iterator  = head1;

    while (iterator->next != NULL)
    {
        iterator = iterator->next;
    }

    iterator->next = head2;
    displaySingly(head1);
    
}

int main(int argc, char const *argv[])
{
    Node* head1 = NULL;
    Node* head2 = NULL;

    int input = 0;
    for (int i = 0; i < 5; i++)
    {
        printf("Enter the %d Element of 1st List: ",i+1);
        scanf("%d",&input);
        head1 = insertFrontSingly(head1,input);
    }   

    for (int i = 0; i < 5; i++)
    {
        printf("Enter the %d Element of 2nd List: ",i+1);
        scanf("%d",&input);
        head2 = insertFrontSingly(head2,input);
    }   

    cocatenate(head1,head2);
    getch();
    return 0;
}


