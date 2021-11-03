#include <stdio.h>
#include <conio.h>
#include "NodeSinglyLinkedList.h"

int main()
{

    Node* head = NULL;
    head = insertFrontSingly(head,65);
    head = insertBackSingly(head,34);
    displaySingly(head);
    
    head = insertFrontSingly(head , 4);
    head = insertBackSingly(head , 5);
    displaySingly(head);
    printf("Length for first display after inserting at front and back =  %d\n",getLength(head));

    deleteFirstSingly(head);
    displaySingly(head);
    printf("Length after first deletion from start  =  %d\n",getLength(head));

    deleteFirstSingly(head);
    displaySingly(head);
    printf("Length after second deletion from start  =  %d\n",getLength(head));

    head = insertFrontSingly(head , 4);
    head = insertFrontSingly(head , 5);
    displaySingly(head);
    printf("Length for second display after inserting two at front  =  %d\n",getLength(head));

    deleteLastSingly(head);
    displaySingly(head);
    printf("Length after third deletion from last  =  %d\n",getLength(head));

    deleteLastSingly(head);
    displaySingly(head);
    printf("Length after fourth deletion from last  =  %d\n",getLength(head));

    head = insertBackSingly(head,4);
    head = insertBackSingly(head,5);
    head = insertBackSingly(head,6);
    head = insertBackSingly(head,7);
    head = insertBackSingly(head,8);
    displaySingly(head);

    printf("Length for last display after inserting at back (like stack) =  %d\n",getLength(head));
    printf("-------------------------------------\n");
    
    printf("Element Deleted at Index %d is = %d\n",3,deleteAtSingly(head,3));
    displaySingly(head);
    getch();
    return 0;
}