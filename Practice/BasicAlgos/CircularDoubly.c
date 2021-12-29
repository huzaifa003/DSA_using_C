#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct CircularDoubly
{
    int data;
    struct CircularDoubly *next;
    struct CircularDoubly *prev;
} CircularDoubly;

CircularDoubly *insertAtStart(CircularDoubly *list, int data)
{
    CircularDoubly *node = malloc(sizeof(CircularDoubly));
    node->data = data;
    if (list == NULL)
    {
        list = node;
        list->next = list;
        list->prev = list;
    }
    else
    {
        CircularDoubly *temp = list;
        while (temp->next != list)
        {
            temp = temp->next;
        }
        node->next = list;
        list->prev = node;
        temp->next = node;
        node->prev = temp;
        list = node;
    }
    return list;
}

CircularDoubly *insertAtEnd(CircularDoubly *list, int data)
{
    CircularDoubly *node = malloc(sizeof(CircularDoubly));
    node->data = data;
    if (list == NULL)
    {
        list = node;
        list->next = list;
        list->prev = list;
    }
    else
    {
        CircularDoubly *temp = list;
        while (temp->next != list)
        {
            temp = temp->next;
        }
        node->next = list;
        list->prev = node;
        temp->next = node;
        node->prev = temp;
    }
    return list;
}

void display(CircularDoubly *list)
{
    CircularDoubly *temp = list;
    while (temp->next != list)
    {
        printf("Data is =%d\n", temp->data);
        temp = temp->next;
    }
    printf("Data is =%d\n", temp->data);
}
int main()
{
    CircularDoubly *list = NULL;
    list = insertAtStart(list, 1);
    list = insertAtStart(list, 2);
    list = insertAtStart(list, 3);
    list = insertAtStart(list, 4);
    list = insertAtEnd(list,5);
    list = insertAtEnd(list,6);
    list = insertAtEnd(list,7);
    list = insertAtEnd(list,8);
    display(list);
    getch();
    return 0;
}