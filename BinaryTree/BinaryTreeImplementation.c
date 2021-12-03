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
int main()
{
    treeNode *root = NULL;
    int choice;
    int data;
    do
    {
        printf("1 - Insert\n");
        printf("2 - Delete\n");
        printf("3 - Print using In order\n");
        printf("4 - Print using Pre order\n");
        printf("5 - Print using Post order\n");
        printf("6 - Print lowest value\n");
        printf("7 - Print greatest value\n");
        printf("8 - Exit\n");
        printf("Enter your selection: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("Enter value: ");
            scanf("%d", &data);
            root = insertBST(root, data);
        }
        else if (choice == 2)
        {
            printf("What do you want to delete? ");
            scanf("%d", &data);
            deleteNode(root, data);
        }
        else if (choice == 3)
            displayUsingInOrder(root);
        else if (choice == 4)
            displayUsingPreOrder(root);
        else if (choice == 5)
            displayUsingPostOrder(root);
        else if (choice == 6)
            printf("Min Value is = %d\n",minVal(root));
        else if (choice == 7)
            printf("Max Value is = %d\n",maxVal(root));
        else if (choice == 8)
            printf("Program exited\n");
        else
            printf("Wrong input\n");
        printf("\n");
    } while (choice != 8);

    return 0;
}