#include <stdio.h>
#include <conio.h>
#include "NodeSinglyLinkedList.h"


void deleteAllNodes(Node* head)
{
    Node* temp = head;
    Node* next = temp->next;

    while (next != NULL)
    {
        free(temp);
        temp = next;
        next = next->next;
    }
    free(head);
    head = NULL;
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
    
    deleteAllNodes(head);
    getch();
    return 0;
}
