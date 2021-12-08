#include <stdio.h>
#include <stdio.h>
#include "MaxHeapImplementation.h"
int main(int argc, char const *argv[])
{
    
    maxHeapNode maxHeap;
    maxHeap.size = 0;
    insertMaxHeap(&maxHeap,3);
    insertMaxHeap(&maxHeap,4);
    insertMaxHeap(&maxHeap,9);
    insertMaxHeap(&maxHeap,5);
    insertMaxHeap(&maxHeap,2);

    printMaxHeap(&maxHeap);

    printf("\nFirst Deleted Element is = %d\n\n",deleteMaxHeap(&maxHeap));

    printMaxHeap(&maxHeap);

    getch();
    return 0;
}