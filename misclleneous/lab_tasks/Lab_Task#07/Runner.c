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


int getLenghtDoubly()
{
    return length;
}

int isEmptyDoubly()
{
    return length == 0;
}

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

void insertAt(int data, int index)
{
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;

    if (index == 0)
    {
        insertBackDoubly(data);
        return;
    }

    else if (index == getLenghtDoubly())
    {
        insertFrontDoubly(data);
        return;
    }
    
    Node* temp = head;
    for (int i = 1; i < index; i++)
    {
        temp = temp->next;
    }

    newNode->prev = temp;
    newNode->next = temp->next;

    temp->next->prev = newNode;
    temp->next = newNode;
    
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

int deleteLastDoubly()
{
    Node* temp = tail;
    tail = tail->prev;
    tail->next = NULL;
    length--;
    return temp->data;
}

int  deleteFirstDoubly()
{
    Node* temp = head;
    head = head->next;
    head->prev = NULL;
    length--;
    return temp->data;
}


void deleteAt(int index)
{

    if (index == 0)
    {
        deleteFirstDoubly();
        return;
    }

    else if (index == getLenghtDoubly())
    {
        deleteLastDoubly();
        return;
    }
    
    Node* temp = head;
    for (int i = 1; i < index; i++)
    {
        temp = temp->next;
    }

    Node* temp2 = temp->next->next;
    temp2->prev = temp;
    temp->next = temp2;

}

int main(int argc, char const *argv[])
{
    if (isEmptyDoubly())
    {
        printf("List is empty before insertion\n");
    }
    else
    {
        printf("There has to be some error!!");
    }
    
    
    insertFrontDoubly(1);
    insertFrontDoubly(2);
    insertFrontDoubly(3);
    insertBackDoubly(54);
    insertBackDoubly(10);
    printf("Starting length is = %d",getLenghtDoubly());

    displayFrontwardsDoubly();
    displayBackwardsDoubly();

    insertAt(7,3);
    displayFrontwardsDoubly();
    deleteAt(3);
    deleteLastDoubly();

    displayFrontwardsDoubly();
    displayBackwardsDoubly();

    deleteFirstDoubly();

    displayFrontwardsDoubly();
    displayBackwardsDoubly();
    printf("\nEnding length is = %d",getLenghtDoubly());
    if (!isEmptyDoubly())
    {
        printf("\n\nList is NOT empty before insertion\n");
    }
    else
    {
        printf("There has to be some error!!");
    }
    getch();
    return 0;
}