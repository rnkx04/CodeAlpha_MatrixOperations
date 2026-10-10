#include<stdio.h>

#define SIZE 2
int inputMatrix(int matrix[SIZE][SIZE], char name)
{
    printf("\nEnter elements of Matrix %c:\n", name);
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("Enter element [%d][%d]: ", i, j);

            if (scanf("%d", &matrix[i][j]) != 1)
            {
                printf("Invalid input!\n");
                return 1;
            }
        }
    }
}
void display(int matrix[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}
void addition(int A[SIZE][SIZE],
              int B[SIZE][SIZE],
              int result[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}
void subtraction(int A[SIZE][SIZE],
                 int B[SIZE][SIZE],
                 int result[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
}
void multiplication(int A[SIZE][SIZE],
                    int B[SIZE][SIZE],
                    int result[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            result[i][j] = 0;

            for (int k = 0; k < SIZE; k++)
            {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}
void transpose(int A[SIZE][SIZE],
               int result[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            result[j][i] = A[i][j];
        }
    }
}

int main()
{
    int A[SIZE][SIZE], B[SIZE][SIZE];
    int result[SIZE][SIZE];
    int choice;

    printf("=================================\n");
    printf("   CodeAlpha Matrix Operations\n");
    printf("=================================\n");

    inputMatrix(A, 'A');
    inputMatrix(B, 'B');

    while (1)
    {
        printf("\n========== MAIN MENU ==========\n");
        printf("1. Display Matrices\n");
        printf("2. Matrix Addition (A + B)\n");
        printf("3. Matrix Subtraction (A - B)\n");
        printf("4. Matrix Multiplication (A x B)\n");
        printf("5. Transpose of Matrix A\n");
        printf("6. Transpose of Matrix B\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input! Please enter a number.\n");
            return 1;
        }

        switch (choice)
        {
            case 1:
                printf("\nMatrix A:\n");
                display(A);

                printf("\nMatrix B:\n");
                display(B);
                break;

            case 2:
                addition(A, B, result);
                printf("\nResult of A + B:\n");
                display(result);
                break;

            case 3:
                subtraction(A, B, result);
                printf("\nResult of A - B:\n");
                display(result);
                break;

            case 4:
                multiplication(A, B, result);
                printf("\nResult of A x B:\n");
                display(result);
                break;

            case 5:
                transpose(A, result);
                printf("\nTranspose of Matrix A:\n");
                display(result);
                break;

            case 6:
                transpose(B, result);
                printf("\nTranspose of Matrix B:\n");
                display(result);
                break;

            case 0:
                printf("\nCalculator closed. Thank you!\n");
                return 0;

            default:
                printf("\nInvalid choice! Select 0 to 6.\n");
        }
    }
}
return 0;
}
