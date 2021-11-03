#include <stdio.h>
#include <conio.h>
#include "NodeSinglyLinkedList.h"
void moveEvenAtEnd(Node* head)
{
    Node* iterator = head;
    int length = getLength(head);

    for (int i = 0; i < length; i++)
    {
        if (i%2 == 0)
        {
            head = insertFrontSingly(head,iterator->data);
            deleteAtSingly(head,i);
        }
        iterator = iterator->next;
        
    }
    printf("\n--------------Moving Even at end of List-----------\n");
    
    displaySingly(head);
}
int main(int argc, char const *argv[])
{
    Node *head = NULL;
    head = insertFrontSingly(head, 3);
    head = insertFrontSingly(head, 3);
    head = insertFrontSingly(head, 5);
    head = insertFrontSingly(head, 6);
    head = insertFrontSingly(head, 6);
    head = insertFrontSingly(head, 6);

    printf("\n--------------Previosu List-----------\n");
    displaySingly(head);
    moveEvenAtEnd(head);
    getch();
    return 0;
}
