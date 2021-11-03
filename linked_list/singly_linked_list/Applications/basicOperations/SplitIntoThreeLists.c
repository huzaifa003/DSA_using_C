#include <stdio.h>
#include <conio.h>
#include "NodeSinglyLinkedList.h"
void splitList(Node* parent, Node* head2, Node* head3, Node* head4)
{
    int parentLength = getLength(parent);
    if (parentLength < 3)
    {
        printf("\n========Length is not enough========\n");
        return;
    }

    else
    {
        int count = 0;
        head2 = parent;
        while (count < parentLength/3 -1 )
        {
            parent = parent->next;
            count++;
        }

        head3 = parent->next;
        parent->next = NULL;

        parent = head3;
        count = 0;
        while (count  < parentLength/3 -1)
        {
            parent = parent->next;
            count++;
        }
        head4 = parent->next;
        parent->next = NULL;
        
        printf("\n------------List#01 is------------\n");
        displaySingly(head2);
        printf("\n------------List#02 is------------\n");
        displaySingly(head3);
        printf("\n------------List#03 is------------\n");
        displaySingly(head4);
        
    }
    
}
int main(int argc, char const *argv[])
{
    Node* parent = NULL;

    parent = insertFrontSingly(parent,1);
    parent = insertFrontSingly(parent,2);
    parent = insertFrontSingly(parent,3);
    parent = insertFrontSingly(parent,4);
    parent = insertFrontSingly(parent,5);
    parent = insertFrontSingly(parent,6);

    printf("\n------------Full List is------------\n");
    displaySingly(parent);

    Node* head2 = NULL;
    Node* head3 = NULL;
    Node* head4 = NULL;
    splitList(parent,head2,head3,head4);
    getch();
    return 0;
}
