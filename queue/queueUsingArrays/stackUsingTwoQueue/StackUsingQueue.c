#include <stdio.h>
#include <conio.h>
#include "simpleQueueArray.h"
#include <stdlib.h>

void push(simpleQueueArray *queue1, simpleQueueArray *queue2, int data)
{
    enqueueSimpleQueueArray(queue1, data); //enque data to queue1

    if (!isEmptySimpleQueueArray(queue2))
    {
        while (queue2->front != queue2->rear)
        {
            enqueueSimpleQueueArray(queue1, dequeueSimpleQueueArray(queue2)); //copy previous elements of queue2 to queue1
        }
    }

    queue2->front = -1; //mark queue2 as empty
    queue2->rear = -1;

    if (!isEmptySimpleQueueArray(queue1))
    {
        while (queue1->front != queue1->rear)
        {
            enqueueSimpleQueueArray(queue2, dequeueSimpleQueueArray(queue1)); //now copying queue1 with new data to queue2
        }
    }
    queue1->front = -1; //marking queue2 as queue1
    queue1->rear = -1;

}
int main()
{

    simpleQueueArray queue1;
    initSimpleQueueArray(&queue1);

    simpleQueueArray queue2;
    initSimpleQueueArray(&queue2);

    push(&queue1, &queue2, 1);
    push(&queue1, &queue2, 2);
    push(&queue1, &queue2, 3);
    push(&queue1, &queue2, 4);

    displaySimpleQueueArray(&queue2);
    getch();

    return 0;
}