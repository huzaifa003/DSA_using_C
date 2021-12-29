#include <stdio.h>
#include <conio.h>
#define SIZE 10
#include <stdlib.h>

void heapifyMax(int arr[], int i)
{
    int largest = i;
    int leftChild = 2 * i +1;
    int rightChild = 2 * i +2;

    if (leftChild < SIZE && arr[leftChild] > arr[largest])
    {
        largest = leftChild;
    }

    if (rightChild < SIZE && arr[rightChild] > arr[largest])
    {
        largest = rightChild;
    }

    if (arr[largest] != arr[i])
    {
        int temp = arr[largest];
        arr[largest] = arr[i];
        arr[i] = temp;
        heapifyMax(arr,largest);
    }
}

int deleteHeapifyMax(int arr[])
{
    for (int i = SIZE/2 - 1; i >= 0; i--)
    {
        heapifyMax(arr,i);
    }

    int temp = arr[0];
    arr[0] = arr[SIZE -1 ];
    for (int i = SIZE/2 - 1; i >= 0; i--)
    {
        heapifyMax(arr,i);
    }

    return temp;
}
int main()
{
    int arr[] = {8,5,3,4,6,9,7,5,3,2};
    for (int i = SIZE/2 - 1; i >= 0; i--)
    {
        heapifyMax(arr,i);
    }
    for (int i = 0; i < SIZE; i++)
    {
        printf("\n%d ", arr[i]);
    }
    printf("%d ",deleteHeapifyMax(arr));
    printf("%d ",deleteHeapifyMax(arr));
    printf("%d ",deleteHeapifyMax(arr));
    printf("%d ",deleteHeapifyMax(arr));
    printf("%d ",deleteHeapifyMax(arr));
    printf("%d ",deleteHeapifyMax(arr));
    printf("%d ",deleteHeapifyMax(arr));
    getch();
    
    return 0;
}