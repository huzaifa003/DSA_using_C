#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int partition(int arr[], int lower, int high)
{
    int i = lower;
    int j = high;
    int pivot = arr[lower];

    while (i < j)
    {
        do
        {
            i++;
        } while (arr[i] < pivot);

        while (arr[j] > pivot)
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
    int temp = arr[j];
    arr[j] = arr[lower];
    arr[lower] = temp;
    return j;
}

void quickSort(int arr[], int lower, int higher)
{
    if ( lower >= higher)
        return;
    int j = partition(arr,lower,higher);
    quickSort(arr,lower,j - 1);
    quickSort(arr,j + 1,higher);
}
int main()
{
    int arr[] = {8, 5, 3, 4, 6, 9, 7, 5, 3, 2};
    quickSort(arr,0,9);
    for (int i = 0; i < 9; i++)
    {
        printf("%d   ",arr[i]);
    }
    getch();
    
    
    return 0;
}