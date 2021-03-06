#include "StackArrayChar.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
int isOperand(char c);
int checkPrecidence(char c);

char *infixToPostFix(char expression[]);


int isNumber(char c);
int convertCharToInt(char c);
int result (int a, int b, char operator);

int calculateResult(char* expression);

int main()
{
    char exp[] = "";
    printf("Enter the Expression:  ");
    gets(exp);
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
            pushCharStack(&stack, expression[i]); //starting bracker is pushed to stack
            // display(&stack);
        }

        else if (expression[i] == ')') //after encountering closing bracket we iterate until opening one is found
        {
            while (!isEmptyCharStack(&stack) && peekCharStack(&stack) != '(')
            {
                output[j] = popCharStack(&stack); //popping all elements until opening bracket is found in stack and appending it to output array
                j++;
            }
            if (!isEmptyCharStack(&stack) && peekCharStack(&stack) != '(')
            {
                return "-1"; //invalid expression
            }
            else
            {
                popCharStack(&stack); //this will pop that opening bracket we were looking for cause after finding it's closing bracket it's use has ended
            }
        }

        else
        { //when an operand is found it's precendance is compared with top element and if it's precedence is smaller then that operand is popped
            while (!isEmptyCharStack(&stack) && checkPrecidence(expression[i]) <= checkPrecidence(peekCharStack(&stack)))
            {
                // popping all the operands and appending to output which have higher precedance than current one
                output[j] = popCharStack(&stack);
                j++;
            }

            pushCharStack(&stack, expression[i]); //pushing current operand
        }
    }

    while (!isEmptyCharStack(&stack))
    {
        //appending all the remaining elements in the stack to output array
        output[j] = popCharStack(&stack);
        j++;
    }

    printf("Expression is = %s", output);
    printf("\nResult is = %d",calculateResult(output));
}

int isNumber(char c)
{
    if (c >= '0' && c <= '9')
    {
        return 1;
    }
    else
    {
        return 0; //indicating it's not a number
    }
    
}
int convertCharToInt(char c)
{
    if (c >= '0' && c <= '9')
    {
        return (int) (c - '0');
    }
    else
    {
        return -1; //indicating it's not a number
    }
    
}
int result (int a, int b, char operator)
{
    if (operator == '*')
    {
        return a*b;
    }

    else if (operator == '/')
    {
        if (b == 0)
        {
            return -2;
        }
        else
        {
            return a/b;
        }
        
    }
    else if (operator == '+')
    {
        return a+b;
    }
    else if (operator == '-')
    {
        return a-b;
    }

    else if (operator == '^')
    {
        return  (int) (pow(a,b) +0.5); //for power function giving result in double 
    }
    else
    {
        return -1; //for non operator 
    }
}

int calculateResult(char* expression)
{
    StackArrayChar stack; //making int stack
    stack.top = -1;

    for (int i = 0; expression[i] != '\0'; i++)
    {
        char number = isNumber(expression[i]); //checking if given element is a number
        if (isNumber(expression[i])) // if it is a number then push it to stack
        {
            pushCharStack(&stack,expression[i] - '0'); //pushing char by converting them to their int counterparts and pushing their ASCII
        }
        else
        {
            if (stack.top < 1) //if there are less than two operands that means expression is wrong
            {
                printf("Invalid Expression");
                return -2;
            }
            else
            {
                char op = expression[i];
                int number1 = (popCharStack(&stack)) ; //we don't need to change em to int cause we already pushed int ascii codes 198 line#
                int number2 = (popCharStack(&stack));
                int calculation  = result(number1,number2,op); //getting the ascii code by multiplying operators ascii code
                if (calculation == -1)
                {
                    printf("Wrong Operator");
                }
                else
                {
                    pushCharStack(&stack,calculation); //pushing result to array as well 
                }
                
            }


            
        }
        
        
    }
    return popCharStack(&stack);
}