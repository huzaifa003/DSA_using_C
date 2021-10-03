#include "StackArrayChar.h"
#include <stdio.h>

int isOperand(char e)
{
    if((e >= 'a' && e <= 'z') || (e >= 'A' && e <= 'Z') || (e >= '0' && e <= '9'))
        return 1;
    else
        return 0;
}

int checkPrecedence(char e)
{
    if(e == '+' || e == '-')
        return 1;
    else if(e == '*' || e == '/')
        return 2;
    else if(e == '^')
        return 3;
    else
        return -1;
}

int isNumber(char e)
{
    if(e >= '0' && e <= '9')
        return 1;
    else
        return 0;
}

int operation(int a, int b, char operator)
{
    if(operator == '+')
        return b + a;
    else if(operator == '-')
        return b - a;
    else if(operator == '*')
        return b * a;
    else if(operator == '/')
        return b / a;
    else if(operator == '^')
        return b ^ a;
}

void evaluate(char e[50])
{
    Stack stack;
    stack.top = -1;
    int i;
    for(i = 0; e[i] != '\0'; i++)
    {
        if(isNumber(e[i]))
            push(&stack, e[i]);
        else
        {
            //you have to convert int to char by subtracting and adding '0' otherwise it'll just convert char to ascii code ie 0 will give 48
            int a = (int) pop(&stack) - '0';
            int b = (int) pop(&stack) - '0';  
            push(&stack, (char) operation(a, b, e[i]) + '0');
        }
    }
    printf("Evaluation: %c", pop(&stack));
}

void infixToPostfix(char e[50])
{
    Stack stack;
    stack.top = -1;
    char postfix[50] = {""};
    int j = 0, i;

    for(i = 0; e[i] != '\0'; i++)
    {
        if(isOperand(e[i]))
        {
            postfix[j] = e[i];
            j++;
        }
        else if(e[i] == '(')
        {
            push(&stack, e[i]);
        }
        else if(e[i] == ')')
        {
            while (!isEmpty(stack) && peek(stack) != '(')
            {
                postfix[j] = pop(&stack);
                j++;
            }
            pop(&stack);
        }
        else
        {
            while(!isEmpty(stack) && checkPrecedence(e[i]) <= checkPrecedence(peek(stack)))
            {
                postfix[j] = pop(&stack);
                j++;
            }
            push(&stack, e[i]);
        }
    }
    while (!isEmpty(stack))
    {
        postfix[j] = pop(&stack);
        j++;
    }
    printf("%s", postfix);
    evaluate(postfix);
}

int main()
{
    char expression[50] = {""};
    printf("Enter the expression: ");
    gets(expression);
    infixToPostfix(expression);
    return 0;
}