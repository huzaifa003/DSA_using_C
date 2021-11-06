#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;
/*
    *
    * To make multiple linked lists out of a single structure and set of methods we can declare multiple heads of same type.
    * To ensure that each function knows the list it's acting upon we need to pass heads of each list as an argument to function.
    * 
    * FAQ:
    *   Why do we need to return head if we are using pointers?
    *       A: Cause we are changing the value of address variable itself. I.E head = (Node *)malloc(sizeof(Node)); here the value of head is not being modified but the address of head itself is modified thus we need to return it or use double pointers
    * 
    *   Why can't we use Global variable?
    *       A: Turns out we CAN but then we 'd have to make each function specific to each global variable or again pass heads as arguments.
    *   
    *   Double Pointer vs Single Pointer vs Global Variable
    *       Double pointer won't need return. (Not Recommended for beginners)
    *       Single pointer needs return.
    *       Global variable needs neither but needs seperate functions or conditions to specify the value (NOT RECOMMENDED)
    * 
*/

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

Node* insertFrontSingly(Node *head, int data)
{
    if (head == NULL) //for first element
    {
        head = (Node *)malloc(sizeof(Node)); //making a new node
        head->data = data;                   //inserting data
        head->next = NULL;
    }   
    else
    {
        Node *iterator = head; //iterating till empty node is found
        Node *newNode = (Node *)malloc(sizeof(Node));
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



Node* insertBackSingly(Node *head, int data)
{
    if (head == NULL) //for first element
    {
        head = (Node *)malloc(sizeof(Node)); //making a new node
        head->data = data;                   //inserting data
        head->next = NULL;
    }
    else
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = data;
        newNode->next = head;

        head = newNode; //changing head to first pointer again
    }
    return head;

}
Node* insertAtSingly(Node* head, int data, int index)
{
    if (index > getLength(head))
    {
        printf("\n-----------Index overflow-------------\n");
        return NULL;
    }

    else if (index == 0)
    {
        head = insertBackSingly(head,data);
    }
    else if (index == getLength(head))
    {
        head = insertFrontSingly(head,data);
    }
    else
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = data;
        Node *iterator = head;

        for (int i = 1; i < index - 1; i++)
        {
            iterator = iterator->next;
        }
        newNode->next = iterator->next;
        iterator->next = newNode;
    }
    return head;
}
void displaySingly(Node *head)
{
    printf("-------------------------------------\n");
    Node *iterator = head;
    while (iterator != NULL)
    {
        printf("Data is %d\n", iterator->data); //display data at each node till its null
        iterator = iterator->next;
    }
    printf("-------------------------------------\n");
}

Node* deleteFirstSingly(Node* head)
{
    Node *temp = head;
    if (head != NULL) //changing head
    {
        head = head->next;
        return head;
    }
    else
    {
        return NULL;
    }
}

Node* deleteLastSingly(Node *head)
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
        return head;
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
        return head;
    }
}

Node* deleteAtSingly(Node *head, int index)
{
    if (index >= getLength(head))
    {
        printf("\n-----------Index overflow-------------\n");
        return NULL;
    }

    else if (index == 0)
    {
        int data = head->data;
        head = head->next;
        return head;
    }

    Node *iterator = head;
    {
        
        
        for (int i = 1; i <= index - 1; i++)
        {
            iterator = iterator->next;
        }
        Node *temp = iterator->next;
        iterator->next = iterator->next->next;
        if (index == 5)
        {
            printf("Hello\n");
            printf("Temp datais = %d\n",iterator->next->next->data);
        }
        
        return head;
    }
}

int main()
{

    Node* head = NULL;
    head = insertFrontSingly(head,65);
    head = insertBackSingly(head,34);
    displaySingly(head);
    
    head = insertFrontSingly(head , 4);
    head = insertBackSingly(head , 5);
    displaySingly(head);
    printf("Length for first display after inserting at front and back =  %d\n",getLength(head));

    head = deleteFirstSingly(head);
    displaySingly(head);
    printf("Length after first deletion from start  =  %d\n",getLength(head));

    head = deleteFirstSingly(head);
    displaySingly(head);
    printf("Length after second deletion from start  =  %d\n",getLength(head));

    head = insertFrontSingly(head , 4);
    head = insertFrontSingly(head , 5);
    displaySingly(head);
    printf("Length for second display after inserting two at front  =  %d\n",getLength(head));

    head = deleteLastSingly(head);
    displaySingly(head);
    printf("Length after third deletion from last  =  %d\n",getLength(head));

    head = deleteLastSingly(head);
    displaySingly(head);
    printf("Length after fourth deletion from last  =  %d\n",getLength(head));

    head = insertBackSingly(head,4);
    head = insertBackSingly(head,5);
    head = insertBackSingly(head,6);
    head = insertBackSingly(head,7);
    head = insertBackSingly(head,8);
    displaySingly(head);

    printf("Length for last display after inserting at back (like stack) =  %d\n",getLength(head));
    printf("-------------------------------------\n");
    
    head = deleteAtSingly(head,3);
    printf("Element Deleted at Index %d\n",3);
    displaySingly(head);
    getch();
    return 0;
}
