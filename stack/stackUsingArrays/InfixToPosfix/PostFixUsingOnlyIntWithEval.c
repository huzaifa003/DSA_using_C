#include "StackArrayInt.h"
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

char *infixToPostFix(char expression[]) //each cahracter is read as an ASCII Code
{
    StackArrayInt stack;
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
            pushIntStack(&stack, expression[i]); //starting bracker is pushed to stack
            // display(&stack);
        }

        else if (expression[i] == ')') //after encountering closing bracket we iterate until opening one is found
        {
            while (!isEmptyIntStack(&stack) && peekIntStack(&stack) != '(')
            {
                output[j] = popIntStack(&stack); //popping all elements until opening bracket is found in stack and appending it to output array
                j++;
            }
            if (!isEmptyIntStack(&stack) && peekIntStack(&stack) != '(')
            {
                return "-1"; //invalid expression
            }
            else
            {
                popIntStack(&stack); //this will pop that opening bracket we were looking for cause after finding it's closing bracket it's use has ended
            }
        }

        else
        { //when an operand is found it's precendance is compared with top element and if it's precedence is smaller then that operand is popped
            while (!isEmptyIntStack(&stack) && checkPrecidence(expression[i]) <= checkPrecidence(peekIntStack(&stack)))
            {
                // popping all the operands and appending to output which have higher precedance than current one
                output[j] = popIntStack(&stack);
                j++;
            }

            pushIntStack(&stack, expression[i]); //pushing current operand
        }
    }

    while (!isEmptyIntStack(&stack))
    {
        //appending all the remaining elements in the stack to output array
        output[j] = popIntStack(&stack);
        j++;
    }
    j = '\0';
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
   StackArrayInt stack; //making int stack
    stack.top = -1;

    for (int i = 0; expression[i] != '\0'; i++)
    {
        int number = isNumber(expression[i]); //checking if given element is a number
        if (isNumber(expression[i])) // if it is a number then push it to stack
        {
            pushIntStack(&stack,expression[i] - '0');
        }
        else
        {
            if (stack.top < 1) //if there are less than two operands that means expression is wrong
            {
                printf("\n---Invalid Expression For Evaluation\n-------");
                return -2;
            }
            else
            {
                char op = expression[i];
                int number1 = (popIntStack(&stack)) ;
                int number2 = (popIntStack(&stack));
                int calculation  = result(number1,number2,op);
                if (calculation == -1)
                {
                    printf("\n-----Wrong type of Operator---Enter int type-----\n");
                    return -3;
                }
                else
                {
                    pushIntStack(&stack,calculation); //converting result to char for pushing to char array
                }
                
            }


            
        }
        
        
    }
    return popIntStack(&stack);
}