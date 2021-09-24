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

    int freq[26] = {0};                  //intialzing local frequency array
    for (int i = 0; arr[i] != '\0'; i++) //running loop till escape character is reached
    {
        char lowerCase = toLowerCase(arr[i]); //getting lower case of each character to make sure same case because frequency doesn't take case into account

        //----if the character is an alphabat then place it on it's index by getting index using ASCII value in the getIndexLowerCase() function----
        if (lowerCase >= 'a' && lowerCase <= 'z')
        {
            freq[getIndexLowerCase(lowerCase)]++;
        }
    }

    displayFrequency(freq); //displaying frequency table
}

char *changeCase(char arr[])
{
    for (int i = 0; arr[i] != '\0'; i++) //looping till escape char
    {
        char lowerCase = toLowerCase(arr[i]); //getting lowercase of alphabat

        //if the value was already lower case then we change it to upper case otherwise we assign it to current array
        if (lowerCase == arr[i])
        {
            arr[i] = toUpperCase(arr[i]); //changing to uppercase & assigning incase it was already lowerCase
        }
        else
        {
            arr[i] = lowerCase; //if it was lowercase then assigning it back
        }
    }
    return arr;
}

char toLowerCase(char c) //changes uppercase to lowercase
{
    if (c >= 'A' && c <= 'Z') //if letter is an uppercase letter only then
    {
        return (char)((int)c + 32); //changing it to uppercase using ascii value
    }

    else //if it's not an uppercase alphabat then returning the same alphabat
    {
        return c;
    }
}

char toUpperCase(char c) //changes lowercase to uppercase
{
    if (c >= 'a' && c <= 'z')
    {
        return (char)((int)c - 32); //returns uppercase only if it was lowercase
    }

    else
    {
        return c; //returning same character if it was not uppercase alphabat
    }
}

int getIndexLowerCase(char c) //finding index using character value lowercase
{
    //--This function assigns 0th index to 'a' by subtracting 'a' ascii value (97) from character given  and so on
    if (c >= 'a' && c <= 'z')
    {
        return (int)c - 'a'; //if given letter is lowercase alphabat return the index
    }
    else
    {
        return -1; //return -1 (wrong index) if it's not a lowercase alphabat
    }
}

void displayFrequency(int freq[])
{
    printf("\n----Frequency Table---------");
    for (int i = 0; i < 26; i++) //26 for 26 alphabats
    {
        printf("\nLetter '%c' has frequency of %d\n", (char)i + 'a', freq[i]); //printing by reversing the formula of getting index and getting character by using index and printing freq array values besides it
    }
    printf("----------------------------\n");
}