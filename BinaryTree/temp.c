#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//create bst
//insert bst
//traverse BST
//menu

typedef struct BST
{
    int data;
    struct BST *left;
    struct BST *right;
} BST;

BST *insert(int data, BST *root)
{

    //creation of bst
    if (root == NULL)
    {
        BST *newnode = malloc(sizeof(BST));
        newnode->data = data;
        newnode->left = NULL;
        newnode->right = NULL;
        root = newnode;
    }
    //now condition if smaller then put it in left
    else if (data < root->data)
        root->left = insert(data, root->left);
    else if (data > root->data)
        root->right = insert(data, root->right);
    return root;
}

//traversal

void inorder(BST *root)
{
    //in -order left,root,right
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d\n", root->data);
        inorder(root->right);
    }
}

void preorder(BST *root)
{
    if (root != NULL)
    {
        printf("%d", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(BST *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d", root->data);
    }
}
//as we know the minimum value of node is the leftmost value of tree
void mintree(BST *root)
{
    BST *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    printf("The smalles value %d", temp->data);
}

void MaxBST(BST *root)
{
    //as we know the rightmost value is the greatest value of bst
    BST *temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    printf("The greatest value %d", temp->data);
}
int main()
{
    int choice;
    BST *root = NULL;
    int data;

    do
    {
        printf("\t\t\tTHE MENU :");
        printf("\t\t\tEnter 1:TO INSERT the BST \n");
        printf("\t\t\tEnter 2:PRINTING USING INORDER TRAVERSAL\n");
        printf("\t\t\t Enter 3:PRE ORDER TRAVERSAL\n");
        printf("\t\t\t Enter 4:Post ORDER TRAVERSAL\n");
        printf("\t\t\t Enter 5:MINIMUM & lowest value of BST\n");
        printf("\t\t\t Enter 6:Maximum & greatest value of BST\n");
        printf("Exit the program");
        printf("ENTER THE CHOICE :");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("insert the bst value\n");
            scanf("%d", &data);
            root = insert(data, root);
            break;
        case 2:
            printf("THE inorder\n");
            inorder(root);
            break;
        case 3:
            printf("travserse the pre-order code");

            preorder(root);
            break;
        case 4:
            printf("travserse the Post-order code");
            postorder(root);
            break;
        case 5:
            printf("the minimum value");
            mintree(root);
            break;
        case 6:
            printf("maximum value ");
            MaxBST(root);
            break;
        case 7:
            printf("program exit");
            break;
        default:
            printf("YOU have entered the wrong choice");
        }
    } while (choice != 7);

    return 0;
}