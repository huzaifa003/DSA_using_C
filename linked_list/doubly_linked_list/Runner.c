#include <stdio.h>
#include <conio.h>

#include <stdlib.h>
#include "NodeDoublyLinkedList.h"

int main(int argc, char const *argv[])
{
    if (isEmptyDoubly())
    {
        printf("List is empty before insertion\n");
    }
    else
    {
        printf("There has to be some error!!");
    }
    
    
    insertFrontDoubly(4);
    insertFrontDoubly(8);
    insertFrontDoubly(9);
    insertBackDoubly(5);
    insertBackDoubly(10);
    printf("Starting length is = %d",getLenghtDoubly());

    displayFrontwardsDoubly();
    displayBackwardsDoubly();

    insertAt(7,3);
    displayFrontwardsDoubly();
    deleteAt(3);
    deleteLastDoubly();

    displayFrontwardsDoubly();
    displayBackwardsDoubly();

    deleteFirstDoubly();

    displayFrontwardsDoubly();
    displayBackwardsDoubly();
    printf("\nEnding length is = %d",getLenghtDoubly());
    if (!isEmptyDoubly())
    {
        printf("\n\nList is NOT empty before insertion\n");
    }
    else
    {
        printf("There has to be some error!!");
    }
    getch();
    return 0;
}