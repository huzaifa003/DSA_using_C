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

    head = insertFrontSingly(head, 1);
    head = insertFrontSingly(head, 3);
    head = insertFrontSingly(head, 7);
    head = insertFrontSingly(head, -1);
    head = insertFrontSingly(head, 4);
    head = insertFrontSingly(head, 2);

    printf("\n------------UnSorted List is ------------\n");
    displaySingly(head);

    sortList(head);
    getch();
    return 0;
}
