#include "matrix.h"

// Function to take input matrix from the keyboard test
void get_matrix_data(matrix_t *matrix)
{
    //Get matrix a size
    printf("Matrix Row: ");
    scanf("%i", &(matrix->m_row));
    printf("Matrix Col: ");
    scanf("%i", &(matrix->m_column));

    //Allocate memory for matrix 
    matrix->m_data = (int **)malloc(matrix->m_row * sizeof(int *));
    for (int i = 0; i < matrix->m_row; i++) 
    {
        matrix->m_data[i] = (int *)malloc(matrix->m_column * sizeof(int));
    }

    printf("Input matrix:\n");
    for(int row = 0; row < matrix->m_row; row++)
    {
        for(int collum = 0 ; collum < matrix->m_column ; collum++)
        {
            scanf("%i", &(matrix->m_data[row][collum]));
        }
    }
}

// Function to print matrix
void print_matrix(matrix_t *matrix)
{
    for(int row = 0 ; row < matrix->m_row ; row++)
    {
        for(int collum = 0; collum < matrix->m_column; collum++)
        {
            printf("%10i", matrix->m_data[row][collum]);
        }
        printf("\n");
    }
}

// Function to calculate the sum of two matrices
matrix_t *sum_matrix(matrix_t *matrix_a, matrix_t *matrix_b)
{
    if(matrix_a->m_row != matrix_b->m_row || matrix_a->m_column != matrix_b->m_column)
    {
        return NULL;
    }
    
    matrix_t *matrix_sum = malloc(sizeof(matrix_t)); 
    matrix_sum->m_row = matrix_a->m_row;
    matrix_sum->m_column = matrix_a->m_column;

    matrix_sum->m_data = (int **)malloc(matrix_sum->m_row * sizeof(int *));
    for (int i = 0; i < matrix_sum->m_row; i++) 
    {
        matrix_sum->m_data[i] = (int *)malloc(matrix_sum->m_column * sizeof(int));
    }

    for(int row = 0 ; row < matrix_sum->m_row; row++)
    {
        for(int collum = 0; collum < matrix_sum->m_column; collum++)
        {
            matrix_sum->m_data[row][collum] = matrix_a->m_data[row][collum] + matrix_b->m_data[row][collum];
        }
    }
    
    return matrix_sum;
}

// Function to calculate the product of two matrices
matrix_t *product_matrix(matrix_t *matrix_a, matrix_t *matrix_b)
{
    if(matrix_a->m_column != matrix_b->m_row)
    {
        return NULL;
    }
    
    matrix_t *matrix_product = malloc(sizeof(matrix_t)); 
    matrix_product->m_row = matrix_a->m_row;
    matrix_product->m_column = matrix_b->m_column;

    matrix_product->m_data = (int **)malloc(matrix_a->m_row * sizeof(int *));
    for (int i = 0; i < matrix_a->m_row; i++) {
        matrix_product->m_data[i] = (int *)malloc(matrix_b->m_column * sizeof(int));
    }
    
    for (int i = 0; i < matrix_a->m_row; i++) {
        for (int j = 0; j < matrix_b->m_column; j++) {
            matrix_product->m_data[i][j] = 0;
            for (int k = 0; k < matrix_a->m_column; k++) {
                matrix_product->m_data[i][j] += matrix_a->m_data[i][k] * matrix_b->m_data[k][j];
            }
        }
    }
    
    return matrix_product;
}

// Free matrix allocated memory
void free_matrix(matrix_t *matrix)
{
    for (int i = 0; i < matrix->m_row; i++) 
    {
        free(matrix->m_data[i]);
    }
    free(matrix->m_data);
    free(matrix);
}