#include <stdio.h>
#include <conio.h>
#include "NodeSinglyLinkedList.h"

void deleteDuplicates(Node* head)
{
    Node* outerIterator = head;
    Node* innerIterator;

    while (outerIterator != NULL && outerIterator->next != NULL)
    {
        innerIterator = outerIterator;

        while (innerIterator->next != NULL)
        {
            if (innerIterator->next->data == outerIterator->data)
            {
                innerIterator->next = innerIterator->next->next;
            }
            else
            {
                innerIterator = innerIterator->next; //only incremeent if we can't find equal
            }   
        }
        outerIterator = outerIterator->next;
    }
    printf("\n----------------Without Duplicates-------------\n");
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

    printf("\n----------------With Duplicates-------------\n");
    displaySingly(head);
    deleteDuplicates(head);
    getch();
    return 0;
}
