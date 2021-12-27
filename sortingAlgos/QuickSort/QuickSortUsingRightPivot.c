#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "ArrayMaking.h"

void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int arr[], int left, int right)
{
    //this will split array into two parts where one half will have values less than pivot and other half will have values greater than it.
    int pivot = arr[right];
    int i = left;
    int j = right - 1;

    while (i < j)
    {
        while (arr[i] < pivot)
        {
            i++;
        }

        while (arr[j] >= pivot)
        {
            j--;
        }

        if (i < j)
        {
            swap(arr,i,j);
        }
    }
    

    swap(arr, right, i); //swap pivot with the ith index value to place pivot at correct position
    return i; //this will make return the index where i is shifted
}

void quickSort(int arr[], int left, int right)
{

    if (left >= right)
    {
        return;
    }

    int j = partition(arr, left, right);
    quickSort(arr, left, j - 1);
    quickSort(arr, j + 1, right);
}
int main()
{   
    createArray();
    printArray();
    quickSort(arr, 0, SIZE - 1);
    printArray();
    getch();
    return 0;
}