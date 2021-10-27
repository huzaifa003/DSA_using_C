#include <stdio.h>
#include <conio.h>
#include "SinglyLinkedList.h"

int main()
{

    insertFront(4);
    insertBack(5);
    display();
    printf("Length for first display  =  %d\n",getLength());

    deleteFirst();
    display();
    printf("Length after first deletion  =  %d\n",getLength());

    deleteFirst();
    display();
    printf("Length after second deletion  =  %d\n",getLength());

    insertFront(4);
    insertFront(5);
    display();
    printf("Length for second display  =  %d\n",getLength());

    deleteLast();
    display();
    printf("Length after third deletion  =  %d\n",getLength());

    deleteLast();
    display();
    printf("Length after fourth deletion  =  %d\n",getLength());

    insertBack(4);
    insertBack(5);
    insertBack(6);
    insertBack(7);
    insertBack(8);
    display();
    printf("Length for last display  =  %d\n",getLength());
    printf("-------------------------------------\n");
    printf("Element Deleted at Index %d is = %d\n",3,deleteAt(3));
    display();
    getch();
    return 0;
}