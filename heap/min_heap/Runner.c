#include <stdio.h>
#include <stdio.h>
#include "MinHeapImplementation.h"
int main(int argc, char const *argv[])
{
    
    minHeapNode minHeap;
    minHeap.size = 0;
    insertMinHeap(&minHeap,3);
    insertMinHeap(&minHeap,4);
    insertMinHeap(&minHeap,9);
    insertMinHeap(&minHeap,5);
    insertMinHeap(&minHeap,2);

    printMinHeap(&minHeap);

    printf("\nFirst Deleted Element is = %d\n\n",deleteMinHeap(&minHeap));

    printMinHeap(&minHeap);

    printf("\n\nSorted Heap is :\n\n");
    sortMinHeap(&minHeap);
    printMinHeap(&minHeap);


    getch();
    return 0;
}