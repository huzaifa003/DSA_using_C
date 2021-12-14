#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
typedef struct treeNode
{
    struct treeNode *left;
    int data;
    struct treeNode *right;
} treeNode;


treeNode *insertBST(treeNode *root, int data)
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
            parentOfTemp = temp;
            if (data < temp->data)
            {
                temp = temp->left;
                if (temp == NULL)
                {
                    parentOfTemp->left = newNode;
                    return root;
                }
            }

            else
            {
                temp = temp->right;
                if (temp == NULL)
                {
                    parentOfTemp->right = newNode;
                    return root;
                }
            }
        }
    }
    return root;
}

void displayUsingInOrder(treeNode *root)
{
    if (root == NULL)
        return;
    else
    {
        displayUsingInOrder(root->left);
        printf("%d ", root->data);
        displayUsingInOrder(root->right);
    }
}

void displayUsingPreOrder(treeNode *root)
{
    if (root == NULL)
        return;
    else
    {
        printf("%d ", root->data);
        displayUsingPreOrder(root->left);
        displayUsingPreOrder(root->right);
    }
}

void displayUsingPostOrder(treeNode *root)
{
    if (root == NULL)
        return;
    else
    {
        displayUsingPostOrder(root->left);
        displayUsingPostOrder(root->right);
        printf("%d ", root->data);
    }
}

treeNode *minVal(treeNode *root)
{
    treeNode *temp = root;
    while (temp->left != NULL)
        temp = temp->left;
    return temp;
}

treeNode *maxVal(treeNode *root)
{
    treeNode *temp = root;
    while (temp->right != NULL)
        temp = temp->right;
    return temp;
}

treeNode *deleteNode(treeNode *root, int data)
{
    if (root == NULL)
        return root;
    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else
    {
        //if node has no child we will just free the last node
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        // if Node has one child we will simply link it's parent to it's child (temp which will recursively be stored in it's parent
        else if (root->left == NULL)
        {
            treeNode *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            treeNode *temp = root->left;
            free(root);
            return temp;
        }
        // Node has two child
        treeNode *temp = minVal(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int isBST(treeNode* root) 
{ 
  if (root == NULL) 
    return 1; 
    
  if (root->left!=NULL && maxVal(root->left)->data > root->data)  //if the max of left subtree is lesser than everything is lesser
    return 0; 
    
  if (root->right!=NULL && minVal(root->right)->data < root->data)  //if least of right subtree is greater than everything is greater
    return 0; 
  
  if (!isBST(root->left) || !isBST(root->right)) 
    return 0; 
    
  return 1; 
} 

int searchBST(treeNode* root, int data, int height)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->data == data)
    {
        printf("The element %d is found on height %d\n",data,height);
        return 1;
    }
    height++;

    return searchBST(root->left,data,height) || searchBST(root->right,data,height);
}

int countNo(treeNode* root, int i)
{
    if (root == NULL)
        return i;

    i++;
    i = countNo(root->left,i);
    i = countNo(root->right,i);
    return i;
}