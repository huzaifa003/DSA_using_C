#include <stdio.h>
#include <conio.h>
#include "NodeSinglyLinkedList.h"


int main(int argc, char const *argv[])
{
    Node *parent = NULL;

    parent = insertFrontSingly(parent, 1);
    parent = insertFrontSingly(parent, 2);
    parent = insertFrontSingly(parent, 3);
    parent = insertFrontSingly(parent, 4);
    parent = insertFrontSingly(parent, 5);
    parent = insertFrontSingly(parent, 6);

    displaySingly(parent);
    getch();
    return 0;
}
