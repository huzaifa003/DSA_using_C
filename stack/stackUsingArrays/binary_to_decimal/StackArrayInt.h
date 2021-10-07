#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define SIZE 30
typedef struct StackArrayInt
{
    int data;
    int max;
    int top;
    int arr[SIZE];
} StackArrayInt;

void pushIntStack(StackArrayInt* stack, int value)
{
    if (stack->top >= SIZE)
    {
        printf("Stack Overflow");
        return;
    }
    
    stack->top++;
    stack->arr[stack->top] = value;
    
}

int popIntStack(StackArrayInt* stack)
{
    if (stack->top == -1)
    {
        printf("Stack underflow");
        return 0;
    }
    else
    {
        stack->top--;
       return stack->arr[stack->top +1];
        
    }
    
}
int peekIntStack(StackArrayInt* stack)
{
    if (stack->top != -1)
    {
        return stack->arr[stack->top];
    }
    else
    {
        printf("Stack Empty");
        return 0;
    }
    
}
void displayIntStack(StackArrayInt* stack)
{
    if (stack->top != -1)
    {
        for (int i = 0; i <= stack->top; i++)
        {
            printf("\nElement is = %d\n",stack->arr[i]);
        }
        
    }
    else
    {
        printf("stack is emoty");
    }
    
    
}

int isEmptyIntStack(StackArrayInt* stack)
{
    return stack->top == -1;
}
