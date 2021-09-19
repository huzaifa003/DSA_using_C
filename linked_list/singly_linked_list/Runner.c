#include <stdio.h>
#include <conio.h>
#include "Node.h"

int main()
{

    insertSingly(4);
    insertSingly(5);
    displaySingly();
    printf("Length for first display  =  %d\n",getLength());

    deleteFirstSingly();
    displaySingly();
    printf("Length after first deletion  =  %d\n",getLength());

    deleteFirstSingly();
    displaySingly();
    printf("Length after second deletion  =  %d\n",getLength());

    insertSingly(4);
    insertSingly(5);
    displaySingly();
    printf("Length for second display  =  %d\n",getLength());

    deleteLastSingly();
    displaySingly();
    printf("Length after third deletion  =  %d\n",getLength());

    deleteLastSingly();
    displaySingly();
    printf("Length after fourth deletion  =  %d\n",getLength());

    insertSingly(4);
    insertSingly(5);
    displaySingly();
    printf("Length for last display  =  %d\n",getLength());
    getch();
    return 0;
}