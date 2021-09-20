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

void insertSingly(int data)
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
            printf("Data is %d\n", iterator->data);
            iterator = iterator->next;
        }
        Node *temp = iterator->next;
        iterator->next = NULL;
        length--;
        free(iterator->next);
        return temp->data;

    }
}

int isEmptySingly()
{
    return length == 0;
}

int getLength()
{
    return length;
}
