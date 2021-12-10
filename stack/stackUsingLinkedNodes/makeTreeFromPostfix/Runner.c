#include "NodeStack.h"
#include "InfixToPostfix.h"
#include <stdio.h>
#include <conio.h>
int makeTree(char postfix[])
{
    for (int i = 0; postfix[i] != '\0'; i++)
    {
        tree* temp = (tree*) malloc(sizeof(tree));
        temp->data = postfix[i];
        if (isOperand(postfix[i]))
        {   
            temp->left = NULL;
            temp->right = NULL;
        }
        else
        {
            
            temp->right = pop();
            temp->left = pop();
        }

        insertStack(temp);
    }

    tree* tempNode = pop();
    printf("\nDisplaying Using In Order : \n");
    displayUsingInOrder(tempNode);
    printf("\n\nDisplaying Using Post Order : \n");
    displayUsingPostOrder(tempNode);
    printf("\n\nDisplaying Using Pre Order : \n");
    displayUsingPreOrder(tempNode);
}
int main(int argc, char const *argv[])
{
    char exp[] = "((a+b-c)/(d*e))^3";
    printf("Prefix Expression is = %s\n\n",exp);
    infixToPostFix(exp);
    printf("Postfix Expression is = %s\n\n", output);
    makeTree(output);
    getch();
    return 0;
}
