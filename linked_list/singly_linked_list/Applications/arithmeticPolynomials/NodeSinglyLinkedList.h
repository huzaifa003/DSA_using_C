#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    int power;
    struct Node *next;
} Node;

Node *createNode(Node *head)
{
    head = (Node *)malloc(sizeof(Node));
    head = NULL;
    return head;
}

int getLength(Node *head)
{
    Node *temp = head;
    int i;
    for (i = 0; temp != NULL; i++)
    {
        temp = temp->next;
    }
    return i;
}

int isEmptySingly(Node *head)
{
    return getLength(head) == 0;
}

Node *insertFrontSingly(Node *head, int data, int power)
{
    if (head == NULL) //for first element
    {
        head = (Node *)malloc(sizeof(Node)); //making a new node
        head->data = data;                   //inserting data
        head->power = power;
        head->next = NULL;
    }
    else
    {
        Node *iterator = head; //iterating till empty node is found
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->power = power;
        newNode->data = data;
        newNode->next = NULL;

        while (iterator->next != NULL)
        {
            iterator = iterator->next;
        }
        iterator->next = newNode; //adding node at end
    }
    return head;

}

Node *insertBackSingly(Node *head, int data, int power)
{
    if (head == NULL) //for first element
    {
        head = (Node *)malloc(sizeof(Node)); //making a new node
        head->data = data;                   //inserting data
        head->power = power;
        head->next = NULL;
        return head;
    }
    else
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = data;
        newNode->next = head;
        newNode->power = power;
        head = newNode; //changing head to first pointer again
    }
    return head;

}

void displaySingly(Node *head)
{
    printf("--------------DATA is  =  -------------------\n");
    Node *iterator = head;
    while (iterator != NULL)
    {
        if (iterator->data > 0)
        {
            printf("+%dx^%d", iterator->data, iterator->power);
        }
        else
        {
            printf("%dx^%d", iterator->data, iterator->power); //display data at each node till its null
        }
        iterator = iterator->next;
    }
    printf("\n-------------------------------------\n");
}

int deleteFirstSingly(Node *head)
{
    Node *temp = head;
    if (head != NULL) //changing head
    {
        head = head->next;
        return temp->data;
    }
    else
    {
        return NULL;
    }
}

int deleteLastSingly(Node *head)
{
    Node *iterator = head;
    if (head == NULL)
    {
        return NULL;
    }

    if (iterator->next == NULL) //for a single element aka only head
    {
        head = NULL;
        free(head); //freeing memory
        return iterator->data;
    }
    else
    {

        while (iterator->next->next != NULL) //iterating for multiple elements
        {
            iterator = iterator->next;
        }
        Node *temp = iterator->next;
        iterator->next = NULL;
        free(iterator->next);
        return temp->data;
    }
}

int deleteAtSingly(Node *head, int index)
{
    if (index >= getLength(head))
    {
        printf("\n-----------Index overflow-------------\n");
        return -1;
    }

    Node *iterator = head;
    {
        for (int i = 1; i < index - 1; i++)
        {
            iterator = iterator->next;
        }
        Node *temp = iterator->next;
        iterator->next = iterator->next->next;
        return temp->data;
    }
}
