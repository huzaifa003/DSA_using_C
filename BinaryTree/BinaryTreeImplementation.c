#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "NodeQueue.h"
typedef struct treeNode
{
    struct treeNode* left;
    int data;
    struct treeNode* right;
} treeNode;

treeNode* root = NULL;

void insertUsingLevelOrder(int data)
{
    //making a new Node
    treeNode* newNode = (treeNode* ) malloc(sizeof(treeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    if (root == NULL)
    {
        root = newNode;
    }
    else
    {
        treeNode* temp;
        // enqueue(root);//TODO
    }
    
}
int main() {

    

    return 0;
}