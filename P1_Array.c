#include <stdio.h>
void main()
{
    int array[3][3];
    int i, j, k, sum;
    int transpose[3][3];
    int temp_matrix[3][3];
    int add_matrix[3][3];
    int multi_matrix[3][3];
    printf("Enter matrix elements: ");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            scanf("%d", &array[i][j]);
        }
    }
    int option;
    while (1)
    {
        printf("\nEnter 1 for printing matrix\nEnter 2 for printing matrix Row-wise\nEnter 3 for printing matrix Column-wise\nEnter 4 for finding transpose\nEnter 5 for matrix addition\nEnter 6 for matrix multiplication\nEnter your choice: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1: // Printing Matrix
            for (i = 0; i < 3; i++)
            {
                for (j = 0; j < 3; j++)
                {
                    printf("%d\t", array[i][j]);
                }
                printf("\n");
            }
            break;
        case 2: // Row-wise
            for (i = 0; i < 3; i++)
            {
                for (j = 0; j < 3; j++)
                {
                    printf("%d ", array[i][j]);
                }
            }
            break;
        case 3: // Column-wise
            for (i = 0; i < 3; i++)
            {
                for (j = 0; j < 3; j++)
                {
                    printf("%d\n", array[j][i]);
                }
            }
            break;
        case 4: // Transpose
            for (i = 0; i < 3; i++)
            {
                for (j = 0; j < 3; j++)
                {
                    transpose[i][j] = array[j][i];
                }
            }
            for (i = 0; i < 3; i++)
            {
                for (j = 0; j < 3; j++)
                {
                    printf("%d\t", transpose[i][j]);
                }
                printf("\n");
            }
            break;
        case 5: // Addition
            printf("Enter new matrix for addition: ");
            for (i = 0; i < 3; i++)
            {
                for (j = 0; j < 3; j++)
                {
                    scanf("%d", &temp_matrix[i][j]);
                }
            }
            for (i = 0; i < 3; i++)
            {
                for (j = 0; j < 3; j++)
                {
                    add_matrix[i][j] = array[i][j] +
                                       temp_matrix[i][j];
                }
            }
            printf("Addition matrix:\n");
            for (i = 0; i < 3; i++)
            {
                for (j = 0; j < 3; j++)
                {
                    printf("%d\t", add_matrix[i][j]);
                }
                printf("\n");
            }
            break;
        case 6:
            printf("Enter new matrix for multiplication: ");
            for (i = 0; i < 3; i++)
            {
                for (j = 0; j < 3; j++)
                {
                    scanf("%d", &temp_matrix[i][j]);
                }
            }
            for (i = 0; i < 3; i++)
            {
                for (j = 0; j < 3; j++)
                {
                    sum = 0;
                    for (k = 0; k < 3; k++)
                    {
                        sum = sum + array[i][k] * temp_matrix[k][j];
                    }
                    multi_matrix[i][j] = sum;
                }
            }
            printf("Multiplicaton matrix:\n");
            for (i = 0; i < 3; i++)
            {
                for (j = 0; j < 3; j++)
                {
                    printf("%d\t", multi_matrix[i][j]);
                }
                printf("\n");
            }
            break;
        default:
            return;
        }
    }
}