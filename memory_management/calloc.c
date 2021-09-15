#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

/*
calloc is used to allocate memory blocks directly instead of using multiplication to allocate them
this is pretty good for arrays and when we use to store multiple values and allocate memory for that
REMEMEBER ALL VALUES ARE AUTOMATICALLY INITIALIZED BY 0 using calloc 
*/
int main() {
    
    int* ptr = (int*) calloc(10,sizeof(int)); //this will allocate 10 blocks of integers in memory. in malloc() we needed to allocate using malloc(10*sizeof(int)) by multiplying

    for (int i = 0; i < 9; i++)
    {
        printf("Value Automatically Intialized of element %d is = %d\n",i,*(ptr+i)); //note how value is = 0
    }
    
    for (int i = 0; i < 9; i++)
    {
        printf("Address of Automatically Intialized element %d is = %d\n",i,(ptr+i));
    }

    for (int i = 0; i < 9; i++)
    {
        *(ptr+i) = i; //assigning value automatically
        printf("Value After Intialization is = %d\n",*(ptr+i));
    }
    

    return 0;
}