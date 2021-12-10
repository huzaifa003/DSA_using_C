#include <stdio.h>
#include <conio.h>
#define SIZE 10 
typedef struct HashTableNode
{
    char key[15];
    int value;
    struct HashTableNode* next ; //10%10 = 0
    //4500%10 = 0
} HashTableNode;

int* arr[10];

HashTableNode* hashTable[SIZE] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL}; //used for reducing space complexity for pointers.
int hashCode(char key[])
{
    return strlen(key)%SIZE;
}


void insertHash(char key[], int value)
{
    HashTableNode* newNode = (HashTableNode*) malloc(sizeof(HashTableNode));
    strcpy(newNode->key,key);
    newNode->value = value;
    newNode->next = NULL;

    int index = hashCode(key);
    if (hashTable[index] == NULL)
    {
        hashTable[index] = newNode;
    }

    else
    {
        
        if (strcmp(key,hashTable[index]->key)== 0) //if key exists in head 
            {
                printf("\n-------This key \"%s\" already exists so only replacing the value----\n",key);
                hashTable[index] = newNode;
                return;
            }
        HashTableNode* temp = hashTable[index];
        while (temp->next != NULL) //if key exists in chaining
        {
            printf("Key is = %s\n",key);
            if (strcmp(key,temp->key)== 0)
            {
                printf("\n-------This key \"%s\" already exists, so only replacing the value----\n",key);
                temp = newNode;
                return;
            }
            temp = temp->next;
        }

        temp->next = newNode;
    }
    
}

HashTableNode* searchHash(char key[])
{
    int index = hashCode(key);
    
    if (hashTable[index] == NULL)
    {
        printf("\n------------KEY \"%s\" DOESN'T EXIST-------------\n",key);
        return NULL;
    }

    else
    {
        HashTableNode* temp = hashTable[index];
        while (strcmp(temp->key,key) != 0 & temp != NULL)
        {
            temp = temp->next;
        }

        if (temp == NULL)
        {
            printf("\n-----------------Key \"%s\" still doesn't exist--------------\n",key); //IF KEY DOESN'T EXIST IN CHAINING EITHER
        }

        return temp;
        
    }
}

void printSearchedValue(HashTableNode* temp) //for managing NULL
{
    if (temp != NULL)
    {
        printf("Searched stuff is = %d\n",temp->value); 
    }
}


int main(int argc, char const *argv[])
{
    
    insertHash("Hello",1);
    insertHash("Hello",2);
    insertHash("World",5);
    
    printSearchedValue(searchHash("Hello"));
    printSearchedValue(searchHash("World"));
    printSearchedValue(searchHash("Meow"));
    getch();
    return 0;
}
