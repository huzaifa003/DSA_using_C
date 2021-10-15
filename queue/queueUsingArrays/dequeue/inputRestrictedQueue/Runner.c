#include <stdio.h>
#include <conio.h>
#include "InputRestrictedQueueUsingArray.h"
#include <stdlib.h>
int main() {

    InputRestrictedDequeUsingArray queue;
    initInputRestrictedDequeUsingArray(&queue);
    insertRearInputRestrictedDequeUsingArray(&queue, 1);
    insertRearInputRestrictedDequeUsingArray(&queue, 2);
    insertRearInputRestrictedDequeUsingArray(&queue, 3);
    displayInputRestrictedDequeUsingArray(&queue);
    printf("Deleted from front is = %d\n",deleteFrontInputRestrictedDequeUsingArray(&queue));
    printf("Deleted from Back is = %d\n",deleteRearInputRestrictedDequeUsingArray(&queue));
    printf("Deleted last element is = %d\n",deleteRearInputRestrictedDequeUsingArray(&queue));

    displayInputRestrictedDequeUsingArray(&queue);

    getch();
    return 0;
}