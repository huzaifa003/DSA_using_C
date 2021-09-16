#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
/*
formula for 1-D array at BACKEND =  base address + (index - 1) * sizeof(data type)
*/
int main() {

    int size = 0;
    printf("Please Enter the number of elements you want to enter : ");
    scanf("%d",&size);
    int* ptr = (int* ) calloc(size,sizeof(int));
    for (int i = 0; i < size; i++)
    {
        printf("Please Enter the Value of Element Element[%d]",i);
        scanf("%d",&ptr[i]); //watch how this pointer acts like array
    }
    for (int i = 0; i < size; i++)
    {
        printf("Incremented Value by margin of 10 of element[%d] is = %d\n",i,ptr[i]+10);
    }
    
    

    return 0;
}