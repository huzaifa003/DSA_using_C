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

        do //here do while is needed as we have to start from pivot and at first iteration pivot will be equal to arr[left] or arr[i] in 1st iteration
        {
            i++;
        } while (arr[i] <= pivot);

         while (arr[j] > pivot) //we are using while here cause we need to swap the last element as well
        {
            j--;
        }

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