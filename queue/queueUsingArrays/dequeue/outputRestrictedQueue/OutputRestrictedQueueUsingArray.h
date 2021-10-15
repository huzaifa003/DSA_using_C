#include <stdio.h>
/*
    * Input restricted Deque is a special type of queue in which insertion is allowed on only 1 end deletion is possible on both sides
*/
#define SIZE 20
typedef struct OutputRestrictedDequeUsingArray
{
    int front;
    int rear;
    int arr[20];
} OutputRestrictedDequeUsingArray;

void initOutputRestrictedDequeUsingArray(OutputRestrictedDequeUsingArray *queue)
{
    queue->front = -1;
    queue->rear = -1;
}

int isFullOutputRestrictedDequeUsingArray(OutputRestrictedDequeUsingArray *queue)
{
    return (queue->front == 0 && queue->rear == SIZE - 1) || queue->front == queue->rear + 1;
}

int isEmptyOutputRestrictedDequeUsingArray(OutputRestrictedDequeUsingArray *queue)
{
    return queue->rear == -1 || queue->front == -1;
}
void insertRearOutputRestrictedDequeUsingArray(OutputRestrictedDequeUsingArray *queue, int data) //insertion only on 1 side
{
    if (isFullOutputRestrictedDequeUsingArray(queue))
    {
        printf("\nQueue is Full\n");
        return;
    }

    else if (isEmptyOutputRestrictedDequeUsingArray(queue))
    {
        queue->rear = 0;
        queue->front = 0;
    }

    else
    {
        queue->rear++;
        if (queue->rear == SIZE)
        {
            queue->rear = 0; //making it back to 0 aka linking the last element to first one
        }
    }
    queue->arr[queue->rear] = data;
    
}


int deleteFrontOutputRestrictedDequeUsingArray(OutputRestrictedDequeUsingArray *queue) //deletion at only one side
{
    if (isEmptyOutputRestrictedDequeUsingArray(queue))
    {
        printf("\n-----------Queue is empty and cannot be Dequed-----------\n");
        return -2;
    }
    else if (queue->front == queue->rear) //in case of a single element 
    {
        int temp  = queue->arr[queue->front];
        queue->front = -1;
        queue->rear = -1;
        return temp;
    }
    else
    {
        if (queue->front == SIZE)
        {
            queue->front = 0; //making it back to 0 aka linking the last element to first one
        }
        

        return queue->arr[queue->front++]; //incrementing too
    }
}

void insertFrontOutputRestrictedDequeUsingArray(OutputRestrictedDequeUsingArray *queue, int data)
{
    if (isFullOutputRestrictedDequeUsingArray(queue))
    {
        printf("\nQueue is Full\n");
        return;
    }

    else if (isEmptyOutputRestrictedDequeUsingArray(queue))
    {
        queue->rear = 0;
        queue->front = 0;
    }

    else
    {
        queue->front--;
        if (queue->front == -1)
        {
            queue->front = SIZE - 1;
        }
    }

    queue->arr[queue->front] = data;
    
}


void displayOutputRestrictedDequeUsingArray(OutputRestrictedDequeUsingArray *queue)
{
    if (isEmptyOutputRestrictedDequeUsingArray(queue))
    {
        printf("\n-----------Queue is empty and cannot be Dequed-----------\n");
        return;
    }
    printf("\n-----------DISPLAYING DEQUE-------------\n");
    int i = queue->front, counter = 0;

    while (i != queue->rear)
    {
        printf("Element %d of queue is = %d\n", counter, queue->arr[i]);
        i++;
        if (i >= SIZE)
        {
            i = 0;
        }
        counter++;
    }
    printf("Element %d of queue is = %d\n", counter, queue->arr[queue->rear]); //for printing the last value
}
