#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
//----Task Functions-----
void calculateFrequency(char arr[]);
char *changeCase(char arr[]);

//----Small task Functions----
char toUpperCase(char c);
char toLowerCase(char c);
int getIndexLowerCase(char c);

//-----Display Function-----
void displayFrequency(int freq[]);

int main()
{
    //variables declaration
    char arr[30];
    char choice;

    while (1)
    {

        fflush(stdin); //flushing buffer for to make sure gets() takes input every time
        
        //--------Menu And User choice--------
        printf("\nPress 1 to Calculate Frequency\nPress 2 to change case\nPress any other key to exit\n"); 
        choice = getche();
        switch (choice)
        {
        //---Calling apt functions according to user choice and getting user input----
        case '1':
            printf("\nEnter the String: ");
            gets(arr);
            calculateFrequency(arr);
            break;

        case '2':
            printf("\nEnter the String: ");
            gets(arr);
            printf("\nChanged case is = %s\n", changeCase(arr));
            break;

        default:
            return 1; //for exiting 
            break;
        }
    }

    getch();
    return 0;
}

void calculateFrequency(char arr[]) //to calculate frequency of each alphabat in a string which is character array
{
    //------This works by storing frequency of each alphabat into an array where 0th index represents 'a' and so on------

    int freq[26] = {0}; //intialzing local frequency array 
    for (int i = 0; arr[i] != '\0'; i++) //running loop till escape character is reached
    {
        char lowerCase = toLowerCase(arr[i]); //getting lower case of each character to make sure same case because frequency doesn't take case into account

        if (lowerCase >= 'a' && lowerCase <= 'z')
        {
            freq[getIndexLowerCase(lowerCase)]++;
        }
    }

    displayFrequency(freq);
}

char *changeCase(char arr[])
{
    for (int i = 0; arr[i] != '\0'; i++)
    {
        char lowerCase = toLowerCase(arr[i]);
        if (lowerCase == arr[i])
        {
            arr[i] = toUpperCase(arr[i]);
        }
        else
        {
            arr[i] = lowerCase;
        }
    }
    return arr;
}

char toLowerCase(char c)
{
    if (c >= 'A' && c <= 'Z')
    {
        return (char)((int)c + 32);
    }

    else
    {
        return c;
    }
}

char toUpperCase(char c)
{
    if (c >= 'a' && c <= 'z')
    {
        return (char)((int)c - 32);
    }

    else
    {
        return c;
    }
}

int getIndexLowerCase(char c)
{
    if (c >= 'a' && c <= 'z')
    {
        return (int)c - 'a';
    }
    else
    {
        return -1;
    }
}

void displayFrequency(int freq[])
{
    printf("\n----Frequency Table---------");
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] != 0)
        {
            printf("\nLetter '%c' has frequency of %d\n", (char)i + 'a', freq[i]);
        }
    }
    printf("----------------------------\n");
}