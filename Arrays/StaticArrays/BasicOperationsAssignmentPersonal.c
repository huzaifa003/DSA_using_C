/* perform following operations on array */
/*  1. Insertion
•	2. Deletion By Index
•	3. Deletion By value
•	4. Searching By Index
•	5. Searching By Value
•	6. Traversing
*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 30
int insert(int[], int);
void searchByVal(int[], int);
int delByVal(int[], int);
int delByIndex(int[], int);
void searchByIndex(int[], int);
void display(int[], int);

void main()
{
    int c = 0, s, choice; // Variable Declarations
    int arr[SIZE];
    //Array Sizing and Initializing
    printf("Enter How many Elements You want in Array: ");
    scanf("%d", &s);
    for (c = 0; c < s; c++)
    {
        printf("Enter Value for Element %d: ", c);
        scanf("%d", &arr[c]);
    }
    system("cls");

    //printf("\n Enter 1 to Insert at Index\n Enter 2 to Delete by Index\n Enter 3 to search by Value\n Enter 4 to Delete by Value\n Enter 5 to search Value by Index\n Enter 6 to display Array\n Enter 0 to exit\n\tChoice=");
    //scanf("%d",&choice);

    system("cls");
    do
    {

        printf("\n\n\n\n\n\n\t\t\t\t Enter 1 to Insert at Index\n\t\t\t\t Enter 2 to Delete by Index\n\t\t\t\t Enter 3 to search by Value\n\t\t\t\t Enter 4 to Delete by Value\n\t\t\t\t Enter 5 to search Value by Index\n\t\t\t\t Enter 6 to display Array\n\t\t\t\t Enter 0 to exit\n\t\t\t\t\tChoice=");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            s = insert(arr, s);
            break;
        case 2:
            s = delByIndex(arr, s);
            break;
        case 3:
            searchByVal(arr, s);
            break;
        case 5:
            searchByIndex(arr, s);
            break;
        case 4:
            s = delByVal(arr, s);
            break;
        case 6:
            display(arr, s);
            break;
        }
    } while (choice != 0);
}
int insert(int arr[], int s)
{
    system("cls");
    int loc, val, c = 0, tmp = 0, sh;
    do
    {
        printf("\nEnter the location on which you want to insert value: ");
        scanf("%d", &loc);
        if (loc > s)
        {
            printf("Warning! No Such Location Exist");
            printf("\nEnter a Valid Location");
        }
    } while (loc > s);
    printf("Enter the value you want to insert: ");
    scanf("%d", &val);
    sh = s;
    for (c = 0; c < s; c++)
    {
        if (c == loc)
        {
            tmp = arr[c];
            arr[c] = val;
            s++;
        }
        if (c > loc)
        {
            arr[sh] = arr[sh - 1];
            sh--;
        }
    }
    arr[loc + 1] = tmp;
    printf("\nValue Successfully Inserted at Location %d", loc);
    return s;
}

int delByIndex(int arr[], int s)
{
    system("cls");
    int i, pos;

    /* Input element position to delete */
    printf("Enter the element position to delete : ");
    scanf("%d", &pos);

    /* Invalid delete position */
    if (pos < 0 || pos > s)
    {
        printf("Invalid position! Please enter position between 1 to %d", s);
    }
    else
    {
        /* Copy next element value to current element */
        for (i = pos - 1; i < s - 1; i++)
        {
            arr[i] = arr[i + 1];
        }

        /* Decrement array size by 1 */
        s--;

        /* Print array after deletion */
        printf("Element is Deleted..!!\n");
        printf("\nElements of array after delete are : ");
        display(arr,s);
    }
    return s;
}
void searchByVal(int arr[], int s)
{
    int flag = 0;
    int val;
    printf("Enter the value to be searched: ");
    scanf("%d", &val);

    for (int i = 0; i < s; i++)
    {
        if (val == arr[i])
        {
            if (flag == 0)
            {
                printf("Element Found at Index %d\n", i);
                flag = 1;
            }
            else
            {
                printf("Element ALSO found at Index %d\n", i); //for duplicate elements in Array
            }
        }
    }

    if (flag == 0)
    {
        printf("Element Not Found\n");
    }
}
int delByVal(int arr[], int s)
{
    int val;
    int flag = 0;
    printf("Enter the value to be deleted: ");
    scanf("%d", &val);
    for (int i = 0; i < s; i++)
    {
        if (val == arr[i])
        {
            int j;
            for (j = i; j < s; j++)
            {
                arr[j] = arr[j+1];
            }
            s--; //decreasing size
            if (flag == 0)
            {
                printf("Value %d deleted at index %d successfully\n",val,i);
                flag = 1;
            }
            else
            {
                printf("Value %d ALSO deleted at index %d successfully\n",val,i); //in case of repeated values in array
            }
            i--; //for successive duplicative elements elements
        }
    }

    if (flag == 0)
    {
        printf("Element Not Found\n");
    }
    else
    {
        printf("New Array Values are:\n");
        display(arr,s);
    }

    return s;
}
void searchByIndex(int arr[], int s)
{
    printf("%d", arr[2]);
    system("cls");
    int loc, c;
    do
    {
        printf("\nEnter the index you want to search: ");
        scanf("%d", &loc);
        if (loc > s)
        {
            system("cls");
            printf("Warning! No Such Location Exist");
            printf("\nEnter a Valid Location");
        }

    } while (loc > s);
    printf("Value at index %d is: %d", loc, arr[loc]);
}
void display(int arr[], int s)
{

    for (int i = 0; i < s; i++)
    {
        printf("Value at arr[%d] is = %d\n", i, arr[i]);
    }
}
