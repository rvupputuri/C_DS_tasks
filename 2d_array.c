#include <stdio.h>
int main()
{
    int row1, row2, column1, column2, i = 0, j = 0, k = 0;
    int matrix1[row1][column1], matrix2[row2][column2], mul[row1][column2];
    printf("Enter number of rows for First Matrix:\n");
    scanf("%d", &row1);
    printf("Enter number of columns for First Matrix:\n");
    scanf("%d", &column1);
    printf("Enter number of rows for Second Matrix:\n");
    scanf("%d", &row2);
    printf("Enter number of columns for Second Matrix:\n");
    scanf("%d", &column2);
    if (column1 != row2)
    {
        printf("Matrices Can't be multiplied\n");
    }
    else
    {
        printf("Enter first matrix elements \n");
        for (i = 0; i < row1; i++)
        {
            for (j = 0; j < column1; j++)
            {
                scanf("%d", &matrix1[i][j]);
            }
        }
        printf("Enter Second matrix elements\n");
        for (i = 0; i < row2; i++)
        {
            for (j = 0; j < column2; j++)
            {
                scanf("%d", &matrix2[i][j]);
            }
        }
        for (i = 0; i < row1; i++)
        {
            for (j = 0; j < column2; j++)
            {
                mul[i][j] = 0;
                for (k = 0; k < column1; k++)
                {
                    mul[i][j] += matrix1[i][k] * matrix2[k][j];
                }
            }
        }
        printf("Multiplied matrix\n");
        for (i = 0; i < row1; i++)
        {
            for (j = 0; j < column2; j++)
            {
                printf("%d\t", mul[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}