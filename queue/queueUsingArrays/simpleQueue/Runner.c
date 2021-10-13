#include <stdio.h>
#include <conio.h>
#include "simpleQueueArray.h"
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    simpleQueueArray queue;
    initSimpleQueueArray(&queue);
    dequeueSimpleQueueArray(&queue); //queue is empty :)

    enqueueSimpleQueueArray(&queue,1);
    enqueueSimpleQueueArray(&queue,2);
    enqueueSimpleQueueArray(&queue,3);
    
    displaySimpleQueueArray(&queue);

    printf("First Dequeued Element is =  %d\n",dequeueSimpleQueueArray(&queue));
    printf("Second Dequeued Element is =  %d\n",dequeueSimpleQueueArray(&queue));
    displaySimpleQueueArray(&queue);
    getch();
    return 0;
}