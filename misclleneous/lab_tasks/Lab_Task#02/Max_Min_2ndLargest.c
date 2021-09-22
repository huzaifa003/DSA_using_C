#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void find2ndLargest(int arr[], int size)
{
    int largest, secondLargest;
 
    /* There should be atleast two elements */
    if (size < 2) {
        printf(" Invalid Input ");
        return;
    }
 
    largest = secondLargest = arr[0];
    for (int i = 0; i < size; i++) {

        if (arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        }

        else if (arr[i] > secondLargest && arr[i] != largest)
            secondLargest = arr[i];
    }
    printf("Largest is = %d\n",largest);
    if (secondLargest == arr[0])
        printf("There is no second largest element\n");
    else
        printf("The second largest element is %d\n", secondLargest);
}
 
/* Driver program to test above function */
int main()
{
    int arr[] = { 12, 35, 1, 10, 34, 1 };
    find2ndLargest(arr, 6);
    getch();
    return 0;
}