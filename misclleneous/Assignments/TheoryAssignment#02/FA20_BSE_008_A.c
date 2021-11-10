#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    int power;
    struct Node *next;
} Node;

int getLength(Node *head)
{
    Node *temp = head;
    int i;
    for (i = 0; temp != NULL; i++)
    {
        temp = temp->next;
    }
    return i;
}

int isEmptySingly(Node *head)
{
    return getLength(head) == 0;
}

Node *insertFrontSingly(Node *head, int data, int power)
{
    if (head == NULL) //for first element
    {
        head = (Node *)malloc(sizeof(Node)); //making a new node
        head->data = data;                   //inserting data
        head->power = power;
        head->next = NULL;
    }
    else
    {
        Node *iterator = head; //iterating till empty node is found
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->power = power;
        newNode->data = data;
        newNode->next = NULL;

        while (iterator->next != NULL)
        {
            iterator = iterator->next;
        }
        iterator->next = newNode; //adding node at end
    }
    return head;
}

Node *insertBackSingly(Node *head, int data, int power)
{
    if (head == NULL) //for first element
    {
        head = (Node *)malloc(sizeof(Node)); //making a new node
        head->data = data;                   //inserting data
        head->power = power;
        head->next = NULL;
        return head;
    }
    else
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = data;
        newNode->next = head;
        newNode->power = power;
        head = newNode; //changing head to first pointer again
    }
    return head;
}

void displaySingly(Node *head)
{
    printf("---------------------------------\n");
    Node *iterator = head;
    while (iterator != NULL)
    {
        if (iterator->data >= 0)
        {
            printf("+%dx^%d", iterator->data, iterator->power);
        }
        else
        {
            printf("%dx^%d", iterator->data, iterator->power); //display data at each node till its null
        }
        iterator = iterator->next;
    }
    printf("\n-------------------------------------\n");
}

int deleteFirstSingly(Node *head)
{
    Node *temp = head;
    if (head != NULL) //changing head
    {
        head = head->next;
        return temp->data;
    }
    else
    {
        return NULL;
    }
}

int deleteLastSingly(Node *head)
{
    Node *iterator = head;
    if (head == NULL)
    {
        return NULL;
    }

    if (iterator->next == NULL) //for a single element aka only head
    {
        head = NULL;
        free(head); //freeing memory
        return iterator->data;
    }
    else
    {

        while (iterator->next->next != NULL) //iterating for multiple elements
        {
            iterator = iterator->next;
        }
        Node *temp = iterator->next;
        iterator->next = NULL;
        free(iterator->next);
        return temp->data;
    }
}

int deleteAtSingly(Node *head, int index)
{
    if (index >= getLength(head))
    {
        printf("\n-----------Index overflow-------------\n");
        return -1;
    }

    Node *iterator = head;
    {
        for (int i = 1; i < index - 1; i++)
        {
            iterator = iterator->next;
        }
        Node *temp = iterator->next;
        iterator->next = iterator->next->next;
        return temp->data;
    }
}

void deleteDuplicates(Node *head)
{
    Node *iterator = head;
    while (iterator != NULL)
    {

        Node *temp = iterator;
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

void sortList(Node *head)
{
    Node *iterator = head;
    Node *temp;
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
        iterator = iterator->next;
    }
    deleteDuplicates(head);
}

Node *makeExpression(Node *head)
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
        scanf("%d", &power);

        head = insertFrontSingly(head, data, power);
    }
}

void addPolynomials(Node *head1, Node *head2, Node *head3)
{
    Node *iterator1 = head1;
    Node *iterator2 = head2;

    while (iterator1 != NULL && iterator2 != NULL)
    {
        if (iterator1->power == iterator2->power)
        {
            head3 = insertFrontSingly(head3, iterator1->data + iterator2->data, iterator1->power);
            iterator1 = iterator1->next;
            iterator2 = iterator2->next;
        }

        else if (iterator1->power > iterator2->power)
        {
            head3 = insertFrontSingly(head3, iterator1->data, iterator1->power);
            iterator1 = iterator1->next;
        }

        else if (iterator2->power > iterator1->power)
        {
            head3 = insertFrontSingly(head3, iterator2->data, iterator2->power);
            iterator2 = iterator2->next;
        }
    }

    while (iterator1 != NULL)
    {
        head3 = insertFrontSingly(head3, iterator1->data, iterator1->power);
        iterator1 = iterator1->next;
    }

    while (iterator2 != NULL)
    {
        head3 = insertFrontSingly(head3, iterator2->data, iterator2->power);
        iterator2 = iterator2->next;
    }

    displaySingly(head3);
}

void subPolynomials(Node *head1, Node *head2, Node *head3)
{
    Node *iterator1 = head1;
    Node *iterator2 = head2;

    Node *temp = head2;
    while (temp != NULL)
    {
        temp->data = -1 * temp->data;
        temp = temp->next;
    }

    addPolynomials(head1, head2, head3);
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

    int choice;
    while (1)
    {
        printf("\nPress 1 to add polynomials");
        printf("\nPress 2 to subtract polynomials");
        printf("\nPress 3 to re-enter expressions");
        printf("\nPress Any Other Key To Exit");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("\n==========Expression 1=================\n");
            displaySingly(head1);

            printf("\n==========Expression 2=================\n");
            displaySingly(head2);

            printf("=======================Resultant Addition Expression is============================\n");
            addPolynomials(head1, head2, resultantHead);
            resultantHead = NULL;
        }

        else if (choice == 2)
        {
            printf("\n==========Expression 1=================\n");
            displaySingly(head1);

            printf("\n==========Expression 2=================\n");
            displaySingly(head2);

            printf("=======================Resultant Subtraction Expression is============================\n");
            subPolynomials(head1, head2, resultantHead);
            resultantHead = NULL;
        }

        else if (choice == 3)
        {
            head1 = NULL;
            head2 = NULL;
            printf("----------------Entering First Expression---------------\n");
            head1 = makeExpression(head1);
            printf("----------------Entering Second Expression---------------\n");
            head2 = makeExpression(head2);
        }

        else
        {
            printf("========Program Exited==========");
            break;
        }
    }

    getch();
    return 0;
}
