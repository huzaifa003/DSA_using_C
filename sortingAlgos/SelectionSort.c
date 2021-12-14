#include "ArrayMaking.h"
int *selectionSort(int arr[])
{
    /*
        * Selection Sort Works by replacing the ith index value with the samllest value at every iteration
    */
    int min;
    int minIndex;
    for (int i = 0; i < SIZE - 1; i++)
    {
        min = arr[i];
        minIndex = i;

        for (int j = i + 1; j < SIZE; j++)
        {
            if (arr[j] < min)
            {
                min = arr[j];
                minIndex = j;
            }
        }
        if (min != arr[i])
        {
            arr[minIndex] = arr[i];
            arr[i] = min;
        }
    }
    return arr;
}
int main()
{
    createArray();
    printArray();
    selectionSort(arr);
    printArray();
    getch();
    return 0;
}