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

    head1 = insertFrontSingly(head1,1);
    head1 = insertFrontSingly(head1,2);

    head2 = insertFrontSingly(head2,3);
    head2 = insertFrontSingly(head2,4);

    cocatenate(head1,head2);
    getch();
    return 0;
}


