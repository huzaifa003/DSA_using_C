#include <stdio.h>
/*
    * Input restricted Deque is a special type of queue in which insertion is allowed on only 1 end deletion is possible on both sides
*/
#define SIZE 20
typedef struct InputRestrictedDequeUsingArray
{
    int front;
    int rear;
    int arr[20];
} InputRestrictedDequeUsingArray;

void initInputRestrictedDequeUsingArray(InputRestrictedDequeUsingArray *queue)
{
    queue->front = -1;
    queue->rear = -1;
}

int isFullInputRestrictedDequeUsingArray(InputRestrictedDequeUsingArray *queue)
{
    return (queue->front == 0 && queue->rear == SIZE - 1) || queue->front == queue->rear + 1;
}

int isEmptyInputRestrictedDequeUsingArray(InputRestrictedDequeUsingArray *queue)
{
    return queue->rear == -1 || queue->front == -1;
}
void insertRearInputRestrictedDequeUsingArray(InputRestrictedDequeUsingArray *queue, int data) //insertion only on 1 side
{

    if (isFullInputRestrictedDequeUsingArray(queue))
    {
        printf("\nQueue is Full\n");
        return;
    }

    else if (isEmptyInputRestrictedDequeUsingArray(queue))
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


int deleteFrontInputRestrictedDequeUsingArray(InputRestrictedDequeUsingArray *queue)
{
    if (isEmptyInputRestrictedDequeUsingArray(queue))
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

int deleteRearInputRestrictedDequeUsingArray(InputRestrictedDequeUsingArray *queue)
{
    if (isEmptyInputRestrictedDequeUsingArray(queue))
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

void displayInputRestrictedDequeUsingArray(InputRestrictedDequeUsingArray *queue)
{
    if (isEmptyInputRestrictedDequeUsingArray(queue))
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
