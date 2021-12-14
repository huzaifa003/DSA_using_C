#include "ArrayMaking.h"

void merge(int arr[], int left, int middle, int right)
{
    int size = right - left;
    int temp[size];
    int k = 0;
    int i, j;
    for (i = left, j = middle; i < middle && j <= right;) 
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i < middle)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while (j <= right)
    {

        temp[k] = arr[j];
        j++;
        k++;
    }

    for (i = 0; i <= size; i++)
    {
        arr[left+i] = temp[i]; //using left index as start to make sure og array isn't affected
    }
}

void mergeSort(int arr[], int left, int right)
{
    if (left >= right)
        return;
    else
    {
        int middle = (left + right) / 2;
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);
        merge(arr, left, middle + 1, right);
    }
}

int main()
{

    createArray();
    printArray();
    mergeSort(arr,0,SIZE-1);
    printArray();
    getch();
    return 0;
}