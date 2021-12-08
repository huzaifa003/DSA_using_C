#include <stdio.h>
#include <stdio.h>
#define MAX_SIZE 20
/*
    *
    * A heap is a like a tree with max heap having the root as largest element
    * There can be same values in a heap
    * Heap's first non leaf node is accessed by formula (size/2 - 1)
    * it's implemented by queue
    * Each element is checked after insertion and deletion to ensure heap's property is ensured.
    * 
*/
typedef struct MinHeapImplementation
{
    int maxHeap[MAX_SIZE];
    int size;
} minHeapNode;

void heapifyMin(minHeapNode *heapNode, int i)
{
    if (heapNode->size == 1)
    {
        printf("Only 1 element so no need to heapifyMin");
        return;
    }
    else
    {
        int smallest = i;       //current element position
        int left = 2 * i + 1;  //current left child
        int right = 2 * i + 2; //current right child
        if (left < heapNode->size && heapNode->maxHeap[left] < heapNode->maxHeap[smallest])
            smallest = left; //checking the smallest element on both sides
        else if (right < heapNode->size && heapNode->maxHeap[right] < heapNode->maxHeap[smallest])
            smallest = right;
        if (smallest != i) //if any child is greater than parent then swap the nodes
        {
            int temp = heapNode->maxHeap[smallest];
            heapNode->maxHeap[smallest] = heapNode->maxHeap[i];
            heapNode->maxHeap[i] = temp;
            heapifyMin(heapNode, smallest); //heapifyMin till root the node aka first element in array
        }
    }
}

void insertMinHeap(minHeapNode *heapNode, int data)
{
    heapNode->maxHeap[heapNode->size] = data;
    heapNode->size++;

    if (heapNode->size > 1)
    {
        for (int i = heapNode->size / 2 - 1; i >= 0; i--) //size/2 -1 returns the first non leaf node address
        {
            heapifyMin(heapNode, i);
        }
    }
}

int deleteMinHeap(minHeapNode *heapNode)
{
    int temp = heapNode->maxHeap[0];
    heapNode->maxHeap[0] = heapNode->maxHeap[heapNode->size - 1];
    heapNode->maxHeap[heapNode->size - 1] = temp;

    heapNode->size--;
    for (int i = heapNode->size / 2 - 1; i >= 0; i--) //size/2 -1 returns the first non leaf node address
    {
        heapifyMin(heapNode, i);
    }
    return temp;
}

void printMinHeap(minHeapNode *heapNode)
{
    for (int i = 0; i < heapNode->size; i++)
    {
        printf("Element %d of MinHeap is = %d\n",i,heapNode->maxHeap[i]);
    }
    
}

