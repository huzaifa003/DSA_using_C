#include <stdio.h>
#include <conio.h>
#include "NodeSinglyLinkedList.h"


Node* swapKNode(Node* head, int k)
{
    int totalLength = getLength(head);

    if (k > totalLength)
    {
        printf("\n=======Invalid Index=======\n");
        return NULL;
    }
    
    Node* leftNode = head;
    Node* leftNodePrev = NULL;

    Node* rightNode = head;
    Node* rightNodePrev = NULL;
    
    int leftIndex = k;
    int rightIndex = totalLength - k + 1;

    for (int i = 1; i < leftIndex; i++)
    {
        leftNodePrev = leftNode;
        leftNode = leftNode->next;
    }

    
    for (int i = 1; i < rightIndex; i++)
    {
        rightNodePrev = rightNode;
        rightNode = rightNode->next;
    }
    /*
        Changing the pointers by changing their previous's-> next to the opposite pointer
        left side's next will become right node
        right side next will be become left node 
        This will cause a self loop too
    */
    leftNodePrev->next = rightNode;
    rightNodePrev->next = leftNode;

    /*
        Next we change the changed pointers next to break the loop
    */
    Node* temp = rightNode->next;
    rightNode->next = leftNode->next;
    leftNode->next = temp;
    

    if (k == 0)
    {
        head = rightNode; //changing head if index is =  0
    }
    return head;
    
    
}
int main(int argc, char const *argv[])
{
    Node *parent = NULL;

    parent = insertFrontSingly(parent, 1);
    parent = insertFrontSingly(parent, 2);
    parent = insertFrontSingly(parent, 3);
    parent = insertFrontSingly(parent, 4);
    parent = insertFrontSingly(parent, 5);
    parent = insertFrontSingly(parent, 6);

    printf("\n------------OG List is------------\n");
    displaySingly(parent);


    parent = swapKNode(parent,2);
    displaySingly(parent);
    getch();
    return 0;
}