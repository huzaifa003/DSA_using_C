#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "NodeQueue.h"
int main()
{

    enqueue(4);
    printf("\nElement after dequeue is = %d\n", dequeue());
    enqueue(5);
    enqueue(6);
    enqueue(7);
    enqueue(8);
    printf("\nElement after dequeue is = %d\n", dequeue());

    displayQueue();

    printf("\nElement after dequeue is = %d\n", dequeue());
    
    printf("LENGTH AFTER 3RD DEQUEUE IS = %d", getLengthQueue());

    printf("\nElement after dequeue is = %d\n", dequeue());
    printf("\nElement after dequeue is = %d\n", dequeue()); //last element being dequeued

    printf("\nElement after dequeue is = %d\n", dequeue()); //will return 0 cause all elements are done for
    printf("\nElement after dequeue is = %d\n", dequeue()); //similarly this will display 0

    printf("\nReinserting Elements\n");
    enqueue(5);
    enqueue(6);
    enqueue(7);
    enqueue(8);
    printf("LENGTH AFTER 2nd INSERTION IS = %d", getLengthQueue());
    displayQueue();
    
    freeQueue();
    displayQueue();
    printf("LENGTH AFTER Freeing QUEUE IS = %d", getLengthQueue());
    
    //inserting again;
    printf("\n\n\n\nFilling Queue Again\n\n");
    enqueue(5);
    enqueue(6);
    enqueue(7);
    enqueue(8);
    displayQueue();

    //popping Node
    NodeQueue* dequeuedNode = dequeueNode();
    printf("\nAddress of popped Node is = %d\n",dequeuedNode);
    printf("\nValue of Popped Node is = %d\n",dequeuedNode->data);
    free(dequeuedNode);
    dequeuedNode = NULL; //freeing memory later on
    getch();
    return 0;
}