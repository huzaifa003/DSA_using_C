#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "NodeDoublyLinkedList.h"

int main(int argc, char const *argv[])
{

    insertFrontDoubly(1);
    insertFrontDoubly(3);
    insertFrontDoubly(4);
    insertBackDoubly(3);
    insertBackDoubly(3);
    insertFrontDoubly(3);
    displayFrontwardsDoubly();


    printf("\nRemoved Duplicates\n");
    removeDuplicates();
    displayFrontwardsDoubly();
    getch();
    return 0;
}