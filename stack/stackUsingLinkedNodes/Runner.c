#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "NodeStack.h"
int main() {

    insertStack(1);
    displayStack(); //inserting values and displaying 
    
    insertStack(2); //inserting and popping
    printf("\nFirst Popped Element is = %d",pop());
    insertStack(3);
    insertStack(4); //inserting again
    insertStack(5);
    displayStack(); //displaying and checking length
    printf("Length of stack is = %d",getLengthStack());
    
    printf("\nEmptying Stack\n\n"); //emptying stack 
    freeStack();
    printf("Length of stack is = %d",getLengthStack()); //checking length and displaying
    displayStack();
    
    //again inserting data after freeing and displaying 
    printf("\nFilling Stack\n\n");
    insertStack(3);
    insertStack(4);
    insertStack(5);
    displayStack(); //displaying again

    //popping Node instead of data of node
    stackNode* poppedNode = popNode();
    printf("\nAddress of popped Node is = %d\n",poppedNode);
    printf("\nValue of Popped Node is = %d\n",poppedNode->data);
    free(poppedNode);
    poppedNode = NULL; //freeing memory later on
    getch();
    return 0;
}