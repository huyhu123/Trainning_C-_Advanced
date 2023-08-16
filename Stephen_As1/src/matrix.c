#include "matrix.h"

// Function to take input matrix from the keyboard test
void get_matrix_data(int **matrix, int rows, int collums)
{
    for(int row = 0; row < rows; row++)
    {
        for(int collum = 0 ; collum < collums ; collum++)
        {
            scanf("%i", &matrix[row][collum]);
        }
    }
}

// Function to print matrix
void print_matrix(int **matrix, int rows, int collums)
{
    for(int row = 0 ; row < rows ; row++)
    {
        for(int collum = 0; collum < collums; collum++)
        {
            printf("%i ", matrix[row][collum]);
        }
        printf("\n");
    }
}

// Function to calculate the sum of two matrices
int **sum_matrix(int **matrix_a, int matrix_a_row, int matrix_a_col, int **matrix_b, int matrix_b_row, int matrix_b_col)
{
    if(matrix_a_row != matrix_b_row || matrix_a_col != matrix_b_col)
    {
        return NULL;
    }
    
    int **matrix_sum = (int **)malloc(matrix_a_row * sizeof(int *));
    for (int i = 0; i < matrix_a_row; i++) 
    {
        matrix_sum[i] = (int *)malloc(matrix_a_col * sizeof(int));
    }

    for(int row = 0 ; row < matrix_a_row; row++)
    {
        for(int collum = 0; collum < matrix_a_col; collum++)
        {
            matrix_sum[row][collum] = matrix_a[row][collum] + matrix_b[row][collum];
        }
    }
    
    return matrix_sum;
}

// Function to calculate the product of two matrices
int **product_matrix(int **matrix_a, int matrix_a_row, int matrix_a_col, int **matrix_b, int matrix_b_row, int matrix_b_col)
{
    if(matrix_a_col != matrix_b_row)
    {
        return NULL;
    }
    
    int **product = (int **)malloc(matrix_a_row * sizeof(int *));
    for (int i = 0; i < matrix_a_row; i++) {
        product[i] = (int *)malloc(matrix_b_col * sizeof(int));
    }
    
    for (int i = 0; i < matrix_a_row; i++) {
        for (int j = 0; j < matrix_b_col; j++) {
            product[i][j] = 0;
            for (int k = 0; k < matrix_a_col; k++) {
                product[i][j] += matrix_a[i][k] * matrix_b[k][j];
            }
        }
    }
    
    return product;
}