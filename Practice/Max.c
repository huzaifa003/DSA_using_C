#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int size = 0;
void heapifyMax(int arr[], int i, int SIZE)
{
    int largest = i;
    int leftNode = 2 * i + 1;
    int rightNode = 2 * i + 2;

    if (leftNode < SIZE && arr[leftNode] > arr[largest])
    {
        largest = leftNode;
    }

    if (rightNode < SIZE && arr[rightNode] > arr[largest])
    {
        largest = rightNode;
    }

    if (largest != i)
    {
        int temp = arr[largest];
        arr[largest] = arr[i];
        arr[i] = temp;
        heapifyMax(arr, i, largest);
    }
}

void insertHeap(int arr[], int data)
{
    if (size >= 15)
    {
        printf("Cant be added");
        return;
    }
    arr[size] = data;
    size++;

    if (size > 1)
    {
        for (int i = size / 2 - 1; i >= 0; i--)
        {
            heapifyMax(arr, i, size);
        }
    }
}

int deleteHeap(int arr[])
{
    if (size < 0)
    {
        printf("Empty heap");
        return -1;
    }
    size--;
    int temp = arr[0];
    arr[0] = arr[size];
    if (size > 1)
    {
        for (int i = size / 2 - 1; i >= 0; i--)
        {
            heapifyMax(arr, i, size);
        }
    }
    return temp;
}

void displayHeap(int arr[])
{
    for (int i = 0; i < size; i++)
    {
        printf("%d   ",arr[i]);
    }
    
}
int main()
{

    int arr[15];
    insertHeap(arr, 1);
    insertHeap(arr, 2);
    insertHeap(arr, 5);
    insertHeap(arr, 6);
    insertHeap(arr, 3);
    insertHeap(arr, 15);
    insertHeap(arr, 89);
    displayHeap(arr);
    printf("\n%d is =  \n",deleteHeap(arr));
    displayHeap(arr);

    getch();
    return 0;
}