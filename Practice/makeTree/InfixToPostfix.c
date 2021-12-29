#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
typedef struct Tree
{
    char data;
    struct Tree *right;
    struct Tree *left;
} Tree;
typedef struct postfixStack
{
    Tree *tree;
    struct postfixStack *next;
} Stack;

Stack *pushPostfixChar(Stack *stack, Tree *tree)
{
    Stack *newStack = malloc(sizeof(Stack));
    newStack->tree = tree;

    if (stack == NULL)
    {
        stack = newStack;
        stack->next = NULL;
    }

    else
    {
        newStack->next = stack;
        stack = newStack;
    }

    return stack;
}
Stack *popPostfixChar(Stack **stack)
{
    if (*stack == NULL)
    {
        printf("EMpty");
    }
    Stack *temp = *stack;
    *stack = (*stack)->next;
    return temp;
}
typedef struct Stack
{
    int top;
    char arr[15];
} postfixStack;

void insertChar(postfixStack *stack, char c)
{
    stack->top++;
    if (stack->top >= 15)
    {
        printf("OVERFLOW IN CHAR");
        return;
    }
    stack->arr[stack->top] = c;
}

char getCharStack(postfixStack *stack)
{
    char c = stack->arr[stack->top];
    stack->top--;
    return c;
}
char peekChar(postfixStack *stack)
{
    return stack->arr[stack->top];
}
int isOperand(char c)
{
    if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9')
        return 1;
    return 0;
}

int checkPrecedence(char c)
{
    if (c == '-')
        return 1;
    if (c == '+')
        return 1;
    if (c == '*')
        return 2;
    if (c == '/')
        return 2;
    if (c == '^')
        return 4;
    else
        return -1;
}

char *infixToPostfix(char exp[])
{
    char *output = calloc(15, sizeof(char));
    postfixStack stack;
    char temp;
    stack.top = -1;
    int j = 0;
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (isOperand(exp[i]))
        {
            output[j] = exp[i];
            j++;
        }

        else if (exp[i] == '(')
        {
            insertChar(&stack, exp[i]);
        }

        else if (exp[i] == ')')
        {

            while ((temp = getCharStack(&stack)) != '(')
            {
                output[j] = temp;
                j++;
            }
        }

        else
        {
            while (checkPrecedence(exp[i]) <= checkPrecedence(peekChar(&stack)))
            {
                output[j] = getCharStack(&stack);
                j++;
            }
            insertChar(&stack, exp[i]);
        }
    }
    while (stack.top != -1)
    {
        output[j] = getCharStack(&stack);
        j++;
    }
    output[j] = '\0';
    return output;
}

void displayUsingInOrder(Tree *tree)
{
    if (tree == NULL)
    {
        return;
    }

    else
    {
     
        displayUsingInOrder(tree->left);
         printf("Data is = %c\n", tree->data);
        getch();  
        displayUsingInOrder(tree->right);
    }
}
void makeTree(char exp[])
{
    printf("%s", exp);
    getch();
    Stack *stack = NULL;
    for (int i = 0; exp[i] != '\0'; i++)
    {
        Tree *tree = malloc(sizeof(tree));
        tree->data = exp[i];
        if (isOperand(exp[i]))
        {
            tree->left = NULL;
            tree->right = NULL;
        }
        else
        {
            Stack *temp1 = popPostfixChar(&stack);
            if (temp1 == NULL)
            {
                printf("Null1");
                getch();
            }
            tree->right = temp1->tree;
            temp1 = popPostfixChar(&stack);
            if (temp1 == NULL)
            {
                printf("Null2");
                getch();
            }
       
            tree->left = temp1->tree;
        }
        stack = pushPostfixChar(stack, tree);
    }
    Stack *temp = popPostfixChar(&stack);
    if (temp == NULL)
    {
        printf("Meow");
        getch();
    }
    printf("\n%c->",temp->tree->data);
    printf("%c->",temp->tree->left->data);

    printf("%c->",temp->tree->right->data);
    getch();

    printf("hello");
    displayUsingInOrder(temp->tree);
    getch();

}
int main()
{
    char exp[] = "";
    printf("Enter the Expression:  ");
    gets(exp);
    char *arr = infixToPostfix(exp);
    printf("the outputs is = %s\n", arr);
    makeTree(arr);
    getch();

    return 0;
}