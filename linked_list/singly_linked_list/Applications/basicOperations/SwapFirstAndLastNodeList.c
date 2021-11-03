#include <stdio.h>
#include <conio.h>
#include "NodeSinglyLinkedList.h"
//TODO
void swap(Node* head)
{
    Node* firstNode = head;
    Node* lastNode;

    while (firstNode->next != NULL)
    {
        firstNode = firstNode->next;
    }

    lastNode = firstNode;
    firstNode = head;

    int temp = head->data;
    firstNode->data = lastNode->data;
    lastNode->data = temp;

    printf("\n--------------AFTER EXCHANGING BOTH NODES----------\n");

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
    printf("\n--------------Before EXCHANGING BOTH NODES----------\n");
    displaySingly(head);
    swap(head);

    getch();
    return 0;
}
