#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
/*
realloc is used to reallocate memory without loosing data
this is used to change the size of memory that's allocated by malloac()
IF GIVEN SIZE IS SMALLER THAN OG SIZE THEN IT'LL SHRINK THE MEMORY
IF GIVEN SIZE IS GREATER THAN OG SIZE IT'LL CHECK IF IT CAN EXPAND MEMORY.
IF IT CAN IT'LL EXTEND THE MEMORY 
IF IT CAN'T IT WILL ALLOCATE ENTIRELY NEW MEMORY AND WIPE THE PREVIOUS ONE BY COPYING THAT DATA INTO NEW ONE
*/
int main() {

    int* ptr;
    ptr = (int*) malloc(1*sizeof(int)); //1 cause Cause we need to store only 1 integer variable its optional in this case
    printf("Enter First integer ");
    scanf("%d",ptr);
    printf("value of ptr = %d\n\n",*ptr); //Getting value of pointer

    //Now before we needed in malloc.c to assign a brand new pointer to have more memory.
    //But now by using realloac() we can change the size directly.

    ptr = realloc(ptr,2*sizeof(int)); //watch closely how these two memory locations are created while retaining the previous one which means that now there are three integer spaces in memory.

    printf("Enter the value of first integer in newly allocated memory: ");
    scanf("%d",ptr + 1);  //+1 means that arithmetic is 0+1 = 1 and it'll point to second memory element like array index

    printf("Enter the value of second Integer in newly allocated memory: ");
    scanf("%d",ptr + 2); //this will refer to third one

    printf("\nAddress of previous allocation is  =  %d\nAddress of first integer in newly allocated memory is = %d\nAddress of Second Integer in newly allocated memory is = %d\n\n",(ptr + 0) , (ptr + 1), (ptr + 2)); //note difference is of 4 bytes cause of int value

    printf("Value of previous allocation is  =  %d\nValue of first integer in newly allocated memory is = %d\nValue of Second Integer in newly allocated memory is = %d\n\n",*(ptr + 0) , *(ptr + 1), *(ptr + 2));
    

    ptr = realloc(ptr,1*sizeof(int)); //shrinking memory size
    printf("Value of First Value after decreasing the size of memory = %d\n\n",*(ptr+0));
    return 0;
}