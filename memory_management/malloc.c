#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

/*
malloc is used to assign memory to a particular type of data.
it assigns one block at a time that's why we have to do calculations.
malloc returns a void pointer that points to the start of memory location.
This pointer needs to be typecasted.
*/
// mal
int main() {

    int* ptr;
    ptr = (int*) malloc(1*sizeof(int)); //1 cause Cause we need to store only 1 integer variable its optional in this case
    printf("Enter First integer: ");
    scanf("%d",ptr);
    printf("value of ptr = %d\n\n",*ptr); //Getting value of pointer

    //Now assigning for two integers

    ptr = (int*) malloc(2*sizeof(int)); //2 Here means we need memory for two variables
    printf("Enter the value of first integer in newly allocated memory: ");
    scanf("%d",ptr + 0);  //+0 means that arithmetic is 0 and it'll point to first memory element

    printf("Enter the value of second Integer in newly allocated memory: ");
    scanf("%d",ptr + 1);

    printf("\nAddress of first integer in newly allocated memory is = %d\nAddress of Second Integer in newly allocated memory is = %d\n\n",(ptr + 0) , (ptr + 1)); //note difference is of 4 bytes cause of int value

    printf("Value of first integer in newly allocated memory is = %d\nValue of Second Integer in newly allocated memory is = %d\n\n",*(ptr + 0) , *(ptr + 1));

    return 0;
}