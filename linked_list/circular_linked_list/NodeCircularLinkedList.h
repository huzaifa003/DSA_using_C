#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
/*
    * In circular linked list we add the last node to first node and it creates a loop
    * THE ONLY NODE THAT WE NEED TO KEEP TRACK OF IS THE LAST NODE
    * AKA TAIL, NOT HEAD
    * THE REASON WE ARE USING HEAD IN HERE IS JUST FOR OUR OWN CONVENIENCE
    * OTHERWISE WE CAN LOOP THE TAIL UNTIL TAIL IS AGAIN FOUND
 */
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

int length = 0;
Node *head = NULL; //initializing head
Node *tail = NULL; //initializing tail
void insertCircular(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    if (tail == NULL) //for first element
    {
        head = newNode;
        tail = newNode;
    }
    else
    {

        tail->next = newNode;
        tail = newNode;

    }
    tail->next = head;
    length++;
}

void displayCircular()
{
    printf("-------------------------------------\n");
    Node *iterator = tail;
    if (tail == NULL)
    {
        return;
    }

    if (iterator == NULL)
    {
        printf("Data is %d\n",tail->data);
    }

    else {

        do
            {
                iterator = iterator->next;
                printf("Data is = %d\n", iterator->data); //display data at each node till its null
            } while (iterator != tail);
    }

    printf("-------------------------------------\n");
}

int deleteFirstCircular()
{
    Node *temp = head;
    if (head != NULL)  //changing head
    {
        head = head->next;
        tail->next = head;
        length--;
        if (length == 0)
        {
            free(head);
            free(tail); //for empty list
            head = NULL;
            tail = NULL;
        }
        return temp->data;
    }
    else
    {
        return NULL;
    }

    
    
}

int deleteLastCircular()
{
    Node *iterator = tail;
    if (tail == NULL)
    {
        return NULL;
    }

    if (iterator->next == NULL) //for a single element aka only tail
    {
        free(head);
        head = NULL;
        free(tail); //freeing memory
        tail = NULL;
        length--;
        return iterator->data;
    }
    else
    {
        while (iterator->next != tail) //iterating for multiple elements
        {
            printf("Data is %d\n", iterator->data);
            iterator = iterator->next;
        }

        Node *temp = iterator->next;
        tail = iterator;
        tail->next = head; //again pointing to head
        length--;

        if (length == 0)
        {
            free(head); //for empty list
            free(tail);
            head = NULL;
            tail = NULL;
        }

        return temp->data;

    }
}

int isEmptyCircular()
{
    return length == 0;
}

int getLength()
{
    return length;
}

