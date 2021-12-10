#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

char output[50] = {""};
typedef struct stackNode
{
    struct stackNode* next;
    char data;
}stackNode;

stackNode* Top = NULL;
int len = 0;

void pushChar(char data) //inserts a new element on Top
{
    stackNode* newNode = (stackNode *) malloc(sizeof(stackNode));
    newNode->data = data;
    newNode->next = NULL;

    if (Top == NULL)
    {
        Top = newNode;
    }
    else
    {
        newNode->next = Top; //cause newNode will become Top later on hence it'll point to current newNode
        Top = newNode;
    }
    len++;
}

char popChar() //removes 1 element from Top
{
    
    if (Top != NULL)
    {
        stackNode* temp = Top;
        Top = Top->next; 
        len--;
        return temp->data;
        
    }
    else
    {
        return (int) NULL;
    }
}

stackNode* popNodeChar()
{
    if (Top != NULL)
    {
        stackNode* temp = Top;
        Top = Top->next; 
        len--;
        return temp;
        
    }
    else
    {
        return NULL;
    }
}

char peekChar() //returns the Top element data without removing it 
{
    return Top->data;
}

int isEmptyCharStack() //returns 1 if len is 0
{
    return len == 0;
}

int getlenCharStack()
{
    return len;
}

void freeCharStack()
{
    free(Top);
    Top = NULL; //freeing memory along with adding NULL to avoid dangling pointers
    len = 0;
}

void displayCharStack() //not used but just using here for convineance to display stack and debug it
{
    stackNode* temp = Top;
    printf("\n---------------------------------------\n");
    while (temp != NULL)
    {
        printf("Data is = %d\n",temp->data);
        temp = temp->next;
    }
    
}


// Algorithm for conversion of INFIX TO POSTFIX
// 1. Scan the infix expression from left to right. 
// 2. If the scanned character is an operand, output it. 
// 3. Else, 
//       1 If the precedence of the scanned operator is greater than the precedence of the operator in the stack(or the stack is empty or the stack contains a ‘(‘ ), push it. 
//       2 Else, Pop all the operators from the stack which are greater than or equal to in precedence than that of the scanned operator. After doing that Push the scanned operator to the stack. (If you encounter parenthesis while popping then sTop there and push the scanned operator in the stack.) 
// 4. If the scanned character is an ‘(‘, push it to the stack. 
// 5. If the scanned character is an ‘)’, pop the stack and output it until a ‘(‘ is encountered, and discard both the parenthesis. 
// 6. Repeat steps 2-6 until infix expression is scanned. 
// 7. Print the output 
// 8. Pop and output from the stack until it is not empty.

int isOperand(char c);
int checkPrecidence(char c);

int  infixToPostFix(char expression[]);

//Algorithm for evaluation postfix expressions. 
// 1) Create a stack to store operands (or values). 
// 2) Scan the given expression and do the following for every scanned element. 
// …..a) If the element is a number, push it into the stack 
// …..b) If the element is a operator, pop operands for the operator from stack. Evaluate the operator and push the result back to the stack 
// 3) When the expression is ended, the number in the stack is the final answer 



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
    for (int i = 0; expression[i] != '\0'; i++)
    {
        if (isOperand(expression[i])) //operand is appended directly to output 
        {
            output[j] = expression[i];
            j++;
        }
        else if (expression[i] == '(') //starting bracker is pushed to stack
        {
            pushChar(expression[i]);
        }
        else if (expression[i] == ')') //after encountering closing bracket we iterate until opening one is found
        {
            while (!isEmptyCharStack() && peekChar() != '(')
            {
                output[j] = popChar(); //popping all elements until opening bracket is found in stack and appending it to output array
                j++;
            }
                if (!isEmptyCharStack() && peekChar() != '(')
                {
                    printf("Hello");
                    return -1;  //invalid expression
                }
                else
                {
                    popChar(); //this will pop that opening bracket we were looking for cause after finding it's closing bracket it's use has ended
                }
                
            
        }

        else 
        { //when an operand is found it's precendance is compared with Top element and if it's precedence is smaller then that operand is popped
            while (!isEmptyCharStack() && checkPrecidence(expression[i]) <= checkPrecidence(peekChar())) 
            {
                // popping all the operands and appending to output which have higher precedance than current one
                output[j] = popChar(); 
                j++; 
            }

            pushChar(expression[i]); //pushing current operand
        }
        
    }

    while (!isEmptyCharStack())
    {
        //appending all the remaining elements in the stack to output array
        output[j] = popChar();
        j++;
    }

    
    isEmptyCharStack();
}
