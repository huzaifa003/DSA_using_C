#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "NodeSinglyLinkedList.h"
int main(int argc, char const *argv[])
{

    while (1)
    {
        int choice;
        int data;
        int index;
        printf("\nCOOSE FROM THE FOLLOWING CHOICES \n----------------------------------------------------\n");
        printf("1.Insert at end");
        printf("\n2.Insert at start");
        printf("\n3.Insert at any index");
        printf("\n4.Delete at start");
        printf("\n5.Delete at end");
        printf("\n6.Delete at any index");
        printf("\n7.Display");
        printf("\nPRESS -1 TO EXIT\n-----------------------------------------------\n");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("Enter the value of your choice ");
            scanf("%d", &data);
            insertFrontSingly(data);
            displaySingly();
        }
        else if (choice == 2)
        {
            printf("Enter the value of your choice ");
            scanf("%d", &data);
            insertBackSingly(data);
            displaySingly();
        }

        else if (choice == 3)
        {

            printf("Enter the value of your choice");
            scanf("%d", &data);
            printf("Enter indexition you want to enter the value");
            scanf("%d", &index);
            insertAtSingly(data,index);
            displaySingly();
        }

        else if (choice == 4)
        {

            int vals = deleteFirstSingly();

            printf("The value %d from the start is deleted", vals);
        }
        else if (choice == 5)
        {

            int vals = deleteLastSingly();
            printf("The value %d  at the end is deleted", vals);
        }

       else  if (choice == 6)
        {

            int ind;

            printf("Enter the index where you want to delete");
            scanf("%d", &ind);
            int vals = deleteAtSingly(ind);
            printf("The value %d  at the %d is deleted", vals,ind);
        }

        else if (choice == 7)
        {
            displaySingly();
        }
        
        else if (choice == -1)
        {
            break;
        }


    }
    getch();
    return 0;
}
