#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define SIZE 15
typedef struct StackArray
{
    int data;
    int max;
    int top;
    char arr[SIZE];
} StackArrayChar;

void push(StackArrayChar* stack, char value)
{
    if (stack->top >= SIZE)
    {
        printf("Stack Overflow");
        return;
    }
    
    stack->top++;
    stack->arr[stack->top] = value;
    
}

char pop(StackArrayChar* stack)
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

char peek(StackArrayChar* stack)
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

void display(StackArrayChar* stack)
{
    if (stack->top != -1)
    {
        for (int i = 0; i <= stack->top; i++)
        {
            printf("\nElement is = %c\n",stack->arr[i]);
        }
        
    }
    else
    {
        printf("stack is emoty");
    }
    
    
}

int isEmpty(StackArrayChar* stack)
{
    return stack->top == -1;
}
