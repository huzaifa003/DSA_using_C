#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
typedef struct trieNode
{
    int inWord;                 //representing end of the word
    struct trieNode *child[26]; //each index represents an english char

} trieNode;

trieNode *root;

int getIndex(char c)
{
    if (c >= 'a' && c <= 'z')
        return (int)c - 'a';
    else
        return (int)c - 'A';
}

void insertTrie(char str[])
{
    trieNode *temp = root;
    for (int i = 0; i < strlen(str); i++)
    {

        if (temp->child[getIndex(str[i])] == NULL)
        {

            trieNode *newNode = (trieNode *)malloc(sizeof(trieNode));
            newNode->inWord = 0;
            for (int i = 0; i < 26; i++)
            {
                newNode->child[i] = NULL;
            }
            temp->child[getIndex(str[i])] = newNode;
        }

        temp = temp->child[getIndex(str[i])];
    }

    temp->inWord = 1; //current word is completed
}

int trieContains(char *str)
{
    trieNode *temp = root;
    if (temp == NULL)
    {
        printf("\n------------TRIE IS EMPTY------------\n");
        return 0;
    }
    for (int i = 0; i < strlen(str); i++)
    {
        if (temp->child[getIndex(str[i])] == NULL)
        {
            return 0;
        }

        else
        {
            temp = temp->child[getIndex(str[i])];
        }
    }

    return temp->inWord; // will return 1 if words end here this is for words that are a subwords for other words like daddy contains the word dad but that doesn't mean that user has necessarily entered it.
}

int hasChildren(trieNode *temp)
{
    for (int i = 0; i < 26; i++)
    {
        if (temp->child[i] != NULL)
        {
            return 1;
        }
    }
    return 0;
}

int deleteTrie(trieNode **temp, int i, char *str)
{

    if (*temp == NULL)
    {
        return 0;
    }

    if (i < strlen(str))
    {
        // recur for the node corresponding to the next character in
        // the string and if it returns 1, delete the current node
        // (if it is non-leaf)

        if (*temp != NULL && (*(temp))->child[getIndex(str[i])] != NULL && deleteTrie(&((*temp))->child[getIndex(str[i])], i + 1, str) && (*(temp))->inWord == 0) //inword shouldn't be 1 until string is completely traversed, *temp and it's child should also not be null as string is on going, delete trie is recursive call to reach end of string first
        {
            if (!hasChildren(*temp))
            {
                free(*temp);
                (*temp) = NULL;
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }

    if (i == strlen(str) && (*(temp))->inWord == 1) //at end word should be 1 as it represents terminating char
    {
        // if the current node is a leaf node and doesn't have any children
        if (!hasChildren(*temp))
        {
            free(*temp); // delete the current node
            (*temp) = NULL;
            return 1; // delete the non-leaf parent nodes
        }

        // if the current node is a leaf node and has children
        else
        {
            // mark the current node as a non-leaf node (DON'T DELETE IT)
            (*(temp))->inWord = 0;
            return 0; // don't delete its parent nodes
        }
    }
}

int checkForDeletion(char *str)
{
    if (trieContains(str))
    {
        deleteTrie(&root, 0, str);
        return 1;
    }
    else
    {
        printf("\n-------------This does not exist---------------\n");
        return 0;
    }
}

trieNode *getPrefixNode(char *prefix)
{
    trieNode *temp = root;
    if (strcmp(prefix,"") == 0)
    {
        return root;
    }
    for (int i = 0; i < strlen(prefix); i++)
    {
        if (temp->child[getIndex(prefix[i])] == NULL)
        {
            printf("The index is = %d",getIndex(prefix[i]));
            printf("\n------------------This Prefix Doens't exist---------------\n");
            getch();
            return NULL;
        }

        temp = temp->child[getIndex(prefix[i])];
    }

    return temp;
}



void addAllWordsTry(trieNode *temp, int index, char* prefix, int flag )
{
    if (flag == 1)
    {
        printf("%s",prefix);
        flag = 0;
    }
    if (temp->inWord == 1)
    {
        printf("\n%s",prefix);
        return;
    }

    for (int index = 0; index < 26; index++)
    {
        if (temp->child[index] != NULL)
        {
            printf("%c", index + 'a');
            addAllWordsTry(temp->child[index], index, prefix, flag);
            
        }
    }
}

void getSearchSuggestions(char* prefix)
{
    addAllWordsTry(getPrefixNode(prefix),0,prefix,1);
    printf("\r                   \n"); //erarsing last line of added prefix
}
int main(int argc, char const *argv[])
{
    root = (trieNode *)malloc(sizeof(trieNode)); //creating the start of trie
    root->inWord = 0;
    for (int i = 0; i < 26; i++)
    {
        root->child[i] = NULL;
    }
    insertTrie("Daddy");
    insertTrie("Dab");
    insertTrie("Dare");
    insertTrie("Heli");
    insertTrie("Mom");
    insertTrie("Mad");

    printf("The word %s is in trie %d\n", "Daddy", trieContains("Daddy"));
    printf("The word %s is in trie %d\n", "Dab", trieContains("Dab"));
    printf("The word %s is in trie %d\n", "Mom", trieContains("Mom"));
    printf("The word %s is in trie %d\n", "Meow", trieContains("Meow"));
    printf("The word %s is in trie %d\n", "Meow", trieContains("Meow"));

    printf("The Word %s is deleted from trie %d\n", "Mad", checkForDeletion("Mad"));

    printf("The word %s is in trie %d\n", "Mad", trieContains("Mad"));

    getSearchSuggestions("da"); //get predictions here it wil give all the words starting with da


    getch();
    return 0;
}
