#include <stdio.h>
#include <conio.h>
#include "NodeSinglyLinkedList.h"

void reverseList(Node* parent)
{
    Node* reversedList = NULL;
    Node* iterator = parent;

    while (iterator != NULL)
    {
        reversedList = insertBackSingly(reversedList,iterator->data);
        iterator  = iterator->next;
    }

    printf("\n------------Reversed List is------------\n");
    displaySingly(reversedList);

    free(parent);
    
}
int main(int argc, char const *argv[])
{
    Node *parent = NULL;

    parent = insertFrontSingly(parent, 1);
    parent = insertFrontSingly(parent, 2);
    parent = insertFrontSingly(parent, 3);
    parent = insertFrontSingly(parent, 4);
    parent = insertFrontSingly(parent, 5);
    parent = insertFrontSingly(parent, 6);

    printf("\n------------Non-Reversed List is------------\n");
    displaySingly(parent);

    reverseList(parent);
    getch();
    return 0;
}
