#include "bst.h"

int main(int argc, char const *argv[])
{//40, 10, 65, 25, 90, 5, 34, 20, 110, 15
    treeNode *tree = NULL;

    tree = insertBST(tree, 40);
    tree = insertBST(tree, 10);
    tree = insertBST(tree, 65);
    tree = insertBST(tree, 25);
    tree = insertBST(tree, 90);
    tree = insertBST(tree, 5);
    tree = insertBST(tree, 34);
    tree = insertBST(tree, 20);
    tree = insertBST(tree, 110);
    tree = insertBST(tree, 15);

    printf("The number of nodes in tree are =  %d",countNo(tree,0));
    tree = deleteNode(tree,25);
    tree = deleteNode(tree,65);
    printf("The number of nodes in tree are =  %d",countNo(tree,0));

    if (isBST(tree))
    {
        printf("\nThe tree is still a BST\n");
    }
    else
    {
        printf("\nThe tree is NOT a BST\n");
    }

    printf("\n-------------IN ORDER TRAVERSAL IS ------------------\n");
    displayUsingInOrder(tree);
    printf("\n-------------POST ORDER TRAVERSAL IS ------------------\n");
    displayUsingPostOrder(tree);
    printf("\n-------------PRE ORDER TRAVERSAL IS ------------------\n");
    displayUsingPreOrder(tree);

    printf("\n------ENTER THE VALUE TO BE SEARCHED------\n");
    int data;
    scanf("%d",&data);

    if (!searchBST(tree,data,0))
    {
        printf("\nThis element does not exist in the tree\n");
    }

    tree = insertBST(tree,45);
    tree = insertBST(tree,100);

    printf("\n\nThe smallest value is = %d",minVal(tree)->data);
    printf("\n\nThe largest value is = %d",maxVal(tree)->data);
    getch();

    return 0;
}
