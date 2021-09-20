#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node* prev;
    int data;
    struct Node* next;
} Node;

int length = 0;
Node* head = NULL; //points to first element
Node* tail = NULL; //points to last element

void insertFrontDoubly(int data)
{
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->data = data;
    if (head == NULL)
    {
        //setting both tail and head
        head = newNode;
        tail = newNode;
    }
    else
    {


        Node* temp = tail;
        
        temp->next = newNode;
        newNode->prev = temp;
        tail = newNode;

    }
    length++;
}

void insertBackDoubly(int data)
{

    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->data = data;
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }

    else
    {

        newNode->next = head;
        head->prev = newNode;
        head = newNode;

        newNode->data = data;
        newNode->prev = NULL;
    }
    length++;
}


void seperator()
{
    printf("\n---------------------------------\n");
}
void displayFrontwardsDoubly()
{
    seperator();
    Node* temp = head;
    while (temp != NULL)
    {
        printf("Data Frontwards is = %d\n",temp->data);
        temp = temp->next;
    }

}

void displayBackwardsDoubly()
{
    seperator();
    Node* temp = tail;
    while (temp != NULL)
    {
        printf("Data Backwards is = %d\n",temp->data);
        temp = temp->prev;
    }
}

void deleteLastDoubly()
{
    tail = tail->prev;
    tail->next = NULL;
    length--;
}

void deleteFirstDoubly()
{
    head = head->next;
    head->prev = NULL;
    length--;
}

int getLenghtDoubly()
{
    return length;
}

int isEmptyDoubly()
{
    return length == 0;
}



