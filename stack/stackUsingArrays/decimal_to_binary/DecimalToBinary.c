#include <stdio.h>
#include <conio.h>
#include "StackArrayInt.h"
#include <stdlib.h>

int decimalToBinary(int number, int binary[]);
int main() {

    int number;
    printf("Enter the Decimal Number");
    scanf("%d",&number);
    int binary[50];
    int range = decimalToBinary(number,binary);
    for (int i = 0; i < range; i++)
    {
        printf("%d",binary[i]);
    }
    getch();
    return 0;
}

int decimalToBinary(int number, int binary[])
{
    StackArrayInt stack;
    stack.top = -1;
    while (number != 0)
    {
        pushIntStack(&stack,number%2);
        number = number / 2;

    }
    displayIntStack(&stack);
    int i = 0;
    while (!isEmptyIntStack(&stack))
    {
        binary[i] = popIntStack(&stack);
        i++;
    }
    
    return i;
}