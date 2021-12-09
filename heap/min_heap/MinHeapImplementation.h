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
    int minHeap[MAX_SIZE];
    int size;
} minHeapNode;

void heapifyMin(minHeapNode *heapNode, int i)
{

    int smallest = i;      //current element position
    int left = 2 * i + 1;  //current left child
    int right = 2 * i + 2; //current right child
    if (left < heapNode->size && heapNode->minHeap[left] < heapNode->minHeap[smallest])
        smallest = left; //checking the smallest element on both sides
    if (right < heapNode->size && heapNode->minHeap[right] < heapNode->minHeap[smallest])
        smallest = right;
    if (smallest != i) //if any child is greater than parent then swap the nodes
    {
        int temp = heapNode->minHeap[smallest];
        heapNode->minHeap[smallest] = heapNode->minHeap[i];
        heapNode->minHeap[i] = temp;
        heapifyMin(heapNode, smallest); //heapifyMin till root the node aka first element in array
    }
}

void insertMinHeap(minHeapNode *heapNode, int data)
{
    heapNode->minHeap[heapNode->size] = data;
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
    int temp = heapNode->minHeap[0];
    heapNode->minHeap[0] = heapNode->minHeap[heapNode->size - 1];
    heapNode->minHeap[heapNode->size - 1] = temp;

    heapNode->size--;
    for (int i = heapNode->size / 2 - 1; i >= 0; i--) //size/2 -1 returns the first non leaf node address
    {
        heapifyMin(heapNode, i);
    }
    return temp;
}

void sortMinHeap(minHeapNode *heapNode)
{
    /*
        *
        *To Sort Max heap in ascending order we first form the heap.
        * Then we exchange the root and the last element aka leaf node
        * We reduce size (Not Literally, we just don't heap the swapped element at the last as it's sorted now)
        * Then we heapify the root node
        * Finally we repeat the process till all the elements are sorted
        *
    */

    for (int i = heapNode->size / 2 - 1; i >= 0; i--)
    {
        heapifyMin(heapNode, i); //making sure heap is properly created
    }

    int tempSize = heapNode->size;
    for (int i = heapNode->size - 1; i >= 0; i--)
    {
        int temp = heapNode->minHeap[i]; //swapping root and last leaf node
        heapNode->minHeap[i] = heapNode->minHeap[0];
        heapNode->minHeap[0] = temp;

        heapNode->size = i; //temporarily reducing size
        heapifyMin(heapNode, 0);
    }

    heapNode->size = tempSize; //again repleneshing the size
}

void printMinHeap(minHeapNode *heapNode)
{
    for (int i = 0; i < heapNode->size; i++)
    {
        printf("Element %d of MinHeap is = %d\n", i, heapNode->minHeap[i]);
    }
}
