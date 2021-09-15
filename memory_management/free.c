#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

/*
free is used to deallocate memory
this is programmers responsibillity
a freed pointer should be assigned NULL
BECAUSE OTHERWISE IT BECOMES A DANGLING POINTER
AKA A POINTER THAT REFERS TO MEMORY LOCATION THAT DOES NOT EXIST
*/
int main() {

    int* ptr = (int*) malloc(sizeof(int));
    printf("Address is = %d\n",ptr);

    free(ptr);
    ptr = NULL; //to avoid dangling pointer


    return 0;
}