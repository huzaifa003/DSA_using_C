#include <stdio.h>
#include <conio.h>
#include "DequeUsingArray.h"
#include <stdlib.h>
int main() {

    DequeUsingArray DequeArray;
    initDequeUsingArray(&DequeArray);
    insertRearDequeUsingArray(&DequeArray,2);
    insertFrontDequeUsingArray(&DequeArray,1);

    displayDequeUsingArray(&DequeArray);

    printf("Deleted 1 element from front is = %d\n",deleteFrontDequeUsingArray(&DequeArray));
    printf("Deleted 1 element from Rear is = %d\n",deleteRearDequeUsingArray(&DequeArray));
    displayDequeUsingArray(&DequeArray);     //TODO algo for empty isn't working directly
    getch();

    return 0;
}