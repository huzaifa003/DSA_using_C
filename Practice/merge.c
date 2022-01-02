#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void merge(int arr[], int lower, int middle, int high)
{
    int temp[15];
    int j = middle;
    int i = lower;

    int k = 0;

    while (i < middle && j <= high)
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            k++;
            i++;
        }

        else
        {
            temp[k] = arr[j];
            j++;
            k++;
        }
    }

    while (i < middle)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while (j <= high)
    {
        temp[k] = arr[j];
        k++;
        j++;
    }

    for (int i = lower; i <= high; i++)
    {
        arr[i] = temp[i - lower];
    }


}

void mergeSort(int arr[], int low, int high)
{
    if (low >= high)
    {
        return;
    }

    int middle = low + (high - low) / 2;
    mergeSort(arr, low, middle);
    mergeSort(arr, middle + 1, high);
    merge(arr, low, middle + 1, high);
}
int main()
{
    int arr[] = {5, 6, 7, 2, 6, 8, 5, -52};
    mergeSort(arr, 0, 7);
    for (int i = 0; i < 7; i++)
    {
        printf("%d  ", arr[i]);
    }
    getch();
    return 0;
}