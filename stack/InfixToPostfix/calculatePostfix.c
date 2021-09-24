#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include "NodeStackInt.h"

int isNumber(char c);
int result (int a, int b, char operator);

int calculateResult(char* expression);

int main(int argc, char const *argv[])
{
    char exp2[] = "123*+";
    calculateResult(exp2);
    getch();   
    return 0;
}

int isNumber(char c)
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
    for (int i = 0; expression[i] != '\0'; i++)
    {
        int number = isNumber(expression[i]);
        if (number != -1)
        {
            pushInt(number);
        }
        else
        {
            if (getLengthIntStack() < 2)
            {
                printf("Invalid Expression");
                return -2;
            }
            else
            {
                char op = expression[i];
                int number1 = popInt();
                int number2 = popInt();
                int calculation  = result(number1,number2,op);
                if (calculation == -1)
                {
                    printf("Wrong Operator");
                }
                else
                {
                    pushInt(calculation);
                }
                
            }


            
        }
        
        
    }
    printf("Result is = %d",peekInt());
    return popInt();
}
