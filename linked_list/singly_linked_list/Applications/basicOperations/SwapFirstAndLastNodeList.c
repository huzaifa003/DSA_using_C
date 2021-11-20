#include <stdio.h>
#include <conio.h>
#include "NodeSinglyLinkedList.h"
void swap(Node* head)
{
    Node* firstNode = head;
    Node* lastNode;
    Node* lastNodePrev;
    while (firstNode->next != NULL)
    {
        lastNodePrev = firstNode;
        firstNode = firstNode->next;
    }

    lastNode = firstNode;
    firstNode = head;

    Node* temp = lastNodePrev;
    lastNodePrev->next = firstNode;
    lastNode->next = head->next;
    
    head = lastNode;
    firstNode->next = NULL;


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
    head = insertFrontSingly(head, 7);
    printf("\n--------------Before EXCHANGING BOTH NODES----------\n");
    displaySingly(head);
    swap(head);

    getch();
    return 0;
}
