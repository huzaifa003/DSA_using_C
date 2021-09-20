#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "NodeStack.h"
int main() {

    insertStack(1);
    displayStack();
    
    insertStack(2);
    printf("\nFirst Popped Element is = %d",pop());
    insertStack(3);
    insertStack(4);
    insertStack(5);
    displayStack();
    printf("Length of stack is = %d",getLength());
    
    getch();
    return 0;
}