#include <stdio.h>

typedef struct StackArray
{
    int max;
    int top;
    char array[50];
} Stack;

void push(Stack* structArray, char e)
{
    if(structArray->top >= 50)
    {
        printf("Stack overflow");
    }
    else
    {
        structArray->top++;
        structArray->array[structArray->top] = e;
    }
}

char pop(Stack* structArray)
{
    if(structArray->top == -1)
    {
        printf("Stack underflow");
        return 0;
    }
    else
    {
        structArray->top--;
        return structArray->array[structArray->top + 1];
    }
}

char peek(Stack* structArray)
{
    if(structArray->top == -1)
    {
        printf("Stack underflow");
        return 0;
    }
    else
    {
        return structArray->array[structArray->top];
    }
}

int isEmpty(Stack* s)
{
    return s->top == -1;
}