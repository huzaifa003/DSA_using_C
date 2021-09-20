#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

/*
Two-D arrays are made using Row First order 
first all rows are stored and then their columns
There are multiple approaches to do this
Create an array of pointers and allocate memory to each one
Use Double pointer and point it to columns (USED BELOW)
Use Two Pointers and Point Row ** Pointer to each Column Pointer *
*/
int main() {

    int rows = 0; int columns = 0;
    printf("Please Enter the number of rows you want to enter : ");
    scanf("%d",&rows);
    printf("Please Enter the number of columns you want to enter : ");
    scanf("%d",&columns);
    int** ptrRow = (int** ) calloc(rows,sizeof(int*)); //making rows

 
    for (int i = 0; i < rows; i++)
    {
        ptrRow[i] = (int *) calloc(columns, sizeof(int)); //Making arrays of arrays pointing rows to columns
        //this means that each row points to additional set of columns
    }

    
    

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("Enter the value of rows and columns :  ");
            scanf("%d",*(ptrRow+i) + j); //Same formula as &ptrRow[i][j]
        }
        
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("\nvalue of rows and columns[%d][%d] : %d ",i,j, *(*(ptrRow+i) + j)); //same Formula of ptrRow[i][j]
        }
        
    }
    getch();

    return 0;
}