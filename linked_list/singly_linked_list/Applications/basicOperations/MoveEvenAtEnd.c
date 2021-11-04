#include <stdio.h>
#include <conio.h>
#include "NodeSinglyLinkedList.h"
void moveEvenAtEnd(Node *head)
{
    Node *iterator = head;
    int length = getLength(head);
    for (int i = 0, j = 0; i < length; i++)
    {
        if (iterator->data % 2 == 0)
        {
            head = insertFrontSingly(head, iterator->data);
            deleteAtSingly(&head, j);
            iterator = iterator->next; //moving to ndex element after deleting previous one
            continue; //dont increment j
        }
        j++; //j will only increment if node is not deleted as length of list is shortened when node is deleted
        iterator = iterator->next;
    }
    printf("\n--------------Moving Even at end of List-----------\n");

    displaySingly(head);
}
int main(int argc, char const *argv[])
{
    Node *head = NULL;
    head = insertFrontSingly(head, 2);
    head = insertFrontSingly(head, 4);
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
