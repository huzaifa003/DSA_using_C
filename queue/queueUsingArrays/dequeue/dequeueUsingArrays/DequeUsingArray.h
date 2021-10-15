#include <stdio.h>
/*
    * Deque is a special type of queue in which insertion and deletion is possible on both sides
    * Deque makes it possible to insert on both sides by using both front and rear to add and delete elements
*/
#define SIZE 20
typedef struct DequeUsingArray
{
    int front;
    int rear;
    int arr[20];
} DequeUsingArray;

void initDequeUsingArray(DequeUsingArray *queue)
{
    queue->front = -1;
    queue->rear = -1;
}

int isFullDequeUsingArray(DequeUsingArray *queue)
{
    return (queue->front == 0 && queue->rear == SIZE - 1) || queue->front == queue->rear + 1;
}

int isEmptyDequeUsingArray(DequeUsingArray *queue)
{
    return queue->rear == -1 || queue->front == -1;
}
void insertRearDequeUsingArray(DequeUsingArray *queue, int data)
{
    if (isFullDequeUsingArray(queue))
    {
        printf("\nQueue is Full\n");
        return;
    }

    else if (isEmptyDequeUsingArray(queue))
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

void insertFrontDequeUsingArray(DequeUsingArray *queue, int data)
{
    if (isFullDequeUsingArray(queue))
    {
        printf("\nQueue is Full\n");
        return;
    }

    else if (isEmptyDequeUsingArray(queue))
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

int deleteFrontDequeUsingArray(DequeUsingArray *queue)
{
    if (isEmptyDequeUsingArray(queue))
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
        

        return queue->arr[queue->front++];
    }
}

int deleteRearDequeUsingArray(DequeUsingArray *queue)
{
    if (isEmptyDequeUsingArray(queue))
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
        if (queue->rear == -1)
        {
            queue->rear = SIZE - 1; //making it back to 0 aka linking the last element to first one
        }
        

        return queue->arr[queue->rear--];
    }
}

void displayDequeUsingArray(DequeUsingArray *queue)
{
    if (isEmptyDequeUsingArray(queue))
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
