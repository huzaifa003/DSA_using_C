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
    int pivot = arr[left];
    int i = left;
    int j = right;

    while (i < j)
    {

        do
        {
            i++;
        } while (arr[i] <= pivot);

        do
        {
            j--;
        } while (arr[j] > pivot);

        if (i < j)
        {
            swap(arr, i, j); //swap to make all the members less than on left side and all memebers greater on the right
        }
    }

    swap(arr, left, j); //swap pivot with the jth index value to place pivot at correct position
    return j; //this will make return the index where j is shifted
}

void quickSort(int arr[], int left, int right)
{

    if (left >= right)
    {
        return;
    }

    int j = partition(arr, left, right);
    quickSort(arr, left, j);
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