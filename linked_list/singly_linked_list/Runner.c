#include <stdio.h>
#include <conio.h>
#include "NodeSinglyLinkedList.h"

int main()
{

    insertFrontSingly(4);
    insertBackSingly(5);
    displaySingly();
    printf("Length for first display  =  %d\n",getLength());

    deleteFirstSingly();
    displaySingly();
    printf("Length after first deletion  =  %d\n",getLength());

    deleteFirstSingly();
    displaySingly();
    printf("Length after second deletion  =  %d\n",getLength());

    insertFrontSingly(4);
    insertFrontSingly(5);
    displaySingly();
    printf("Length for second display  =  %d\n",getLength());

    deleteLastSingly();
    displaySingly();
    printf("Length after third deletion  =  %d\n",getLength());

    deleteLastSingly();
    displaySingly();
    printf("Length after fourth deletion  =  %d\n",getLength());

    insertBackSingly(4);
    insertBackSingly(5);
    insertBackSingly(6);
    insertBackSingly(7);
    insertBackSingly(8);
    displaySingly();
    printf("Length for last display  =  %d\n",getLength());
    printf("-------------------------------------\n");
    printf("Element Deleted at Index %d is = %d\n",3,deleteAtSingly(3));
    displaySingly();
    getch();
    return 0;
}