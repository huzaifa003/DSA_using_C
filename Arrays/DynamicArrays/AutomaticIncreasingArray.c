#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
//TODO ADD Deletion and Searching Methods!!!
static int count = 1;
int insert(int arr[], int size)
{
    count++; //size of array will always be 1 greater than count
    if (count >= size)
    {
        printf("HELLO");
        size = size + 5; //increasing size
        arr = realloc(arr, size);
    }
    printf("Enter the value to be inserted: ");
    int value;
    scanf("%d", &value);

    int pos;
    printf("Enter the Position starting from %d:  ", count - 2);
    scanf("%d", &pos);

    for (int i = size - 1; i > pos; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    return size;
}

void display(int arr[], int size)
{
    for (int i = 0; i < count - 1; i++)
    {
        printf("Element of arr[%d] =  %d\n", i, arr[i]);
    }
}
int main()
{

    int *arr = (int *)calloc(2, sizeof(int));
    int size = 2;
    int choice;
    while (1)
    {
        printf("Press 1 to Enter value in Array\nPress 2 to Display Values in Array\n");
        scanf("%d", &choice);

        if (choice == 1)
        {
            size = insert(arr, size);
        }

        else if (choice == 2)
        {
            display(arr, size);
        }
        else if (choice == 5)
        {
            return 1;
        }
    }

    return 0;
}