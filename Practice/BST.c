#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct BST
{
    int data;
    struct BST *right;
    struct BST *left;
} BST;

BST *createNewNode(int data)
{
    BST *temp = malloc(sizeof(BST));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
BST *insertInBSTusingRecursion(BST *root, int data)
{
    if (root == NULL)
    {
        return createNewNode(data);
    }

    else
    {
        if (data < root->data)
            root->left = insertInBSTusingRecursion(root->left, data);
        else
            root->right = insertInBSTusingRecursion(root->right, data);
        return root;
    }
}
BST *insertInBSTusingIteration(BST *root, int data)
{
    if (root == NULL)
    {
        root = createNewNode(data);
        return root;
    }
    BST *iterator = root;
    BST *parentOfIterator = NULL;
    while (iterator != NULL)
    {
        parentOfIterator = iterator;
        if (data < iterator->data)
        {
            iterator = iterator->left;
            if (parentOfIterator->left == NULL)
            {
                parentOfIterator->left = createNewNode(data);
            }
        }
        else
        {
            iterator = iterator->right;
            if (parentOfIterator->left == NULL)
            {
                parentOfIterator->right = createNewNode(data);
            }
        }
    }

    return root;
}

void displayInOrderRecursive(BST *root)
{
    if (root == NULL)
        return;
    else
    {
        displayInOrderRecursive(root->left);
        printf("Data is = %d\n", root->data);
        displayInOrderRecursive(root->right);
    }
}

void displayUsingPreOrder(BST *root)
{
    if (root == NULL)
        return;
    else
    {
        printf("Data is = %d\n", root->data);
        displayUsingPreOrder(root->left);
        displayUsingPreOrder(root->right);
    }
}

BST *minValue(BST *root)
{
    BST *iterator = root;
    while (iterator->left != NULL)
    {
        iterator = iterator->left;
    }

    return iterator;
}

BST *maxValue(BST *root)
{
    BST *iterator = root;
    while (iterator->right != NULL)
    {
        iterator = iterator->right;
    }

    return iterator;
}
BST *deleteNodeBST(BST *root, int data)
{
    if (root == NULL)
    {
        return root;
    }

    if (data < root->data)
    {
        root->left = deleteNodeBST(root->left, data);
    }

    else if (data > root->data)
    {
        root->right = deleteNodeBST(root->right, data);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }

        else if (root->left == NULL)
        {
            return root->right;
        }

        else if (root->right == NULL)
        {
            return root->left;
        }

        else
        {
            int tempData = minValue(root->right)->data;
            root->data = tempData;
            root->right = deleteNodeBST(root->right, tempData);
        }
    }

    return root;
}

BST *balanceTree(BST *root, int left, int right, int inOrderBST[])
{
    if (left > right)
    {
        return NULL;
    }

    else
    {
        int middle = left + (right - left) / 2;
        root = createNewNode(inOrderBST[middle]);
        printf("root %d\n", root->data);
        getch();
        root->left = balanceTree(root, left, middle - 1, inOrderBST);
        root->right = balanceTree(root, middle + 1, right, inOrderBST);
        return root;
    }
}

int getInorderArray(BST *root, int arr[], int i)
{
    if (root == NULL)
        return i;
    else
    {
        i = getInorderArray(root->left, arr, i);
        arr[i] = root->data;
        i++;
        i = getInorderArray(root->right, arr, i);
        return i;
    }
}

BST *balancingTreeCaller(BST *root)
{
    int arr[100];
    int i = 0;
    i = getInorderArray(root, arr, i);
    for (int j = 0; j < i; j++)
    {
        printf("%d ", arr[j]);
    }
    return balanceTree(root, 0, i - 1, arr);
}

int checkBST(BST *root)
{
    if (root == NULL)
    {
        return 1;
    }

    if (root->left != NULL && maxValue(root->left)->data > root->data)
    {
        return 0;
    }
    if (root->right != NULL && minValue(root->right)->data < root->data)
    {
        return 0;
    }

    if (!checkBST(root->left) || !checkBST(root->right))
    {
        return 0;
    }

    return 1;
}
void print()
{
    printf("\n----------------------------------------------------------\n");
}

int isBST(BST *node)
{
    if (node == NULL)
        return 1;

    /* false if the max of the left is > than us */
    if (node->left != NULL && maxValue(node->left)->data > node->data)
        return 0;

    /* false if the min of the right is <= than us */
    if (node->right != NULL && minValue(node->right)->data < node->data)
        return 0;

    /* false if, recursively, the left or right is not a BST */
    if (!isBST(node->left) || !isBST(node->right))
        return 0;

    /* passing all that, it's a BST */
    return 1;
}
int main()
{
    BST *root = NULL;
    root = insertInBSTusingRecursion(root, 4);
    root = insertInBSTusingIteration(root, 5);
    root = insertInBSTusingRecursion(root, 1);
    root = insertInBSTusingRecursion(root, 2);
    root = insertInBSTusingRecursion(root, 3);
    printf("CHECK BST is = %d\n", checkBST(root));
    print();
    displayInOrderRecursive(root);

    root = deleteNodeBST(root, 3);
    print();

    displayInOrderRecursive(root);

    BST *root2 = NULL;
    root2 = insertInBSTusingIteration(root2, 3);
    root2->left = createNewNode(2);
    root2->right = createNewNode(5);
    root2->left->left = createNewNode(1);
    root2->left->right = createNewNode(4);
    print();
    displayInOrderRecursive(root2);
    print();
    printf("CHECK BST is = %d\n", checkBST(root2));

    BST *root3 = NULL;
    root3 = insertInBSTusingIteration(root3, 7);
    root3 = insertInBSTusingIteration(root3, 6);
    root3 = insertInBSTusingIteration(root3, 5);
    root3 = insertInBSTusingIteration(root3, 4);
    root3 = insertInBSTusingIteration(root3, 3);
    root3 = insertInBSTusingIteration(root3, 2);
    root3 = insertInBSTusingIteration(root3, 1);

    displayUsingPreOrder(root3);
    root3 = balancingTreeCaller(root3);
    displayUsingPreOrder(root3);

    getch();
    return 0;
}