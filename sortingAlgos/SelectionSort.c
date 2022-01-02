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
    
        int j;
        int k;
        for (j = i + 1; j < SIZE; j++)
        {
            if (arr[j] < min)
            {
                min = arr[j];
                k = j;
            }
        }
        if (min != arr[i])
        {
            int temp = arr[i];
            arr[i] = min;
            arr[k] = temp;
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