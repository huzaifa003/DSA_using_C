#include <stdio.h>
#include <conio.h>
#include "StackArrayInt.h"
#include <stdlib.h>
int binaryToDecimal(char binary[]);
int power(int number, int power);
int main() {

    char binary[50];
    printf("Enter the Binary Number");
    gets(binary);
    printf("Decimal Result is = %d",binaryToDecimal(binary));
    getch();
    return 0;
}

int binaryToDecimal(char binary[])
{
    StackArrayInt stack;
    stack.top = -1;
    int base = 0;
    int result  = 0;
    for (int i = 0; binary[i] != '\0'; i++)
    {
        if (binary[i] != '0' && binary[i] != '1')
        {
            printf("Illegal Binary Expression");
            return -1;
        }
        
        pushIntStack(&stack,binary[i] - '0');
   
    }
    while (!isEmptyIntStack(&stack))
    {
        result = result + (power(2,base) * popIntStack(&stack));
        base++;
    }

    return result;
       
    
}

int power(int number, int power)
{
    int temp = number;
    for (int i = 1; i < power; i++)
    {
        number = number*temp;
    }

    return number;
    
}