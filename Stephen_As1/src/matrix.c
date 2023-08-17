#include "matrix.h"

/*FUNCTION===================================================================================
*   Function Name : get_matrix_data
*   Description   : Take input matrix from the keyboard
============================================================================================*/
void get_matrix_data(matrix_t *p_matrix)
{
    //Get matrix a size
    printf("Matrix Row: ");
    scanf("%i", &(p_matrix->m_row));
    printf("Matrix Col: ");
    scanf("%i", &(p_matrix->m_column));

    //Allocate memory for matrix 
    p_matrix->m_data = (int **)malloc(p_matrix->m_row * sizeof(int *));
    for (int i = 0; i < p_matrix->m_row; i++) 
    {
        p_matrix->m_data[i] = (int *)malloc(p_matrix->m_column * sizeof(int));
    }

    //Take input matrix from the keyboard
    printf("Input matrix:\n");
    for(int row = 0; row < p_matrix->m_row; row++)
    {
        for(int collum = 0 ; collum < p_matrix->m_column ; collum++)
        {
            scanf("%i", &(p_matrix->m_data[row][collum]));
        }
    }
}

/*FUNCTION===================================================================================
*   Function Name : print_matrix
*   Description   : Print the matrix to the terminal
============================================================================================*/
void print_matrix(matrix_t *p_matrix)
{
    for(int row = 0 ; row < p_matrix->m_row ; row++)
    {
        for(int collum = 0; collum < p_matrix->m_column; collum++)
        {
            printf("%10i", p_matrix->m_data[row][collum]);
        }
        printf("\n");
    }
}

/*FUNCTION===================================================================================
*   Function Name : sum_matrix
*   Description   : Calculate the sum of two matrices
============================================================================================*/
matrix_t *sum_matrix(matrix_t *p_matrix_a, matrix_t *p_matrix_b)
{
    if(p_matrix_a->m_row != p_matrix_b->m_row || p_matrix_a->m_column != p_matrix_b->m_column)
    {
        return NULL;
    }
    
    matrix_t *p_matrix_sum = malloc(sizeof(matrix_t)); 
    p_matrix_sum->m_row = p_matrix_a->m_row;
    p_matrix_sum->m_column = p_matrix_a->m_column;

    p_matrix_sum->m_data = (int **)malloc(p_matrix_sum->m_row * sizeof(int *));
    for (int i = 0; i < p_matrix_sum->m_row; i++) 
    {
        p_matrix_sum->m_data[i] = (int *)malloc(p_matrix_sum->m_column * sizeof(int));
    }

    for(int row = 0 ; row < p_matrix_sum->m_row; row++)
    {
        for(int collum = 0; collum < p_matrix_sum->m_column; collum++)
        {
            p_matrix_sum->m_data[row][collum] = p_matrix_a->m_data[row][collum] + p_matrix_b->m_data[row][collum];
        }
    }
    
    return p_matrix_sum;
}

/*FUNCTION===================================================================================
*   Function Name : product_matrix
*   Description   : Calculate the product of two matrices
============================================================================================*/
matrix_t *product_matrix(matrix_t *p_matrix_a, matrix_t *p_matrix_b)
{
    if(p_matrix_a->m_column != p_matrix_b->m_row)
    {
        return NULL;
    }
    
    matrix_t *p_matrix_product = malloc(sizeof(matrix_t)); 
    p_matrix_product->m_row = p_matrix_a->m_row;
    p_matrix_product->m_column = p_matrix_b->m_column;

    p_matrix_product->m_data = (int **)malloc(p_matrix_a->m_row * sizeof(int *));
    for (int i = 0; i < p_matrix_a->m_row; i++) {
        p_matrix_product->m_data[i] = (int *)malloc(p_matrix_b->m_column * sizeof(int));
    }
    
    for (int i = 0; i < p_matrix_a->m_row; i++) {
        for (int j = 0; j < p_matrix_b->m_column; j++) {
            p_matrix_product->m_data[i][j] = 0;
            for (int k = 0; k < p_matrix_a->m_column; k++) {
                p_matrix_product->m_data[i][j] += p_matrix_a->m_data[i][k] * p_matrix_b->m_data[k][j];
            }
        }
    }
    
    return p_matrix_product;
}

/*FUNCTION===================================================================================
*   Function Name : free_matrix
*   Description   : Free matrix allocated memory
============================================================================================*/
void free_matrix(matrix_t *p_matrix)
{
    for (int i = 0; i < p_matrix->m_row; i++) 
    {
        free(p_matrix->m_data[i]);
    }
    free(p_matrix->m_data);
    free(p_matrix);
}