#include <stdio.h>
/*
    * Dequeue is a special type of queue in which insertion and deletion is possible on both sides
    * Dequeue makes it possible to insert on both sides by using both front and rear to add and delete elements
    * It can be made by both normal and circular queue, in this case circular queue is being used.
*/
#define SIZE 20 
typedef struct DequeueUsingArray
{
    int front;
    int rear;
    int arr[20];
}DequeueUsingArray;

void initDequeueUsingArray(DequeueUsingArray* queue)
{
    queue->front = -1;
    queue->rear = -1;
}

int isFullDequeueUsingArray(DequeueUsingArray* queue)
{
    return (queue->front == 0 && queue->rear == SIZE-1) || queue->front == queue->rear+1   
}

int isEmptyDequeueUsingArray(DequeueUsingArray* queue)
{
    return queue->rear == -1;
}
void insertFrontDequeueUsingArray(DequeueUsingArray* queue, int data)
{
    if (isFullDequeueUsingArray(queue))
    {
        printf("\nQueue is Full\n");
        return;
    }

    else if(queue->rear == SIZE) 
    {
        queue->rear = 0
    }
    
    queue->rear++;
    queue->arr[queue->rear];
    
}