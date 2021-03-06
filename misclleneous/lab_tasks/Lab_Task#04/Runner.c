#include <stdio.h>
#include <conio.h>
#include "SinglyLinkedList.h"

int main()
{

    insertFront(1);
    insertBack(2);
    display();
    printf("Length for first display  =  %d\n",getLength());

    insertFront(4);
    insertFront(5);

    printf("\nLast element deleted\n");
    deleteLast();

    display();


    insertBack(10);
    insertBack(20);

    insertFront(30);
    insertFront(40);
    insertFront(50);

    display();
    printf("Length for last display  =  %d\n",getLength());

    printf("\nElement Deleted at Index %d\n",1,deleteAt(1));
    display();
    printf("Length after deletion  =  %d\n",getLength());

    printf("\nElement inserted at index 1\n");
    insertAt(1,99);
    display();
    getch();
    return 0;
}