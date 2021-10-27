#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int length = 0;
struct Node *head = NULL; //initializing head


int isEmpty()
{
    return length == 0;
}

int getLength()
{
    return length;
}


void insertFront(int data)
{
    if (head == NULL) //for first element 
    {
        head = (struct Node *)malloc(sizeof(struct Node)); //making a new struct Node
        head->data = data; //inserting data
        head->next = NULL;
    }
    else
    {
        struct Node *temporary = head; //iterating till empty struct Node is found
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = NULL;

        while (temporary->next != NULL)
        {
            temporary = temporary->next;
        }
        temporary->next = newNode; //adding struct Node at end
    }
    length++;
}

void insertBack(int data)
{
    if (head == NULL) //for first element 
    {
        head = (struct Node *)malloc(sizeof(struct Node)); //making a new struct Node
        head->data = data; //inserting data
        head->next = NULL;
    }
    else
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = head;

        head = newNode; //changing head to first pointer again
    }
    length++;
}


void display()
{
    printf("-------------------------------------\n");
    struct Node *temporary = head; 
    while (temporary != NULL)
    {
        printf("Data is %d\n", temporary->data); //display data at each struct Node till its null
        temporary = temporary->next;
    }
    printf("-------------------------------------\n");
}

int deleteFirst()
{
    struct Node *temp = head;
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

int deleteLast()
{
    struct Node *temporary = head;
    if (head == NULL)
    {
        return NULL;
    }
    
    if (temporary->next == NULL) //for a single element aka only head
    {
        head = NULL;
        free(head); //freeing memory
        length--;
        return temporary->data;
    }
    else
    {
        
        while (temporary->next->next != NULL) //iterating for multiple elements 
        {
            printf("Data is %d\n", temporary->data);
            temporary = temporary->next;
        }
        struct Node *temp = temporary->next;
        temporary->next = NULL;
        length--;
        free(temporary->next);
        return temp->data;

    }
}

int deleteAt(int index)
{
    if (index >= getLength())
    {        
        printf("\n-----------Index overflow-------------\n");
        return -1;
    }
    
    struct Node *temporary = head;
    {
        for (int i = 1; i < index-1; i++)
        {
            temporary = temporary->next;
        }
        struct Node* temp = temporary->next;
        temporary->next = temporary->next->next;
        length--;
        return temp->data;
    }
    
}


