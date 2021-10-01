#include "StackArrayChar.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int isOperand(char c);
int checkPrecidence(char c);

char *infixToPostFix(char expression[]);
int main()
{
    char exp[] = "((a+b-c)/(d*e))^3";
    infixToPostFix(exp);
    getch();
    return 0;
}

int isOperand(char c) //checks if value is an operand or not
{
    if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int checkPrecidence(char c) //returns precedence by number
{
    if (c == '+' || c == '-')
    {
        return 1;
    }
    else if (c == '/' || c == '*')
    {
        return 2;
    }
    else if (c == '^')
    {
        return 3;
    }
    else
    {
        return -1; //if it is not an operator
    }
}

char *infixToPostFix(char expression[])
{
    StackArrayChar stack;
    stack.top = -1;
    int j = 0;
    char output[50] = {""};
    for (int i = 0; expression[i] != '\0'; i++)
    {
        if (isOperand(expression[i])) //operand is appended directly to output
        {
            output[j] = expression[i];
            j++;
        }

        else if (expression[i] == '(')
        {
            push(&stack, expression[i]); //starting bracker is pushed to stack
            // display(&stack);
        }

        else if (expression[i] == ')') //after encountering closing bracket we iterate until opening one is found
        {
            while (!isEmpty(&stack) && peek(&stack) != '(')
            {
                output[j] = pop(&stack); //popping all elements until opening bracket is found in stack and appending it to output array
                j++;
            }
            if (!isEmpty(&stack) && peek(&stack) != '(')
            {
                return "-1"; //invalid expression
            }
            else
            {
                pop(&stack); //this will pop that opening bracket we were looking for cause after finding it's closing bracket it's use has ended
            }
        }

        else
        { //when an operand is found it's precendance is compared with top element and if it's precedence is smaller then that operand is popped
            while (!isEmpty(&stack) && checkPrecidence(expression[i]) <= checkPrecidence(peek(&stack)))
            {
                // popping all the operands and appending to output which have higher precedance than current one
                output[j] = pop(&stack);
                j++;
            }

            push(&stack, expression[i]); //pushing current operand
        }
    }

    while (!isEmpty(&stack))
    {
        //appending all the remaining elements in the stack to output array
        output[j] = pop(&stack);
        j++;
    }

    printf("Expression is = %s", output);
    
}