#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

int length = 0;
Node *head = NULL; //initializing head


int isEmptySingly()
{
    return length == 0;
}

int getLength()
{
    return length;
}


void insertFrontSingly(int data)
{
    if (head == NULL) //for first element 
    {
        head = (Node *)malloc(sizeof(Node)); //making a new node
        head->data = data; //inserting data
        head->next = NULL;
    }
    else
    {
        Node *iterator = head; //iterating till empty node is found
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = data;
        newNode->next = NULL;

        while (iterator->next != NULL)
        {
            iterator = iterator->next;
        }
        iterator->next = newNode; //adding node at end
    }
    length++;
}

void insertBackSingly(int data)
{
    if (head == NULL) //for first element 
    {
        head = (Node *)malloc(sizeof(Node)); //making a new node
        head->data = data; //inserting data
        head->next = NULL;
    }
    else
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = data;
        newNode->next = head;

        head = newNode; //changing head to first pointer again
    }
    length++;
}

void insertAtSingly(int data, int index)
{
    if (index > getLength())
    {
        printf("\n-----------Index overflow-------------\n");
        return ;
    }

    else if (index == 0)
    {
        insertBackSingly(data);
    }
    else if (index == getLength())
    {
        insertFrontSingly(data);
    }
    else
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = data;
        Node *iterator = head;

        for (int i = 1; i < index - 1; i++)
        {
            iterator = iterator->next;
        }
        newNode->next = iterator->next;
        iterator->next = newNode;
        length++;
    }
}
void displaySingly()
{
    printf("-------------------------------------\n");
    Node *iterator = head; 
    while (iterator != NULL)
    {
        printf("Data is %d\n", iterator->data); //display data at each node till its null
        iterator = iterator->next;
    }
    printf("-------------------------------------\n");
}

int deleteFirstSingly()
{
    Node *temp = head;
    if (head != NULL)  //changing head
    {
        head = head->next;
        length--;
        return temp->data;
    }
    else 
    {
        return NULL;
    }
}

int deleteLastSingly()
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
        length--;
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
        length--;
        free(iterator->next);
        return temp->data;

    }
}

int deleteAtSingly(int index)
{
    if (index >= getLength())
    {        
        printf("\n-----------Index overflow-------------\n");
        return -1;
    }
    
    Node *iterator = head;
    {
        for (int i = 1; i < index-1; i++)
        {
            iterator = iterator->next;
        }
        Node* temp = iterator->next;
        iterator->next = iterator->next->next;
        length--;
        return temp->data;
    }
    
}


