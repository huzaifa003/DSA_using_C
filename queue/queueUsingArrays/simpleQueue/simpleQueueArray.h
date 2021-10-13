#include "stdio.h"
#define SIZE 20 

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
typedef struct simpleQueueArray
{
    int front;
    int rear;
    int array[SIZE];

}simpleQueueArray;

void initSimpleQueueArray(simpleQueueArray* queue)
{
    /*
    initializing the queue
    front is used to remove data
    rear is used to add data

    both have indexes of -1 at start indicating they are empty
    as Arrays index start at 0

    Here array is statically created so we don't utillize malloc function :)
    */
    queue->front = -1;
    queue->rear = -1;
}

int isEmptySimpleQueueArray(simpleQueueArray* queue)
{
    return queue->front == queue->rear; //checks if front is == rear and returns the value 1 if it's true and 0 if its false
}

int enqueueSimpleQueueArray(simpleQueueArray* queue, int data)
{
    if (queue->rear == SIZE) //in queue rear points to last element and it is used to add more elements to the queue
    {
        printf("Queue is full");
        return -1;
    }
    else
    {
        queue->rear++; //again incrementing rear first cause it's starting index is = -1 (Read init for clarification)
        queue->array[queue->rear] = data; //adding data
    }
}

int dequeueSimpleQueueArray(simpleQueueArray* queue)
{
    if (isEmptySimpleQueueArray(queue))
    {
        printf("\n-----------Queue is empty and cannot be dequeued-----------\n");
        return -2;
    }
    else
    {
        queue->front++; //incrementing front first as deletion is carried out by front and front's starting value is = -1 (Read init for clarification)
        return queue->array[queue->front];
    }
}

void displaySimpleQueueArray(simpleQueueArray* queue)
{
    if (isEmptySimpleQueueArray(queue))
    {
        printf("\n-----------Queue is empty and cannot be dequeued-----------\n");
    }
    
    for (int i = queue->front +1; i <= queue->rear; i++) //+1 cause we don't have to display already dequeued element
    {
        printf("Element %d of queue is = %d\n",i-queue->front,queue->array[i]);
    }
    
}



