#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "NodeCircularLinkedList.h"
int main(int argc, char const *argv[])
{
    insertCircular(4);
    insertCircular(5);
    displayCircular();
    printf("Length for first display  =  %d\n",getLength());
    
    deleteFirstCircular();
    displayCircular();
    printf("Length after first deletion  =  %d\n",getLength());
    
    deleteFirstCircular();
    displayCircular();
    printf("Length after second deletion  =  %d\n",getLength());
    
    insertCircular(4);
    insertCircular(5);

    displayCircular();
    printf("Length for second display  =  %d\n",getLength());

    deleteLastCircular();
    displayCircular();
    printf("Length after third deletion  =  %d\n",getLength());
    

    deleteLastCircular();
    displayCircular();
    printf("Length after fourth deletion  =  %d\n",getLength());

    insertCircular(4);
    insertCircular(5);
    displayCircular();
    printf("Length for last display  =  %d\n",getLength());
    getch();
    return 0;
}

