#include <stdio.h>
#include <conio.h>
#include "NodeSinglyLinkedList.h"

void shuffleMerge(Node* head1 , Node* head2)
{
    while (head2 != NULL)
    {
        insertAtSingly(head1,head2->data,rand()%getLength(head1));
        head2 = deleteFirstSingly(head2);
    }

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
    head2 = insertFrontSingly(head2,5);
    head2 = insertFrontSingly(head2,6);

    shuffleMerge(head1,head2);
    getch();
}
