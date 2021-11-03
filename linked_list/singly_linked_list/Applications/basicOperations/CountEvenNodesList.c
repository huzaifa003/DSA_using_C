#include <stdio.h>
#include <conio.h>
#include "NodeSinglyLinkedList.h"

int numberOfEvenNodes(Node* head)
{
    int count = 0;
    int evenCount = 0;
    Node* iterator = head;
    while (iterator != NULL)
    {
        if(count %2 == 0)
        {
            evenCount++;
        }
        count++;
        iterator = iterator->next;
    }
    
    return evenCount;
}
int main(int argc, char const *argv[])
{
    Node *head = NULL;

    head = insertFrontSingly(head, 1);
    head = insertFrontSingly(head, 2);
    head = insertFrontSingly(head, 3);
    head = insertFrontSingly(head, 4);
    head = insertFrontSingly(head, 5);
    head = insertFrontSingly(head, 6);

    printf("Even No of nodes are  =  %d",numberOfEvenNodes(head));
    getch();
    return 0;
}
