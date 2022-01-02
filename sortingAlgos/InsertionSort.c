#include "ArrayMaking.h"

int *insertionSort(int arr[])
{
    for (int i = 0, j = 1; j < SIZE - 1; i++,j++)
    {
        if (arr[j] < arr[i])
        {
            int temp;
            for (int k = j; k > 0 && arr[k] < arr[k-1]; k--)
            {
                temp = arr[k];
                arr[k] = arr[k-1];
                arr[k-1] = temp;
            }
            
        }
    }

    return arr;
    
}

int main(int argc, char const *argv[])
{
    createArray();
    printArray();
    insertionSort(arr);
    printArray();

    getch();
    return 0;
}
