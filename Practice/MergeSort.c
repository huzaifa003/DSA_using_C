#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define SIZE 10
void merge(int arr[], int low, int middle, int high)
{
    int i = low;
    int j = middle;
    int temp[SIZE];
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
        k++;
        i++;
    }

    while (j <= high)
    {
        temp[k] = arr[j];
        k++;
        j++;
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

void mergeSort(int arr[], int low, int high)
{
    if (low >= high)
        return;
    int mid = low + (high - low)/2;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid + 1,high);
    merge(arr,low,mid+1,high);
}
int main()
{
    int arr[] = {8,5,3,4,6,9,7,5,3,2};
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ",arr[i]);
    }
    mergeSort(arr,0,SIZE -1 );
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ",arr[i]);
    }
    
    getch();

    return 0;
}