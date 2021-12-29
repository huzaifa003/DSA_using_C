#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct Queue
{
    int arr[5];
    int front;
    int rear;
} Queue;

void insertInQueue(Queue *queue, int data)
{
    if (queue->rear == -1)
    {
        queue->rear = queue->front = 0;
    }
    else if (queue->rear >= 5)
    {
        queue->rear = 0;
    }
    else if ((queue->front == 0 && queue->rear == 4) || (queue->front == queue->rear +1) )
    {
        printf("Queue is full\n");
        return;
    }
    queue->arr[queue->rear] = data;
    queue->rear++;
}

int deleteInQueue(Queue *Queue)
{
    if (Queue->front == -1)
    {
        printf("Empty Queue");
        return -1;
    }
    else if (Queue->front == Queue->rear)
    {
        Queue->front = Queue->rear = -1;
    }
    else
    {
        return Queue->arr[Queue->front++];
    }
}

void displayQueue(Queue *Queue)
{
    for (int i = Queue->front; i != Queue->rear; i++)
    {
        if (i > 4)
        {
            i = 0;
        }
        printf("Data is = %d\n", Queue->arr[i]);
    }
}
int main()
{

    Queue Queue;
    Queue.front = Queue.rear = -1;

    insertInQueue(&Queue, 1);
    insertInQueue(&Queue, 2);
    insertInQueue(&Queue, 3);
    insertInQueue(&Queue, 4);
    insertInQueue(&Queue, 5);
    insertInQueue(&Queue, 6);


    displayQueue(&Queue);

    printf("Queue is = %d\n",deleteInQueue(&Queue));
    printf("Queue is = %d\n",deleteInQueue(&Queue));
    printf("Queue is = %d\n",deleteInQueue(&Queue));
    printf("Queue is = %d\n",deleteInQueue(&Queue));
    displayQueue(&Queue);
    insertInQueue(&Queue, 5);
    insertInQueue(&Queue, 6);
    displayQueue(&Queue);
    getch();
    return 0;
}