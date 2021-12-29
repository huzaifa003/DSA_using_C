#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int SIZE = 10;
void heapifyMin(int arr[], int i, int size)
{
    int smallest = i;
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;

    if (leftChild < size && arr[leftChild] < arr[smallest])
    {
        smallest = leftChild;
    }

    if (rightChild < size && arr[rightChild] < arr[smallest])
    {
        smallest = rightChild;
    }

    if (arr[smallest] != arr[i])
    {
        int temp = arr[smallest];
        arr[smallest] = arr[i];
        arr[i] = temp;
        heapifyMin(arr, smallest, size);
    }
}

int deleteHeapifyMin(int arr[])
{
    for (int i = SIZE / 2 - 1; i >= 0; i--)
    {
        heapifyMin(arr, i, SIZE);
    }
    int temp = arr[0];
    arr[0] = arr[SIZE - 1];
    SIZE--;
    for (int i = SIZE / 2 - 1; i >= 0; i--)
    {
        heapifyMin(arr, i, SIZE);
    }

    return temp;
}

void sortMinHeap(int arr[])
{
    int temp;
    for (int i = SIZE - 1; i >= 0; i--)
    {
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapifyMin(arr, 0, i);
    }
}

void deleteElement(int arr[], int element)
{   int index = 0;
    for (index = 0; index < SIZE; index++)
    {
    //this will provide index
        if (element == arr[index]) 
        {
            break;
        }
    }
    
    for (index; index < SIZE - 1; index++)
    {
        arr[index] = arr[index+1];
    }
    SIZE--;

    if (SIZE > 1)
    {
        for (int i = SIZE / 2 - 1;i >= 0; i--)
        {
            heapifyMin(arr,i,SIZE);
        }
        
    }
}
int main()
{
    int arr[] = {8, 5, 3, 4, 6, 9, 7, 5, 3, 2};
    for (int i = SIZE / 2 - 1; i >= 0; i--)
    {
        heapifyMin(arr, i, SIZE);
    }

    for (int i = 0; i < SIZE; i++)
    {
        printf("\n%d ", arr[i]);
    }

    sortMinHeap(arr);   
    printf("\n\n");
    for (int i = 0; i < SIZE; i++)
    {
        printf("\n%d ", arr[i]);
    }

    for (int i = SIZE / 2 - 1; i >= 0; i--)
    {
        heapifyMin(arr, i, SIZE);
    }
    printf("\nDEL\n");

    for (int i = 0; i < SIZE; i++)
    {
        printf("\n%d ", arr[i]);
    }
    printf("\nDEL\n");

    deleteElement(arr,3);
    for (int i = 0; i < SIZE; i++)
    {
        printf("\n%d ", arr[i]);
    }
    printf("\nDEL\n");

    getch();

    printf("%d ", deleteHeapifyMin(arr));
    printf("%d ", deleteHeapifyMin(arr));
    printf("%d ", deleteHeapifyMin(arr));
    printf("%d ", deleteHeapifyMin(arr));
    printf("%d ", deleteHeapifyMin(arr));
    printf("%d ", deleteHeapifyMin(arr));
    printf("%d ", deleteHeapifyMin(arr));
    getch();

    return 0;
}