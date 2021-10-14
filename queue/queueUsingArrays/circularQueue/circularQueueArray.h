#include "stdio.h"
#define SIZE 10 

/*
 * In a normal Queue, we can insert elements until queue becomes full. But once queue becomes full, we can not insert the next element even if there is a space in front of queue.
 * In Circular Queue you can still insert elements in a circular manner
 * Circular Queue is a linear data structure in which the operations are performed based on FIFO (First In First Out) principle and the last position is connected back to the first position to make a circle. It is also called ‘Ring Buffer’. 
 */
typedef struct circularQueueArray
{
    int front;
    int rear;
    int array[SIZE];

}circularQueueArray;

void initcircularQueueArray(circularQueueArray* queue)
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

int isFullcircularQueueArray(circularQueueArray* queue)
{
    return (queue->front == 0 && queue->rear == SIZE-1) || queue->front == queue->rear +1; //checks if queue is full (Elements are overidden and returns the value 1 if it's true and 0 if its false for both cases 
}
int isEmptycircularQueueArray(circularQueueArray* queue)
{
    return queue->rear == -1 && queue->front == -1;
}
int enqueuecircularQueueArray(circularQueueArray* queue, int data)
{
    if (isEmptycircularQueueArray(queue))
    {
        queue->rear = 0;
        queue->front = 0;
    }
    

    else if (isFullcircularQueueArray(queue)) //in queue rear points to last element and it is used to add more elements to the queue
    {
        printf("----------------\nQueue is full\n------------");
        return -1;
    }
    else
    {
        queue->rear++; //again incrementing rear first cause it's starting index is = -1 (Read init for clarification)
        if (queue->rear == SIZE)
        {
            queue->rear = 0 ; //making it back to 0 aka linking the last element to first one
        }
    }
    queue->array[queue->rear] = data; //adding data
}

int dequeuecircularQueueArray(circularQueueArray* queue)
{
    if (isEmptycircularQueueArray(queue))
    {
        printf("\n-----------Queue is empty and cannot be dequeued-----------\n");
        return -2;
    }
    else
    {
        queue->front++; //incrementing front first as deletion is carried out by front and front's starting value is = -1 (Read init for clarification)
        if (queue->front == SIZE)
        {
            queue->front = 0 ; //making it back to 0 aka linking the last element to first one
        }
        return queue->array[queue->front];
    }
}

void displaycircularQueueArray(circularQueueArray* queue)
{
    if (isEmptycircularQueueArray(queue))
    {
        printf("\n-----------Queue is empty and cannot be dequeued-----------\n");
        return;
    }
    printf("\n-----------DISPLAYING QUEUE CIRCULAR-------------\n");
    int i = queue->front ,counter = 0;
    do //Do While cause same front and rear can have values too
    {
        if (i >= SIZE)
        {
            i = 0;
        }
        printf("Element %d of queue is = %d\n",counter,queue->array[i]);
        counter++;
        i++;
    } while(i != queue->rear +1);
    
}



