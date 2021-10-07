#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define SIZE 15
typedef struct StackArrayArray
{
    int data;
    int max;
    int top;
    char arr[SIZE];
} StackArrayChar;

void pushCharStack(StackArrayChar* stack, char value)
{
    if (stack->top >= SIZE)
    {
        printf("Stack Overflow");
        return;
    }
    
    stack->top++;
    stack->arr[stack->top] = value;
    
}

char popCharStack(StackArrayChar* stack)
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

char peekCharStack(StackArrayChar* stack)
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

void displayCharStack(StackArrayChar* stack)
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

int isEmptyCharStack(StackArrayChar* stack)
{
    return stack->top == -1;
}
