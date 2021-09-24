#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "NodeStackChar.h"

// Algorithm 
// 1. Scan the infix expression from left to right. 
// 2. If the scanned character is an operand, output it. 
// 3. Else, 
//       1 If the precedence of the scanned operator is greater than the precedence of the operator in the stack(or the stack is empty or the stack contains a ‘(‘ ), push it. 
//       2 Else, Pop all the operators from the stack which are greater than or equal to in precedence than that of the scanned operator. After doing that Push the scanned operator to the stack. (If you encounter parenthesis while popping then stop there and push the scanned operator in the stack.) 
// 4. If the scanned character is an ‘(‘, push it to the stack. 
// 5. If the scanned character is an ‘)’, pop the stack and output it until a ‘(‘ is encountered, and discard both the parenthesis. 
// 6. Repeat steps 2-6 until infix expression is scanned. 
// 7. Print the output 
// 8. Pop and output from the stack until it is not empty.

int isOperand(char c);
int checkPrecidence(char c);

int  infixToPostFix(char expression[]);

int main() {
    
    char exp[] = "((a+b-c)/(d*e))^3";
    infixToPostFix(exp);
    getch();
    return 0;
}

int isOperand(char c) //checks if value is an operand or not
{
    if (c >= 'a' && c <= 'z' || c>='A' && c <='Z' || c>='0' && c <= '9')
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

int infixToPostFix(char expression[])
{
    
    int j = 0;
    char output[50] = {""};
    for (int i = 0; expression[i] != '\0'; i++)
    {
        if (isOperand(expression[i])) //operand is appended directly to output 
        {
            output[j] = expression[i];
            j++;
        }
        else if (expression[i] == '(') //starting bracker is pushed to stack
        {
            push(expression[i]);
        }
        else if (expression[i] == ')') //after encountering closing bracket we iterate until opening one is found
        {
            while (!isEmptyStack() && peak() != '(')
            {
                output[j] = pop(); //popping all elements until opening bracket is found in stack and appending it to output array
                j++;
            }
                if (!isEmptyStack() && peak() != '(')
                {
                    printf("Hello");
                    return -1;  //invalid expression
                }
                else
                {
                    pop(); //this will pop that opening bracket we were looking for cause after finding it's closing bracket it's use has ended
                }
                
            
        }

        else 
        { //when an operand is found it's precendance is compared with top element and if it's precedence is smaller then that operand is popped
            while (!isEmptyStack() && checkPrecidence(expression[i]) <= checkPrecidence(peak())) 
            {
                // popping all the operands and appending to output which have higher precedance than current one
                output[j] = pop(); 
                j++; 
            }

            push(expression[i]); //pushing current operand
        }
        
    }

    while (!isEmptyStack())
    {
        //appending all the remaining elements in the stack to output array
        output[j] = pop();
        j++;
    }

    
    printf("Expression is = %s",output);
    
}