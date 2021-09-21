#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
/*
 * IT uses FILO structure which is first in last out, means elements added first are removed last
 * A stack consists of elements on top of each other
 * Stack uses push and pop
 * in Stack the top node is the top element
 * Top Element is used to push new elements or pop previous elements
 * It's like a SINGLE LINKED LIST IN UPWARD DIRECTION WHERE TOP == HEAD pointing to element below it
 * the below element points toward the next below element
 * CONSIDER IT LIKE A CLOSED SINGLE LINKED LIST
 * Length here is the total length starting from 0
 */

typedef struct stackNode
{
    struct stackNode* next;
    int data;
}stackNode;

stackNode* top = NULL;
int length = 0;

void insertStack(int data) //inserts a new element on top
{
    stackNode* newNode = (stackNode *) malloc(sizeof(stackNode));
    newNode->data = data;
    newNode->next = NULL;

    if (top == NULL)
    {
        top = newNode;
    }
    else
    {
        newNode->next = top; //cause newNode will become top later on hence it'll point to current newNode
        top = newNode;
    }
    length++;
}

int pop() //removes 1 element from top
{
    
    if (top != NULL)
    {
        stackNode* temp = top;
        top = top->next; 
        length--;
        return temp->data;
        
    }
    else
    {
        return (int) NULL;
    }
}

stackNode* popNode()
{
    if (top != NULL)
    {
        stackNode* temp = top;
        top = top->next; 
        length--;
        return temp;
        
    }
    else
    {
        return NULL;
    }
}

int peak() //returns the top element data without removing it 
{
    return top->data;
}

int isEmptyStack() //returns 1 if length is 0
{
    return length == 0;
}

int getLengthStack()
{
    return length;
}

void freeStack()
{
    free(top);
    top = NULL; //freeing memory along with adding NULL to avoid dangling pointers
    length = 0;
}

void displayStack() //not used but just using here for convineance to display stack and debug it
{
    stackNode* temp = top;
    printf("\n---------------------------------------\n");
    while (temp != NULL)
    {
        printf("Data is = %d\n",temp->data);
        temp = temp->next;
    }
    
}
