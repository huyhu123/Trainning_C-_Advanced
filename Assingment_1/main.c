#include "matrix.h"

int main()
{
    matrix_t *p_matrix_a = NULL;
    matrix_t *p_matrix_b = NULL;
    int matrix_a_row = 0;
    int matrix_a_col = 0;
    int matrix_b_row = 0;
    int matrix_b_col = 0;

    //Get matrix size
    printf("Input matrix A size\n");
    get_matrix_size(&matrix_a_row, &matrix_a_col);
    printf("Input matrix B size\n");
    get_matrix_size(&matrix_b_row, &matrix_b_col);

    //Initialize_matrix
    p_matrix_a = initialize_matrix(matrix_a_row, matrix_a_col);
    p_matrix_b = initialize_matrix(matrix_b_row, matrix_b_col);

    //Get matrix data
    printf("Input matrix A\n");
    get_matrix_data(p_matrix_a);
    printf("Input matrix B\n");
    get_matrix_data(p_matrix_b);

    //Print matrix
    printf("Matrix A:\n");
    print_matrix(p_matrix_a);
    printf("Matrix B:\n");
    print_matrix(p_matrix_b);

    //Calculate and print sum of 2 matrix
    matrix_t *p_matrix_sum = sum_matrix(p_matrix_a, p_matrix_b);
    if(p_matrix_sum != NULL)
    {
        printf("Matrix A + Matrix B:\n");
        print_matrix(p_matrix_sum);
    }
    else
    {
        printf("Matrix A, Matrix B cant add together\n");
    }

    
    //Calculate and print product of 2 matrix
    matrix_t *p_matrix_product = multiply_matrix(p_matrix_a, p_matrix_b);
    if(p_matrix_product != NULL)
    {
        printf("Matrix A * Matrix B:\n");
        print_matrix(p_matrix_product);
    }
    else
    {
        printf("Matrix A, Matrix B cant multi together\n");
    }

    //Free allocated memory
    free_matrix(4, p_matrix_a, p_matrix_b, p_matrix_sum, p_matrix_product);
    
    return 0;
}