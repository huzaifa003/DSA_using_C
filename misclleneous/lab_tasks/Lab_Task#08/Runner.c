#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
} Node;

Node *head = NULL; 
Node *tail = NULL; 


void insertFront(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->data = data;
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {

        Node *temp = tail;

        temp->next = newNode;
        newNode->prev = temp;
        tail = newNode;
    }
}

void displayFrontwards()
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("Data Frontwards is = %d\n", temp->data);
        temp = temp->next;
    }
}
void removeDuplicates()
{
    Node *outertemp = head;
    Node *innertemp = NULL;

    while (outertemp->next != NULL)
    {
        innertemp = outertemp;
        if (innertemp == NULL)
        {
            return;
        }
        
        while (innertemp->next != NULL)
        {
            if (innertemp->next->data == outertemp->data)
            {
                innertemp->next = innertemp->next->next;
                if (innertemp->next != NULL)
                {
                    innertemp->next->prev = innertemp;
                }
                continue;
            }
            innertemp = innertemp->next;
        }

        outertemp = outertemp->next;
    }
}

int main()
{

    insertFront(1);
    insertFront(3);
    insertFront(4);
    insertFront(4);
    insertFront(4);
    insertFront(3);
    insertFront(3);
    insertFront(2);
    displayFrontwards();


    printf("\nAfter Removing Duplicates\n");
    removeDuplicates();
    displayFrontwards();
    getch();
    return 0;
}