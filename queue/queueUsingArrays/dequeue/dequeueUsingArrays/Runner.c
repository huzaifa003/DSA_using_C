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
    
    getch();

    

    return 0;
}