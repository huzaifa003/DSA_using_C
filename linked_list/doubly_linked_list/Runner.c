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
    
    
    insertFrontDoubly(1);
    insertFrontDoubly(3);
    insertFrontDoubly(3);
    insertBackDoubly(3);
    insertBackDoubly(10);
    printf("Starting length is = %d",getLenghtDoubly());

    displayFrontwardsDoubly();
    displayBackwardsDoubly();

    insertAt(3,2);
    displayFrontwardsDoubly();
    deleteAt(2);
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

    printf("\nRemoved Duplicates\n");
    removeDuplicates();
    displayFrontwardsDoubly();
    getch();
    return 0;
}