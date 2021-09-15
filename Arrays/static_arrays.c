#include <stdio.h>
#include <conio.h>
/*
arrays are consecutive memory locations in c.
there can be 1d-2d-3d-4d arrays statically allocated.
*/

void separator()
{
    printf("-----------------------------------\n");
}
int main()
{

    //-----------------1D ARRAY-------------------

    int arr1[4];
    for (int i = 0; i < 4; i++)
    {
        arr1[i] = i;
        printf("1D Array arr1[%d] = %d\n", i, arr1[i]);
    }
    separator();
    //-----------------2D Array--------------------
    int arr2[2][4] = //2rows 4 columns
        {
            {1, 2, 3, 4},
            {5, 6, 7, 8},

        };
    for (int i = 0; i < 2; i++)
    {

        for (int j = 0; j < 4; j++)
        {
            printf("2D Array arr2[%d][%d] = %d || ", i, j, arr2[i][j]);
        }
        printf("\n");
    }
    separator();
    int arr3[2][3][4] = //2 rows 3 columns 4 elements per se
        {
            {   {0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11}  },
            {   {12, 13, 14, 15}, {16, 17, 18, 19}, {20, 21, 22, 23}   }
        };
    for (int i = 0; i < 2; i++)
    {

        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                printf("3D Array arr3[%d][%d][%d] = %d || ", i, j,k, arr3[i][j][k]);
            }
            printf("\n");
            
        }
    }

    separator();

    //similarly we can use N-D Arrays but they become too much complex :(
    return 0;
}