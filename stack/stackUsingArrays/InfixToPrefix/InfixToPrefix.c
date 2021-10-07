#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include "PostFixUsingOnlyInt.h"
/*
    Algo For Prfix is:
        Take Expression
        Reverse it 
        Reverse the brackets (Opening to closing and closing to opening)
        Solve it using postfix logic
        Reverse it again
        The given answer is in prefix form
*/
char* reverseBracket(char c[]);
char *reverseExpression(char expression[]);
char *reverseArray(char array[]);
int main()
{

    char infix[20];
    printf("ENTER THE EXPRESSION IN INFIX FORM");
    gets(infix);
    printf("The Prefix Expression is = %s", reverseArray(infixToPostFix(reverseExpression(infix))));
    getch();
    return 0;
}

char* reverseBracket(char c[])
{
    for (int i = 0; c[i] != '\0'; i++)
    {
        if (c[i] == '(')
        {
            c[i] = ')';
        }

        else if (c[i] == ')')
        {
            c[i] = '(';
        }
    }
    return c;

}

char *reverseExpression(char expression[])
{
    char temp;
    int length = strlen(expression) - 1;
    for (int i = 0, j = length; i <= length / 2; i++, j--)
    {
        temp = expression[i];
        expression[i] = expression[j];
        expression[j] = temp;
    }

    return reverseBracket(expression);
}

char *reverseArray(char array[])
{
    char temp;
    int length = strlen(array) - 1;
    for (int i = 0, j = length; i <= length / 2; i++, j--)
    {
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    return array;
}

