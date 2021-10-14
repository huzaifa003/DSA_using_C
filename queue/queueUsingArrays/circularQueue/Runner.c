#include <stdio.h>
#include <conio.h>
#include "circularQueueArray.h"
#include <stdlib.h>
int main() {

    circularQueueArray circularQueue;
    initcircularQueueArray(&circularQueue);
    dequeuecircularQueueArray(&circularQueue); //queue is empty :)

    enqueuecircularQueueArray(&circularQueue,1);
    enqueuecircularQueueArray(&circularQueue,2);
    enqueuecircularQueueArray(&circularQueue,3);
    enqueuecircularQueueArray(&circularQueue,3);
    enqueuecircularQueueArray(&circularQueue,3);
    enqueuecircularQueueArray(&circularQueue,3);
    enqueuecircularQueueArray(&circularQueue,3);
    enqueuecircularQueueArray(&circularQueue,3);
    enqueuecircularQueueArray(&circularQueue,3);
    enqueuecircularQueueArray(&circularQueue,3);
    enqueuecircularQueueArray(&circularQueue,3);
    enqueuecircularQueueArray(&circularQueue,3);
    enqueuecircularQueueArray(&circularQueue,10);
    
    displaycircularQueueArray(&circularQueue);

    printf("First Dequeued Element is =  %d\n",dequeuecircularQueueArray(&circularQueue));
    printf("Second Dequeued Element is =  %d\n",dequeuecircularQueueArray(&circularQueue));
    displaycircularQueueArray(&circularQueue);
    enqueuecircularQueueArray(&circularQueue,20);
    enqueuecircularQueueArray(&circularQueue,20); 
    enqueuecircularQueueArray(&circularQueue,20); 
    
    displaycircularQueueArray(&circularQueue); 
    getch();
    return 0;
}