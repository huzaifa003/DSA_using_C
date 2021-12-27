#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>
#define SIZE 20
int arr[SIZE];

int* createArray()
{
    srand(time(NULL));

    for (int i = 0; i < SIZE; i++)
    {
        if (i%2 == 0)
            arr[i] = -rand()%100;
        else 
            arr[i] = rand()%100;
    }

    return arr;
}

void printArray()
{
    printf("\n------------------------------------------------\n");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d,",arr[i]);
    }
    printf("\n------------------------------------------------\n");
}