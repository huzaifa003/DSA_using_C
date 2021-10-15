#include <stdio.h>
/*
    * Deque is a special type of queue in which insertion and deletion is possible on both sides
    * Deque makes it possible to insert on both sides by using both front and rear to add and delete elements
*/
#define SIZE 20
static int insertNo = 0; //will keep track on how many values are inserted
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
    return (queue->front == 0 && queue->rear == SIZE - 1) || queue->front == queue->rear + 1 || insertNo == SIZE;
}

int isEmptyDequeUsingArray(DequeUsingArray *queue)
{
    return queue->rear == -1 || queue->front == -1 || insertNo == 0;
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
    insertNo++;
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
    insertNo++;
}

int deleteFrontDequeUsingArray(DequeUsingArray *queue)
{
    if (isEmptyDequeUsingArray(queue))
    {
        printf("\n-----------Queue is empty and cannot be Dequed-----------\n");
        return -2;
    }
    else
    {
        queue->front++; //incrementing front first as deletion is carried out by front and front's starting value is = -1 (Read init for clarification)
        if (queue->front == SIZE)
        {
            queue->front = 0; //making it back to 0 aka linking the last element to first one
        }
        insertNo--;

        return queue->arr[queue->front];
    }
}

int deleteRearDequeUsingArray(DequeUsingArray *queue)
{
    if (isEmptyDequeUsingArray(queue))
    {
        printf("\n-----------Queue is empty and cannot be Dequed-----------\n");
        return -2;
    }
    else
    {
        queue->rear--; //decrementing first as rear deletion is started from -1 and it changes to SIZE -1
        if (queue->rear == -1)
        {
            queue->rear = SIZE - 1; //making it back to 0 aka linking the last element to first one
        }
        insertNo--;

        return queue->arr[queue->rear];
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
