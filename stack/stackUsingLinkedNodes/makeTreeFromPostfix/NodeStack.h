#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
/*
 * IT uses FILO structure which is first in last out, means elements added first are removed last
 * A stack consists of elements on top of each other
 * Stack uses push and pop
 * in Stack the top node is the top element
 * Top Element is used to push new elements or pop previous elements
 * It's like a SINGLE LINKED LIST IN UPWARD DIRECTION WHERE TOP == HEAD pointing to element below it
 * the below element points toward the next below element
 * CONSIDER IT LIKE A CLOSED SINGLE LINKED LIST
 * Length here is the total length starting from 0
 */

typedef struct tree
{
    char data;
    struct tree *right;
    struct tree *left;
} tree;
typedef struct stackNodeTree
{
    struct stackNodeTree *next;
    tree *treeNode;

} stackNodeTree;

stackNodeTree *top = NULL;
int length = 0;

void insertStack(tree* treeNode) //inserts a new element on top
{
    stackNodeTree *newNode = (stackNodeTree *)malloc(sizeof(stackNodeTree));
    newNode->treeNode = treeNode;
    newNode->next = NULL;

    if (top == NULL)
    {
        top = newNode;
    }
    else
    {
        newNode->next = top; //cause newNode will become top later on hence it'll point to current newNode
        top = newNode;
    }
    length++;
}

tree* pop() //removes 1 element from top
{

    if (top != NULL)
    {
        stackNodeTree *temp = top;
        top = top->next;
        length--;
        return temp->treeNode;
    }
    else
    {
        printf("\n-----Error in Popping------\n");
        return (int)NULL;
    }
}

stackNodeTree *popNode()
{
    if (top != NULL)
    {
        stackNodeTree *temp = top;
        top = top->next;
        length--;
        return temp;
    }
    else
    {
        return NULL;
    }
}

int peak() //returns the top element data without removing it
{
    return top->treeNode->data;
}

int isEmptyStack() //returns 1 if length is 0
{
    return length == 0;
}

int getLengthStack()
{
    return length;
}

void freeStack()
{
    free(top);
    top = NULL; //freeing memory along with adding NULL to avoid dangling pointers
    length = 0;
}

void displayStack() //not used but just using here for convineance to display stack and debug it
{
    stackNodeTree *temp = top;
    printf("\n---------------------------------------\n");
    while (temp != NULL)
    {
        printf("Data is = %d\n", temp->treeNode->data);
        temp = temp->next;
    }
}

void displayUsingInOrder(tree *root)
{
    if (root == NULL)
        return;
    else
    {
        displayUsingInOrder(root->left);
        printf("%c", root->data);
        displayUsingInOrder(root->right);
    }
}


void displayUsingPostOrder(tree *root)
{
    if (root == NULL)
        return;
    else
    {
        displayUsingPostOrder(root->left);
        displayUsingPostOrder(root->right);
        printf("%c", root->data);

    }
}

void displayUsingPreOrder(tree *root)
{
    if (root == NULL)
        return;
    else
    {
        printf("%c", root->data);
        displayUsingPreOrder(root->left);
        displayUsingPreOrder(root->right);
    }
}
