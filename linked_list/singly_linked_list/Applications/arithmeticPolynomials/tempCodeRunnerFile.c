#include <stdio.h>
#include <conio.h>
#include "NodeSinglyLinkedList.h"


void deleteDuplicates(Node* head)
{
    Node* iterator = head;
    while (iterator != NULL)
    {
        
        Node* temp = iterator;
        while (temp->next != NULL)
        {
            if (temp->next->power == iterator->power)
            {
                iterator->data = iterator->data + temp->next->data;
                temp->next = temp->next->next;
            }
            else
            {
                temp = temp->next;
            }
        }
        iterator = iterator->next;
        
    }
    printf("\n------------Expression is------------\n");
    displaySingly(head);
}

void sortList(Node* head)
{
    Node* iterator = head;
    Node* temp;
    while (iterator->next != NULL)
    {
        temp = iterator->next;
        while (temp != NULL)
        {
            if (temp->power > iterator->power)
            {
                int data = temp->data;
                temp->data = iterator->data;
                iterator->data = data;

                int power = temp->power;
                temp->power = iterator->power;
                iterator->power = power;
            }
            temp = temp->next;
           
        }
        iterator =iterator->next;
    }
    deleteDuplicates(head);
    
}



Node* makeExpression(Node *head)
{
    int data;
    int power;
    while (1)
    {
        printf("Enter the value or press 0 to exit: ");
        scanf("%d", &data);
        if (data == 0)
        {
            sortList(head);
            return head;
        }
        
        printf("Enter the Power: ");
        scanf("%d",&power);

        head = insertFrontSingly(head,data,power); 
    }
}

void addPolynomials(Node* head1, Node* head2, Node* head3)
{
    Node* iterator1 = head1;
    Node* iterator2 = head2;

    while (iterator1 != NULL && iterator2 != NULL)
    {
        if (iterator1->power == iterator2->power)
        {
            head3 = insertFrontSingly(head3,iterator1->data + iterator2->data, iterator1->power);
            iterator1 = iterator1->next;
            iterator2 = iterator2->next;
        }

        else if (iterator1->power > iterator2->power)
        {
            head3 = insertFrontSingly(head3,iterator1->data,iterator1->power);
            iterator1 = iterator1->next;
        }

        else if (iterator2->power > iterator1->power)
        {
            head3 = insertFrontSingly(head3,iterator2->data,iterator2->power);
            iterator2 = iterator2->next;
        }
    }

    while (iterator1 != NULL)
    {
        head3 = insertFrontSingly(head3,iterator1->data,iterator1->power);
        iterator1 = iterator1->next;
    }

    while (iterator2 != NULL)
    {
        head3 = insertFrontSingly(head3,iterator2->data,iterator2->power);
        iterator2 = iterator2->next;
    }

    printf("=======================Resultant Expression is============================\n");
    displaySingly(head3);
    
    
    
}
int main(int argc, char const *argv[])
{
    Node *head1 = NULL;
    Node *head2 = NULL;
    Node *resultantHead = NULL;
    printf("----------------Entering First Expression---------------\n");
    head1 = makeExpression(head1);
    printf("----------------Entering Second Expression---------------\n");
    head2 = makeExpression(head2);
    addPolynomials(head1,head2,resultantHead);
    getch();
    return 0;
}
