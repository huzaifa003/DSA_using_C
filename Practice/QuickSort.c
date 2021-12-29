#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define SIZE 10
int partitionDescending(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j)
    {
        do
        {
            i++;
        } while (arr[i] > arr[low]);

        while (arr[j] < arr[low])
        {
            j--;
        }

        if (i < j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j;
}

void quickSortDescending(int arr[], int low, int high)
{
    if (low >= high)
    {
        return;
    }
    int j = partitionDescending(arr, low, high);
    quickSortDescending(arr, low, j - 1);
    quickSortDescending(arr, j + 1, high);
}

int partitionAscending(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j)
    {
        do
        {
            i++;
        } while (arr[i] < arr[low]);

        while (arr[j] > arr[low])
        {
            j--;
        }

        if (i < j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j;
}

void quickSortAscending(int arr[], int low, int high)
{
    if (low >= high)
    {
        return;
    }
    int j = partitionAscending(arr, low, high);
    quickSortAscending(arr, low, j - 1);
    quickSortAscending(arr, j + 1, high);
}
int main()
{
    int arr[] = {8, 5, 3, 4, 6, 9, 7, 5, 3, 2};
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", arr[i]);
    }
    quickSortAscending(arr, 0, SIZE - 1);
    for (int i = 0; i < SIZE; i++)
    {
        printf("\n%d ", arr[i]);
    }
    printf("\n----------------------------------------\n");
    quickSortDescending(arr, 0, SIZE - 1);

    for (int i = 0; i < SIZE; i++)
    {
        printf("\n%d ", arr[i]);
    }

    getch();
    return 0;
}