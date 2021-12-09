#include <stdio.h>
#include <stdio.h>
#include "MaxHeapImplementation.h"
int main(int argc, char const *argv[])
{
    
    maxHeapNode maxHeap;
    maxHeap.size = 0;
    
    int choice;
    int data;
    do
    {
        printf("1 - Insert\n");
        printf("2 - Delete\n");
        printf("3 - Print Heap\n");
        printf("4 - Sort\n");
        printf("8 - Exit\n");
        printf("Enter your selection: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("Enter value: ");
            scanf("%d", &data);
            insertMaxHeap(&maxHeap, data);
        }
        else if (choice == 2)
        {
            printf("\nDeleted Element is = %d\n\n",deleteMaxHeap(&maxHeap));
        }
        else if (choice == 3)
        {
            printMaxHeap(&maxHeap);
        }
        else if (choice == 4)
            sortMaxHeap(&maxHeap);
        else if (choice == 8)
            printf("Program exited\n");
        else
            printf("Wrong input\n");
        printf("\n");
    } while (choice != 8);
    
    getch();
    return 0;
}