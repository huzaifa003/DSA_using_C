#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

/*
 * Queue is basically same as singly linked list
 * FRONT of the queue is the first element
 * REAR is the last element
 * it works on FIFO principle
 * the only DIFFERENCE with linked list is that adding is done by front and deletion by rear
 * IT MIMICS REAL QUEUE (This queue is followed by everybody though:))
 * REAR IS USED TO ADD ELEMENTS
 * FRONT IS USED TO DELETE ELEMENTS
 */

typedef struct NodeQueue
{
    struct NodeQueue *next;
    int data;
} NodeQueue;

NodeQueue *front = NULL; // will be used to remove data or dequeue
NodeQueue *rear = NULL;  //will be used to add data or enqueue
int length = 0;

void enqueue(int data)
{
    NodeQueue *newNode = (NodeQueue *)malloc(sizeof(NodeQueue));
    newNode->data = data;
    if (front == NULL && rear == NULL)
    {
        front = newNode;
        rear = newNode;
        
    }
    else
    {
        rear->next = newNode;
        rear = newNode; //using rear part to insert the nodes at the end
    }
    rear->next = NULL; //making rear's next = NULLs
    length++;
}

int dequeue()
{
    if (front != NULL)
    {
        NodeQueue* temp = front;
        front = front->next; //replacing front with another element
        length--;
        if (length == 0) //if front is null then rear will be null as well so making sure of that
        {
        
            front = NULL;
            rear = NULL;
        }
        
        return temp->data; //returning the last node
    }
    else
    {
        return 0;
    }
}

NodeQueue* dequeueNode()
{
    if (front != NULL)
    {
        NodeQueue* temp = front;
        front = front->next; //replacing front with another element
        length--;
        if (length == 0) //if front is null then rear will be null as well so making sure of that
        {
        
            front = NULL;
            rear = NULL;
        }
        
        return temp; //returning the last node
    }
    else
    {
        return NULL;
    }
}


int isEmptyQueue()
{
    return length == 0;
}

int getLengthQueue()
{
    return length;
}

void freeQueue()
{ 
    //freeing memory along with dangling Pointers handling by placing NUll
    free(front);
    free(rear);
    front = NULL;
    rear = NULL;
    length = 0;
}

void displayQueue()
{
    NodeQueue* temp = front;
    printf("\n---------------------------------------\n");   
    while (temp != NULL)
    {
        printf("Data is = %d\n",temp->data);
        temp = temp->next;
    }
    printf("\n---------------------------------------\n");
}
