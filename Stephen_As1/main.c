#include "matrix.h"

int main()
{
    matrix_t *p_matrix_a = malloc(sizeof(size_t));
    matrix_t *p_matrix_b = malloc(sizeof(size_t));

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
    matrix_t *p_matrix_product = product_matrix(p_matrix_a, p_matrix_b);
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
    free_matrix(p_matrix_a);
    free_matrix(p_matrix_b);
    if(p_matrix_sum != NULL)
    {
        free_matrix(p_matrix_sum);
    }
    if(p_matrix_product != NULL)
    {
        free_matrix(p_matrix_product);
    }
    
    return 0;
}