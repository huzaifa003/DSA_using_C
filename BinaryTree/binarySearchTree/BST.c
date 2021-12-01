#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
typedef struct treeNode
{
    struct treeNode *left;
    int data;
    struct treeNode *right;
} treeNode;

treeNode *root = NULL;

void insert(int data)
{
    //making a new Node
    treeNode *newNode = (treeNode *)malloc(sizeof(treeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    if (root == NULL)
    {
        root = newNode;
    }
    else
    {
        treeNode *parentOfTemp = NULL;
        treeNode *temp = root;
        while (1)
        {
            printf("Hello\n");
            parentOfTemp = temp;
            if (data < temp->data)
            {
                temp = temp->left;
                if(temp == NULL)
                {
                    parentOfTemp->left = newNode;
                    return;
                }
            }

            else 
            {
                temp = temp->right;
                if (temp == NULL)
                {
                    parentOfTemp->right = newNode;
                    return;
                }
    
            }
        }
    }
}

void displayUsingPreOrder(treeNode* root)
{
    if (root == NULL)
    {
        return;
    }
    printf("Data is = %d\n",root->data);
    displayUsingLevelOrder(root->left);
    displayUsingLevelOrder(root->right);
}

void displayUsingInOrder(treeNode* root)
{
    if (root == NULL)
    {
        return;
    }
    displayUsingLevelOrder(root->left);
    printf("Data is = %d\n",root->data);
    displayUsingLevelOrder(root->right);
}

void displayUsingPostOrder(treeNode* root)
{
    if (root == NULL)
    {
        return;
    }
    displayUsingLevelOrder(root->left);
    displayUsingLevelOrder(root->right);
    printf("Data is = %d\n",root->data);
}
int main()
{
    insert(10);
    insert(4);
    insert(5);
    insert(1);
   
    displayUsingLevelOrder(root);

    return 0;
}