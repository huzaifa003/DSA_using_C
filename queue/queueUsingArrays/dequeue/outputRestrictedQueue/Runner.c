#include <stdio.h>
#include <conio.h>
#include "OutputRestrictedQueueUsingArray.h"
#include <stdlib.h>
int main() {

    OutputRestrictedDequeUsingArray queue;
    initOutputRestrictedDequeUsingArray(&queue);

    insertRearOutputRestrictedDequeUsingArray(&queue,1);
    insertFrontOutputRestrictedDequeUsingArray(&queue,2);
    
    displayOutputRestrictedDequeUsingArray(&queue);
    printf("Deleted Element is = %d\n",deleteFrontOutputRestrictedDequeUsingArray(&queue));

    getch();

    return 0;
}